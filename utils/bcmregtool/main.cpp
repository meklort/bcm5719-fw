////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.cpp
///
/// @project
///
/// @brief      Main bcm regiuster tool for decoding BCM5179 registers.
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
    printf("APEChipId: %x\n", (uint32_t)APE.ChipId.r32);

    // printf("RxRiscMode: %0x\n", DEVICE.RxRiscMode.r32);
    // printf("RxRiscStatus: %0x\n", DEVICE.RxRiscStatus.r32);
    // printf("RxRiscProgramCounter: %0x\n", DEVICE.RxRiscProgramCounter.r32);
    // printf("RxRiscRegister0: %0x\n", DEVICE.RxRiscRegister0.r32);
    // printf("RxRiscRegister1: %0x\n", DEVICE.RxRiscRegister1.r32);
    // printf("RxRiscRegister2: %0x\n", DEVICE.RxRiscRegister2.r32);
    // printf("RxRiscRegister3: %0x\n", DEVICE.RxRiscRegister3.r32);
    DEVICE.LinkStatusControl.r32 = 0xffffffff;
    printf("LinkStatusControl.NegotiatedLinkSpeed: %0x\n",
           (uint32_t)DEVICE.LinkStatusControl.bits.NegotiatedLinkSpeed);
    printf("LinkStatusControl.NegotiatedLinkWidth: %0x\n",
           (uint32_t)DEVICE.LinkStatusControl.bits.NegotiatedLinkWidth);
    printf("LinkStatusControl.r32:                 %0x\n",
           (uint32_t)DEVICE.LinkStatusControl.r32);

    DEVICE.LinkStatusControl.bits.NegotiatedLinkSpeed = 0;
    printf("LinkStatusControl.NegotiatedLinkSpeed: %0x\n",
           (uint32_t)DEVICE.LinkStatusControl.bits.NegotiatedLinkSpeed);
    printf("LinkStatusControl.NegotiatedLinkWidth: %0x\n",
           (uint32_t)DEVICE.LinkStatusControl.bits.NegotiatedLinkWidth);
    printf("LinkStatusControl.r32:                 %0x\n",
           (uint32_t)DEVICE.LinkStatusControl.r32);

    printf("EmacMode.PortMode: %0x\n", (uint32_t)DEVICE.EmacMode.bits.PortMode);
    printf("EmacMacAddresses0High: %0x\n",
           (uint32_t)DEVICE.EmacMacAddresses0High.r32);
    printf("EmacMacAddresses0Low: %0x\n",
           (uint32_t)DEVICE.EmacMacAddresses0Low.r32);
    printf("RxRiscMode: %0x\n", (uint32_t)DEVICE.RxRiscMode.r32);

    // printf("HostDriverId: %0x\n", APE.HostDriverId.r32);
    // printf("RcpuPciSubsystemId: %0x\n", APE.RcpuPciSubsystemId.r32);

    // printf("\n\n=========\n\n");

    printf("Grab lock...\n");
    NVRam_acquireLock();

    NVRam_enable();

    uint32_t length = NVRam_readWord(8);   // current stage length
    uint32_t offset = NVRam_readWord(0xc); // current stage offset
    printf("NVRam_read(8) = %x\n", length);
    printf("NVRam_read(C) = %x\n", offset);
    // uint32_t next_stage_hdr = offset + (length*4);
    // uint32_t next_stage_size = next_stage_hdr + 4;
    // printf("NVRam_read(%x) = %x\n", next_stage_hdr,
    // NVRam_readWord(next_stage_hdr)); printf("NVRam_read(%x) = %x\n",
    // next_stage_size, NVRam_readWord(next_stage_size));

    NVRam_releaseLock();

    return 0;
}
