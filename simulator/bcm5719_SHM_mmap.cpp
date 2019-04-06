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

static uint32_t read_from_ram(uint32_t val, uint32_t offset, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += offset;

    BARRIER();
    return *(uint32_t *)base;
}

static uint32_t write_to_ram(uint32_t val, uint32_t offset, void *args)
{
    uint8_t *base = (uint8_t *)args;
    base += offset;

    BARRIER();
    *(uint32_t *)base = val;
    BARRIER();
    return val;
}

void init_bcm5719_SHM_mmap(void *base)
{
    SHM.mIndexReadCallback = read_from_ram;
    SHM.mIndexReadCallbackArgs = base;

    SHM.mIndexWriteCallback = write_to_ram;
    SHM.mIndexWriteCallbackArgs = base;

    /** @brief Component Registers for @ref SHM. */
    /** @brief Bitmap for @ref SHM_t.SegSig. */
    SHM.SegSig.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.SegSig.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.ApeSegLength. */
    SHM.ApeSegLength.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.ApeSegLength.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.FwStatus. */
    SHM.FwStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.FwStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.FwFeatures. */
    SHM.FwFeatures.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.FwFeatures.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.4014. */
    SHM._4014.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM._4014.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.FwVersion. */
    SHM.FwVersion.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.FwVersion.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.SegMessageBufferOffset. */
    SHM.SegMessageBufferOffset.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.SegMessageBufferOffset.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.SegMessageBufferLength. */
    SHM.SegMessageBufferLength.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.SegMessageBufferLength.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.4024. */
    SHM._4024.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM._4024.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.4028. */
    SHM._4028.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM._4028.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.LoaderCommand. */
    SHM.LoaderCommand.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.LoaderCommand.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.LoaderArg0. */
    SHM.LoaderArg0.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.LoaderArg0.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.LoaderArg1. */
    SHM.LoaderArg1.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.LoaderArg1.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuSegSig. */
    SHM.RcpuSegSig.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuSegSig.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuSegLength. */
    SHM.RcpuSegLength.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuSegLength.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuInitCount. */
    SHM.RcpuInitCount.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuInitCount.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuFwVersion. */
    SHM.RcpuFwVersion.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuFwVersion.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuCfgFeature. */
    SHM.RcpuCfgFeature.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuCfgFeature.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuPciVendorDeviceId. */
    SHM.RcpuPciVendorDeviceId.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuPciVendorDeviceId.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuPciSubsystemId. */
    SHM.RcpuPciSubsystemId.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuPciSubsystemId.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuApeResetCount. */
    SHM.RcpuApeResetCount.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuApeResetCount.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuLastApeStatus. */
    SHM.RcpuLastApeStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuLastApeStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuLastApeFwStatus. */
    SHM.RcpuLastApeFwStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuLastApeFwStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuCfgHw. */
    SHM.RcpuCfgHw.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuCfgHw.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuCfgHw2. */
    SHM.RcpuCfgHw2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuCfgHw2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.RcpuCpmuStatus. */
    SHM.RcpuCpmuStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.RcpuCpmuStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HostSegSig. */
    SHM.HostSegSig.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HostSegSig.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HostSegLen. */
    SHM.HostSegLen.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HostSegLen.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HostInitCount. */
    SHM.HostInitCount.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HostInitCount.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HostDriverId. */
    SHM.HostDriverId.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HostDriverId.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HostBehavior. */
    SHM.HostBehavior.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HostBehavior.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HeartbeatInterval. */
    SHM.HeartbeatInterval.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HeartbeatInterval.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HeartbeatCount. */
    SHM.HeartbeatCount.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HeartbeatCount.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.HostDriverState. */
    SHM.HostDriverState.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.HostDriverState.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.WolSpeed. */
    SHM.WolSpeed.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.WolSpeed.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.EventStatus. */
    SHM.EventStatus.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.EventStatus.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.ProtMagic. */
    SHM.ProtMagic.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.ProtMagic.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.ProtMac0High. */
    SHM.ProtMac0High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.ProtMac0High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.ProtMac0Low. */
    SHM.ProtMac0Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.ProtMac0Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiSig. */
    SHM.NcsiSig.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiSig.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiBuildTime. */
    SHM.NcsiBuildTime.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiBuildTime.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiBuildTime2. */
    SHM.NcsiBuildTime2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiBuildTime2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiBuildTime3. */
    SHM.NcsiBuildTime3.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiBuildTime3.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiBuildDate. */
    SHM.NcsiBuildDate.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiBuildDate.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiBuildDate2. */
    SHM.NcsiBuildDate2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiBuildDate2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiBuildDate3. */
    SHM.NcsiBuildDate3.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiBuildDate3.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.ChipId. */
    SHM.ChipId.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.ChipId.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Info. */
    SHM.NcsiChannel0Info.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Info.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mcid. */
    SHM.NcsiChannel0Mcid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mcid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Aen. */
    SHM.NcsiChannel0Aen.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Aen.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Bfilt. */
    SHM.NcsiChannel0Bfilt.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Bfilt.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mfilt. */
    SHM.NcsiChannel0Mfilt.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mfilt.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Setting1. */
    SHM.NcsiChannel0Setting1.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Setting1.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Setting2. */
    SHM.NcsiChannel0Setting2.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Setting2.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Vlan. */
    SHM.NcsiChannel0Vlan.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Vlan.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0AltHostMacHigh. */
    SHM.NcsiChannel0AltHostMacHigh.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0AltHostMacHigh.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0AltHostMacMid. */
    SHM.NcsiChannel0AltHostMacMid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0AltHostMacMid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0AltHostMacLow. */
    SHM.NcsiChannel0AltHostMacLow.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0AltHostMacLow.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0High. */
    SHM.NcsiChannel0Mac0High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac0High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0Mid. */
    SHM.NcsiChannel0Mac0Mid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac0Mid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0Low. */
    SHM.NcsiChannel0Mac0Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac0Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1High. */
    SHM.NcsiChannel0Mac1High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac1High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1Mid. */
    SHM.NcsiChannel0Mac1Mid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac1Mid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1Low. */
    SHM.NcsiChannel0Mac1Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac1Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac2High. */
    SHM.NcsiChannel0Mac2High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac2High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac2Mid. */
    SHM.NcsiChannel0Mac2Mid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac2Mid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac2Low. */
    SHM.NcsiChannel0Mac2Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac2Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac3High. */
    SHM.NcsiChannel0Mac3High.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac3High.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac3Mid. */
    SHM.NcsiChannel0Mac3Mid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac3Mid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac3Low. */
    SHM.NcsiChannel0Mac3Low.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac3Low.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0VlanValid. */
    SHM.NcsiChannel0Mac0VlanValid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac0VlanValid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0Vlan. */
    SHM.NcsiChannel0Mac0Vlan.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac0Vlan.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1VlanValid. */
    SHM.NcsiChannel0Mac1VlanValid.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac1VlanValid.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1Vlan. */
    SHM.NcsiChannel0Mac1Vlan.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Mac1Vlan.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Status. */
    SHM.NcsiChannel0Status.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Status.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0ResetCount. */
    SHM.NcsiChannel0ResetCount.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0ResetCount.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Pxe. */
    SHM.NcsiChannel0Pxe.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Pxe.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Dropfil. */
    SHM.NcsiChannel0Dropfil.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Dropfil.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Slink. */
    SHM.NcsiChannel0Slink.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Slink.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Dbg. */
    SHM.NcsiChannel0Dbg.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0Dbg.r32.installWriteCallback(write_to_ram, (uint8_t *)base);

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0CtrlstatRx. */
    SHM.NcsiChannel0CtrlstatRx.r32.installReadCallback(read_from_ram, (uint8_t *)base);
    SHM.NcsiChannel0CtrlstatRx.r32.installWriteCallback(write_to_ram, (uint8_t *)base);


}
