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
#include <iostream>
#include <APE.h>
#include <bcm5719_SHM.h>
#include <elfio/elfio.hpp>

#include <types.h>
#include <bcm5719_DEVICE.h>
#include <APE_APE_PERI.h>
#include <APE_NVIC.h>

#include "../NVRam/bcm5719_NVM.h"

using namespace std;
using namespace ELFIO;
using optparse::OptionParser;

#ifdef __ppc64__
#define BARRIER()    do { asm volatile ("sync 0\neieio\n" ::: "memory"); } while(0)
#else
#define BARRIER()    do { asm volatile ("" ::: "memory"); } while(0)
#endif

int main(int argc, char const *argv[])
{
    OptionParser parser = OptionParser().description("BCM Register Utility");

    parser.add_option("-f", "--function")
            .dest("function")
            .type("int")
            .set_default("1")
            .metavar("FUNCTION")
            .help("Read registers from the specified pci function.");

    optparse::Values options = parser.parse_args(argc, argv);
    vector<string> args = parser.args();


    if(!initHAL(NULL, options.get("function")))
    {
        cerr << "Unable to locate pci device with function " << options["function"] << " for the debug console." << endl;
        exit(-1);
    }

    uint32_t* DEBUG = (uint32_t*)&gAPEBase[0x4000];
    volatile uint32_t* write_pointer = &DEBUG[0];
    volatile uint32_t* read_pointer = &DEBUG[1];
    uint32_t  buffer_size = 0x1000 - 8;
    volatile uint32_t*  buffer = &DEBUG[2];

    for(;;)
    {
        BARRIER();
        uint32_t cached_pointer = *read_pointer;
        if(cached_pointer != *write_pointer)
        {
            char character = (uint8_t)buffer[cached_pointer];
            // printf("Buffer[%d] = %c\n", cached_pointer, character);
            putchar(character);

            if(cached_pointer++ >= buffer_size/4)
            {
                cached_pointer = 0;
            }
            *read_pointer = cached_pointer;
        }
    }

    return 0;
}
