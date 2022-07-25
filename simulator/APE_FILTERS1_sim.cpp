////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_FILTERS1_sim.cpp
///
/// @project    ape
///
/// @brief      APE_FILTERS1_sim
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
#include <bcm5719_SHM.h>
#include <APE_FILTERS1.h>

void init_APE_FILTERS1_sim(void *arg0,
    uint32_t (*read)(uint32_t val, uint32_t offset, void *args),
    uint32_t (*write)(uint32_t val, uint32_t offset, void *args))
{
    (void)arg0; // unused
    void* base = (void*)0xa0058000;

    FILTERS1.mIndexReadCallback = read;
    FILTERS1.mIndexReadCallbackArgs = base;

    FILTERS1.mIndexWriteCallback = write;
    FILTERS1.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref FILTERS1. */
    /** @brief Bitmap for @ref FILTERS1_t.ElementConfig. */
    for(int i = 0; i < 32; i++)
    {
        FILTERS1.ElementConfig[i].r32.installReadCallback(read, (uint8_t *)base);
        FILTERS1.ElementConfig[i].r32.installWriteCallback(write, (uint8_t *)base);
    }

    /** @brief Bitmap for @ref FILTERS1_t.ElementPattern. */
    for(int i = 0; i < 32; i++)
    {
        FILTERS1.ElementPattern[i].r32.installReadCallback(read, (uint8_t *)base);
        FILTERS1.ElementPattern[i].r32.installWriteCallback(write, (uint8_t *)base);
    }

    /** @brief Bitmap for @ref FILTERS1_t.RuleConfiguration. */
    FILTERS1.RuleConfiguration.r32.installReadCallback(read, (uint8_t *)base);
    FILTERS1.RuleConfiguration.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref FILTERS1_t.RuleSet. */
    for(int i = 0; i < 31; i++)
    {
        FILTERS1.RuleSet[i].r32.installReadCallback(read, (uint8_t *)base);
        FILTERS1.RuleSet[i].r32.installWriteCallback(write, (uint8_t *)base);
    }

    /** @brief Bitmap for @ref FILTERS1_t.RuleMask. */
    for(int i = 0; i < 31; i++)
    {
        FILTERS1.RuleMask[i].r32.installReadCallback(read, (uint8_t *)base);
        FILTERS1.RuleMask[i].r32.installWriteCallback(write, (uint8_t *)base);
    }


}
