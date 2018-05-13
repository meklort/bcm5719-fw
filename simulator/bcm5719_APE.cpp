////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_APE.cpp
///
/// @project    <PROJECT>
///
/// @brief      bcm5719_APE simulation support
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

#include <bcm5719_APE.h>

APE_t APE;

void init_bcm5719_APE(void)
{
    /** @brief Component Registers for @ref APE. */ 
    /** @brief Bitmap for @ref APE_t.Mode. */ 
    APE.Mode.bits.Reset.setBaseRegister(&APE.Mode.r32);
    APE.Mode.bits.Halt.setBaseRegister(&APE.Mode.r32);
    APE.Mode.bits.FastBoot.setBaseRegister(&APE.Mode.r32);
    APE.Mode.bits.HostDiag.setBaseRegister(&APE.Mode.r32);
    APE.Mode.bits.MemoryECC.setBaseRegister(&APE.Mode.r32);

    /** @brief Bitmap for @ref APE_t.Status. */ 
    APE.Status.bits.PCIeReset.setBaseRegister(&APE.Status.r32);
    APE.Status.bits.LAN0Dstate.setBaseRegister(&APE.Status.r32);
    APE.Status.bits.BootMode.setBaseRegister(&APE.Status.r32);
    APE.Status.bits.NVRAMControlReset.setBaseRegister(&APE.Status.r32);
    APE.Status.bits.LAN1Dstate.setBaseRegister(&APE.Status.r32);
    APE.Status.bits.BootStatusB.setBaseRegister(&APE.Status.r32);
    APE.Status.bits.BootStatusA.setBaseRegister(&APE.Status.r32);

    /** @brief Bitmap for @ref APE_t.GpioMessage. */ 

    /** @brief Bitmap for @ref APE_t.Event. */ 
    APE.Event.bits._1.setBaseRegister(&APE.Event.r32);

    /** @brief Bitmap for @ref APE_t.Mode2. */ 

    /** @brief Bitmap for @ref APE_t.Status2. */ 

    /** @brief Bitmap for @ref APE_t.LockGrantObsolete. */ 

    /** @brief Bitmap for @ref APE_t.B0. */ 

    /** @brief Bitmap for @ref APE_t.Gpio. */ 
    APE.Gpio.bits.PIN0Unknown.setBaseRegister(&APE.Gpio.r32);
    APE.Gpio.bits.PIN1Unknown.setBaseRegister(&APE.Gpio.r32);
    APE.Gpio.bits.PIN2Unknown.setBaseRegister(&APE.Gpio.r32);
    APE.Gpio.bits.PIN3Unknown.setBaseRegister(&APE.Gpio.r32);
    APE.Gpio.bits.PIN0UnknownOut.setBaseRegister(&APE.Gpio.r32);
    APE.Gpio.bits.PIN1UnknownOut.setBaseRegister(&APE.Gpio.r32);
    APE.Gpio.bits.PIN2UnknownOut.setBaseRegister(&APE.Gpio.r32);
    APE.Gpio.bits.PIN3UnknownOut.setBaseRegister(&APE.Gpio.r32);
    APE.Gpio.bits.PIN0ModeOutput.setBaseRegister(&APE.Gpio.r32);
    APE.Gpio.bits.PIN1ModeOutput.setBaseRegister(&APE.Gpio.r32);
    APE.Gpio.bits.PIN2ModeOutput.setBaseRegister(&APE.Gpio.r32);
    APE.Gpio.bits.PIN3ModeOutput.setBaseRegister(&APE.Gpio.r32);

    /** @brief Bitmap for @ref APE_t.Gint. */ 

    /** @brief Bitmap for @ref APE_t.OtpControl. */ 
    APE.OtpControl.bits.Start.setBaseRegister(&APE.OtpControl.r32);
    APE.OtpControl.bits.ProgEnable.setBaseRegister(&APE.OtpControl.r32);

    /** @brief Bitmap for @ref APE_t.OtpStatus. */ 
    APE.OtpStatus.bits.CommandDone.setBaseRegister(&APE.OtpStatus.r32);

    /** @brief Bitmap for @ref APE_t.OtpAddr. */ 
    APE.OtpAddr.bits.Address.setBaseRegister(&APE.OtpAddr.r32);
    APE.OtpAddr.bits.CPUEnable.setBaseRegister(&APE.OtpAddr.r32);

    /** @brief Bitmap for @ref APE_t.OtpReadData. */ 

    /** @brief Bitmap for @ref APE_t.Cm3. */ 
    APE.Cm3.bits.CPUStatus.setBaseRegister(&APE.Cm3.r32);

    /** @brief Bitmap for @ref APE_t.SegSig. */ 

    /** @brief Bitmap for @ref APE_t.FwStatus. */ 
    APE.FwStatus.bits.Ready.setBaseRegister(&APE.FwStatus.r32);
    APE.FwStatus.bits.unknown_31_28.setBaseRegister(&APE.FwStatus.r32);

    /** @brief Bitmap for @ref APE_t.FwFeatures. */ 
    APE.FwFeatures.bits.NCSI.setBaseRegister(&APE.FwFeatures.r32);

    /** @brief Bitmap for @ref APE_t.4014. */ 

    /** @brief Bitmap for @ref APE_t.FwVersion. */ 
    APE.FwVersion.bits.Build.setBaseRegister(&APE.FwVersion.r32);
    APE.FwVersion.bits.Revision.setBaseRegister(&APE.FwVersion.r32);
    APE.FwVersion.bits.Minor.setBaseRegister(&APE.FwVersion.r32);
    APE.FwVersion.bits.Major.setBaseRegister(&APE.FwVersion.r32);

    /** @brief Bitmap for @ref APE_t.SegMessageBufferOffset. */ 

    /** @brief Bitmap for @ref APE_t.SegMessageBufferLength. */ 

    /** @brief Bitmap for @ref APE_t.4024. */ 

    /** @brief Bitmap for @ref APE_t.4028. */ 

    /** @brief Bitmap for @ref APE_t.RcpuSegSig. */ 

    /** @brief Bitmap for @ref APE_t.RcpuSegLength. */ 

    /** @brief Bitmap for @ref APE_t.RcpuInitCount. */ 

    /** @brief Bitmap for @ref APE_t.RcpuFwVersion. */ 

    /** @brief Bitmap for @ref APE_t.RcpuCfgFeature. */ 

    /** @brief Bitmap for @ref APE_t.RcpuPciVendorDeviceId. */ 

    /** @brief Bitmap for @ref APE_t.RcpuPciSubsystemId. */ 

    /** @brief Bitmap for @ref APE_t.411c. */ 

    /** @brief Bitmap for @ref APE_t.4120. */ 

    /** @brief Bitmap for @ref APE_t.4124. */ 

    /** @brief Bitmap for @ref APE_t.RcpuCfgHw. */ 

    /** @brief Bitmap for @ref APE_t.RcpuCfgHw2. */ 

    /** @brief Bitmap for @ref APE_t.RcpuCpmuStatus. */ 

    /** @brief Bitmap for @ref APE_t.HostSegSig. */ 

    /** @brief Bitmap for @ref APE_t.HostSegLen. */ 

    /** @brief Bitmap for @ref APE_t.HostInitCount. */ 

    /** @brief Bitmap for @ref APE_t.HostDriverId. */ 

    /** @brief Bitmap for @ref APE_t.HostBehavior. */ 
    APE.HostBehavior.bits.NoPHYLock.setBaseRegister(&APE.HostBehavior.r32);

    /** @brief Bitmap for @ref APE_t.HeartbeatInterval. */ 

    /** @brief Bitmap for @ref APE_t.HeartbeatCount. */ 

    /** @brief Bitmap for @ref APE_t.HostDriverState. */ 

    /** @brief Bitmap for @ref APE_t.WolSpeed. */ 

    /** @brief Bitmap for @ref APE_t.EventStatus. */ 
    APE.EventStatus.bits.DriverEvent.setBaseRegister(&APE.EventStatus.r32);
    APE.EventStatus.bits.Command.setBaseRegister(&APE.EventStatus.r32);
    APE.EventStatus.bits.State.setBaseRegister(&APE.EventStatus.r32);
    APE.EventStatus.bits.Pending.setBaseRegister(&APE.EventStatus.r32);

    /** @brief Bitmap for @ref APE_t.ProtMagic. */ 

    /** @brief Bitmap for @ref APE_t.ProtMac0High. */ 

    /** @brief Bitmap for @ref APE_t.ProtMac0Low. */ 

    /** @brief Bitmap for @ref APE_t.NcsiSig. */ 

    /** @brief Bitmap for @ref APE_t.NcsiBuildTime. */ 

    /** @brief Bitmap for @ref APE_t.NcsiBuildTime2. */ 

    /** @brief Bitmap for @ref APE_t.NcsiBuildTime3. */ 

    /** @brief Bitmap for @ref APE_t.NcsiBuildDate. */ 

    /** @brief Bitmap for @ref APE_t.NcsiBuildDate2. */ 

    /** @brief Bitmap for @ref APE_t.NcsiBuildDate3. */ 

    /** @brief Bitmap for @ref APE_t.ChipId. */ 

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy0. */ 

    /** @brief Bitmap for @ref APE_t.PerLockRequestGrc. */ 

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy1. */ 

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy2. */ 

    /** @brief Bitmap for @ref APE_t.PerLockRequestMem. */ 

    /** @brief Bitmap for @ref APE_t.PerLockRequestPhy3. */ 

    /** @brief Bitmap for @ref APE_t.PerLockRequestPort6. */ 

    /** @brief Bitmap for @ref APE_t.PerLockRequestGpio. */ 

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy0. */ 

    /** @brief Bitmap for @ref APE_t.PerLockGrantGrc. */ 

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy1. */ 

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy2. */ 

    /** @brief Bitmap for @ref APE_t.PerLockGrantMem. */ 

    /** @brief Bitmap for @ref APE_t.PerLockGrantPhy3. */ 

    /** @brief Bitmap for @ref APE_t.PerLockGrantPort6. */ 

    /** @brief Bitmap for @ref APE_t.PerLockGrantGpio. */ 


}
