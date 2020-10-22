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
#include <NCSI.h>

#if 0
uint8_t printf_packet[] = {
    0xff, 0xff, 0xff, 0xff, 0xff, 0xff, /* 0 -  5: Dst: Boradcasst Address */
    0x98, 0xaf, 0x65, 0x4c, 0x0e, 0xb9, /* 6 - 11: Src: */
    0x08, 0x00, /* 12 - 13: IPv4 */
    0x45, /* 14: IPv4, 5 byte header. */
    0x00, /* 15: DSCP */
    0x00, 0x21, /* 16 - 17: Length - 33 bytes */
        0xcf, 0xb6, /* 18 - 19: ID */
        0x40, 0x00, /* 20 - 21: Flags: Don't Fragment */
        0x40, /* 22: TTL */
        0x11, /* 23: UDP */
    0x8a, 0x59, /* 24 - 25: Header Checksum */
    0xc0, 0xa8, 0x20, 0x14, /* 26 - 29: Src IP */
    0xff, 0xff, 0xff, 0xff, /* 30 - 33: Dst IP */
    0xd0, 0x30, /* 34 - 35: Src Port */
    0x19, 0xc8, /* 36 - 37: Dst Port */
    0x00, 0x0d, /* 38 - 39: Length: 13 */
    0xe0, 0xda, /* 40 - 41: Checksum */
    // 42 - len : Data.
    0x74, 0x65, 0x73, 0x74, 0x0a,

    // Paddinf
    0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00,
};
#endif

uint32_t packet2[] = {
    0xffffffff,
    0xaf98ffff,
    0xb90e4c65,
    0x00450008,
    0x5ed93200,
    0x11400040,
    0xa8c0a080,
    0xffff1420,
    0xa08effff,
    0x1e00c819, /* 0x1e - length */
    0x00000000, /* CRC (empty) + start of payload. */
    0x20202020,
    0x20202020,
    0x20202020,
    0x20202020,
    0x20202020,
};


#define NCSI_PAYLOAD_MAX        (5 * 4 + 2)
#define NCSI_PAYLOAD_OFFSET     (sizeof(packet2) - NCSI_PAYLOAD_MAX)

uint16_t g_used_buffer = 0;
bool ncsi_print_enabled = false;
void NCSI_putchar(char c)
{
    if(!ncsi_print_enabled) return;
    uint16_t used_buffer = g_used_buffer;
    uint8_t *payload = &((uint8_t*)packet2)[NCSI_PAYLOAD_OFFSET];

    payload[used_buffer] = (uint8_t)c;
    used_buffer++;

    // Flush if the buffer is full or if we reached the end of a line
    if (('\n' == c) || (used_buffer >= NCSI_PAYLOAD_MAX))
    {
        if(used_buffer < NCSI_PAYLOAD_MAX)
        {
            while(used_buffer < NCSI_PAYLOAD_MAX)
            {
                // Clear out remaining part of payload
                payload[used_buffer] = 0;
                used_buffer++;
            }
        }
        NCSI_TxBePacket(packet2, sizeof(packet2));
        used_buffer = 0;
    }
    else
    {
        payload[used_buffer] = 0;
    }

    g_used_buffer = used_buffer;
}
