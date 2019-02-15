////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_NVM_mmap.cpp
///
/// @project    <PROJECT>
///
/// @brief      bcm5719_NVM_mmap
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

typedef std::pair<uint8_t *, uint32_t> ram_offset_t;

static uint32_t read_from_ram(uint32_t val, void *args)
{
    ram_offset_t *loc = (ram_offset_t *)args;

    uint8_t *base = loc->first;
    base += loc->second;

    return *(uint32_t *)base;
}

static uint32_t write_to_ram(uint32_t val, void *args)
{
    ram_offset_t *loc = (ram_offset_t *)args;

    uint8_t *base = loc->first;
    base += loc->second;

    *(uint32_t *)base = val;
    return val;
}

void init_bcm5719_NVM_mmap(void *base)
{
    /** @brief Component Registers for @ref NVM. */
    /** @brief Bitmap for @ref NVM_t.Command. */
    static ram_offset_t NVM_Command_r32((uint8_t *)base, (uint32_t)0);
    NVM.Command.r32.installReadCallback(read_from_ram, &NVM_Command_r32);
    NVM.Command.r32.installWriteCallback(write_to_ram, &NVM_Command_r32);

    /** @brief Bitmap for @ref NVM_t.Write. */
    static ram_offset_t NVM_Write_r32((uint8_t *)base, (uint32_t)8);
    NVM.Write.r32.installReadCallback(read_from_ram, &NVM_Write_r32);
    NVM.Write.r32.installWriteCallback(write_to_ram, &NVM_Write_r32);

    /** @brief Bitmap for @ref NVM_t.Addr. */
    static ram_offset_t NVM_Addr_r32((uint8_t *)base, (uint32_t)12);
    NVM.Addr.r32.installReadCallback(read_from_ram, &NVM_Addr_r32);
    NVM.Addr.r32.installWriteCallback(write_to_ram, &NVM_Addr_r32);

    /** @brief Bitmap for @ref NVM_t.Read. */
    static ram_offset_t NVM_Read_r32((uint8_t *)base, (uint32_t)16);
    NVM.Read.r32.installReadCallback(read_from_ram, &NVM_Read_r32);
    NVM.Read.r32.installWriteCallback(write_to_ram, &NVM_Read_r32);

    /** @brief Bitmap for @ref NVM_t.NvmCfg1. */
    static ram_offset_t NVM_NvmCfg1_r32((uint8_t *)base, (uint32_t)20);
    NVM.NvmCfg1.r32.installReadCallback(read_from_ram, &NVM_NvmCfg1_r32);
    NVM.NvmCfg1.r32.installWriteCallback(write_to_ram, &NVM_NvmCfg1_r32);

    /** @brief Bitmap for @ref NVM_t.SoftwareArbitration. */
    static ram_offset_t NVM_SoftwareArbitration_r32((uint8_t *)base, (uint32_t)32);
    NVM.SoftwareArbitration.r32.installReadCallback(read_from_ram, &NVM_SoftwareArbitration_r32);
    NVM.SoftwareArbitration.r32.installWriteCallback(write_to_ram, &NVM_SoftwareArbitration_r32);

    /** @brief Bitmap for @ref NVM_t.Access. */
    static ram_offset_t NVM_Access_r32((uint8_t *)base, (uint32_t)36);
    NVM.Access.r32.installReadCallback(read_from_ram, &NVM_Access_r32);
    NVM.Access.r32.installWriteCallback(write_to_ram, &NVM_Access_r32);


}
