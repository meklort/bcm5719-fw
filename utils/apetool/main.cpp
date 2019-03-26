////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.cpp
///
/// @project
///
/// @brief      Main ape tool for parsing BCM5179 APE images.
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

#define MAX_SIZE      (1024u * 256u) /* 256KB - max NVRAM */
int main(int argc, char const *argv[])
{
    union {
        uint8_t     bytes[MAX_SIZE];
        uint32_t    words[MAX_SIZE/4];
        APEHeader_t header;
    } ape;

    OptionParser parser = OptionParser().description("BCM APE Utility");

    parser.add_option("-f", "--file")
            .dest("filename")
            .help("Read from the specified file")
            .metavar("FILE");


    parser.add_option("-q", "--quiet")
            .action("store_false")
            .dest("verbose")
            .set_default("1")
            .help("don't print status messages to stdout");

    optparse::Values options = parser.parse_args(argc, argv);
    vector<string> args = parser.args();

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
        infile.read((char*)ape.bytes, MAX_SIZE);

        // The file is swapped... fix it.
        for(int i = 0; i < sizeof(ape)/sizeof(ape.words[0]); i++)
        {
            ape.words[i] = be32toh(ape.words[i]);
        }

        infile.close();
    }
    else
    {
        cerr << " Unable to open file '" << options["filename"] << "'" << endl;
        exit(-1);
    }

    printf("=== Header ===\n");
    printf("Magic:              0x%08X\n", ape.header.magic);
    printf("UNK0:               0x%08X\n", ape.header.unk0);

    char name[sizeof(ape.header.name) + 1] = {0};
    strncpy(name, (char*)ape.header.name, sizeof(ape.header.name));
    printf("Name:               %s\n", name);
    printf("Version:            0x%08X\n", ape.header.version);
    printf("Start:              0x%08X\n", ape.header.entrypoint);

    printf("UNK1:               0x%02X\n", ape.header.unk1);
    printf("Header Size:        %d\n", ape.header.words * 4);
    printf("UNK2:               0x%02X\n", ape.header.unk2);
    printf("Sections:           %d\n", ape.header.sections);

    printf("CRC:                0x%08X\n", ape.header.crc);

    ape.header.crc = 0;
    uint32_t calculated_crc = NVRam_crc(ape.bytes, (4 * ape.header.words), 0);
    printf("Calculated CRC:     0x%08X\n", calculated_crc);

    for(int i = 0; i < ape.header.sections; i++)
    {
        APESection_t* section = &ape.header.section[i];

        printf("\n=== Section %i ===\n", i);
        printf("Load Addr:          0x%08X\n", section->loadAddr);

        printf("Offset:             0x%08X\n", section->offset);
        printf("Flags:              0x%08X\n", section->flags);
        if(section->flags & APE_SECTION_FLAG_COMPRESSED)
        {
            printf("    compressed\n");
        }
        if(section->flags & APE_SECTION_FLAG_CHECKSUM_IS_CRC32)
        {
            printf("    crc32\n");
        }
        printf("    %s\n", section->flags & APE_SECTION_FLAG_CODE ? "code" : "data");
        if(section->flags & APE_SECTION_FLAG_UNK0)
        {
            printf("    unknown\n");
        }
        if(section->flags & APE_SECTION_FLAG_ZERO_ON_FAST_BOOT)
        {
            printf("    bss\n");
        }
        printf("Decompressed Size:  0x%08X\n", section->decompressedSize);
        printf("Compressed Size:    0x%08X\n", section->compressedSize);
        printf("CRC:                0x%08X\n", section->crc);
    }


    return 0;
}
