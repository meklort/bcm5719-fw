////////////////////////////////////////////////////////////////////////////////
///
/// @file       ape_purchar.c
///
/// @project
///
/// @brief      APE printf support Routines
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2019, Evan Lojewski
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

#include <printf.h>
#include <APE_DEBUG.h>
#include <APE_SHM.h>

void _putchar(char character)
{
    SHM.ApeSegLength.r32 = 0xaaaaaaaa;
    uint32_t write_pointer = DEBUG.WritePointer.r32;
    // while(write_pointer + 1 == DEBUG.ReadPointer.r32)
    {
        // Wait for host to read memory.
    }

    // volatile uint32_t *write_buffer = &DEBUG.Buffer[0].r32;
    // volatile uint32_t *write_bytes = write_buffer;
    DEBUG.Buffer[write_pointer].r32 = character;
    // write_bytes[write_pointer] = '1';//character;
    write_pointer++;
    if(write_pointer >= sizeof(DEBUG.Buffer)/4)
    {
        write_pointer = 0;
    }

    DEBUG.WritePointer.r32 = write_pointer;
    SHM.ApeSegLength.r32 = 0xbbbbbbbb;

}
