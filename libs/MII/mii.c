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
    return DEVICE.Status.bits.FunctionNumber + 1;
}

uint16_t MII_readRegister(uint8_t phy, uint8_t reg)
{
    RegDEVICEMiiCommunication_t regcontents;
    regcontents.bits.Command = 2; // Read, FIXME
    regcontents.bits.PHYAddress = phy;
    regcontents.bits.RegisterAddress = reg;

    // Ensure there are no active transactions
    MII_wait();

    // Start the transaction
    DEVICE.MiiCommunication = regcontents;

    // Wait for transaction to complete.
    MII_wait();

    return DEVICE.MiiCommunication.bits.TransactionData;
}

void MII_writeRegister(uint8_t phy, uint8_t reg, uint16_t data)
{
    RegDEVICEMiiCommunication_t regcontents;
    regcontents.bits.Command = 2; // Read, FIXME
    regcontents.bits.PHYAddress = phy;
    regcontents.bits.RegisterAddress = reg;
    regcontents.bits.TransactionData = data;

    // Ensure there are no active transactions
    MII_wait();

    // Start the transaction
    DEVICE.MiiCommunication = regcontents;

    // Wait for transaction to complete (not strictly required for writes).
    MII_wait();
}
