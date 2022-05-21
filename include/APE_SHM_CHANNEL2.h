////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_SHM_CHANNEL2.h
///
/// @project    ape
///
/// @brief      APE_SHM_CHANNEL2
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

/** @defgroup APE_SHM_CHANNEL2_H    APE_SHM_CHANNEL2 */
/** @addtogroup APE_SHM_CHANNEL2_H
 * @{
 */
#ifndef APE_SHM_CHANNEL2_H
#define APE_SHM_CHANNEL2_H

#include <types.h>
#include "APE_SHM_CHANNEL0.h"

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_SHM_CHANNEL2_sim(void* base);
void init_APE_SHM_CHANNEL2(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_SHM_CHANNEL2_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_SHM_CHANNEL2_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_SHM_CHANNEL2_H_uint32_t;
#define APE_SHM_CHANNEL2_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_SHM_CHANNEL2_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_SHM_CHANNEL2_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define APE_SHM_CHANNEL2_H_VOLATILE
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_SHM_CHANNEL2_H_uint8_t;
typedef uint16_t APE_SHM_CHANNEL2_H_uint16_t;
typedef uint32_t APE_SHM_CHANNEL2_H_uint32_t;
#define register_container union
#define APE_SHM_CHANNEL2_H_VOLATILE volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_SHM_CHANNEL2_BASE ((volatile void*)0x60220b00) /* Device SHM Registers, function 0 */
#define REG_SHM_CHANNEL2_SIZE (sizeof(SHM_CHANNEL_t))

#define REG_SHM_CHANNEL2_NCSI_CHANNEL_INFO ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b00) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MCID ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b04) /* AEN Management Controller ID, set by BMC when sending AEN ENABLE command and used when sending AENs. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_BFILT ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b0c) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MFILT ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b10) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1 ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b14) /* This is the "Link Settings" value from NCSI Set Link. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_2 ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b18) /* This is the "OEM Settings" value from NCSI Set Link. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_VLAN ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b1c) /* Receives VLAN mode from NCSI specification "Enable VLAN" command. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_ALT_HOST_MAC_HIGH ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b24) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_ALT_HOST_MAC_MID ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b28) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_ALT_HOST_MAC_LOW ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b2c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_HIGH ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b34) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_MID ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b38) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_LOW ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b3c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_HIGH ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b44) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_MID ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b48) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_LOW ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b4c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC2_HIGH ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b54) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC2_MID ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b58) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC2_LOW ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b5c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC3_HIGH ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b64) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC3_MID ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b68) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC3_LOW ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b6c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_VLAN_VALID ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b70) /* Nonzero indicates VLAN field is valid */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_VLAN ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b74) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_VLAN_VALID ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b78) /* Nonzero indicates VLAN field is valid */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_VLAN ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b7c) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_STATUS ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b80) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_RESET_COUNT ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b84) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_PXE ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b88) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_DROPFIL ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b8c) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_SLINK ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220b90) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_DBG ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220ba0) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_NETWORK_RX ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220bb0) /* Number of packets received from the external network interface */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_NETWORK_TX ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220bb4) /* Number of packets transmited from the BCM5719 to external network interface */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_NCSI_RX ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220bb8) /* Number of packets received from the BMC via NCSI */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_NCSI_TX ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220bbc) /* Number of packets transmitted from the BCM5719 to the BMC via NCSI */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_NCSI_DROPPED ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220bc0) /* Number of packets dropped on the NCSI interface. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_NETWORK_DROPPED ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220bc4) /* Number of packets dropped on the external network interface. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_AEN ((APE_SHM_CHANNEL2_H_VOLATILE APE_SHM_CHANNEL2_H_uint32_t*)0x60220bc8) /* Number of AEN packets sent via NCSI */
/** @brief Device SHM Registers, function 0 */
extern APE_SHM_CHANNEL2_H_VOLATILE SHM_CHANNEL_t SHM_CHANNEL2;



#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#ifndef CXX_SIMULATOR
_Static_assert(sizeof(SHM_CHANNEL_t) == 204, "sizeof(SHM_CHANNEL_t) must be 204");
#endif

#endif /* !APE_SHM_CHANNEL2_H */

/** @} */
