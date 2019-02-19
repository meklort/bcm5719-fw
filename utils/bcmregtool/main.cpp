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
#include <MII.h>
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
#include <OptionParser.h>
#include <vector>
#include <string>
#include <iostream>
#include <bcm5719_GEN.h>

using namespace std;
using optparse::OptionParser;

const char* regnames[32] = {
    "$zero", /* Zero register - always 0 */
    "$at",   /* Assembler register */
    "$v0", "$v1",             /* Results */
    "$a0", "$a1", "$a2", "$a3", /* Aguments */
    "$t0", "$t1", "$t2", "$t3", "$t4", "$t5", "$t6", "$t7", /* Temp, not saved */
    "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", /* Saved registers */
    "$t8", "$t9", /* Temp, not saved */
    "$k0", "$k1", /* Kernel / OS */
    "$gp", "$sp", "$fp", /* Pointers */
    "$ra", /* return address */
};

void print_context(void)
{
    uint32_t r[32];
    uint32_t pc;
    uint32_t opcode;

    // Read out the device context.
    pc = DEVICE.RxRiscProgramCounter.r32;
    opcode = DEVICE.RxRiscCurrentInstruction.r32;
    r[0] = DEVICE.RxRiscRegister0.r32;
    r[1] = DEVICE.RxRiscRegister1.r32;
    r[2] = DEVICE.RxRiscRegister2.r32;
    r[3] = DEVICE.RxRiscRegister3.r32;
    r[4] = DEVICE.RxRiscRegister4.r32;
    r[5] = DEVICE.RxRiscRegister5.r32;
    r[6] = DEVICE.RxRiscRegister6.r32;
    r[7] = DEVICE.RxRiscRegister7.r32;
    r[8] = DEVICE.RxRiscRegister8.r32;
    r[9] = DEVICE.RxRiscRegister9.r32;
    r[10] = DEVICE.RxRiscRegister10.r32;
    r[11] = DEVICE.RxRiscRegister11.r32;
    r[12] = DEVICE.RxRiscRegister12.r32;
    r[13] = DEVICE.RxRiscRegister13.r32;
    r[14] = DEVICE.RxRiscRegister14.r32;
    r[15] = DEVICE.RxRiscRegister15.r32;
    r[16] = DEVICE.RxRiscRegister16.r32;
    r[17] = DEVICE.RxRiscRegister17.r32;
    r[18] = DEVICE.RxRiscRegister18.r32;
    r[19] = DEVICE.RxRiscRegister19.r32;
    r[20] = DEVICE.RxRiscRegister20.r32;
    r[21] = DEVICE.RxRiscRegister21.r32;
    r[22] = DEVICE.RxRiscRegister22.r32;
    r[23] = DEVICE.RxRiscRegister23.r32;
    r[24] = DEVICE.RxRiscRegister24.r32;
    r[25] = DEVICE.RxRiscRegister25.r32;
    r[26] = DEVICE.RxRiscRegister26.r32;
    r[27] = DEVICE.RxRiscRegister27.r32;
    r[28] = DEVICE.RxRiscRegister28.r32;
    r[29] = DEVICE.RxRiscRegister29.r32;
    r[30] = DEVICE.RxRiscRegister30.r32;
    r[31] = DEVICE.RxRiscRegister31.r32;

    printf("==== Context ===\n");
    printf("   pc: 0x%08X   opcode: 0x%08X\n", pc, opcode);
    int numCols = 4;
    int offset = 32 / numCols;
    for(int i = 0; i < ARRAY_ELEMENTS(r)/4; i++)
    {
        for(int j = 0; j < numCols; j++)
        {
            printf("%5s: 0x%08X    ", regnames[i + j*offset], r[i + j*offset]);
        }
        printf("\n");
    }
}

int main(int argc, char const *argv[])
{
    OptionParser parser = OptionParser().description("BCM Register Utility");

    parser.add_option("-f", "--function")
            .dest("function")
            .type("int")
            .set_default("0")
            .metavar("FUNCTION")
            .help("Read registers from the specified pci function.");


    parser.add_option("-r", "--reset")
            .dest("reset")
            .set_default("0")
            .action("store_true")
            .help("Issue a device reset request.");

    parser.add_option("-s", "--step")
            .dest("step")
            .set_default("0")
            .action("store_true")
            .help("Single step the CPU.");

    parser.add_option("-c", "--context")
            .dest("context")
            .set_default("0")
            .action("store_true")
            .help("Print the current CPU context.");

    parser.add_option("-g", "--run")
            .dest("run")
            .set_default("0")
            .action("store_true")
            .help("Continue CPU execution.");

    parser.add_option("-i", "--info")
            .dest("info")
            .set_default("0")
            .action("store_true")
            .help("Print device information registers.");

    parser.add_option("-m", "--mii")
            .dest("mii")
            .set_default("0")
            .action("store_true")
            .help("Print MII information registers.");


    optparse::Values options = parser.parse_args(argc, argv);
    vector<string> args = parser.args();


    if(!initHAL(NULL, options.get("function")))
    {
        cerr << "Unable to locate pci device with function " << (int)options.get("function") << endl;
        exit(-1);
    }


    if(options.get("reset"))
    {
        cout << "Resetting...\n";
        RegDEVICERxRiscMode_t mode;
        mode.r32 = 0;
        mode.bits.Reset = 1;
        DEVICE.RxRiscMode = mode;
        exit(0);
    }

    if(options.get("step"))
    {
        cout << "Stepping...\n";
        RegDEVICERxRiscMode_t mode;
        mode.r32 = 0;
        mode.bits.SingleStep = 1;
        mode.bits.Halt = 1;
        DEVICE.RxRiscMode = mode;

        print_context();
        exit(0);
    }

    if(options.get("context"))
    {
        print_context();
        exit(0);
    }

    if(options.get("run"))
    {
        cout << "Running...\n";
        RegDEVICERxRiscMode_t mode;
        mode.r32 = 0; // Ensure single-step and halt are cleared
        DEVICE.RxRiscMode = mode;
        exit(0);
    }

    if(options.get("mii"))
    {
        uint8_t phy = MII_getPhy();
        printf("MII Phy:          %d\n", phy);
        printf("MII Control:      0x%04X\n", MII_readRegister(phy, REG_MII_CONTROL));
        printf("MII Status:       0x%04X\n", MII_readRegister(phy, REG_MII_STATUS));
        printf("MII PHY ID[high]: 0x%04X\n", MII_readRegister(phy, REG_MII_PHY_ID_HIGH));
        printf("MII PHY ID[low]:  0x%04X\n", MII_readRegister(phy, REG_MII_PHY_ID_LOW));

        MII_selectBlock(0, 0x8010);
        printf("0x1A (0x8010):    0x%04X\n", MII_readRegister(0, (mii_reg_t)0x1A));
        MII_selectBlock(0, 0);

        exit(0);
    }


    if(options.get("info"))
    {
        printf("Firmware Ver:    0x%08X\n", (uint32_t)GEN.GenFwVersion.r32);
        printf("Chip Id:         0x%08X\n", (uint32_t)DEVICE.ChipId.r32);
        printf("Vendor ID:       0x%04X         Device ID: 0x%04X\n", (uint16_t)DEVICE.PciVendorDeviceId.bits.VendorID, (uint16_t)DEVICE.PciVendorDeviceId.bits.DeviceID);
        printf("Subsystem Vend:  0x%04X      Subsystem ID: 0x%04X\n", (uint16_t)DEVICE.PciSubsystemId.bits.SubsystemVendorID, (uint16_t)DEVICE.PciSubsystemId.bits.SubsystemID);
        printf("Class Code Rev:  0x%08X\n", (uint32_t)DEVICE.PciClassCodeRevision.r32);
        printf("Function En:     0x%X\n", (uint32_t)DEVICE.Status.bits.FunctionEnable);
        printf("Function Num:    %d\n", (uint32_t)DEVICE.Status.bits.FunctionNumber);


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

        // RegDEVICEStatus_t


        // RegDEVICEFastBootProgramCounter_t
        // RegDEVICEExpansionRomAddr_t

        // RegDEVICEMiscellaneousLocalControl_t
        // RegDEVICETimer_t

        // RegDEVICEEmacMode_t
        // RegDEVICELedControl_t

        // RegDEVICEPciPowerConsumptionInfo_t
        // RegDEVICEPciPowerDissipatedInfo_t

        // RegDEVICEMtuSize_t

        // RegDEVICEReceiveMacMode_t

        // RegDEVICELinkAwarePowerModeClockPolicy_t
        // RegDEVICEClockSpeedOverridePolicy_t
        // RegDEVICEClockStatus_t
        // RegDEVICETopLevelMiscellaneousControl1_t

        // RegDEVICEMemoryArbiterMode_t

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
        printf("GphyControlStatus:  0x%08X\n", (uint32_t)DEVICE.GphyControlStatus.r32);
        printf("TopLevelMiscellaneousControl1: 0x%08X\n", (uint32_t)DEVICE.TopLevelMiscellaneousControl1.r32);
        printf("MiscellaneousLocalControl:     0x%08X\n", (uint32_t)DEVICE.MiscellaneousLocalControl.r32);

        exit(0);
    }


    printf("APEChipId: %x\n", (uint32_t)APE.ChipId.r32);

    printf("EmacMode.PortMode: %0x\n", (uint32_t)DEVICE.EmacMode.bits.PortMode);
    printf("RxRiscMode: %0x\n", (uint32_t)DEVICE.RxRiscMode.r32);

    // printf("HostDriverId: %0x\n", APE.HostDriverId.r32);
    // printf("RcpuPciSubsystemId: %0x\n", APE.RcpuPciSubsystemId.r32);

    print_context();

    return 0;
}
