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

#if !CXX_SIMULATOR
    load_nvm_config(&gNVMContents);

    // Initialize the hardware.
    init_hw(&gNVMContents);
#endif

    reportStatus(STATUS_MAIN, 3);

    // Locate, verify, and execute stage2.
    uint32_t stage1_start  = be32toh(gNVMContents.header.bootstrapOffset);
    uint32_t stage1_length = be32toh(gNVMContents.header.bootstrapWords) * 4; // including crc.

    uint32_t stage2_start  = stage1_start + stage1_length;
    NVRAMStage2Header_t stage2_hdr;
    NVRam_read(stage2_start, (uint32_t*)&stage2_hdr, sizeof(stage2_hdr)/4);

    uint32_t stage2_length = be32toh(stage2_hdr.length);
    uint32_t stage2_magic = be32toh(stage2_hdr.magic);

    reportStatus(STATUS_MAIN, 4);

    if(BCM_NVRAM_MAGIC == stage2_magic)
    {
        // Magic matches. Attempt to load stage2.
        NVRam_read(stage2_start + sizeof(stage2_hdr), bootcode_dest, stage2_length/4);
        NVRam_releaseLock();

        uint32_t calculated_crc = be32toh(~NVRam_crc((uint8_t*)bootcode_dest, stage2_length - 4, 0xffffffff));
        uint32_t expected_crc = be32toh(bootcode_dest[stage2_length/4 - 1]);

        if(expected_crc == crc_swap(calculated_crc))
        {
            reportStatus(GEN_GEN_FW_MBOX_MBOX_DRIVER_READY, 0);
#if CXX_SIMULATOR
            // TODO: exec stage2.
            printf("Stage1 completed successfully with status 0x%08X.\n", (uint32_t)GEN.GenDataSig.r32);
            free(bootcode_dest);
            exit(0);
#else
           // Jump to bootcode_dest
            void __attribute__((noreturn)) (*stage2_entry)(void) = (void*)bootcode_dest;
            stage2_entry();
#endif
        }
        else
        {
            // Error. Invalid CRC.
            reportStatus(GEN_GEN_DATA_SIG_SIG_STAGE2_CRC_INVALID, 0);
        }
    }
    else
    {
        // Error. Invalid magic.
        reportStatus(GEN_GEN_DATA_SIG_SIG_STAGE2_MAGIC_INVALID, 0);
    }

    NVRam_releaseLock();

#if CXX_SIMULATOR
    printf("Stage1 failed with status 0x%08X.\n", (uint32_t)GEN.GenDataSig.r32);
    free(bootcode_dest);
    exit(-1);
#else
    for(;;)
    {
        // Spin forever.
        // Unable to do anything more. Halt the cpu.
        RegDEVICERxRiscMode_t mode;
        mode.r32 = 0;
        mode.bits.Halt = 1;
        DEVICE.RxRiscMode = mode;
    }
#endif
}
