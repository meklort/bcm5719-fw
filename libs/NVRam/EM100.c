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

void NVRAM_EM100_send_byte(uint8_t byte)
{
    RegNVMWrite_t nvm_write;
    nvm_write.r32 = 0;

    for (int i = 7; i >= 0; i--)
    {
        // Setup the SI value
        nvm_write.bits.SCLKOutputValue = 0;
        nvm_write.bits.SIOutputValue = (byte & (1 << i)) ? 1 : 0;
        NVM.Write.r32 = nvm_write.r32;

        // Clock data out.
        nvm_write.bits.SCLKOutputValue = 1;
        NVM.Write.r32 = nvm_write.r32;
    }

    // Final clock edge
    nvm_write.bits.SCLKOutputValue = 0;
    nvm_write.bits.SIOutputValue = 0;
    NVM.Write.r32 = nvm_write.r32;
}

void NVRam_EM100_writeBytes(uint8_t bytes[], size_t num_bytes)
{
    // Aquire the lock
    NVRam_acquireLock();
    NVRam_enable();

    // Save defaults and set sane values
    RegNVMNvmCfg1_t cfg1_orig;
    RegNVMNvmCfg1_t cfg1_bitbang;
    cfg1_orig.r32 = NVM.NvmCfg1.r32;
    cfg1_bitbang.r32 = cfg1_orig.r32;
    cfg1_bitbang.bits.BitbangMode = 1;

    // Drive the SCLK, CSb and MOSI lines
    RegNVMAddr_t nvm_od;
    nvm_od.r32 = 0xffffff;             // All Input
    nvm_od.bits.SCLKOutputDisable = 0; // Drive SCLK
    nvm_od.bits.CSbOutputDisable = 0;  // Drive CSb
    nvm_od.bits.SIOutputDisable = 0;   // Drive MOSI

    RegNVMWrite_t nvm_write;

    NVM.Addr.r32 = nvm_od.r32;
    NVM.Write.r32 = nvm_write.r32;
    // Enable Bitbang mode
    NVM.NvmCfg1.r32 = cfg1_bitbang.r32;

    for (int i = 0; i < num_bytes; i++)
    {
        NVRAM_EM100_send_byte(bytes[i]);
    }

    // Restore Cfg1.
    NVM.NvmCfg1.r32 = cfg1_orig.r32;

    NVRam_disable();
    NVRam_releaseLock();
}

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
        NVRam_EM100_writeBytes(gEM100Packet, EM100_PACKET_BUFFER_OFFSET + used_buffer);
        // Mark buffer as empty
        gEM100Packet[EM100_PACKET_MSG_LEN] = 0;
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

    NVRam_EM100_writeBytes(packet_AA, sizeof(packet_AA));
    NVRam_EM100_writeBytes(packet_55, sizeof(packet_AA));
    NVRam_EM100_writeBytes(packet_AA, sizeof(packet_AA));
}

void NVRam_EM100_disableConsole(void)
{
    uint8_t packet_exit_console[] = {
        EM100_CONSOLE_WRITE_COMMAND,
        0x00,
        EM100_CMD_EXIT_CONSOLE,
        0x00,
    };
    NVRam_EM100_writeBytes(packet_exit_console, sizeof(packet_exit_console));
}
#endif /* ENABLE_CONSOLE */