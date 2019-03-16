////////////////////////////////////////////////////////////////////////////////
///
/// @file       main.c
///
/// @project
///
/// @brief      Main stage2 code
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

#include <MII.h>
#include <bcm5719_DEVICE.h>

void init_mii(void)
{
    uint8_t phy = MII_getPhy();

    // Set MII_REG_CONTROL to RESET; wait until RESET bit clears.
    MII_reset(phy);

    // Mask REG_MDI_CONTROL bits 0x4. MDI Select must be cleared to enable Auto-Access mode for the MAC.
    DEVICE.MdiControl.r32 &= ~0x4;

    // Set MII (SHADOW 0x05):0x1C as desired. e.g. CLK125_OUTPUT_ENABLE, SIGDET_DEASSERT_TIMER_LENGTHEN, DISABLE_LOW_POWER_10BASET_LINK_MODE, LOW_POWER_ENC_DISABLE.
    // uint16_t shadow = MII_readRegister(phy, )
    RegMIISpareControl3_t sc3;
    sc3.r16 = 0; // MII_readRegister(phy, (mii_reg_t)REG_MII_SPARE_CONTROL_3);
    sc3.bits.CLK125OutputEnable = 1;
    sc3.bits.SIGDETDeassertTimerLengthen = 1;
    sc3.bits.DisableLowPowerTOBase_TLinkMode = 1;
    sc3.bits.LowPowerENCDisable = 1;
    MII_writeRegister(phy, (mii_reg_t)REG_MII_SPARE_CONTROL_3, sc3.r16);

    // Set MII_REG_1000BASE_T_CONTROL as desired (e.g. ADVERTISE_FULL_DUPLEX|ADVERTISE_HALF_DUPLEX).
    RegMII1000baseTControl_t gig_control;
    gig_control.r16 = 0;
    gig_control.bits.Advertise1000BASE_THalfDuplex = 1;
    gig_control.bits.Advertise1000BASE_TFullDuplex = 1;
    MII_writeRegister(phy, (mii_reg_t)REG_MII_1000BASE_T_CONTROL, gig_control.r16);

    // Set MII_REG_AUTO_NEGOTIATION_ADVERTISEMENT as desired (pretty much enable PROTOCOL_SELECT__IEEE_802_3 and all the full/half duplex options).
    RegMIIAutonegotiationAdvertisement_t auto_neg_advert;
    auto_neg_advert.r16 = 0; //MII_readRegister(phy, (mii_reg_t)REG_MII_AUTONEGOTIATION_ADVERTISEMENT);
    auto_neg_advert.bits.ProtocolSelect = MII_AUTONEGOTIATION_ADVERTISEMENT_PROTOCOL_SELECT_IEEE_802_3;
    auto_neg_advert.bits._10BASE_THalfDuplexCapable = 1;
    auto_neg_advert.bits._10BASE_TFullDuplexCapable = 1;
    auto_neg_advert.bits._100BASE_TXHalfDuplexCapable = 1;
    auto_neg_advert.bits._100BASE_TXFullDuplexCapable = 1;
    MII_writeRegister(phy, (mii_reg_t)REG_MII_AUTONEGOTIATION_ADVERTISEMENT, auto_neg_advert.r16);
}

int main()
{
    init_mii();

    // Set REG_EMAC_MODE__PORT_MODE based on REG_STATUS__ETHERNET_LINK_STATUS (GPHY) or REG_SGMII_STATUS__LINK_STATUS (SERDES).
    if(DEVICE.SgmiiStatus.bits.MediaSelectionMode)
    {
        // SERDES
        DEVICE.EmacMode.bits.PortMode = DEVICE.SgmiiStatus.bits.LinkStatus;
    }
    else
    {
        // GPHY
        DEVICE.EmacMode.bits.PortMode = DEVICE.Status.bits.EthernetLinkStatus;
    }

    // Set REG_LINK_AWARE_POWER_MODE_CLOCK_POLICY__MAC_CLOCK_SWITCH__6_25MHZ.
    DEVICE.LinkAwarePowerModeClockPolicy.bits.MACClockSwitch = DEVICE_LINK_AWARE_POWER_MODE_CLOCK_POLICY_MAC_CLOCK_SWITCH_6_25MHZ;

    // Set/mask REG_CPMU_CONTROL__LINK_{AWARE,IDLE,SPEED}_POWER_MODE_ENABLE as desired (from NVM).
    // RegDEVICECpmuControl_t cpmu_control = DEVICE.Cpmu.Control;


    // End of main init:

    // Mask REG_CLOCK_SPEED_OVERRIDE_POLICY__MAC_CLOCK_SPEED_OVERRIDE_ENABLE.

    // Set GEN_FIRMWARE_MBOX to BOOTCODE_READY_MAGIC.

    // Do main loop.
}
