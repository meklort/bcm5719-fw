////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_APE_mmap.cpp
///
/// @project    bcm5719
///
/// @brief      bcm5719_APE_mmap
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

void init_bcm5719_APE_mmap(void *base)
{
    /** @brief Component Registers for @ref APE. */
    /** @brief Bitmap for @ref APE_t.Mode. */
    static ram_offset_t APE_Mode_r32((uint8_t *)base, (uint32_t)0);
    APE.Mode.r32.installReadCallback(read_from_ram, &APE_Mode_r32);
    APE.Mode.r32.installWriteCallback(write_to_ram, &APE_Mode_r32);

    /** @brief Bitmap for @ref APE_t.Status. */
    static ram_offset_t APE_Status_r32((uint8_t *)base, (uint32_t)4);
    APE.Status.r32.installReadCallback(read_from_ram, &APE_Status_r32);
    APE.Status.r32.installWriteCallback(write_to_ram, &APE_Status_r32);

    /** @brief Bitmap for @ref APE_t.GpioMessage. */
    static ram_offset_t APE_GpioMessage_r32((uint8_t *)base, (uint32_t)8);
    APE.GpioMessage.r32.installReadCallback(read_from_ram, &APE_GpioMessage_r32);
    APE.GpioMessage.r32.installWriteCallback(write_to_ram, &APE_GpioMessage_r32);

    /** @brief Bitmap for @ref APE_t.Event. */
    static ram_offset_t APE_Event_r32((uint8_t *)base, (uint32_t)12);
    APE.Event.r32.installReadCallback(read_from_ram, &APE_Event_r32);
    APE.Event.r32.installWriteCallback(write_to_ram, &APE_Event_r32);

    /** @brief Bitmap for @ref APE_t.Mode2. */
    static ram_offset_t APE_Mode2_r32((uint8_t *)base, (uint32_t)44);
    APE.Mode2.r32.installReadCallback(read_from_ram, &APE_Mode2_r32);
    APE.Mode2.r32.installWriteCallback(write_to_ram, &APE_Mode2_r32);

    /** @brief Bitmap for @ref APE_t.Status2. */
    static ram_offset_t APE_Status2_r32((uint8_t *)base, (uint32_t)48);
    APE.Status2.r32.installReadCallback(read_from_ram, &APE_Status2_r32);
    APE.Status2.r32.installWriteCallback(write_to_ram, &APE_Status2_r32);

    /** @brief Bitmap for @ref APE_t.LockGrantObsolete. */
    static ram_offset_t APE_LockGrantObsolete_r32((uint8_t *)base, (uint32_t)76);
    APE.LockGrantObsolete.r32.installReadCallback(read_from_ram, &APE_LockGrantObsolete_r32);
    APE.LockGrantObsolete.r32.installWriteCallback(write_to_ram, &APE_LockGrantObsolete_r32);

    /** @brief Bitmap for @ref APE_t.B0. */
    static ram_offset_t APE_B0_r32((uint8_t *)base, (uint32_t)176);
    APE.B0.r32.installReadCallback(read_from_ram, &APE_B0_r32);
    APE.B0.r32.installWriteCallback(write_to_ram, &APE_B0_r32);

    /** @brief Bitmap for @ref APE_t.Gpio. */
    static ram_offset_t APE_Gpio_r32((uint8_t *)base, (uint32_t)184);
    APE.Gpio.r32.installReadCallback(read_from_ram, &APE_Gpio_r32);
    APE.Gpio.r32.installWriteCallback(write_to_ram, &APE_Gpio_r32);

    /** @brief Bitmap for @ref APE_t.Gint. */
    static ram_offset_t APE_Gint_r32((uint8_t *)base, (uint32_t)188);
    APE.Gint.r32.installReadCallback(read_from_ram, &APE_Gint_r32);
    APE.Gint.r32.installWriteCallback(write_to_ram, &APE_Gint_r32);

    /** @brief Bitmap for @ref APE_t.OtpControl. */
    static ram_offset_t APE_OtpControl_r32((uint8_t *)base, (uint32_t)232);
    APE.OtpControl.r32.installReadCallback(read_from_ram, &APE_OtpControl_r32);
    APE.OtpControl.r32.installWriteCallback(write_to_ram, &APE_OtpControl_r32);

    /** @brief Bitmap for @ref APE_t.OtpStatus. */
    static ram_offset_t APE_OtpStatus_r32((uint8_t *)base, (uint32_t)236);
    APE.OtpStatus.r32.installReadCallback(read_from_ram, &APE_OtpStatus_r32);
    APE.OtpStatus.r32.installWriteCallback(write_to_ram, &APE_OtpStatus_r32);

    /** @brief Bitmap for @ref APE_t.OtpAddr. */
    static ram_offset_t APE_OtpAddr_r32((uint8_t *)base, (uint32_t)240);
    APE.OtpAddr.r32.installReadCallback(read_from_ram, &APE_OtpAddr_r32);
    APE.OtpAddr.r32.installWriteCallback(write_to_ram, &APE_OtpAddr_r32);

    /** @brief Bitmap for @ref APE_t.OtpReadData. */
    static ram_offset_t APE_OtpReadData_r32((uint8_t *)base, (uint32_t)248);
    APE.OtpReadData.r32.installReadCallback(read_from_ram, &APE_OtpReadData_r32);
    APE.OtpReadData.r32.installWriteCallback(write_to_ram, &APE_OtpReadData_r32);

    /** @brief Bitmap for @ref APE_t.Cm3. */
    static ram_offset_t APE_Cm3_r32((uint8_t *)base, (uint32_t)264);
    APE.Cm3.r32.installReadCallback(read_from_ram, &APE_Cm3_r32);
    APE.Cm3.r32.installWriteCallback(write_to_ram, &APE_Cm3_r32);

    /** @brief Bitmap for @ref APE_t.SegSig. */
    static ram_offset_t APE_SegSig_r32((uint8_t *)base, (uint32_t)16384);
    APE.SegSig.r32.installReadCallback(read_from_ram, &APE_SegSig_r32);
    APE.SegSig.r32.installWriteCallback(write_to_ram, &APE_SegSig_r32);

    /** @brief Bitmap for @ref APE_t.FwStatus. */
    static ram_offset_t APE_FwStatus_r32((uint8_t *)base, (uint32_t)16396);
    APE.FwStatus.r32.installReadCallback(read_from_ram, &APE_FwStatus_r32);
    APE.FwStatus.r32.installWriteCallback(write_to_ram, &APE_FwStatus_r32);

    /** @brief Bitmap for @ref APE_t.FwFeatures. */
    static ram_offset_t APE_FwFeatures_r32((uint8_t *)base, (uint32_t)16400);
    APE.FwFeatures.r32.installReadCallback(read_from_ram, &APE_FwFeatures_r32);
    APE.FwFeatures.r32.installWriteCallback(write_to_ram, &APE_FwFeatures_r32);

    /** @brief Bitmap for @ref APE_t.4014. */
    static ram_offset_t APE__4014_r32((uint8_t *)base, (uint32_t)16404);
    APE._4014.r32.installReadCallback(read_from_ram, &APE__4014_r32);
    APE._4014.r32.installWriteCallback(write_to_ram, &APE__4014_r32);

    /** @brief Bitmap for @ref APE_t.FwVersion. */
    static ram_offset_t APE_FwVersion_r32((uint8_t *)base, (uint32_t)16408);
    APE.FwVersion.r32.installReadCallback(read_from_ram, &APE_FwVersion_r32);
    APE.FwVersion.r32.installWriteCallback(write_to_ram, &APE_FwVersion_r32);

    /** @brief Bitmap for @ref APE_t.SegMessageBufferOffset. */
    static ram_offset_t APE_SegMessageBufferOffset_r32((uint8_t *)base, (uint32_t)16412);
    APE.SegMessageBufferOffset.r32.installReadCallback(read_from_ram, &APE_SegMessageBufferOffset_r32);
    APE.SegMessageBufferOffset.r32.installWriteCallback(write_to_ram, &APE_SegMessageBufferOffset_r32);

    /** @brief Bitmap for @ref APE_t.SegMessageBufferLength. */
    static ram_offset_t APE_SegMessageBufferLength_r32((uint8_t *)base, (uint32_t)16416);
    APE.SegMessageBufferLength.r32.installReadCallback(read_from_ram, &APE_SegMessageBufferLength_r32);
    APE.SegMessageBufferLength.r32.installWriteCallback(write_to_ram, &APE_SegMessageBufferLength_r32);

    /** @brief Bitmap for @ref APE_t.4024. */
    static ram_offset_t APE__4024_r32((uint8_t *)base, (uint32_t)16420);
    APE._4024.r32.installReadCallback(read_from_ram, &APE__4024_r32);
    APE._4024.r32.installWriteCallback(write_to_ram, &APE__4024_r32);

    /** @brief Bitmap for @ref APE_t.4028. */
    static ram_offset_t APE__4028_r32((uint8_t *)base, (uint32_t)16424);
    APE._4028.r32.installReadCallback(read_from_ram, &APE__4028_r32);
    APE._4028.r32.installWriteCallback(write_to_ram, &APE__4028_r32);

    /** @brief Bitmap for @ref APE_t.RcpuSegSig. */
    static ram_offset_t APE_RcpuSegSig_r32((uint8_t *)base, (uint32_t)16640);
    APE.RcpuSegSig.r32.installReadCallback(read_from_ram, &APE_RcpuSegSig_r32);
    APE.RcpuSegSig.r32.installWriteCallback(write_to_ram, &APE_RcpuSegSig_r32);

    /** @brief Bitmap for @ref APE_t.RcpuSegLength. */
    static ram_offset_t APE_RcpuSegLength_r32((uint8_t *)base, (uint32_t)16644);
    APE.RcpuSegLength.r32.installReadCallback(read_from_ram, &APE_RcpuSegLength_r32);
    APE.RcpuSegLength.r32.installWriteCallback(write_to_ram, &APE_RcpuSegLength_r32);

    /** @brief Bitmap for @ref APE_t.RcpuInitCount. */
    static ram_offset_t APE_RcpuInitCount_r32((uint8_t *)base, (uint32_t)16648);
    APE.RcpuInitCount.r32.installReadCallback(read_from_ram, &APE_RcpuInitCount_r32);
    APE.RcpuInitCount.r32.installWriteCallback(write_to_ram, &APE_RcpuInitCount_r32);

    /** @brief Bitmap for @ref APE_t.RcpuFwVersion. */
    static ram_offset_t APE_RcpuFwVersion_r32((uint8_t *)base, (uint32_t)16652);
    APE.RcpuFwVersion.r32.installReadCallback(read_from_ram, &APE_RcpuFwVersion_r32);
    APE.RcpuFwVersion.r32.installWriteCallback(write_to_ram, &APE_RcpuFwVersion_r32);

    /** @brief Bitmap for @ref APE_t.RcpuCfgFeature. */
    static ram_offset_t APE_RcpuCfgFeature_r32((uint8_t *)base, (uint32_t)16656);
    APE.RcpuCfgFeature.r32.installReadCallback(read_from_ram, &APE_RcpuCfgFeature_r32);
    APE.RcpuCfgFeature.r32.installWriteCallback(write_to_ram, &APE_RcpuCfgFeature_r32);

    /** @brief Bitmap for @ref APE_t.RcpuPciVendorDeviceId. */
    static ram_offset_t APE_RcpuPciVendorDeviceId_r32((uint8_t *)base, (uint32_t)16660);
    APE.RcpuPciVendorDeviceId.r32.installReadCallback(read_from_ram, &APE_RcpuPciVendorDeviceId_r32);
    APE.RcpuPciVendorDeviceId.r32.installWriteCallback(write_to_ram, &APE_RcpuPciVendorDeviceId_r32);

    /** @brief Bitmap for @ref APE_t.RcpuPciSubsystemId. */
    static ram_offset_t APE_RcpuPciSubsystemId_r32((uint8_t *)base, (uint32_t)16664);
    APE.RcpuPciSubsystemId.r32.installReadCallback(read_from_ram, &APE_RcpuPciSubsystemId_r32);
    APE.RcpuPciSubsystemId.r32.installWriteCallback(write_to_ram, &APE_RcpuPciSubsystemId_r32);

    /** @brief Bitmap for @ref APE_t.411c. */
    static ram_offset_t APE__411c_r32((uint8_t *)base, (uint32_t)16668);
    APE._411c.r32.installReadCallback(read_from_ram, &APE__411c_r32);
    APE._411c.r32.installWriteCallback(write_to_ram, &APE__411c_r32);

    /** @brief Bitmap for @ref APE_t.4120. */
    static ram_offset_t APE__4120_r32((uint8_t *)base, (uint32_t)16672);
    APE._4120.r32.installReadCallback(read_from_ram, &APE__4120_r32);
    APE._4120.r32.installWriteCallback(write_to_ram, &APE__4120_r32);

    /** @brief Bitmap for @ref APE_t.4124. */
    static ram_offset_t APE__4124_r32((uint8_t *)base, (uint32_t)16676);
    APE._4124.r32.installReadCallback(read_from_ram, &APE__4124_r32);
    APE._4124.r32.installWriteCallback(write_to_ram, &APE__4124_r32);

    /** @brief Bitmap for @ref APE_t.RcpuCfgHw. */
    static ram_offset_t APE_RcpuCfgHw_r32((uint8_t *)base, (uint32_t)16680);
    APE.RcpuCfgHw.r32.installReadCallback(read_from_ram, &APE_RcpuCfgHw_r32);
    APE.RcpuCfgHw.r32.installWriteCallback(write_to_ram, &APE_RcpuCfgHw_r32);

    /** @brief Bitmap for @ref APE_t.RcpuCfgHw2. */
    static ram_offset_t APE_RcpuCfgHw2_r32((uint8_t *)base, (uint32_t)16684);
    APE.RcpuCfgHw2.r32.installReadCallback(read_from_ram, &APE_RcpuCfgHw2_r32);
    APE.RcpuCfgHw2.r32.installWriteCallback(write_to_ram, &APE_RcpuCfgHw2_r32);

    /** @brief Bitmap for @ref APE_t.RcpuCpmuStatus. */
    static ram_offset_t APE_RcpuCpmuStatus_r32((uint8_t *)base, (uint32_t)16688);
    APE.RcpuCpmuStatus.r32.installReadCallback(read_from_ram, &APE_RcpuCpmuStatus_r32);
    APE.RcpuCpmuStatus.r32.installWriteCallback(write_to_ram, &APE_RcpuCpmuStatus_r32);

    /** @brief Bitmap for @ref APE_t.HostSegSig. */
    static ram_offset_t APE_HostSegSig_r32((uint8_t *)base, (uint32_t)16896);
    APE.HostSegSig.r32.installReadCallback(read_from_ram, &APE_HostSegSig_r32);
    APE.HostSegSig.r32.installWriteCallback(write_to_ram, &APE_HostSegSig_r32);

    /** @brief Bitmap for @ref APE_t.HostSegLen. */
    static ram_offset_t APE_HostSegLen_r32((uint8_t *)base, (uint32_t)16900);
    APE.HostSegLen.r32.installReadCallback(read_from_ram, &APE_HostSegLen_r32);
    APE.HostSegLen.r32.installWriteCallback(write_to_ram, &APE_HostSegLen_r32);

    /** @brief Bitmap for @ref APE_t.HostInitCount. */
    static ram_offset_t APE_HostInitCount_r32((uint8_t *)base, (uint32_t)16904);
    APE.HostInitCount.r32.installReadCallback(read_from_ram, &APE_HostInitCount_r32);
    APE.HostInitCount.r32.installWriteCallback(write_to_ram, &APE_HostInitCount_r32);

    /** @brief Bitmap for @ref APE_t.HostDriverId. */
    static ram_offset_t APE_HostDriverId_r32((uint8_t *)base, (uint32_t)16908);
    APE.HostDriverId.r32.installReadCallback(read_from_ram, &APE_HostDriverId_r32);
    APE.HostDriverId.r32.installWriteCallback(write_to_ram, &APE_HostDriverId_r32);

    /** @brief Bitmap for @ref APE_t.HostBehavior. */
    static ram_offset_t APE_HostBehavior_r32((uint8_t *)base, (uint32_t)16912);
    APE.HostBehavior.r32.installReadCallback(read_from_ram, &APE_HostBehavior_r32);
    APE.HostBehavior.r32.installWriteCallback(write_to_ram, &APE_HostBehavior_r32);

    /** @brief Bitmap for @ref APE_t.HeartbeatInterval. */
    static ram_offset_t APE_HeartbeatInterval_r32((uint8_t *)base, (uint32_t)16916);
    APE.HeartbeatInterval.r32.installReadCallback(read_from_ram, &APE_HeartbeatInterval_r32);
    APE.HeartbeatInterval.r32.installWriteCallback(write_to_ram, &APE_HeartbeatInterval_r32);

    /** @brief Bitmap for @ref APE_t.HeartbeatCount. */
    static ram_offset_t APE_HeartbeatCount_r32((uint8_t *)base, (uint32_t)16920);
    APE.HeartbeatCount.r32.installReadCallback(read_from_ram, &APE_HeartbeatCount_r32);
    APE.HeartbeatCount.r32.installWriteCallback(write_to_ram, &APE_HeartbeatCount_r32);

    /** @brief Bitmap for @ref APE_t.HostDriverState. */
    static ram_offset_t APE_HostDriverState_r32((uint8_t *)base, (uint32_t)16924);
    APE.HostDriverState.r32.installReadCallback(read_from_ram, &APE_HostDriverState_r32);
    APE.HostDriverState.r32.installWriteCallback(write_to_ram, &APE_HostDriverState_r32);

    /** @brief Bitmap for @ref APE_t.WolSpeed. */
    static ram_offset_t APE_WolSpeed_r32((uint8_t *)base, (uint32_t)16932);
    APE.WolSpeed.r32.installReadCallback(read_from_ram, &APE_WolSpeed_r32);
    APE.WolSpeed.r32.installWriteCallback(write_to_ram, &APE_WolSpeed_r32);

    /** @brief Bitmap for @ref APE_t.EventStatus. */
    static ram_offset_t APE_EventStatus_r32((uint8_t *)base, (uint32_t)17152);
    APE.EventStatus.r32.installReadCallback(read_from_ram, &APE_EventStatus_r32);
    APE.EventStatus.r32.installWriteCallback(write_to_ram, &APE_EventStatus_r32);

    /** @brief Bitmap for @ref APE_t.ProtMagic. */
    static ram_offset_t APE_ProtMagic_r32((uint8_t *)base, (uint32_t)17160);
    APE.ProtMagic.r32.installReadCallback(read_from_ram, &APE_ProtMagic_r32);
    APE.ProtMagic.r32.installWriteCallback(write_to_ram, &APE_ProtMagic_r32);

    /** @brief Bitmap for @ref APE_t.ProtMac0High. */
    static ram_offset_t APE_ProtMac0High_r32((uint8_t *)base, (uint32_t)17172);
    APE.ProtMac0High.r32.installReadCallback(read_from_ram, &APE_ProtMac0High_r32);
    APE.ProtMac0High.r32.installWriteCallback(write_to_ram, &APE_ProtMac0High_r32);

    /** @brief Bitmap for @ref APE_t.ProtMac0Low. */
    static ram_offset_t APE_ProtMac0Low_r32((uint8_t *)base, (uint32_t)17176);
    APE.ProtMac0Low.r32.installReadCallback(read_from_ram, &APE_ProtMac0Low_r32);
    APE.ProtMac0Low.r32.installWriteCallback(write_to_ram, &APE_ProtMac0Low_r32);

    /** @brief Bitmap for @ref APE_t.NcsiSig. */
    static ram_offset_t APE_NcsiSig_r32((uint8_t *)base, (uint32_t)18432);
    APE.NcsiSig.r32.installReadCallback(read_from_ram, &APE_NcsiSig_r32);
    APE.NcsiSig.r32.installWriteCallback(write_to_ram, &APE_NcsiSig_r32);

    /** @brief Bitmap for @ref APE_t.NcsiBuildTime. */
    static ram_offset_t APE_NcsiBuildTime_r32((uint8_t *)base, (uint32_t)18448);
    APE.NcsiBuildTime.r32.installReadCallback(read_from_ram, &APE_NcsiBuildTime_r32);
    APE.NcsiBuildTime.r32.installWriteCallback(write_to_ram, &APE_NcsiBuildTime_r32);

    /** @brief Bitmap for @ref APE_t.NcsiBuildTime2. */
    static ram_offset_t APE_NcsiBuildTime2_r32((uint8_t *)base, (uint32_t)18452);
    APE.NcsiBuildTime2.r32.installReadCallback(read_from_ram, &APE_NcsiBuildTime2_r32);
    APE.NcsiBuildTime2.r32.installWriteCallback(write_to_ram, &APE_NcsiBuildTime2_r32);

    /** @brief Bitmap for @ref APE_t.NcsiBuildTime3. */
    static ram_offset_t APE_NcsiBuildTime3_r32((uint8_t *)base, (uint32_t)18456);
    APE.NcsiBuildTime3.r32.installReadCallback(read_from_ram, &APE_NcsiBuildTime3_r32);
    APE.NcsiBuildTime3.r32.installWriteCallback(write_to_ram, &APE_NcsiBuildTime3_r32);

    /** @brief Bitmap for @ref APE_t.NcsiBuildDate. */
    static ram_offset_t APE_NcsiBuildDate_r32((uint8_t *)base, (uint32_t)18460);
    APE.NcsiBuildDate.r32.installReadCallback(read_from_ram, &APE_NcsiBuildDate_r32);
    APE.NcsiBuildDate.r32.installWriteCallback(write_to_ram, &APE_NcsiBuildDate_r32);

    /** @brief Bitmap for @ref APE_t.NcsiBuildDate2. */
    static ram_offset_t APE_NcsiBuildDate2_r32((uint8_t *)base, (uint32_t)18464);
    APE.NcsiBuildDate2.r32.installReadCallback(read_from_ram, &APE_NcsiBuildDate2_r32);
    APE.NcsiBuildDate2.r32.installWriteCallback(write_to_ram, &APE_NcsiBuildDate2_r32);

    /** @brief Bitmap for @ref APE_t.NcsiBuildDate3. */
    static ram_offset_t APE_NcsiBuildDate3_r32((uint8_t *)base, (uint32_t)18468);
    APE.NcsiBuildDate3.r32.installReadCallback(read_from_ram, &APE_NcsiBuildDate3_r32);
    APE.NcsiBuildDate3.r32.installWriteCallback(write_to_ram, &APE_NcsiBuildDate3_r32);

    /** @brief Bitmap for @ref APE_t.ChipId. */
    static ram_offset_t APE_ChipId_r32((uint8_t *)base, (uint32_t)18576);
    APE.ChipId.r32.installReadCallback(read_from_ram, &APE_ChipId_r32);
    APE.ChipId.r32.installWriteCallback(write_to_ram, &APE_ChipId_r32);

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy0. */
    static ram_offset_t APE_PerLockRequestPhy0_r32((uint8_t *)base, (uint32_t)33792);
    APE.PerLockRequestPhy0.r32.installReadCallback(read_from_ram, &APE_PerLockRequestPhy0_r32);
    APE.PerLockRequestPhy0.r32.installWriteCallback(write_to_ram, &APE_PerLockRequestPhy0_r32);

    /** @brief Bitmap for @ref APE_t.PerLockRequestGrc. */
    static ram_offset_t APE_PerLockRequestGrc_r32((uint8_t *)base, (uint32_t)33796);
    APE.PerLockRequestGrc.r32.installReadCallback(read_from_ram, &APE_PerLockRequestGrc_r32);
    APE.PerLockRequestGrc.r32.installWriteCallback(write_to_ram, &APE_PerLockRequestGrc_r32);

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy1. */
    static ram_offset_t APE_PerLockRequestPhy1_r32((uint8_t *)base, (uint32_t)33800);
    APE.PerLockRequestPhy1.r32.installReadCallback(read_from_ram, &APE_PerLockRequestPhy1_r32);
    APE.PerLockRequestPhy1.r32.installWriteCallback(write_to_ram, &APE_PerLockRequestPhy1_r32);

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy2. */
    static ram_offset_t APE_PerLockRequestPhy2_r32((uint8_t *)base, (uint32_t)33804);
    APE.PerLockRequestPhy2.r32.installReadCallback(read_from_ram, &APE_PerLockRequestPhy2_r32);
    APE.PerLockRequestPhy2.r32.installWriteCallback(write_to_ram, &APE_PerLockRequestPhy2_r32);

    /** @brief Bitmap for @ref APE_t.PerLockRequestMem. */
    static ram_offset_t APE_PerLockRequestMem_r32((uint8_t *)base, (uint32_t)33808);
    APE.PerLockRequestMem.r32.installReadCallback(read_from_ram, &APE_PerLockRequestMem_r32);
    APE.PerLockRequestMem.r32.installWriteCallback(write_to_ram, &APE_PerLockRequestMem_r32);

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy3. */
    static ram_offset_t APE_PerLockRequestPhy3_r32((uint8_t *)base, (uint32_t)33812);
    APE.PerLockRequestPhy3.r32.installReadCallback(read_from_ram, &APE_PerLockRequestPhy3_r32);
    APE.PerLockRequestPhy3.r32.installWriteCallback(write_to_ram, &APE_PerLockRequestPhy3_r32);

    /** @brief Bitmap for @ref APE_t.PerLockRequestPort6. */
    static ram_offset_t APE_PerLockRequestPort6_r32((uint8_t *)base, (uint32_t)33816);
    APE.PerLockRequestPort6.r32.installReadCallback(read_from_ram, &APE_PerLockRequestPort6_r32);
    APE.PerLockRequestPort6.r32.installWriteCallback(write_to_ram, &APE_PerLockRequestPort6_r32);

    /** @brief Bitmap for @ref APE_t.PerLockRequestGpio. */
    static ram_offset_t APE_PerLockRequestGpio_r32((uint8_t *)base, (uint32_t)33820);
    APE.PerLockRequestGpio.r32.installReadCallback(read_from_ram, &APE_PerLockRequestGpio_r32);
    APE.PerLockRequestGpio.r32.installWriteCallback(write_to_ram, &APE_PerLockRequestGpio_r32);

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy0. */
    static ram_offset_t APE_PerLockGrantPhy0_r32((uint8_t *)base, (uint32_t)33824);
    APE.PerLockGrantPhy0.r32.installReadCallback(read_from_ram, &APE_PerLockGrantPhy0_r32);
    APE.PerLockGrantPhy0.r32.installWriteCallback(write_to_ram, &APE_PerLockGrantPhy0_r32);

    /** @brief Bitmap for @ref APE_t.PerLockGrantGrc. */
    static ram_offset_t APE_PerLockGrantGrc_r32((uint8_t *)base, (uint32_t)33828);
    APE.PerLockGrantGrc.r32.installReadCallback(read_from_ram, &APE_PerLockGrantGrc_r32);
    APE.PerLockGrantGrc.r32.installWriteCallback(write_to_ram, &APE_PerLockGrantGrc_r32);

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy1. */
    static ram_offset_t APE_PerLockGrantPhy1_r32((uint8_t *)base, (uint32_t)33832);
    APE.PerLockGrantPhy1.r32.installReadCallback(read_from_ram, &APE_PerLockGrantPhy1_r32);
    APE.PerLockGrantPhy1.r32.installWriteCallback(write_to_ram, &APE_PerLockGrantPhy1_r32);

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy2. */
    static ram_offset_t APE_PerLockGrantPhy2_r32((uint8_t *)base, (uint32_t)33836);
    APE.PerLockGrantPhy2.r32.installReadCallback(read_from_ram, &APE_PerLockGrantPhy2_r32);
    APE.PerLockGrantPhy2.r32.installWriteCallback(write_to_ram, &APE_PerLockGrantPhy2_r32);

    /** @brief Bitmap for @ref APE_t.PerLockGrantMem. */
    static ram_offset_t APE_PerLockGrantMem_r32((uint8_t *)base, (uint32_t)33840);
    APE.PerLockGrantMem.r32.installReadCallback(read_from_ram, &APE_PerLockGrantMem_r32);
    APE.PerLockGrantMem.r32.installWriteCallback(write_to_ram, &APE_PerLockGrantMem_r32);

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy3. */
    static ram_offset_t APE_PerLockGrantPhy3_r32((uint8_t *)base, (uint32_t)33844);
    APE.PerLockGrantPhy3.r32.installReadCallback(read_from_ram, &APE_PerLockGrantPhy3_r32);
    APE.PerLockGrantPhy3.r32.installWriteCallback(write_to_ram, &APE_PerLockGrantPhy3_r32);

    /** @brief Bitmap for @ref APE_t.PerLockGrantPort6. */
    static ram_offset_t APE_PerLockGrantPort6_r32((uint8_t *)base, (uint32_t)33848);
    APE.PerLockGrantPort6.r32.installReadCallback(read_from_ram, &APE_PerLockGrantPort6_r32);
    APE.PerLockGrantPort6.r32.installWriteCallback(write_to_ram, &APE_PerLockGrantPort6_r32);

    /** @brief Bitmap for @ref APE_t.PerLockGrantGpio. */
    static ram_offset_t APE_PerLockGrantGpio_r32((uint8_t *)base, (uint32_t)33852);
    APE.PerLockGrantGpio.r32.installReadCallback(read_from_ram, &APE_PerLockGrantGpio_r32);
    APE.PerLockGrantGpio.r32.installWriteCallback(write_to_ram, &APE_PerLockGrantGpio_r32);


}
