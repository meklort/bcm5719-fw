////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_DEVICE_mmap.cpp
///
/// @project    <PROJECT>
///
/// @brief      bcm5719_DEVICE_mmap
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

#include <bcm5719_DEVICE.h>
#include <stdint.h>
#include <utility>

typedef std::pair<uint8_t *, uint32_t> ram_offset_t;

static uint32_t read_from_ram(uint32_t val, void *args)
{
    ram_offset_t *loc = (ram_offset_t *)args;

    uint8_t *base = loc->first;
    base += loc->second;

    return *(uint32_t *)base;
}

static uint32_t write_to_ram(uint32_t val, void *args)
{
    ram_offset_t *loc = (ram_offset_t *)args;

    uint8_t *base = loc->first;
    base += loc->second;

    *(uint32_t *)base = val;
    return val;
}

void init_bcm5719_DEVICE_mmap(void *base)
{
    /** @brief Component Registers for @ref DEVICE. */
    /** @brief Bitmap for @ref DEVICE_t.MiscellaneousHostControl. */
    DEVICE.MiscellaneousHostControl.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)104));
    DEVICE.MiscellaneousHostControl.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)104));

    /** @brief Bitmap for @ref DEVICE_t.PciState. */
    DEVICE.PciState.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)112));
    DEVICE.PciState.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)112));

    /** @brief Bitmap for @ref DEVICE_t.RegisterBase. */
    DEVICE.RegisterBase.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)120));
    DEVICE.RegisterBase.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)120));

    /** @brief Bitmap for @ref DEVICE_t.MemoryBase. */
    DEVICE.MemoryBase.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)124));
    DEVICE.MemoryBase.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)124));

    /** @brief Bitmap for @ref DEVICE_t.RegisterData. */
    DEVICE.RegisterData.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)128));
    DEVICE.RegisterData.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)128));

    /** @brief Bitmap for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndex. */
    DEVICE.UndiReceiveReturnRingConsumerIndex.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)136));
    DEVICE.UndiReceiveReturnRingConsumerIndex.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)136));

    /** @brief Bitmap for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndexLow.
     */
    DEVICE.UndiReceiveReturnRingConsumerIndexLow.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)140));
    DEVICE.UndiReceiveReturnRingConsumerIndexLow.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)140));

    /** @brief Bitmap for @ref DEVICE_t.LinkStatusControl. */
    DEVICE.LinkStatusControl.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)188));
    DEVICE.LinkStatusControl.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)188));

    /** @brief Bitmap for @ref DEVICE_t.EmacMode. */
    DEVICE.EmacMode.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1024));
    DEVICE.EmacMode.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1024));

    /** @brief Bitmap for @ref DEVICE_t.LedControl. */
    DEVICE.LedControl.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1036));
    DEVICE.LedControl.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1036));

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses0High. */
    DEVICE.EmacMacAddresses0High.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1040));
    DEVICE.EmacMacAddresses0High.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1040));

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses0Low. */
    DEVICE.EmacMacAddresses0Low.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1044));
    DEVICE.EmacMacAddresses0Low.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1044));

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses1High. */
    DEVICE.EmacMacAddresses1High.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1048));
    DEVICE.EmacMacAddresses1High.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1048));

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses1Low. */
    DEVICE.EmacMacAddresses1Low.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1052));
    DEVICE.EmacMacAddresses1Low.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1052));

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses2High. */
    DEVICE.EmacMacAddresses2High.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1056));
    DEVICE.EmacMacAddresses2High.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1056));

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses2Low. */
    DEVICE.EmacMacAddresses2Low.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1060));
    DEVICE.EmacMacAddresses2Low.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1060));

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses3High. */
    DEVICE.EmacMacAddresses3High.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1064));
    DEVICE.EmacMacAddresses3High.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1064));

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses3Low. */
    DEVICE.EmacMacAddresses3Low.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1068));
    DEVICE.EmacMacAddresses3Low.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1068));

    /** @brief Bitmap for @ref DEVICE_t.WolPatternPointer. */
    DEVICE.WolPatternPointer.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1072));
    DEVICE.WolPatternPointer.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1072));

    /** @brief Bitmap for @ref DEVICE_t.WolPatternCfg. */
    DEVICE.WolPatternCfg.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1076));
    DEVICE.WolPatternCfg.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1076));

    /** @brief Bitmap for @ref DEVICE_t.MtuSize. */
    DEVICE.MtuSize.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1084));
    DEVICE.MtuSize.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1084));

    /** @brief Bitmap for @ref DEVICE_t.MiiCommunication. */
    DEVICE.MiiCommunication.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1100));
    DEVICE.MiiCommunication.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1100));

    /** @brief Bitmap for @ref DEVICE_t.MiiMode. */
    DEVICE.MiiMode.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1108));
    DEVICE.MiiMode.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1108));

    /** @brief Bitmap for @ref DEVICE_t.ReceiveMacMode. */
    DEVICE.ReceiveMacMode.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1128));
    DEVICE.ReceiveMacMode.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1128));

    /** @brief Bitmap for @ref DEVICE_t.SgmiiStatus. */
    DEVICE.SgmiiStatus.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1460));
    DEVICE.SgmiiStatus.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)1460));

    /** @brief Bitmap for @ref DEVICE_t.CpmuControl. */
    DEVICE.CpmuControl.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13824));
    DEVICE.CpmuControl.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13824));

    /** @brief Bitmap for @ref DEVICE_t.LinkAwarePowerModeClockPolicy. */
    DEVICE.LinkAwarePowerModeClockPolicy.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13840));
    DEVICE.LinkAwarePowerModeClockPolicy.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13840));

    /** @brief Bitmap for @ref DEVICE_t.ClockSpeedOverridePolicy. */
    DEVICE.ClockSpeedOverridePolicy.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13860));
    DEVICE.ClockSpeedOverridePolicy.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13860));

    /** @brief Bitmap for @ref DEVICE_t.Status. */
    DEVICE.Status.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13868));
    DEVICE.Status.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13868));

    /** @brief Bitmap for @ref DEVICE_t.ClockStatus. */
    DEVICE.ClockStatus.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13872));
    DEVICE.ClockStatus.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13872));

    /** @brief Bitmap for @ref DEVICE_t.GphyControlStatus. */
    DEVICE.GphyControlStatus.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13880));
    DEVICE.GphyControlStatus.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13880));

    /** @brief Bitmap for @ref DEVICE_t.ChipId. */
    DEVICE.ChipId.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13912));
    DEVICE.ChipId.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13912));

    /** @brief Bitmap for @ref DEVICE_t.MutexRequest. */
    DEVICE.MutexRequest.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13916));
    DEVICE.MutexRequest.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13916));

    /** @brief Bitmap for @ref DEVICE_t.MutexGrant. */
    DEVICE.MutexGrant.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13920));
    DEVICE.MutexGrant.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13920));

    /** @brief Bitmap for @ref DEVICE_t.GphyStrap. */
    DEVICE.GphyStrap.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13924));
    DEVICE.GphyStrap.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13924));

    /** @brief Bitmap for @ref DEVICE_t.TopLevelMiscellaneousControl1. */
    DEVICE.TopLevelMiscellaneousControl1.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13948));
    DEVICE.TopLevelMiscellaneousControl1.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)13948));

    /** @brief Bitmap for @ref DEVICE_t.EeeMode. */
    DEVICE.EeeMode.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)14000));
    DEVICE.EeeMode.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)14000));

    /** @brief Bitmap for @ref DEVICE_t.EeeLinkIdleControl. */
    DEVICE.EeeLinkIdleControl.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)14012));
    DEVICE.EeeLinkIdleControl.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)14012));

    /** @brief Bitmap for @ref DEVICE_t.EeeControl. */
    DEVICE.EeeControl.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)14032));
    DEVICE.EeeControl.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)14032));

    /** @brief Bitmap for @ref DEVICE_t.GlobalMutexRequest. */
    DEVICE.GlobalMutexRequest.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)14064));
    DEVICE.GlobalMutexRequest.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)14064));

    /** @brief Bitmap for @ref DEVICE_t.GlobalMutexGrant. */
    DEVICE.GlobalMutexGrant.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)14068));
    DEVICE.GlobalMutexGrant.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)14068));

    /** @brief Bitmap for @ref DEVICE_t.MemoryArbiterMode. */
    DEVICE.MemoryArbiterMode.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)16384));
    DEVICE.MemoryArbiterMode.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)16384));

    /** @brief Bitmap for @ref DEVICE_t.BufferManagerMode. */
    DEVICE.BufferManagerMode.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)17408));
    DEVICE.BufferManagerMode.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)17408));

    /** @brief Bitmap for @ref
     * DEVICE_t.LsoNonlsoBdReadDmaCorruptionEnableControl. */
    DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)18704));
    DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)18704));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscMode. */
    DEVICE.RxRiscMode.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20480));
    DEVICE.RxRiscMode.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20480));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscStatus. */
    DEVICE.RxRiscStatus.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20484));
    DEVICE.RxRiscStatus.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20484));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscProgramCounter. */
    DEVICE.RxRiscProgramCounter.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20508));
    DEVICE.RxRiscProgramCounter.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20508));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscCurrentInstruction. */
    DEVICE.RxRiscCurrentInstruction.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20512));
    DEVICE.RxRiscCurrentInstruction.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20512));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscHardwareBreakpoint. */
    DEVICE.RxRiscHardwareBreakpoint.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20532));
    DEVICE.RxRiscHardwareBreakpoint.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20532));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister0. */
    DEVICE.RxRiscRegister0.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20992));
    DEVICE.RxRiscRegister0.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20992));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister1. */
    DEVICE.RxRiscRegister1.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20996));
    DEVICE.RxRiscRegister1.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)20996));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister2. */
    DEVICE.RxRiscRegister2.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21000));
    DEVICE.RxRiscRegister2.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21000));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister3. */
    DEVICE.RxRiscRegister3.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21004));
    DEVICE.RxRiscRegister3.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21004));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister4. */
    DEVICE.RxRiscRegister4.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21008));
    DEVICE.RxRiscRegister4.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21008));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister5. */
    DEVICE.RxRiscRegister5.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21012));
    DEVICE.RxRiscRegister5.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21012));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister6. */
    DEVICE.RxRiscRegister6.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21016));
    DEVICE.RxRiscRegister6.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21016));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister7. */
    DEVICE.RxRiscRegister7.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21020));
    DEVICE.RxRiscRegister7.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21020));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister8. */
    DEVICE.RxRiscRegister8.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21024));
    DEVICE.RxRiscRegister8.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21024));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister9. */
    DEVICE.RxRiscRegister9.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21028));
    DEVICE.RxRiscRegister9.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21028));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister10. */
    DEVICE.RxRiscRegister10.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21032));
    DEVICE.RxRiscRegister10.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21032));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister11. */
    DEVICE.RxRiscRegister11.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21036));
    DEVICE.RxRiscRegister11.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21036));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister12. */
    DEVICE.RxRiscRegister12.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21040));
    DEVICE.RxRiscRegister12.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21040));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister13. */
    DEVICE.RxRiscRegister13.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21044));
    DEVICE.RxRiscRegister13.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21044));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister14. */
    DEVICE.RxRiscRegister14.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21048));
    DEVICE.RxRiscRegister14.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21048));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister15. */
    DEVICE.RxRiscRegister15.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21052));
    DEVICE.RxRiscRegister15.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21052));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister16. */
    DEVICE.RxRiscRegister16.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21056));
    DEVICE.RxRiscRegister16.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21056));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister17. */
    DEVICE.RxRiscRegister17.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21060));
    DEVICE.RxRiscRegister17.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21060));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister18. */
    DEVICE.RxRiscRegister18.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21064));
    DEVICE.RxRiscRegister18.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21064));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister19. */
    DEVICE.RxRiscRegister19.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21068));
    DEVICE.RxRiscRegister19.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21068));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister20. */
    DEVICE.RxRiscRegister20.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21072));
    DEVICE.RxRiscRegister20.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21072));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister21. */
    DEVICE.RxRiscRegister21.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21076));
    DEVICE.RxRiscRegister21.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21076));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister22. */
    DEVICE.RxRiscRegister22.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21080));
    DEVICE.RxRiscRegister22.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21080));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister23. */
    DEVICE.RxRiscRegister23.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21084));
    DEVICE.RxRiscRegister23.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21084));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister24. */
    DEVICE.RxRiscRegister24.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21088));
    DEVICE.RxRiscRegister24.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21088));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister25. */
    DEVICE.RxRiscRegister25.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21092));
    DEVICE.RxRiscRegister25.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21092));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister26. */
    DEVICE.RxRiscRegister26.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21096));
    DEVICE.RxRiscRegister26.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21096));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister27. */
    DEVICE.RxRiscRegister27.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21100));
    DEVICE.RxRiscRegister27.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21100));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister28. */
    DEVICE.RxRiscRegister28.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21104));
    DEVICE.RxRiscRegister28.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21104));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister29. */
    DEVICE.RxRiscRegister29.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21108));
    DEVICE.RxRiscRegister29.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21108));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister30. */
    DEVICE.RxRiscRegister30.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21112));
    DEVICE.RxRiscRegister30.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21112));

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister31. */
    DEVICE.RxRiscRegister31.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21116));
    DEVICE.RxRiscRegister31.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)21116));

    /** @brief Bitmap for @ref DEVICE_t.6408. */
    DEVICE._6408.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25608));
    DEVICE._6408.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25608));

    /** @brief Bitmap for @ref DEVICE_t.PciPowerConsumptionInfo. */
    DEVICE.PciPowerConsumptionInfo.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25616));
    DEVICE.PciPowerConsumptionInfo.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25616));

    /** @brief Bitmap for @ref DEVICE_t.PciPowerDissipatedInfo. */
    DEVICE.PciPowerDissipatedInfo.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25620));
    DEVICE.PciPowerDissipatedInfo.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25620));

    /** @brief Bitmap for @ref DEVICE_t.PciVpdRequest. */
    DEVICE.PciVpdRequest.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25644));
    DEVICE.PciVpdRequest.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25644));

    /** @brief Bitmap for @ref DEVICE_t.PciVpdResponse. */
    DEVICE.PciVpdResponse.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25648));
    DEVICE.PciVpdResponse.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25648));

    /** @brief Bitmap for @ref DEVICE_t.PciVendorDeviceId. */
    DEVICE.PciVendorDeviceId.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25652));
    DEVICE.PciVendorDeviceId.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25652));

    /** @brief Bitmap for @ref DEVICE_t.PciSubsystemId. */
    DEVICE.PciSubsystemId.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25656));
    DEVICE.PciSubsystemId.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25656));

    /** @brief Bitmap for @ref DEVICE_t.PciClassCodeRevision. */
    DEVICE.PciClassCodeRevision.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25660));
    DEVICE.PciClassCodeRevision.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25660));

    /** @brief Bitmap for @ref DEVICE_t.64c0. */
    DEVICE._64c0.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25792));
    DEVICE._64c0.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25792));

    /** @brief Bitmap for @ref DEVICE_t.64c8. */
    DEVICE._64c8.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25800));
    DEVICE._64c8.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25800));

    /** @brief Bitmap for @ref DEVICE_t.64dc. */
    DEVICE._64dc.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25820));
    DEVICE._64dc.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25820));

    /** @brief Bitmap for @ref DEVICE_t.PciSerialNumberLow. */
    DEVICE.PciSerialNumberLow.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25860));
    DEVICE.PciSerialNumberLow.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25860));

    /** @brief Bitmap for @ref DEVICE_t.PciSerialNumberHigh. */
    DEVICE.PciSerialNumberHigh.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25864));
    DEVICE.PciSerialNumberHigh.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25864));

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget0. */
    DEVICE.PciPowerBudget0.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25872));
    DEVICE.PciPowerBudget0.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25872));

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget1. */
    DEVICE.PciPowerBudget1.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25876));
    DEVICE.PciPowerBudget1.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25876));

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget2. */
    DEVICE.PciPowerBudget2.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25880));
    DEVICE.PciPowerBudget2.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25880));

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget3. */
    DEVICE.PciPowerBudget3.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25884));
    DEVICE.PciPowerBudget3.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25884));

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget4. */
    DEVICE.PciPowerBudget4.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25888));
    DEVICE.PciPowerBudget4.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25888));

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget5. */
    DEVICE.PciPowerBudget5.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25892));
    DEVICE.PciPowerBudget5.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25892));

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget6. */
    DEVICE.PciPowerBudget6.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25896));
    DEVICE.PciPowerBudget6.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25896));

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget7. */
    DEVICE.PciPowerBudget7.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25900));
    DEVICE.PciPowerBudget7.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25900));

    /** @brief Bitmap for @ref DEVICE_t.6530. */
    DEVICE._6530.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25904));
    DEVICE._6530.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25904));

    /** @brief Bitmap for @ref DEVICE_t.6550. */
    DEVICE._6550.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25936));
    DEVICE._6550.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)25936));

    /** @brief Bitmap for @ref DEVICE_t.65f4. */
    DEVICE._65f4.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26100));
    DEVICE._65f4.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26100));

    /** @brief Bitmap for @ref DEVICE_t.GrcModeControl. */
    DEVICE.GrcModeControl.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26624));
    DEVICE.GrcModeControl.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26624));

    /** @brief Bitmap for @ref DEVICE_t.MiscellaneousLocalControl. */
    DEVICE.MiscellaneousLocalControl.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26632));
    DEVICE.MiscellaneousLocalControl.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26632));

    /** @brief Bitmap for @ref DEVICE_t.Timer. */
    DEVICE.Timer.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26636));
    DEVICE.Timer.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26636));

    /** @brief Bitmap for @ref DEVICE_t.RxCpuEvent. */
    DEVICE.RxCpuEvent.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26640));
    DEVICE.RxCpuEvent.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26640));

    /** @brief Bitmap for @ref DEVICE_t.6838. */
    DEVICE._6838.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26680));
    DEVICE._6838.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26680));

    /** @brief Bitmap for @ref DEVICE_t.MdiControl. */
    DEVICE.MdiControl.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26692));
    DEVICE.MdiControl.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26692));

    /** @brief Bitmap for @ref DEVICE_t.FastBootProgramCounter. */
    DEVICE.FastBootProgramCounter.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26772));
    DEVICE.FastBootProgramCounter.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26772));

    /** @brief Bitmap for @ref DEVICE_t.ExpansionRomAddr. */
    DEVICE.ExpansionRomAddr.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26860));
    DEVICE.ExpansionRomAddr.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26860));

    /** @brief Bitmap for @ref DEVICE_t.68f0. */
    DEVICE._68f0.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26864));
    DEVICE._68f0.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26864));

    /** @brief Bitmap for @ref DEVICE_t.EavRefClockControl. */
    DEVICE.EavRefClockControl.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26888));
    DEVICE.EavRefClockControl.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)26888));

    /** @brief Bitmap for @ref DEVICE_t.7c04. */
    DEVICE._7c04.r32.installReadCallback(
        read_from_ram, new ram_offset_t((uint8_t *)base, (uint32_t)31748));
    DEVICE._7c04.r32.installWriteCallback(
        write_to_ram, new ram_offset_t((uint8_t *)base, (uint32_t)31748));
}
