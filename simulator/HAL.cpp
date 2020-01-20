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

#include <bcm5719_DEVICE.h>
#include <bcm5719_APE.h>
#include <bcm5719_APE_PERI.h>
#include <bcm5719_SHM.h>
#include <bcm5719_SHM_CHANNEL0.h>
#include <bcm5719_SHM_CHANNEL1.h>
#include <bcm5719_SHM_CHANNEL2.h>
#include <bcm5719_SHM_CHANNEL3.h>
#include <bcm5719_GEN.h>

#include <dirent.h>
#include <endian.h>
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

using namespace std;

#define DEVICE_ROOT     "/sys/bus/pci/devices/"
#define DEVICE_CONFIG   "config"
#define BAR_STR         "resource"

uint8_t *gDEVICEBase;
uint8_t *gAPEBase;

typedef struct
{
    uint16_t vendor_id;
    uint16_t device_id;
} devices_t;

devices_t gSupportedDevices[] = {
    {.vendor_id = 0x14e4, .device_id = 0x1657},
};

bool is_supported(uint16_t vendor_id, uint16_t device_id)
{
    for (unsigned int i = 0; i < ARRAY_ELEMENTS(gSupportedDevices); i++)
    {
        devices_t *pDevice = &gSupportedDevices[i];
        if (vendor_id == pDevice->vendor_id && device_id == pDevice->device_id)
        {
            return true;
        }
    }

    return false;
}

#define BAR_REGION_MASK (0x1)
#define BAR_TYPE_MASK   (0x6)
#define BAR_TYPE_16BIT  (1u << 1)
#define BAR_TYPE_32BIT  (0u << 1)
#define BAR_TYPE_64BIT  (2u << 1)
#define BAR_ADDR_MASK   (0xFFFFFF0)
bool is_bar_64bit(uint32_t bar)
{
    return (BAR_TYPE_64BIT == (bar & BAR_TYPE_MASK));
}

uint32_t get_bar_addr(uint32_t bar)
{
    return (bar & BAR_ADDR_MASK);
}

#define MAX_NUM_BARS 8
uint8_t *bar[MAX_NUM_BARS] = {0};

uint32_t read_device_chipid(uint32_t)
{
    printf("DEIVCE CHIP ID\n");
    return 1123;
}

bool is_pci_function(const char *pci_path, int wanted_function)
{
    // Path: 0001:01:00.0
    int sys = 0;
    int bus = 0;
    int slot = 0;
    int function = 0;
    if (4 == sscanf(pci_path, "%x:%x:%x.%d\n", &sys, &bus, &slot, &function))
    {
        if (wanted_function == function)
        {
            return true;
        }
    }

    return false;
}

static char* locate_pci_path(int wanted_function)
{
    char* pci_path = NULL;
    struct dirent *pDirent;
    DIR *pDir;

    pDir = opendir(DEVICE_ROOT);
    if (pDir == NULL)
    {
        printf("Cannot open directory '%s'\n", DEVICE_ROOT);
        return NULL;
    }

    while ((pDirent = readdir(pDir)) != NULL && NULL == pci_path)
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

                if (fread(&config, sizeof(config), 1, pConfigFile))
                {
                    if (is_supported(config.vendor_id, config.device_id))
                    {
                        pci_path = (char *)malloc(
                            strlen(DEVICE_ROOT "%s/") + strlen(pPCIPath) + 1);
                        sprintf(pci_path, DEVICE_ROOT "%s/", pPCIPath);
                    }
                }
                fclose(pConfigFile);
            }

        }
    }
    closedir(pDir);

    return pci_path;
}


bool initHAL(const char *pci_path, int wanted_function)
{
    char* located_pci_path = NULL;
    struct stat st;
    int memfd;

    if(RUNNING_ON_VALGRIND)
    {
        cerr << "Running on valgrind is not supported when mmaping device registers." << endl;
        return false;;
    }

    if(!pci_path)
    {
        // Let's 
        located_pci_path = locate_pci_path(wanted_function);
        pci_path = located_pci_path;
        if(!located_pci_path)
        {
            fprintf(stderr, "Unable to find supported PCI device\n");
            return false;
        }
    }

    string configPath = string(pci_path) + string("/") + string(DEVICE_CONFIG);
    const char* pConfigPath = configPath.c_str();

    FILE *pConfigFile = fopen(pConfigPath, "rb");

    if(!pConfigFile)
    {
        fprintf(stderr, "Unable to open PCI configuration %p\n", pConfigPath);
        exit(-1);
    }

    pci_config_t config;

    if (fread(&config, sizeof(config), 1, pConfigFile))
    {
        if (is_supported(config.vendor_id, config.device_id))
        {
            printf("Found supported device %x:%x at %s\n", config.vendor_id,
                   config.device_id, configPath.c_str());
            for (unsigned int i = 0; i < ARRAY_ELEMENTS(config.BAR); i++)
            {
                string BARPath = string(pci_path) + "/" BAR_STR + to_string(i);
                const char* pBARPath = BARPath.c_str();

                if ((memfd = open(pBARPath, O_RDWR | O_SYNC)) < 0)
                {
                    printf("Error opening %s file. \n", pBARPath);
                    close(memfd);
                    if(located_pci_path)
                    {
                        free(located_pci_path);
                    }
                    return false;
                }
                else
                {
                    printf("mmaping BAR[%d]: %s\n", i, pBARPath);
                }

                if (fstat(memfd, &st) < 0)
                {
                    fprintf(stderr, "error: couldn't stat file\n");
                    if(located_pci_path)
                    {
                        free(located_pci_path);
                    }
                    return false;
                }

                bar[i] = (uint8_t *)mmap(0, st.st_size, PROT_READ | PROT_WRITE,
                                         MAP_SHARED, memfd, 0); // PROT_WRITE
                if (bar[i] == MAP_FAILED)
                {
                    printf("Unable to mmap %s: %s\n", pBARPath,
                           strerror(errno));
                    if(located_pci_path)
                    {
                        free(located_pci_path);
                    }
                    return false;
                }

                if (is_bar_64bit(config.BAR[i]))
                {
                    i++;
                }
            }
        }
    }

    if(located_pci_path)
    {
        free(located_pci_path);
    }

    uint8_t *DEVICEBase = gDEVICEBase = (uint8_t *)bar[0];
    uint8_t *APEBase = gAPEBase = (uint8_t *)bar[2];

    init_bcm5719_DEVICE();
    init_bcm5719_DEVICE_sim(DEVICEBase);

    init_bcm5719_GEN();
    init_bcm5719_GEN_sim(&DEVICEBase[0x8000 + 0xB50]); // 0x8000 for windowed area

    init_bcm5719_NVM();
    init_bcm5719_NVM_sim(&DEVICEBase[0x7000]);

    init_bcm5719_APE();
    init_bcm5719_APE_sim(APEBase);

    init_bcm5719_APE_PERI();
    init_bcm5719_APE_PERI_sim(&APEBase[0x8000]);

    init_bcm5719_SHM();
    init_bcm5719_SHM_sim(&APEBase[0x4000]);

    init_bcm5719_SHM_CHANNEL0();
    init_bcm5719_SHM_CHANNEL0_sim(&APEBase[0x4900]);
    init_bcm5719_SHM_CHANNEL1();
    init_bcm5719_SHM_CHANNEL1_sim(&APEBase[0x4a00]);
    init_bcm5719_SHM_CHANNEL2();
    init_bcm5719_SHM_CHANNEL2_sim(&APEBase[0x4b00]);
    init_bcm5719_SHM_CHANNEL3();
    init_bcm5719_SHM_CHANNEL3_sim(&APEBase[0x4c00]);

    return true;
}
