////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_SHM_CHANNEL1.h
///
/// @project    ape
///
/// @brief      APE_SHM_CHANNEL1
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
/// 3. Neither the name of the <organization> nor the
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

/** @defgroup APE_SHM_CHANNEL1_H    APE_SHM_CHANNEL1 */
/** @addtogroup APE_SHM_CHANNEL1_H
 * @{
 */
#ifndef APE_SHM_CHANNEL1_H
#define APE_SHM_CHANNEL1_H

#include <types.h>
#include "APE_SHM_CHANNEL0.h"

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_SHM_CHANNEL1_sim(void* base);
void init_APE_SHM_CHANNEL1(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_SHM_CHANNEL1_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_SHM_CHANNEL1_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_SHM_CHANNEL1_H_uint32_t;
#define APE_SHM_CHANNEL1_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_SHM_CHANNEL1_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_SHM_CHANNEL1_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_SHM_CHANNEL1_H_uint8_t;
typedef uint16_t APE_SHM_CHANNEL1_H_uint16_t;
typedef uint32_t APE_SHM_CHANNEL1_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_SHM_CHANNEL1_BASE ((volatile void*)0x60220a00) /* Device SHM Registers, function 0 */
#define REG_SHM_CHANNEL1_SIZE (sizeof(SHM_CHANNEL_t))

#define REG_SHM_CHANNEL1_NCSI_CHANNEL_INFO ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a00) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MCID ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a04) /* AEN Management Controller ID, set by BMC when sending AEN ENABLE command and used when sending AENs. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_AEN ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a08) /* Set via NCSI ENABLE AEN. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_BFILT ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a0c) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MFILT ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a10) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_SETTING_1 ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a14) /* This is the "Link Settings" value from NCSI Set Link. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_SETTING_2 ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a18) /* This is the "OEM Settings" value from NCSI Set Link. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_VLAN ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a1c) /* Receives VLAN mode from NCSI specification "Enable VLAN" command. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_ALT_HOST_MAC_HIGH ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a24) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_ALT_HOST_MAC_MID ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a28) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_ALT_HOST_MAC_LOW ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a2c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC0_HIGH ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a34) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC0_MID ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a38) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC0_LOW ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a3c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC1_HIGH ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a44) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC1_MID ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a48) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC1_LOW ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a4c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC2_HIGH ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a54) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC2_MID ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a58) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC2_LOW ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a5c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC3_HIGH ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a64) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC3_MID ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a68) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC3_LOW ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a6c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC0_VLAN_VALID ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a70) /* Nonzero indicates VLAN field is valid */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC0_VLAN ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a74) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC1_VLAN_VALID ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a78) /* Nonzero indicates VLAN field is valid */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_MAC1_VLAN ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a7c) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_STATUS ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a80) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_RESET_COUNT ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a84) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_PXE ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a88) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_DROPFIL ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a8c) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_SLINK ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220a90) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_DBG ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220aa0) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_CTRLSTAT_RX ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220ab0) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_CTRLSTAT_DROPPED ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220ab4) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_CTRLSTAT_TYPE_ERR ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220ab8) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_CTRLSTAT_BAD_CSUM ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220abc) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_CTRLSTAT_ALL_RX ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220ac0) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_CTRLSTAT_ALL_TX ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220ac4) /*  */
#define REG_SHM_CHANNEL1_NCSI_CHANNEL_CTRLSTAT_ALL_AEN ((volatile APE_SHM_CHANNEL1_H_uint32_t*)0x60220ac8) /*  */
/** @brief Device SHM Registers, function 0 */
extern volatile SHM_CHANNEL_t SHM_CHANNEL1;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#ifndef CXX_SIMULATOR
_Static_assert(sizeof(SHM_CHANNEL_t) == 204, "sizeof(SHM_CHANNEL_t) must be 204");
#endif

#endif /* !APE_SHM_CHANNEL1_H */

/** @} */
