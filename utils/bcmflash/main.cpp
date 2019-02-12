////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.cpp
///
/// @project
///
/// @brief      Main bcmflash tool for parsing BCM5179 flash images.
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2018, Evan Lojewski
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

#include "HAL.hpp"
#include "pci_config.h"

#include <NVRam.h>
#include <bcm5719_eeprom.h>
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

#define DEVICE_ROOT "/sys/bus/pci/devices/"
#define DEVICE_CONFIG "config"
#define BAR_STR "resource%d"

#define ERROR_NO_PCI_DEVS (1)

bool is_primary_function(const char *pci_path)
{
    // Path: 0001:01:00.0
    int sys = 0;
    int bus = 0;
    int slot = 0;
    int function = 0;
    if (4 == sscanf(pci_path, "%d:%d:%d.%d\n", &sys, &bus, &slot, &function))
    {
        if (0 == function)
        {
            return true;
        }
    }

    return false;
}

int main(int argc, char const *argv[])
{
    struct dirent *pDirent;
    DIR *pDir;

    pDir = opendir(DEVICE_ROOT);
    if (pDir == NULL)
    {
        printf("Cannot open directory '%s'\n", DEVICE_ROOT);
        return ERROR_NO_PCI_DEVS;
    }

    while ((pDirent = readdir(pDir)) != NULL)
    {
        const char *pPCIPath = pDirent->d_name;
        if (is_primary_function(pDirent->d_name))
        {
            // This is the primary function of a device.
            // Read the configuration and see if it matches a supported
            // vendor/device.
            char *pConfigPath = (char *)malloc(
                strlen(DEVICE_ROOT "%s/" DEVICE_CONFIG) + strlen(pPCIPath) + 1);
            sprintf(pConfigPath, DEVICE_ROOT "%s/" DEVICE_CONFIG, pPCIPath);

            FILE *pConfigFile = fopen(pConfigPath, "rb");

            if (pConfigFile)
            {
                pci_config_t config;

                if (fread(&config, sizeof(config), 1, pConfigFile))
                {
                    if (is_supported(config.vendor_id, config.device_id))
                    {
                        char *pFullPCIPath = (char *)malloc(
                            strlen(DEVICE_ROOT "%s/") + strlen(pPCIPath) + 1);
                        sprintf(pFullPCIPath, DEVICE_ROOT "%s/", pPCIPath);
                        initHAL(pFullPCIPath);

                        free(pFullPCIPath);
                        free(pConfigPath);
                        break;
                    }
                }
            }
            free(pConfigPath);
        }
    }
    closedir(pDir);

    printf("ChipId: %x\n", (uint32_t)DEVICE.ChipId.r32);

    printf("Grab lock...\n");
    NVRam_acquireLock();

    NVRam_enable();

    NVRAMContents_t *nvram = (NVRAMContents_t *)malloc(sizeof(NVRAMContents_t));
    NVRam_read(0, (uint32_t *)nvram, sizeof(NVRAMContents_t) / 4);

    printf("=== Header ===\n");
    printf("Magic:               0x%08X\n", be32toh(nvram->header.magic));
    printf("Bootstrap Phys Addr: 0x%08X\n",
           be32toh(nvram->header.bootstrapPhysAddr));
    printf("Bootstrap Words:     0x%08X (%d bytes)\n",
           be32toh(nvram->header.bootstrapWords),
           be32toh(nvram->header.bootstrapWords) * 4);
    printf("Bootstrap Offset:    0x%08X\n",
           be32toh(nvram->header.bootstrapOffset));
    printf("CRC:                 0x%08X\n", be32toh(nvram->header.crc));
    uint32_t expected_crc = be32toh(~NVRam_crc(
        (uint8_t *)&nvram->header,
        (((uint8_t *)&nvram->header.crc - (uint8_t *)&nvram->header)),
        0xffffffff));
    printf("Expected CRC:        0x%08X\n", expected_crc);

    for (int i = 0; i < ARRAY_ELEMENTS(nvram->directory); i++)
    {
        uint32_t info = be32toh(nvram->directory[i].codeInfo);
        if (info)
        {
            printf("\n=== Directory %d (0x%08X)===\n", i, info);
            uint32_t length = BCM_CODE_DIRECTORY_GET_LENGTH(info);
            uint32_t cpu = BCM_CODE_DIRECTORY_GET_CPU(info);
            uint32_t type = BCM_CODE_DIRECTORY_GET_TYPE(info);
            printf("Code Address:   0x%08X\n",
                   be32toh(nvram->directory[i].codeAddress));
            printf("Code Words:     0x%08X (%d bytes)\n", length, length);
            printf("Code Offset:    0x%08X\n",
                   be32toh(nvram->directory[i].directoryOffset));
            printf("Code CPU:       0x%02X\n", cpu);
            printf("Code Type:      0x%02X\n", type);
            printf("\n");
        }
    }

    printf("\n=== Info ===\n");

    printf("MAC[0]: 0x%012lX\n", be64toh(nvram->info.macAddr0)); // FIXME
    printf("Part Number: %s\n", nvram->info.partNumber);
    printf("Vendor ID: 0x%04X\n", be16toh(nvram->info.vendorID));
    printf("Device ID: 0x%04X\n", be16toh(nvram->info.deviceID));
    printf("Subsystem Vendor ID: 0x%04X\n",
           be16toh(nvram->info.subsystemVendorID));
    printf("Subsystem Device ID: 0x%04X\n",
           be16toh(nvram->info.subsystemDeviceID));

    printf("\n=== VPD ===\n");
    if (vpd_is_valid(nvram->vpd.bytes, sizeof(nvram->vpd)))
    {
        size_t vpd_len = sizeof(nvram->vpd);
        printf("Identifier: %s\n",
               vpd_get_identifier(nvram->vpd.bytes, &vpd_len));

        uint8_t *resource;
        int index = 0;
        do
        {
            vpd_len = sizeof(nvram->vpd);
            uint16_t name;
            resource = vpd_get_resource_by_index(nvram->vpd.bytes, &vpd_len,
                                                 &name, index);
            if (resource)
            {
                char *data = (char *)malloc(vpd_len + 1);
                memcpy(data, resource, vpd_len);
                data[vpd_len] = 0;
                printf("[%02d] %24s: %s\n", index, vpd_get_field_name(name),
                       data);
                free(data);
            }
            index++;
        } while (resource);
    }
    else
    {
        printf("VPD is invalid.\n");
    }

    //
    //     FILE* out = fopen("firmware.fw", "w+");
    //     fwrite(nvram, bytes, 1, out);
    //     fclose(out);

    NVRam_releaseLock();

    return 0;
}
