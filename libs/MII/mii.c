////////////////////////////////////////////////////////////////////////////////
///
/// @file       MII.c
///
/// @project
///
/// @brief      MII Support Routines
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
#if __mips__
#include <bcm5719_DEVICE.h>
#else
#include <APE_DEVICE.h>
#endif

#ifdef CXX_SIMULATOR
#define volatile
#endif

static bool __attribute__((noinline)) MII_wait(volatile DEVICE_t *device)
{
    uint32_t maxWait = 0xffff;
    // Wait for the status bit to be clear.
    while (device->MiiCommunication.bits.Start_DIV_Busy && maxWait)
    {
        // Waiting...
        maxWait--;
    }

    return maxWait ? true : false;
}

uint8_t MII_getPhy(volatile DEVICE_t *device)
{
    if (device->SgmiiStatus.bits.MediaSelectionMode)
    {
        // SERDES platform
        return device->Status.bits.FunctionNumber + DEVICE_MII_COMMUNICATION_PHY_ADDRESS_SGMII_0;
    }
    else
    {
        // GPHY platform
        return device->Status.bits.FunctionNumber + DEVICE_MII_COMMUNICATION_PHY_ADDRESS_PHY_0;
    }
}

static int32_t MII_readRegisterInternal(volatile DEVICE_t *device, uint8_t phy, mii_reg_t reg)
{
    union
    {
        uint8_t addr;
        mii_reg_t reg;
    } caster;
    caster.reg = reg;

    RegDEVICEMiiCommunication_t regcontents;
    regcontents.r32 = 0;
    regcontents.bits.Command = DEVICE_MII_COMMUNICATION_COMMAND_READ;
    regcontents.bits.Start_DIV_Busy = 1;
    regcontents.bits.PHYAddress = phy;
    regcontents.bits.RegisterAddress = caster.addr;

    // Ensure there are no active transactions
    if (!MII_wait(device))
    {
        // Unable to read
        return -1;
    }

    // Start the transaction
    device->MiiCommunication = regcontents;

    // Wait for transaction to complete.
    if (!MII_wait(device))
    {
        // Unable to read
        return -1;
    }

    return device->MiiCommunication.bits.TransactionData;
}

static bool MII_writeRegisterInternal(volatile DEVICE_t *device, uint8_t phy, mii_reg_t reg, uint16_t data)
{
    RegDEVICEMiiCommunication_t regcontents;
    regcontents.r32 = 0;
    regcontents.bits.Command = DEVICE_MII_COMMUNICATION_COMMAND_WRITE;
    regcontents.bits.Start_DIV_Busy = 1;
    regcontents.bits.PHYAddress = phy;
    regcontents.bits.RegisterAddress = reg;
    regcontents.bits.TransactionData = data;

    // Ensure there are no active transactions
    if (!MII_wait(device))
    {
        // Unable to read
        return false;
    }

    // Start the transaction
    device->MiiCommunication = regcontents;

    // Wait for transaction to complete (not strictly required for writes).
    if (!MII_wait(device))
    {
        // Unable to read
        return false;
    }

    return true;
}

static int32_t MII_readShadowRegister18(volatile DEVICE_t *device, uint8_t phy, mii_reg_t reg)
{
    // Write register 18h, bits [2:0] = 111 This selects the Miscellaneous
    // Control register, shadow 7h. All reads must be performed through the
    // Miscellaneous Control register. Bit 15 = 0 This allows only bits [14:12]
    // and bits [2:0] to be written. Bits [14:12] = zzz This selects shadow
    // register zzz to be read. Bits [11: 3] = <don't care> When bit 15 = 0,
    // these bits are ignored. Bits [2:0] = 111 This sets the Shadow Register
    // Select to 111 (Miscellaneous Control register). Read register 18h Data
    // read back is the value from shadow register zzz.

    // --------------------------------------------
    // PHY 0x18 Shadow 0x1 register read Procedure
    // --------------------------------------------
    // int value;
    // phy_write(0x18, 0x1007); //switch to shadow 0x1
    // valu = phy_read(0x18);

    uint16_t shadow_reg = reg >> 8;
    RegMIIMiscellaneousControl_t shadow_select;
    shadow_select.r16 = 0;
    shadow_select.bits.ShadowRegisterReadSelector = shadow_reg;
    shadow_select.bits.ShadowRegisterSelector = 7;
    if(MII_writeRegisterInternal(device, phy, (mii_reg_t)0x18, shadow_select.r16))
    {
        return MII_readRegisterInternal(device, phy, (mii_reg_t)0x18);
    }
    else
    {
        return -1;
    }
}

static int32_t MII_readShadowRegister1C(volatile DEVICE_t *device, uint8_t phy, mii_reg_t reg)
{
    // --------------------------------------------
    // PHY 0x1C Shadow 0x1 register read Procedure
    // --------------------------------------------
    // int value;
    // phy_write(0x1C, 0x0400); //switch to shadow 0x1
    // value = phy_read(0x1C);
    // return value;

    uint16_t shadow_reg = reg >> 8;
    RegMIICabletronLed_t shadow_select;
    shadow_select.r16 = 0;
    shadow_select.bits.ShadowRegisterSelector = shadow_reg;
    MII_writeRegisterInternal(device, phy, (mii_reg_t)0x1C, shadow_select.r16);

    return MII_readRegisterInternal(device, phy, (mii_reg_t)0x1C);
}

int32_t MII_readRegister(volatile DEVICE_t *device, uint8_t phy, mii_reg_t reg)
{
    if ((reg & 0xFF) == 0x1C)
    {
        return MII_readShadowRegister1C(device, phy, reg);
    }
    else if ((reg & 0xFF) == 0x18)
    {
        return MII_readShadowRegister18(device, phy, reg);
    }
    else
    {
        return MII_readRegisterInternal(device, phy, reg);
    }
}

static bool MII_writeShadowRegister18(volatile DEVICE_t *device, uint8_t phy, mii_reg_t reg, uint16_t data)
{
    // Set Bits [15:3] = Preferred write values Bits [15:3] contain the desired
    // bits to be written to. Set Bits [2:0] = yyy This enables shadow register
    // yyy to be written. For shadow 7h, bit 15 must also be written.

    // --------------------------------------------
    // PHY 0x18 Shadow 0x2 register write Procedure
    // --------------------------------------------
    // int wdata;
    // phy_write(0x18, 0x2007); //switch to shadow 0x2
    // phy_write(0x18, wdata | 0x2 );

    uint16_t shadow_reg = reg >> 8;
    RegMIIMiscellaneousControl_t shadow_select;
    shadow_select.r16 = 0;
    shadow_select.bits.ShadowRegisterReadSelector = shadow_reg;
    shadow_select.bits.ShadowRegisterSelector = 7;
    if(MII_writeRegisterInternal(device, phy, (mii_reg_t)REG_MII_AUXILIARY_CONTROL, shadow_select.r16))
    {
        RegMIIMiscellaneousControl_t write_data;
        write_data.r16 = data;
        write_data.bits.ShadowRegisterSelector = shadow_reg;

        return MII_writeRegisterInternal(device, phy, (mii_reg_t)REG_MII_AUXILIARY_CONTROL, write_data.r16);
    }

    return false;
}

static bool MII_writeShadowRegister1C(volatile DEVICE_t *device, uint8_t phy, mii_reg_t reg, uint16_t data)
{
    // --------------------------------------------
    // PHY 0x1C Shadow 0x2 register write Procedure
    // --------------------------------------------
    // int wdata;
    // phy_write(0x1C, 0x0800); //switch to shadow 0x2
    // phy_write(0x1C, wdata | 0x8800 );

    uint16_t shadow_reg = reg >> 8;
    RegMIICabletronLed_t shadow_select;
    shadow_select.r16 = 0;
    shadow_select.bits.ShadowRegisterSelector = shadow_reg;
    if(MII_writeRegisterInternal(device, phy, (mii_reg_t)REG_MII_CABLETRON_LED, shadow_select.r16))
    {
        RegMIICabletronLed_t write_data;
        write_data.r16 = data;
        write_data.bits.ShadowRegisterSelector = shadow_reg;
        write_data.bits.WriteEnable = 1;

        return MII_writeRegisterInternal(device, phy, (mii_reg_t)REG_MII_CABLETRON_LED, write_data.r16);
    }

    return false;
}

bool MII_writeRegister(volatile DEVICE_t *device, uint8_t phy, mii_reg_t reg, uint16_t data)
{
    if ((reg & 0xFF) == 0x1C)
    {
        return MII_writeShadowRegister1C(device, phy, reg, data);
    }
    else if ((reg & 0xFF) == 0x18)
    {
        return MII_writeShadowRegister18(device, phy, reg, data);
    }
    else
    {
        return MII_writeRegisterInternal(device, phy, reg, data);
    }
}

bool MII_selectBlock(volatile DEVICE_t *device, uint8_t phy, uint16_t block)
{
    // Write register 0x1f with the block.
    return MII_writeRegister(device, phy, (mii_reg_t)REG_MII_BLOCK_SELECT, block);
}

int32_t MII_getBlock(volatile DEVICE_t *device, uint8_t phy)
{
    // Write register 0x1f with the block.
    return MII_readRegister(device, phy, (mii_reg_t)REG_MII_BLOCK_SELECT);
}

bool MII_reset(volatile DEVICE_t *device, uint8_t phy)
{
    // Set MII_REG_CONTROL to RESET; wait until RESET bit clears.
    if(MII_writeRegister(device, phy, (mii_reg_t)REG_MII_CONTROL, MII_CONTROL_RESET_MASK))
    {
        do
        {
            // Spin
        } while ((MII_readRegister(device, phy, (mii_reg_t)REG_MII_CONTROL) & MII_CONTROL_RESET_MASK) == MII_CONTROL_RESET_MASK);

        return true;
    }
    return false;
}
