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

#include <HAL.hpp>
#include <OptionParser.h>
#include <bcm5719_SHM.h>
#include <iostream>
#include <stdint.h>
#include <string>
#include <vector>

#define VERSION_STRING STRINGIFY(VERSION_MAJOR) "." STRINGIFY(VERSION_MINOR) "." STRINGIFY(VERSION_PATCH)

using namespace std;
using optparse::OptionParser;

#ifdef __ppc64__
#define BARRIER()                                                                                                                                              \
    do                                                                                                                                                         \
    {                                                                                                                                                          \
        asm volatile("sync 0\neieio\n" ::: "memory");                                                                                                          \
    } while (0)
#else
#define BARRIER()                                                                                                                                              \
    do                                                                                                                                                         \
    {                                                                                                                                                          \
        asm volatile("" ::: "memory");                                                                                                                         \
    } while (0)
#endif

int main(int argc, char const *argv[])
{
    OptionParser parser = OptionParser().description("BCM Console Utility v" VERSION_STRING);

    parser.version(VERSION_STRING);

    parser.add_option("-f", "--function")
        .dest("function")
        .type("int")
        .set_default("1")
        .metavar("FUNCTION")
        .help("Read registers from the specified pci function.");

    optparse::Values options = parser.parse_args(argc, argv);
    vector<string> args = parser.args();

    if (!initHAL(NULL, options.get("function")))
    {
        cerr << "Unable to locate pci device with function " << options["function"] << endl;
        exit(-1);
    }

    uint32_t buffer_size = sizeof(SHM.RcpuPrintfBuffer) / sizeof(SHM.RcpuPrintfBuffer[0]) * sizeof(uint32_t);

    if (SHM.RcpuWritePointer.r32 > buffer_size || SHM.RcpuReadPointer.r32 > buffer_size || SHM.RcpuHostReadPointer.r32 > buffer_size)
    {
        // Print buffer has not been initialized or we are not function 0. Exit out.
        cerr << "Unexpected value in SHM. exiting." << endl;
        cerr << "Write Pointer: " << SHM.RcpuWritePointer.r32 << endl;
        cerr << "Read Pointer: " << SHM.RcpuReadPointer.r32 << endl;
        cerr << "Host Read Pointer: " << SHM.RcpuHostReadPointer.r32 << endl;
        cerr << "Max Pointer: " << buffer_size << endl;
        exit(-1);
    }

    for (;;)
    {
        BARRIER();
        uint32_t cached_pointer = SHM.RcpuHostReadPointer.r32;
        if (cached_pointer != SHM.RcpuWritePointer.r32)
        {
            if (cached_pointer >= buffer_size)
            {
                cached_pointer = 0;
            }

            uint32_t word_pointer = cached_pointer / 4;
            uint32_t byte_index = cached_pointer % 4;
            char character = (uint8_t)(SHM.RcpuPrintfBuffer[word_pointer].r32 >> (byte_index * 8));
            putchar(character);
            fflush(stdout);

            SHM.RcpuHostReadPointer.r32 = ++cached_pointer;
        }
    }

    return 0;
}
