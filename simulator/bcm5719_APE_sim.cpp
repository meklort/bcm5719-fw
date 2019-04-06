////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_APE_sim.cpp
///
/// @project    bcm5719
///
/// @brief      bcm5719_APE_sim
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
#include <bcm5719_APE.h>

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

void init_bcm5719_APE_sim(void *base)
{
    APE.mIndexReadCallback = read_from_ram;
    APE.mIndexReadCallbackArgs = base;

    APE.mIndexWriteCallback = write_to_ram;
    APE.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref APE. */
    /** @brief Bitmap for @ref APE_t.Mode. */
    APE.Mode.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.Mode.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.Status. */
    APE.Status.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.Status.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.GpioMessage. */
    APE.GpioMessage.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.GpioMessage.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.Event. */
    APE.Event.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.Event.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.RxbufoffsetFunc0. */
    APE.RxbufoffsetFunc0.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.RxbufoffsetFunc0.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.RxbufoffsetFunc1. */
    APE.RxbufoffsetFunc1.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.RxbufoffsetFunc1.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.Mode2. */
    APE.Mode2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.Mode2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.Status2. */
    APE.Status2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.Status2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.LockGrantObsolete. */
    APE.LockGrantObsolete.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.LockGrantObsolete.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.B0. */
    APE.B0.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.B0.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.Gpio. */
    APE.Gpio.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.Gpio.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.Gint. */
    APE.Gint.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.Gint.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.OtpControl. */
    APE.OtpControl.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.OtpControl.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.OtpStatus. */
    APE.OtpStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.OtpStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.OtpAddr. */
    APE.OtpAddr.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.OtpAddr.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.OtpReadData. */
    APE.OtpReadData.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.OtpReadData.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.Cm3. */
    APE.Cm3.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.Cm3.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy0. */
    APE.PerLockRequestPhy0.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockRequestPhy0.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockRequestGrc. */
    APE.PerLockRequestGrc.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockRequestGrc.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy1. */
    APE.PerLockRequestPhy1.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockRequestPhy1.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy2. */
    APE.PerLockRequestPhy2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockRequestPhy2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockRequestMem. */
    APE.PerLockRequestMem.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockRequestMem.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy3. */
    APE.PerLockRequestPhy3.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockRequestPhy3.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockRequestPort6. */
    APE.PerLockRequestPort6.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockRequestPort6.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockRequestGpio. */
    APE.PerLockRequestGpio.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockRequestGpio.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy0. */
    APE.PerLockGrantPhy0.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockGrantPhy0.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockGrantGrc. */
    APE.PerLockGrantGrc.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockGrantGrc.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy1. */
    APE.PerLockGrantPhy1.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockGrantPhy1.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy2. */
    APE.PerLockGrantPhy2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockGrantPhy2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockGrantMem. */
    APE.PerLockGrantMem.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockGrantMem.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy3. */
    APE.PerLockGrantPhy3.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockGrantPhy3.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockGrantPort6. */
    APE.PerLockGrantPort6.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockGrantPort6.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.PerLockGrantGpio. */
    APE.PerLockGrantGpio.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    APE.PerLockGrantGpio.r32.installWriteCallback(write_to_ram, (uint8_t *)base);


}
