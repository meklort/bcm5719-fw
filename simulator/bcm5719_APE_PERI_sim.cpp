////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_APE_PERI_sim.cpp
///
/// @project    bcm5719
///
/// @brief      bcm5719_APE_PERI_sim
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
#include <bcm5719_APE_PERI.h>

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

void init_bcm5719_APE_PERI_sim(void *base)
{
    APE_PERI.mIndexReadCallback = read_from_ram;
    APE_PERI.mIndexReadCallbackArgs = base;

    APE_PERI.mIndexWriteCallback = write_to_ram;
    APE_PERI.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref APE_PERI. */
    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcRxStatus. */
    APE_PERI.BmcToNcRxStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcRxStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacHigh. */
    APE_PERI.BmcToNcSourceMacHigh.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacHigh.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacLow. */
    APE_PERI.BmcToNcSourceMacLow.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacLow.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch0High. */
    APE_PERI.BmcToNcSourceMacMatch0High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch0High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch0Low. */
    APE_PERI.BmcToNcSourceMacMatch0Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch0Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch1High. */
    APE_PERI.BmcToNcSourceMacMatch1High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch1High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch1Low. */
    APE_PERI.BmcToNcSourceMacMatch1Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch1Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch2High. */
    APE_PERI.BmcToNcSourceMacMatch2High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch2High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch2Low. */
    APE_PERI.BmcToNcSourceMacMatch2Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch2Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch3High. */
    APE_PERI.BmcToNcSourceMacMatch3High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch3High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch3Low. */
    APE_PERI.BmcToNcSourceMacMatch3Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch3Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch4High. */
    APE_PERI.BmcToNcSourceMacMatch4High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch4High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch4Low. */
    APE_PERI.BmcToNcSourceMacMatch4Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch4Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch5High. */
    APE_PERI.BmcToNcSourceMacMatch5High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch5High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch5Low. */
    APE_PERI.BmcToNcSourceMacMatch5Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch5Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch6High. */
    APE_PERI.BmcToNcSourceMacMatch6High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch6High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch6Low. */
    APE_PERI.BmcToNcSourceMacMatch6Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch6Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch7High. */
    APE_PERI.BmcToNcSourceMacMatch7High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch7High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcSourceMacMatch7Low. */
    APE_PERI.BmcToNcSourceMacMatch7Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcSourceMacMatch7Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcRxVlan. */
    APE_PERI.BmcToNcRxVlan.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcRxVlan.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcReadBuffer. */
    APE_PERI.BmcToNcReadBuffer.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcReadBuffer.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcRxControl. */
    APE_PERI.BmcToNcRxControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcRxControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcTxStatus. */
    APE_PERI.BmcToNcTxStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcTxStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcTxControl. */
    APE_PERI.BmcToNcTxControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcTxControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcTxBuffer. */
    APE_PERI.BmcToNcTxBuffer.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcTxBuffer.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.BmcToNcTxBufferLast. */
    APE_PERI.BmcToNcTxBufferLast.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.BmcToNcTxBufferLast.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.RmuControl. */
    APE_PERI.RmuControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.RmuControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.ArbControl. */
    APE_PERI.ArbControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.ArbControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockRequestPhy0. */
    APE_PERI.PerLockRequestPhy0.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockRequestPhy0.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockRequestGrc. */
    APE_PERI.PerLockRequestGrc.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockRequestGrc.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockRequestPhy1. */
    APE_PERI.PerLockRequestPhy1.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockRequestPhy1.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockRequestPhy2. */
    APE_PERI.PerLockRequestPhy2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockRequestPhy2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockRequestMem. */
    APE_PERI.PerLockRequestMem.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockRequestMem.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockRequestPhy3. */
    APE_PERI.PerLockRequestPhy3.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockRequestPhy3.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockRequestPort6. */
    APE_PERI.PerLockRequestPort6.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockRequestPort6.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockRequestGpio. */
    APE_PERI.PerLockRequestGpio.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockRequestGpio.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockGrantPhy0. */
    APE_PERI.PerLockGrantPhy0.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockGrantPhy0.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockGrantGrc. */
    APE_PERI.PerLockGrantGrc.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockGrantGrc.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockGrantPhy1. */
    APE_PERI.PerLockGrantPhy1.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockGrantPhy1.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockGrantPhy2. */
    APE_PERI.PerLockGrantPhy2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockGrantPhy2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockGrantMem. */
    APE_PERI.PerLockGrantMem.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockGrantMem.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockGrantPhy3. */
    APE_PERI.PerLockGrantPhy3.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockGrantPhy3.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockGrantPort6. */
    APE_PERI.PerLockGrantPort6.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockGrantPort6.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_PERI_t.PerLockGrantGpio. */
    APE_PERI.PerLockGrantGpio.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE_PERI.PerLockGrantGpio.r32.installWriteCallback(write_to_ram, (uint8_t *)base);


}
