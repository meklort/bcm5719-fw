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
#include <ape_console.h>
#include <APE_SHM.h>
#include <APE_SHM1.h>

static bool reset_ape_console_internal(VOLATILE SHM_t *port)
{
    if (port->RcpuWritePointer.r32 > sizeof(port->RcpuPrintfBuffer) ||
        port->RcpuReadPointer.r32 > sizeof(port->RcpuPrintfBuffer) ||
        port->RcpuHostReadPointer.r32 > sizeof(port->RcpuPrintfBuffer))
    {
        port->RcpuReadPointer.r32 = 0;
        port->RcpuHostReadPointer.r32 = 0;
        port->RcpuWritePointer.r32 = 0;

        return true;
    }

    return false;
}

bool reset_ape_console(void)
{
    bool was_reset = false;

    if(reset_ape_console_internal(&SHM))
    {
        was_reset = true;
    }

    if (reset_ape_console_internal(&SHM1))
    {
        was_reset = true;
    }

    return was_reset;
}


static void ape_putchar(char character, VOLATILE SHM_t *port)
{
    uint32_t write_pointer = port->RcpuWritePointer.r32;
    uint32_t word_pointer = write_pointer / 4;
    uint32_t byte_index = write_pointer % 4;
    uint32_t byte_mask = 0xFFu << (byte_index * 8u);

    uint32_t new_word = port->RcpuPrintfBuffer[word_pointer].r32 & ~byte_mask;
    new_word |= ((uint32_t)((uint8_t)character)) << (byte_index * 8u);
    port->RcpuPrintfBuffer[word_pointer].r32 = new_word;
    write_pointer++;

    if(write_pointer >= sizeof(port->RcpuPrintfBuffer))
    {
        write_pointer = 0;
    }

    port->RcpuWritePointer.r32 = write_pointer;
}

void _putchar(char character)
{
    // NCSI_putchar(character);
    ape_putchar(character, &SHM);
    ape_putchar(character, &SHM1);
}
