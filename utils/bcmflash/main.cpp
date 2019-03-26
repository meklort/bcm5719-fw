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

#include "../NVRam/bcm5719_NVM.h"

using namespace std;
using optparse::OptionParser;


bool save_to_file(const char* filename, void* buffer, size_t size)
{
    cout << "Writing to " << filename << "." << endl;
    FILE* out = fopen(filename, "w+");
    if(out)
    {
        fwrite(buffer, size, 1, out);
        fclose(out);
        return true;
    }
    else
    {
        cerr << "Unable to open " << filename << " for writing." << endl;
        return false;
    }
}

#define NVRAM_SIZE      (1024u * 256u) /* 256KB */
int main(int argc, char const *argv[])
{
    bool extract = false;
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

    parser.add_option("-b", "--backup")
            .dest("backup")
            .metavar("TYPE")
            .help(  "Backup the firmware to the specified file.\n"
                    "binary:  Save a raw binary copy of the firmware to firmware.fw.\n"
                    "extract: Save each individual stage to <stage>.fw.\n");

    parser.add_option("-r", "restore")
            .dest("restore")
            .help("Update the target device to match the specified file.")
            .metavar("FILE");


    parser.add_option("-1", "--stage1")
            .dest("stage1")
            .help("Update the target with the specified stage1 image, if possible.")
            .metavar("STAGE1");

    parser.add_option("-2", "--stage2")
            .dest("stage2")
            .help("Update the target with the specified stage2 image, if possible.")
            .metavar("STAGE2");

    parser.add_option("-u", "--unlock")
            .dest("unlock")
            .action("store_true")
            .set_default("0")
            .help("Clear all NVM locks.")
            .metavar("STAGE1");

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
        if(!initHAL(NULL))
        {
            exit(-1);
        }

        printf("ChipId: %x\n", (uint32_t)DEVICE.ChipId.r32);

        if(options.get("unlock"))
        {
            NVM.SoftwareArbitration.bits.ReqClr0 = 1;
            NVM.SoftwareArbitration.bits.ReqClr1 = 1;
            NVM.SoftwareArbitration.bits.ReqClr2 = 1;
            NVM.SoftwareArbitration.bits.ReqClr3 = 1;
        }


        NVRam_acquireLock();

        NVRam_enable();

        NVRam_read(0, nvram.words, NVRAM_SIZE / 4);

        NVRam_releaseLock();
    }
    else
    {
        cerr << "Please specify a target." << endl;
        parser.print_help();
        exit(-1);
    }

    if(options.is_set("restore"))
    {
        fstream restoreFile;
        restoreFile.open(options["restore"], fstream::in | fstream::binary);
        if(restoreFile.is_open())
        {
            restoreFile.read((char*)nvram.bytes, NVRAM_SIZE);

            restoreFile.close();
        }
        else
        {
            cerr << " Unable to open file '" << options["restore"] << "'" << endl;
            exit(-1);
        }

        if("hardware" == options["target"])
        {
            NVRam_acquireLock();

            NVRam_enable();
            NVRam_enableWrites();

            NVRam_write(0, nvram.words, NVRAM_SIZE / 4);

            NVRam_disableWrites();

            NVRam_releaseLock();
        }
        else
        {
            // Write back to infile
        }
    }


    if(options.is_set("backup"))
    {
        if("binary" ==  options["backup"])
        {
            // Save to file.
            if(!save_to_file("firmware.fw", nvram.bytes, NVRAM_SIZE))
            {
                exit(-1);
            }
        }
        else if ("extract" ==  options["backup"])
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

    uint8_t* stage1 = &nvram.bytes[be32toh(nvram.contents.header.bootstrapOffset)];
    uint32_t* stage1_wd = &nvram.words[be32toh(nvram.contents.header.bootstrapOffset)/4];
    size_t stage1_length = (be32toh(nvram.contents.header.bootstrapWords) * 4) - 4; // last word is CRC

    uint32_t crc_word = stage1_length / 4;

    uint32_t expected_crc = be32toh(~NVRam_crc(stage1, stage1_length, 0xffffffff));
    printf("=== stage1 ===\n");
    printf("Magic:               0x%08X\n", be32toh(nvram.contents.header.magic));
    printf("Bootstrap Phys Addr: 0x%08X\n",
           be32toh(nvram.contents.header.bootstrapPhysAddr));
    printf("Length (bytes):      0x%08zX\n", stage1_length);
    printf("Offset:              0x%08lX\n", ((stage1_wd - nvram.words) * 4));
    printf("Calculated CRC:      0x%08X\n", expected_crc);
    printf("CRC:                 0x%08X\n", be32toh(stage1_wd[crc_word]));

    if(be32toh(nvram.contents.header.magic) != BCM_NVRAM_MAGIC)
    {
        fprintf(stderr, "Error: stage1 magic is invalid.\n");
        exit(-1);
    }

    if(be32toh(stage1_wd[crc_word]) != expected_crc)
    {
        fprintf(stderr, "Error: stage1 crc is invalid.\n");
        // exit(-1);
    }

    if(extract)
    {

        if(!save_to_file("stage1.bin", stage1, stage1_length))
        {
            exit(-1);
        }
    }

    if(options.is_set("stage1"))
    {
        const char* stage1_file = options["stage1"].c_str();
        printf("Updating stage1 with contents of file %s\n", stage1_file);

        fstream infile;
        infile.open(stage1_file, fstream::in | fstream::binary | fstream::ate);

        if(infile.is_open())
        {
            uint32_t new_stage1_length = infile.tellg();
            infile.seekg(0);

            if(new_stage1_length > stage1_length)
            {
                cerr << "Length is longer than original, currently unable to update." << endl;
                exit(-1);
            }
            else
            {
                // Overwrite position
                infile.read((char*)stage1, new_stage1_length);
                infile.close();

                while(new_stage1_length < stage1_length)
                {
                    // erase remaining bytes.
                    stage1[new_stage1_length] = 0xFF;
                    new_stage1_length++;
                }
            }

            uint32_t new_crc = be32toh(~NVRam_crc(stage1, new_stage1_length, 0xffffffff));
            printf("New CRC:             0x%08X\n", new_crc);
            printf("New Length (bytes):  0x%08X\n", new_stage1_length);

            // Update the CRC in the file copy.
            stage1_wd[crc_word] = htobe32(new_crc);

            // TODO: update length (if changed);

            if("file" == options["target"])
            {
                // write update file.
                if(!save_to_file(options["filename"].c_str(), (char*)nvram.bytes, NVRAM_SIZE))
                {
                    exit(-1);
                }
            }

            if("hardware" == options["target"])
            {
                NVRam_acquireLock();

                NVRam_enable();
                NVRam_enableWrites();

                NVRam_write(0, nvram.words, NVRAM_SIZE / 4);

                NVRam_disableWrites();

                NVRam_releaseLock();
            }
        }
        else
        {
            cerr << " Unable to open file '" << options["filename"] << "'" << endl;
            exit(-1);
        }
        exit(1);
    }



    uint32_t* stage2_wd =  &stage1_wd[(crc_word + 1)]; // immediately after stage1 crc
    NVRAMStage2_t *stage2 = (NVRAMStage2_t*)stage2_wd;

    uint32_t stage2_length = be32toh(stage2->header.length); // second word is size (bytes).
    stage2_length -= 4; // length includes crc.
    uint32_t stage2_crc_word = stage2_length / 4;
    printf("=== stage2 ===\n");
    printf("Magic:               0x%08X\n", be32toh(stage2->header.magic));
    printf("Length (bytes):      0x%08X\n", stage2_length);
    printf("Offset:              0x%08lX\n", ((stage2_wd - nvram.words) * 4));
    uint32_t stage2_expected_crc = be32toh(~NVRam_crc((uint8_t*)stage2->words, stage2_length, 0xffffffff));
    printf("Calculated CRC:      0x%08X\n", stage2_expected_crc);
    printf("CRC:                 0x%08X\n", be32toh(stage2->words[stage2_crc_word]));

    if(be32toh(stage2->header.magic) != BCM_NVRAM_MAGIC)
    {
        fprintf(stderr, "Error: stage2 magic is invalid.\n");
        exit(-1);
    }

    if(be32toh(stage2->words[stage2_crc_word]) != stage2_expected_crc)
    {
        fprintf(stderr, "Error: stage2 crc is invalid.\n");
        exit(-1);
    }

    if(extract)
    {
        if(!save_to_file("stage2.bin", stage2->words, stage2_length))
        {
            exit(-1);
        }
    }

#if 1
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
            printf("Code Words:     0x%08X (%ld bytes)\n", length, length * sizeof(uint32_t));
            printf("Code Offset:    0x%08X\n",
                   be32toh(nvram.contents.directory[i].directoryOffset));
            printf("Code CPU:       0x%02X\n", cpu);
            printf("Code Type:      0x%02X\n", type);
            printf("\n");

            if(extract)
            {
                uint8_t* cd_loc = &nvram.bytes[be32toh(nvram.contents.directory[i].directoryOffset)];
                char* cd_name = strdup("cdN.bin");
                cd_name[2] = '0' + i;
                if(!save_to_file(cd_name, cd_loc, length * sizeof(uint32_t)))
                {
                    exit(-1);
                }
                free(cd_name);
            }
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
    printf("Subsystem ID: 0x%04X\n",
           be16toh(nvram.contents.info.subsystemDeviceID));

    printf("Function 0S Subsystem ID 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF0SERDES));
    printf("Function 1S Subsystem ID 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF1SERDES));
    printf("Function 2S Subsystem ID 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF2SERDES));
    printf("Function 3S Subsystem ID 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF3SERDES));
    printf("Function 0G Subsystem ID 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF0GPHY));
    printf("Function 1G Subsystem ID 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF1GPHY));
    printf("Function 2G Subsystem ID 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF2GPHY));
    printf("Function 3G Subsystem ID 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF3GPHY));


    printf("Shared Cfg:     0x%08X\n", be32toh(nvram.contents.info.cfgShared));

    printf("Power Dissipated: 0x%02X 0x%02X 0x%02X 0x%02X\n",
           nvram.contents.info.powerDissipatedD3, nvram.contents.info.powerDissipatedD2,
           nvram.contents.info.powerDissipatedD1, nvram.contents.info.powerDissipatedD0);

    printf("Power Consumed:   0x%02X 0x%02X 0x%02X 0x%02X\n",
           nvram.contents.info.powerConsumedD3, nvram.contents.info.powerConsumedD2,
           nvram.contents.info.powerConsumedD1, nvram.contents.info.powerConsumedD0);

    // Print out power budget (and translated values).
    uint32_t pb_raw[8];
    pb_raw[0] = be32toh(nvram.contents.info.powerBudget0) & 0xffff;
    pb_raw[1] = be32toh(nvram.contents.info.powerBudget0) >> 16;
    pb_raw[2] = be32toh(nvram.contents.info.powerBudget1) & 0xffff;
    pb_raw[3] = be32toh(nvram.contents.info.powerBudget1) >> 16;
    pb_raw[4] = be32toh(nvram.contents.info.powerBudget2) & 0xffff;
    pb_raw[5] = be32toh(nvram.contents.info.powerBudget2) >> 16;
    pb_raw[6] = be32toh(nvram.contents.info.powerBudget3) & 0xffff;
    pb_raw[7] = be32toh(nvram.contents.info.powerBudget3) >> 16;
    printf("Power Budget0:    0x%04X%04X\n", pb_raw[1], pb_raw[0]);
    printf("Power Budget1:    0x%04X%04X\n", pb_raw[3], pb_raw[2]);
    printf("Power Budget2:    0x%04X%04X\n", pb_raw[5], pb_raw[4]);
    printf("Power Budget3:    0x%04X%04X\n", pb_raw[7], pb_raw[6]);

    for(int i = 0; i < ARRAY_ELEMENTS(pb_raw); i++)
    {
        uint32_t raw = pb_raw[i];
        RegDEVICEPciPowerBudget0_t pb0;
        pb0.r32 = 0;
        if(raw)
        {
            pb0.bits.BasePower = raw & 0xFF;
            pb0.bits.DataScale = DEVICE_PCI_POWER_BUDGET_0_DATA_SCALE_0_1X;
            pb0.bits.PMState   = (raw & 0x0300) >> 8;
            pb0.bits.Type      = (raw & 0x1C00) >> 10;
            pb0.bits.PowerRail = (raw & 0xE000) >> 13;
        }

        printf("Translated Power Budget[%d]:    0x%08X\n", i, (uint32_t)pb0.r32);
    }


    printf("\n=== Port 0 ===\n");
    printf("Subsystem ID: 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF0GPHY));
    printf("MAC:        0x%04X%08X\n", be32toh(nvram.contents.info.macAddr0[0]), be32toh(nvram.contents.info.macAddr0[1]));
    printf("Feature:    0x%08X\n", be32toh(nvram.contents.info.func0CfgFeature));
    printf("Cfg:        0x%08X\n", be32toh(nvram.contents.info.func0CfgHW));
    printf("Cfg2:       0x%08X\n", be32toh(nvram.contents.info2.func0CfgHW2));

    printf("\n=== Port 1 ===\n");
    printf("Subsystem ID: 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF1GPHY));
    printf("MAC:        0x%04X%08X\n", be32toh(nvram.contents.info.macAddr1[0]), be32toh(nvram.contents.info.macAddr1[1]));
    printf("Feature:    0x%08X\n", be32toh(nvram.contents.info.func1CfgFeature));
    printf("Cfg:        0x%08X\n", be32toh(nvram.contents.info.func1CfgHW));
    printf("Cfg2:       0x%08X\n", be32toh(nvram.contents.info2.func1CfgHW2));

    printf("\n=== Port 2 ===\n");
    printf("Subsystem ID: 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF2GPHY));
    printf("MAC:        0x%04X%08X\n", be32toh(nvram.contents.info2.macAddr2[0]), be32toh(nvram.contents.info2.macAddr2[1]));
    printf("Feature:    0x%08X\n", be32toh(nvram.contents.info2.func2CfgFeature));
    printf("Cfg:        0x%08X\n", be32toh(nvram.contents.info2.func2CfgHW));
    printf("Cfg2:       0x%08X\n", be32toh(nvram.contents.info2.func2CfgHW2));

    printf("\n=== Port 3 ===\n");
    printf("Subsystem ID: 0x%04X\n", be16toh(nvram.contents.info2.pciSubsystemF3GPHY));
    printf("MAC:        0x%04X%08X\n", be32toh(nvram.contents.info2.macAddr3[0]), be32toh(nvram.contents.info2.macAddr3[1]));
    printf("Feature:    0x%08X\n", be32toh(nvram.contents.info2.func3CfgFeature));
    printf("Cfg:        0x%08X\n", be32toh(nvram.contents.info2.func3CfgHW));
    printf("Cfg2:       0x%08X\n", be32toh(nvram.contents.info2.func3CfgHW2));

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
                printf("[%c%c] %24s: %s\n", name & 0xff, name >> 8, vpd_get_field_name(name),
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
