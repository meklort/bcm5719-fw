////////////////////////////////////////////////////////////////////////////////
///
/// @file       MII.h
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
#ifndef MII_H
#define MII_H

#include <bcm5719_MII.h>
#include <stdint.h>

#ifdef CXX_SIMULATOR
typedef uint64_t    mii_reg_t;
#else
typedef uint8_t     mii_reg_t;
#endif

/**
 * @fn uint8_t MII_getPhy(void);
 *
 * @brief Determines the PHY address for the current CPU/Function
 *
 * @returns The PHY address
 */
uint8_t MII_getPhy(void);

/**
 * @fn uint16_t MII_readRegister(uint8_t PHY, uint8_t reg);
 */
uint16_t MII_readRegister(uint8_t phy, mii_reg_t reg);

/**
 * @fn void MII_writeRegister(uint8_t PHY, uint8_t reg, uint16_t data);
 */
void MII_writeRegister(uint8_t phy, mii_reg_t reg, uint16_t data);

/**
 * @fn void MII_selectBlock(uint8_t phy, uint16_t block);
 */
void MII_selectBlock(uint8_t phy, uint16_t block);

/**
 * @fn uint16_t MII_getBlock(uint8_t phy);
 */
uint16_t MII_getBlock(uint8_t phy);

/**
 * @fn void MII_reset(uint8_t phy);
 */
void MII_reset(uint8_t phy);

#endif /* MII_H */
