////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_GEN_mmap.cpp
///
/// @project    bcm5719
///
/// @brief      bcm5719_GEN_mmap
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

typedef std::pair<uint8_t *, uint32_t> ram_offset_t;

static uint32_t read_from_ram(uint32_t val, void *args)
{
    ram_offset_t *loc = (ram_offset_t *)args;

    uint8_t *base = loc->first;
    base += loc->second;

    BARRIER();
    return *(uint32_t *)base;
}

static uint32_t write_to_ram(uint32_t val, void *args)
{
    ram_offset_t *loc = (ram_offset_t *)args;

    uint8_t *base = loc->first;
    base += loc->second;

    BARRIER();
    *(uint32_t *)base = val;
    BARRIER();
    return val;
}

void init_bcm5719_GEN_mmap(void *base)
{
    /** @brief Component Registers for @ref GEN. */
    /** @brief Bitmap for @ref GEN_t.GenFwMbox. */
    static ram_offset_t GEN_GenFwMbox_r32((uint8_t *)base, (uint32_t)0);
    GEN.GenFwMbox.r32.installReadCallback(read_from_ram, &GEN_GenFwMbox_r32);
    GEN.GenFwMbox.r32.installWriteCallback(write_to_ram, &GEN_GenFwMbox_r32);

    /** @brief Bitmap for @ref GEN_t.GenDataSig. */
    static ram_offset_t GEN_GenDataSig_r32((uint8_t *)base, (uint32_t)4);
    GEN.GenDataSig.r32.installReadCallback(read_from_ram, &GEN_GenDataSig_r32);
    GEN.GenDataSig.r32.installWriteCallback(write_to_ram, &GEN_GenDataSig_r32);

    /** @brief Bitmap for @ref GEN_t.GenCfg. */
    static ram_offset_t GEN_GenCfg_r32((uint8_t *)base, (uint32_t)8);
    GEN.GenCfg.r32.installReadCallback(read_from_ram, &GEN_GenCfg_r32);
    GEN.GenCfg.r32.installWriteCallback(write_to_ram, &GEN_GenCfg_r32);

    /** @brief Bitmap for @ref GEN_t.GenVersion. */
    static ram_offset_t GEN_GenVersion_r32((uint8_t *)base, (uint32_t)12);
    GEN.GenVersion.r32.installReadCallback(read_from_ram, &GEN_GenVersion_r32);
    GEN.GenVersion.r32.installWriteCallback(write_to_ram, &GEN_GenVersion_r32);

    /** @brief Bitmap for @ref GEN_t.GenPhyId. */
    static ram_offset_t GEN_GenPhyId_r32((uint8_t *)base, (uint32_t)36);
    GEN.GenPhyId.r32.installReadCallback(read_from_ram, &GEN_GenPhyId_r32);
    GEN.GenPhyId.r32.installWriteCallback(write_to_ram, &GEN_GenPhyId_r32);

    /** @brief Bitmap for @ref GEN_t.GenAsfStatusMbox. */
    static ram_offset_t GEN_GenAsfStatusMbox_r32((uint8_t *)base, (uint32_t)176);
    GEN.GenAsfStatusMbox.r32.installReadCallback(read_from_ram, &GEN_GenAsfStatusMbox_r32);
    GEN.GenAsfStatusMbox.r32.installWriteCallback(write_to_ram, &GEN_GenAsfStatusMbox_r32);

    /** @brief Bitmap for @ref GEN_t.GenFwDriverStateMbox. */
    static ram_offset_t GEN_GenFwDriverStateMbox_r32((uint8_t *)base, (uint32_t)180);
    GEN.GenFwDriverStateMbox.r32.installReadCallback(read_from_ram, &GEN_GenFwDriverStateMbox_r32);
    GEN.GenFwDriverStateMbox.r32.installWriteCallback(write_to_ram, &GEN_GenFwDriverStateMbox_r32);

    /** @brief Bitmap for @ref GEN_t.GenFwResetTypeMbox. */
    static ram_offset_t GEN_GenFwResetTypeMbox_r32((uint8_t *)base, (uint32_t)184);
    GEN.GenFwResetTypeMbox.r32.installReadCallback(read_from_ram, &GEN_GenFwResetTypeMbox_r32);
    GEN.GenFwResetTypeMbox.r32.installWriteCallback(write_to_ram, &GEN_GenFwResetTypeMbox_r32);

    /** @brief Bitmap for @ref GEN_t.GenBc. */
    static ram_offset_t GEN_GenBc_r32((uint8_t *)base, (uint32_t)188);
    GEN.GenBc.r32.installReadCallback(read_from_ram, &GEN_GenBc_r32);
    GEN.GenBc.r32.installWriteCallback(write_to_ram, &GEN_GenBc_r32);

    /** @brief Bitmap for @ref GEN_t.GenMacAddrHighMbox. */
    static ram_offset_t GEN_GenMacAddrHighMbox_r32((uint8_t *)base, (uint32_t)196);
    GEN.GenMacAddrHighMbox.r32.installReadCallback(read_from_ram, &GEN_GenMacAddrHighMbox_r32);
    GEN.GenMacAddrHighMbox.r32.installWriteCallback(write_to_ram, &GEN_GenMacAddrHighMbox_r32);

    /** @brief Bitmap for @ref GEN_t.GenMacAddrLowMbox. */
    static ram_offset_t GEN_GenMacAddrLowMbox_r32((uint8_t *)base, (uint32_t)200);
    GEN.GenMacAddrLowMbox.r32.installReadCallback(read_from_ram, &GEN_GenMacAddrLowMbox_r32);
    GEN.GenMacAddrLowMbox.r32.installWriteCallback(write_to_ram, &GEN_GenMacAddrLowMbox_r32);

    /** @brief Bitmap for @ref GEN_t.GenD8. */
    static ram_offset_t GEN_GenD8_r32((uint8_t *)base, (uint32_t)216);
    GEN.GenD8.r32.installReadCallback(read_from_ram, &GEN_GenD8_r32);
    GEN.GenD8.r32.installWriteCallback(write_to_ram, &GEN_GenD8_r32);

    /** @brief Bitmap for @ref GEN_t.Gen1dc. */
    static ram_offset_t GEN_Gen1dc_r32((uint8_t *)base, (uint32_t)476);
    GEN.Gen1dc.r32.installReadCallback(read_from_ram, &GEN_Gen1dc_r32);
    GEN.Gen1dc.r32.installWriteCallback(write_to_ram, &GEN_Gen1dc_r32);

    /** @brief Bitmap for @ref GEN_t.GenWolMbox. */
    static ram_offset_t GEN_GenWolMbox_r32((uint8_t *)base, (uint32_t)480);
    GEN.GenWolMbox.r32.installReadCallback(read_from_ram, &GEN_GenWolMbox_r32);
    GEN.GenWolMbox.r32.installWriteCallback(write_to_ram, &GEN_GenWolMbox_r32);

    /** @brief Bitmap for @ref GEN_t.GenCfgFeature. */
    static ram_offset_t GEN_GenCfgFeature_r32((uint8_t *)base, (uint32_t)484);
    GEN.GenCfgFeature.r32.installReadCallback(read_from_ram, &GEN_GenCfgFeature_r32);
    GEN.GenCfgFeature.r32.installWriteCallback(write_to_ram, &GEN_GenCfgFeature_r32);

    /** @brief Bitmap for @ref GEN_t.GenCfgHw. */
    static ram_offset_t GEN_GenCfgHw_r32((uint8_t *)base, (uint32_t)488);
    GEN.GenCfgHw.r32.installReadCallback(read_from_ram, &GEN_GenCfgHw_r32);
    GEN.GenCfgHw.r32.installWriteCallback(write_to_ram, &GEN_GenCfgHw_r32);

    /** @brief Bitmap for @ref GEN_t.GenCfgShared. */
    static ram_offset_t GEN_GenCfgShared_r32((uint8_t *)base, (uint32_t)492);
    GEN.GenCfgShared.r32.installReadCallback(read_from_ram, &GEN_GenCfgShared_r32);
    GEN.GenCfgShared.r32.installWriteCallback(write_to_ram, &GEN_GenCfgShared_r32);

    /** @brief Bitmap for @ref GEN_t.GenFwVersion. */
    static ram_offset_t GEN_GenFwVersion_r32((uint8_t *)base, (uint32_t)532);
    GEN.GenFwVersion.r32.installReadCallback(read_from_ram, &GEN_GenFwVersion_r32);
    GEN.GenFwVersion.r32.installWriteCallback(write_to_ram, &GEN_GenFwVersion_r32);

    /** @brief Bitmap for @ref GEN_t.GenCfgHw2. */
    static ram_offset_t GEN_GenCfgHw2_r32((uint8_t *)base, (uint32_t)680);
    GEN.GenCfgHw2.r32.installReadCallback(read_from_ram, &GEN_GenCfgHw2_r32);
    GEN.GenCfgHw2.r32.installWriteCallback(write_to_ram, &GEN_GenCfgHw2_r32);

    /** @brief Bitmap for @ref GEN_t.GenCpmuStatus. */
    static ram_offset_t GEN_GenCpmuStatus_r32((uint8_t *)base, (uint32_t)688);
    GEN.GenCpmuStatus.r32.installReadCallback(read_from_ram, &GEN_GenCpmuStatus_r32);
    GEN.GenCpmuStatus.r32.installWriteCallback(write_to_ram, &GEN_GenCpmuStatus_r32);

    /** @brief Bitmap for @ref GEN_t.GenCfg5. */
    static ram_offset_t GEN_GenCfg5_r32((uint8_t *)base, (uint32_t)700);
    GEN.GenCfg5.r32.installReadCallback(read_from_ram, &GEN_GenCfg5_r32);
    GEN.GenCfg5.r32.installWriteCallback(write_to_ram, &GEN_GenCfg5_r32);

    /** @brief Bitmap for @ref GEN_t.GenDbgControlStatus. */
    static ram_offset_t GEN_GenDbgControlStatus_r32((uint8_t *)base, (uint32_t)864);
    GEN.GenDbgControlStatus.r32.installReadCallback(read_from_ram, &GEN_GenDbgControlStatus_r32);
    GEN.GenDbgControlStatus.r32.installWriteCallback(write_to_ram, &GEN_GenDbgControlStatus_r32);

    /** @brief Bitmap for @ref GEN_t.GenDbgData. */
    static ram_offset_t GEN_GenDbgData_r32((uint8_t *)base, (uint32_t)868);
    GEN.GenDbgData.r32.installReadCallback(read_from_ram, &GEN_GenDbgData_r32);
    GEN.GenDbgData.r32.installWriteCallback(write_to_ram, &GEN_GenDbgData_r32);


}
