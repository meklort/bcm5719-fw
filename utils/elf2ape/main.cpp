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

    parser.add_option("-o", "--output").dest("output").help("Output ape binary").metavar("FILE");

    parser.add_option("-n", "--name").dest("name").help("Output ape binary").metavar("FILE");

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

    // writer.set_os_abi( ELFOSABI_LINUX );
    // writer.set_type( ET_EXEC );
    // writer.set_machine( EM_ARM );

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
                                                       psec->get_size() * 2, // Output, compressed
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
                    section->flags |= APE_SECTION_FLAG_CHECKSUM_IS_CRC32 | APE_SECTION_FLAG_COMPRESSED;
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
                    section->flags |= APE_SECTION_FLAG_CODE;
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
        strncpy((char *)ape.header.name, name.c_str(), sizeof(ape.header.name));
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
    ///

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

    // uint32_t calculated_crc = NVRam_crc(ape.bytes, (4 * ape.header.words), 0);

    // ...

    uint32_t calculated_crc = NVRam_crc(ape.bytes, (4 * ape.header.words), 0);
    ape.header.crc = calculated_crc;
    printf("Calculated CRC:     0x%08X\n", calculated_crc);

    save_to_file(options["output"].c_str(), ape.bytes, byteOffset);

    // fstream infile;
    // infile.open(options["input"], fstream::in | fstream::binary);
    // if(infile.is_open())
    // {
    //     infile.read((char*)ape.bytes, MAX_SIZE);

    //     // The file is swapped... fix it.
    //     for(int i = 0; i < sizeof(ape)/sizeof(ape.words[0]); i++)
    //     {
    //         ape.words[i] = be32toh(ape.words[i]);
    //     }

    //     infile.close();
    // }
    // else
    // {
    //     cerr << " Unable to open file '" << options["filename"] << "'" <<
    //     endl; exit(-1);
    // }

    // elfio writer;

    // // You can't proceed without this function call!
    // writer.create( ELFCLASS32, ELFDATA2LSB );
    // writer.set_os_abi( ELFOSABI_LINUX );
    // writer.set_type( ET_EXEC );
    // writer.set_machine( EM_ARM );

    // // Create code section
    // section* text_sec = writer.sections.add( ".text" );
    // segment* text_seg = writer.segments.add();
    // text_sec->set_type( SHT_PROGBITS );
    // text_sec->set_flags( SHF_ALLOC | SHF_EXECINSTR );
    // text_sec->set_addr_align( 0x4 );

    // section* bss_sec = writer.sections.add( ".bss" );
    // segment* bss_seg = writer.segments.add();
    // bss_sec->set_type( SHT_PROGBITS );
    // bss_sec->set_flags( SHF_ALLOC | SHF_WRITE );
    // bss_sec->set_addr_align( 0x4 );

    // section* data_sec = writer.sections.add( ".data" );
    // segment* data_seg = writer.segments.add();
    // data_sec->set_type( SHT_PROGBITS );
    // data_sec->set_flags( SHF_ALLOC | SHF_WRITE );
    // data_sec->set_addr_align( 0x4 );

    // printf("=== Header ===\n");
    // printf("Magic:              0x%08X\n", ape.header.magic);
    // printf("UNK0:               0x%08X\n", ape.header.unk0);

    // char name[sizeof(ape.header.name) + 1] = {0};
    // strncpy(name, (char*)ape.header.name, sizeof(ape.header.name));
    // printf("Name:               %s\n", name);
    // printf("Version:            0x%08X\n", ape.header.version);
    // printf("Start:              0x%08X\n", ape.header.entrypoint);

    // printf("UNK1:               0x%02X\n", ape.header.unk1);
    // printf("Header Size:        %d\n", ape.header.words * 4);
    // printf("UNK2:               0x%02X\n", ape.header.unk2);
    // printf("Sections:           %d\n", ape.header.sections);

    // printf("CRC:                0x%08X\n", ape.header.crc);

    // ape.header.crc = 0;
    // uint32_t calculated_crc = NVRam_crc(ape.bytes, (4 * ape.header.words),
    // 0); printf("Calculated CRC:     0x%08X\n", calculated_crc);

    // for(int i = 0; i < ape.header.sections; i++)
    // {
    //     uint8_t * inBufferPtr = NULL;
    //     uint8_t * outBufferPtr = NULL;
    //     ssize_t inBufferSize;
    //     ssize_t outBufferSize;
    //     size_t  out_length;

    //     APESection_t* section = &ape.header.section[i];

    //     printf("\n=== Section %i ===\n", i);
    //     printf("Load Addr:          0x%08X\n", section->loadAddr);

    //     printf("Offset:             0x%08X\n", section->offset);
    //     printf("Flags:              0x%08X\n", section->flags);
    //     if(section->flags & APE_SECTION_FLAG_COMPRESSED)
    //     {
    //         printf("    compressed\n");
    //     }
    //     if(section->flags & APE_SECTION_FLAG_CHECKSUM_IS_CRC32)
    //     {
    //         printf("    crc32\n");
    //     }
    //     printf("    %s\n", section->flags & APE_SECTION_FLAG_CODE ? "code" :
    //     "data"); if(section->flags & APE_SECTION_FLAG_UNK0)
    //     {
    //         printf("    unknown\n");
    //     }
    //     if(section->flags & APE_SECTION_FLAG_ZERO_ON_FAST_BOOT)
    //     {
    //         printf("    bss\n");
    //     }
    //     printf("Decompressed Size:  0x%08X\n", section->decompressedSize);
    //     printf("Compressed Size:    0x%08X\n", section->compressedSize);
    //     printf("CRC:                0x%08X\n", section->crc);

    //     inBufferPtr = &ape.bytes[section->offset];
    //     inBufferSize = section->compressedSize;
    //     outBufferPtr = (uint8_t *)malloc(section->decompressedSize);
    //     outBufferSize = section->decompressedSize;
    //     out_length = decompress(outBufferPtr, outBufferSize, inBufferPtr,
    //     inBufferSize); calculated_crc = NVRam_crc(outBufferPtr,
    //     outBufferSize, 0); printf("out_length:                0x%08zX\n",
    //     out_length); printf("out CRC:                 0x%08X\n",
    //     calculated_crc);

    //     uint8_t* compOut = (uint8_t*)malloc(out_length * 2);
    //     int32_t compOutSize = out_length*2;
    //     int32_t recomp = compress(compOut, compOutSize, outBufferPtr,
    //     out_length); printf("recompressed length:                0x%08X\n",
    //     recomp);

    //     out_length = decompress(outBufferPtr, outBufferSize, compOut,
    //     recomp); calculated_crc = NVRam_crc(outBufferPtr, outBufferSize, 0);

    //     printf("out_length:                0x%08zX\n", out_length);
    //     printf("try CRC:                 0x%08X\n", calculated_crc);

    //     char outfile[] = "seciton%d";
    //     sprintf(outfile, "seciton%d", i);
    //     save_to_file(outfile, outBufferPtr, out_length);

    //     if(i == 0) continue;
    //     if(section->flags & APE_SECTION_FLAG_ZERO_ON_FAST_BOOT)
    //     {
    //         bss_sec->set_data((const char*)outBufferPtr, out_length);
    //         bss_seg->set_type( PT_LOAD );
    //         bss_seg->set_virtual_address( section->loadAddr );
    //         bss_seg->set_physical_address( section->loadAddr );
    //         bss_seg->set_flags( PF_W | PF_R );
    //         bss_seg->set_align( 0x4 );

    //         // Add data section into data segment
    //         bss_seg->add_section_index( bss_sec->get_index(),
    //         bss_sec->get_addr_align() );
    //     }
    //     else if(!(section->flags & APE_SECTION_FLAG_CODE))
    //     {
    //         data_sec->set_data((const char*)outBufferPtr, out_length);
    //         data_seg->set_type( PT_LOAD );
    //         data_seg->set_virtual_address( section->loadAddr );
    //         data_seg->set_physical_address( section->loadAddr );
    //         data_seg->set_flags( PF_W | PF_R );
    //         data_seg->set_align( 0x4 );

    //         // Add data section into data segment
    //         data_seg->add_section_index( data_sec->get_index(),
    //         data_sec->get_addr_align() );
    //     }
    //     else
    //     {
    //         text_sec->set_data((const char*)outBufferPtr, out_length);
    //         text_seg->set_type( PT_LOAD );
    //         text_seg->set_virtual_address( section->loadAddr );
    //         text_seg->set_physical_address( section->loadAddr );
    //         text_seg->set_flags( PF_X | PF_R );
    //         text_seg->set_align( 0x4 );

    //         // Add code section into program segment
    //         text_seg->add_section_index( text_sec->get_index(),
    //         text_sec->get_addr_align() );

    //     }
    // }

    return 0;
}
