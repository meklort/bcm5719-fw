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
#include <OptionParser.h>
#include <vector>
#include <string>
#include <iostream>
#include <APE.h>
#include <bcm5719_SHM.h>
#include <elfio/elfio.hpp>

#include <types.h>
#include <APE_APE_PERI.h>
#include <APE_NVIC.h>

#include "../NVRam/bcm5719_NVM.h"

using namespace std;
using namespace ELFIO;
using optparse::OptionParser;

#ifdef __ppc64__
#define BARRIER()    do { asm volatile ("sync 0\neieio\n" ::: "memory"); } while(0)
#else
#define BARRIER()    do { asm volatile ("" ::: "memory"); } while(0)
#endif

int main(int argc, char const *argv[])
{
    OptionParser parser = OptionParser().description("BCM Register Utility");

    parser.add_option("-f", "--function")
            .dest("function")
            .type("int")
            .set_default("0")
            .metavar("FUNCTION")
            .help("Read registers from the specified pci function.");

    optparse::Values options = parser.parse_args(argc, argv);
    vector<string> args = parser.args();


    if(!initHAL(NULL, 1))
    {
        cerr << "Unable to locate pci device with function 1 for the debug console." << endl;
        exit(-1);
    }


    if(options.get("ape"))
    {
        APE.Mode.print();
        APE.Status.print();
        APE.Gpio.print();
        SHM.FwStatus.print();
        SHM.FwFeatures.print();
        SHM.FwVersion.print();

        printf("APE SegSig: 0x%08X\n", (uint32_t)SHM.SegSig.r32);
        printf("APE SegLen: 0x%08X\n", (uint32_t)SHM.ApeSegLength.r32);
        printf("APE RcpuApeResetCount: 0x%08X\n", (uint32_t)SHM.RcpuApeResetCount.r32);

        printf("APE RCPU SegSig: 0x%08X\n", (uint32_t)SHM.RcpuSegSig.r32);
        printf("APE RCPU SegLen: 0x%08X\n", (uint32_t)SHM.RcpuSegLength.r32);
        printf("APE RCPU Init Count: 0x%08X\n", (uint32_t)SHM.RcpuInitCount.r32);
        printf("APE RCPU FW Version: 0x%08X\n", (uint32_t)SHM.RcpuFwVersion.r32);

        printf("APE RCPU CfgFeature: 0x%08X\n", (uint32_t)SHM.RcpuCfgFeature.r32);
        printf("APE RCPU PCI Vendor/Device ID: 0x%08X\n", (uint32_t)SHM.RcpuPciVendorDeviceId.r32);
        printf("APE RCPU PCI Subsystem ID: 0x%08X\n", (uint32_t)SHM.RcpuPciSubsystemId.r32);

        APE_PERI.RmuControl.print();
        APE_PERI.ArbControl.print();

        // APE.Mode.print();
        // APE.Status.print();
        // APE.GpioMessage.print();
        // APE.Event.print();
        // APE.RxbufoffsetFunc0.print();
        // APE.RxbufoffsetFunc1.print();
        // APE.TxToNetDoorbellFunc0.print();
        // APE.TxState0.print();
        // APE.Mode2.print();
        // APE.Status2.print();
        // APE.LockGrantObsolete.print();
        // APE.RxPoolModeStatus0.print();
        // APE.RxPoolModeStatus1.print();
        // APE.RxPoolRetire0.print();
        // APE.RxPoolRetire1.print();
        // APE.TxToNetPoolModeStatus0.print();
        // APE.TxToNetBufferAllocator0.print();
        // APE.TxToNetBufferReturn0.print();
        // APE.TxToNetBufferRing0.print();
        // APE.Tick1mhz.print();
        // APE.Tick1khz.print();
        // APE.Tick10hz.print();
        // APE.Gpio.print();
        // APE.Gint.print();
        // APE.OtpControl.print();
        // APE.OtpStatus.print();
        // APE.OtpAddr.print();
        // APE.OtpReadData.print();
        // APE.CpuStatus.print();
        // APE.TxToNetPoolModeStatus1.print();
        // APE.TxToNetBufferAllocator1.print();
        // APE.TxToNetDoorbellFunc1.print();
        // APE.RxbufoffsetFunc2.print();
        // APE.TxToNetDoorbellFunc2.print();
        // APE.RxPoolModeStatus2.print();
        // APE.RxPoolRetire2.print();
        // APE.TxToNetPoolModeStatus2.print();
        // APE.TxToNetBufferAllocator2.print();
        // APE.RxbufoffsetFunc3.print();
        // APE.TxToNetDoorbellFunc3.print();
        // APE.RxPoolModeStatus3.print();
        // APE.RxPoolRetire3.print();
        // APE.TxToNetPoolModeStatus3.print();
        // APE.TxToNetBufferAllocator3.print();

        // APE.print();

        DEVICE.PerfectMatch1High.print();
        DEVICE.PerfectMatch1Low.print();

        printf("\n======= Port 0 =======\n");
        APE.TxToNetPoolModeStatus0.print();
        APE.RxPoolModeStatus0.print();
        
        printf("APE SegSig: 0x%08X\n", (uint32_t)SHM.SegSig.r32);
        printf("APE SegLen: 0x%08X\n", (uint32_t)SHM.ApeSegLength.r32);

        exit(0);
    }


    if(options.get("info"))
    {
        DEVICE.ChipId.print();
        DEVICE.PciVendorDeviceId.print();
        DEVICE.PciSubsystemId.print();
        DEVICE.PciClassCodeRevision.print();
        DEVICE.Status.print();


        // GenCfgFeature
        // GenCfgHw
        // GenCfgShared
        // GenCfgHw2
        // GenCfg5

        printf("\n");

        uint64_t serial = (((uint64_t)(DEVICE.PciSerialNumberHigh.r32)) << 32) | DEVICE.PciSerialNumberLow.r32;
        printf("Serial Number:   0x%016lX\n", serial);

        printf("\n");

        printf("Power Budget[0]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget0.r32);
        printf("Power Budget[1]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget1.r32);
        printf("Power Budget[2]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget2.r32);
        printf("Power Budget[3]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget3.r32);
        printf("Power Budget[4]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget4.r32);
        printf("Power Budget[5]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget5.r32);
        printf("Power Budget[6]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget6.r32);
        printf("Power Budget[7]: 0x%08X\n", (uint32_t)DEVICE.PciPowerBudget7.r32);

        printf("\n");

        uint64_t mac0 = (((uint64_t)(DEVICE.EmacMacAddresses0High.r32)) << 32) | DEVICE.EmacMacAddresses0Low.r32;
        uint64_t mac1 = (((uint64_t)(DEVICE.EmacMacAddresses1High.r32)) << 32) | DEVICE.EmacMacAddresses1Low.r32;
        uint64_t mac2 = (((uint64_t)(DEVICE.EmacMacAddresses2High.r32)) << 32) | DEVICE.EmacMacAddresses2Low.r32;
        uint64_t mac3 = (((uint64_t)(DEVICE.EmacMacAddresses3High.r32)) << 32) | DEVICE.EmacMacAddresses3Low.r32;
        printf("MAC0: 0x%012lX\n", mac0);
        printf("MAC1: 0x%012lX\n", mac1);
        printf("MAC2: 0x%012lX\n", mac2);
        printf("MAC3: 0x%012lX\n", mac3);

        printf("\n");

        printf("Reg 6408: 0x%08X\n", (uint32_t)DEVICE._6408.r32);
        printf("Reg 64c0: 0x%08X\n", (uint32_t)DEVICE._64c0.r32);
        printf("Reg 64c8: 0x%08X\n", (uint32_t)DEVICE._64c8.r32);
        printf("Reg 64dc: 0x%08X\n", (uint32_t)DEVICE._64dc.r32);
        printf("Reg 6530: 0x%08X\n", (uint32_t)DEVICE._6530.r32);
        printf("Reg 6550: 0x%08X\n", (uint32_t)DEVICE._6550.r32);
        printf("Reg 65f4: 0x%08X\n", (uint32_t)DEVICE._65f4.r32);
        printf("Reg 7c04: 0x%08X\n", (uint32_t)DEVICE._7c04.r32);

        printf("LedControl:         0x%08X\n", (uint32_t)DEVICE.LedControl.r32);
        printf("GrcModeControl:     0x%08X\n", (uint32_t)DEVICE.GrcModeControl.r32);
        DEVICE.GrcModeControl.bits.NVRAMWriteEnable = 1;
        DEVICE.GrcModeControl.print();
        printf("GphyControlStatus:  0x%08X\n", (uint32_t)DEVICE.GphyControlStatus.r32);
        printf("TopLevelMiscellaneousControl1: 0x%08X\n", (uint32_t)DEVICE.TopLevelMiscellaneousControl1.r32);
        printf("MiscellaneousLocalControl:     0x%08X\n", (uint32_t)DEVICE.MiscellaneousLocalControl.r32);

        DEVICE.RxRiscMode.print();
        DEVICE.RxRiscStatus.print();

        DEVICE.RxCpuEventEnable.print();
        DEVICE.RxCpuEvent.print();
        exit(0);
    }

    uint32_t* DEBUG = (uint32_t*)&gAPEBase[0x4000];
    volatile uint32_t* write_pointer = &DEBUG[0];
    volatile uint32_t* read_pointer = &DEBUG[1];
    uint32_t  buffer_size = 0x1000 - 8;
    volatile uint32_t*  buffer = &DEBUG[2];

    printf("Write Pointer: %d\n", *write_pointer);
    printf("Read Pointer: %d\n", *read_pointer);

    for(int i = 0; i < 16; i++)
        printf("DEBUG[i] = %08Xx\n", DEBUG[i]);

    for(;;)
    {
        BARRIER();
        uint32_t cached_pointer = *read_pointer;
        if(cached_pointer != *write_pointer)
        {
            BARRIER();
            char character = (uint8_t)buffer[cached_pointer];
            // printf("Buffer[%d] = %c\n", cached_pointer, character);
            putchar(character);

            if(cached_pointer++ >= buffer_size/4)
            {
                cached_pointer = 0;
            }
            *read_pointer = cached_pointer;
        }
    }

    return 0;
}
