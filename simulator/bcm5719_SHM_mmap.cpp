////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_SHM_mmap.cpp
///
/// @project    bcm5719
///
/// @brief      bcm5719_SHM_mmap
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

static uint32_t read_from_ram_index(uint32_t index, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += index;

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

static void write_to_ram_index(uint32_t index, uint32_t val, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += index;

    BARRIER();
    *(uint32_t *)base = val;
    BARRIER();
}

void init_bcm5719_SHM_mmap(void *base)
{
    SHM.mIndexReadCallback = read_from_ram_index;
    SHM.mIndexReadCallbackArgs = base;

    SHM.mIndexWriteCallback = write_to_ram_index;
    SHM.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref SHM. */
    /** @brief Bitmap for @ref SHM_t.SegSig. */
    static ram_offset_t SHM_SegSig_r32((uint8_t *)base, (uint32_t)0);
    SHM.SegSig.r32.installReadCallback(read_from_ram, &SHM_SegSig_r32);
    SHM.SegSig.r32.installWriteCallback(write_to_ram, &SHM_SegSig_r32);

    /** @brief Bitmap for @ref SHM_t.FwStatus. */
    static ram_offset_t SHM_FwStatus_r32((uint8_t *)base, (uint32_t)12);
    SHM.FwStatus.r32.installReadCallback(read_from_ram, &SHM_FwStatus_r32);
    SHM.FwStatus.r32.installWriteCallback(write_to_ram, &SHM_FwStatus_r32);

    /** @brief Bitmap for @ref SHM_t.FwFeatures. */
    static ram_offset_t SHM_FwFeatures_r32((uint8_t *)base, (uint32_t)16);
    SHM.FwFeatures.r32.installReadCallback(read_from_ram, &SHM_FwFeatures_r32);
    SHM.FwFeatures.r32.installWriteCallback(write_to_ram, &SHM_FwFeatures_r32);

    /** @brief Bitmap for @ref SHM_t.4014. */
    static ram_offset_t SHM__4014_r32((uint8_t *)base, (uint32_t)20);
    SHM._4014.r32.installReadCallback(read_from_ram, &SHM__4014_r32);
    SHM._4014.r32.installWriteCallback(write_to_ram, &SHM__4014_r32);

    /** @brief Bitmap for @ref SHM_t.FwVersion. */
    static ram_offset_t SHM_FwVersion_r32((uint8_t *)base, (uint32_t)24);
    SHM.FwVersion.r32.installReadCallback(read_from_ram, &SHM_FwVersion_r32);
    SHM.FwVersion.r32.installWriteCallback(write_to_ram, &SHM_FwVersion_r32);

    /** @brief Bitmap for @ref SHM_t.SegMessageBufferOffset. */
    static ram_offset_t SHM_SegMessageBufferOffset_r32((uint8_t *)base, (uint32_t)28);
    SHM.SegMessageBufferOffset.r32.installReadCallback(read_from_ram, &SHM_SegMessageBufferOffset_r32);
    SHM.SegMessageBufferOffset.r32.installWriteCallback(write_to_ram, &SHM_SegMessageBufferOffset_r32);

    /** @brief Bitmap for @ref SHM_t.SegMessageBufferLength. */
    static ram_offset_t SHM_SegMessageBufferLength_r32((uint8_t *)base, (uint32_t)32);
    SHM.SegMessageBufferLength.r32.installReadCallback(read_from_ram, &SHM_SegMessageBufferLength_r32);
    SHM.SegMessageBufferLength.r32.installWriteCallback(write_to_ram, &SHM_SegMessageBufferLength_r32);

    /** @brief Bitmap for @ref SHM_t.4024. */
    static ram_offset_t SHM__4024_r32((uint8_t *)base, (uint32_t)36);
    SHM._4024.r32.installReadCallback(read_from_ram, &SHM__4024_r32);
    SHM._4024.r32.installWriteCallback(write_to_ram, &SHM__4024_r32);

    /** @brief Bitmap for @ref SHM_t.4028. */
    static ram_offset_t SHM__4028_r32((uint8_t *)base, (uint32_t)40);
    SHM._4028.r32.installReadCallback(read_from_ram, &SHM__4028_r32);
    SHM._4028.r32.installWriteCallback(write_to_ram, &SHM__4028_r32);

    /** @brief Bitmap for @ref SHM_t.RcpuSegSig. */
    static ram_offset_t SHM_RcpuSegSig_r32((uint8_t *)base, (uint32_t)256);
    SHM.RcpuSegSig.r32.installReadCallback(read_from_ram, &SHM_RcpuSegSig_r32);
    SHM.RcpuSegSig.r32.installWriteCallback(write_to_ram, &SHM_RcpuSegSig_r32);

    /** @brief Bitmap for @ref SHM_t.RcpuSegLength. */
    static ram_offset_t SHM_RcpuSegLength_r32((uint8_t *)base, (uint32_t)260);
    SHM.RcpuSegLength.r32.installReadCallback(read_from_ram, &SHM_RcpuSegLength_r32);
    SHM.RcpuSegLength.r32.installWriteCallback(write_to_ram, &SHM_RcpuSegLength_r32);

    /** @brief Bitmap for @ref SHM_t.RcpuInitCount. */
    static ram_offset_t SHM_RcpuInitCount_r32((uint8_t *)base, (uint32_t)264);
    SHM.RcpuInitCount.r32.installReadCallback(read_from_ram, &SHM_RcpuInitCount_r32);
    SHM.RcpuInitCount.r32.installWriteCallback(write_to_ram, &SHM_RcpuInitCount_r32);

    /** @brief Bitmap for @ref SHM_t.RcpuFwVersion. */
    static ram_offset_t SHM_RcpuFwVersion_r32((uint8_t *)base, (uint32_t)268);
    SHM.RcpuFwVersion.r32.installReadCallback(read_from_ram, &SHM_RcpuFwVersion_r32);
    SHM.RcpuFwVersion.r32.installWriteCallback(write_to_ram, &SHM_RcpuFwVersion_r32);

    /** @brief Bitmap for @ref SHM_t.RcpuCfgFeature. */
    static ram_offset_t SHM_RcpuCfgFeature_r32((uint8_t *)base, (uint32_t)272);
    SHM.RcpuCfgFeature.r32.installReadCallback(read_from_ram, &SHM_RcpuCfgFeature_r32);
    SHM.RcpuCfgFeature.r32.installWriteCallback(write_to_ram, &SHM_RcpuCfgFeature_r32);

    /** @brief Bitmap for @ref SHM_t.RcpuPciVendorDeviceId. */
    static ram_offset_t SHM_RcpuPciVendorDeviceId_r32((uint8_t *)base, (uint32_t)276);
    SHM.RcpuPciVendorDeviceId.r32.installReadCallback(read_from_ram, &SHM_RcpuPciVendorDeviceId_r32);
    SHM.RcpuPciVendorDeviceId.r32.installWriteCallback(write_to_ram, &SHM_RcpuPciVendorDeviceId_r32);

    /** @brief Bitmap for @ref SHM_t.RcpuPciSubsystemId. */
    static ram_offset_t SHM_RcpuPciSubsystemId_r32((uint8_t *)base, (uint32_t)280);
    SHM.RcpuPciSubsystemId.r32.installReadCallback(read_from_ram, &SHM_RcpuPciSubsystemId_r32);
    SHM.RcpuPciSubsystemId.r32.installWriteCallback(write_to_ram, &SHM_RcpuPciSubsystemId_r32);

    /** @brief Bitmap for @ref SHM_t.RcpuApeResetCount. */
    static ram_offset_t SHM_RcpuApeResetCount_r32((uint8_t *)base, (uint32_t)284);
    SHM.RcpuApeResetCount.r32.installReadCallback(read_from_ram, &SHM_RcpuApeResetCount_r32);
    SHM.RcpuApeResetCount.r32.installWriteCallback(write_to_ram, &SHM_RcpuApeResetCount_r32);

    /** @brief Bitmap for @ref SHM_t.RcpuLastApeStatus. */
    static ram_offset_t SHM_RcpuLastApeStatus_r32((uint8_t *)base, (uint32_t)288);
    SHM.RcpuLastApeStatus.r32.installReadCallback(read_from_ram, &SHM_RcpuLastApeStatus_r32);
    SHM.RcpuLastApeStatus.r32.installWriteCallback(write_to_ram, &SHM_RcpuLastApeStatus_r32);

    /** @brief Bitmap for @ref SHM_t.RcpuLastApeFwStatus. */
    static ram_offset_t SHM_RcpuLastApeFwStatus_r32((uint8_t *)base, (uint32_t)292);
    SHM.RcpuLastApeFwStatus.r32.installReadCallback(read_from_ram, &SHM_RcpuLastApeFwStatus_r32);
    SHM.RcpuLastApeFwStatus.r32.installWriteCallback(write_to_ram, &SHM_RcpuLastApeFwStatus_r32);

    /** @brief Bitmap for @ref SHM_t.RcpuCfgHw. */
    static ram_offset_t SHM_RcpuCfgHw_r32((uint8_t *)base, (uint32_t)296);
    SHM.RcpuCfgHw.r32.installReadCallback(read_from_ram, &SHM_RcpuCfgHw_r32);
    SHM.RcpuCfgHw.r32.installWriteCallback(write_to_ram, &SHM_RcpuCfgHw_r32);

    /** @brief Bitmap for @ref SHM_t.RcpuCfgHw2. */
    static ram_offset_t SHM_RcpuCfgHw2_r32((uint8_t *)base, (uint32_t)300);
    SHM.RcpuCfgHw2.r32.installReadCallback(read_from_ram, &SHM_RcpuCfgHw2_r32);
    SHM.RcpuCfgHw2.r32.installWriteCallback(write_to_ram, &SHM_RcpuCfgHw2_r32);

    /** @brief Bitmap for @ref SHM_t.RcpuCpmuStatus. */
    static ram_offset_t SHM_RcpuCpmuStatus_r32((uint8_t *)base, (uint32_t)304);
    SHM.RcpuCpmuStatus.r32.installReadCallback(read_from_ram, &SHM_RcpuCpmuStatus_r32);
    SHM.RcpuCpmuStatus.r32.installWriteCallback(write_to_ram, &SHM_RcpuCpmuStatus_r32);

    /** @brief Bitmap for @ref SHM_t.HostSegSig. */
    static ram_offset_t SHM_HostSegSig_r32((uint8_t *)base, (uint32_t)512);
    SHM.HostSegSig.r32.installReadCallback(read_from_ram, &SHM_HostSegSig_r32);
    SHM.HostSegSig.r32.installWriteCallback(write_to_ram, &SHM_HostSegSig_r32);

    /** @brief Bitmap for @ref SHM_t.HostSegLen. */
    static ram_offset_t SHM_HostSegLen_r32((uint8_t *)base, (uint32_t)516);
    SHM.HostSegLen.r32.installReadCallback(read_from_ram, &SHM_HostSegLen_r32);
    SHM.HostSegLen.r32.installWriteCallback(write_to_ram, &SHM_HostSegLen_r32);

    /** @brief Bitmap for @ref SHM_t.HostInitCount. */
    static ram_offset_t SHM_HostInitCount_r32((uint8_t *)base, (uint32_t)520);
    SHM.HostInitCount.r32.installReadCallback(read_from_ram, &SHM_HostInitCount_r32);
    SHM.HostInitCount.r32.installWriteCallback(write_to_ram, &SHM_HostInitCount_r32);

    /** @brief Bitmap for @ref SHM_t.HostDriverId. */
    static ram_offset_t SHM_HostDriverId_r32((uint8_t *)base, (uint32_t)524);
    SHM.HostDriverId.r32.installReadCallback(read_from_ram, &SHM_HostDriverId_r32);
    SHM.HostDriverId.r32.installWriteCallback(write_to_ram, &SHM_HostDriverId_r32);

    /** @brief Bitmap for @ref SHM_t.HostBehavior. */
    static ram_offset_t SHM_HostBehavior_r32((uint8_t *)base, (uint32_t)528);
    SHM.HostBehavior.r32.installReadCallback(read_from_ram, &SHM_HostBehavior_r32);
    SHM.HostBehavior.r32.installWriteCallback(write_to_ram, &SHM_HostBehavior_r32);

    /** @brief Bitmap for @ref SHM_t.HeartbeatInterval. */
    static ram_offset_t SHM_HeartbeatInterval_r32((uint8_t *)base, (uint32_t)532);
    SHM.HeartbeatInterval.r32.installReadCallback(read_from_ram, &SHM_HeartbeatInterval_r32);
    SHM.HeartbeatInterval.r32.installWriteCallback(write_to_ram, &SHM_HeartbeatInterval_r32);

    /** @brief Bitmap for @ref SHM_t.HeartbeatCount. */
    static ram_offset_t SHM_HeartbeatCount_r32((uint8_t *)base, (uint32_t)536);
    SHM.HeartbeatCount.r32.installReadCallback(read_from_ram, &SHM_HeartbeatCount_r32);
    SHM.HeartbeatCount.r32.installWriteCallback(write_to_ram, &SHM_HeartbeatCount_r32);

    /** @brief Bitmap for @ref SHM_t.HostDriverState. */
    static ram_offset_t SHM_HostDriverState_r32((uint8_t *)base, (uint32_t)540);
    SHM.HostDriverState.r32.installReadCallback(read_from_ram, &SHM_HostDriverState_r32);
    SHM.HostDriverState.r32.installWriteCallback(write_to_ram, &SHM_HostDriverState_r32);

    /** @brief Bitmap for @ref SHM_t.WolSpeed. */
    static ram_offset_t SHM_WolSpeed_r32((uint8_t *)base, (uint32_t)548);
    SHM.WolSpeed.r32.installReadCallback(read_from_ram, &SHM_WolSpeed_r32);
    SHM.WolSpeed.r32.installWriteCallback(write_to_ram, &SHM_WolSpeed_r32);

    /** @brief Bitmap for @ref SHM_t.EventStatus. */
    static ram_offset_t SHM_EventStatus_r32((uint8_t *)base, (uint32_t)768);
    SHM.EventStatus.r32.installReadCallback(read_from_ram, &SHM_EventStatus_r32);
    SHM.EventStatus.r32.installWriteCallback(write_to_ram, &SHM_EventStatus_r32);

    /** @brief Bitmap for @ref SHM_t.ProtMagic. */
    static ram_offset_t SHM_ProtMagic_r32((uint8_t *)base, (uint32_t)776);
    SHM.ProtMagic.r32.installReadCallback(read_from_ram, &SHM_ProtMagic_r32);
    SHM.ProtMagic.r32.installWriteCallback(write_to_ram, &SHM_ProtMagic_r32);

    /** @brief Bitmap for @ref SHM_t.ProtMac0High. */
    static ram_offset_t SHM_ProtMac0High_r32((uint8_t *)base, (uint32_t)788);
    SHM.ProtMac0High.r32.installReadCallback(read_from_ram, &SHM_ProtMac0High_r32);
    SHM.ProtMac0High.r32.installWriteCallback(write_to_ram, &SHM_ProtMac0High_r32);

    /** @brief Bitmap for @ref SHM_t.ProtMac0Low. */
    static ram_offset_t SHM_ProtMac0Low_r32((uint8_t *)base, (uint32_t)792);
    SHM.ProtMac0Low.r32.installReadCallback(read_from_ram, &SHM_ProtMac0Low_r32);
    SHM.ProtMac0Low.r32.installWriteCallback(write_to_ram, &SHM_ProtMac0Low_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiSig. */
    static ram_offset_t SHM_NcsiSig_r32((uint8_t *)base, (uint32_t)2048);
    SHM.NcsiSig.r32.installReadCallback(read_from_ram, &SHM_NcsiSig_r32);
    SHM.NcsiSig.r32.installWriteCallback(write_to_ram, &SHM_NcsiSig_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiBuildTime. */
    static ram_offset_t SHM_NcsiBuildTime_r32((uint8_t *)base, (uint32_t)2064);
    SHM.NcsiBuildTime.r32.installReadCallback(read_from_ram, &SHM_NcsiBuildTime_r32);
    SHM.NcsiBuildTime.r32.installWriteCallback(write_to_ram, &SHM_NcsiBuildTime_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiBuildTime2. */
    static ram_offset_t SHM_NcsiBuildTime2_r32((uint8_t *)base, (uint32_t)2068);
    SHM.NcsiBuildTime2.r32.installReadCallback(read_from_ram, &SHM_NcsiBuildTime2_r32);
    SHM.NcsiBuildTime2.r32.installWriteCallback(write_to_ram, &SHM_NcsiBuildTime2_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiBuildTime3. */
    static ram_offset_t SHM_NcsiBuildTime3_r32((uint8_t *)base, (uint32_t)2072);
    SHM.NcsiBuildTime3.r32.installReadCallback(read_from_ram, &SHM_NcsiBuildTime3_r32);
    SHM.NcsiBuildTime3.r32.installWriteCallback(write_to_ram, &SHM_NcsiBuildTime3_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiBuildDate. */
    static ram_offset_t SHM_NcsiBuildDate_r32((uint8_t *)base, (uint32_t)2076);
    SHM.NcsiBuildDate.r32.installReadCallback(read_from_ram, &SHM_NcsiBuildDate_r32);
    SHM.NcsiBuildDate.r32.installWriteCallback(write_to_ram, &SHM_NcsiBuildDate_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiBuildDate2. */
    static ram_offset_t SHM_NcsiBuildDate2_r32((uint8_t *)base, (uint32_t)2080);
    SHM.NcsiBuildDate2.r32.installReadCallback(read_from_ram, &SHM_NcsiBuildDate2_r32);
    SHM.NcsiBuildDate2.r32.installWriteCallback(write_to_ram, &SHM_NcsiBuildDate2_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiBuildDate3. */
    static ram_offset_t SHM_NcsiBuildDate3_r32((uint8_t *)base, (uint32_t)2084);
    SHM.NcsiBuildDate3.r32.installReadCallback(read_from_ram, &SHM_NcsiBuildDate3_r32);
    SHM.NcsiBuildDate3.r32.installWriteCallback(write_to_ram, &SHM_NcsiBuildDate3_r32);

    /** @brief Bitmap for @ref SHM_t.ChipId. */
    static ram_offset_t SHM_ChipId_r32((uint8_t *)base, (uint32_t)2192);
    SHM.ChipId.r32.installReadCallback(read_from_ram, &SHM_ChipId_r32);
    SHM.ChipId.r32.installWriteCallback(write_to_ram, &SHM_ChipId_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Info. */
    static ram_offset_t SHM_NcsiChannel0Info_r32((uint8_t *)base, (uint32_t)2304);
    SHM.NcsiChannel0Info.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Info_r32);
    SHM.NcsiChannel0Info.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Info_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mcid. */
    static ram_offset_t SHM_NcsiChannel0Mcid_r32((uint8_t *)base, (uint32_t)2308);
    SHM.NcsiChannel0Mcid.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mcid_r32);
    SHM.NcsiChannel0Mcid.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mcid_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Aen. */
    static ram_offset_t SHM_NcsiChannel0Aen_r32((uint8_t *)base, (uint32_t)2312);
    SHM.NcsiChannel0Aen.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Aen_r32);
    SHM.NcsiChannel0Aen.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Aen_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Bfilt. */
    static ram_offset_t SHM_NcsiChannel0Bfilt_r32((uint8_t *)base, (uint32_t)2316);
    SHM.NcsiChannel0Bfilt.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Bfilt_r32);
    SHM.NcsiChannel0Bfilt.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Bfilt_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mfilt. */
    static ram_offset_t SHM_NcsiChannel0Mfilt_r32((uint8_t *)base, (uint32_t)2320);
    SHM.NcsiChannel0Mfilt.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mfilt_r32);
    SHM.NcsiChannel0Mfilt.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mfilt_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Setting1. */
    static ram_offset_t SHM_NcsiChannel0Setting1_r32((uint8_t *)base, (uint32_t)2324);
    SHM.NcsiChannel0Setting1.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Setting1_r32);
    SHM.NcsiChannel0Setting1.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Setting1_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Setting2. */
    static ram_offset_t SHM_NcsiChannel0Setting2_r32((uint8_t *)base, (uint32_t)2328);
    SHM.NcsiChannel0Setting2.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Setting2_r32);
    SHM.NcsiChannel0Setting2.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Setting2_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Vlan. */
    static ram_offset_t SHM_NcsiChannel0Vlan_r32((uint8_t *)base, (uint32_t)2332);
    SHM.NcsiChannel0Vlan.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Vlan_r32);
    SHM.NcsiChannel0Vlan.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Vlan_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0AltHostMacHigh. */
    static ram_offset_t SHM_NcsiChannel0AltHostMacHigh_r32((uint8_t *)base, (uint32_t)2340);
    SHM.NcsiChannel0AltHostMacHigh.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0AltHostMacHigh_r32);
    SHM.NcsiChannel0AltHostMacHigh.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0AltHostMacHigh_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0AltHostMacMid. */
    static ram_offset_t SHM_NcsiChannel0AltHostMacMid_r32((uint8_t *)base, (uint32_t)2344);
    SHM.NcsiChannel0AltHostMacMid.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0AltHostMacMid_r32);
    SHM.NcsiChannel0AltHostMacMid.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0AltHostMacMid_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0AltHostMacLow. */
    static ram_offset_t SHM_NcsiChannel0AltHostMacLow_r32((uint8_t *)base, (uint32_t)2348);
    SHM.NcsiChannel0AltHostMacLow.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0AltHostMacLow_r32);
    SHM.NcsiChannel0AltHostMacLow.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0AltHostMacLow_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0High. */
    static ram_offset_t SHM_NcsiChannel0Mac0High_r32((uint8_t *)base, (uint32_t)2356);
    SHM.NcsiChannel0Mac0High.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac0High_r32);
    SHM.NcsiChannel0Mac0High.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac0High_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0Mid. */
    static ram_offset_t SHM_NcsiChannel0Mac0Mid_r32((uint8_t *)base, (uint32_t)2360);
    SHM.NcsiChannel0Mac0Mid.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac0Mid_r32);
    SHM.NcsiChannel0Mac0Mid.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac0Mid_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0Low. */
    static ram_offset_t SHM_NcsiChannel0Mac0Low_r32((uint8_t *)base, (uint32_t)2364);
    SHM.NcsiChannel0Mac0Low.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac0Low_r32);
    SHM.NcsiChannel0Mac0Low.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac0Low_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1High. */
    static ram_offset_t SHM_NcsiChannel0Mac1High_r32((uint8_t *)base, (uint32_t)2372);
    SHM.NcsiChannel0Mac1High.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac1High_r32);
    SHM.NcsiChannel0Mac1High.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac1High_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1Mid. */
    static ram_offset_t SHM_NcsiChannel0Mac1Mid_r32((uint8_t *)base, (uint32_t)2376);
    SHM.NcsiChannel0Mac1Mid.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac1Mid_r32);
    SHM.NcsiChannel0Mac1Mid.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac1Mid_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1Low. */
    static ram_offset_t SHM_NcsiChannel0Mac1Low_r32((uint8_t *)base, (uint32_t)2380);
    SHM.NcsiChannel0Mac1Low.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac1Low_r32);
    SHM.NcsiChannel0Mac1Low.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac1Low_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac2High. */
    static ram_offset_t SHM_NcsiChannel0Mac2High_r32((uint8_t *)base, (uint32_t)2388);
    SHM.NcsiChannel0Mac2High.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac2High_r32);
    SHM.NcsiChannel0Mac2High.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac2High_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac2Mid. */
    static ram_offset_t SHM_NcsiChannel0Mac2Mid_r32((uint8_t *)base, (uint32_t)2392);
    SHM.NcsiChannel0Mac2Mid.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac2Mid_r32);
    SHM.NcsiChannel0Mac2Mid.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac2Mid_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac2Low. */
    static ram_offset_t SHM_NcsiChannel0Mac2Low_r32((uint8_t *)base, (uint32_t)2396);
    SHM.NcsiChannel0Mac2Low.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac2Low_r32);
    SHM.NcsiChannel0Mac2Low.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac2Low_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac3High. */
    static ram_offset_t SHM_NcsiChannel0Mac3High_r32((uint8_t *)base, (uint32_t)2404);
    SHM.NcsiChannel0Mac3High.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac3High_r32);
    SHM.NcsiChannel0Mac3High.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac3High_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac3Mid. */
    static ram_offset_t SHM_NcsiChannel0Mac3Mid_r32((uint8_t *)base, (uint32_t)2408);
    SHM.NcsiChannel0Mac3Mid.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac3Mid_r32);
    SHM.NcsiChannel0Mac3Mid.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac3Mid_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac3Low. */
    static ram_offset_t SHM_NcsiChannel0Mac3Low_r32((uint8_t *)base, (uint32_t)2412);
    SHM.NcsiChannel0Mac3Low.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac3Low_r32);
    SHM.NcsiChannel0Mac3Low.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac3Low_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0VlanValid. */
    static ram_offset_t SHM_NcsiChannel0Mac0VlanValid_r32((uint8_t *)base, (uint32_t)2416);
    SHM.NcsiChannel0Mac0VlanValid.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac0VlanValid_r32);
    SHM.NcsiChannel0Mac0VlanValid.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac0VlanValid_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0Vlan. */
    static ram_offset_t SHM_NcsiChannel0Mac0Vlan_r32((uint8_t *)base, (uint32_t)2420);
    SHM.NcsiChannel0Mac0Vlan.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac0Vlan_r32);
    SHM.NcsiChannel0Mac0Vlan.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac0Vlan_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1VlanValid. */
    static ram_offset_t SHM_NcsiChannel0Mac1VlanValid_r32((uint8_t *)base, (uint32_t)2424);
    SHM.NcsiChannel0Mac1VlanValid.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac1VlanValid_r32);
    SHM.NcsiChannel0Mac1VlanValid.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac1VlanValid_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1Vlan. */
    static ram_offset_t SHM_NcsiChannel0Mac1Vlan_r32((uint8_t *)base, (uint32_t)2428);
    SHM.NcsiChannel0Mac1Vlan.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Mac1Vlan_r32);
    SHM.NcsiChannel0Mac1Vlan.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Mac1Vlan_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Status. */
    static ram_offset_t SHM_NcsiChannel0Status_r32((uint8_t *)base, (uint32_t)2432);
    SHM.NcsiChannel0Status.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Status_r32);
    SHM.NcsiChannel0Status.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Status_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0ResetCount. */
    static ram_offset_t SHM_NcsiChannel0ResetCount_r32((uint8_t *)base, (uint32_t)2436);
    SHM.NcsiChannel0ResetCount.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0ResetCount_r32);
    SHM.NcsiChannel0ResetCount.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0ResetCount_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Pxe. */
    static ram_offset_t SHM_NcsiChannel0Pxe_r32((uint8_t *)base, (uint32_t)2440);
    SHM.NcsiChannel0Pxe.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Pxe_r32);
    SHM.NcsiChannel0Pxe.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Pxe_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Dropfil. */
    static ram_offset_t SHM_NcsiChannel0Dropfil_r32((uint8_t *)base, (uint32_t)2444);
    SHM.NcsiChannel0Dropfil.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Dropfil_r32);
    SHM.NcsiChannel0Dropfil.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Dropfil_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Slink. */
    static ram_offset_t SHM_NcsiChannel0Slink_r32((uint8_t *)base, (uint32_t)2448);
    SHM.NcsiChannel0Slink.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Slink_r32);
    SHM.NcsiChannel0Slink.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Slink_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Dbg. */
    static ram_offset_t SHM_NcsiChannel0Dbg_r32((uint8_t *)base, (uint32_t)2464);
    SHM.NcsiChannel0Dbg.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0Dbg_r32);
    SHM.NcsiChannel0Dbg.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0Dbg_r32);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0CtrlstatRx. */
    static ram_offset_t SHM_NcsiChannel0CtrlstatRx_r32((uint8_t *)base, (uint32_t)2480);
    SHM.NcsiChannel0CtrlstatRx.r32.installReadCallback(read_from_ram, &SHM_NcsiChannel0CtrlstatRx_r32);
    SHM.NcsiChannel0CtrlstatRx.r32.installWriteCallback(write_to_ram, &SHM_NcsiChannel0CtrlstatRx_r32);


}
