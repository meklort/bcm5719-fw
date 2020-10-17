////////////////////////////////////////////////////////////////////////////////
///
/// @file       bitbang.c
///
/// @project
///
/// @brief      NVRam bitbang Routines
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

void NVRAM_sendByte(uint8_t byte)
{
    RegNVMWrite_t nvm_write;
    nvm_write.r32 = 0;

    for (int i = 7; i >= 0; i--)
    {
        // Setup the SI value
        nvm_write.bits.SCLKOutputValue = 0;
        nvm_write.bits.SIOutputValue = (byte & (1u << i)) ? 1 : 0;
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

uint8_t NVRAM_sendAndGetByte(uint8_t byte)
{
    uint8_t readByte = 0;
    RegNVMWrite_t nvm_write;
    nvm_write.r32 = 0;

    for (int i = 7; i >= 0; i--)
    {
        // Setup the SI value
        nvm_write.bits.SCLKOutputValue = 0;
        nvm_write.bits.SIOutputValue = (byte & (1u << i)) ? 1 : 0;
        NVM.Write.r32 = nvm_write.r32;

        // Clock data out.
        nvm_write.bits.SCLKOutputValue = 1;
        NVM.Write.r32 = nvm_write.r32;

        // Read Input value.
        readByte |= (uint8_t)(NVM.Read.bits.SOInputValue ? (1u << i) : 0);
    }

    // Final clock edge
    nvm_write.bits.SCLKOutputValue = 0;
    nvm_write.bits.SIOutputValue = 0;
    NVM.Write.r32 = nvm_write.r32;

    return readByte;
}

bool NVRam_sendBytes(const uint8_t bytes[], uint32_t num_bytes)
{
    // Aquire the lock
    if (!NVRam_acquireLock())
    {
        // Unable to lock.
        return false;
    }
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
    nvm_write.r32 = 0;

    NVM.Addr.r32 = nvm_od.r32;
    NVM.Write.r32 = nvm_write.r32;
    // Enable Bitbang mode
    NVM.NvmCfg1.r32 = cfg1_bitbang.r32;

    for (uint32_t i = 0; i < num_bytes; i++)
    {
        NVRAM_sendByte(bytes[i]);
    }

    // Restore Cfg1.
    NVM.NvmCfg1.r32 = cfg1_orig.r32;

    NVRam_disable();
    NVRam_releaseLock();

    return true;
}

bool NVRam_sendAndGetBytes(const uint8_t send_bytes[], uint8_t get_bytes[], uint32_t num_bytes)
{
    // Aquire the lock
    if (!NVRam_acquireLock())
    {
        // Unable to lock.
        return false;
    }
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
    nvm_write.r32 = 0;

    NVM.Addr.r32 = nvm_od.r32;
    NVM.Write.r32 = nvm_write.r32;
    // Enable Bitbang mode
    NVM.NvmCfg1.r32 = cfg1_bitbang.r32;

    for (uint32_t i = 0; i < num_bytes; i++)
    {
        get_bytes[i] = NVRAM_sendAndGetByte(send_bytes[i]);
    }

    // Restore Cfg1, ensuring bitbang mode is disabled.
    cfg1_orig.bits.BitbangMode = 0;
    NVM.NvmCfg1.r32 = cfg1_orig.r32;

    NVRam_disable();
    NVRam_releaseLock();

    return true;
}

uint32_t NVRam_bitbang_readWord(uint32_t address)
{
    // 0x03: read word for AT45DB021D
    uint8_t send_bytes[] = {
        0x03, (uint8_t)(address >> 16), (uint8_t)(address >> 8), (uint8_t)(address), 0x00, 0x00, 0x00, 0x00,
    };
    uint8_t get_bytes[sizeof(send_bytes)];
    uint32_t num_bytes = sizeof(send_bytes);
    if (NVRam_sendAndGetBytes(send_bytes, get_bytes, num_bytes))
    {
        uint32_t read_word = ((uint32_t)get_bytes[4]) | ((uint32_t)get_bytes[5] << 8) | ((uint32_t)get_bytes[6] << 16) | ((uint32_t)get_bytes[7] << 24);

        return read_word;
    }
    else
    {
        // TOOD: return an error.
        return 0;
    }
}

bool NVRam_bitbang_writeWord(uint32_t address, uint32_t word)
{
    // 0x82: write word for AT45DB021D
    uint8_t send_bytes[] = { 0x82,
                             (uint8_t)(address >> 16),
                             (uint8_t)(address >> 8),
                             (uint8_t)(address),
                             (uint8_t)(word >> 24),
                             (uint8_t)(word >> 16),
                             (uint8_t)(word >> 8),
                             (uint8_t)(word) };
    uint32_t num_bytes = sizeof(send_bytes);
    return NVRam_sendBytes(send_bytes, num_bytes);
}
