////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_SHM_CHANNEL2.h
///
/// @project    bcm5719
///
/// @brief      bcm5719_SHM_CHANNEL2
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2022, Evan Lojewski
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

/** @defgroup BCM5719_SHM_CHANNEL2_H    bcm5719_SHM_CHANNEL2 */
/** @addtogroup BCM5719_SHM_CHANNEL2_H
 * @{
 */
#ifndef BCM5719_SHM_CHANNEL2_H
#define BCM5719_SHM_CHANNEL2_H

#include <types.h>
#include "bcm5719_SHM_CHANNEL0.h"

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_bcm5719_SHM_CHANNEL2_sim(void* base);
void init_bcm5719_SHM_CHANNEL2(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> BCM5719_SHM_CHANNEL2_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> BCM5719_SHM_CHANNEL2_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> BCM5719_SHM_CHANNEL2_H_uint32_t;
#define BCM5719_SHM_CHANNEL2_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define BCM5719_SHM_CHANNEL2_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define BCM5719_SHM_CHANNEL2_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define BCM5719_SHM_CHANNEL2_H_VOLATILE
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  BCM5719_SHM_CHANNEL2_H_uint8_t;
typedef uint16_t BCM5719_SHM_CHANNEL2_H_uint16_t;
typedef uint32_t BCM5719_SHM_CHANNEL2_H_uint32_t;
#define register_container union
#define BCM5719_SHM_CHANNEL2_H_VOLATILE volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_SHM_CHANNEL2_BASE ((volatile void*)0xc0014b00) /* Device APE SHM Channel Registers */
#define REG_SHM_CHANNEL2_SIZE (sizeof(SHM_CHANNEL_t))

#define REG_SHM_CHANNEL2_NCSI_CHANNEL_INFO ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b00) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MCID ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b04) /* AEN Management Controller ID, set by BMC when sending AEN ENABLE command and used when sending AENs. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_BFILT ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b0c) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MFILT ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b10) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1 ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b14) /* This is the "Link Settings" value from NCSI Set Link. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_2 ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b18) /* This is the "OEM Settings" value from NCSI Set Link. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_VLAN ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b1c) /* Receives VLAN mode from NCSI specification "Enable VLAN" command. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_ALT_HOST_MAC_HIGH ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b24) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_ALT_HOST_MAC_MID ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b28) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_ALT_HOST_MAC_LOW ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b2c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_HIGH ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b34) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_MID ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b38) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_LOW ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b3c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_HIGH ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b44) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_MID ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b48) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_LOW ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b4c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC2_HIGH ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b54) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC2_MID ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b58) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC2_LOW ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b5c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC3_HIGH ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b64) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC3_MID ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b68) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC3_LOW ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b6c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_VLAN_VALID ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b70) /* Nonzero indicates VLAN field is valid */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_VLAN ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b74) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_VLAN_VALID ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b78) /* Nonzero indicates VLAN field is valid */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_VLAN ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b7c) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_STATUS ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b80) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_RESET_COUNT ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b84) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_PXE ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b88) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_DROPFIL ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b8c) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_SLINK ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b90) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_DBG ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014ba0) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_NETWORK_RX ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bb0) /* Number of packets received from the external network interface */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_NETWORK_TX ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bb4) /* Number of packets transmited from the BCM5719 to external network interface */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_NCSI_RX ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bb8) /* Number of packets received from the BMC via NCSI */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_NCSI_TX ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bbc) /* Number of packets transmitted from the BCM5719 to the BMC via NCSI */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_NCSI_DROPPED ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bc0) /* Number of packets dropped on the NCSI interface. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_NETWORK_DROPPED ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bc4) /* Number of packets dropped on the external network interface. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_AEN ((BCM5719_SHM_CHANNEL2_H_VOLATILE BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bc8) /* Number of AEN packets sent via NCSI */
/** @brief Device APE SHM Channel Registers */
extern BCM5719_SHM_CHANNEL2_H_VOLATILE SHM_CHANNEL_t SHM_CHANNEL2;



#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#ifndef CXX_SIMULATOR
_Static_assert(sizeof(SHM_CHANNEL_t) == 204, "sizeof(SHM_CHANNEL_t) must be 204");
#endif

#endif /* !BCM5719_SHM_CHANNEL2_H */

/** @} */
