////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_DEVICE_mmap.cpp
///
/// @project    bcm5719
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

#include <stdint.h>
#include <utility>
#include <bcm5719_DEVICE.h>

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

void init_bcm5719_DEVICE_mmap(void *base)
{
    /** @brief Component Registers for @ref DEVICE. */
    /** @brief Bitmap for @ref DEVICE_t.MiscellaneousHostControl. */
    static ram_offset_t DEVICE_MiscellaneousHostControl_r32((uint8_t *)base, (uint32_t)104);
    DEVICE.MiscellaneousHostControl.r32.installReadCallback(read_from_ram, &DEVICE_MiscellaneousHostControl_r32);
    DEVICE.MiscellaneousHostControl.r32.installWriteCallback(write_to_ram, &DEVICE_MiscellaneousHostControl_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciState. */
    static ram_offset_t DEVICE_PciState_r32((uint8_t *)base, (uint32_t)112);
    DEVICE.PciState.r32.installReadCallback(read_from_ram, &DEVICE_PciState_r32);
    DEVICE.PciState.r32.installWriteCallback(write_to_ram, &DEVICE_PciState_r32);

    /** @brief Bitmap for @ref DEVICE_t.RegisterBase. */
    static ram_offset_t DEVICE_RegisterBase_r32((uint8_t *)base, (uint32_t)120);
    DEVICE.RegisterBase.r32.installReadCallback(read_from_ram, &DEVICE_RegisterBase_r32);
    DEVICE.RegisterBase.r32.installWriteCallback(write_to_ram, &DEVICE_RegisterBase_r32);

    /** @brief Bitmap for @ref DEVICE_t.MemoryBase. */
    static ram_offset_t DEVICE_MemoryBase_r32((uint8_t *)base, (uint32_t)124);
    DEVICE.MemoryBase.r32.installReadCallback(read_from_ram, &DEVICE_MemoryBase_r32);
    DEVICE.MemoryBase.r32.installWriteCallback(write_to_ram, &DEVICE_MemoryBase_r32);

    /** @brief Bitmap for @ref DEVICE_t.RegisterData. */
    static ram_offset_t DEVICE_RegisterData_r32((uint8_t *)base, (uint32_t)128);
    DEVICE.RegisterData.r32.installReadCallback(read_from_ram, &DEVICE_RegisterData_r32);
    DEVICE.RegisterData.r32.installWriteCallback(write_to_ram, &DEVICE_RegisterData_r32);

    /** @brief Bitmap for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndex. */
    static ram_offset_t DEVICE_UndiReceiveReturnRingConsumerIndex_r32((uint8_t *)base, (uint32_t)136);
    DEVICE.UndiReceiveReturnRingConsumerIndex.r32.installReadCallback(read_from_ram, &DEVICE_UndiReceiveReturnRingConsumerIndex_r32);
    DEVICE.UndiReceiveReturnRingConsumerIndex.r32.installWriteCallback(write_to_ram, &DEVICE_UndiReceiveReturnRingConsumerIndex_r32);

    /** @brief Bitmap for @ref DEVICE_t.UndiReceiveReturnRingConsumerIndexLow. */
    static ram_offset_t DEVICE_UndiReceiveReturnRingConsumerIndexLow_r32((uint8_t *)base, (uint32_t)140);
    DEVICE.UndiReceiveReturnRingConsumerIndexLow.r32.installReadCallback(read_from_ram, &DEVICE_UndiReceiveReturnRingConsumerIndexLow_r32);
    DEVICE.UndiReceiveReturnRingConsumerIndexLow.r32.installWriteCallback(write_to_ram, &DEVICE_UndiReceiveReturnRingConsumerIndexLow_r32);

    /** @brief Bitmap for @ref DEVICE_t.LinkStatusControl. */
    static ram_offset_t DEVICE_LinkStatusControl_r32((uint8_t *)base, (uint32_t)188);
    DEVICE.LinkStatusControl.r32.installReadCallback(read_from_ram, &DEVICE_LinkStatusControl_r32);
    DEVICE.LinkStatusControl.r32.installWriteCallback(write_to_ram, &DEVICE_LinkStatusControl_r32);

    /** @brief Bitmap for @ref DEVICE_t.EmacMode. */
    static ram_offset_t DEVICE_EmacMode_r32((uint8_t *)base, (uint32_t)1024);
    DEVICE.EmacMode.r32.installReadCallback(read_from_ram, &DEVICE_EmacMode_r32);
    DEVICE.EmacMode.r32.installWriteCallback(write_to_ram, &DEVICE_EmacMode_r32);

    /** @brief Bitmap for @ref DEVICE_t.LedControl. */
    static ram_offset_t DEVICE_LedControl_r32((uint8_t *)base, (uint32_t)1036);
    DEVICE.LedControl.r32.installReadCallback(read_from_ram, &DEVICE_LedControl_r32);
    DEVICE.LedControl.r32.installWriteCallback(write_to_ram, &DEVICE_LedControl_r32);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses0High. */
    static ram_offset_t DEVICE_EmacMacAddresses0High_r32((uint8_t *)base, (uint32_t)1040);
    DEVICE.EmacMacAddresses0High.r32.installReadCallback(read_from_ram, &DEVICE_EmacMacAddresses0High_r32);
    DEVICE.EmacMacAddresses0High.r32.installWriteCallback(write_to_ram, &DEVICE_EmacMacAddresses0High_r32);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses0Low. */
    static ram_offset_t DEVICE_EmacMacAddresses0Low_r32((uint8_t *)base, (uint32_t)1044);
    DEVICE.EmacMacAddresses0Low.r32.installReadCallback(read_from_ram, &DEVICE_EmacMacAddresses0Low_r32);
    DEVICE.EmacMacAddresses0Low.r32.installWriteCallback(write_to_ram, &DEVICE_EmacMacAddresses0Low_r32);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses1High. */
    static ram_offset_t DEVICE_EmacMacAddresses1High_r32((uint8_t *)base, (uint32_t)1048);
    DEVICE.EmacMacAddresses1High.r32.installReadCallback(read_from_ram, &DEVICE_EmacMacAddresses1High_r32);
    DEVICE.EmacMacAddresses1High.r32.installWriteCallback(write_to_ram, &DEVICE_EmacMacAddresses1High_r32);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses1Low. */
    static ram_offset_t DEVICE_EmacMacAddresses1Low_r32((uint8_t *)base, (uint32_t)1052);
    DEVICE.EmacMacAddresses1Low.r32.installReadCallback(read_from_ram, &DEVICE_EmacMacAddresses1Low_r32);
    DEVICE.EmacMacAddresses1Low.r32.installWriteCallback(write_to_ram, &DEVICE_EmacMacAddresses1Low_r32);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses2High. */
    static ram_offset_t DEVICE_EmacMacAddresses2High_r32((uint8_t *)base, (uint32_t)1056);
    DEVICE.EmacMacAddresses2High.r32.installReadCallback(read_from_ram, &DEVICE_EmacMacAddresses2High_r32);
    DEVICE.EmacMacAddresses2High.r32.installWriteCallback(write_to_ram, &DEVICE_EmacMacAddresses2High_r32);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses2Low. */
    static ram_offset_t DEVICE_EmacMacAddresses2Low_r32((uint8_t *)base, (uint32_t)1060);
    DEVICE.EmacMacAddresses2Low.r32.installReadCallback(read_from_ram, &DEVICE_EmacMacAddresses2Low_r32);
    DEVICE.EmacMacAddresses2Low.r32.installWriteCallback(write_to_ram, &DEVICE_EmacMacAddresses2Low_r32);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses3High. */
    static ram_offset_t DEVICE_EmacMacAddresses3High_r32((uint8_t *)base, (uint32_t)1064);
    DEVICE.EmacMacAddresses3High.r32.installReadCallback(read_from_ram, &DEVICE_EmacMacAddresses3High_r32);
    DEVICE.EmacMacAddresses3High.r32.installWriteCallback(write_to_ram, &DEVICE_EmacMacAddresses3High_r32);

    /** @brief Bitmap for @ref DEVICE_t.EmacMacAddresses3Low. */
    static ram_offset_t DEVICE_EmacMacAddresses3Low_r32((uint8_t *)base, (uint32_t)1068);
    DEVICE.EmacMacAddresses3Low.r32.installReadCallback(read_from_ram, &DEVICE_EmacMacAddresses3Low_r32);
    DEVICE.EmacMacAddresses3Low.r32.installWriteCallback(write_to_ram, &DEVICE_EmacMacAddresses3Low_r32);

    /** @brief Bitmap for @ref DEVICE_t.WolPatternPointer. */
    static ram_offset_t DEVICE_WolPatternPointer_r32((uint8_t *)base, (uint32_t)1072);
    DEVICE.WolPatternPointer.r32.installReadCallback(read_from_ram, &DEVICE_WolPatternPointer_r32);
    DEVICE.WolPatternPointer.r32.installWriteCallback(write_to_ram, &DEVICE_WolPatternPointer_r32);

    /** @brief Bitmap for @ref DEVICE_t.WolPatternCfg. */
    static ram_offset_t DEVICE_WolPatternCfg_r32((uint8_t *)base, (uint32_t)1076);
    DEVICE.WolPatternCfg.r32.installReadCallback(read_from_ram, &DEVICE_WolPatternCfg_r32);
    DEVICE.WolPatternCfg.r32.installWriteCallback(write_to_ram, &DEVICE_WolPatternCfg_r32);

    /** @brief Bitmap for @ref DEVICE_t.MtuSize. */
    static ram_offset_t DEVICE_MtuSize_r32((uint8_t *)base, (uint32_t)1084);
    DEVICE.MtuSize.r32.installReadCallback(read_from_ram, &DEVICE_MtuSize_r32);
    DEVICE.MtuSize.r32.installWriteCallback(write_to_ram, &DEVICE_MtuSize_r32);

    /** @brief Bitmap for @ref DEVICE_t.MiiCommunication. */
    static ram_offset_t DEVICE_MiiCommunication_r32((uint8_t *)base, (uint32_t)1100);
    DEVICE.MiiCommunication.r32.installReadCallback(read_from_ram, &DEVICE_MiiCommunication_r32);
    DEVICE.MiiCommunication.r32.installWriteCallback(write_to_ram, &DEVICE_MiiCommunication_r32);

    /** @brief Bitmap for @ref DEVICE_t.MiiMode. */
    static ram_offset_t DEVICE_MiiMode_r32((uint8_t *)base, (uint32_t)1108);
    DEVICE.MiiMode.r32.installReadCallback(read_from_ram, &DEVICE_MiiMode_r32);
    DEVICE.MiiMode.r32.installWriteCallback(write_to_ram, &DEVICE_MiiMode_r32);

    /** @brief Bitmap for @ref DEVICE_t.ReceiveMacMode. */
    static ram_offset_t DEVICE_ReceiveMacMode_r32((uint8_t *)base, (uint32_t)1128);
    DEVICE.ReceiveMacMode.r32.installReadCallback(read_from_ram, &DEVICE_ReceiveMacMode_r32);
    DEVICE.ReceiveMacMode.r32.installWriteCallback(write_to_ram, &DEVICE_ReceiveMacMode_r32);

    /** @brief Bitmap for @ref DEVICE_t.SgmiiStatus. */
    static ram_offset_t DEVICE_SgmiiStatus_r32((uint8_t *)base, (uint32_t)1460);
    DEVICE.SgmiiStatus.r32.installReadCallback(read_from_ram, &DEVICE_SgmiiStatus_r32);
    DEVICE.SgmiiStatus.r32.installWriteCallback(write_to_ram, &DEVICE_SgmiiStatus_r32);

    /** @brief Bitmap for @ref DEVICE_t.CpmuControl. */
    static ram_offset_t DEVICE_CpmuControl_r32((uint8_t *)base, (uint32_t)13824);
    DEVICE.CpmuControl.r32.installReadCallback(read_from_ram, &DEVICE_CpmuControl_r32);
    DEVICE.CpmuControl.r32.installWriteCallback(write_to_ram, &DEVICE_CpmuControl_r32);

    /** @brief Bitmap for @ref DEVICE_t.LinkAwarePowerModeClockPolicy. */
    static ram_offset_t DEVICE_LinkAwarePowerModeClockPolicy_r32((uint8_t *)base, (uint32_t)13840);
    DEVICE.LinkAwarePowerModeClockPolicy.r32.installReadCallback(read_from_ram, &DEVICE_LinkAwarePowerModeClockPolicy_r32);
    DEVICE.LinkAwarePowerModeClockPolicy.r32.installWriteCallback(write_to_ram, &DEVICE_LinkAwarePowerModeClockPolicy_r32);

    /** @brief Bitmap for @ref DEVICE_t.ClockSpeedOverridePolicy. */
    static ram_offset_t DEVICE_ClockSpeedOverridePolicy_r32((uint8_t *)base, (uint32_t)13860);
    DEVICE.ClockSpeedOverridePolicy.r32.installReadCallback(read_from_ram, &DEVICE_ClockSpeedOverridePolicy_r32);
    DEVICE.ClockSpeedOverridePolicy.r32.installWriteCallback(write_to_ram, &DEVICE_ClockSpeedOverridePolicy_r32);

    /** @brief Bitmap for @ref DEVICE_t.Status. */
    static ram_offset_t DEVICE_Status_r32((uint8_t *)base, (uint32_t)13868);
    DEVICE.Status.r32.installReadCallback(read_from_ram, &DEVICE_Status_r32);
    DEVICE.Status.r32.installWriteCallback(write_to_ram, &DEVICE_Status_r32);

    /** @brief Bitmap for @ref DEVICE_t.ClockStatus. */
    static ram_offset_t DEVICE_ClockStatus_r32((uint8_t *)base, (uint32_t)13872);
    DEVICE.ClockStatus.r32.installReadCallback(read_from_ram, &DEVICE_ClockStatus_r32);
    DEVICE.ClockStatus.r32.installWriteCallback(write_to_ram, &DEVICE_ClockStatus_r32);

    /** @brief Bitmap for @ref DEVICE_t.GphyControlStatus. */
    static ram_offset_t DEVICE_GphyControlStatus_r32((uint8_t *)base, (uint32_t)13880);
    DEVICE.GphyControlStatus.r32.installReadCallback(read_from_ram, &DEVICE_GphyControlStatus_r32);
    DEVICE.GphyControlStatus.r32.installWriteCallback(write_to_ram, &DEVICE_GphyControlStatus_r32);

    /** @brief Bitmap for @ref DEVICE_t.ChipId. */
    static ram_offset_t DEVICE_ChipId_r32((uint8_t *)base, (uint32_t)13912);
    DEVICE.ChipId.r32.installReadCallback(read_from_ram, &DEVICE_ChipId_r32);
    DEVICE.ChipId.r32.installWriteCallback(write_to_ram, &DEVICE_ChipId_r32);

    /** @brief Bitmap for @ref DEVICE_t.MutexRequest. */
    static ram_offset_t DEVICE_MutexRequest_r32((uint8_t *)base, (uint32_t)13916);
    DEVICE.MutexRequest.r32.installReadCallback(read_from_ram, &DEVICE_MutexRequest_r32);
    DEVICE.MutexRequest.r32.installWriteCallback(write_to_ram, &DEVICE_MutexRequest_r32);

    /** @brief Bitmap for @ref DEVICE_t.MutexGrant. */
    static ram_offset_t DEVICE_MutexGrant_r32((uint8_t *)base, (uint32_t)13920);
    DEVICE.MutexGrant.r32.installReadCallback(read_from_ram, &DEVICE_MutexGrant_r32);
    DEVICE.MutexGrant.r32.installWriteCallback(write_to_ram, &DEVICE_MutexGrant_r32);

    /** @brief Bitmap for @ref DEVICE_t.GphyStrap. */
    static ram_offset_t DEVICE_GphyStrap_r32((uint8_t *)base, (uint32_t)13924);
    DEVICE.GphyStrap.r32.installReadCallback(read_from_ram, &DEVICE_GphyStrap_r32);
    DEVICE.GphyStrap.r32.installWriteCallback(write_to_ram, &DEVICE_GphyStrap_r32);

    /** @brief Bitmap for @ref DEVICE_t.TopLevelMiscellaneousControl1. */
    static ram_offset_t DEVICE_TopLevelMiscellaneousControl1_r32((uint8_t *)base, (uint32_t)13948);
    DEVICE.TopLevelMiscellaneousControl1.r32.installReadCallback(read_from_ram, &DEVICE_TopLevelMiscellaneousControl1_r32);
    DEVICE.TopLevelMiscellaneousControl1.r32.installWriteCallback(write_to_ram, &DEVICE_TopLevelMiscellaneousControl1_r32);

    /** @brief Bitmap for @ref DEVICE_t.EeeMode. */
    static ram_offset_t DEVICE_EeeMode_r32((uint8_t *)base, (uint32_t)14000);
    DEVICE.EeeMode.r32.installReadCallback(read_from_ram, &DEVICE_EeeMode_r32);
    DEVICE.EeeMode.r32.installWriteCallback(write_to_ram, &DEVICE_EeeMode_r32);

    /** @brief Bitmap for @ref DEVICE_t.EeeLinkIdleControl. */
    static ram_offset_t DEVICE_EeeLinkIdleControl_r32((uint8_t *)base, (uint32_t)14012);
    DEVICE.EeeLinkIdleControl.r32.installReadCallback(read_from_ram, &DEVICE_EeeLinkIdleControl_r32);
    DEVICE.EeeLinkIdleControl.r32.installWriteCallback(write_to_ram, &DEVICE_EeeLinkIdleControl_r32);

    /** @brief Bitmap for @ref DEVICE_t.EeeControl. */
    static ram_offset_t DEVICE_EeeControl_r32((uint8_t *)base, (uint32_t)14032);
    DEVICE.EeeControl.r32.installReadCallback(read_from_ram, &DEVICE_EeeControl_r32);
    DEVICE.EeeControl.r32.installWriteCallback(write_to_ram, &DEVICE_EeeControl_r32);

    /** @brief Bitmap for @ref DEVICE_t.GlobalMutexRequest. */
    static ram_offset_t DEVICE_GlobalMutexRequest_r32((uint8_t *)base, (uint32_t)14064);
    DEVICE.GlobalMutexRequest.r32.installReadCallback(read_from_ram, &DEVICE_GlobalMutexRequest_r32);
    DEVICE.GlobalMutexRequest.r32.installWriteCallback(write_to_ram, &DEVICE_GlobalMutexRequest_r32);

    /** @brief Bitmap for @ref DEVICE_t.GlobalMutexGrant. */
    static ram_offset_t DEVICE_GlobalMutexGrant_r32((uint8_t *)base, (uint32_t)14068);
    DEVICE.GlobalMutexGrant.r32.installReadCallback(read_from_ram, &DEVICE_GlobalMutexGrant_r32);
    DEVICE.GlobalMutexGrant.r32.installWriteCallback(write_to_ram, &DEVICE_GlobalMutexGrant_r32);

    /** @brief Bitmap for @ref DEVICE_t.MemoryArbiterMode. */
    static ram_offset_t DEVICE_MemoryArbiterMode_r32((uint8_t *)base, (uint32_t)16384);
    DEVICE.MemoryArbiterMode.r32.installReadCallback(read_from_ram, &DEVICE_MemoryArbiterMode_r32);
    DEVICE.MemoryArbiterMode.r32.installWriteCallback(write_to_ram, &DEVICE_MemoryArbiterMode_r32);

    /** @brief Bitmap for @ref DEVICE_t.BufferManagerMode. */
    static ram_offset_t DEVICE_BufferManagerMode_r32((uint8_t *)base, (uint32_t)17408);
    DEVICE.BufferManagerMode.r32.installReadCallback(read_from_ram, &DEVICE_BufferManagerMode_r32);
    DEVICE.BufferManagerMode.r32.installWriteCallback(write_to_ram, &DEVICE_BufferManagerMode_r32);

    /** @brief Bitmap for @ref DEVICE_t.LsoNonlsoBdReadDmaCorruptionEnableControl. */
    static ram_offset_t DEVICE_LsoNonlsoBdReadDmaCorruptionEnableControl_r32((uint8_t *)base, (uint32_t)18704);
    DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installReadCallback(read_from_ram, &DEVICE_LsoNonlsoBdReadDmaCorruptionEnableControl_r32);
    DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl.r32.installWriteCallback(write_to_ram, &DEVICE_LsoNonlsoBdReadDmaCorruptionEnableControl_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscMode. */
    static ram_offset_t DEVICE_RxRiscMode_r32((uint8_t *)base, (uint32_t)20480);
    DEVICE.RxRiscMode.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscMode_r32);
    DEVICE.RxRiscMode.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscMode_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscStatus. */
    static ram_offset_t DEVICE_RxRiscStatus_r32((uint8_t *)base, (uint32_t)20484);
    DEVICE.RxRiscStatus.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscStatus_r32);
    DEVICE.RxRiscStatus.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscStatus_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscProgramCounter. */
    static ram_offset_t DEVICE_RxRiscProgramCounter_r32((uint8_t *)base, (uint32_t)20508);
    DEVICE.RxRiscProgramCounter.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscProgramCounter_r32);
    DEVICE.RxRiscProgramCounter.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscProgramCounter_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscCurrentInstruction. */
    static ram_offset_t DEVICE_RxRiscCurrentInstruction_r32((uint8_t *)base, (uint32_t)20512);
    DEVICE.RxRiscCurrentInstruction.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscCurrentInstruction_r32);
    DEVICE.RxRiscCurrentInstruction.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscCurrentInstruction_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscHardwareBreakpoint. */
    static ram_offset_t DEVICE_RxRiscHardwareBreakpoint_r32((uint8_t *)base, (uint32_t)20532);
    DEVICE.RxRiscHardwareBreakpoint.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscHardwareBreakpoint_r32);
    DEVICE.RxRiscHardwareBreakpoint.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscHardwareBreakpoint_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister0. */
    static ram_offset_t DEVICE_RxRiscRegister0_r32((uint8_t *)base, (uint32_t)20992);
    DEVICE.RxRiscRegister0.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister0_r32);
    DEVICE.RxRiscRegister0.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister0_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister1. */
    static ram_offset_t DEVICE_RxRiscRegister1_r32((uint8_t *)base, (uint32_t)20996);
    DEVICE.RxRiscRegister1.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister1_r32);
    DEVICE.RxRiscRegister1.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister1_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister2. */
    static ram_offset_t DEVICE_RxRiscRegister2_r32((uint8_t *)base, (uint32_t)21000);
    DEVICE.RxRiscRegister2.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister2_r32);
    DEVICE.RxRiscRegister2.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister2_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister3. */
    static ram_offset_t DEVICE_RxRiscRegister3_r32((uint8_t *)base, (uint32_t)21004);
    DEVICE.RxRiscRegister3.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister3_r32);
    DEVICE.RxRiscRegister3.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister3_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister4. */
    static ram_offset_t DEVICE_RxRiscRegister4_r32((uint8_t *)base, (uint32_t)21008);
    DEVICE.RxRiscRegister4.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister4_r32);
    DEVICE.RxRiscRegister4.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister4_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister5. */
    static ram_offset_t DEVICE_RxRiscRegister5_r32((uint8_t *)base, (uint32_t)21012);
    DEVICE.RxRiscRegister5.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister5_r32);
    DEVICE.RxRiscRegister5.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister5_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister6. */
    static ram_offset_t DEVICE_RxRiscRegister6_r32((uint8_t *)base, (uint32_t)21016);
    DEVICE.RxRiscRegister6.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister6_r32);
    DEVICE.RxRiscRegister6.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister6_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister7. */
    static ram_offset_t DEVICE_RxRiscRegister7_r32((uint8_t *)base, (uint32_t)21020);
    DEVICE.RxRiscRegister7.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister7_r32);
    DEVICE.RxRiscRegister7.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister7_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister8. */
    static ram_offset_t DEVICE_RxRiscRegister8_r32((uint8_t *)base, (uint32_t)21024);
    DEVICE.RxRiscRegister8.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister8_r32);
    DEVICE.RxRiscRegister8.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister8_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister9. */
    static ram_offset_t DEVICE_RxRiscRegister9_r32((uint8_t *)base, (uint32_t)21028);
    DEVICE.RxRiscRegister9.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister9_r32);
    DEVICE.RxRiscRegister9.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister9_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister10. */
    static ram_offset_t DEVICE_RxRiscRegister10_r32((uint8_t *)base, (uint32_t)21032);
    DEVICE.RxRiscRegister10.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister10_r32);
    DEVICE.RxRiscRegister10.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister10_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister11. */
    static ram_offset_t DEVICE_RxRiscRegister11_r32((uint8_t *)base, (uint32_t)21036);
    DEVICE.RxRiscRegister11.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister11_r32);
    DEVICE.RxRiscRegister11.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister11_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister12. */
    static ram_offset_t DEVICE_RxRiscRegister12_r32((uint8_t *)base, (uint32_t)21040);
    DEVICE.RxRiscRegister12.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister12_r32);
    DEVICE.RxRiscRegister12.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister12_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister13. */
    static ram_offset_t DEVICE_RxRiscRegister13_r32((uint8_t *)base, (uint32_t)21044);
    DEVICE.RxRiscRegister13.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister13_r32);
    DEVICE.RxRiscRegister13.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister13_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister14. */
    static ram_offset_t DEVICE_RxRiscRegister14_r32((uint8_t *)base, (uint32_t)21048);
    DEVICE.RxRiscRegister14.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister14_r32);
    DEVICE.RxRiscRegister14.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister14_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister15. */
    static ram_offset_t DEVICE_RxRiscRegister15_r32((uint8_t *)base, (uint32_t)21052);
    DEVICE.RxRiscRegister15.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister15_r32);
    DEVICE.RxRiscRegister15.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister15_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister16. */
    static ram_offset_t DEVICE_RxRiscRegister16_r32((uint8_t *)base, (uint32_t)21056);
    DEVICE.RxRiscRegister16.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister16_r32);
    DEVICE.RxRiscRegister16.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister16_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister17. */
    static ram_offset_t DEVICE_RxRiscRegister17_r32((uint8_t *)base, (uint32_t)21060);
    DEVICE.RxRiscRegister17.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister17_r32);
    DEVICE.RxRiscRegister17.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister17_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister18. */
    static ram_offset_t DEVICE_RxRiscRegister18_r32((uint8_t *)base, (uint32_t)21064);
    DEVICE.RxRiscRegister18.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister18_r32);
    DEVICE.RxRiscRegister18.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister18_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister19. */
    static ram_offset_t DEVICE_RxRiscRegister19_r32((uint8_t *)base, (uint32_t)21068);
    DEVICE.RxRiscRegister19.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister19_r32);
    DEVICE.RxRiscRegister19.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister19_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister20. */
    static ram_offset_t DEVICE_RxRiscRegister20_r32((uint8_t *)base, (uint32_t)21072);
    DEVICE.RxRiscRegister20.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister20_r32);
    DEVICE.RxRiscRegister20.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister20_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister21. */
    static ram_offset_t DEVICE_RxRiscRegister21_r32((uint8_t *)base, (uint32_t)21076);
    DEVICE.RxRiscRegister21.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister21_r32);
    DEVICE.RxRiscRegister21.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister21_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister22. */
    static ram_offset_t DEVICE_RxRiscRegister22_r32((uint8_t *)base, (uint32_t)21080);
    DEVICE.RxRiscRegister22.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister22_r32);
    DEVICE.RxRiscRegister22.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister22_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister23. */
    static ram_offset_t DEVICE_RxRiscRegister23_r32((uint8_t *)base, (uint32_t)21084);
    DEVICE.RxRiscRegister23.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister23_r32);
    DEVICE.RxRiscRegister23.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister23_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister24. */
    static ram_offset_t DEVICE_RxRiscRegister24_r32((uint8_t *)base, (uint32_t)21088);
    DEVICE.RxRiscRegister24.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister24_r32);
    DEVICE.RxRiscRegister24.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister24_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister25. */
    static ram_offset_t DEVICE_RxRiscRegister25_r32((uint8_t *)base, (uint32_t)21092);
    DEVICE.RxRiscRegister25.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister25_r32);
    DEVICE.RxRiscRegister25.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister25_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister26. */
    static ram_offset_t DEVICE_RxRiscRegister26_r32((uint8_t *)base, (uint32_t)21096);
    DEVICE.RxRiscRegister26.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister26_r32);
    DEVICE.RxRiscRegister26.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister26_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister27. */
    static ram_offset_t DEVICE_RxRiscRegister27_r32((uint8_t *)base, (uint32_t)21100);
    DEVICE.RxRiscRegister27.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister27_r32);
    DEVICE.RxRiscRegister27.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister27_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister28. */
    static ram_offset_t DEVICE_RxRiscRegister28_r32((uint8_t *)base, (uint32_t)21104);
    DEVICE.RxRiscRegister28.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister28_r32);
    DEVICE.RxRiscRegister28.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister28_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister29. */
    static ram_offset_t DEVICE_RxRiscRegister29_r32((uint8_t *)base, (uint32_t)21108);
    DEVICE.RxRiscRegister29.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister29_r32);
    DEVICE.RxRiscRegister29.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister29_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister30. */
    static ram_offset_t DEVICE_RxRiscRegister30_r32((uint8_t *)base, (uint32_t)21112);
    DEVICE.RxRiscRegister30.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister30_r32);
    DEVICE.RxRiscRegister30.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister30_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxRiscRegister31. */
    static ram_offset_t DEVICE_RxRiscRegister31_r32((uint8_t *)base, (uint32_t)21116);
    DEVICE.RxRiscRegister31.r32.installReadCallback(read_from_ram, &DEVICE_RxRiscRegister31_r32);
    DEVICE.RxRiscRegister31.r32.installWriteCallback(write_to_ram, &DEVICE_RxRiscRegister31_r32);

    /** @brief Bitmap for @ref DEVICE_t.6408. */
    static ram_offset_t DEVICE__6408_r32((uint8_t *)base, (uint32_t)25608);
    DEVICE._6408.r32.installReadCallback(read_from_ram, &DEVICE__6408_r32);
    DEVICE._6408.r32.installWriteCallback(write_to_ram, &DEVICE__6408_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerConsumptionInfo. */
    static ram_offset_t DEVICE_PciPowerConsumptionInfo_r32((uint8_t *)base, (uint32_t)25616);
    DEVICE.PciPowerConsumptionInfo.r32.installReadCallback(read_from_ram, &DEVICE_PciPowerConsumptionInfo_r32);
    DEVICE.PciPowerConsumptionInfo.r32.installWriteCallback(write_to_ram, &DEVICE_PciPowerConsumptionInfo_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerDissipatedInfo. */
    static ram_offset_t DEVICE_PciPowerDissipatedInfo_r32((uint8_t *)base, (uint32_t)25620);
    DEVICE.PciPowerDissipatedInfo.r32.installReadCallback(read_from_ram, &DEVICE_PciPowerDissipatedInfo_r32);
    DEVICE.PciPowerDissipatedInfo.r32.installWriteCallback(write_to_ram, &DEVICE_PciPowerDissipatedInfo_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciVpdRequest. */
    static ram_offset_t DEVICE_PciVpdRequest_r32((uint8_t *)base, (uint32_t)25644);
    DEVICE.PciVpdRequest.r32.installReadCallback(read_from_ram, &DEVICE_PciVpdRequest_r32);
    DEVICE.PciVpdRequest.r32.installWriteCallback(write_to_ram, &DEVICE_PciVpdRequest_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciVpdResponse. */
    static ram_offset_t DEVICE_PciVpdResponse_r32((uint8_t *)base, (uint32_t)25648);
    DEVICE.PciVpdResponse.r32.installReadCallback(read_from_ram, &DEVICE_PciVpdResponse_r32);
    DEVICE.PciVpdResponse.r32.installWriteCallback(write_to_ram, &DEVICE_PciVpdResponse_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciVendorDeviceId. */
    static ram_offset_t DEVICE_PciVendorDeviceId_r32((uint8_t *)base, (uint32_t)25652);
    DEVICE.PciVendorDeviceId.r32.installReadCallback(read_from_ram, &DEVICE_PciVendorDeviceId_r32);
    DEVICE.PciVendorDeviceId.r32.installWriteCallback(write_to_ram, &DEVICE_PciVendorDeviceId_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciSubsystemId. */
    static ram_offset_t DEVICE_PciSubsystemId_r32((uint8_t *)base, (uint32_t)25656);
    DEVICE.PciSubsystemId.r32.installReadCallback(read_from_ram, &DEVICE_PciSubsystemId_r32);
    DEVICE.PciSubsystemId.r32.installWriteCallback(write_to_ram, &DEVICE_PciSubsystemId_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciClassCodeRevision. */
    static ram_offset_t DEVICE_PciClassCodeRevision_r32((uint8_t *)base, (uint32_t)25660);
    DEVICE.PciClassCodeRevision.r32.installReadCallback(read_from_ram, &DEVICE_PciClassCodeRevision_r32);
    DEVICE.PciClassCodeRevision.r32.installWriteCallback(write_to_ram, &DEVICE_PciClassCodeRevision_r32);

    /** @brief Bitmap for @ref DEVICE_t.64c0. */
    static ram_offset_t DEVICE__64c0_r32((uint8_t *)base, (uint32_t)25792);
    DEVICE._64c0.r32.installReadCallback(read_from_ram, &DEVICE__64c0_r32);
    DEVICE._64c0.r32.installWriteCallback(write_to_ram, &DEVICE__64c0_r32);

    /** @brief Bitmap for @ref DEVICE_t.64c8. */
    static ram_offset_t DEVICE__64c8_r32((uint8_t *)base, (uint32_t)25800);
    DEVICE._64c8.r32.installReadCallback(read_from_ram, &DEVICE__64c8_r32);
    DEVICE._64c8.r32.installWriteCallback(write_to_ram, &DEVICE__64c8_r32);

    /** @brief Bitmap for @ref DEVICE_t.64dc. */
    static ram_offset_t DEVICE__64dc_r32((uint8_t *)base, (uint32_t)25820);
    DEVICE._64dc.r32.installReadCallback(read_from_ram, &DEVICE__64dc_r32);
    DEVICE._64dc.r32.installWriteCallback(write_to_ram, &DEVICE__64dc_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciSerialNumberLow. */
    static ram_offset_t DEVICE_PciSerialNumberLow_r32((uint8_t *)base, (uint32_t)25860);
    DEVICE.PciSerialNumberLow.r32.installReadCallback(read_from_ram, &DEVICE_PciSerialNumberLow_r32);
    DEVICE.PciSerialNumberLow.r32.installWriteCallback(write_to_ram, &DEVICE_PciSerialNumberLow_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciSerialNumberHigh. */
    static ram_offset_t DEVICE_PciSerialNumberHigh_r32((uint8_t *)base, (uint32_t)25864);
    DEVICE.PciSerialNumberHigh.r32.installReadCallback(read_from_ram, &DEVICE_PciSerialNumberHigh_r32);
    DEVICE.PciSerialNumberHigh.r32.installWriteCallback(write_to_ram, &DEVICE_PciSerialNumberHigh_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget0. */
    static ram_offset_t DEVICE_PciPowerBudget0_r32((uint8_t *)base, (uint32_t)25872);
    DEVICE.PciPowerBudget0.r32.installReadCallback(read_from_ram, &DEVICE_PciPowerBudget0_r32);
    DEVICE.PciPowerBudget0.r32.installWriteCallback(write_to_ram, &DEVICE_PciPowerBudget0_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget1. */
    static ram_offset_t DEVICE_PciPowerBudget1_r32((uint8_t *)base, (uint32_t)25876);
    DEVICE.PciPowerBudget1.r32.installReadCallback(read_from_ram, &DEVICE_PciPowerBudget1_r32);
    DEVICE.PciPowerBudget1.r32.installWriteCallback(write_to_ram, &DEVICE_PciPowerBudget1_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget2. */
    static ram_offset_t DEVICE_PciPowerBudget2_r32((uint8_t *)base, (uint32_t)25880);
    DEVICE.PciPowerBudget2.r32.installReadCallback(read_from_ram, &DEVICE_PciPowerBudget2_r32);
    DEVICE.PciPowerBudget2.r32.installWriteCallback(write_to_ram, &DEVICE_PciPowerBudget2_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget3. */
    static ram_offset_t DEVICE_PciPowerBudget3_r32((uint8_t *)base, (uint32_t)25884);
    DEVICE.PciPowerBudget3.r32.installReadCallback(read_from_ram, &DEVICE_PciPowerBudget3_r32);
    DEVICE.PciPowerBudget3.r32.installWriteCallback(write_to_ram, &DEVICE_PciPowerBudget3_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget4. */
    static ram_offset_t DEVICE_PciPowerBudget4_r32((uint8_t *)base, (uint32_t)25888);
    DEVICE.PciPowerBudget4.r32.installReadCallback(read_from_ram, &DEVICE_PciPowerBudget4_r32);
    DEVICE.PciPowerBudget4.r32.installWriteCallback(write_to_ram, &DEVICE_PciPowerBudget4_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget5. */
    static ram_offset_t DEVICE_PciPowerBudget5_r32((uint8_t *)base, (uint32_t)25892);
    DEVICE.PciPowerBudget5.r32.installReadCallback(read_from_ram, &DEVICE_PciPowerBudget5_r32);
    DEVICE.PciPowerBudget5.r32.installWriteCallback(write_to_ram, &DEVICE_PciPowerBudget5_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget6. */
    static ram_offset_t DEVICE_PciPowerBudget6_r32((uint8_t *)base, (uint32_t)25896);
    DEVICE.PciPowerBudget6.r32.installReadCallback(read_from_ram, &DEVICE_PciPowerBudget6_r32);
    DEVICE.PciPowerBudget6.r32.installWriteCallback(write_to_ram, &DEVICE_PciPowerBudget6_r32);

    /** @brief Bitmap for @ref DEVICE_t.PciPowerBudget7. */
    static ram_offset_t DEVICE_PciPowerBudget7_r32((uint8_t *)base, (uint32_t)25900);
    DEVICE.PciPowerBudget7.r32.installReadCallback(read_from_ram, &DEVICE_PciPowerBudget7_r32);
    DEVICE.PciPowerBudget7.r32.installWriteCallback(write_to_ram, &DEVICE_PciPowerBudget7_r32);

    /** @brief Bitmap for @ref DEVICE_t.6530. */
    static ram_offset_t DEVICE__6530_r32((uint8_t *)base, (uint32_t)25904);
    DEVICE._6530.r32.installReadCallback(read_from_ram, &DEVICE__6530_r32);
    DEVICE._6530.r32.installWriteCallback(write_to_ram, &DEVICE__6530_r32);

    /** @brief Bitmap for @ref DEVICE_t.6550. */
    static ram_offset_t DEVICE__6550_r32((uint8_t *)base, (uint32_t)25936);
    DEVICE._6550.r32.installReadCallback(read_from_ram, &DEVICE__6550_r32);
    DEVICE._6550.r32.installWriteCallback(write_to_ram, &DEVICE__6550_r32);

    /** @brief Bitmap for @ref DEVICE_t.65f4. */
    static ram_offset_t DEVICE__65f4_r32((uint8_t *)base, (uint32_t)26100);
    DEVICE._65f4.r32.installReadCallback(read_from_ram, &DEVICE__65f4_r32);
    DEVICE._65f4.r32.installWriteCallback(write_to_ram, &DEVICE__65f4_r32);

    /** @brief Bitmap for @ref DEVICE_t.GrcModeControl. */
    static ram_offset_t DEVICE_GrcModeControl_r32((uint8_t *)base, (uint32_t)26624);
    DEVICE.GrcModeControl.r32.installReadCallback(read_from_ram, &DEVICE_GrcModeControl_r32);
    DEVICE.GrcModeControl.r32.installWriteCallback(write_to_ram, &DEVICE_GrcModeControl_r32);

    /** @brief Bitmap for @ref DEVICE_t.MiscellaneousLocalControl. */
    static ram_offset_t DEVICE_MiscellaneousLocalControl_r32((uint8_t *)base, (uint32_t)26632);
    DEVICE.MiscellaneousLocalControl.r32.installReadCallback(read_from_ram, &DEVICE_MiscellaneousLocalControl_r32);
    DEVICE.MiscellaneousLocalControl.r32.installWriteCallback(write_to_ram, &DEVICE_MiscellaneousLocalControl_r32);

    /** @brief Bitmap for @ref DEVICE_t.Timer. */
    static ram_offset_t DEVICE_Timer_r32((uint8_t *)base, (uint32_t)26636);
    DEVICE.Timer.r32.installReadCallback(read_from_ram, &DEVICE_Timer_r32);
    DEVICE.Timer.r32.installWriteCallback(write_to_ram, &DEVICE_Timer_r32);

    /** @brief Bitmap for @ref DEVICE_t.RxCpuEvent. */
    static ram_offset_t DEVICE_RxCpuEvent_r32((uint8_t *)base, (uint32_t)26640);
    DEVICE.RxCpuEvent.r32.installReadCallback(read_from_ram, &DEVICE_RxCpuEvent_r32);
    DEVICE.RxCpuEvent.r32.installWriteCallback(write_to_ram, &DEVICE_RxCpuEvent_r32);

    /** @brief Bitmap for @ref DEVICE_t.6838. */
    static ram_offset_t DEVICE__6838_r32((uint8_t *)base, (uint32_t)26680);
    DEVICE._6838.r32.installReadCallback(read_from_ram, &DEVICE__6838_r32);
    DEVICE._6838.r32.installWriteCallback(write_to_ram, &DEVICE__6838_r32);

    /** @brief Bitmap for @ref DEVICE_t.MdiControl. */
    static ram_offset_t DEVICE_MdiControl_r32((uint8_t *)base, (uint32_t)26692);
    DEVICE.MdiControl.r32.installReadCallback(read_from_ram, &DEVICE_MdiControl_r32);
    DEVICE.MdiControl.r32.installWriteCallback(write_to_ram, &DEVICE_MdiControl_r32);

    /** @brief Bitmap for @ref DEVICE_t.FastBootProgramCounter. */
    static ram_offset_t DEVICE_FastBootProgramCounter_r32((uint8_t *)base, (uint32_t)26772);
    DEVICE.FastBootProgramCounter.r32.installReadCallback(read_from_ram, &DEVICE_FastBootProgramCounter_r32);
    DEVICE.FastBootProgramCounter.r32.installWriteCallback(write_to_ram, &DEVICE_FastBootProgramCounter_r32);

    /** @brief Bitmap for @ref DEVICE_t.ExpansionRomAddr. */
    static ram_offset_t DEVICE_ExpansionRomAddr_r32((uint8_t *)base, (uint32_t)26860);
    DEVICE.ExpansionRomAddr.r32.installReadCallback(read_from_ram, &DEVICE_ExpansionRomAddr_r32);
    DEVICE.ExpansionRomAddr.r32.installWriteCallback(write_to_ram, &DEVICE_ExpansionRomAddr_r32);

    /** @brief Bitmap for @ref DEVICE_t.68f0. */
    static ram_offset_t DEVICE__68f0_r32((uint8_t *)base, (uint32_t)26864);
    DEVICE._68f0.r32.installReadCallback(read_from_ram, &DEVICE__68f0_r32);
    DEVICE._68f0.r32.installWriteCallback(write_to_ram, &DEVICE__68f0_r32);

    /** @brief Bitmap for @ref DEVICE_t.EavRefClockControl. */
    static ram_offset_t DEVICE_EavRefClockControl_r32((uint8_t *)base, (uint32_t)26888);
    DEVICE.EavRefClockControl.r32.installReadCallback(read_from_ram, &DEVICE_EavRefClockControl_r32);
    DEVICE.EavRefClockControl.r32.installWriteCallback(write_to_ram, &DEVICE_EavRefClockControl_r32);

    /** @brief Bitmap for @ref DEVICE_t.7c04. */
    static ram_offset_t DEVICE__7c04_r32((uint8_t *)base, (uint32_t)31748);
    DEVICE._7c04.r32.installReadCallback(read_from_ram, &DEVICE__7c04_r32);
    DEVICE._7c04.r32.installWriteCallback(write_to_ram, &DEVICE__7c04_r32);


}
