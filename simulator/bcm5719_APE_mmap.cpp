////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_APE_mmap.cpp
///
/// @project    <PROJECT>
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

typedef std::pair<uint8_t*, uint32_t> ram_offset_t;

static uint32_t read_from_ram(uint32_t val, void* args)
{
    ram_offset_t* loc = (ram_offset_t*)args;

    uint8_t* base = loc->first;
    base += loc->second;

    return *(uint32_t*)base;
}

static uint32_t write_to_ram(uint32_t val, void* args)
{
    ram_offset_t* loc = (ram_offset_t*)args;

    uint8_t* base = loc->first;
    base += loc->second;

    *(uint32_t*)base = val;
    return val;
}

void init_bcm5719_APE_mmap(void* base)
{
    /** @brief Component Registers for @ref APE. */ 
    /** @brief Bitmap for @ref APE_t.Mode. */ 
    APE.Mode.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)0));
    APE.Mode.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)0));

    /** @brief Bitmap for @ref APE_t.Status. */ 
    APE.Status.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)4));
    APE.Status.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)4));

    /** @brief Bitmap for @ref APE_t.GpioMessage. */ 
    APE.GpioMessage.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)8));
    APE.GpioMessage.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)8));

    /** @brief Bitmap for @ref APE_t.Event. */ 
    APE.Event.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)12));
    APE.Event.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)12));

    /** @brief Bitmap for @ref APE_t.Mode2. */ 
    APE.Mode2.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)44));
    APE.Mode2.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)44));

    /** @brief Bitmap for @ref APE_t.Status2. */ 
    APE.Status2.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)48));
    APE.Status2.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)48));

    /** @brief Bitmap for @ref APE_t.LockGrantObsolete. */ 
    APE.LockGrantObsolete.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)76));
    APE.LockGrantObsolete.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)76));

    /** @brief Bitmap for @ref APE_t.B0. */ 
    APE.B0.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)176));
    APE.B0.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)176));

    /** @brief Bitmap for @ref APE_t.Gpio. */ 
    APE.Gpio.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)184));
    APE.Gpio.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)184));

    /** @brief Bitmap for @ref APE_t.Gint. */ 
    APE.Gint.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)188));
    APE.Gint.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)188));

    /** @brief Bitmap for @ref APE_t.OtpControl. */ 
    APE.OtpControl.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)232));
    APE.OtpControl.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)232));

    /** @brief Bitmap for @ref APE_t.OtpStatus. */ 
    APE.OtpStatus.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)236));
    APE.OtpStatus.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)236));

    /** @brief Bitmap for @ref APE_t.OtpAddr. */ 
    APE.OtpAddr.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)240));
    APE.OtpAddr.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)240));

    /** @brief Bitmap for @ref APE_t.OtpReadData. */ 
    APE.OtpReadData.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)248));
    APE.OtpReadData.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)248));

    /** @brief Bitmap for @ref APE_t.Cm3. */ 
    APE.Cm3.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)264));
    APE.Cm3.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)264));

    /** @brief Bitmap for @ref APE_t.SegSig. */ 
    APE.SegSig.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16384));
    APE.SegSig.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16384));

    /** @brief Bitmap for @ref APE_t.FwStatus. */ 
    APE.FwStatus.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16396));
    APE.FwStatus.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16396));

    /** @brief Bitmap for @ref APE_t.FwFeatures. */ 
    APE.FwFeatures.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16400));
    APE.FwFeatures.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16400));

    /** @brief Bitmap for @ref APE_t.4014. */ 
    APE._4014.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16404));
    APE._4014.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16404));

    /** @brief Bitmap for @ref APE_t.FwVersion. */ 
    APE.FwVersion.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16408));
    APE.FwVersion.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16408));

    /** @brief Bitmap for @ref APE_t.SegMessageBufferOffset. */ 
    APE.SegMessageBufferOffset.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16412));
    APE.SegMessageBufferOffset.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16412));

    /** @brief Bitmap for @ref APE_t.SegMessageBufferLength. */ 
    APE.SegMessageBufferLength.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16416));
    APE.SegMessageBufferLength.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16416));

    /** @brief Bitmap for @ref APE_t.4024. */ 
    APE._4024.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16420));
    APE._4024.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16420));

    /** @brief Bitmap for @ref APE_t.4028. */ 
    APE._4028.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16424));
    APE._4028.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16424));

    /** @brief Bitmap for @ref APE_t.RcpuSegSig. */ 
    APE.RcpuSegSig.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16640));
    APE.RcpuSegSig.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16640));

    /** @brief Bitmap for @ref APE_t.RcpuSegLength. */ 
    APE.RcpuSegLength.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16644));
    APE.RcpuSegLength.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16644));

    /** @brief Bitmap for @ref APE_t.RcpuInitCount. */ 
    APE.RcpuInitCount.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16648));
    APE.RcpuInitCount.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16648));

    /** @brief Bitmap for @ref APE_t.RcpuFwVersion. */ 
    APE.RcpuFwVersion.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16652));
    APE.RcpuFwVersion.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16652));

    /** @brief Bitmap for @ref APE_t.RcpuCfgFeature. */ 
    APE.RcpuCfgFeature.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16656));
    APE.RcpuCfgFeature.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16656));

    /** @brief Bitmap for @ref APE_t.RcpuPciVendorDeviceId. */ 
    APE.RcpuPciVendorDeviceId.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16660));
    APE.RcpuPciVendorDeviceId.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16660));

    /** @brief Bitmap for @ref APE_t.RcpuPciSubsystemId. */ 
    APE.RcpuPciSubsystemId.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16664));
    APE.RcpuPciSubsystemId.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16664));

    /** @brief Bitmap for @ref APE_t.411c. */ 
    APE._411c.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16668));
    APE._411c.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16668));

    /** @brief Bitmap for @ref APE_t.4120. */ 
    APE._4120.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16672));
    APE._4120.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16672));

    /** @brief Bitmap for @ref APE_t.4124. */ 
    APE._4124.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16676));
    APE._4124.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16676));

    /** @brief Bitmap for @ref APE_t.RcpuCfgHw. */ 
    APE.RcpuCfgHw.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16680));
    APE.RcpuCfgHw.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16680));

    /** @brief Bitmap for @ref APE_t.RcpuCfgHw2. */ 
    APE.RcpuCfgHw2.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16684));
    APE.RcpuCfgHw2.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16684));

    /** @brief Bitmap for @ref APE_t.RcpuCpmuStatus. */ 
    APE.RcpuCpmuStatus.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16688));
    APE.RcpuCpmuStatus.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16688));

    /** @brief Bitmap for @ref APE_t.HostSegSig. */ 
    APE.HostSegSig.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16896));
    APE.HostSegSig.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16896));

    /** @brief Bitmap for @ref APE_t.HostSegLen. */ 
    APE.HostSegLen.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16900));
    APE.HostSegLen.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16900));

    /** @brief Bitmap for @ref APE_t.HostInitCount. */ 
    APE.HostInitCount.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16904));
    APE.HostInitCount.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16904));

    /** @brief Bitmap for @ref APE_t.HostDriverId. */ 
    APE.HostDriverId.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16908));
    APE.HostDriverId.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16908));

    /** @brief Bitmap for @ref APE_t.HostBehavior. */ 
    APE.HostBehavior.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16912));
    APE.HostBehavior.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16912));

    /** @brief Bitmap for @ref APE_t.HeartbeatInterval. */ 
    APE.HeartbeatInterval.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16916));
    APE.HeartbeatInterval.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16916));

    /** @brief Bitmap for @ref APE_t.HeartbeatCount. */ 
    APE.HeartbeatCount.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16920));
    APE.HeartbeatCount.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16920));

    /** @brief Bitmap for @ref APE_t.HostDriverState. */ 
    APE.HostDriverState.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16924));
    APE.HostDriverState.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16924));

    /** @brief Bitmap for @ref APE_t.WolSpeed. */ 
    APE.WolSpeed.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16932));
    APE.WolSpeed.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)16932));

    /** @brief Bitmap for @ref APE_t.EventStatus. */ 
    APE.EventStatus.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)17152));
    APE.EventStatus.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)17152));

    /** @brief Bitmap for @ref APE_t.ProtMagic. */ 
    APE.ProtMagic.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)17160));
    APE.ProtMagic.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)17160));

    /** @brief Bitmap for @ref APE_t.ProtMac0High. */ 
    APE.ProtMac0High.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)17172));
    APE.ProtMac0High.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)17172));

    /** @brief Bitmap for @ref APE_t.ProtMac0Low. */ 
    APE.ProtMac0Low.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)17176));
    APE.ProtMac0Low.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)17176));

    /** @brief Bitmap for @ref APE_t.NcsiSig. */ 
    APE.NcsiSig.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18432));
    APE.NcsiSig.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18432));

    /** @brief Bitmap for @ref APE_t.NcsiBuildTime. */ 
    APE.NcsiBuildTime.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18448));
    APE.NcsiBuildTime.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18448));

    /** @brief Bitmap for @ref APE_t.NcsiBuildTime2. */ 
    APE.NcsiBuildTime2.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18452));
    APE.NcsiBuildTime2.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18452));

    /** @brief Bitmap for @ref APE_t.NcsiBuildTime3. */ 
    APE.NcsiBuildTime3.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18456));
    APE.NcsiBuildTime3.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18456));

    /** @brief Bitmap for @ref APE_t.NcsiBuildDate. */ 
    APE.NcsiBuildDate.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18460));
    APE.NcsiBuildDate.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18460));

    /** @brief Bitmap for @ref APE_t.NcsiBuildDate2. */ 
    APE.NcsiBuildDate2.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18464));
    APE.NcsiBuildDate2.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18464));

    /** @brief Bitmap for @ref APE_t.NcsiBuildDate3. */ 
    APE.NcsiBuildDate3.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18468));
    APE.NcsiBuildDate3.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18468));

    /** @brief Bitmap for @ref APE_t.ChipId. */ 
    APE.ChipId.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18576));
    APE.ChipId.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)18576));

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy0. */ 
    APE.PerLockRequestPhy0.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33792));
    APE.PerLockRequestPhy0.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33792));

    /** @brief Bitmap for @ref APE_t.PerLockRequestGrc. */ 
    APE.PerLockRequestGrc.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33796));
    APE.PerLockRequestGrc.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33796));

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy1. */ 
    APE.PerLockRequestPhy1.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33800));
    APE.PerLockRequestPhy1.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33800));

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy2. */ 
    APE.PerLockRequestPhy2.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33804));
    APE.PerLockRequestPhy2.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33804));

    /** @brief Bitmap for @ref APE_t.PerLockRequestMem. */ 
    APE.PerLockRequestMem.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33808));
    APE.PerLockRequestMem.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33808));

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy3. */ 
    APE.PerLockRequestPhy3.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33812));
    APE.PerLockRequestPhy3.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33812));

    /** @brief Bitmap for @ref APE_t.PerLockRequestPort6. */ 
    APE.PerLockRequestPort6.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33816));
    APE.PerLockRequestPort6.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33816));

    /** @brief Bitmap for @ref APE_t.PerLockRequestGpio. */ 
    APE.PerLockRequestGpio.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33820));
    APE.PerLockRequestGpio.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33820));

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy0. */ 
    APE.PerLockGrantPhy0.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33824));
    APE.PerLockGrantPhy0.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33824));

    /** @brief Bitmap for @ref APE_t.PerLockGrantGrc. */ 
    APE.PerLockGrantGrc.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33828));
    APE.PerLockGrantGrc.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33828));

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy1. */ 
    APE.PerLockGrantPhy1.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33832));
    APE.PerLockGrantPhy1.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33832));

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy2. */ 
    APE.PerLockGrantPhy2.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33836));
    APE.PerLockGrantPhy2.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33836));

    /** @brief Bitmap for @ref APE_t.PerLockGrantMem. */ 
    APE.PerLockGrantMem.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33840));
    APE.PerLockGrantMem.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33840));

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy3. */ 
    APE.PerLockGrantPhy3.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33844));
    APE.PerLockGrantPhy3.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33844));

    /** @brief Bitmap for @ref APE_t.PerLockGrantPort6. */ 
    APE.PerLockGrantPort6.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33848));
    APE.PerLockGrantPort6.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33848));

    /** @brief Bitmap for @ref APE_t.PerLockGrantGpio. */ 
    APE.PerLockGrantGpio.r32.installReadCallback(read_from_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33852));
    APE.PerLockGrantGpio.r32.installWriteCallback(write_to_ram, new ram_offset_t((uint8_t*)base, (uint32_t)33852));


}
