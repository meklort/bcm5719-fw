////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.cpp
///
/// @project    bcm5719-fw
///
/// @brief      Main bcmflash tool for parsing BCM5179 flash images.
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2018-2020, Evan Lojewski
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
#include "bcmflash.h"

#include <../bcm5719_NVM.h>
#include <NVRam.h>
#include <OptionParser.h>
#include <bcm5719_DEVICE.h>
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
#include <string>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <vector>

#define VERSION_STRING STRINGIFY(VERSION_MAJOR) "." STRINGIFY(VERSION_MINOR) "." STRINGIFY(VERSION_PATCH)

using namespace std;
using optparse::OptionParser;

uint32_t gApeLength = 0;
uint8_t *gApe = NULL;
uint32_t *gApeWd = NULL;

void dump_stage1(NVRAMContents_t *nvram, uint8_t *stage1, size_t stage1_length)
{
    uint32_t *stage1_wd = (uint32_t *)stage1;

    uint32_t crc_word = stage1_length / 4;

    uint32_t expected_crc = be32toh(~NVRam_crc(stage1, stage1_length, 0xffffffff));
    uint32_t phys_addr = be32toh(nvram->header.bootstrapPhysAddr);
    uint32_t ver_addr = be32toh(stage1_wd[2]) - phys_addr;
    const char *stage1_ver = NULL;
    uint32_t stage1_version_num = be32toh(stage1_wd[3]);
    uint8_t stage1_version_major = stage1_version_num >> 24;
    uint8_t stage1_version_minor = stage1_version_num >> 16 & 0xff;
    uint16_t stage1_version_patch = stage1_version_num & 0xffff;

    stage1_ver = NULL;
    if (ver_addr < stage1_length)
    {
        stage1_ver = (char *)&stage1[ver_addr];
    }
    else
    {
        stage1_ver = "Unknown";
    }

    printf("=== stage1 ===\n");
    printf("Version:             %s (version %d.%d.%d)\n", stage1_ver, stage1_version_major, stage1_version_minor, stage1_version_patch);
    printf("Magic:               0x%08X\n", be32toh(nvram->header.magic));
    printf("Bootstrap Phys Addr: 0x%08X\n", phys_addr);
    printf("Length (bytes):      0x%08zX\n", stage1_length);
    // printf("Offset:              0x%08lX\n", ((stage1_wd - nvram.words) * 4));
    printf("Calculated CRC:      0x%08X\n", expected_crc);
    printf("CRC:                 0x%08X\n", be32toh(stage1_wd[crc_word]));

    if (be32toh(nvram->header.magic) != BCM_NVRAM_MAGIC)
    {
        fprintf(stderr, "Error: stage1 magic is invalid.\n");
        exit(-1);
    }

    if (be32toh(stage1_wd[crc_word]) != expected_crc)
    {
        fprintf(stderr, "Error: stage1 crc is invalid.\n");
        // exit(-1);
    }
}

void dump_stage2(NVRAMStage2_t *stage2)
{
    uint32_t stage2_length = be32toh(stage2->header.length); // second word is size (bytes).
    stage2_length -= 4;                                      // length includes crc.
    uint32_t stage2_crc_word = stage2_length / 4;
    printf("=== stage2 ===\n");
    printf("Magic:               0x%08X\n", be32toh(stage2->header.magic));
    printf("Length (bytes):      0x%08X\n", stage2_length);
    // printf("Offset:              0x%08lX\n", ((stage2_wd - nvram.words) * 4));
    uint32_t stage2_expected_crc = be32toh(~NVRam_crc((uint8_t *)stage2->words, stage2_length, 0xffffffff));
    printf("Calculated CRC:      0x%08X\n", stage2_expected_crc);
    printf("CRC:                 0x%08X\n", be32toh(stage2->words[stage2_crc_word]));

    if (be32toh(stage2->header.magic) != BCM_NVRAM_MAGIC)
    {
        fprintf(stderr, "Error: stage2 magic is invalid.\n");
        exit(-1);
    }

    if (be32toh(stage2->words[stage2_crc_word]) != stage2_expected_crc)
    {
        fprintf(stderr, "Error: stage2 crc is invalid.\n");
        exit(-1);
    }
}

void dump_code_directory(NVRAMCodeDirectory_t *cd, uint8_t *nvram, const char *outfile)
{

    uint32_t info = be32toh(cd->codeInfo);
    if (info)
    {
        printf("\n=== Directory (0x%08X)===\n", info);
        uint32_t addr = be32toh(cd->codeAddress);
        uint32_t length = BCM_CODE_DIRECTORY_GET_LENGTH(info);
        uint32_t cpu = BCM_CODE_DIRECTORY_GET_CPU(info);
        uint32_t type = BCM_CODE_DIRECTORY_GET_TYPE(info);

        uint8_t *cd_loc = &nvram[be32toh(cd->directoryOffset)];
        uint32_t crc_calc = be32toh(~NVRam_crc(cd_loc, (length - 1) * sizeof(uint32_t), 0xffffffff));
        uint32_t crc_expect = be32toh(((uint32_t *)cd_loc)[length - 1]);

        printf("Code Address:   0x%08X\n", addr);
        printf("Code Words:     0x%08X (%ld bytes)\n", length, length * sizeof(uint32_t));
        printf("Code Offset:    0x%08X\n", be32toh(cd->directoryOffset));
        printf("Code CPU:       0x%02X\n", cpu);
        printf("Code Type:      0x%02X\n", type);
        printf("Calculated CRC: 0x%08X\n", crc_calc);
        printf("Expected CRC:   0x%08X\n", crc_expect);
        printf("\n");

        if (BCM_CODE_DIRECTORY_ADDR_APE == addr && BCM_CODE_DIRECTORY_CPU_APE == cpu) /* APE */
        {
            gApe = &nvram[be32toh(cd->directoryOffset)];
            gApeWd = (uint32_t *)gApe;
            gApeLength = length * sizeof(uint32_t);
        }

        if (outfile)
        {
            if (!bcmflash_file_write(outfile, cd_loc, (length - 1) * sizeof(uint32_t)))
            {
                exit(-1);
            }
        }
    }
}

void dump_info(NVRAMInfo_t *info, NVRAMInfo2_t *info2)
{
    printf("\n=== Info ===\n");
    printf("Firmware Revision: 0x%04X\n", be16toh(info->firmwareRevision));

    printf("Part Number: %s\n", info->partNumber);
    printf("Part Revision: %c%c\n", info->partRevision[0], info->partRevision[1]);

    printf("Vendor ID: 0x%04X\n", be16toh(info->vendorID));
    printf("Device ID: 0x%04X\n", be16toh(info->deviceID));
    printf("Subsystem Vendor ID: 0x%04X\n", be16toh(info->subsystemVendorID));
    printf("Subsystem Device ID: 0x%04X\n", be16toh(info->subsystemDeviceID));
    printf("Subsystem ID: 0x%04X\n", be16toh(info->subsystemDeviceID));

    printf("Function 0S Subsystem ID 0x%04X\n", be16toh(info2->pciSubsystemF0SERDES));
    printf("Function 1S Subsystem ID 0x%04X\n", be16toh(info2->pciSubsystemF1SERDES));
    printf("Function 2S Subsystem ID 0x%04X\n", be16toh(info2->pciSubsystemF2SERDES));
    printf("Function 3S Subsystem ID 0x%04X\n", be16toh(info2->pciSubsystemF3SERDES));
    printf("Function 0G Subsystem ID 0x%04X\n", be16toh(info2->pciSubsystemF0GPHY));
    printf("Function 1G Subsystem ID 0x%04X\n", be16toh(info2->pciSubsystemF1GPHY));
    printf("Function 2G Subsystem ID 0x%04X\n", be16toh(info2->pciSubsystemF2GPHY));
    printf("Function 3G Subsystem ID 0x%04X\n", be16toh(info2->pciSubsystemF3GPHY));

    printf("Shared Cfg:     0x%08X\n", be32toh(info->cfgShared));

    printf("Power Dissipated: 0x%02X 0x%02X 0x%02X 0x%02X\n", info->powerDissipatedD3, info->powerDissipatedD2, info->powerDissipatedD1,
           info->powerDissipatedD0);

    printf("Power Consumed:   0x%02X 0x%02X 0x%02X 0x%02X\n", info->powerConsumedD3, info->powerConsumedD2, info->powerConsumedD1, info->powerConsumedD0);

    // Print out power budget (and translated values).
    uint32_t pb_raw[8];
    pb_raw[0] = be32toh(info->powerBudget0) & 0xffff;
    pb_raw[1] = be32toh(info->powerBudget0) >> 16;
    pb_raw[2] = be32toh(info->powerBudget1) & 0xffff;
    pb_raw[3] = be32toh(info->powerBudget1) >> 16;
    pb_raw[4] = be32toh(info->powerBudget2) & 0xffff;
    pb_raw[5] = be32toh(info->powerBudget2) >> 16;
    pb_raw[6] = be32toh(info->powerBudget3) & 0xffff;
    pb_raw[7] = be32toh(info->powerBudget3) >> 16;
    printf("Power Budget0:    0x%04X%04X\n", pb_raw[1], pb_raw[0]);
    printf("Power Budget1:    0x%04X%04X\n", pb_raw[3], pb_raw[2]);
    printf("Power Budget2:    0x%04X%04X\n", pb_raw[5], pb_raw[4]);
    printf("Power Budget3:    0x%04X%04X\n", pb_raw[7], pb_raw[6]);

    for (int i = 0; i < ARRAY_ELEMENTS(pb_raw); i++)
    {
        uint32_t raw = pb_raw[i];
        RegDEVICEPciPowerBudget0_t pb0;
        pb0.r32 = 0;
        if (raw)
        {
            pb0.bits.BasePower = raw & 0xFF;
            pb0.bits.DataScale = DEVICE_PCI_POWER_BUDGET_0_DATA_SCALE_0_1X;
            pb0.bits.PMState = (raw & 0x0300) >> 8;
            pb0.bits.Type = (raw & 0x1C00) >> 10;
            pb0.bits.PowerRail = (raw & 0xE000) >> 13;
        }

        printf("Translated Power Budget[%d]:    0x%08X\n", i, (uint32_t)pb0.r32);
    }

    printf("\n=== Port 0 ===\n");
    printf("Subsystem ID: 0x%04X\n", be16toh(info2->pciSubsystemF0GPHY));
    printf("MAC:        0x%04X%08X\n", be32toh(info->macAddr0[0]), be32toh(info->macAddr0[1]));
    printf("Feature:    0x%08X\n", be32toh(info->func0CfgFeature));
    printf("Cfg:        0x%08X\n", be32toh(info->func0CfgHW));
    printf("Cfg2:       0x%08X\n", be32toh(info2->func0CfgHW2));

    printf("\n=== Port 1 ===\n");
    printf("Subsystem ID: 0x%04X\n", be16toh(info2->pciSubsystemF1GPHY));
    printf("MAC:        0x%04X%08X\n", be32toh(info->macAddr1[0]), be32toh(info->macAddr1[1]));
    printf("Feature:    0x%08X\n", be32toh(info->func1CfgFeature));
    printf("Cfg:        0x%08X\n", be32toh(info->func1CfgHW));
    printf("Cfg2:       0x%08X\n", be32toh(info2->func1CfgHW2));

    printf("\n=== Port 2 ===\n");
    printf("Subsystem ID: 0x%04X\n", be16toh(info2->pciSubsystemF2GPHY));
    printf("MAC:        0x%04X%08X\n", be32toh(info2->macAddr2[0]), be32toh(info2->macAddr2[1]));
    printf("Feature:    0x%08X\n", be32toh(info2->func2CfgFeature));
    printf("Cfg:        0x%08X\n", be32toh(info2->func2CfgHW));
    printf("Cfg2:       0x%08X\n", be32toh(info2->func2CfgHW2));

    printf("\n=== Port 3 ===\n");
    printf("Subsystem ID: 0x%04X\n", be16toh(info2->pciSubsystemF3GPHY));
    printf("MAC:        0x%04X%08X\n", be32toh(info2->macAddr3[0]), be32toh(info2->macAddr3[1]));
    printf("Feature:    0x%08X\n", be32toh(info2->func3CfgFeature));
    printf("Cfg:        0x%08X\n", be32toh(info2->func3CfgHW));
    printf("Cfg2:       0x%08X\n", be32toh(info2->func3CfgHW2));
}

void dump_vpd(uint8_t *vpd, size_t vpd_len)
{
    printf("\n=== VPD ===\n");
    if (vpd_is_valid(vpd, vpd_len))
    {
        uint32_t len = vpd_len;
        printf("Identifier: %s\n", vpd_get_identifier(vpd, &len));

        uint8_t *resource;
        int index = 0;
        do
        {
            len = vpd_len;
            uint16_t name;
            resource = vpd_get_resource_by_index(vpd, &len, &name, index);
            if (resource)
            {
                char *data = (char *)malloc(len + 1);
                memcpy(data, resource, len);
                data[len] = 0;
                printf("[%c%c] %24s: %s\n", name & 0xff, name >> 8, vpd_get_field_name(name), data);
                free(data);
            }
            index++;
        } while (resource);
    }
    else
    {
        printf("VPD is invalid.\n");
    }
}

#define NVRAM_MAX_SIZE (2048u * 256u) /* 512KB */
int main(int argc, char const *argv[])
{
    bool extract = false;
    bool should_write = false;
    uint32_t nvm_size = NVRAM_MAX_SIZE;

    union
    {
        uint8_t bytes[NVRAM_MAX_SIZE];
        uint32_t words[NVRAM_MAX_SIZE / 4];
        NVRAMContents_t contents;
    } nvram;

    uint8_t *stage1 = NULL;
    uint32_t *stage1_wd = NULL;

    OptionParser parser = OptionParser().description("BCM Flash Utility v" VERSION_STRING);

    parser.version(VERSION_STRING);

    parser.add_option("-t", "--target")
        .choices({ "hardware", "file" })
        .dest("target")
        // .set_default("hardware")
        .help("hardware: Use the attached physical device.\n"
              "file: Use the file specified with -i, --file\n");

    parser.add_option("-f", "--function")
        .dest("function")
        .type("int")
        .set_default("1")
        .metavar("FUNCTION")
        .help("Read registers from the specified pci function.");

    parser.add_option("--nvm-recovery")
        .dest("recovery")
        .action("store_true")
        .set_default("0")
        .help("Recover form an incorrect NVM autodetection. Only valid with --target=hardware");

    parser.add_option("-i", "--file").dest("filename").help("Read from the specified file").metavar("FILE");

    parser.add_option("-b", "--backup")
        .dest("backup")
        .metavar("TYPE")
        .help("Backup the firmware to the specified file.\n"
              "binary:  Save a raw binary copy of the firmware to firmware.fw.\n"
              "extract: Save each individual stage to <stage>.fw.\n");

    parser.add_option("-r", "restore").dest("restore").help("Update the target device to match the specified file.").metavar("FILE");

    parser.add_option("-c", "--create")
        .dest("create")
        .action("store_true")
        .set_default("0")
        .help("Create a full firmware image for use with fwupd.");

    parser.add_option("-1", "--stage1").dest("stage1").help("Update the target with the specified stage1 image, if possible.").metavar("STAGE1");

    parser.add_option("-a", "--ape").dest("ape").help("Update the target with the specified ape image, if possible.").metavar("APE");

    parser.add_option("-u", "--unlock").dest("unlock").action("store_true").set_default("0").help("Clear all NVM locks.").metavar("UNLOCK");

    parser.add_option("-q", "--quiet").action("store_false").dest("verbose").set_default("1").help("don't print status messages to stdout");

    optparse::Values options = parser.parse_args(argc, argv);
    vector<string> args = parser.args();

    if (options.get("create"))
    {
        // Default to erased flash contents.
        memset(nvram.words, -1, sizeof(nvram.words));

        memcpy(nvram.contents.info.partNumber, "BCM95719", sizeof("BCM95719"));
        memcpy(nvram.contents.info.partRevision, "A0", sizeof("A0"));
        nvram.contents.info.vendorID = htobe16(0x14E4);
        nvram.contents.info.deviceID = htobe16(0x1657);

        nvram.contents.header.magic = htobe32(BCM_NVRAM_MAGIC);
        nvram.contents.header.bootstrapPhysAddr = htobe32(0x08003800);
        nvram.contents.header.bootstrapOffset = htobe32(sizeof(NVRAMContents_t));
        nvram.contents.header.bootstrapWords = 0;
        nvram.contents.header.crc = 0;

        // FIXME
        nvram.contents.header.crc = htobe32(~NVRam_crc((uint8_t*)&nvram.contents.header, sizeof(nvram.contents.header), 0xffffffff));
        printf("CRC: %x\n", nvram.contents.header.crc);

        if(options.is_set("stage1"))
        {
            uint32_t new_stage1_length = bcmflash_file_size(options["stage1"].c_str());

            if (new_stage1_length)
            {
                nvram.contents.header.bootstrapWords = htobe32(1 + ((new_stage1_length + 3) / 4));
            }
            else
            {
                // error
            }
        }

        // Stage2 unsupported presently.
        size_t stage1_length = (be32toh(nvram.contents.header.bootstrapWords) * 4) - 4; // last word is CRC

        uint32_t crc_word = stage1_length / 4;
        stage1_wd = &nvram.words[be32toh(nvram.contents.header.bootstrapOffset) / 4];

        uint32_t *stage2_wd = &stage1_wd[(crc_word + 1)]; // immediately after stage1 crc
        NVRAMStage2_t *stage2 = (NVRAMStage2_t *)stage2_wd;

        stage2->header.magic = htobe32(BCM_NVRAM_MAGIC);
        stage2->header.length = htobe32(4); /* CRC */
        stage2->words[0] = htobe32(0);

        // Invalidate all code directories
        memset(nvram.contents.directory, 0, sizeof(nvram.contents.directory));

        if(options.is_set("ape"))
        {
            uint32_t length = 4 + bcmflash_file_size(options["ape"].c_str());

            // uint32_t *ape = &stage2_wd[4];
            uint32_t info = 0;
            length = (length + 3) / 4;
            info = BCM_CODE_DIRECTORY_SET_LENGTH(info, length);
            info = BCM_CODE_DIRECTORY_SET_CPU(info, BCM_CODE_DIRECTORY_CPU_APE);
            info = BCM_CODE_DIRECTORY_SET_TYPE(info, 0);
            nvram.contents.directory[0].codeInfo = htobe32(info);
            nvram.contents.directory[0].codeAddress = htobe32(BCM_CODE_DIRECTORY_ADDR_APE);
            nvram.contents.directory[0].directoryOffset= htobe32(4 * (&stage2->words[1] - nvram.words));

            nvm_size = 4 * ((&stage2->words[1] - nvram.words) + length);
        }

        memset(&nvram.contents.vpd, 0, sizeof(nvram.contents.vpd));
    }
    else if ("file" == options["target"])
    {
        if (!options.is_set("filename"))
        {
            cerr << "Please specify a file to use." << endl;
            parser.print_help();
            exit(-1);
        }

        nvm_size = bcmflash_file_size(options["filename"].c_str());

        if (!bcmflash_file_read(options["filename"].c_str(), nvram.bytes, nvm_size))
        {
            cerr << " Unable to open file '" << options["filename"] << "'" << endl;
            exit(-1);
        }
    }
    else if ("hardware" == options["target"])
    {
        if (!initHAL(NULL, options.get("function")))
        {
            cerr << "Unable to locate pci device with function " << options["function"] << endl;
            exit(-1);
        }

        printf("ChipId: %x\n", (uint32_t)DEVICE.ChipId.r32);

        if (options.get("recovery"))
        {
            bcmflash_nvram_recovery();

            exit(0);
        }

        if (options.get("unlock"))
        {
            bcmflash_nvram_unlock();
        }

        bcmflash_nvram_read("nvram", nvram.words, nvm_size / 4);
    }
    else
    {
        cerr << "Please specify a target." << endl;
        parser.print_help();
        exit(-1);
    }

    if (options.is_set("restore"))
    {
        if (!bcmflash_file_read(options["restore"].c_str(), nvram.bytes, nvm_size))
        {
            cerr << " Unable to open file '" << options["restore"] << "'" << endl;
            exit(-1);
        }

        if ("hardware" == options["target"])
        {
            cout << "Restoring from " << options["restore"] << " to hardware." << endl;
            bcmflash_nvram_write("nvram", nvram.words, nvm_size);
        }
        else
        {
            // Write back to infile
        }
    }

    if (options.is_set("backup"))
    {
        if ("binary" == options["backup"])
        {
            // Save to file.
            if (!bcmflash_file_write("firmware.fw", nvram.bytes, nvm_size))
            {
                exit(-1);
            }
        }
        else if ("extract" == options["backup"])
        {
            extract = true;
        }
        else
        {
            cerr << "Invalid backup type specified." << endl;
            parser.print_help();
            exit(-1);
        }
    }

    stage1 = &nvram.bytes[be32toh(nvram.contents.header.bootstrapOffset)];
    stage1_wd = &nvram.words[be32toh(nvram.contents.header.bootstrapOffset) / 4];
    size_t stage1_length = (be32toh(nvram.contents.header.bootstrapWords) * 4) - 4; // last word is CRC
    uint32_t crc_word = stage1_length / 4;

    dump_stage1(&nvram.contents, stage1, stage1_length);

    if (extract)
    {

        if (!bcmflash_file_write("stage1.bin", stage1, stage1_length))
        {
            exit(-1);
        }
    }

    if (options.is_set("stage1"))
    {
        const char *stage1_file = options["stage1"].c_str();
        printf("Updating stage1 with contents of file %s\n", stage1_file);

        uint32_t new_stage1_length = bcmflash_file_size(stage1_file);

        if (0 == new_stage1_length)
        {
            cerr << " Unable to open file '" << options["stage1"] << "'" << endl;
            exit(-1);
        }
        else if (new_stage1_length > stage1_length)
        {
            cerr << "Length is longer than original, currently unable to update." << endl;
            exit(-1);
        }
        else
        {
            bcmflash_file_read(stage1_file, stage1, new_stage1_length);

            while (new_stage1_length < stage1_length)
            {
                // erase remaining bytes.
                stage1[new_stage1_length] = 0xFF;
                new_stage1_length++;
            }

            uint32_t new_crc = be32toh(~NVRam_crc(stage1, new_stage1_length, 0xffffffff));
            printf("New CRC:             0x%08X\n", new_crc);
            printf("New Length (bytes):  0x%08X\n", new_stage1_length);

            // Update the CRC in the file copy.
            stage1_wd[crc_word] = htobe32(new_crc);

            dump_stage1(&nvram.contents, stage1, new_stage1_length);

            should_write = true;
        }
    }

    uint32_t *stage2_wd = &stage1_wd[(crc_word + 1)]; // immediately after stage1 crc
    NVRAMStage2_t *stage2 = (NVRAMStage2_t *)stage2_wd;
    uint32_t stage2_length = be32toh(stage2->header.length); // second word is size (bytes).
    stage2_length -= 4;                                      // length includes crc.

    dump_stage2(stage2);

    if (extract)
    {
        if (!bcmflash_file_write("stage2.bin", stage2->words, stage2_length))
        {
            exit(-1);
        }
    }

    for (int i = 0; i < ARRAY_ELEMENTS(nvram.contents.directory); i++)
    {
        char *cd_name = NULL;
        if (extract)
        {
            cd_name = strdup("cdN.bin");
            cd_name[2] = '0' + i;
        }

        dump_code_directory(&nvram.contents.directory[i], nvram.bytes, cd_name);
        free(cd_name);
    }

    if (options.is_set("ape"))
    {
        if (NULL == gApe)
        {
            fprintf(stderr, "Original APE entry was not found in firmware header.");
            exit(-1);
        }
        const char *ape_file = options["ape"].c_str();
        printf("Updating ape with contents of file %s\n", ape_file);

        uint32_t new_ape_length = bcmflash_file_size(ape_file);

        if (0 == new_ape_length)
        {
            cerr << " Unable to open file '" << options["ape"] << "'" << endl;
            exit(-1);
        }
        else if (new_ape_length + sizeof(uint32_t) > gApeLength)
        {
            cerr << "Length is longer than original, currently unable to update." << endl;
            exit(-1);
        }
        else
        {
            bcmflash_file_read(ape_file, (char *)gApe, new_ape_length);
            new_ape_length += sizeof(uint32_t); /* CRC */

#if 0
            // Erase the previous APE image
            while(new_ape_length < ape_length)
            {
                // erase remaining bytes.
                ape[new_ape_length] = 0xFF;
                new_ape_length++;
            }
#endif

            if (gApeWd[0] == APE_HEADER_MAGIC)
            {
                // Ensure everything is in the correct endianness.
                for (int i = 0; i < (new_ape_length - 4) / 4; i++)
                {
                    gApeWd[i] = be32toh(gApeWd[i]);
                }
            }

            uint32_t new_ape_crc = be32toh(~NVRam_crc(gApe, gApeLength - sizeof(uint32_t), 0xffffffff));

            printf("New Length (bytes):  0x%08X\n", new_ape_length);
            printf("New CRC:  0x%08X\n", new_ape_crc);
            uint32_t *crc_loc = (uint32_t *)&gApe[gApeLength - sizeof(uint32_t)];
            *crc_loc = htobe32(new_ape_crc);

            // TODO: update length (if changed);

            should_write = true;
        }
    }

    if (should_write)
    {
        if ("file" == options["target"] || options.get("create"))
        {
            // write update file.
            if (!bcmflash_file_write(options["filename"].c_str(), nvram.bytes, nvm_size))
            {
                exit(-1);
            }
        }
        else if ("hardware" == options["target"])
        {
            bcmflash_nvram_write("nvram", nvram.words, nvm_size);
        }

        exit(0);
    }

    dump_info(&nvram.contents.info, &nvram.contents.info2);

    dump_vpd(nvram.contents.vpd.bytes, sizeof(nvram.contents.vpd));

    return 0;
}
