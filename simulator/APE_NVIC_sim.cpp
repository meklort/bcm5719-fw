////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_NVIC_sim.cpp
///
/// @project    ape
///
/// @brief      APE_NVIC_sim
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
#include <APE_NVIC.h>

void init_APE_NVIC_sim(void *arg0,
    uint32_t (*read)(uint32_t val, uint32_t offset, void *args),
    uint32_t (*write)(uint32_t val, uint32_t offset, void *args))
{
    (void)arg0; // unused
    void* base = (void*)0xe000e000;

    NVIC.mIndexReadCallback = read;
    NVIC.mIndexReadCallbackArgs = base;

    NVIC.mIndexWriteCallback = write;
    NVIC.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref NVIC. */
    /** @brief Bitmap for @ref NVIC_t.InterruptControlType. */
    NVIC.InterruptControlType.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.InterruptControlType.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.SystickControlAndStatus. */
    NVIC.SystickControlAndStatus.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.SystickControlAndStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.SystickReloadValue. */
    NVIC.SystickReloadValue.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.SystickReloadValue.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.SystickCurrentValue. */
    NVIC.SystickCurrentValue.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.SystickCurrentValue.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.SystickCalibrationValue. */
    NVIC.SystickCalibrationValue.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.SystickCalibrationValue.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.InterruptSetEnable. */
    NVIC.InterruptSetEnable.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.InterruptSetEnable.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.InterruptClearEnable. */
    NVIC.InterruptClearEnable.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.InterruptClearEnable.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.InterruptSetPending. */
    NVIC.InterruptSetPending.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.InterruptSetPending.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.InterruptClearPending. */
    NVIC.InterruptClearPending.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.InterruptClearPending.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.ActiveBit. */
    NVIC.ActiveBit.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.ActiveBit.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.InterruptPriority0. */
    NVIC.InterruptPriority0.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.InterruptPriority0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.InterruptPriority1. */
    NVIC.InterruptPriority1.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.InterruptPriority1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.CpuId. */
    NVIC.CpuId.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.CpuId.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.InterruptControlState. */
    NVIC.InterruptControlState.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.InterruptControlState.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.VectorTableOffset. */
    NVIC.VectorTableOffset.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.VectorTableOffset.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.ApplicationInterruptAndResetControl. */
    NVIC.ApplicationInterruptAndResetControl.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.ApplicationInterruptAndResetControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.SystemControl. */
    NVIC.SystemControl.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.SystemControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.ConfigurationControl. */
    NVIC.ConfigurationControl.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.ConfigurationControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.SystemHandlerPriority4. */
    NVIC.SystemHandlerPriority4.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.SystemHandlerPriority4.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.SystemHandlerPriority8. */
    NVIC.SystemHandlerPriority8.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.SystemHandlerPriority8.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.SystemHandlerPriority12. */
    NVIC.SystemHandlerPriority12.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.SystemHandlerPriority12.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.SystemHandlerControlAndState. */
    NVIC.SystemHandlerControlAndState.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.SystemHandlerControlAndState.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.FaultStatus. */
    NVIC.FaultStatus.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.FaultStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.HardFaultStatus. */
    NVIC.HardFaultStatus.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.HardFaultStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.DebugFaultStatus. */
    NVIC.DebugFaultStatus.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.DebugFaultStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.MemoryManageFaultAddress. */
    NVIC.MemoryManageFaultAddress.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.MemoryManageFaultAddress.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.BusFaultAddress. */
    NVIC.BusFaultAddress.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.BusFaultAddress.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.AuxiliaryFaultAddress. */
    NVIC.AuxiliaryFaultAddress.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.AuxiliaryFaultAddress.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref NVIC_t.SoftwareTriggerInterrupt. */
    NVIC.SoftwareTriggerInterrupt.r32.installReadCallback(read, (uint8_t *)base);
    NVIC.SoftwareTriggerInterrupt.r32.installWriteCallback(write, (uint8_t *)base);


}
