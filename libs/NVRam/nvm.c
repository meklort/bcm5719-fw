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
#include <NVRam.h>
#include "bcm5719_NVM.h"
#include <stdio.h>

#define ATMEL_AT45DB0X1B_PAGE_POS   (9u)
#define ATMEL_AT45DB0X1B_PAGE_SIZE  (264u)
#define ATMEL_AT45DB0X1B_ERASE      (false)

#define PAGE_POS                    ATMEL_AT45DB0X1B_PAGE_POS
#define PAGE_SIZE                   ATMEL_AT45DB0X1B_PAGE_SIZE
#define NEEDS_ERASE                 ATMEL_AT45DB0X1B_ERASE

#define REQ     ReqSet2
#define CLR     ReqClr2
#define WON     ArbWon2

/**
 * @fn  uint32_t NVRam_translate(uint32_t address)
 *
 * @brief Translates a logical address to the NVM physical address.
 */
static inline uint32_t NVRam_translate(uint32_t address)
{
    // Equation from NetXtremeII PG203
    if(NVM_NVM_CFG_1_PAGE_SIZE_264_BYTES == NVM.NvmCfg1.bits.PageSize)
    {
        return ((address / PAGE_SIZE) << PAGE_POS) + (address % PAGE_SIZE);
    }
    else
    {
        return address;        
    }
}

void NVRam_enable(void)
{
    // TODO: enable both bits on read.
    NVM.Access.bits.Enable = 1;
}

void NVRam_disable(void)
{
    // TODO: enable both bits on read.
    NVM.Access.bits.Enable = 0;
}

static inline void NVRam_waitDone(void)
{
    while(!NVM.Command.bits.Done)
    {

    }
}

static inline void NVRam_erase(uint32_t offset)
{
    if(NEEDS_ERASE)
    {
        // TODO: No need to erase when buffered.        
    }
}

bool NVRam_acquireLock(void)
{
    // Grab lock
    printf("DEVICE->SoftwareArbitration.r32 = %x\n", (uint32_t)NVM.SoftwareArbitration.r32);
    NVM.SoftwareArbitration.bits.REQ = 1;

    while(!NVM.SoftwareArbitration.bits.WON);


    printf("DEVICE->SoftwareArbitration.r32 = %x\n", (uint32_t)NVM.SoftwareArbitration.r32);

    return true;
}

bool NVRam_releaseLock(void)
{
    // Release locks
    printf("DEVICE->SoftwareArbitration.r32 = %x\n", (uint32_t)NVM.SoftwareArbitration.r32);

    NVM.SoftwareArbitration.bits.CLR = 1;
    printf("DEVICE->SoftwareArbitration.r32 = %x\n", (uint32_t)NVM.SoftwareArbitration.r32);
    return true;
}

static uint32_t NVRam_readByteInternal(uint32_t address, RegNVMCommand_t cmd)
{
    address = NVRam_translate(address);

    // Clear the done bit
    RegNVMCommand_t done = {0u};
    done.bits.Done = 1;

    NVM.Command = done;
    NVM.Addr.r32 = address;
    NVM.Command = cmd;

    NVRam_waitDone();

    return NVM.Read.r32;
}
static void NVRam_writeByteInternal(uint32_t address, uint32_t data, RegNVMCommand_t cmd)
{
    address = NVRam_translate(address);

    // Clear the done bit
    RegNVMCommand_t done = {0u};
    done.bits.Done = 1;

    NVM.Command = done;
    NVM.Write.r32 = data;
    NVM.Addr.r32 = address;
    NVM.Command = cmd;

    NVRam_waitDone();
}

uint32_t NVRam_readByte(uint32_t address)
{
    RegNVMCommand_t cmd = {0u};
    cmd.bits.First = 1;
    cmd.bits.Last = 1;
    cmd.bits.Doit = 1;

    return NVRam_readByteInternal(address, cmd);
}

void NVRam_read(uint32_t address, uint32_t* buffer, size_t words)
{
    if(!words)
    {
        // No bytes to read.
        return;
    }

    // First word.
    RegNVMCommand_t cmd = {0u};
    cmd.bits.Doit = 1;
    cmd.bits.First = 1;

    while(words)
    {
        if(1 == words)
        {
            // Last word.
            cmd.bits.Last = 1;
        }

        *buffer = NVRam_readByteInternal(address, cmd);
        buffer++;
        words--;
        address +=4;

        // If we have more than one word, clear the first bit.
        cmd.bits.First = 0;
    }
}

void NVRam_writeByte(uint32_t address, uint32_t data)
{
    RegNVMCommand_t cmd = {0};
    cmd.bits.First = 1;
    cmd.bits.Last = 1;
    cmd.bits.Doit = 1;
    cmd.bits.Wr = 1;

    NVRam_writeByteInternal(address, data, cmd);
}

void NVRam_write(uint32_t address, uint32_t* buffer, size_t words)
{
    if(!words)
    {
        // No bytes to read.
        return;
    }

    // First word.
    RegNVMCommand_t cmd = {0};
    cmd.bits.Doit = 1;
    cmd.bits.First = 1;
    cmd.bits.Wr = 1;

    while(words)
    {
        if(1 == words)
        {
            // Last word.
            cmd.bits.Last = 1;
        }

        NVRam_writeByteInternal(address, *buffer, cmd);
        buffer++;
        words--;
        address += 4;

        // If we have more than one word, clear the first bit.
        cmd.bits.First = 0;
    }
}
