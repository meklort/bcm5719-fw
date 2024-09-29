////////////////////////////////////////////////////////////////////////////////
///
/// @file       nvm.cpp
///
/// @project    bcm5719-fw
///
/// @brief      Support routines for accessing nvm.
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

#include "HAL.hpp"
#include "bcmflash.h"

#include <../bcm5719_NVM.h>
#include <NVRam.h>
#include <bcm5719_eeprom.h>

bool bcmflash_nvram_init(const char *name)
{
    bool result;
    char *end_ptr;
    int function = strtol(name, &end_ptr, 10);
    if (end_ptr == name)
    {
        // Unable to detect, default to function 1.
        function = 1;
    }

    result = HAL_init(NULL, function);

    if (result)
    {
        // Release the NVM controller in case if we were terminated early
        NVRam_disableWrites();
        NVRam_releaseLock();
    }

    return result;
}

size_t bcmflash_nvram_size(const char *name)
{
    size_t size;

    NVRam_acquireLock();

    NVRam_enable();

    size = NVRam_size();

    NVRam_releaseLock();

    return size;
}

bool bcmflash_nvram_read(const char *name, void *buffer, size_t len)
{
    uint32_t *words = static_cast<uint32_t *>(buffer);
    uint32_t num_words = len / 4;
    NVRam_acquireLock();

    NVRam_enable();

    NVRam_read(0, words, num_words);

    NVRam_releaseLock();

    return true;
}

bool bcmflash_nvram_write(const char *name, void *buffer, size_t len)
{
    (void)name;

    uint32_t *words = static_cast<uint32_t *>(buffer);
    uint32_t num_words = len / 4;

    NVRam_acquireLock();

    NVRam_enable();
    NVRam_enableWrites();

    NVRam_write(0, words, num_words);

    NVRam_disableWrites();

    NVRam_releaseLock();

    return true;
}

void bcmflash_nvram_unlock(void)
{
    NVM.SoftwareArbitration.bits.ReqClr0 = 1;
    NVM.SoftwareArbitration.bits.ReqClr1 = 1;
    NVM.SoftwareArbitration.bits.ReqClr2 = 1;
    NVM.SoftwareArbitration.bits.ReqClr3 = 1;
}

void bcmflash_nvram_recovery(void)
{
    NVRam_acquireLock();
    NVRam_disable();
    // Value pulled form the talos / blackbird. Update as needed.
    uint32_t cfg1 = 0x14080f3;
    uint32_t cfg2 = 0xd70081;
    uint32_t cfg3 = 0x3000a00;
    uint32_t sense = 0x30030;
    printf("Updating NvmCfg1 from %x to %x.\n", (uint32_t)NVM.NvmCfg1.r32, cfg1);
    printf("Updating NvmCfg2 from %x to %x.\n", (uint32_t)NVM.NvmCfg2.r32, cfg2);
    printf("Updating NvmCfg3 from %x to %x.\n", (uint32_t)NVM.NvmCfg3.r32, cfg3);
    printf("Updating AutoSenseStatus from %x to %x.\n", (uint32_t)NVM.AutoSenseStatus.r32, sense);
    NVM.NvmCfg1.r32 = cfg1;
    NVM.NvmCfg2.r32 = cfg2;
    NVM.NvmCfg3.r32 = cfg3;
    NVM.AutoSenseStatus.r32 = sense;

    NVRam_releaseLock();
}
