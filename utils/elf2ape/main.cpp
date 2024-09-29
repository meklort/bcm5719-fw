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

#include <Compress.h>
#include <NVRam.h>
#include <OptionParser.h>
#include <arpa/inet.h>
#include <bcm5719_eeprom.h>
#include <elfio/elfio.hpp>
#include <types.h>

#define VERSION_STRING STRINGIFY(VERSION_MAJOR) "." STRINGIFY(VERSION_MINOR) "." STRINGIFY(VERSION_PATCH)

using namespace ELFIO;

using namespace std;
using optparse::OptionParser;

uint64_t get_symbol_value(const char *search, elfio &reader)
{
    const symbol_section_accessor *psyms = NULL;
    Elf_Half sec_num = reader.sections.size();

    for (int i = 0; i < sec_num; ++i)
    {
        section *psec = reader.sections[i];
        // Check section type
        if (psec->get_type() == SHT_SYMTAB)
        {
            psyms = new symbol_section_accessor(reader, psec);
            break;
        }
    }

    if (psyms)
    {
        for (unsigned int j = 0; j < psyms->get_symbols_num(); ++j)
        {
            std::string name;
            Elf64_Addr value;
            Elf_Xword size;
            unsigned char bind;
            unsigned char type;
            Elf_Half section_index;
            unsigned char other;

            // Read symbol properties
            if (psyms->get_symbol(j, name, value, size, bind, type, section_index, other))
            {
                if (name == search)
                {
                    delete psyms;
                    return value;
                }
            }
        }

        delete psyms;
    }

    return 0;
}

bool save_to_file(const char *filename, void *buffer, size_t size)
{
    union caster
    {
        void *pv;
        uint32_t *p32;
    } caster;
    caster.pv = buffer;
    uint32_t *words = caster.p32;

    if (size % sizeof(uint32_t))
    {
        printf("Unexpected output size - must be a multiple of %lu\n", sizeof(uint32_t));
    }

    if (words[0] == htobe32(APE_HEADER_MAGIC))
    {
        // Expected BE image format
    }
    else if (words[0] == APE_HEADER_MAGIC)
    {
        // Image is stored BE in the non-volatile memeory. Swap it.
        for (size_t i = 0; i < (size / sizeof(uint32_t)); i++)
        {
            words[i] = htobe32(words[i]);
        }
    }
    else
    {
        printf("Unknown header 0x%08X\n", words[0]);
        return false;
    }

    cout << "Writing to " << filename << "." << endl;
    FILE *out = fopen(filename, "w+");
    if (out)
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

#define MAX_SIZE (1024u * 256u) /* 256KB - max NVRAM */
int main(int argc, char const *argv[])
{
    uint32_t byteOffset = 0;
    int numSections = 0;
    union
    {
        uint8_t bytes[MAX_SIZE];
        uint32_t words[MAX_SIZE / 4];
        APEHeader_t header;
    } ape;

    OptionParser parser = OptionParser().description("BCM ELF 2 APE Utility v" VERSION_STRING);

    parser.version(VERSION_STRING);

    parser.add_option("-i", "--input").dest("input").help("Input elf file to convert").metavar("FILE");

    parser.add_option("-o", "--output").dest("output").help("Output ape binary").metavar("OUTPUT");

    parser.add_option("-n", "--name").dest("name").help("APE Firmware Name").metavar("NAME");

    optparse::Values options = parser.parse_args(argc, argv);
    vector<string> args = parser.args();

    if (!options.is_set("input"))
    {
        cerr << "Please specify an input elf file to use." << endl;
        parser.print_help();
        exit(-1);
    }

    if (!options.is_set("output"))
    {
        cerr << "Please specify an output binary to write." << endl;
        parser.print_help();
        exit(-1);
    }

    elfio reader;

    if (!reader.load(options["input"]))
    {
        printf("File %s is not found or it is not a valid ELF file\n", argv[1]);
        return 1;
    }

    // Ensure that this is the correct elf type.
    if (reader.get_class() != ELFCLASS32 || reader.get_encoding() != ELFDATA2LSB || reader.get_machine() != EM_ARM || reader.get_type() != ET_EXEC)
    {
        printf("Only 32-bit little-endian arm binaries are supported\n");
        return 1;
    }

    // Determine number of output sections.
    Elf_Half seg_num = reader.segments.size();
    for (int i = 0; i < seg_num; ++i)
    {
        const segment *pseg = reader.segments[i];
        for (int j = 0; j < pseg->get_sections_num(); j++)
        {
            Elf_Half idx = pseg->get_section_index_at(j);
            section *psec = reader.sections[idx];
            if (psec->get_flags() & SHF_ALLOC)
            {
                numSections++;
            }
        }
    }

    byteOffset = (sizeof(ape.header) + sizeof(APESection_t) * numSections);
    // Print ELF file segments info
    std::cout << "Number of segments: " << seg_num << std::endl;
    numSections = 0;
    for (int i = 0; i < seg_num; ++i)
    {
        const segment *pseg = reader.segments[i];
        std::cout << "  [" << i << "] 0x" << std::hex << pseg->get_flags() << "\tVirt: 0x" << pseg->get_virtual_address() << "\tFileSize: 0x"
                  << pseg->get_file_size() << "\tSize: 0x" << pseg->get_memory_size() << "\tFlags: 0x" << pseg->get_flags() << std::endl;

        for (int j = 0; j < pseg->get_sections_num(); j++)
        {
            Elf_Half idx = pseg->get_section_index_at(j);
            section *psec = reader.sections[idx];
            if (psec->get_flags() & SHF_ALLOC)
            {
                std::cout << "    [" << j << "] " << psec->get_name() << "\t" << psec->get_size() << "\tType: 0x" << psec->get_type() << "\tFlags: 0x"
                          << psec->get_flags() << "\tAddr: 0x" << psec->get_address() << std::endl;

                APESection_t *section = &ape.header.section[numSections++];
                section->flags = 0;
                section->offset = byteOffset;

                const char *data = psec->get_data();
                if (data)
                {
                    uint32_t compressedSize = compress((uint8_t *)&ape.bytes[byteOffset],
                                                       sizeof(ape.bytes) - byteOffset, // Output, compressed
                                                       (const uint8_t *)data,
                                                       psec->get_size()); // input, uncompressed
                    // ROund up to nearest word.
                    compressedSize = ((compressedSize + 3) / 4) * 4;

                    section->compressedSize = compressedSize;
                    byteOffset += section->compressedSize;
                    // memcpy(&ape.bytes[byteOffset], compressed,
                    // section->compressedSize); byteOffset +=
                    // section->compressedSize;
                    section->crc = NVRam_crc((const uint8_t *)data, psec->get_size(), 0);
                    section->flags |= APE_SECTION_FLAG_CHECKSUM_IS_CRC32 | APE_SECTION_FLAG_COMPRESSED | (1u << 3);
                }
                else
                {
                    section->compressedSize = 0;
                    section->crc = 0;
                    section->flags |= APE_SECTION_FLAG_ZERO_ON_FAST_BOOT;
                }
                section->decompressedSize = psec->get_size();
                section->loadAddr = psec->get_address();

                if (psec->get_flags() & SHF_EXECINSTR)
                {
                    section->flags |= APE_SECTION_FLAG_CODE | (1u << 3);
                }
            }
        }
    }

    ape.header.magic = APE_HEADER_MAGIC;
    ape.header.unk0 = APE_HEADER_UNK0;
    // ape.header.name =
    if (options.is_set("name"))
    {
        string name = options["name"];
        name.resize(sizeof(ape.header.name) + 1, '\0');

        memcpy(ape.header.name, name.c_str(), sizeof(ape.header.name));
    }

    uint8_t version_major = get_symbol_value("VERSION_MAJOR", reader);
    uint8_t version_minor = get_symbol_value("VERSION_MINOR", reader);
    uint16_t version_patch = get_symbol_value("VERSION_PATCH", reader);
    ape.header.version = version_major << 24 | version_minor << 16 | htons(version_patch);
    ape.header.entrypoint = get_symbol_value("__start", reader);
    ape.header.unk1 = APE_HEADER_UNK1;
    ape.header.words = (sizeof(ape.header) + sizeof(APESection_t) * numSections) / 4;
    ape.header.unk2 = APE_HEADER_UNK2;
    ape.header.sections = numSections;
    ape.header.crc = 0;

    printf("Magic:              0x%08X\n", ape.header.magic);
    printf("UNK0:               0x%08X\n", ape.header.unk0);

    char name[sizeof(ape.header.name) + 1] = { 0 };
    memcpy(name, ape.header.name, sizeof(name) - 1);
    printf("Name:               %s\n", name);
    printf("Version:            0x%08X (%d.%d.%d)\n", ape.header.version, version_major, version_minor, version_patch);
    printf("Start:              0x%08X\n", ape.header.entrypoint);

    printf("UNK1:               0x%02X\n", ape.header.unk1);
    printf("Header Size:        %d\n", ape.header.words * 4);
    printf("UNK2:               0x%02X\n", ape.header.unk2);
    printf("Sections:           %d\n", ape.header.sections);
    for (int i = 0; i < ape.header.sections; i++)
    {
        APESection_t *section = &ape.header.section[i];
        std::cout << "  [" << i << "] Addr: 0x" << section->loadAddr << " - 0x" << section->decompressedSize + section->loadAddr << "\tSize 0x"
                  << section->decompressedSize << "\tCompressed Size 0x" << section->compressedSize << "\tOffset 0x" << section->offset << "\tEndOffset 0x"
                  << section->offset + section->compressedSize << "\tFlags 0x" << section->flags << std::endl;
    }

    uint32_t calculated_crc = NVRam_crc(ape.bytes, (4 * ape.header.words), 0);
    ape.header.crc = calculated_crc;
    printf("Calculated CRC:     0x%08X\n", calculated_crc);

    if (!save_to_file(options["output"].c_str(), ape.bytes, byteOffset))
    {
        exit(-1);
    }

    return 0;
}
