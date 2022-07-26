////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_NVM_sim.cpp
///
/// @project    bcm5719
///
/// @brief      bcm5719_NVM_sim
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2022, Evan Lojewski
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
/// 3. Neither the name of the <organization> nor the
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

#include <stdint.h>
#include <utility>
#include <bcm5719_NVM.h>

void init_bcm5719_NVM_sim(void *base,
    uint32_t (*read)(uint32_t val, uint32_t offset, void *args),
    uint32_t (*write)(uint32_t val, uint32_t offset, void *args))
{
    NVM.mIndexReadCallback = read;
    NVM.mIndexReadCallbackArgs = base;

    NVM.mIndexWriteCallback = write;
    NVM.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref NVM. */
    /** @brief Bitmap for @ref NVM_t.Command. */
    NVM.Command.r32.installReadCallback(read, (uint8_t *)base);
    NVM.Command.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        NVM.reserved_4[i].installReadCallback(read, (uint8_t *)base);
        NVM.reserved_4[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref NVM_t.Write. */
    NVM.Write.r32.installReadCallback(read, (uint8_t *)base);
    NVM.Write.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVM_t.Addr. */
    NVM.Addr.r32.installReadCallback(read, (uint8_t *)base);
    NVM.Addr.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVM_t.Read. */
    NVM.Read.r32.installReadCallback(read, (uint8_t *)base);
    NVM.Read.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVM_t.NvmCfg1. */
    NVM.NvmCfg1.r32.installReadCallback(read, (uint8_t *)base);
    NVM.NvmCfg1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVM_t.NvmCfg2. */
    NVM.NvmCfg2.r32.installReadCallback(read, (uint8_t *)base);
    NVM.NvmCfg2.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVM_t.NvmCfg3. */
    NVM.NvmCfg3.r32.installReadCallback(read, (uint8_t *)base);
    NVM.NvmCfg3.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVM_t.SoftwareArbitration. */
    NVM.SoftwareArbitration.r32.installReadCallback(read, (uint8_t *)base);
    NVM.SoftwareArbitration.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVM_t.Access. */
    NVM.Access.r32.installReadCallback(read, (uint8_t *)base);
    NVM.Access.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVM_t.NvmWrite1. */
    NVM.NvmWrite1.r32.installReadCallback(read, (uint8_t *)base);
    NVM.NvmWrite1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVM_t.ArbitrationWatchdog. */
    NVM.ArbitrationWatchdog.r32.installReadCallback(read, (uint8_t *)base);
    NVM.ArbitrationWatchdog.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 2; i++)
    {
        NVM.reserved_48[i].installReadCallback(read, (uint8_t *)base);
        NVM.reserved_48[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref NVM_t.AutoSenseStatus. */
    NVM.AutoSenseStatus.r32.installReadCallback(read, (uint8_t *)base);
    NVM.AutoSenseStatus.r32.installWriteCallback(write, (uint8_t *)base);


}
