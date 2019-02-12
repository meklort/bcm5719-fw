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
#include <stdbool.h>
#include <stdint.h>

static inline bool is_nic(void)
{
    // If DEVICE.Status.bits.VMAINPowerStatus is set we are in NIC mode,
    // otherwise LoM mode.
    return (1 == DEVICE.Status.bits.VMAINPowerStatus);
}

void init_mii_function0(void)
{
    // MIIPORT 0 (0x8010):0x1A |= 0x4000
    // MIIPORT 0 (0x8610):0x15, set bits 0:1 to 2. (Note: This is done in a
    // retry loop which verifies the block select by reading 0x1F and confirming
    // it reads 0x8610, and then verifies that bits 0:1 have been set to 2, and
    // retries about a dozen times until the block select and write are both
    // correct. Probably an attempt to work around some bug or weird
    // asynchronous behaviour for these unknown MII registers.) MIIPORT 0
    // (0x8010):0x1A, mask 0x4000.
}

void init_mii(void)
{
    //     MII init for all functions (MIIPORT determined by function/PHY type):
    // Set MII_REG_CONTROL to AUTO_NEGOTIATION_ENABLE.
}

void init_hw(NVRAMContents_t *nvram)
{
    // Enable memory arbitration
    DEVICE.MemoryArbiterMode.bits.Enable = 1;

    // Disable data cache.
    DEVICE.RxRiscMode.bits.EnableDataCache = 0;

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

    // Load information from NVM, set various registers + mem

    // Zero out ram - gencom, db cache, tx/rx mbuf, others in mem map

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

    // Mask REG 0x64DC bits 0xC00, set ...

    // Unknown stuff involving REG 0x6530, REG 0x65F4, depends on config

    // REG_LSO_NONLSO_BD_READ_DMA_CORRUPTION_ENABLE_CONTROL: Set BD and NonLSO
    // fields to 4K.

    // Disable ECC.
    RegDEVICEGphyStrap_t gphyStrap = DEVICE.GphyStrap;
    gphyStrap.bits.TXMBUFECCEnable = 0;
    gphyStrap.bits.RXMBUFECCEnable = 0;
    gphyStrap.bits.RXCPUSPADECCEnable = 0;
    DEVICE.GphyStrap = gphyStrap;

    // LED Control

    // MISC LOcal Control

    // Set REG_EAV_REF_CLOCK_CONTROL as desired. This is initialized from
    // CFG_HW; the TIMESYNC_GPIO_MAPPING, APE_GPIO_{0,1,2,3} fields within it
    // are copied to the corresponding fields in REG_EAV_REF_CLOCK_CONTROL.

    // Optionally enable REG_GRC_MODE_CONTROL__TIME_SYNC_MODE_ENABLE.

    // Enable const clock for MII
    DEVICE.MiiMode.bits.ConstantMDIO_DIV_MDCClockSpeed = 1;

    // Set or clear REG_GPHY_CONTROL_STATUS__SWITCHING_REGULATOR_POWER_DOWN as
    // desired.

    // Set or clear
    // REG_TOP_LEVEL_MISCELLANEOUS_CONTROL_1__NCSI_CLOCK_OUTPUT_DISABLE as
    // desired.
    init_mii_function0();

    init_mii();
}
