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
#include <bcm5719_DEVICE.h>

static void MII_wait(void)
{
    // Wait for the status bit to be clear.
    while (DEVICE.MiiCommunication.bits.Start_DIV_Busy)
    {
        // Waiting...
    }
}

uint8_t MII_getPhy(void)
{
    if(DEVICE.SgmiiStatus.bits.MediaSelectionMode)
    {
        // SERDES platform
        return DEVICE.Status.bits.FunctionNumber + DEVICE_MII_COMMUNICATION_PHY_ADDRESS_SGMII_0;
    }
    else
    {
        // GPHY platform
        return DEVICE.Status.bits.FunctionNumber + DEVICE_MII_COMMUNICATION_PHY_ADDRESS_PHY_0;
    }
}

uint16_t MII_readRegister(uint8_t phy, mii_reg_t reg)
{
    union {
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
    MII_wait();

    // Start the transaction
    DEVICE.MiiCommunication = regcontents;

    // Wait for transaction to complete.
    MII_wait();

    return DEVICE.MiiCommunication.bits.TransactionData;
}

void MII_writeRegister(uint8_t phy, mii_reg_t reg, uint16_t data)
{
    union {
        uint8_t addr;
        mii_reg_t reg;
    } caster;
    caster.reg = reg;

    RegDEVICEMiiCommunication_t regcontents;
    regcontents.r32 = 0;
    regcontents.bits.Command = DEVICE_MII_COMMUNICATION_COMMAND_WRITE;
    regcontents.bits.Start_DIV_Busy = 1;
    regcontents.bits.PHYAddress = phy;
    regcontents.bits.RegisterAddress = caster.addr;
    regcontents.bits.TransactionData = data;

    // Ensure there are no active transactions
    MII_wait();

    // Start the transaction
    DEVICE.MiiCommunication = regcontents;

    // Wait for transaction to complete (not strictly required for writes).
    MII_wait();
}

void MII_selectBlock(uint8_t phy, uint16_t block)
{
    // Write register 0x1f with the block.
    MII_writeRegister(phy, REG_MII_BLOCK_SELECT, block);
}

uint16_t MII_getBlock(uint8_t phy)
{
    // Write register 0x1f with the block.
    return MII_readRegister(phy, REG_MII_BLOCK_SELECT);
}
