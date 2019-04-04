////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_SHM.cpp
///
/// @project    bcm5719
///
/// @brief      bcm5719_SHM
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

#include <bcm5719_SHM.h>

SHM_t SHM;

void init_bcm5719_SHM(void)
{
    /** @brief Component Registers for @ref SHM. */
    /** @brief Bitmap for @ref SHM_t.SegSig. */

    /** @brief Bitmap for @ref SHM_t.ApeSegLength. */

    /** @brief Bitmap for @ref SHM_t.FwStatus. */

    /** @brief Bitmap for @ref SHM_t.FwFeatures. */

    /** @brief Bitmap for @ref SHM_t.4014. */

    /** @brief Bitmap for @ref SHM_t.FwVersion. */

    /** @brief Bitmap for @ref SHM_t.SegMessageBufferOffset. */

    /** @brief Bitmap for @ref SHM_t.SegMessageBufferLength. */

    /** @brief Bitmap for @ref SHM_t.4024. */

    /** @brief Bitmap for @ref SHM_t.4028. */

    /** @brief Bitmap for @ref SHM_t.LoaderCommand. */

    /** @brief Bitmap for @ref SHM_t.LoaderArg0. */

    /** @brief Bitmap for @ref SHM_t.LoaderArg1. */

    /** @brief Bitmap for @ref SHM_t.RcpuSegSig. */

    /** @brief Bitmap for @ref SHM_t.RcpuSegLength. */

    /** @brief Bitmap for @ref SHM_t.RcpuInitCount. */

    /** @brief Bitmap for @ref SHM_t.RcpuFwVersion. */

    /** @brief Bitmap for @ref SHM_t.RcpuCfgFeature. */

    /** @brief Bitmap for @ref SHM_t.RcpuPciVendorDeviceId. */

    /** @brief Bitmap for @ref SHM_t.RcpuPciSubsystemId. */

    /** @brief Bitmap for @ref SHM_t.RcpuApeResetCount. */

    /** @brief Bitmap for @ref SHM_t.RcpuLastApeStatus. */

    /** @brief Bitmap for @ref SHM_t.RcpuLastApeFwStatus. */

    /** @brief Bitmap for @ref SHM_t.RcpuCfgHw. */

    /** @brief Bitmap for @ref SHM_t.RcpuCfgHw2. */

    /** @brief Bitmap for @ref SHM_t.RcpuCpmuStatus. */

    /** @brief Bitmap for @ref SHM_t.HostSegSig. */

    /** @brief Bitmap for @ref SHM_t.HostSegLen. */

    /** @brief Bitmap for @ref SHM_t.HostInitCount. */

    /** @brief Bitmap for @ref SHM_t.HostDriverId. */

    /** @brief Bitmap for @ref SHM_t.HostBehavior. */

    /** @brief Bitmap for @ref SHM_t.HeartbeatInterval. */

    /** @brief Bitmap for @ref SHM_t.HeartbeatCount. */

    /** @brief Bitmap for @ref SHM_t.HostDriverState. */

    /** @brief Bitmap for @ref SHM_t.WolSpeed. */

    /** @brief Bitmap for @ref SHM_t.EventStatus. */

    /** @brief Bitmap for @ref SHM_t.ProtMagic. */

    /** @brief Bitmap for @ref SHM_t.ProtMac0High. */

    /** @brief Bitmap for @ref SHM_t.ProtMac0Low. */

    /** @brief Bitmap for @ref SHM_t.NcsiSig. */

    /** @brief Bitmap for @ref SHM_t.NcsiBuildTime. */

    /** @brief Bitmap for @ref SHM_t.NcsiBuildTime2. */

    /** @brief Bitmap for @ref SHM_t.NcsiBuildTime3. */

    /** @brief Bitmap for @ref SHM_t.NcsiBuildDate. */

    /** @brief Bitmap for @ref SHM_t.NcsiBuildDate2. */

    /** @brief Bitmap for @ref SHM_t.NcsiBuildDate3. */

    /** @brief Bitmap for @ref SHM_t.ChipId. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Info. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mcid. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Aen. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Bfilt. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mfilt. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Setting1. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Setting2. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Vlan. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0AltHostMacHigh. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0AltHostMacMid. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0AltHostMacLow. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0High. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0Mid. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0Low. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1High. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1Mid. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1Low. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac2High. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac2Mid. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac2Low. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac3High. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac3Mid. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac3Low. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0VlanValid. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac0Vlan. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1VlanValid. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Mac1Vlan. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Status. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0ResetCount. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Pxe. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Dropfil. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Slink. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0Dbg. */

    /** @brief Bitmap for @ref SHM_t.NcsiChannel0CtrlstatRx. */


}
