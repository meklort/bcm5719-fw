////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.cpp
///
/// @project
///
/// @brief      Main bcm regiuster tool for decoding BCM5179 registers.
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
#include "HAL.hpp"
#include "pci_config.h"

#include <NVRam.h>
#include <bcm5719_eeprom.h>
#include <dirent.h>
#include <endian.h>
#include <errno.h>
#include <fcntl.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    initHAL(NULL);

    printf("ChipId: %x\n", (uint32_t)DEVICE.ChipId.r32);
    printf("APEChipId: %x\n", (uint32_t)APE.ChipId.r32);

    // printf("RxRiscMode: %0x\n", DEVICE.RxRiscMode.r32);
    // printf("RxRiscStatus: %0x\n", DEVICE.RxRiscStatus.r32);
    // printf("RxRiscProgramCounter: %0x\n", DEVICE.RxRiscProgramCounter.r32);
    // printf("RxRiscRegister0: %0x\n", DEVICE.RxRiscRegister0.r32);
    // printf("RxRiscRegister1: %0x\n", DEVICE.RxRiscRegister1.r32);
    // printf("RxRiscRegister2: %0x\n", DEVICE.RxRiscRegister2.r32);
    // printf("RxRiscRegister3: %0x\n", DEVICE.RxRiscRegister3.r32);
    DEVICE.LinkStatusControl.r32 = 0xffffffff;
    printf("LinkStatusControl.NegotiatedLinkSpeed: %0x\n",
           (uint32_t)DEVICE.LinkStatusControl.bits.NegotiatedLinkSpeed);
    printf("LinkStatusControl.NegotiatedLinkWidth: %0x\n",
           (uint32_t)DEVICE.LinkStatusControl.bits.NegotiatedLinkWidth);
    printf("LinkStatusControl.r32:                 %0x\n",
           (uint32_t)DEVICE.LinkStatusControl.r32);

    DEVICE.LinkStatusControl.bits.NegotiatedLinkSpeed = 0;
    printf("LinkStatusControl.NegotiatedLinkSpeed: %0x\n",
           (uint32_t)DEVICE.LinkStatusControl.bits.NegotiatedLinkSpeed);
    printf("LinkStatusControl.NegotiatedLinkWidth: %0x\n",
           (uint32_t)DEVICE.LinkStatusControl.bits.NegotiatedLinkWidth);
    printf("LinkStatusControl.r32:                 %0x\n",
           (uint32_t)DEVICE.LinkStatusControl.r32);

    printf("EmacMode.PortMode: %0x\n", (uint32_t)DEVICE.EmacMode.bits.PortMode);
    printf("EmacMacAddresses0High: %0x\n",
           (uint32_t)DEVICE.EmacMacAddresses0High.r32);
    printf("EmacMacAddresses0Low: %0x\n",
           (uint32_t)DEVICE.EmacMacAddresses0Low.r32);
    printf("RxRiscMode: %0x\n", (uint32_t)DEVICE.RxRiscMode.r32);

    // printf("HostDriverId: %0x\n", APE.HostDriverId.r32);
    // printf("RcpuPciSubsystemId: %0x\n", APE.RcpuPciSubsystemId.r32);

    // printf("\n\n=========\n\n");

    printf("Grab lock...\n");
    NVRam_acquireLock();

    NVRam_enable();

    uint32_t length = NVRam_readWord(8);   // current stage length
    uint32_t offset = NVRam_readWord(0xc); // current stage offset
    printf("NVRam_read(8) = %x\n", length);
    printf("NVRam_read(C) = %x\n", offset);
    // uint32_t next_stage_hdr = offset + (length*4);
    // uint32_t next_stage_size = next_stage_hdr + 4;
    // printf("NVRam_read(%x) = %x\n", next_stage_hdr,
    // NVRam_readWord(next_stage_hdr)); printf("NVRam_read(%x) = %x\n",
    // next_stage_size, NVRam_readWord(next_stage_size));

    NVRam_releaseLock();

    return 0;
}
