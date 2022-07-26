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
#include <bcm5719_APE.h>

void init_bcm5719_APE_sim(void *base,
    uint32_t (*read)(uint32_t val, uint32_t offset, void *args),
    uint32_t (*write)(uint32_t val, uint32_t offset, void *args))
{
    APE.mIndexReadCallback = read;
    APE.mIndexReadCallbackArgs = base;

    APE.mIndexWriteCallback = write;
    APE.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref APE. */
    /** @brief Bitmap for @ref APE_t.Mode. */
    APE.Mode.r32.installReadCallback(read, (uint8_t *)base);
    APE.Mode.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.Status. */
    APE.Status.r32.installReadCallback(read, (uint8_t *)base);
    APE.Status.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.GpioMessage. */
    APE.GpioMessage.r32.installReadCallback(read, (uint8_t *)base);
    APE.GpioMessage.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.Event. */
    APE.Event.r32.installReadCallback(read, (uint8_t *)base);
    APE.Event.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        APE.reserved_16[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_16[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.RxbufoffsetFunc0. */
    APE.RxbufoffsetFunc0.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxbufoffsetFunc0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.RxbufoffsetFunc1. */
    APE.RxbufoffsetFunc1.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxbufoffsetFunc1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetDoorbellFunc0. */
    APE.TxToNetDoorbellFunc0.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetDoorbellFunc0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxState0. */
    APE.TxState0.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxState0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxState1. */
    APE.TxState1.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxState1.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        APE.reserved_40[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_40[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.Mode2. */
    APE.Mode2.r32.installReadCallback(read, (uint8_t *)base);
    APE.Mode2.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.Status2. */
    APE.Status2.r32.installReadCallback(read, (uint8_t *)base);
    APE.Status2.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 6; i++)
    {
        APE.reserved_52[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_52[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.LockGrantObsolete. */
    APE.LockGrantObsolete.r32.installReadCallback(read, (uint8_t *)base);
    APE.LockGrantObsolete.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 10; i++)
    {
        APE.reserved_80[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_80[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.RxPoolModeStatus0. */
    APE.RxPoolModeStatus0.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxPoolModeStatus0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.RxPoolModeStatus1. */
    APE.RxPoolModeStatus1.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxPoolModeStatus1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.RxPoolRetire0. */
    APE.RxPoolRetire0.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxPoolRetire0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.RxPoolFreePointer0. */
    APE.RxPoolFreePointer0.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxPoolFreePointer0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.RxPoolRetire1. */
    APE.RxPoolRetire1.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxPoolRetire1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetPoolModeStatus0. */
    APE.TxToNetPoolModeStatus0.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetPoolModeStatus0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetBufferAllocator0. */
    APE.TxToNetBufferAllocator0.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetBufferAllocator0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetBufferReturn0. */
    APE.TxToNetBufferReturn0.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetBufferReturn0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetBufferRing0. */
    APE.TxToNetBufferRing0.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetBufferRing0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.RxPoolFreePointer1. */
    APE.RxPoolFreePointer1.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxPoolFreePointer1.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 2; i++)
    {
        APE.reserved_160[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_160[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.Tick1mhz. */
    APE.Tick1mhz.r32.installReadCallback(read, (uint8_t *)base);
    APE.Tick1mhz.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.Tick1khz. */
    APE.Tick1khz.r32.installReadCallback(read, (uint8_t *)base);
    APE.Tick1khz.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.Tick10hz. */
    APE.Tick10hz.r32.installReadCallback(read, (uint8_t *)base);
    APE.Tick10hz.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        APE.reserved_180[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_180[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.Gpio. */
    APE.Gpio.r32.installReadCallback(read, (uint8_t *)base);
    APE.Gpio.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.Gint. */
    APE.Gint.r32.installReadCallback(read, (uint8_t *)base);
    APE.Gint.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 10; i++)
    {
        APE.reserved_192[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_192[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.OtpControl. */
    APE.OtpControl.r32.installReadCallback(read, (uint8_t *)base);
    APE.OtpControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.OtpStatus. */
    APE.OtpStatus.r32.installReadCallback(read, (uint8_t *)base);
    APE.OtpStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.OtpAddr. */
    APE.OtpAddr.r32.installReadCallback(read, (uint8_t *)base);
    APE.OtpAddr.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        APE.reserved_244[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_244[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.OtpReadData. */
    APE.OtpReadData.r32.installReadCallback(read, (uint8_t *)base);
    APE.OtpReadData.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 3; i++)
    {
        APE.reserved_252[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_252[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.CpuStatus. */
    APE.CpuStatus.r32.installReadCallback(read, (uint8_t *)base);
    APE.CpuStatus.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 1; i++)
    {
        APE.reserved_268[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_268[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.TxToNetPoolModeStatus1. */
    APE.TxToNetPoolModeStatus1.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetPoolModeStatus1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetBufferAllocator1. */
    APE.TxToNetBufferAllocator1.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetBufferAllocator1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetBufferReturn1. */
    APE.TxToNetBufferReturn1.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetBufferReturn1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetBufferRing1. */
    APE.TxToNetBufferRing1.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetBufferRing1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetDoorbellFunc1. */
    APE.TxToNetDoorbellFunc1.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetDoorbellFunc1.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 55; i++)
    {
        APE.reserved_292[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_292[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.RxbufoffsetFunc2. */
    APE.RxbufoffsetFunc2.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxbufoffsetFunc2.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetDoorbellFunc2. */
    APE.TxToNetDoorbellFunc2.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetDoorbellFunc2.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxState2. */
    APE.TxState2.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxState2.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 2; i++)
    {
        APE.reserved_524[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_524[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.RxPoolModeStatus2. */
    APE.RxPoolModeStatus2.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxPoolModeStatus2.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.RxPoolRetire2. */
    APE.RxPoolRetire2.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxPoolRetire2.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.RxPoolFreePointer2. */
    APE.RxPoolFreePointer2.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxPoolFreePointer2.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetPoolModeStatus2. */
    APE.TxToNetPoolModeStatus2.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetPoolModeStatus2.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetBufferAllocator2. */
    APE.TxToNetBufferAllocator2.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetBufferAllocator2.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetBufferReturn2. */
    APE.TxToNetBufferReturn2.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetBufferReturn2.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetBufferRing2. */
    APE.TxToNetBufferRing2.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetBufferRing2.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 52; i++)
    {
        APE.reserved_560[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_560[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.RxbufoffsetFunc3. */
    APE.RxbufoffsetFunc3.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxbufoffsetFunc3.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetDoorbellFunc3. */
    APE.TxToNetDoorbellFunc3.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetDoorbellFunc3.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxState3. */
    APE.TxState3.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxState3.r32.installWriteCallback(write, (uint8_t *)base);

    for(int i = 0; i < 2; i++)
    {
        APE.reserved_780[i].installReadCallback(read, (uint8_t *)base);
        APE.reserved_780[i].installWriteCallback(write, (uint8_t *)base);
    }
    /** @brief Bitmap for @ref APE_t.RxPoolModeStatus3. */
    APE.RxPoolModeStatus3.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxPoolModeStatus3.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.RxPoolRetire3. */
    APE.RxPoolRetire3.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxPoolRetire3.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.RxPoolFreePointer3. */
    APE.RxPoolFreePointer3.r32.installReadCallback(read, (uint8_t *)base);
    APE.RxPoolFreePointer3.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetPoolModeStatus3. */
    APE.TxToNetPoolModeStatus3.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetPoolModeStatus3.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetBufferAllocator3. */
    APE.TxToNetBufferAllocator3.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetBufferAllocator3.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetBufferReturn3. */
    APE.TxToNetBufferReturn3.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetBufferReturn3.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref APE_t.TxToNetBufferRing3. */
    APE.TxToNetBufferRing3.r32.installReadCallback(read, (uint8_t *)base);
    APE.TxToNetBufferRing3.r32.installWriteCallback(write, (uint8_t *)base);


}
