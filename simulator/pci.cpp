////////////////////////////////////////////////////////////////////////////////
///
/// @file       HAL.cpp
///
/// @project
///
/// @brief      C++ Register wrapper code
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2019, Evan Lojewski
/// @cond
///
/// All rights reserved.
///
/// Redistribution and use in source and binary forms, with or without
/// modification, are permitted provided that the following conditions are met:
/// 1. Redistributions of source code must retain the above copyright notice,
/// this list of conditions and the following disclaimer.
/// 2. Redistributions in binary form must reproduce the above copyright notice,
/// this list of conditions and the following disclaimer in the documentation
/// and/or other materials provided with the distribution.
/// 3. Neither the name of the copyright holder nor the
/// names of its contributors may be used to endorse or promote products
/// derived from this software without specific prior written permission.
///
////////////////////////////////////////////////////////////////////////////////
///
/// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
/// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
/// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
/// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
/// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
/// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
/// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
/// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
/// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
/// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
/// POSSIBILITY OF SUCH DAMAGE.
/// @endcond
////////////////////////////////////////////////////////////////////////////////
#include "../libs/NVRam/bcm5719_NVM.h"
#include "pci_config.h"

#include <HAL.hpp>

#include <bcm5719_DEVICE.h>
#include <bcm5719_APE.h>
#include <bcm5719_APE_PERI.h>
#include <bcm5719_SHM.h>
#include <bcm5719_SHM_CHANNEL0.h>
#include <bcm5719_SHM_CHANNEL1.h>
#include <bcm5719_SHM_CHANNEL2.h>
#include <bcm5719_SHM_CHANNEL3.h>
#include <bcm5719_GEN.h>

#include <APE_NVIC.h>

#include <dirent.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

#include <string>
#include <iostream>

#if __has_include("valgrind/valgrind.h")
#include <valgrind/valgrind.h>
#else
#define RUNNING_ON_VALGRIND 0
#endif

#ifdef __ppc64__
#define BARRIER()    do { asm volatile ("sync 0\neieio\n" ::: "memory"); } while(0)
#else
#define BARRIER()    do { asm volatile ("" ::: "memory"); } while(0)
#endif

using namespace std;

#define DEVICE_ROOT     "/sys/bus/pci/devices/"
#define DEVICE_CONFIG   "config"
#define BAR_STR         "resource"

static hal_config_t gConfig = {0};

#define BAR_REGION_MASK (0x1)
#define BAR_TYPE_MASK   (0x6)
#define BAR_TYPE_16BIT  (1u << 1)
#define BAR_TYPE_32BIT  (0u << 1)
#define BAR_TYPE_64BIT  (2u << 1)
#define BAR_ADDR_MASK   (0xFFFFFF0)
static bool is_bar_64bit(uint32_t bar)
{
    return (BAR_TYPE_64BIT == (bar & BAR_TYPE_MASK));
}

#define MAX_NUM_BARS 8
static uint8_t *bar[MAX_NUM_BARS] = {0};
static size_t  barlen[MAX_NUM_BARS];


static void unmap_bars()
{
    for(size_t i = 0; i < ARRAY_ELEMENTS(bar); i++)
    {
        if(bar[i] && barlen[i])
        {
            munmap(bar[i], barlen[i]);
            bar[i] = 0;
            barlen[i] = 0;
        }
    }
}

static bool is_pci_function(const char *pci_path, int wanted_function)
{
    // Path: 0001:01:00.0
    unsigned int sys = 0;
    unsigned int bus = 0;
    unsigned int slot = 0;
    unsigned int function = 0;
    if (4 == sscanf(pci_path, "%x:%x:%x.%u\n", &sys, &bus, &slot, &function))
    {
        if (wanted_function == function)
        {
            return true;
        }
    }

    return false;
}

static void locate_pci_path(int wanted_function, string &pci_path)
{
    struct dirent *pDirent;
    DIR *pDir;

    pDir = opendir(DEVICE_ROOT);
    if (pDir == NULL)
    {
        printf("Cannot open directory '%s'\n", DEVICE_ROOT);
        return;
    }

    while ((pDirent = readdir(pDir)) != NULL && pci_path.empty())
    {
        const char *pPCIPath = pDirent->d_name;

        if (is_pci_function(pDirent->d_name, wanted_function))
        {
            string configPath;
            configPath = string(DEVICE_ROOT) + pPCIPath + "/" + DEVICE_CONFIG;
            const char* pConfigPath = configPath.c_str();

            // This is the primary function of a device.
            // Read the configuration and see if it matches a supported
            // vendor/device.

            FILE *pConfigFile = fopen(pConfigPath, "rb");

            if (pConfigFile)
            {
                pci_config_t config;

                if (1 == fread(&config, sizeof(config), 1, pConfigFile))
                {
                    if (HAL_deviceIsSupported(config.vendor_id, config.device_id))
                    {
                        pci_path = string(DEVICE_ROOT) + "/" + pPCIPath;
                    }
                }

                fclose(pConfigFile);
            }
        }
    }

    closedir(pDir);
}

static uint32_t read_from_ram(uint32_t val, uint32_t offset, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += offset;

    BARRIER();
    return *(uint32_t *)base;
}

static uint32_t write_to_ram(uint32_t val, uint32_t offset, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += offset;

    BARRIER();
    *(uint32_t *)base = val;
    BARRIER();
    return val;
}

const hal_config_t *HAL_probePCI(const char* path, int wanted_function)
{
    struct stat st;
    string located_pci_path;

    if(RUNNING_ON_VALGRIND)
    {
        cerr << "Running on valgrind is not supported when mmaping device registers." << endl;
        return NULL;
    }

    if(!path)
    {
        // Locate the first PCI device.
        locate_pci_path(wanted_function, located_pci_path);
        if(located_pci_path.empty())
        {
            fprintf(stderr, "Unable to find supported PCI device\n");
            return NULL;
        }
    }
    else
    {
        located_pci_path  = path;
    }

    string configPath = located_pci_path + "/" + DEVICE_CONFIG;
    const char* pConfigPath = configPath.c_str();

    FILE *pConfigFile = fopen(pConfigPath, "rb");

    if(!pConfigFile)
    {
        fprintf(stderr, "Unable to open PCI configuration %p\n", pConfigPath);

        return NULL;
    }

    pci_config_t config;
    size_t read_count = fread(&config, sizeof(config), 1, pConfigFile);

    fclose(pConfigFile);

    if (1 != read_count)
    {
        return NULL;
    }

    if (HAL_deviceIsSupported(config.vendor_id, config.device_id))
    {
        printf("Found supported device %x:%x at %s\n", config.vendor_id,
                config.device_id, configPath.c_str());

        for (size_t i = 0; i < ARRAY_ELEMENTS(config.BAR); i++)
        {
            int memfd;
            string BARPath = string(located_pci_path) + "/" BAR_STR + to_string(i);
            const char* pBARPath = BARPath.c_str();

            if ((memfd = open(pBARPath, O_RDWR | O_SYNC)) < 0)
            {
                printf("Error opening %s file. \n", pBARPath);

                unmap_bars();

                return NULL;
            }
            else
            {
                printf("mmaping BAR[%zu]: %s\n", i, pBARPath);
            }

            if (fstat(memfd, &st) < 0)
            {
                fprintf(stderr, "error: couldn't stat file\n");

                unmap_bars();
                close(memfd);

                return NULL;
            }

            bar[i] = (uint8_t *)mmap(0, st.st_size, PROT_READ | PROT_WRITE,
                                        MAP_SHARED, memfd, 0); // PROT_WRITE
            barlen[i] = st.st_size;
            close(memfd);

            if (bar[i] == MAP_FAILED)
            {
                printf("Unable to mmap %s: %s\n", pBARPath,
                        strerror(errno));

                unmap_bars();

                return NULL;
            }

            if (is_bar_64bit(config.BAR[i]))
            {
                i++;
            }
        }
    }

    uint8_t *DEVICEBase = (uint8_t *)bar[0];
    uint8_t *APEBase = (uint8_t *)bar[2];

    gConfig.DEVICEBase = DEVICEBase;
    gConfig.APEBase = APEBase;
    gConfig.read = read_from_ram;
    gConfig.write = write_to_ram;

    return &gConfig;
}
