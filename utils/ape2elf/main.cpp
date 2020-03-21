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

#define ENTRYPOINT_SYMBOL "__start"
#define VERSION_MAJOR_SYMBOL "VERSION_MAJOR"
#define VERSION_MINOR_SYMBOL "VERSION_MINOR"
#define VERSION_PATCH_SYMBOL "VERSION_PATCH"
#define STACK_END_SYMBOL "_estack"
#define THUMB_CODE_SYMBOL "$t"

using namespace std;
using namespace ELFIO;
using optparse::OptionParser;

#define MAX_SIZE (1024u * 256u) /* 256KB - max NVRAM */
int main(int argc, char const *argv[])
{
    union
    {
        uint8_t bytes[MAX_SIZE];
        uint32_t words[MAX_SIZE / 4];
        APEHeader_t header;
    } ape;

    OptionParser parser = OptionParser().description("BCM APE to elf Utility");

    parser.add_option("-i", "--input").dest("input").help("Read from the input ape binary").metavar("FILE");

    parser.add_option("-o", "--output").dest("output").help("Save to the specified output elf file").metavar("FILE");

    optparse::Values options = parser.parse_args(argc, argv);
    vector<string> args = parser.args();

    if (!options.is_set("input"))
    {
        cerr << "Please specify an ape binary to use." << endl;
        parser.print_help();
        exit(-1);
    }

    fstream infile;
    infile.open(options["input"], fstream::in | fstream::binary);
    if (infile.is_open())
    {
        infile.read((char *)ape.bytes, MAX_SIZE);

        if (ape.words[0] == be32toh(APE_HEADER_MAGIC))
        {
            // The file is swapped... fix it.
            for (int i = 0; i < sizeof(ape) / sizeof(ape.words[0]); i++)
            {
                ape.words[i] = be32toh(ape.words[i]);
            }
        }

        infile.close();
    }
    else
    {
        cerr << " Unable to open file '" << options["filename"] << "'" << endl;
        exit(-1);
    }

    elfio writer;

    // Setup the elf header
    writer.create(ELFCLASS32, ELFDATA2LSB);
    writer.set_os_abi(ELFOSABI_NONE);
    writer.set_type(ET_EXEC);
    writer.set_machine(EM_ARM);

    // Create code section
    section *text_sec = writer.sections.add(".text");
    segment *text_seg = writer.segments.add();
    text_sec->set_type(SHT_PROGBITS);
    text_sec->set_flags(SHF_ALLOC | SHF_EXECINSTR);
    text_sec->set_addr_align(0x4);

    section *bss_sec = writer.sections.add(".bss");
    segment *bss_seg = writer.segments.add();
    bss_sec->set_type(SHT_PROGBITS);
    bss_sec->set_flags(SHF_ALLOC | SHF_WRITE);
    bss_sec->set_addr_align(0x4);

    section *data_sec = writer.sections.add(".data");
    segment *data_seg = writer.segments.add();
    data_sec->set_type(SHT_PROGBITS);
    data_sec->set_flags(SHF_ALLOC | SHF_WRITE);
    data_sec->set_addr_align(0x4);

    uint8_t version_major = (ape.header.version >> 24) & 0xFF;
    uint8_t version_minor = (ape.header.version >> 16) & 0xFF;
    uint16_t version_patch = ntohs(ape.header.version & 0xFFFF);

    printf("=== Header ===\n");
    printf("Magic:              0x%08X\n", ape.header.magic);
    printf("UNK0:               0x%08X\n", ape.header.unk0);

    char name[sizeof(ape.header.name) + 1] = { 0 };
    strncpy(name, (char *)ape.header.name, sizeof(ape.header.name));
    printf("Name:               %s\n", name);
    printf("Version:            0x%08X (%d.%d.%d)\n", ape.header.version, version_major, version_minor, version_patch);
    printf("Start:              0x%08X\n", ape.header.entrypoint);

    printf("UNK1:               0x%02X\n", ape.header.unk1);
    printf("Header Size:        %d\n", ape.header.words * 4);
    printf("UNK2:               0x%02X\n", ape.header.unk2);
    printf("Sections:           %d\n", ape.header.sections);

    printf("CRC:                0x%08X\n", ape.header.crc);

    ape.header.crc = 0;
    uint32_t calculated_crc = NVRam_crc(ape.bytes, (4 * ape.header.words), 0);
    printf("Calculated CRC:     0x%08X\n", calculated_crc);

    for (int i = 0; i < ape.header.sections; i++)
    {
        uint8_t *inBufferPtr = NULL;
        uint8_t *outBufferPtr = NULL;
        ssize_t inBufferSize;
        ssize_t outBufferSize;
        size_t out_length;

        APESection_t *section = &ape.header.section[i];

        printf("\n=== Section %i ===\n", i);
        printf("Load Addr:          0x%08X\n", section->loadAddr);

        printf("Offset:             0x%08X\n", section->offset);
        printf("Flags:              0x%08X\n", section->flags);
        if (section->flags & APE_SECTION_FLAG_COMPRESSED)
        {
            printf("    compressed\n");
        }
        if (section->flags & APE_SECTION_FLAG_CHECKSUM_IS_CRC32)
        {
            printf("    crc32\n");
        }
        printf("    %s\n", section->flags & APE_SECTION_FLAG_CODE ? "code" : "data");
        if (section->flags & APE_SECTION_FLAG_UNK0)
        {
            printf("    unknown\n");
        }
        if (section->flags & APE_SECTION_FLAG_ZERO_ON_FAST_BOOT)
        {
            printf("    bss\n");
        }
        printf("Decompressed Size:  0x%08X\n", section->decompressedSize);
        printf("Compressed Size:    0x%08X\n", section->compressedSize);
        printf("CRC:                0x%08X\n", section->crc);

        inBufferPtr = &ape.bytes[section->offset];
        inBufferSize = section->compressedSize;
        outBufferPtr = (uint8_t *)malloc(section->decompressedSize);
        outBufferSize = section->decompressedSize;
        out_length = decompress(outBufferPtr, outBufferSize, inBufferPtr, inBufferSize);
        calculated_crc = NVRam_crc(outBufferPtr, outBufferSize, 0);
        printf("out_length:                0x%08zX\n", out_length);
        printf("out CRC:                 0x%08X\n", calculated_crc);

        if (ape.header.sections == 4 && i == 0)
            continue;
        if (section->flags & APE_SECTION_FLAG_ZERO_ON_FAST_BOOT)
        {
            bss_sec->set_data((const char *)outBufferPtr, out_length);
            bss_seg->set_type(PT_LOAD);
            bss_seg->set_virtual_address(section->loadAddr);
            bss_seg->set_physical_address(section->loadAddr);
            bss_seg->set_flags(PF_W | PF_R);
            bss_seg->set_align(0x4);

            // Add data section into data segment
            bss_seg->add_section_index(bss_sec->get_index(), bss_sec->get_addr_align());
        }
        else if (!(section->flags & APE_SECTION_FLAG_CODE))
        {
            data_sec->set_data((const char *)outBufferPtr, out_length);
            data_seg->set_type(PT_LOAD);
            data_seg->set_virtual_address(section->loadAddr);
            data_seg->set_physical_address(section->loadAddr);
            data_seg->set_flags(PF_W | PF_R);
            data_seg->set_align(0x4);

            // Add data section into data segment
            data_seg->add_section_index(data_sec->get_index(), data_sec->get_addr_align());
        }
        else
        {
            text_sec->set_data((const char *)outBufferPtr, out_length);
            text_seg->set_type(PT_LOAD);
            text_seg->set_virtual_address(section->loadAddr);
            text_seg->set_physical_address(section->loadAddr);
            text_seg->set_flags(PF_X | PF_R);
            text_seg->set_align(0x4);

            // Add code section into program segment
            text_seg->add_section_index(text_sec->get_index(), text_sec->get_addr_align());
        }
    }

    if (options.is_set("output"))
    {
        // REcord entry-point address
        writer.set_entry(ape.header.entrypoint);

        // Create string table section
        section *str_sec = writer.sections.add(".strtab");
        str_sec->set_type(SHT_STRTAB);

        // Create string table writer
        string_section_accessor stra(str_sec);

        // Create symbol table section
        section *sym_sec = writer.sections.add(".symtab");
        sym_sec->set_type(SHT_SYMTAB);
        sym_sec->set_info(2);
        sym_sec->set_addr_align(0x4);
        sym_sec->set_entry_size(writer.get_default_entry_size(SHT_SYMTAB));
        sym_sec->set_link(str_sec->get_index());

        // Create symbol table writer
        symbol_section_accessor syma(writer, sym_sec);

        // Add label name
        Elf32_Word _start = stra.add_string(ENTRYPOINT_SYMBOL);
        Elf32_Word _thumb = stra.add_string(THUMB_CODE_SYMBOL);
        Elf32_Word _version_major = stra.add_string(VERSION_MAJOR_SYMBOL);
        Elf32_Word _version_minor = stra.add_string(VERSION_MINOR_SYMBOL);
        Elf32_Word _version_patch = stra.add_string(VERSION_PATCH_SYMBOL);

        // Add symbol entry
        syma.add_symbol(_start, ape.header.entrypoint, 0, STB_GLOBAL, STT_FUNC, 0, text_sec->get_index());

        syma.add_symbol(_thumb, ape.header.entrypoint & 0xfffffffe, 0, STB_LOCAL, STT_OBJECT, 0, text_sec->get_index());

        syma.add_symbol(_version_major, version_major, 0, STB_GLOBAL, STT_OBJECT, 0, text_sec->get_index());
        syma.add_symbol(_version_minor, version_minor, 0, STB_GLOBAL, STT_OBJECT, 0, text_sec->get_index());
        syma.add_symbol(_version_patch, version_patch, 0, STB_GLOBAL, STT_OBJECT, 0, text_sec->get_index());

        uint32_t *vectors = (uint32_t *)text_sec->get_data();
        Elf32_Word index = stra.add_string(STACK_END_SYMBOL);
        syma.add_symbol(index, vectors[0], 0, STB_GLOBAL, STT_OBJECT, 0, data_sec->get_index());

        // Create ELF file
        writer.save(options["output"]);
    }

    return 0;
}
