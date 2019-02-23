////////////////////////////////////////////////////////////////////////////////
///
/// @file       init_hw.c
///
/// @project
///
/// @brief      Hardware initialization routines for stage1
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

#include <MII.h>
#include <bcm5719_DEVICE.h>
#include <bcm5719_GEN.h>
#include <bcm5719_RXMBUF.h>
#include <bcm5719_TXMBUF.h>
#include <bcm5719_SDBCACHE.h>
#include <stdbool.h>
#include <stdint.h>

void *memset(void *s, int c, size_t n)
{
#if CXX_SIMULATOR
    // TODO: Use the memory window to set everything.
#else
    // We assume things are aligned here...
    uint32_t* buffer = s;
    for(int i = 0; i <  n/4; i++)
    {
        buffer[i] = c;
    }
#endif
    return s;
}

static inline bool is_nic(void)
{
    // If DEVICE.Status.bits.VMAINPowerStatus is set we are in NIC mode,
    // otherwise LoM mode.
    return (1 == DEVICE.Status.bits.VMAINPowerStatus);
}

void init_mii_function0(void)
{
    // MIIPORT 0 (0x8010):0x1A |= 0x4000
    MII_selectBlock(0, 0x8010);
    uint16_t r1Ah_value = MII_readRegister(0, (mii_reg_t)0x1A);
    r1Ah_value |= 0x4000;
    MII_writeRegister(0, (mii_reg_t)0x1A, r1Ah_value);

    // (Note: This is done in a retry loop which verifies the block select by
    // reading 0x1F and confirming it reads 0x8610
    do
    {
        MII_selectBlock(0, 0x8610);
    } while (0x8610 != MII_getBlock(0));

    // MIIPORT 0 (0x8610):0x15, set bits 0:1 to 2.
    uint16_t r15h_value = MII_readRegister(0, (mii_reg_t)0x15);
    r15h_value &= ~0x3;
    r15h_value |= 0x2;
    MII_writeRegister(0, (mii_reg_t)0x15, r15h_value);

    // and then verifies that bits 0:1 have been set to 2, and retries about a
    // dozen times until the block select and write are both correct. Probably
    // an attempt to work around some bug or weird asynchronous behaviour for
    // these unknown MII registers.)
    do
    {
        r15h_value = MII_readRegister(0, (mii_reg_t)0x15);
    } while (2 != (r15h_value & 0x3));

    // (0x8010):0x1A, mask 0x4000.
    MII_selectBlock(0, 0x8010);
    r1Ah_value &= ~0x4000;
    MII_writeRegister(0, (mii_reg_t)0x1A, r1Ah_value);

    MII_selectBlock(0, 0);
}

void init_mii(void)
{
    //     MII init for all functions (MIIPORT determined by function/PHY type):
    // Set MII_REG_CONTROL to AUTO_NEGOTIATION_ENABLE.
    uint8_t phy = MII_getPhy();
    RegMIIControl_t control;
    control.r16 = MII_readRegister(phy, REG_MII_CONTROL);
    control.bits.AutoNegotiationEnable = 1;
    MII_writeRegister(phy, REG_MII_CONTROL, control.r16);
}

void __attribute__((noinline)) zero_bss(void)
{
#if !CXX_SIMULATOR
    // Zero BSS information, will always be word aligned.
    extern uint32_t _fbss[];
    extern uint32_t _ebss[];

    memset(_fbss, 0, (_ebss - _fbss) *  4);
#endif
}

void early_init_hw(void)
{
    // Enable memory arbitration
    DEVICE.MemoryArbiterMode.bits.Enable = 1;

    // Disable data cache.
    DEVICE.RxRiscMode.bits.EnableDataCache = 0;

    zero_bss();

    // Enable various ape bits.
    RegDEVICEPciState_t pcistate = DEVICE.PciState;
    pcistate.bits.APEControlRegisterWriteEnable = 1;
    pcistate.bits.APESharedMemoryWriteEnable = 1;
    pcistate.bits.APEProgramSpaceWriteEnable = 1;
    DEVICE.PciState = pcistate;

    // Configure GPHY
    RegDEVICEGphyControlStatus_t gphystate = DEVICE.GphyControlStatus;
    gphystate.bits.GPHYIDDQ = 0;               // Power on GPHY
    gphystate.bits.BIASIDDQ = 0;               // Power on BIAS
    gphystate.bits.SGMII_DIV_PCSPowerDown = 0; // Power on SGMII
    gphystate.bits.TLPClockSource = 0;         // TLP Clock from PCIE SERDES

    if (is_nic())
    {
        // VMAIN ON, NIC (not LoM)
        gphystate.bits.TLPClockSource = 1;
    }

    DEVICE.GphyControlStatus = gphystate;
}


void init_mac(NVRAMContents_t *nvram)
{
    int function = DEVICE.Status.bits.FunctionNumber;
    uint64_t mac0 = nvram->info.macAddr0;
    uint64_t my_mac = mac0; // default.
    DEVICE.EmacMacAddresses0High.r32 = mac0 >> 32;
    DEVICE.EmacMacAddresses0Low.r32  = mac0;

    uint64_t mac1 = nvram->info.macAddr1;
    if(1 == function)
    {
        my_mac = mac1;
    }
    DEVICE.EmacMacAddresses1High.r32 = mac1 >> 32;
    DEVICE.EmacMacAddresses1Low.r32  = mac1;

    uint64_t mac2 = nvram->info2.macAddr2;
    if(2 == function)
    {
        my_mac = mac2;
    }
    DEVICE.EmacMacAddresses2High.r32 = mac2 >> 32;
    DEVICE.EmacMacAddresses2Low.r32  = mac2;

    uint64_t mac3 = nvram->info2.macAddr3;
    if(3 == function)
    {
        my_mac = mac3;
    }
    DEVICE.EmacMacAddresses3High.r32 = mac3 >> 32;
    DEVICE.EmacMacAddresses3Low.r32  = mac3;

    // Store mac / serial number.
    DEVICE.PciSerialNumberHigh.r32 = my_mac >> 32;
    GEN.GenMacAddrHighMbox.r32 = my_mac >> 32;

    DEVICE.PciSerialNumberLow.r32  = my_mac;
    GEN.GenMacAddrLowMbox.r32 = my_mac;
}

uint32_t translate_power_budget(uint16_t raw)
{
    RegDEVICEPciPowerBudget0_t translator;
    translator.r32 = 0;
    if(raw)
    {
        translator.bits.BasePower = (raw) & 0xFF;
        translator.bits.DataScale = DEVICE_PCI_POWER_BUDGET_0_DATA_SCALE_0_1X;
        translator.bits.PMState   = ((raw) & 0x0300) >> 8;
        translator.bits.Type      = ((raw) & 0x1C00) >> 10;
        translator.bits.PowerRail = ((raw) & 0xE000) >> 13;

    }

    return translator.r32;
}

void init_power(NVRAMContents_t *nvram)
{
    // PCI power dissipated / consumed
    DEVICE.PciPowerConsumptionInfo.r32 = nvram->info.powerConsumed;
    DEVICE.PciPowerDissipatedInfo.r32  = nvram->info.powerDissipated;

    // Power Budget
    uint32_t pb_raw0 = (nvram->info.powerBudget0) & 0xffff;
    uint32_t pb_raw1 = (nvram->info.powerBudget0) >> 16;
    uint32_t pb_raw2 = (nvram->info.powerBudget1) & 0xffff;
    uint32_t pb_raw3 = (nvram->info.powerBudget1) >> 16;
    uint32_t pb_raw4 = (nvram->info.powerBudget2) & 0xffff;
    uint32_t pb_raw5 = (nvram->info.powerBudget2) >> 16;
    uint32_t pb_raw6 = (nvram->info.powerBudget3) & 0xffff;
    uint32_t pb_raw7 = (nvram->info.powerBudget3) >> 16;

    DEVICE.PciPowerBudget0.r32 = translate_power_budget(pb_raw0);
    DEVICE.PciPowerBudget1.r32 = translate_power_budget(pb_raw1);
    DEVICE.PciPowerBudget2.r32 = translate_power_budget(pb_raw2);
    DEVICE.PciPowerBudget3.r32 = translate_power_budget(pb_raw3);
    DEVICE.PciPowerBudget4.r32 = translate_power_budget(pb_raw4);
    DEVICE.PciPowerBudget5.r32 = translate_power_budget(pb_raw5);
    DEVICE.PciPowerBudget6.r32 = translate_power_budget(pb_raw6);
    DEVICE.PciPowerBudget7.r32 = translate_power_budget(pb_raw7);
}

uint16_t nvm_get_subsystem_device(NVRAMContents_t* nvram)
{
    switch(MII_getPhy())
    {
        /* SERDES */
        case DEVICE_MII_COMMUNICATION_PHY_ADDRESS_SGMII_0:
            return nvram->info2.pciSubsystemF0SERDES;
        case DEVICE_MII_COMMUNICATION_PHY_ADDRESS_SGMII_1:
            return nvram->info2.pciSubsystemF1SERDES;
        case DEVICE_MII_COMMUNICATION_PHY_ADDRESS_SGMII_2:
            return nvram->info2.pciSubsystemF2SERDES;
        case DEVICE_MII_COMMUNICATION_PHY_ADDRESS_SGMII_3:
            return nvram->info2.pciSubsystemF3SERDES;

        /* GPHY */
        case DEVICE_MII_COMMUNICATION_PHY_ADDRESS_PHY_0:
            return nvram->info2.pciSubsystemF0GPHY;
        case DEVICE_MII_COMMUNICATION_PHY_ADDRESS_PHY_1:
            return nvram->info2.pciSubsystemF1GPHY;
        case DEVICE_MII_COMMUNICATION_PHY_ADDRESS_PHY_2:
            return nvram->info2.pciSubsystemF2GPHY;
        case DEVICE_MII_COMMUNICATION_PHY_ADDRESS_PHY_3:
            return nvram->info2.pciSubsystemF3GPHY;

        default:
            // Unknown. use nvm default.
            return nvram->info.subsystemDeviceID;
    }
}

void init_pci(NVRAMContents_t* nvram)
{
    // PCI Device / Vendor ID.
    RegDEVICEPciVendorDeviceId_t vendor_device;
    vendor_device.r32 = 0;
    vendor_device.bits.DeviceID = nvram->info.deviceID;
    vendor_device.bits.VendorID = nvram->info.vendorID;
    DEVICE.PciVendorDeviceId = vendor_device;

    // PCI Subsystem
    RegDEVICEPciSubsystemId_t subsystem;
    subsystem.r32 = 0;
    subsystem.bits.SubsystemVendorID = nvram->info.subsystemVendorID;
    subsystem.bits.SubsystemID = nvm_get_subsystem_device(nvram);
    DEVICE.PciSubsystemId = subsystem;

    // RegDEVICEPciClassCodeRevision_t partially from REG_CHIP_ID
}

void init_gen(NVRAMContents_t* nvram)
{
    int function = DEVICE.Status.bits.FunctionNumber;
    uint32_t cfg_feature;
    uint32_t cfg_hw;
    uint32_t cfg_hw2;

    switch(function)
    {
        default:
        case 0:
            cfg_feature = nvram->info.func0CfgFeature;
            cfg_hw      = nvram->info.func0CfgHW;
            cfg_hw2     = nvram->info2.func0CfgHW2;
            break;

        case 1:
            cfg_feature = nvram->info.func1CfgFeature;
            cfg_hw      = nvram->info.func1CfgHW;
            cfg_hw2     = nvram->info2.func1CfgHW2;
            break;

        case 2:
            cfg_feature = nvram->info2.func2CfgFeature;
            cfg_hw      = nvram->info2.func2CfgHW;
            cfg_hw2     = nvram->info2.func2CfgHW2;
            break;

        case 3:
            cfg_feature = nvram->info2.func3CfgFeature;
            cfg_hw      = nvram->info2.func3CfgHW;
            cfg_hw2     = nvram->info2.func3CfgHW2;
            break;
    }

    GEN.GenCfgFeature.r32 = cfg_feature;
    GEN.GenCfgHw.r32 = cfg_hw;
    GEN.GenCfgHw2.r32 = cfg_hw2;
    GEN.GenCfgShared.r32 = nvram->info.cfgShared;
    GEN.GenCfg5.r32 = nvram->info2.cfg5;
}

void load_nvm_config(NVRAMContents_t *nvram)
{
    // Load information from NVM, set various registers + mem

    // MAC Addr, serial number
    init_mac(nvram);

    // firmware revision
    // mfrDate


    // Power
    init_power(nvram);

    // REG_PCI_SUBSYSTEM_ID, vendor, class, rev
    init_pci(nvram);

    init_gen(nvram);
}

void init_hw(NVRAMContents_t *nvram)
{
    // Zero out ram - gencom, db cache, tx/rx mbuf, others in mem map
    memset((void*)&GEN, 0, REG_GEN_SIZE);
    memset((void*)&RXMBUF, 0, REG_RXMBUF_SIZE);
    memset((void*)&TXMBUF, 0, REG_TXMBUF_SIZE);
    memset((void*)&SDBCACHE, 0, REG_SDBCACHE_SIZE);

    reportStatus(STATUS_INIT_HW, 0);
    // Misc regs init

    // Mask REG 0x64C0 bits 0x7FF, or bits 0x0010. This register is unknown.
    DEVICE._64c0.r32 = (DEVICE._64c0.r32 & ~0x7FFu) | 0x10;

    // Set unknown REG 0x64C8 to 0x1004.
    DEVICE._64c8.r32 = 0x00001004;

    // Enable MAC clock speed override
    RegDEVICEClockSpeedOverridePolicy_t clockspeed;
    clockspeed.r32 = 0;
    clockspeed.bits.MACClockSpeedOverrideEnabled = 1;
    DEVICE.ClockSpeedOverridePolicy = clockspeed;

    // Mask REG 0x64DC bits 0x0F, or bits 0x01. Unknown.
    DEVICE._64dc.r32 = (DEVICE._64dc.r32 & ~0xFu) | 0x01;

    // Mask REG 0x64DC bits 0xC00, set ... TODO
    // value from talos: 0x00315E42
    DEVICE._64dc.r32 &= ~0xC00;

    // Unknown stuff involving REG 0x6530, REG 0x65F4, depends on config, TODO
    // Value from Talos:0x6530z 0x6530 -> 0x00000000, 0x65F4 -> 0x00000109.


    // REG_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL: Set BD and NonLSO
    // fields to 4K.
    RegDEVICELsoNonlsoBdReadDmaCorruptionEnableControl_t reglso = DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl;
    reglso.bits.PCIRequestBurstLengthforBDRDMAEngine = DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_BD_RDMA_ENGINE_4K;
    reglso.bits.PCIRequestBurstLengthforNonLSORDMAEngine = DEVICE_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL_PCI_REQUEST_BURST_LENGTH_FOR_NONLSO_RDMA_ENGINE_4K;
    DEVICE.LsoNonlsoBdReadDmaCorruptionEnableControl = reglso;

    // Disable ECC.
    RegDEVICEGphyStrap_t gphyStrap = DEVICE.GphyStrap;
    gphyStrap.bits.TXMBUFECCEnable = 0;
    gphyStrap.bits.RXMBUFECCEnable = 0;
    gphyStrap.bits.RXCPUSPADECCEnable = 0;
    DEVICE.GphyStrap = gphyStrap;

    // LED Control
    // Value from Talos: 0x00000880: DEVICE_LED_CONTROL_LED_STATUS_1000_MASK | DEVICE_LED_CONTROL_LED_MODE_PHY_MODE_1
    RegDEVICELedControl_t ledControl = DEVICE.LedControl;
    ledControl.bits.LEDMode = DEVICE_LED_CONTROL_LED_MODE_PHY_MODE_1;
    DEVICE.LedControl = ledControl;

    // MISC Local Control
    // Value from Talos: 0x00020001, reserved bits

    // Set REG_EAV_REF_CLOCK_CONTROL as desired. This is initialized from
    // CFG_HW; the TIMESYNC_GPIO_MAPPING, APE_GPIO_{0,1,2,3} fields within it
    // are copied to the corresponding fields in REG_EAV_REF_CLOCK_CONTROL.

    // Optionally enable REG_GRC_MODE_CONTROL__TIME_SYNC_MODE_ENABLE.
    // Value from Talos: 0x00130034
    // Bit is not set on Talos w/ default firmware, disabled for now.

    // Enable const clock for MII
    DEVICE.MiiMode.bits.ConstantMDIO_DIV_MDCClockSpeed = 1;

    // Set or clear REG_GPHY_CONTROL_STATUS__SWITCHING_REGULATOR_POWER_DOWN as
    // desired.
    // Value from Talos:  0x02C01000
    // Bit is not set on Talos w/ default firmware, disabled for now.

    // Set or clear
    // REG_TOP_LEVEL_MISCELLANEOUS_CONTROL_1__NCSI_CLOCK_OUTPUT_DISABLE as
    // desired.
    // Value from Talos: 0x00000080
    // Bit is not set on Talos w/ default firmware, disabled for now.

    reportStatus(STATUS_INIT_HW, 0xf0);

    // Perform MII init.
    init_mii_function0();

    reportStatus(STATUS_INIT_HW, 0xf1);

    init_mii();

    reportStatus(STATUS_INIT_HW, 0xff);
}
