////////////////////////////////////////////////////////////////////////////////
///
/// @file       EM100.c
///
/// @project
///
/// @brief      EM100 Debug Routines
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2019-2020, Evan Lojewski
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
#include "bcm5719_NVM.h"

#include <NVRam.h>

// #define ENABLE_CONSOLE
#undef ENABLE_CONSOLE

#if ENABLE_CONSOLE
void NVRam_EM100_enableConsole(void);
void NVRam_EM100_disableConsole(void);
#endif /* ENABLE_CONSOLE */

#define EM100_CONSOLE_WRITE_COMMAND (0x11)

#define EM100_CMD_GET_UFIFO_LEN (0xB1)
#define EM100_CMD_GET_DFIFO_LEN (0xB2)
#define EM100_CMD_WRITE_UFIFO (0xC0)
#define EM100_CMD_READ_DFIFO (0xD0)
#define EM100_CMD_EXIT_CONSOLE (0xE0)

#define EM100_MSG_STRING (0x05)
#define EM100_MSG_SIG (0x47364440)

uint8_t gEM100Packet[64] = {
    EM100_CONSOLE_WRITE_COMMAND,  /* 0: SPI COmmand */
    0x00,                         /* 1: Reserved */
    EM100_CMD_WRITE_UFIFO,        /* 2: EM100 COmmand */
    0xFF & (EM100_MSG_SIG),       /* 3: EM100_MSG_SIG */
    0xFF & (EM100_MSG_SIG >> 8),  /* 4: EM100_MSG_SIG */
    0xFF & (EM100_MSG_SIG >> 16), /* 5: EM100_MSG_SIG */
    0xFF & (EM100_MSG_SIG >> 24), /* 6: EM100_MSG_SIG */
    EM100_MSG_STRING,             /* 7: Message Type */
    0,                            /* 8: Message Length */
};
#define EM100_PACKET_MSG_LEN (8u)
#define EM100_PACKET_BUFFER_OFFSET (9u)
#define EM100_MAX_BUFFER_LEN (sizeof(gEM100Packet) - EM100_PACKET_BUFFER_OFFSET)

void NVRam_EM100_putchar(char c)
{
    int used_buffer = gEM100Packet[EM100_PACKET_MSG_LEN] + 1;

    gEM100Packet[used_buffer + EM100_PACKET_BUFFER_OFFSET - 1] = c;
    gEM100Packet[EM100_PACKET_MSG_LEN] = used_buffer;

    // Flush if the buffer is full or if we reached the end of a line
    if (('\n' == c) || (used_buffer >= EM100_MAX_BUFFER_LEN))
    {
#if ENABLE_CONSOLE
        NVRam_EM100_enableConsole();
#endif
        if (NVRam_sendBytes(gEM100Packet, EM100_PACKET_BUFFER_OFFSET + used_buffer))
        {
            // Mark buffer as empty
            gEM100Packet[EM100_PACKET_MSG_LEN] = 0;
        }
        else
        {
            if (used_buffer >= EM100_MAX_BUFFER_LEN)
            {
                // Don't output any more chars
                gEM100Packet[EM100_PACKET_MSG_LEN] = used_buffer - 1;
                ;
            }
        }
#if ENABLE_CONSOLE
        NVRam_EM100_disableConsole();
#endif
    }
}

#if ENABLE_CONSOLE
void NVRam_EM100_enableConsole(void)
{
    uint8_t packet_AA[] = { EM100_CONSOLE_WRITE_COMMAND, 0x00, 0xAA, 0xAA, 0x00 };
    uint8_t packet_55[] = { EM100_CONSOLE_WRITE_COMMAND, 0x00, 0x55, 0x55, 0x00 };

    NVRam_sendBytes(packet_AA, sizeof(packet_AA));
    NVRam_sendBytes(packet_55, sizeof(packet_AA));
    NVRam_sendBytes(packet_AA, sizeof(packet_AA));
}

void NVRam_EM100_disableConsole(void)
{
    uint8_t packet_exit_console[] = {
        EM100_CONSOLE_WRITE_COMMAND,
        0x00,
        EM100_CMD_EXIT_CONSOLE,
        0x00,
    };
    NVRam_sendBytes(packet_exit_console, sizeof(packet_exit_console));
}
#endif /* ENABLE_CONSOLE */