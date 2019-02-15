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
#include <OptionParser.h>
#include <vector>
#include <string>
#include <fstream>

using namespace std;
using optparse::OptionParser;

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

bool init_hw_sim(void)
{
    bool inited = false;
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
                        char *pFullPCIPath = (char *)malloc(
                            strlen(DEVICE_ROOT "%s/") + strlen(pPCIPath) + 1);
                        sprintf(pFullPCIPath, DEVICE_ROOT "%s/", pPCIPath);
                        initHAL(pFullPCIPath);
                        inited = true;

                        free(pFullPCIPath);
                    }
                }
                fclose(pConfigFile);
            }

        }
    }
    closedir(pDir);

    return inited;
}

#define NVRAM_SIZE      (1024u * 255u) /* 256KB */
int main(int argc, char const *argv[])
{
    union {
        uint8_t         bytes[NVRAM_SIZE];
        uint32_t        words[NVRAM_SIZE/4];
        NVRAMContents_t contents;
    } nvram;

    OptionParser parser = OptionParser().description("BCM Flash Utility");

    parser.add_option("-t", "--target")
            .choices({"hardware", "file"})
            .dest("target")
            // .set_default("hardware")
            .help(  "hardware: Use the attached physical device.\n"
                    "file: Use the file specified with -f, --file\n");

    parser.add_option("-f", "--file")
            .dest("filename")
            .help("Read from the specified file")
            .metavar("FILE");

    parser.add_option("-1", "--stage1")
            .dest("stage1")
            .help("Update the target with the specified stage1 image, if possible.")
            .metavar("STAGE1");

    parser.add_option("-2", "--stage2")
            .dest("stage2")
            .help("Update the target with the specified stage2 image, if possible.")
            .metavar("STAGE2");

    parser.add_option("-q", "--quiet")
            .action("store_false")
            .dest("verbose")
            .set_default("1")
            .help("don't print status messages to stdout");

    optparse::Values options = parser.parse_args(argc, argv);
    vector<string> args = parser.args();

    if("file" == options["target"])
    {
        if(!options.is_set("filename"))
        {
            cerr << "Please specify a file to use." << endl;
            parser.print_help();
            exit(-1);
        }


        fstream infile;
        infile.open(options["filename"], fstream::in | fstream::binary);
        if(infile.is_open())
        {
            infile.read((char*)nvram.bytes, NVRAM_SIZE);

            infile.close();
        }
        else
        {
            cerr << " Unable to open file '" << options["filename"] << "'" << endl;
            exit(-1);
        }
    }
    else if("hardware" == options["target"])
    {
        if(!init_hw_sim())
        {
            exit(-1);
        }

        printf("ChipId: %x\n", (uint32_t)DEVICE.ChipId.r32);

        NVRam_acquireLock();

        NVRam_enable();

        NVRam_read(0, nvram.words, sizeof(NVRAMContents_t) / 4);

        NVRam_releaseLock();


        // FILE* out = fopen("firmware.fw", "w+");
        // fwrite(nvram.bytes, NVRAM_SIZE, 1, out);
        // fclose(out);

    }
    else
    {
        cerr << "Please specify a target." << endl;
        parser.print_help();
        exit(-1);
    }

#if 1


    printf("=== Header ===\n");
    printf("Magic:               0x%08X\n", be32toh(nvram.contents.header.magic));
    printf("Bootstrap Phys Addr: 0x%08X\n",
           be32toh(nvram.contents.header.bootstrapPhysAddr));
    printf("Bootstrap Words:     0x%08X (%d bytes)\n",
           be32toh(nvram.contents.header.bootstrapWords),
           be32toh(nvram.contents.header.bootstrapWords) * 4);
    printf("Bootstrap Offset:    0x%08X\n",
           be32toh(nvram.contents.header.bootstrapOffset));
    printf("CRC:                 0x%08X\n", be32toh(nvram.contents.header.crc));
    uint32_t expected_crc = be32toh(~NVRam_crc(
        (uint8_t *)&nvram.contents.header,
        (((uint8_t *)&nvram.contents.header.crc - (uint8_t *)&nvram.contents.header)),
        0xffffffff));
    printf("Expected CRC:        0x%08X\n", expected_crc);

    for (int i = 0; i < ARRAY_ELEMENTS(nvram.contents.directory); i++)
    {
        uint32_t info = be32toh(nvram.contents.directory[i].codeInfo);
        if (info)
        {
            printf("\n=== Directory %d (0x%08X)===\n", i, info);
            uint32_t length = BCM_CODE_DIRECTORY_GET_LENGTH(info);
            uint32_t cpu = BCM_CODE_DIRECTORY_GET_CPU(info);
            uint32_t type = BCM_CODE_DIRECTORY_GET_TYPE(info);
            printf("Code Address:   0x%08X\n",
                   be32toh(nvram.contents.directory[i].codeAddress));
            printf("Code Words:     0x%08X (%d bytes)\n", length, length);
            printf("Code Offset:    0x%08X\n",
                   be32toh(nvram.contents.directory[i].directoryOffset));
            printf("Code CPU:       0x%02X\n", cpu);
            printf("Code Type:      0x%02X\n", type);
            printf("\n");
        }
    }

    printf("\n=== Info ===\n");
    printf("Firmware Revision: 0x%04X\n",
           be16toh(nvram.contents.info.firmwareRevision));

    printf("Part Number: %s\n", nvram.contents.info.partNumber);
    printf("Part Revision: %c%c\n", nvram.contents.info.partRevision[0],
           nvram.contents.info.partRevision[1]);

    printf("Vendor ID: 0x%04X\n", be16toh(nvram.contents.info.vendorID));
    printf("Device ID: 0x%04X\n", be16toh(nvram.contents.info.deviceID));
    printf("Subsystem Vendor ID: 0x%04X\n",
           be16toh(nvram.contents.info.subsystemVendorID));
    printf("Subsystem Device ID: 0x%04X\n",
           be16toh(nvram.contents.info.subsystemDeviceID));

    printf("Shared Cfg:     0x%08X\n", be32toh(nvram.contents.info.cfgShared));

    printf("Power Dissipated: 0x%02X 0x%02X 0x%02X 0x%02X\n",
           nvram.contents.info.powerDissipatedD3, nvram.contents.info.powerDissipatedD2,
           nvram.contents.info.powerDissipatedD1, nvram.contents.info.powerDissipatedD0);

    printf("Power Consumed: 0x%02X 0x%02X 0x%02X 0x%02X\n",
           nvram.contents.info.powerConsumedD3, nvram.contents.info.powerConsumedD2,
           nvram.contents.info.powerConsumedD1, nvram.contents.info.powerConsumedD0);

    printf("\n=== Port 0 ===\n");
    printf("Subsystem ID: 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF0GPHY));
    printf("MAC:    0x%012lX\n", be64toh(nvram.contents.info.macAddr0));
    printf("Feature:    0x%08X\n", be32toh(nvram.contents.info.func0CfgFeature));
    printf("Cfg:        0x%08X\n", be32toh(nvram.contents.info.func0CfgHW));
    printf("Cfg2:       0x%08X\n", be32toh(nvram.contents.info2.func0CfgHW2));
    printf("Pwr Budget: 0x%08X\n", be32toh(nvram.contents.info.powerBudget0));

    printf("\n=== Port 1 ===\n");
    printf("Subsystem ID: 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF1GPHY));
    printf("MAC:    0x%012lX\n", be64toh(nvram.contents.info.macAddr1));
    printf("Feature:    0x%08X\n", be32toh(nvram.contents.info.func1CfgFeature));
    printf("Cfg:        0x%08X\n", be32toh(nvram.contents.info.func1CfgHW));
    printf("Cfg2:       0x%08X\n", be32toh(nvram.contents.info2.func1CfgHW2));
    printf("Pwr Budget: 0x%08X\n", be32toh(nvram.contents.info.powerBudget1));

    printf("\n=== Port 2 ===\n");
    printf("Subsystem ID: 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF2GPHY));
    printf("MAC:    0x%012lX\n", be64toh(nvram.contents.info2.macAddr2));
    printf("Feature:    0x%08X\n", be32toh(nvram.contents.info2.func2CfgFeature));
    printf("Cfg:        0x%08X\n", be32toh(nvram.contents.info2.func2CfgHW));
    printf("Cfg2:       0x%08X\n", be32toh(nvram.contents.info2.func2CfgHW2));
    printf("Pwr Budget: 0x%08X\n", be32toh(nvram.contents.info.powerBudget2));

    printf("\n=== Port 3 ===\n");
    printf("Subsystem ID: 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF3GPHY));
    printf("MAC:    0x%012lX\n", be64toh(nvram.contents.info2.macAddr3));
    printf("Feature:    0x%08X\n", be32toh(nvram.contents.info2.func3CfgFeature));
    printf("Cfg:        0x%08X\n", be32toh(nvram.contents.info2.func3CfgHW));
    printf("Cfg2:       0x%08X\n", be32toh(nvram.contents.info2.func3CfgHW2));
    printf("Pwr Budget: 0x%08X\n", be32toh(nvram.contents.info.powerBudget3));

    printf("\n=== VPD ===\n");
    if (vpd_is_valid(nvram.contents.vpd.bytes, sizeof(nvram.contents.vpd)))
    {
        size_t vpd_len = sizeof(nvram.contents.vpd);
        printf("Identifier: %s\n",
               vpd_get_identifier(nvram.contents.vpd.bytes, &vpd_len));

        uint8_t *resource;
        int index = 0;
        do
        {
            vpd_len = sizeof(nvram.contents.vpd);
            uint16_t name;
            resource = vpd_get_resource_by_index(nvram.contents.vpd.bytes, &vpd_len,
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

#endif
    return 0;
}
