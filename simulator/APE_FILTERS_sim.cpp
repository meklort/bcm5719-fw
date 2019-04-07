////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_FILTERS_sim.cpp
///
/// @project    ape
///
/// @brief      APE_FILTERS_sim
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
#include <bcm5719_SHM.h>
#include <APE_FILTERS.h>

static uint32_t loader_read_mem(uint32_t val, uint32_t offset, void *args)
{
    uint32_t addr = (uint32_t)((uint64_t)args);
    addr += offset;

    SHM.LoaderArg0.r32 = addr;
    SHM.LoaderCommand.bits.Command = SHM_LOADER_COMMAND_COMMAND_READ_MEM;

    // Wait for command to be handled.
    while(0 != SHM.LoaderCommand.bits.Command);

    return (uint32_t)SHM.LoaderArg0.r32;
}

static uint32_t loader_write_mem(uint32_t val, uint32_t offset, void *args)
{
    uint32_t addr = (uint32_t)((uint64_t)args);
    addr += offset;

    SHM.LoaderArg0.r32 = addr;
    SHM.LoaderArg1.r32 = val;
    SHM.LoaderCommand.bits.Command = SHM_LOADER_COMMAND_COMMAND_WRITE_MEM;

    // Wait for command to be handled.
    while(0 != SHM.LoaderCommand.bits.Command);

    return val;
}

void init_APE_FILTERS_sim(void *arg0)
{
    (void)arg0; // unused
    void* base = (void*)0xa0048000;

    FILTERS.mIndexReadCallback = loader_read_mem;
    FILTERS.mIndexReadCallbackArgs = base;

    FILTERS.mIndexWriteCallback = loader_write_mem;
    FILTERS.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref FILTERS. */
    /** @brief Bitmap for @ref FILTERS_t.ElementConfig. */
    for(int i = 0; i < 32; i++)
    {
        FILTERS.ElementConfig[i].r32.installReadCallback(loader_read_mem, ((uint8_t *)base) + (i * 4));
        FILTERS.ElementConfig[i].r32.installWriteCallback(loader_write_mem, ((uint8_t *)base) + (i * 4));
    }

    /** @brief Bitmap for @ref FILTERS_t.ElementPattern. */
    for(int i = 0; i < 32; i++)
    {
        FILTERS.ElementPattern[i].r32.installReadCallback(loader_read_mem, ((uint8_t *)base) + (i * 4));
        FILTERS.ElementPattern[i].r32.installWriteCallback(loader_write_mem, ((uint8_t *)base) + (i * 4));
    }

    /** @brief Bitmap for @ref FILTERS_t.RuleConfiguration. */
    FILTERS.RuleConfiguration.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    FILTERS.RuleConfiguration.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref FILTERS_t.RuleSet. */
    for(int i = 0; i < 31; i++)
    {
        FILTERS.RuleSet[i].r32.installReadCallback(loader_read_mem, ((uint8_t *)base) + (i * 4));
        FILTERS.RuleSet[i].r32.installWriteCallback(loader_write_mem, ((uint8_t *)base) + (i * 4));
    }

    /** @brief Bitmap for @ref FILTERS_t.RuleMask. */
    for(int i = 0; i < 31; i++)
    {
        FILTERS.RuleMask[i].r32.installReadCallback(loader_read_mem, ((uint8_t *)base) + (i * 4));
        FILTERS.RuleMask[i].r32.installWriteCallback(loader_write_mem, ((uint8_t *)base) + (i * 4));
    }


}
