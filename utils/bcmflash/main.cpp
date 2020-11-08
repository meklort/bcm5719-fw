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

#include "bcmflash.h"
#include "create_header.h"
#ifdef CONFIG_HAVE_LINUX_ETHTOOL_H
#include "ethtool.h"
#endif

#include <../bcm5719_NVM.h>
#include <NVRam.h>
#include <OptionParser.h>
#include <bcm5719-endian.h>
#include <bcm5719_DEVICE.h>
#include <bcm5719_eeprom.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>

#define VERSION_STRING STRINGIFY(VERSION_MAJOR) "." STRINGIFY(VERSION_MINOR) "." STRINGIFY(VERSION_PATCH)

#define MAX_NVRAM_SIZE (512u * 1024u) /* Allow up to 512KB flash size */

using namespace std;
using optparse::OptionParser;

uint32_t gApeLength = 0;
uint8_t *gApe = NULL;
uint32_t *gApeWd = NULL;

uint8_t *gVPD = NULL;
uint32_t gVPDLength = 0;

typedef struct
{
    const char *type;
    const char *type_help;
    const char *name_help;
    bool (*read)(const char *name, void *buffer, size_t len);
    bool (*write)(const char *name, void *buffer, size_t len);
    bool (*lock)(const char *name);
    bool (*unlock)(const char *name);
    size_t (*size)(const char *name);
} storage_t;

storage_t gStorage[] = {
    {
        .type = "raw",
        .type_help = "Use the attached physical device (driver must be unloaded).",
        .name_help = "The PCI function to use for register access.",
        .read = bcmflash_nvram_read,
        .write = bcmflash_nvram_write,
        .size = bcmflash_nvram_size,
    },
#ifdef CONFIG_HAVE_LINUX_ETHTOOL_H
    {
        .type = "eth",
        .type_help = "Use the specified network interface (tg3 driver must be loaded).",
        .name_help = "The network interface to access.",
        .read = bcmflash_ethtool_read,
        .write = bcmflash_ethtool_write,
        .size = bcmflash_ethtool_size,
    },
#endif
    {
        .type = "file",
        .type_help = "Use the file specified.",
        .name_help = "The file to access.",
        .read = bcmflash_file_read,
        .write = bcmflash_file_write,
        .size = bcmflash_file_size,
    },
};

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

        if (BCM_CODE_DIRECTORY_CPU_APE == cpu) /* APE */
        {
            gApe = &nvram[be32toh(cd->directoryOffset)];
            gApeWd = (uint32_t *)gApe;
            gApeLength = length * sizeof(uint32_t);
        }

        if (BCM_CODE_DIRECTORY_CPU_VPD == cpu) /* Extended VPD */
        {
            gVPD = &nvram[be32toh(cd->directoryOffset)];
            gVPDLength = length * sizeof(uint32_t);
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

bool set_mac(uint32_t dest[2], const char *mac_str)
{
    const int num_octets = 6;
    uint64_t mac = 0;
    char *endptr;
    for (int i = 0; i < num_octets; i++)
    {
        long int octet = strtol(mac_str, &endptr, 16);
        if (i < num_octets - 1 && *endptr != ':')
        {
            // Octets must be seperated by :.
            return false;
        }

        if (i == num_octets - 1 && *endptr != '\0')
        {
            // Must only have 6 octets
            return false;
        }

        if (endptr != mac_str + 2)
        {
            // Must have two digets
            return false;
        }

        if ((octet & 0xFF) != octet)
        {
            // Invalid - must only be a single byte.
            return false;
        }

        mac = octet | (mac << 8);

        mac_str = endptr + 1;
    }

    dest[0] = htobe32((mac >> 32) & 0xFFFF);
    dest[1] = htobe32(mac & 0xFFFFFFff);

    return true;
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

    printf("\n=== SMBus ===\n");
    printf("Device Address: 0x%02X\n", info->SMBusAddr);
    printf("BMC Address:    0x%02X\n", info->SMBusAddrBMC);
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

int main(int argc, char const *argv[])
{
    bool extract = false;
    bool should_write = false;
    const char *target_name = NULL;

    union
    {
        uint8_t bytes[MAX_NVRAM_SIZE];
        uint32_t words[MAX_NVRAM_SIZE / 4];
        NVRAMContents_t contents;
    } nvram = { { 0 } };
    uint32_t nvram_size = 0;

    uint8_t *stage1 = NULL;
    uint32_t *stage1_wd = NULL;

    gVPD = nvram.contents.vpd.bytes;
    gVPDLength = sizeof(nvram.contents.vpd);

    struct
    {
        const char *option;
        int port;
        uint32_t *dest;
    } mac_table[] = {
        { .option = "mac0", .port = 0, .dest = nvram.contents.info.macAddr0 },
        { .option = "mac1", .port = 1, .dest = nvram.contents.info.macAddr1 },
        { .option = "mac2", .port = 2, .dest = nvram.contents.info2.macAddr2 },
        { .option = "mac3", .port = 3, .dest = nvram.contents.info2.macAddr3 },
    };

    OptionParser parser = OptionParser().description("BCM Flash Utility v" VERSION_STRING);

    parser.version(VERSION_STRING);

    string target_type_help;
    string target_name_help;
    std::list<std::string> target_options;
    for (int i = 0; i < ARRAY_ELEMENTS(gStorage); i++)
    {
        target_type_help += gStorage[i].type;
        target_type_help += ": ";
        target_type_help += gStorage[i].type_help;
        target_type_help += "\n";

        target_name_help += gStorage[i].type;
        target_name_help += ": ";
        target_name_help += gStorage[i].name_help;
        target_name_help += "\n";

        target_options.push_back(gStorage[i].type);
    }

    parser.add_option("-t", "--target-type").choices(target_options.begin(), target_options.end()).dest("target_type").help(target_type_help);

    parser.add_option("-i", "--target-name").dest("target_name").help(target_name_help).metavar("TARGET_NAME");

    parser.add_option("--nvm-recovery")
        .dest("recovery")
        .action("store_true")
        .set_default("0")
        .help("Recover form an incorrect NVM autodetection. Only valid with the raw TARGET_TYPE");

    parser.add_option("-b", "--backup")
        .choices({ "binary", "extract" })
        .dest("backup")
        .metavar("TYPE")
        .help("Backup the firmware to the specified file.\n"
              "binary:  Save a raw binary copy of the firmware to firmware.fw.\n"
              "extract: Save each individual stage to <stage>.fw.\n");

    parser.add_option("-r", "restore").dest("restore").help("Update the target device to match the specified file.").metavar("FILE");

    parser.add_option("-c", "--create").choices({ "talos2", "blackbird", "kh08p" }).dest("create").help("Create a full firmware image for use with fwupd.");

    for (size_t i = 0; i < ARRAY_ELEMENTS(mac_table); i++)
    {
        std::string option = "--" + std::string(mac_table[i].option);
        std::string help = "Update the MAC address for port " + std::to_string(mac_table[i].port) + ". Format: 01:23:45:67:89:AB";
        parser.add_option(option).dest(mac_table[i].option).help(help);
    }

    parser.add_option("-1", "--stage1").dest("stage1").help("Update the target with the specified stage1 image, if possible.").metavar("STAGE1");

    parser.add_option("-a", "--ape").dest("ape").help("Update the target with the specified ape image, if possible.").metavar("APE");

    parser.add_option("-u", "--unlock")
        .dest("unlock")
        .action("store_true")
        .set_default("0")
        .help("Clear all NVM locks. Only valid with the raw TARGET_TYPE")
        .metavar("UNLOCK");

    parser.add_option("-q", "--quiet").action("store_false").dest("verbose").set_default("1").help("don't print status messages to stdout");

    optparse::Values options = parser.parse_args(argc, argv);
    vector<string> args = parser.args();
    storage_t *target = NULL;

    for (int i = 0; i < ARRAY_ELEMENTS(gStorage); i++)
    {
        if (gStorage[i].type == options["target_type"])
        {
            target = &gStorage[i];
            break;
        }
    }

    if (!target)
    {
        parser.error("Please specify a target type to use.");
    }

    if (!options.is_set("target_name"))
    {
        parser.error("Please specify a target name to use.");
    }
    target_name = options["target_name"].c_str();

    // Treat raw NVM access as a special case for now.
    if ("raw" == options["target_type"])
    {
        if (!bcmflash_nvram_init(target_name))
        {
            cerr << "Unable to open '" << options["target_type"] << ":" << target_name << "'." << endl;
            exit(-1);
        }

        if (options.get("recovery"))
        {
            bcmflash_nvram_recovery();

            exit(0);
        }

        if (options.get("unlock"))
        {
            bcmflash_nvram_unlock();
        }
    }

    if (options.is_set("create"))
    {
        // Default to erased flash contents.
        memset(nvram.words, -1, sizeof(nvram.words));
        memset(&nvram.contents.vpd, 0, sizeof(nvram.contents.vpd));

        init_firmware_header(&nvram.contents, options["create"].c_str());

        if (options.is_set("stage1"))
        {
            uint32_t new_stage1_length = bcmflash_file_size(options["stage1"].c_str());

            if (new_stage1_length)
            {
                nvram.contents.header.bootstrapWords = htobe32(1 + ((new_stage1_length + 3) / 4));
            }
            else
            {
                cerr << "Unable to open '" << options["stage1"] << "'." << endl;
                exit(-1);
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

        if (options.is_set("ape"))
        {
            uint32_t ape_length = bcmflash_file_size(options["ape"].c_str());

            if (!ape_length)
            {
                cerr << "Unable to open '" << options["ape"] << "'." << endl;
                exit(-1);
            }

            // Allocate space for the code directory CRC.
            ape_length += sizeof(uint32_t);

            uint32_t info = 0;

            ape_length = DIVIDE_RND_UP(ape_length, sizeof(uint32_t));
            info = BCM_CODE_DIRECTORY_SET_LENGTH(info, ape_length);
            info = BCM_CODE_DIRECTORY_SET_CPU(info, BCM_CODE_DIRECTORY_CPU_APE);
            info = BCM_CODE_DIRECTORY_SET_TYPE(info, 0);
            nvram.contents.directory[0].codeInfo = htobe32(info);
            nvram.contents.directory[0].codeAddress = htobe32(BCM_CODE_DIRECTORY_ADDR_APE);
            nvram.contents.directory[0].directoryOffset = htobe32(4 * (&stage2->words[1] - nvram.words));

            nvram_size = sizeof(uint32_t) * ((&stage2->words[1] - nvram.words) + ape_length);
        }
    }
    else
    {
        // Read the target file
        nvram_size = target->size(target_name);
        if (nvram_size > MAX_NVRAM_SIZE)
        {
            cerr << "Unable to handle NVRAM size of " << nvram_size << " bytes.";
            exit(-1);
        }

        if (!target->read(target_name, nvram.bytes, nvram_size))
        {
            cerr << "Unable to read nvram from target '" << options["target_type"] << ":" << target_name << "'" << endl;
            exit(-1);
        }

        if (options.is_set("restore"))
        {
            if (!bcmflash_file_read(options["restore"].c_str(), nvram.bytes, nvram_size))
            {
                cerr << " Unable to open file '" << options["restore"] << "'" << endl;
                exit(-1);
            }

            cout << "Restoring from " << options["restore"] << " to '" << options["target_type"] << ":" << target_name << "'." << endl;

            target->write(target_name, nvram.bytes, nvram_size);
        }

        if (options.is_set("backup"))
        {
            if ("binary" == options["backup"])
            {
                // Save to file.
                if (!bcmflash_file_write("firmware.fw", nvram.bytes, nvram_size))
                {
                    exit(-1);
                }
            }
            else if ("extract" == options["backup"])
            {
                extract = true;
            }
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

    for (size_t i = 0; i < ARRAY_ELEMENTS(mac_table); i++)
    {
        if (options.is_set(mac_table[i].option))
        {
            should_write = true;
            if (!set_mac(mac_table[i].dest, options[mac_table[i].option].c_str()))
            {
                parser.error("Invalid MAC address format.");
            }
        }
    }

    if (should_write)
    {
        // Fixup the firmware header now that all information is up to date.
        fixup_firmware_header(&nvram.contents);
        printf("Header CRC: %x\n", nvram.contents.header.crc);

        // write updated nvram.
        if (!target->write(target_name, nvram.bytes, nvram_size))
        {
            exit(-1);
        }

        exit(0);
    }

    dump_info(&nvram.contents.info, &nvram.contents.info2);

    dump_vpd(gVPD, gVPDLength);

    if (extract)
    {
        if (!bcmflash_file_write("vpd.bin", nvram.contents.vpd.bytes, sizeof(nvram.contents.vpd)))
        {
            exit(-1);
        }

        if (gVPD != nvram.contents.vpd.bytes)
        {
            if (!bcmflash_file_write("vpd-e.bin", gVPD, gVPDLength))
            {
                exit(-1);
            }
        }
    }

    return 0;
}
