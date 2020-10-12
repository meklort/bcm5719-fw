////////////////////////////////////////////////////////////////////////////////
///
/// @file       NVRam.c
///
/// @project
///
/// @brief      NVRam Support Routines
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
#include "bcm5719_NVM.h"

#include <NVRam.h>

#define BCM_NVRAM_MAGIC (0x669955AAu)

#define ATMEL_AT45DB0X1B_PAGE_POS (9u)
#define ATMEL_AT45DB0X1B_PAGE_SIZE (264u)
#define ATMEL_AT45DB0X1B_ERASE (false)

#define PAGE_POS ATMEL_AT45DB0X1B_PAGE_POS
#define PAGE_SIZE ATMEL_AT45DB0X1B_PAGE_SIZE
#define NEEDS_ERASE ATMEL_AT45DB0X1B_ERASE

#ifdef CXX_SIMULATOR
#include <arpa/inet.h>
/* Host */
#define REQ ReqSet1
#define CLR ReqClr1
#define WON ArbWon1
#elif defined(__arm__)
/* APE Firmware */
#define ntohl(__x__) (__x__) /* Todo: swap */
#define htonl(__x__) (__x__) /* Todo: swap */
#define REQ ReqSet2
#define CLR ReqClr2
#define WON ArbWon2
#else
/* RX CPU Firmware */
#define ntohl(__x__) (__x__)
#define htonl(__x__) (__x__)
#define REQ ReqSet0
#define CLR ReqClr0
#define WON ArbWon0
#endif

/**
 * @fn  uint32_t NVRam_translate(uint32_t address)
 *
 * @brief Translates a logical address to the NVM physical address.
 */
static inline uint32_t NVRam_translate(uint32_t address)
{
#if 0
    // Equation from NetXtremeII PG203
    if(NVM_NVM_CFG_1_PAGE_SIZE_264_BYTES == NVM.NvmCfg1.bits.PageSize)
    {
        return ((address / PAGE_SIZE) << PAGE_POS) + (address % PAGE_SIZE);
    }
    else
    {
        return address;
    }
#else
    return address;
#endif
}

void NVRam_enable(void)
{
    NVM.Access.bits.Enable = 1;
}

void NVRam_enableWrites(void)
{
    NVM.Access.bits.WriteEnable = 1;
}

void NVRam_disable(void)
{
    NVM.Access.bits.Enable = 0;
}

void NVRam_disableWrites(void)
{
    NVM.Access.bits.WriteEnable = 0;
}

static inline void NVRam_waitDone(void)
{
    while (!NVM.Command.bits.Done)
    {
    }
}

bool NVRam_acquireLock(void)
{
    // Grab lock
    RegNVMSoftwareArbitration_t req;
    req.r32 = 0;
    req.bits.REQ = 1;
    NVM.SoftwareArbitration = req;

    while (!NVM.SoftwareArbitration.bits.WON)
    {
        // Spin
    }

    return true;
}

bool NVRam_releaseLock(void)
{
    // Release locks
    RegNVMSoftwareArbitration_t req;
    req.r32 = 0;
    req.bits.CLR = 1;
    NVM.SoftwareArbitration = req;

    return true;
}

bool NVRam_releaseAllLocks(void)
{
    RegNVMSoftwareArbitration_t req;
    req.r32 = 0;
    req.bits.ReqClr0 = 1;
    req.bits.ReqClr1 = 1;
    req.bits.ReqClr2 = 1;
    req.bits.ReqClr3 = 1;
    NVM.SoftwareArbitration = req;

    return true;
}

#ifdef CXX_SIMULATOR
static uint32_t NVRam_readWordInternal(uint32_t address, RegNVMCommand_t &cmd)
#else
static uint32_t NVRam_readWordInternal(uint32_t address, RegNVMCommand_t cmd)
#endif
{
    address = NVRam_translate(address);

    // Clear the done bit
    RegNVMCommand_t done;
    done.r32 = 0;
    done.bits.Done = 1;

    NVM.Command = done;
    NVM.Addr.r32 = address;
    NVM.Command = cmd;

    NVRam_waitDone();

    return ntohl(NVM.Read.r32);
}

#ifdef CXX_SIMULATOR
static void NVRam_writeWordInternal(uint32_t address, uint32_t data, RegNVMCommand_t &cmd)
#else
static void NVRam_writeWordInternal(uint32_t address, uint32_t data, RegNVMCommand_t cmd)
#endif
{
    address = NVRam_translate(address);

    // Clear the done bit
    RegNVMCommand_t done;
    done.r32 = 0;
    done.bits.Done = 1;

    NVM.Command = done;
    NVM.Write.r32 = htonl(data);
    NVM.Addr.r32 = address;
    NVM.Command = cmd;

    NVRam_waitDone();
}

uint32_t NVRam_readWord(uint32_t address)
{
    RegNVMCommand_t cmd;
    cmd.r32 = 0;
    cmd.bits.First = 1;
    cmd.bits.Last = 1;
    cmd.bits.Doit = 1;

    return NVRam_readWordInternal(address, cmd);
}

void NVRam_read(uint32_t address, uint32_t *buffer, uint32_t words)
{
    if (!words)
    {
        // No data to read.
        return;
    }

    // First word.
    RegNVMCommand_t cmd;
    cmd.r32 = 0;
    cmd.bits.Doit = 1;
    cmd.bits.First = 1;

    while (words)
    {
        if (1 == words)
        {
            // Last word.
            cmd.bits.Last = 1;
        }

        *buffer = NVRam_readWordInternal(address, cmd);
        buffer++;
        words--;
        address += 4;

        // If we have more than one word, clear the first bit.
        cmd.bits.First = 0;
    }
}

void NVRam_writeWord(uint32_t address, uint32_t data)
{
    if (data != NVRam_readWord(address))
    {
        // Only write if different.

        RegNVMCommand_t cmd;
        cmd.r32 = 0;
        cmd.bits.First = 1;
        cmd.bits.Last = 1;
        cmd.bits.Doit = 1;
        cmd.bits.Wr = 1;

        NVRam_writeWordInternal(address, data, cmd);
    }
}

void NVRam_write(uint32_t address, uint32_t *buffer, uint32_t words)
{
    uint32_t page_size = 256;
    bool find_first_difference = true;
    uint32_t last_difference = address + words * 4;
    uint32_t trim_address;
    uint32_t trim_words = words;
    uint32_t *trim_buffer;

    if (!words)
    {
        // No bytes to read.
        return;
    }

    // Reduce beginning of buffer until we find the first different word.
    // Note: We don't use NVRam_readWord() here as this can sometime lockup the nvm controller.
    RegNVMCommand_t cmd;
    cmd.r32 = 0;
    cmd.bits.Doit = 1;
    cmd.bits.First = 1;

    while (words && trim_words)
    {
        uint32_t read_word;
        if (1 == words || 1 == trim_words)
        {
            // Last word.
            cmd.bits.Last = 1;
        }

        if (find_first_difference)
        {
            // Find the first difference.
            read_word = NVRam_readWordInternal(address, cmd);

            if (buffer[0] == read_word)
            {
                // Skip this word.
                buffer++;
                words--;
                address += 4;
            }
            else
            {
                // address now contains the first difference. Start trimming at the next word.
                find_first_difference = false;

                last_difference = address;
                trim_address = address + 4;
                trim_words = words - 1;
                trim_buffer = buffer + 1;
            }
        }
        else
        {
            // Find the last difference
            read_word = NVRam_readWordInternal(trim_address, cmd);
            if (trim_buffer[0] != read_word)
            {
                last_difference = trim_address;
            }

            trim_buffer++;
            trim_words--;
            trim_address += 4;
        }

        cmd.bits.First = 0;
    }

    // Was a difference found?
    if (last_difference < address + words * 4)
    {
        words = (last_difference + 4 - address) / 4;
    }
    else
    {
        // No differences found in buffer given, no words to write.
        words = 0;
    }

    // Performe the write.
    // First word.
    cmd.r32 = 0;
    cmd.bits.Doit = 1;
    cmd.bits.First = 1;
    cmd.bits.Last = 0;
    cmd.bits.Wr = 1;

    while (words)
    {
        if (0 == address % page_size || cmd.bits.First)
        {
            // New page.
            cmd.bits.First = 1;
            cmd.bits.Last = 0;
        }

        if (1 == words || (((address % page_size) + 4) >= page_size))
        {
            // Last word or end of page.
            cmd.bits.Last = 1;
        }

        NVRam_writeWordInternal(address, *buffer, cmd);
        buffer++;
        words--;
        address += 4;

        // If we have more than one word, clear the first bit.
        cmd.bits.First = 0;
    }
}

uint32_t NVRam_size(void)
{
    size_t size;
    uint32_t magic = NVRam_readWord(0);

    if (magic != htonl(BCM_NVRAM_MAGIC))
    {
        // Unable to determine the size.
        // Return 1024 to allow recovery from a bad flash.
        return 1024;
    }

    // Scan for the magic wrapping around, starting at 2KB flash size.
    size = 2u * 1024u;
    do
    {
        size *= 2;

        magic = NVRam_readWord(size);
    } while (magic != htonl(BCM_NVRAM_MAGIC));

    return size;
}
