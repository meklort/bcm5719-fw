////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_DEVICE1_sim.cpp
///
/// @project    ape
///
/// @brief      APE_DEVICE1_sim
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
#include <APE_DEVICE1.h>

void init_APE_DEVICE1_sim(void *arg0,
    uint32_t (*read)(uint32_t val, uint32_t offset, void *args),
    uint32_t (*write)(uint32_t val, uint32_t offset, void *args))
{
    (void)arg0; // unused
    void* base = (void*)0xa0050000;

    DEVICE1.mIndexReadCallback = read;
    DEVICE1.mIndexReadCallbackArgs = base;

    DEVICE1.mIndexWriteCallback = write;
    DEVICE1.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref DEVICE1. */
    /** @brief Bitmap for @ref DEVICE1_t.MiscellaneousHostControl. */
    DEVICE1.MiscellaneousHostControl.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.MiscellaneousHostControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciState. */
    DEVICE1.PciState.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciState.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RegisterBase. */
    DEVICE1.RegisterBase.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RegisterBase.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.MemoryBase. */
    DEVICE1.MemoryBase.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.MemoryBase.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RegisterData. */
    DEVICE1.RegisterData.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RegisterData.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.UndiReceiveReturnRingConsumerIndex. */
    DEVICE1.UndiReceiveReturnRingConsumerIndex.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.UndiReceiveReturnRingConsumerIndex.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.UndiReceiveReturnRingConsumerIndexLow. */
    DEVICE1.UndiReceiveReturnRingConsumerIndexLow.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.UndiReceiveReturnRingConsumerIndexLow.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.LinkStatusControl. */
    DEVICE1.LinkStatusControl.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.LinkStatusControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.ApeMemoryBase. */
    DEVICE1.ApeMemoryBase.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.ApeMemoryBase.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.ApeMemoryData. */
    DEVICE1.ApeMemoryData.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.ApeMemoryData.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.160. */
    DEVICE1._160.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1._160.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EmacMode. */
    DEVICE1.EmacMode.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EmacMode.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EmacStatus. */
    DEVICE1.EmacStatus.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EmacStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EmacEvent. */
    DEVICE1.EmacEvent.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EmacEvent.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.LedControl. */
    DEVICE1.LedControl.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.LedControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses0High. */
    DEVICE1.EmacMacAddresses0High.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EmacMacAddresses0High.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses0Low. */
    DEVICE1.EmacMacAddresses0Low.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EmacMacAddresses0Low.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses1High. */
    DEVICE1.EmacMacAddresses1High.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EmacMacAddresses1High.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses1Low. */
    DEVICE1.EmacMacAddresses1Low.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EmacMacAddresses1Low.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses2High. */
    DEVICE1.EmacMacAddresses2High.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EmacMacAddresses2High.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses2Low. */
    DEVICE1.EmacMacAddresses2Low.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EmacMacAddresses2Low.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses3High. */
    DEVICE1.EmacMacAddresses3High.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EmacMacAddresses3High.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EmacMacAddresses3Low. */
    DEVICE1.EmacMacAddresses3Low.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EmacMacAddresses3Low.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.WolPatternPointer. */
    DEVICE1.WolPatternPointer.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.WolPatternPointer.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.WolPatternCfg. */
    DEVICE1.WolPatternCfg.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.WolPatternCfg.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.438. */
    DEVICE1._438.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1._438.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.MtuSize. */
    DEVICE1.MtuSize.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.MtuSize.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.MiiCommunication. */
    DEVICE1.MiiCommunication.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.MiiCommunication.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.MiiMode. */
    DEVICE1.MiiMode.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.MiiMode.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.TransmitMacMode. */
    DEVICE1.TransmitMacMode.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.TransmitMacMode.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.TransmitMacStatus. */
    DEVICE1.TransmitMacStatus.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.TransmitMacStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.TransmitMacLengths. */
    DEVICE1.TransmitMacLengths.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.TransmitMacLengths.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.ReceiveMacMode. */
    DEVICE1.ReceiveMacMode.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.ReceiveMacMode.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.ReceiveMacStatus. */
    DEVICE1.ReceiveMacStatus.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.ReceiveMacStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch1High. */
    DEVICE1.PerfectMatch1High.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PerfectMatch1High.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch1Low. */
    DEVICE1.PerfectMatch1Low.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PerfectMatch1Low.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch2High. */
    DEVICE1.PerfectMatch2High.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PerfectMatch2High.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch2Low. */
    DEVICE1.PerfectMatch2Low.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PerfectMatch2Low.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch3High. */
    DEVICE1.PerfectMatch3High.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PerfectMatch3High.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch3Low. */
    DEVICE1.PerfectMatch3Low.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PerfectMatch3Low.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch4High. */
    DEVICE1.PerfectMatch4High.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PerfectMatch4High.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PerfectMatch4Low. */
    DEVICE1.PerfectMatch4Low.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PerfectMatch4Low.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.SgmiiStatus. */
    DEVICE1.SgmiiStatus.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.SgmiiStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.ReceiveListPlacementMode. */
    DEVICE1.ReceiveListPlacementMode.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.ReceiveListPlacementMode.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.ReceiveListPlacementStatus. */
    DEVICE1.ReceiveListPlacementStatus.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.ReceiveListPlacementStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.CpmuControl. */
    DEVICE1.CpmuControl.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.CpmuControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.NoLinkPowerModeClockPolicy. */
    DEVICE1.NoLinkPowerModeClockPolicy.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.NoLinkPowerModeClockPolicy.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.LinkAwarePowerModeClockPolicy. */
    DEVICE1.LinkAwarePowerModeClockPolicy.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.LinkAwarePowerModeClockPolicy.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.D0uClockPolicy. */
    DEVICE1.D0uClockPolicy.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.D0uClockPolicy.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.ApeClkPolicy. */
    DEVICE1.ApeClkPolicy.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.ApeClkPolicy.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.ApeSleepStateClockPolicy. */
    DEVICE1.ApeSleepStateClockPolicy.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.ApeSleepStateClockPolicy.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.ClockSpeedOverridePolicy. */
    DEVICE1.ClockSpeedOverridePolicy.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.ClockSpeedOverridePolicy.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.Status. */
    DEVICE1.Status.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.Status.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.ClockStatus. */
    DEVICE1.ClockStatus.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.ClockStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.GphyControlStatus. */
    DEVICE1.GphyControlStatus.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.GphyControlStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.ChipId. */
    DEVICE1.ChipId.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.ChipId.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.MutexRequest. */
    DEVICE1.MutexRequest.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.MutexRequest.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.MutexGrant. */
    DEVICE1.MutexGrant.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.MutexGrant.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.GphyStrap. */
    DEVICE1.GphyStrap.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.GphyStrap.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.FlashClockControlPolicy. */
    DEVICE1.FlashClockControlPolicy.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.FlashClockControlPolicy.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.TopLevelMiscellaneousControl1. */
    DEVICE1.TopLevelMiscellaneousControl1.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.TopLevelMiscellaneousControl1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EeeMode. */
    DEVICE1.EeeMode.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EeeMode.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EeeLinkIdleControl. */
    DEVICE1.EeeLinkIdleControl.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EeeLinkIdleControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EeeControl. */
    DEVICE1.EeeControl.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EeeControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.GlobalMutexRequest. */
    DEVICE1.GlobalMutexRequest.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.GlobalMutexRequest.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.GlobalMutexGrant. */
    DEVICE1.GlobalMutexGrant.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.GlobalMutexGrant.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.TemperatureMonitorControl. */
    DEVICE1.TemperatureMonitorControl.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.TemperatureMonitorControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.MemoryArbiterMode. */
    DEVICE1.MemoryArbiterMode.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.MemoryArbiterMode.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.BufferManagerMode. */
    DEVICE1.BufferManagerMode.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.BufferManagerMode.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.LsoNonlsoBdReadDmaCorruptionEnableControl. */
    DEVICE1.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscMode. */
    DEVICE1.RxRiscMode.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscMode.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscStatus. */
    DEVICE1.RxRiscStatus.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscStatus.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscEventMask. */
    DEVICE1.RxRiscEventMask.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscEventMask.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscProgramCounter. */
    DEVICE1.RxRiscProgramCounter.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscProgramCounter.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscCurrentInstruction. */
    DEVICE1.RxRiscCurrentInstruction.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscCurrentInstruction.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscInterruptEnable. */
    DEVICE1.RxRiscInterruptEnable.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscInterruptEnable.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscInterruptVector. */
    DEVICE1.RxRiscInterruptVector.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscInterruptVector.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscHardwareBreakpoint. */
    DEVICE1.RxRiscHardwareBreakpoint.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscHardwareBreakpoint.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscLastBranchAddress. */
    DEVICE1.RxRiscLastBranchAddress.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscLastBranchAddress.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister0. */
    DEVICE1.RxRiscRegister0.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister1. */
    DEVICE1.RxRiscRegister1.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister2. */
    DEVICE1.RxRiscRegister2.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister2.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister3. */
    DEVICE1.RxRiscRegister3.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister3.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister4. */
    DEVICE1.RxRiscRegister4.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister4.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister5. */
    DEVICE1.RxRiscRegister5.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister5.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister6. */
    DEVICE1.RxRiscRegister6.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister6.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister7. */
    DEVICE1.RxRiscRegister7.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister7.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister8. */
    DEVICE1.RxRiscRegister8.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister8.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister9. */
    DEVICE1.RxRiscRegister9.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister9.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister10. */
    DEVICE1.RxRiscRegister10.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister10.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister11. */
    DEVICE1.RxRiscRegister11.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister11.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister12. */
    DEVICE1.RxRiscRegister12.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister12.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister13. */
    DEVICE1.RxRiscRegister13.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister13.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister14. */
    DEVICE1.RxRiscRegister14.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister14.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister15. */
    DEVICE1.RxRiscRegister15.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister15.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister16. */
    DEVICE1.RxRiscRegister16.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister16.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister17. */
    DEVICE1.RxRiscRegister17.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister17.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister18. */
    DEVICE1.RxRiscRegister18.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister18.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister19. */
    DEVICE1.RxRiscRegister19.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister19.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister20. */
    DEVICE1.RxRiscRegister20.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister20.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister21. */
    DEVICE1.RxRiscRegister21.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister21.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister22. */
    DEVICE1.RxRiscRegister22.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister22.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister23. */
    DEVICE1.RxRiscRegister23.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister23.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister24. */
    DEVICE1.RxRiscRegister24.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister24.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister25. */
    DEVICE1.RxRiscRegister25.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister25.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister26. */
    DEVICE1.RxRiscRegister26.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister26.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister27. */
    DEVICE1.RxRiscRegister27.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister27.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister28. */
    DEVICE1.RxRiscRegister28.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister28.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister29. */
    DEVICE1.RxRiscRegister29.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister29.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister30. */
    DEVICE1.RxRiscRegister30.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister30.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxRiscRegister31. */
    DEVICE1.RxRiscRegister31.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxRiscRegister31.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.6408. */
    DEVICE1._6408.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1._6408.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerConsumptionInfo. */
    DEVICE1.PciPowerConsumptionInfo.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciPowerConsumptionInfo.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerDissipatedInfo. */
    DEVICE1.PciPowerDissipatedInfo.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciPowerDissipatedInfo.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciVpdRequest. */
    DEVICE1.PciVpdRequest.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciVpdRequest.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciVpdResponse. */
    DEVICE1.PciVpdResponse.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciVpdResponse.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciVendorDeviceId. */
    DEVICE1.PciVendorDeviceId.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciVendorDeviceId.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciSubsystemId. */
    DEVICE1.PciSubsystemId.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciSubsystemId.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciClassCodeRevision. */
    DEVICE1.PciClassCodeRevision.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciClassCodeRevision.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.64c0. */
    DEVICE1._64c0.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1._64c0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.64c4. */
    DEVICE1._64c4.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1._64c4.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.64c8. */
    DEVICE1._64c8.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1._64c8.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.64dc. */
    DEVICE1._64dc.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1._64dc.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciSerialNumberLow. */
    DEVICE1.PciSerialNumberLow.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciSerialNumberLow.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciSerialNumberHigh. */
    DEVICE1.PciSerialNumberHigh.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciSerialNumberHigh.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget0. */
    DEVICE1.PciPowerBudget0.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciPowerBudget0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget1. */
    DEVICE1.PciPowerBudget1.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciPowerBudget1.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget2. */
    DEVICE1.PciPowerBudget2.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciPowerBudget2.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget3. */
    DEVICE1.PciPowerBudget3.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciPowerBudget3.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget4. */
    DEVICE1.PciPowerBudget4.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciPowerBudget4.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget5. */
    DEVICE1.PciPowerBudget5.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciPowerBudget5.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget6. */
    DEVICE1.PciPowerBudget6.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciPowerBudget6.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.PciPowerBudget7. */
    DEVICE1.PciPowerBudget7.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.PciPowerBudget7.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.6530. */
    DEVICE1._6530.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1._6530.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.6550. */
    DEVICE1._6550.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1._6550.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.65f4. */
    DEVICE1._65f4.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1._65f4.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.GrcModeControl. */
    DEVICE1.GrcModeControl.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.GrcModeControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.MiscellaneousConfig. */
    DEVICE1.MiscellaneousConfig.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.MiscellaneousConfig.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.MiscellaneousLocalControl. */
    DEVICE1.MiscellaneousLocalControl.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.MiscellaneousLocalControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.Timer. */
    DEVICE1.Timer.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.Timer.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxCpuEvent. */
    DEVICE1.RxCpuEvent.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxCpuEvent.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.6838. */
    DEVICE1._6838.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1._6838.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.MdiControl. */
    DEVICE1.MdiControl.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.MdiControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.RxCpuEventEnable. */
    DEVICE1.RxCpuEventEnable.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.RxCpuEventEnable.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.FastBootProgramCounter. */
    DEVICE1.FastBootProgramCounter.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.FastBootProgramCounter.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.ExpansionRomAddr. */
    DEVICE1.ExpansionRomAddr.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.ExpansionRomAddr.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.68f0. */
    DEVICE1._68f0.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1._68f0.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.EavRefClockControl. */
    DEVICE1.EavRefClockControl.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1.EavRefClockControl.r32.installWriteCallback(write, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE1_t.7c04. */
    DEVICE1._7c04.r32.installReadCallback(read, (uint8_t *)base);
    DEVICE1._7c04.r32.installWriteCallback(write, (uint8_t *)base);


}
