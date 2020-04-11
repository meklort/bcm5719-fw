////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_SHM_CHANNEL3.h
///
/// @project    bcm5719
///
/// @brief      bcm5719_SHM_CHANNEL3
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2020, Evan Lojewski
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

/** @defgroup BCM5719_SHM_CHANNEL3_H    bcm5719_SHM_CHANNEL3 */
/** @addtogroup BCM5719_SHM_CHANNEL3_H
 * @{
 */
#ifndef BCM5719_SHM_CHANNEL3_H
#define BCM5719_SHM_CHANNEL3_H

#include <types.h>
#include "bcm5719_SHM_CHANNEL0.h"

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_bcm5719_SHM_CHANNEL3_sim(void* base);
void init_bcm5719_SHM_CHANNEL3(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> BCM5719_SHM_CHANNEL3_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> BCM5719_SHM_CHANNEL3_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> BCM5719_SHM_CHANNEL3_H_uint32_t;
#define BCM5719_SHM_CHANNEL3_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define BCM5719_SHM_CHANNEL3_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define BCM5719_SHM_CHANNEL3_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  BCM5719_SHM_CHANNEL3_H_uint8_t;
typedef uint16_t BCM5719_SHM_CHANNEL3_H_uint16_t;
typedef uint32_t BCM5719_SHM_CHANNEL3_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_SHM_CHANNEL3_BASE ((volatile void*)0xc0014c00) /* Device APE SHM Channel Registers */
#define REG_SHM_CHANNEL3_SIZE (sizeof(SHM_CHANNEL_t))

#define REG_SHM_CHANNEL3_NCSI_CHANNEL_INFO ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c00) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MCID ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c04) /* AEN Management Controller ID, set by BMC when sending AEN ENABLE command and used when sending AENs. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_AEN ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c08) /* Set via NCSI ENABLE AEN. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_BFILT ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c0c) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MFILT ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c10) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_SETTING_1 ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c14) /* This is the "Link Settings" value from NCSI Set Link. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_SETTING_2 ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c18) /* This is the "OEM Settings" value from NCSI Set Link. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_VLAN ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c1c) /* Receives VLAN mode from NCSI specification "Enable VLAN" command. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_ALT_HOST_MAC_HIGH ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c24) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_ALT_HOST_MAC_MID ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c28) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_ALT_HOST_MAC_LOW ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c2c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC0_HIGH ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c34) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC0_MID ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c38) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC0_LOW ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c3c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC1_HIGH ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c44) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC1_MID ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c48) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC1_LOW ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c4c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC2_HIGH ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c54) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC2_MID ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c58) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC2_LOW ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c5c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC3_HIGH ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c64) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC3_MID ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c68) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC3_LOW ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c6c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC0_VLAN_VALID ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c70) /* Nonzero indicates VLAN field is valid */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC0_VLAN ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c74) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC1_VLAN_VALID ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c78) /* Nonzero indicates VLAN field is valid */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_MAC1_VLAN ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c7c) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_STATUS ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c80) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_RESET_COUNT ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c84) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_PXE ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c88) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_DROPFIL ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c8c) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_SLINK ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014c90) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_DBG ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014ca0) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_CTRLSTAT_RX ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014cb0) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_CTRLSTAT_DROPPED ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014cb4) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_CTRLSTAT_TYPE_ERR ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014cb8) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_CTRLSTAT_BAD_CSUM ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014cbc) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_CTRLSTAT_ALL_RX ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014cc0) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_CTRLSTAT_ALL_TX ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014cc4) /*  */
#define REG_SHM_CHANNEL3_NCSI_CHANNEL_CTRLSTAT_ALL_AEN ((volatile BCM5719_SHM_CHANNEL3_H_uint32_t*)0xc0014cc8) /*  */
/** @brief Device APE SHM Channel Registers */
extern volatile SHM_CHANNEL_t SHM_CHANNEL3;



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

#endif /* !BCM5719_SHM_CHANNEL3_H */

/** @} */
