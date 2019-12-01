////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_GEN_sim.cpp
///
/// @project    bcm5719
///
/// @brief      bcm5719_GEN_sim
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
#include <bcm5719_GEN.h>

#ifdef __ppc64__
#define BARRIER()    do { asm volatile ("sync 0\neieio\n" ::: "memory"); } while(0)
#else
#define BARRIER()    do { asm volatile ("" ::: "memory"); } while(0)
#endif

static uint32_t read_from_ram(uint32_t val, uint32_t offset, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += offset;

    BARRIER();
    return *(uint32_t *)base;
}

static uint32_t write_to_ram(uint32_t val, uint32_t offset, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += offset;

    BARRIER();
    *(uint32_t *)base = val;
    BARRIER();
    return val;
}

void init_bcm5719_GEN_sim(void *base)
{
    GEN.mIndexReadCallback = read_from_ram;
    GEN.mIndexReadCallbackArgs = base;

    GEN.mIndexWriteCallback = write_to_ram;
    GEN.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref GEN. */
    /** @brief Bitmap for @ref GEN_t.GenFwMbox. */
    GEN.GenFwMbox.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenFwMbox.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref GEN_t.GenDataSig. */
    GEN.GenDataSig.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenDataSig.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref GEN_t.GenCfg. */
    GEN.GenCfg.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenCfg.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref GEN_t.GenVersion. */
    GEN.GenVersion.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenVersion.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 5; i++)
    {
        GEN.reserved_16[i].installReadCallback(read_from_ram, (uint8_t *)base);
        GEN.reserved_16[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref GEN_t.GenPhyId. */
    GEN.GenPhyId.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenPhyId.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 34; i++)
    {
        GEN.reserved_40[i].installReadCallback(read_from_ram, (uint8_t *)base);
        GEN.reserved_40[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref GEN_t.GenAsfStatusMbox. */
    GEN.GenAsfStatusMbox.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenAsfStatusMbox.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref GEN_t.GenFwDriverStateMbox. */
    GEN.GenFwDriverStateMbox.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenFwDriverStateMbox.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref GEN_t.GenFwResetTypeMbox. */
    GEN.GenFwResetTypeMbox.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenFwResetTypeMbox.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref GEN_t.GenBc. */
    GEN.GenBc.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenBc.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        GEN.reserved_192[i].installReadCallback(read_from_ram, (uint8_t *)base);
        GEN.reserved_192[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref GEN_t.GenMacAddrHighMbox. */
    GEN.GenMacAddrHighMbox.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenMacAddrHighMbox.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref GEN_t.GenMacAddrLowMbox. */
    GEN.GenMacAddrLowMbox.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenMacAddrLowMbox.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 3; i++)
    {
        GEN.reserved_204[i].installReadCallback(read_from_ram, (uint8_t *)base);
        GEN.reserved_204[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref GEN_t.GenD8. */
    GEN.GenD8.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenD8.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 64; i++)
    {
        GEN.reserved_220[i].installReadCallback(read_from_ram, (uint8_t *)base);
        GEN.reserved_220[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref GEN_t.Gen1dc. */
    GEN.Gen1dc.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.Gen1dc.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref GEN_t.GenWolMbox. */
    GEN.GenWolMbox.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenWolMbox.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref GEN_t.GenCfgFeature. */
    GEN.GenCfgFeature.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenCfgFeature.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref GEN_t.GenCfgHw. */
    GEN.GenCfgHw.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenCfgHw.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref GEN_t.GenCfgShared. */
    GEN.GenCfgShared.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenCfgShared.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 9; i++)
    {
        GEN.reserved_496[i].installReadCallback(read_from_ram, (uint8_t *)base);
        GEN.reserved_496[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref GEN_t.GenFwVersion. */
    GEN.GenFwVersion.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenFwVersion.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 36; i++)
    {
        GEN.reserved_536[i].installReadCallback(read_from_ram, (uint8_t *)base);
        GEN.reserved_536[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref GEN_t.GenCfgHw2. */
    GEN.GenCfgHw2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenCfgHw2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        GEN.reserved_684[i].installReadCallback(read_from_ram, (uint8_t *)base);
        GEN.reserved_684[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref GEN_t.GenCpmuStatus. */
    GEN.GenCpmuStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenCpmuStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 2; i++)
    {
        GEN.reserved_692[i].installReadCallback(read_from_ram, (uint8_t *)base);
        GEN.reserved_692[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref GEN_t.GenCfg5. */
    GEN.GenCfg5.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenCfg5.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    for(int i = 0; i < 40; i++)
    {
        GEN.reserved_704[i].installReadCallback(read_from_ram, (uint8_t *)base);
        GEN.reserved_704[i].installWriteCallback(write_to_ram, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref GEN_t.GenDbgControlStatus. */
    GEN.GenDbgControlStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenDbgControlStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref GEN_t.GenDbgData. */
    GEN.GenDbgData.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    GEN.GenDbgData.r32.installWriteCallback(write_to_ram, (uint8_t *)base);


}
