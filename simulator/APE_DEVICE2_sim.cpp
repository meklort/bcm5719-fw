////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_DEVICE2_sim.cpp
///
/// @project    ape
///
/// @brief      APE_DEVICE2_sim
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
#include <APE_DEVICE2.h>

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

void init_APE_DEVICE2_sim(void *arg0)
{
    (void)arg0; // unused
    void* base = (void*)0xa0060000;

    DEVICE2.mIndexReadCallback = loader_read_mem;
    DEVICE2.mIndexReadCallbackArgs = base;

    DEVICE2.mIndexWriteCallback = loader_write_mem;
    DEVICE2.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref DEVICE2. */
    /** @brief Bitmap for @ref DEVICE2_t.MiscellaneousHostControl. */
    DEVICE2.MiscellaneousHostControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.MiscellaneousHostControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciState. */
    DEVICE2.PciState.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciState.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RegisterBase. */
    DEVICE2.RegisterBase.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RegisterBase.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.MemoryBase. */
    DEVICE2.MemoryBase.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.MemoryBase.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RegisterData. */
    DEVICE2.RegisterData.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RegisterData.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.UndiReceiveReturnRingConsumerIndex. */
    DEVICE2.UndiReceiveReturnRingConsumerIndex.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.UndiReceiveReturnRingConsumerIndex.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.UndiReceiveReturnRingConsumerIndexLow. */
    DEVICE2.UndiReceiveReturnRingConsumerIndexLow.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.UndiReceiveReturnRingConsumerIndexLow.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.LinkStatusControl. */
    DEVICE2.LinkStatusControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.LinkStatusControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.ApeMemoryBase. */
    DEVICE2.ApeMemoryBase.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.ApeMemoryBase.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.ApeMemoryData. */
    DEVICE2.ApeMemoryData.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.ApeMemoryData.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.EmacMode. */
    DEVICE2.EmacMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.EmacMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.LedControl. */
    DEVICE2.LedControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.LedControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.EmacMacAddresses0High. */
    DEVICE2.EmacMacAddresses0High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.EmacMacAddresses0High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.EmacMacAddresses0Low. */
    DEVICE2.EmacMacAddresses0Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.EmacMacAddresses0Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.EmacMacAddresses1High. */
    DEVICE2.EmacMacAddresses1High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.EmacMacAddresses1High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.EmacMacAddresses1Low. */
    DEVICE2.EmacMacAddresses1Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.EmacMacAddresses1Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.EmacMacAddresses2High. */
    DEVICE2.EmacMacAddresses2High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.EmacMacAddresses2High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.EmacMacAddresses2Low. */
    DEVICE2.EmacMacAddresses2Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.EmacMacAddresses2Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.EmacMacAddresses3High. */
    DEVICE2.EmacMacAddresses3High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.EmacMacAddresses3High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.EmacMacAddresses3Low. */
    DEVICE2.EmacMacAddresses3Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.EmacMacAddresses3Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.WolPatternPointer. */
    DEVICE2.WolPatternPointer.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.WolPatternPointer.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.WolPatternCfg. */
    DEVICE2.WolPatternCfg.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.WolPatternCfg.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.MtuSize. */
    DEVICE2.MtuSize.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.MtuSize.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.MiiCommunication. */
    DEVICE2.MiiCommunication.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.MiiCommunication.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.MiiMode. */
    DEVICE2.MiiMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.MiiMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.TransmitMacMode. */
    DEVICE2.TransmitMacMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.TransmitMacMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.ReceiveMacMode. */
    DEVICE2.ReceiveMacMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.ReceiveMacMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PerfectMatch1High. */
    DEVICE2.PerfectMatch1High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PerfectMatch1High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PerfectMatch1Low. */
    DEVICE2.PerfectMatch1Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PerfectMatch1Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PerfectMatch2High. */
    DEVICE2.PerfectMatch2High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PerfectMatch2High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PerfectMatch2Low. */
    DEVICE2.PerfectMatch2Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PerfectMatch2Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PerfectMatch3High. */
    DEVICE2.PerfectMatch3High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PerfectMatch3High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PerfectMatch3Low. */
    DEVICE2.PerfectMatch3Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PerfectMatch3Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PerfectMatch4High. */
    DEVICE2.PerfectMatch4High.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PerfectMatch4High.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PerfectMatch4Low. */
    DEVICE2.PerfectMatch4Low.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PerfectMatch4Low.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.SgmiiStatus. */
    DEVICE2.SgmiiStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.SgmiiStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.CpmuControl. */
    DEVICE2.CpmuControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.CpmuControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.LinkAwarePowerModeClockPolicy. */
    DEVICE2.LinkAwarePowerModeClockPolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.LinkAwarePowerModeClockPolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.ClockSpeedOverridePolicy. */
    DEVICE2.ClockSpeedOverridePolicy.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.ClockSpeedOverridePolicy.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.Status. */
    DEVICE2.Status.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.Status.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.ClockStatus. */
    DEVICE2.ClockStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.ClockStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.GphyControlStatus. */
    DEVICE2.GphyControlStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.GphyControlStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.ChipId. */
    DEVICE2.ChipId.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.ChipId.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.MutexRequest. */
    DEVICE2.MutexRequest.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.MutexRequest.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.MutexGrant. */
    DEVICE2.MutexGrant.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.MutexGrant.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.GphyStrap. */
    DEVICE2.GphyStrap.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.GphyStrap.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.TopLevelMiscellaneousControl1. */
    DEVICE2.TopLevelMiscellaneousControl1.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.TopLevelMiscellaneousControl1.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.EeeMode. */
    DEVICE2.EeeMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.EeeMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.EeeLinkIdleControl. */
    DEVICE2.EeeLinkIdleControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.EeeLinkIdleControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.EeeControl. */
    DEVICE2.EeeControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.EeeControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.GlobalMutexRequest. */
    DEVICE2.GlobalMutexRequest.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.GlobalMutexRequest.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.GlobalMutexGrant. */
    DEVICE2.GlobalMutexGrant.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.GlobalMutexGrant.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.MemoryArbiterMode. */
    DEVICE2.MemoryArbiterMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.MemoryArbiterMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.BufferManagerMode. */
    DEVICE2.BufferManagerMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.BufferManagerMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.LsoNonlsoBdReadDmaCorruptionEnableControl. */
    DEVICE2.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscMode. */
    DEVICE2.RxRiscMode.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscMode.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscStatus. */
    DEVICE2.RxRiscStatus.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscStatus.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscProgramCounter. */
    DEVICE2.RxRiscProgramCounter.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscProgramCounter.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscCurrentInstruction. */
    DEVICE2.RxRiscCurrentInstruction.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscCurrentInstruction.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscHardwareBreakpoint. */
    DEVICE2.RxRiscHardwareBreakpoint.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscHardwareBreakpoint.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister0. */
    DEVICE2.RxRiscRegister0.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister0.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister1. */
    DEVICE2.RxRiscRegister1.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister1.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister2. */
    DEVICE2.RxRiscRegister2.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister2.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister3. */
    DEVICE2.RxRiscRegister3.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister3.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister4. */
    DEVICE2.RxRiscRegister4.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister4.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister5. */
    DEVICE2.RxRiscRegister5.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister5.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister6. */
    DEVICE2.RxRiscRegister6.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister6.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister7. */
    DEVICE2.RxRiscRegister7.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister7.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister8. */
    DEVICE2.RxRiscRegister8.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister8.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister9. */
    DEVICE2.RxRiscRegister9.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister9.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister10. */
    DEVICE2.RxRiscRegister10.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister10.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister11. */
    DEVICE2.RxRiscRegister11.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister11.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister12. */
    DEVICE2.RxRiscRegister12.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister12.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister13. */
    DEVICE2.RxRiscRegister13.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister13.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister14. */
    DEVICE2.RxRiscRegister14.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister14.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister15. */
    DEVICE2.RxRiscRegister15.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister15.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister16. */
    DEVICE2.RxRiscRegister16.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister16.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister17. */
    DEVICE2.RxRiscRegister17.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister17.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister18. */
    DEVICE2.RxRiscRegister18.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister18.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister19. */
    DEVICE2.RxRiscRegister19.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister19.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister20. */
    DEVICE2.RxRiscRegister20.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister20.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister21. */
    DEVICE2.RxRiscRegister21.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister21.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister22. */
    DEVICE2.RxRiscRegister22.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister22.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister23. */
    DEVICE2.RxRiscRegister23.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister23.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister24. */
    DEVICE2.RxRiscRegister24.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister24.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister25. */
    DEVICE2.RxRiscRegister25.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister25.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister26. */
    DEVICE2.RxRiscRegister26.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister26.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister27. */
    DEVICE2.RxRiscRegister27.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister27.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister28. */
    DEVICE2.RxRiscRegister28.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister28.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister29. */
    DEVICE2.RxRiscRegister29.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister29.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister30. */
    DEVICE2.RxRiscRegister30.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister30.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxRiscRegister31. */
    DEVICE2.RxRiscRegister31.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxRiscRegister31.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.6408. */
    DEVICE2._6408.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2._6408.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciPowerConsumptionInfo. */
    DEVICE2.PciPowerConsumptionInfo.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciPowerConsumptionInfo.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciPowerDissipatedInfo. */
    DEVICE2.PciPowerDissipatedInfo.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciPowerDissipatedInfo.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciVpdRequest. */
    DEVICE2.PciVpdRequest.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciVpdRequest.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciVpdResponse. */
    DEVICE2.PciVpdResponse.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciVpdResponse.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciVendorDeviceId. */
    DEVICE2.PciVendorDeviceId.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciVendorDeviceId.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciSubsystemId. */
    DEVICE2.PciSubsystemId.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciSubsystemId.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciClassCodeRevision. */
    DEVICE2.PciClassCodeRevision.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciClassCodeRevision.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.64c0. */
    DEVICE2._64c0.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2._64c0.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.64c8. */
    DEVICE2._64c8.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2._64c8.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.64dc. */
    DEVICE2._64dc.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2._64dc.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciSerialNumberLow. */
    DEVICE2.PciSerialNumberLow.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciSerialNumberLow.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciSerialNumberHigh. */
    DEVICE2.PciSerialNumberHigh.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciSerialNumberHigh.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciPowerBudget0. */
    DEVICE2.PciPowerBudget0.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciPowerBudget0.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciPowerBudget1. */
    DEVICE2.PciPowerBudget1.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciPowerBudget1.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciPowerBudget2. */
    DEVICE2.PciPowerBudget2.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciPowerBudget2.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciPowerBudget3. */
    DEVICE2.PciPowerBudget3.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciPowerBudget3.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciPowerBudget4. */
    DEVICE2.PciPowerBudget4.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciPowerBudget4.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciPowerBudget5. */
    DEVICE2.PciPowerBudget5.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciPowerBudget5.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciPowerBudget6. */
    DEVICE2.PciPowerBudget6.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciPowerBudget6.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.PciPowerBudget7. */
    DEVICE2.PciPowerBudget7.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.PciPowerBudget7.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.6530. */
    DEVICE2._6530.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2._6530.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.6550. */
    DEVICE2._6550.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2._6550.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.65f4. */
    DEVICE2._65f4.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2._65f4.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.GrcModeControl. */
    DEVICE2.GrcModeControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.GrcModeControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.MiscellaneousConfig. */
    DEVICE2.MiscellaneousConfig.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.MiscellaneousConfig.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.MiscellaneousLocalControl. */
    DEVICE2.MiscellaneousLocalControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.MiscellaneousLocalControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.Timer. */
    DEVICE2.Timer.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.Timer.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxCpuEvent. */
    DEVICE2.RxCpuEvent.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxCpuEvent.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.6838. */
    DEVICE2._6838.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2._6838.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.MdiControl. */
    DEVICE2.MdiControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.MdiControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.RxCpuEventEnable. */
    DEVICE2.RxCpuEventEnable.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.RxCpuEventEnable.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.FastBootProgramCounter. */
    DEVICE2.FastBootProgramCounter.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.FastBootProgramCounter.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.ExpansionRomAddr. */
    DEVICE2.ExpansionRomAddr.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.ExpansionRomAddr.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.68f0. */
    DEVICE2._68f0.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2._68f0.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.EavRefClockControl. */
    DEVICE2.EavRefClockControl.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2.EavRefClockControl.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);

    /** @brief Bitmap for @ref DEVICE2_t.7c04. */
    DEVICE2._7c04.r32.installReadCallback(loader_read_mem, (uint8_t *)base);
    DEVICE2._7c04.r32.installWriteCallback(loader_write_mem, (uint8_t *)base);


}
