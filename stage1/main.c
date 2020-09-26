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
/// @copyright Copyright (c) 2018-2020, Evan Lojewski
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
#define vpd_swap(__x__) (__x__) /* No swapping needed on the host */
#else
#define be32toh(__x__) (__x__)
#define crc_swap(__x__) ((((__x__)&0x000000FF) << 24) | (((__x__)&0x0000FF00) << 8) | (((__x__)&0x00FF0000) >> 8) | (((__x__)&0xFF000000) >> 24))
#define vpd_swap(__x__) ((((__x__)&0x000000FF) << 24) | (((__x__)&0x0000FF00) << 8) | (((__x__)&0x00FF0000) >> 8) | (((__x__)&0xFF000000) >> 24))
#endif
#include <APE.h>
#include <NVRam.h>
#include <bcm5719_APE.h>
#include <bcm5719_BOOTCODE.h>
#if CXX_SIMULATOR
#include <APE_DEVICE.h>
#else
#include <bcm5719_DEVICE.h>
#endif
#include <bcm5719_GEN.h>
#include <bcm5719_SHM.h>

NVRAMContents_t gNVMContents;

void __attribute__((noinline)) reportStatus(uint32_t code, uint8_t step)
{
    GEN.GenDataSig.r32 = (code | step);
}

void init_once(void)
{
    SHM.RcpuInitCount.r32 = 0;
    SHM.RcpuFwVersion.r32 = (VERSION_MAJOR << 24) | (VERSION_MINOR << 16) | VERSION_PATCH;

    SHM.RcpuApeResetCount.r32 = 0;
    SHM.RcpuLastApeStatus.r32 = 0;
    SHM.RcpuLastApeFwStatus.r32 = 0;

    SHM.RcpuSegLength.r32 = 0x34;
}

void handle_printf()
{
    uint32_t buffer_size = sizeof(SHM.RcpuPrintfBuffer) / sizeof(SHM.RcpuPrintfBuffer[0]) * sizeof(uint32_t);

    if (SHM.RcpuWritePointer.r32 > buffer_size || SHM.RcpuReadPointer.r32 > buffer_size || SHM.RcpuHostReadPointer.r32 > buffer_size)
    {
        // Print buffer has not been initialized. Exit out.
        return;
    }

    uint32_t cached_pointer = SHM.RcpuReadPointer.r32;
    if (cached_pointer != SHM.RcpuWritePointer.r32)
    {
        if (cached_pointer >= buffer_size)
        {
            cached_pointer = 0;
        }

        uint32_t word_pointer = cached_pointer / 4;
        uint32_t byte_index = cached_pointer % 4;
        char character = (uint8_t)(SHM.RcpuPrintfBuffer[word_pointer].r32 >> (byte_index * 8));

        em100_putchar(character);

        SHM.RcpuReadPointer.r32 = ++cached_pointer;
    }
}

void handle_vpd()
{
    if (DEVICE.RxCpuEvent.bits.VPDAttention)
    {
        uint32_t vpd_offset = DEVICE.PciVpdRequest.bits.RequestedVPDOffset;

        uint32_t vpd_data = 0;
        if (vpd_offset < sizeof(gNVMContents.vpd.bytes))
        {
            vpd_data = ((uint32_t *)gNVMContents.vpd.bytes)[vpd_offset / 4];
        }

        DEVICE.PciVpdResponse.r32 = vpd_swap(vpd_data);
    }
}

int main()
{
#if CXX_SIMULATOR
    initHAL(NULL);
#endif

    reportStatus(STATUS_MAIN, 0);

    if (0 == DEVICE.Status.bits.FunctionNumber)
    {
        em100_puts("RX Firmware v" STRINGIFY(VERSION_MAJOR) "." STRINGIFY(VERSION_MINOR) "." STRINGIFY(VERSION_PATCH) "\n");
    }

#if !CXX_SIMULATOR
    // Perform early initialization
    early_init_hw();
#endif

    reportStatus(STATUS_MAIN, 1);

    if (SHM.RcpuSegSig.bits.Sig != SHM_RCPU_SEG_SIG_SIG_RCPU_MAGIC)
    {
        init_once();
    }

    // Read out the NVM configuration.
    NVRam_acquireLock();
    NVRam_enable();
    NVRam_read(0, (uint32_t *)&gNVMContents, sizeof(NVRAMContents_t) / 4);
    NVRam_releaseLock();

    reportStatus(STATUS_MAIN, 2);
    // Read in the NVM header.

#if !CXX_SIMULATOR
    load_nvm_config(&DEVICE, &gNVMContents);

    // Initialize the hardware.
    // init_hw(&DEVICE, &gNVMContents);
#endif

    SHM.RcpuInitCount.r32 = SHM.RcpuInitCount.r32 + 1;

    // Send configuration information to APE SHM.
    SHM.RcpuCfgFeature.r32 = GEN.GenCfgFeature.r32;
    SHM.RcpuPciVendorDeviceId.r32 = DEVICE.PciVendorDeviceId.r32;
    SHM.RcpuPciSubsystemId.r32 = DEVICE.PciSubsystemId.r32;
    SHM.RcpuCfgHw.r32 = GEN.GenCfgHw.r32;
    SHM.RcpuCfgHw2.r32 = GEN.GenCfgHw2.r32;
    SHM.RcpuCpmuStatus.bits.Status = (DEVICE.Status.r32 & 0xFFFF0000) >> 16;
    SHM.RcpuCpmuStatus.bits.Address = SHM_RCPU_CPMU_STATUS_ADDRESS_ADDRESS;

    // Mark it as valid.
    SHM.RcpuSegSig.bits.Sig = SHM_RCPU_SEG_SIG_SIG_RCPU_MAGIC;

    // Set GEN_FIRMWARE_MBOX to BOOTCODE_READY_MAGIC.
    reportStatus(GEN_GEN_DATA_SIG_SIG_DRIVER_READY, 0);
    GEN.GenFwMbox.r32 = GEN_GEN_FW_MBOX_MBOX_BOOTCODE_READY;
    GEN.GenAsfStatusMbox.r32 = GEN_GEN_FW_MBOX_MBOX_BOOTCODE_READY;
    // Do main loop.

    if (0 == DEVICE.Status.bits.FunctionNumber)
    {
        for (;;)
        {
            // Handle printf from the APE.
            handle_printf();

            // Handle VPD requests from the host.
            handle_vpd();
        }
    }
    else
    {
        for (;;)
        {
            // Handle VPD requests from the host.
            handle_vpd();
        }
    }
}
