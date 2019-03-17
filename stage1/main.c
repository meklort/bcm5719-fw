////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.c
///
/// @project
///
/// @brief      Main stage1 code
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
/// 3. Neither the name of the copyright holder nor the
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

#include "stage1.h"

#if CXX_SIMULATOR
#include <HAL.hpp>
#include <endian.h>
#define crc_swap(__x__) (__x__) /* No swapping needed on the host */    
#else
#define be32toh(__x__) (__x__)
#define crc_swap(__x__)  ((((__x__) & 0x000000FF) << 24) | \
                         (((__x__) & 0x0000FF00) << 8 ) |  \
                         (((__x__) & 0x00FF0000) >> 8 ) |  \
                         (((__x__) & 0xFF000000) >> 24))
#endif
#include <NVRam.h>
#include <bcm5719_BOOTCODE.h>
#include <bcm5719_GEN.h>
#include <bcm5719_DEVICE.h>
#include <bcm5719_APE.h>
#include <APE.h>

#include <string.h>

NVRAMContents_t gNVMContents;

int main()
{
    reportStatus(STATUS_MAIN, 0);
    uint32_t* bootcode_dest;
#if CXX_SIMULATOR
    initHAL(NULL);
    bootcode_dest = (uint32_t*)malloc(REG_BOOTCODE_SIZE);
#else
    bootcode_dest = (uint32_t*)&BOOTCODE;
#endif

#if !CXX_SIMULATOR
    // Perform early initialization
    early_init_hw();
#endif

    reportStatus(STATUS_MAIN, 1);
    // Read in the NVM header.
    NVRam_acquireLock();

    reportStatus(STATUS_MAIN, 2);

    NVRam_enable();
    NVRam_read(0, (uint32_t *)&gNVMContents, sizeof(NVRAMContents_t) / 4);
    NVRam_releaseLock();

#if !CXX_SIMULATOR
    load_nvm_config(&gNVMContents);

    // Initialize the hardware.
    init_hw(&gNVMContents);
#endif

    // Send configuration information to APE.
    APE.RcpuFwVersion.r32 = 0x0127;
    APE.RcpuCfgFeature.r32 = GEN.GenCfgFeature.r32;
    APE.RcpuPciVendorDeviceId.r32 = DEVICE.PciVendorDeviceId.r32;
    APE.RcpuPciSubsystemId.r32 = DEVICE.PciSubsystemId.r32;
    APE.RcpuCfgHw.r32 = GEN.GenCfgHw.r32;
    APE.RcpuCfgHw2.r32 = GEN.GenCfgHw2.r32;
    APE.RcpuCpmuStatus.bits.Status = (DEVICE.Status.r32 & 0xFFFF0000) >> 16;
    APE.RcpuCpmuStatus.bits.Address = APE_RCPU_CPMU_STATUS_ADDRESS_ADDRESS;

    if(APE_RCPU_SEG_SIG_SIG_RCPU_MAGIC != APE.RcpuSegSig.bits.Sig)
    {
        APE.RcpuInitCount.r32 = 1;
    }
    else
    {
        APE.RcpuInitCount.r32 = APE.RcpuInitCount.r32 + 1;
    }

    APE.RcpuApeResetCount.r32 = 0;
    APE.RcpuLastApeStatus.r32 = 0;
    APE.RcpuLastApeFwStatus.r32 = 0;

    // Mark it as valid.
    APE.RcpuSegLength.r32 = 0x34;
    APE.RcpuSegSig.bits.Sig  = APE_RCPU_SEG_SIG_SIG_RCPU_MAGIC;


    // Set GEN_FIRMWARE_MBOX to BOOTCODE_READY_MAGIC.
    reportStatus(GEN_GEN_DATA_SIG_SIG_DRIVER_READY, 0);
    GEN.GenFwMbox.r32 = GEN_GEN_FW_MBOX_MBOX_BOOTCODE_READY;
    GEN.GenAsfStatusMbox.r32 = GEN_GEN_FW_MBOX_MBOX_BOOTCODE_READY;
    // Do main loop.

    // Ensure all APE locks are released.
    APE_releaseAllLocks();

    DEVICE.RxCpuEventEnable.bits.VPDAttention = 1;
    for(;;)
    {
        // APE heartbeat.
        // APE.RcpuApeResetCount.r32 = APE.RcpuApeResetCount.r32 + 1;
        // APE.RcpuLastApeStatus.r32 = APE.Status.r32;
        // APE.RcpuLastApeFwStatus.r32 = APE.FwStatus.r32;

        // Spin
        if(DEVICE.RxCpuEvent.bits.VPDAttention)
        {
            uint32_t vpd_offset = DEVICE.PciVpdRequest.bits.RequestedVPDOffset;

            union
            {
                uint8_t r8[4];
                uint32_t r32;
            } vpd_data;
            vpd_data.r8[0] = gNVMContents.vpd.bytes[vpd_offset];
            vpd_data.r8[1] = gNVMContents.vpd.bytes[vpd_offset+1];
            vpd_data.r8[2] = gNVMContents.vpd.bytes[vpd_offset+2];
            vpd_data.r8[3] = gNVMContents.vpd.bytes[vpd_offset+3];
            DEVICE.PciVpdResponse.r32 = vpd_data.r32;
        }
    }

}
