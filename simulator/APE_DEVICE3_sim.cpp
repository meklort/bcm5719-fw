////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_DEVICE3_sim.cpp
///
/// @project    ape
///
/// @brief      APE_DEVICE3_sim
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2021, Evan Lojewski
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
#include <APE_DEVICE3.h>

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

void init_APE_DEVICE3_sim(void *arg0)
{
    (void)arg0; // unused
    void* base = (void*)0xa0070000;

    DEVICE3.mIndexReadCallback = loader_read_mem;
    DEVICE3.mIndexReadCallbackArgs = base;

    DEVICE3.mIndexWriteCallback = loader_write_mem;
    DEVICE3.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref DEVICE3. */
    /** @brief Bitmap for @ref DEVICE3_t.MiscellaneousHostControl. */
    DEVICE3.MiscellaneousHostControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.MiscellaneousHostControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciState. */
    DEVICE3.PciState.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciState.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RegisterBase. */
    DEVICE3.RegisterBase.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RegisterBase.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.MemoryBase. */
    DEVICE3.MemoryBase.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.MemoryBase.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RegisterData. */
    DEVICE3.RegisterData.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RegisterData.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.UndiReceiveReturnRingConsumerIndex. */
    DEVICE3.UndiReceiveReturnRingConsumerIndex.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.UndiReceiveReturnRingConsumerIndex.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.UndiReceiveReturnRingConsumerIndexLow. */
    DEVICE3.UndiReceiveReturnRingConsumerIndexLow.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.UndiReceiveReturnRingConsumerIndexLow.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.LinkStatusControl. */
    DEVICE3.LinkStatusControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.LinkStatusControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.ApeMemoryBase. */
    DEVICE3.ApeMemoryBase.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.ApeMemoryBase.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.ApeMemoryData. */
    DEVICE3.ApeMemoryData.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.ApeMemoryData.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.160. */
    DEVICE3._160.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3._160.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EmacMode. */
    DEVICE3.EmacMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EmacMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EmacStatus. */
    DEVICE3.EmacStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EmacStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EmacEvent. */
    DEVICE3.EmacEvent.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EmacEvent.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.LedControl. */
    DEVICE3.LedControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.LedControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EmacMacAddresses0High. */
    DEVICE3.EmacMacAddresses0High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EmacMacAddresses0High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EmacMacAddresses0Low. */
    DEVICE3.EmacMacAddresses0Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EmacMacAddresses0Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EmacMacAddresses1High. */
    DEVICE3.EmacMacAddresses1High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EmacMacAddresses1High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EmacMacAddresses1Low. */
    DEVICE3.EmacMacAddresses1Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EmacMacAddresses1Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EmacMacAddresses2High. */
    DEVICE3.EmacMacAddresses2High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EmacMacAddresses2High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EmacMacAddresses2Low. */
    DEVICE3.EmacMacAddresses2Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EmacMacAddresses2Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EmacMacAddresses3High. */
    DEVICE3.EmacMacAddresses3High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EmacMacAddresses3High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EmacMacAddresses3Low. */
    DEVICE3.EmacMacAddresses3Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EmacMacAddresses3Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.WolPatternPointer. */
    DEVICE3.WolPatternPointer.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.WolPatternPointer.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.WolPatternCfg. */
    DEVICE3.WolPatternCfg.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.WolPatternCfg.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.438. */
    DEVICE3._438.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3._438.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.MtuSize. */
    DEVICE3.MtuSize.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.MtuSize.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.MiiCommunication. */
    DEVICE3.MiiCommunication.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.MiiCommunication.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.MiiMode. */
    DEVICE3.MiiMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.MiiMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.TransmitMacMode. */
    DEVICE3.TransmitMacMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.TransmitMacMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.TransmitMacStatus. */
    DEVICE3.TransmitMacStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.TransmitMacStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.TransmitMacLengths. */
    DEVICE3.TransmitMacLengths.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.TransmitMacLengths.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.ReceiveMacMode. */
    DEVICE3.ReceiveMacMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.ReceiveMacMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.ReceiveMacStatus. */
    DEVICE3.ReceiveMacStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.ReceiveMacStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PerfectMatch1High. */
    DEVICE3.PerfectMatch1High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PerfectMatch1High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PerfectMatch1Low. */
    DEVICE3.PerfectMatch1Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PerfectMatch1Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PerfectMatch2High. */
    DEVICE3.PerfectMatch2High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PerfectMatch2High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PerfectMatch2Low. */
    DEVICE3.PerfectMatch2Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PerfectMatch2Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PerfectMatch3High. */
    DEVICE3.PerfectMatch3High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PerfectMatch3High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PerfectMatch3Low. */
    DEVICE3.PerfectMatch3Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PerfectMatch3Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PerfectMatch4High. */
    DEVICE3.PerfectMatch4High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PerfectMatch4High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PerfectMatch4Low. */
    DEVICE3.PerfectMatch4Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PerfectMatch4Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.SgmiiStatus. */
    DEVICE3.SgmiiStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.SgmiiStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.ReceiveListPlacementMode. */
    DEVICE3.ReceiveListPlacementMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.ReceiveListPlacementMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.ReceiveListPlacementStatus. */
    DEVICE3.ReceiveListPlacementStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.ReceiveListPlacementStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.CpmuControl. */
    DEVICE3.CpmuControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.CpmuControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.NoLinkPowerModeClockPolicy. */
    DEVICE3.NoLinkPowerModeClockPolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.NoLinkPowerModeClockPolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.LinkAwarePowerModeClockPolicy. */
    DEVICE3.LinkAwarePowerModeClockPolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.LinkAwarePowerModeClockPolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.D0uClockPolicy. */
    DEVICE3.D0uClockPolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.D0uClockPolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.ApeClkPolicy. */
    DEVICE3.ApeClkPolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.ApeClkPolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.ApeSleepStateClockPolicy. */
    DEVICE3.ApeSleepStateClockPolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.ApeSleepStateClockPolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.ClockSpeedOverridePolicy. */
    DEVICE3.ClockSpeedOverridePolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.ClockSpeedOverridePolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.Status. */
    DEVICE3.Status.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.Status.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.ClockStatus. */
    DEVICE3.ClockStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.ClockStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.GphyControlStatus. */
    DEVICE3.GphyControlStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.GphyControlStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.ChipId. */
    DEVICE3.ChipId.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.ChipId.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.MutexRequest. */
    DEVICE3.MutexRequest.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.MutexRequest.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.MutexGrant. */
    DEVICE3.MutexGrant.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.MutexGrant.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.GphyStrap. */
    DEVICE3.GphyStrap.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.GphyStrap.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.FlashClockControlPolicy. */
    DEVICE3.FlashClockControlPolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.FlashClockControlPolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.TopLevelMiscellaneousControl1. */
    DEVICE3.TopLevelMiscellaneousControl1.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.TopLevelMiscellaneousControl1.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EeeMode. */
    DEVICE3.EeeMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EeeMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EeeLinkIdleControl. */
    DEVICE3.EeeLinkIdleControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EeeLinkIdleControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EeeControl. */
    DEVICE3.EeeControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EeeControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.GlobalMutexRequest. */
    DEVICE3.GlobalMutexRequest.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.GlobalMutexRequest.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.GlobalMutexGrant. */
    DEVICE3.GlobalMutexGrant.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.GlobalMutexGrant.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.TemperatureMonitorControl. */
    DEVICE3.TemperatureMonitorControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.TemperatureMonitorControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.MemoryArbiterMode. */
    DEVICE3.MemoryArbiterMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.MemoryArbiterMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.BufferManagerMode. */
    DEVICE3.BufferManagerMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.BufferManagerMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.LsoNonlsoBdReadDmaCorruptionEnableControl. */
    DEVICE3.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscMode. */
    DEVICE3.RxRiscMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscStatus. */
    DEVICE3.RxRiscStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscEventMask. */
    DEVICE3.RxRiscEventMask.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscEventMask.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscProgramCounter. */
    DEVICE3.RxRiscProgramCounter.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscProgramCounter.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscCurrentInstruction. */
    DEVICE3.RxRiscCurrentInstruction.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscCurrentInstruction.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscInterruptEnable. */
    DEVICE3.RxRiscInterruptEnable.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscInterruptEnable.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscInterruptVector. */
    DEVICE3.RxRiscInterruptVector.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscInterruptVector.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscHardwareBreakpoint. */
    DEVICE3.RxRiscHardwareBreakpoint.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscHardwareBreakpoint.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscLastBranchAddress. */
    DEVICE3.RxRiscLastBranchAddress.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscLastBranchAddress.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister0. */
    DEVICE3.RxRiscRegister0.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister0.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister1. */
    DEVICE3.RxRiscRegister1.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister1.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister2. */
    DEVICE3.RxRiscRegister2.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister2.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister3. */
    DEVICE3.RxRiscRegister3.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister3.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister4. */
    DEVICE3.RxRiscRegister4.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister4.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister5. */
    DEVICE3.RxRiscRegister5.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister5.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister6. */
    DEVICE3.RxRiscRegister6.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister6.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister7. */
    DEVICE3.RxRiscRegister7.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister7.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister8. */
    DEVICE3.RxRiscRegister8.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister8.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister9. */
    DEVICE3.RxRiscRegister9.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister9.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister10. */
    DEVICE3.RxRiscRegister10.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister10.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister11. */
    DEVICE3.RxRiscRegister11.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister11.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister12. */
    DEVICE3.RxRiscRegister12.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister12.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister13. */
    DEVICE3.RxRiscRegister13.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister13.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister14. */
    DEVICE3.RxRiscRegister14.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister14.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister15. */
    DEVICE3.RxRiscRegister15.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister15.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister16. */
    DEVICE3.RxRiscRegister16.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister16.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister17. */
    DEVICE3.RxRiscRegister17.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister17.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister18. */
    DEVICE3.RxRiscRegister18.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister18.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister19. */
    DEVICE3.RxRiscRegister19.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister19.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister20. */
    DEVICE3.RxRiscRegister20.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister20.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister21. */
    DEVICE3.RxRiscRegister21.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister21.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister22. */
    DEVICE3.RxRiscRegister22.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister22.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister23. */
    DEVICE3.RxRiscRegister23.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister23.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister24. */
    DEVICE3.RxRiscRegister24.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister24.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister25. */
    DEVICE3.RxRiscRegister25.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister25.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister26. */
    DEVICE3.RxRiscRegister26.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister26.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister27. */
    DEVICE3.RxRiscRegister27.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister27.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister28. */
    DEVICE3.RxRiscRegister28.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister28.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister29. */
    DEVICE3.RxRiscRegister29.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister29.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister30. */
    DEVICE3.RxRiscRegister30.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister30.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxRiscRegister31. */
    DEVICE3.RxRiscRegister31.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxRiscRegister31.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.6408. */
    DEVICE3._6408.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3._6408.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciPowerConsumptionInfo. */
    DEVICE3.PciPowerConsumptionInfo.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciPowerConsumptionInfo.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciPowerDissipatedInfo. */
    DEVICE3.PciPowerDissipatedInfo.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciPowerDissipatedInfo.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciVpdRequest. */
    DEVICE3.PciVpdRequest.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciVpdRequest.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciVpdResponse. */
    DEVICE3.PciVpdResponse.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciVpdResponse.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciVendorDeviceId. */
    DEVICE3.PciVendorDeviceId.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciVendorDeviceId.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciSubsystemId. */
    DEVICE3.PciSubsystemId.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciSubsystemId.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciClassCodeRevision. */
    DEVICE3.PciClassCodeRevision.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciClassCodeRevision.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.64c0. */
    DEVICE3._64c0.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3._64c0.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.64c4. */
    DEVICE3._64c4.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3._64c4.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.64c8. */
    DEVICE3._64c8.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3._64c8.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.64dc. */
    DEVICE3._64dc.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3._64dc.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciSerialNumberLow. */
    DEVICE3.PciSerialNumberLow.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciSerialNumberLow.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciSerialNumberHigh. */
    DEVICE3.PciSerialNumberHigh.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciSerialNumberHigh.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciPowerBudget0. */
    DEVICE3.PciPowerBudget0.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciPowerBudget0.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciPowerBudget1. */
    DEVICE3.PciPowerBudget1.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciPowerBudget1.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciPowerBudget2. */
    DEVICE3.PciPowerBudget2.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciPowerBudget2.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciPowerBudget3. */
    DEVICE3.PciPowerBudget3.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciPowerBudget3.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciPowerBudget4. */
    DEVICE3.PciPowerBudget4.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciPowerBudget4.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciPowerBudget5. */
    DEVICE3.PciPowerBudget5.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciPowerBudget5.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciPowerBudget6. */
    DEVICE3.PciPowerBudget6.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciPowerBudget6.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.PciPowerBudget7. */
    DEVICE3.PciPowerBudget7.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.PciPowerBudget7.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.6530. */
    DEVICE3._6530.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3._6530.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.6550. */
    DEVICE3._6550.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3._6550.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.65f4. */
    DEVICE3._65f4.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3._65f4.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.GrcModeControl. */
    DEVICE3.GrcModeControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.GrcModeControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.MiscellaneousConfig. */
    DEVICE3.MiscellaneousConfig.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.MiscellaneousConfig.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.MiscellaneousLocalControl. */
    DEVICE3.MiscellaneousLocalControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.MiscellaneousLocalControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.Timer. */
    DEVICE3.Timer.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.Timer.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxCpuEvent. */
    DEVICE3.RxCpuEvent.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxCpuEvent.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.6838. */
    DEVICE3._6838.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3._6838.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.MdiControl. */
    DEVICE3.MdiControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.MdiControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.RxCpuEventEnable. */
    DEVICE3.RxCpuEventEnable.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.RxCpuEventEnable.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.FastBootProgramCounter. */
    DEVICE3.FastBootProgramCounter.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.FastBootProgramCounter.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.ExpansionRomAddr. */
    DEVICE3.ExpansionRomAddr.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.ExpansionRomAddr.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.68f0. */
    DEVICE3._68f0.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3._68f0.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.EavRefClockControl. */
    DEVICE3.EavRefClockControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3.EavRefClockControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE3_t.7c04. */
    DEVICE3._7c04.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE3._7c04.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);


}
