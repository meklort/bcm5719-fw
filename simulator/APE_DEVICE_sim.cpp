////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_DEVICE_sim.cpp
///
/// @project    ape
///
/// @brief      APE_DEVICE_sim
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
#include <APE_DEVICE.h>

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

void init_APE_DEVICE_sim(void *arg0)
{
    (void)arg0; // unused
    void* base = (void*)0xa0040000;

    DEVICE.mIndexReadCallback = loader_read_mem;
    DEVICE.mIndexReadCallbackArgs = base;

    DEVICE.mIndexWriteCallback = loader_write_mem;
    DEVICE.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref DEVICE. */
    /** @brief Bitmap for @ref DEVICE_t.MiscellaneousHostControl. */
    DEVICE.MiscellaneousHostControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.MiscellaneousHostControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciState. */
    DEVICE.PciState.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciState.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RegisterBase. */
    DEVICE.RegisterBase.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RegisterBase.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MemoryBase. */
    DEVICE.MemoryBase.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.MemoryBase.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RegisterData. */
    DEVICE.RegisterData.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RegisterData.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndex. */
    DEVICE.UndiReceiveReturnRingConsumerIndex.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.UndiReceiveReturnRingConsumerIndex.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndexLow. */
    DEVICE.UndiReceiveReturnRingConsumerIndexLow.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.UndiReceiveReturnRingConsumerIndexLow.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.LinkStatusControl. */
    DEVICE.LinkStatusControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.LinkStatusControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ApeMemoryBase. */
    DEVICE.ApeMemoryBase.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.ApeMemoryBase.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ApeMemoryData. */
    DEVICE.ApeMemoryData.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.ApeMemoryData.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.160. */
    DEVICE._160.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE._160.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMode. */
    DEVICE.EmacMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EmacMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacStatus. */
    DEVICE.EmacStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EmacStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacEvent. */
    DEVICE.EmacEvent.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EmacEvent.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.LedControl. */
    DEVICE.LedControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.LedControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses0High. */
    DEVICE.EmacMacAddresses0High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EmacMacAddresses0High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses0Low. */
    DEVICE.EmacMacAddresses0Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EmacMacAddresses0Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses1High. */
    DEVICE.EmacMacAddresses1High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EmacMacAddresses1High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses1Low. */
    DEVICE.EmacMacAddresses1Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EmacMacAddresses1Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses2High. */
    DEVICE.EmacMacAddresses2High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EmacMacAddresses2High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses2Low. */
    DEVICE.EmacMacAddresses2Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EmacMacAddresses2Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses3High. */
    DEVICE.EmacMacAddresses3High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EmacMacAddresses3High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses3Low. */
    DEVICE.EmacMacAddresses3Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EmacMacAddresses3Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.WolPatternPointer. */
    DEVICE.WolPatternPointer.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.WolPatternPointer.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.WolPatternCfg. */
    DEVICE.WolPatternCfg.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.WolPatternCfg.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.438. */
    DEVICE._438.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE._438.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MtuSize. */
    DEVICE.MtuSize.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.MtuSize.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MiiCommunication. */
    DEVICE.MiiCommunication.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.MiiCommunication.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MiiMode. */
    DEVICE.MiiMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.MiiMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.TransmitMacMode. */
    DEVICE.TransmitMacMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.TransmitMacMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.TransmitMacStatus. */
    DEVICE.TransmitMacStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.TransmitMacStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.TransmitMacLengths. */
    DEVICE.TransmitMacLengths.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.TransmitMacLengths.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ReceiveMacMode. */
    DEVICE.ReceiveMacMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.ReceiveMacMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ReceiveMacStatus. */
    DEVICE.ReceiveMacStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.ReceiveMacStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch1High. */
    DEVICE.PerfectMatch1High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PerfectMatch1High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch1Low. */
    DEVICE.PerfectMatch1Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PerfectMatch1Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch2High. */
    DEVICE.PerfectMatch2High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PerfectMatch2High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch2Low. */
    DEVICE.PerfectMatch2Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PerfectMatch2Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch3High. */
    DEVICE.PerfectMatch3High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PerfectMatch3High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch3Low. */
    DEVICE.PerfectMatch3Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PerfectMatch3Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch4High. */
    DEVICE.PerfectMatch4High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PerfectMatch4High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PerfectMatch4Low. */
    DEVICE.PerfectMatch4Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PerfectMatch4Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.SgmiiStatus. */
    DEVICE.SgmiiStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.SgmiiStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ReceiveListPlacementMode. */
    DEVICE.ReceiveListPlacementMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.ReceiveListPlacementMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ReceiveListPlacementStatus. */
    DEVICE.ReceiveListPlacementStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.ReceiveListPlacementStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.CpmuControl. */
    DEVICE.CpmuControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.CpmuControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.NoLinkPowerModeClockPolicy. */
    DEVICE.NoLinkPowerModeClockPolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.NoLinkPowerModeClockPolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.LinkAwarePowerModeClockPolicy. */
    DEVICE.LinkAwarePowerModeClockPolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.LinkAwarePowerModeClockPolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ApeSleepStateClockPolicy. */
    DEVICE.ApeSleepStateClockPolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.ApeSleepStateClockPolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ClockSpeedOverridePolicy. */
    DEVICE.ClockSpeedOverridePolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.ClockSpeedOverridePolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.Status. */
    DEVICE.Status.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.Status.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ClockStatus. */
    DEVICE.ClockStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.ClockStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.GphyControlStatus. */
    DEVICE.GphyControlStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.GphyControlStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ChipId. */
    DEVICE.ChipId.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.ChipId.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MutexRequest. */
    DEVICE.MutexRequest.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.MutexRequest.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MutexGrant. */
    DEVICE.MutexGrant.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.MutexGrant.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.GphyStrap. */
    DEVICE.GphyStrap.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.GphyStrap.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.FlashClockControlPolicy. */
    DEVICE.FlashClockControlPolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.FlashClockControlPolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.TopLevelMiscellaneousControl1. */
    DEVICE.TopLevelMiscellaneousControl1.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.TopLevelMiscellaneousControl1.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EeeMode. */
    DEVICE.EeeMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EeeMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EeeLinkIdleControl. */
    DEVICE.EeeLinkIdleControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EeeLinkIdleControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EeeControl. */
    DEVICE.EeeControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EeeControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.GlobalMutexRequest. */
    DEVICE.GlobalMutexRequest.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.GlobalMutexRequest.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.GlobalMutexGrant. */
    DEVICE.GlobalMutexGrant.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.GlobalMutexGrant.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.TemperatureMonitorControl. */
    DEVICE.TemperatureMonitorControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.TemperatureMonitorControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MemoryArbiterMode. */
    DEVICE.MemoryArbiterMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.MemoryArbiterMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.BufferManagerMode. */
    DEVICE.BufferManagerMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.BufferManagerMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.LsoNonlsoBdReadDmaCorruptionEnableControl. */
    DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscMode. */
    DEVICE.RxRiscMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscStatus. */
    DEVICE.RxRiscStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscProgramCounter. */
    DEVICE.RxRiscProgramCounter.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscProgramCounter.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscCurrentInstruction. */
    DEVICE.RxRiscCurrentInstruction.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscCurrentInstruction.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscHardwareBreakpoint. */
    DEVICE.RxRiscHardwareBreakpoint.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscHardwareBreakpoint.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister0. */
    DEVICE.RxRiscRegister0.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister0.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister1. */
    DEVICE.RxRiscRegister1.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister1.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister2. */
    DEVICE.RxRiscRegister2.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister2.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister3. */
    DEVICE.RxRiscRegister3.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister3.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister4. */
    DEVICE.RxRiscRegister4.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister4.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister5. */
    DEVICE.RxRiscRegister5.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister5.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister6. */
    DEVICE.RxRiscRegister6.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister6.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister7. */
    DEVICE.RxRiscRegister7.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister7.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister8. */
    DEVICE.RxRiscRegister8.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister8.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister9. */
    DEVICE.RxRiscRegister9.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister9.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister10. */
    DEVICE.RxRiscRegister10.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister10.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister11. */
    DEVICE.RxRiscRegister11.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister11.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister12. */
    DEVICE.RxRiscRegister12.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister12.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister13. */
    DEVICE.RxRiscRegister13.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister13.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister14. */
    DEVICE.RxRiscRegister14.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister14.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister15. */
    DEVICE.RxRiscRegister15.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister15.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister16. */
    DEVICE.RxRiscRegister16.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister16.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister17. */
    DEVICE.RxRiscRegister17.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister17.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister18. */
    DEVICE.RxRiscRegister18.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister18.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister19. */
    DEVICE.RxRiscRegister19.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister19.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister20. */
    DEVICE.RxRiscRegister20.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister20.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister21. */
    DEVICE.RxRiscRegister21.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister21.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister22. */
    DEVICE.RxRiscRegister22.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister22.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister23. */
    DEVICE.RxRiscRegister23.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister23.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister24. */
    DEVICE.RxRiscRegister24.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister24.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister25. */
    DEVICE.RxRiscRegister25.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister25.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister26. */
    DEVICE.RxRiscRegister26.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister26.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister27. */
    DEVICE.RxRiscRegister27.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister27.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister28. */
    DEVICE.RxRiscRegister28.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister28.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister29. */
    DEVICE.RxRiscRegister29.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister29.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister30. */
    DEVICE.RxRiscRegister30.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister30.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister31. */
    DEVICE.RxRiscRegister31.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxRiscRegister31.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.6408. */
    DEVICE._6408.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE._6408.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerConsumptionInfo. */
    DEVICE.PciPowerConsumptionInfo.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciPowerConsumptionInfo.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerDissipatedInfo. */
    DEVICE.PciPowerDissipatedInfo.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciPowerDissipatedInfo.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciVpdRequest. */
    DEVICE.PciVpdRequest.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciVpdRequest.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciVpdResponse. */
    DEVICE.PciVpdResponse.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciVpdResponse.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciVendorDeviceId. */
    DEVICE.PciVendorDeviceId.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciVendorDeviceId.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciSubsystemId. */
    DEVICE.PciSubsystemId.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciSubsystemId.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciClassCodeRevision. */
    DEVICE.PciClassCodeRevision.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciClassCodeRevision.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.64c0. */
    DEVICE._64c0.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE._64c0.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.64c4. */
    DEVICE._64c4.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE._64c4.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.64c8. */
    DEVICE._64c8.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE._64c8.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.64dc. */
    DEVICE._64dc.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE._64dc.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciSerialNumberLow. */
    DEVICE.PciSerialNumberLow.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciSerialNumberLow.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciSerialNumberHigh. */
    DEVICE.PciSerialNumberHigh.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciSerialNumberHigh.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget0. */
    DEVICE.PciPowerBudget0.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciPowerBudget0.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget1. */
    DEVICE.PciPowerBudget1.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciPowerBudget1.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget2. */
    DEVICE.PciPowerBudget2.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciPowerBudget2.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget3. */
    DEVICE.PciPowerBudget3.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciPowerBudget3.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget4. */
    DEVICE.PciPowerBudget4.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciPowerBudget4.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget5. */
    DEVICE.PciPowerBudget5.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciPowerBudget5.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget6. */
    DEVICE.PciPowerBudget6.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciPowerBudget6.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget7. */
    DEVICE.PciPowerBudget7.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.PciPowerBudget7.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.6530. */
    DEVICE._6530.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE._6530.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.6550. */
    DEVICE._6550.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE._6550.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.65f4. */
    DEVICE._65f4.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE._65f4.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.GrcModeControl. */
    DEVICE.GrcModeControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.GrcModeControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MiscellaneousConfig. */
    DEVICE.MiscellaneousConfig.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.MiscellaneousConfig.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MiscellaneousLocalControl. */
    DEVICE.MiscellaneousLocalControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.MiscellaneousLocalControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.Timer. */
    DEVICE.Timer.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.Timer.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxCpuEvent. */
    DEVICE.RxCpuEvent.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxCpuEvent.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.6838. */
    DEVICE._6838.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE._6838.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.MdiControl. */
    DEVICE.MdiControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.MdiControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.RxCpuEventEnable. */
    DEVICE.RxCpuEventEnable.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.RxCpuEventEnable.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.FastBootProgramCounter. */
    DEVICE.FastBootProgramCounter.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.FastBootProgramCounter.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.ExpansionRomAddr. */
    DEVICE.ExpansionRomAddr.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.ExpansionRomAddr.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.68f0. */
    DEVICE._68f0.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE._68f0.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.EavRefClockControl. */
    DEVICE.EavRefClockControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE.EavRefClockControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE_t.7c04. */
    DEVICE._7c04.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE._7c04.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);


}
