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

/** @defgroup BCM5719_SHM_CHANNEL2_H    bcm5719_SHM_CHANNEL2 */
/** @addtogroup BCM5719_SHM_CHANNEL2_H
 * @{
 */
#ifndef BCM5719_SHM_CHANNEL2_H
#define BCM5719_SHM_CHANNEL2_H

#include <stdint.h>
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
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  BCM5719_SHM_CHANNEL2_H_uint8_t;
typedef uint16_t BCM5719_SHM_CHANNEL2_H_uint16_t;
typedef uint32_t BCM5719_SHM_CHANNEL2_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_SHM_CHANNEL2_BASE ((volatile void*)0xc0014b00) /* Device APE SHM Channel Registers */
#define REG_SHM_CHANNEL2_SIZE (sizeof(SHM_CHANNEL_t))

#define REG_SHM_CHANNEL2_NCSI_CHANNEL_INFO ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b00) /*  */
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_ENABLED_SHIFT 0u
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_ENABLED_MASK  0x1u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_ENABLED(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_ENABLED(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_TX_PASSTHROUGH_SHIFT 1u
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_TX_PASSTHROUGH_MASK  0x2u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_TX_PASSTHROUGH(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_TX_PASSTHROUGH(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_READY_SHIFT 2u
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_READY_MASK  0x4u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_READY(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_READY(__val__)  (((__val__) << 2u) & 0x4u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_INIT_SHIFT 3u
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_INIT_MASK  0x8u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_INIT(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_INIT(__val__)  (((__val__) << 3u) & 0x8u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_MFILT_SHIFT 4u
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_MFILT_MASK  0x10u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_MFILT(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_MFILT(__val__)  (((__val__) << 4u) & 0x10u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_BFILT_SHIFT 5u
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_BFILT_MASK  0x20u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_BFILT(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_BFILT(__val__)  (((__val__) << 5u) & 0x20u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_SERDES_SHIFT 6u
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_SERDES_MASK  0x40u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_SERDES(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_SERDES(__val__)  (((__val__) << 6u) & 0x40u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_VLAN_SHIFT 8u
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_VLAN_MASK  0x100u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_VLAN(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_VLAN(__val__)  (((__val__) << 8u) & 0x100u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_B2H_SHIFT 10u
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_B2H_MASK  0x400u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_B2H(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_B2H(__val__)  (((__val__) << 10u) & 0x400u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_B2N_SHIFT 11u
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_B2N_MASK  0x800u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_B2N(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_B2N(__val__)  (((__val__) << 11u) & 0x800u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_EEE_SHIFT 12u
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_EEE_MASK  0x1000u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_EEE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_EEE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_DRIVER_SHIFT 14u
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_DRIVER_MASK  0x4000u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_DRIVER(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_DRIVER(__val__)  (((__val__) << 14u) & 0x4000u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_PDEAD_SHIFT 15u
#define     SHM_CHANNEL2_NCSI_CHANNEL_INFO_PDEAD_MASK  0x8000u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_PDEAD(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_INFO_PDEAD(__val__)  (((__val__) << 15u) & 0x8000u)

#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MCID ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b04) /* AEN Management Controller ID, set by BMC when sending AEN ENABLE command and used when sending AENs. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_AEN ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b08) /* Set via NCSI ENABLE AEN. */
#define     SHM_CHANNEL2_NCSI_CHANNEL_AEN_ENABLE_LINK_STATUS_CHANGE_AEN_SHIFT 0u
#define     SHM_CHANNEL2_NCSI_CHANNEL_AEN_ENABLE_LINK_STATUS_CHANGE_AEN_MASK  0x1u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_AEN_ENABLE_LINK_STATUS_CHANGE_AEN(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_AEN_ENABLE_LINK_STATUS_CHANGE_AEN(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN_SHIFT 1u
#define     SHM_CHANNEL2_NCSI_CHANNEL_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN_MASK  0x2u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN_SHIFT 2u
#define     SHM_CHANNEL2_NCSI_CHANNEL_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN_MASK  0x4u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN(__val__)  (((__val__) << 2u) & 0x4u)

#define REG_SHM_CHANNEL2_NCSI_CHANNEL_BFILT ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b0c) /*  */
#define     SHM_CHANNEL2_NCSI_CHANNEL_BFILT_ARP_PACKET_SHIFT 0u
#define     SHM_CHANNEL2_NCSI_CHANNEL_BFILT_ARP_PACKET_MASK  0x1u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_BFILT_ARP_PACKET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_BFILT_ARP_PACKET(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_BFILT_DHCP_CLIENT_PACKET_SHIFT 1u
#define     SHM_CHANNEL2_NCSI_CHANNEL_BFILT_DHCP_CLIENT_PACKET_MASK  0x2u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_BFILT_DHCP_CLIENT_PACKET(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_BFILT_DHCP_CLIENT_PACKET(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_BFILT_DHCP_SERVER_PACKET_SHIFT 2u
#define     SHM_CHANNEL2_NCSI_CHANNEL_BFILT_DHCP_SERVER_PACKET_MASK  0x4u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_BFILT_DHCP_SERVER_PACKET(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_BFILT_DHCP_SERVER_PACKET(__val__)  (((__val__) << 2u) & 0x4u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_BFILT_NETBIOS_PACKET_SHIFT 3u
#define     SHM_CHANNEL2_NCSI_CHANNEL_BFILT_NETBIOS_PACKET_MASK  0x8u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_BFILT_NETBIOS_PACKET(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_BFILT_NETBIOS_PACKET(__val__)  (((__val__) << 3u) & 0x8u)

#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MFILT ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b10) /*  */
#define     SHM_CHANNEL2_NCSI_CHANNEL_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT_SHIFT 0u
#define     SHM_CHANNEL2_NCSI_CHANNEL_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT_MASK  0x1u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_MFILT_IPV6_ROUTER_ADVERTISEMENT_SHIFT 1u
#define     SHM_CHANNEL2_NCSI_CHANNEL_MFILT_IPV6_ROUTER_ADVERTISEMENT_MASK  0x2u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_MFILT_IPV6_ROUTER_ADVERTISEMENT(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_MFILT_IPV6_ROUTER_ADVERTISEMENT(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST_SHIFT 2u
#define     SHM_CHANNEL2_NCSI_CHANNEL_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST_MASK  0x4u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST(__val__)  (((__val__) << 2u) & 0x4u)

#define REG_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1 ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b14) /* This is the "Link Settings" value from NCSI Set Link. */
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_AUTONEGOTIATION_ENABLED_SHIFT 0u
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_AUTONEGOTIATION_ENABLED_MASK  0x1u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_AUTONEGOTIATION_ENABLED(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_AUTONEGOTIATION_ENABLED(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10M_ENABLE_SHIFT 1u
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10M_ENABLE_MASK  0x2u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10M_ENABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10M_ENABLE(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_100M_ENABLE_SHIFT 2u
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_100M_ENABLE_MASK  0x4u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_100M_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_100M_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_1000M_ENABLE_SHIFT 3u
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_1000M_ENABLE_MASK  0x8u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_1000M_ENABLE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_1000M_ENABLE(__val__)  (((__val__) << 3u) & 0x8u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10G_ENABLE_SHIFT 4u
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10G_ENABLE_MASK  0x10u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10G_ENABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10G_ENABLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_HALF_DUPLEX_ENABLE_SHIFT 8u
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_HALF_DUPLEX_ENABLE_MASK  0x100u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_HALF_DUPLEX_ENABLE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_HALF_DUPLEX_ENABLE(__val__)  (((__val__) << 8u) & 0x100u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_FULL_DUPLEX_ENABLE_SHIFT 9u
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_FULL_DUPLEX_ENABLE_MASK  0x200u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_FULL_DUPLEX_ENABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_FULL_DUPLEX_ENABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_PAUSE_CAPABILITY_ENABLE_SHIFT 10u
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_PAUSE_CAPABILITY_ENABLE_MASK  0x400u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_PAUSE_CAPABILITY_ENABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_PAUSE_CAPABILITY_ENABLE(__val__)  (((__val__) << 10u) & 0x400u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE_SHIFT 11u
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE_MASK  0x800u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE(__val__)  (((__val__) << 11u) & 0x800u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID_SHIFT 12u
#define     SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID_MASK  0x1000u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID(__val__)  (((__val__) << 12u) & 0x1000u)

#define REG_SHM_CHANNEL2_NCSI_CHANNEL_SETTING_2 ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b18) /* This is the "OEM Settings" value from NCSI Set Link. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_VLAN ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b1c) /* Receives VLAN mode from NCSI specification "Enable VLAN" command. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_ALT_HOST_MAC_HIGH ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b24) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_ALT_HOST_MAC_MID ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b28) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_ALT_HOST_MAC_LOW ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b2c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_HIGH ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b34) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_MID ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b38) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_LOW ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b3c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_HIGH ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b44) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_MID ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b48) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_LOW ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b4c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC2_HIGH ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b54) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC2_MID ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b58) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC2_LOW ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b5c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC3_HIGH ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b64) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC3_MID ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b68) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC3_LOW ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b6c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_VLAN_VALID ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b70) /* Nonzero indicates VLAN field is valid */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC0_VLAN ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b74) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_VLAN_VALID ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b78) /* Nonzero indicates VLAN field is valid */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_MAC1_VLAN ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b7c) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_STATUS ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b80) /*  */
#define     SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_UP_SHIFT 0u
#define     SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_UP_MASK  0x1u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_UP(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_UP(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_STATUS_SHIFT 1u
#define     SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_STATUS_MASK  0x1eu
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_STATUS(__reg__)  (((__reg__) & 0x1e) >> 1u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_STATUS(__val__)  (((__val__) << 1u) & 0x1eu)
#define     SHM_CHANNEL2_NCSI_CHANNEL_STATUS_SERDES_SHIFT 5u
#define     SHM_CHANNEL2_NCSI_CHANNEL_STATUS_SERDES_MASK  0x20u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_STATUS_SERDES(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_STATUS_SERDES(__val__)  (((__val__) << 5u) & 0x20u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_STATUS_AUTONEGOTIATION_COMPLETE_SHIFT 6u
#define     SHM_CHANNEL2_NCSI_CHANNEL_STATUS_AUTONEGOTIATION_COMPLETE_MASK  0x40u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_STATUS_AUTONEGOTIATION_COMPLETE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_STATUS_AUTONEGOTIATION_COMPLETE(__val__)  (((__val__) << 6u) & 0x40u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE_SHIFT 9u
#define     SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE_MASK  0x200u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_HALS_DUPLEX_CAPABLE_SHIFT 10u
#define     SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_HALS_DUPLEX_CAPABLE_MASK  0x400u
#define GET_SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_HALS_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_SHM_CHANNEL2_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_HALS_DUPLEX_CAPABLE(__val__)  (((__val__) << 10u) & 0x400u)

#define REG_SHM_CHANNEL2_NCSI_CHANNEL_RESET_COUNT ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b84) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_PXE ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b88) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_DROPFIL ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b8c) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_SLINK ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014b90) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_DBG ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014ba0) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_CTRLSTAT_RX ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bb0) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_CTRLSTAT_DROPPED ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bb4) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_CTRLSTAT_TYPE_ERR ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bb8) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_CTRLSTAT_BAD_CSUM ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bbc) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_CTRLSTAT_ALL_RX ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bc0) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_CTRLSTAT_ALL_TX ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bc4) /*  */
#define REG_SHM_CHANNEL2_NCSI_CHANNEL_CTRLSTAT_ALL_AEN ((volatile BCM5719_SHM_CHANNEL2_H_uint32_t*)0xc0014bc8) /*  */
/** @brief Device APE SHM Channel Registers */
extern volatile SHM_CHANNEL_t SHM_CHANNEL2;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !BCM5719_SHM_CHANNEL2_H */

/** @} */
