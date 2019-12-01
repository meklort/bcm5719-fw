////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_SHM_CHANNEL0.h
///
/// @project    ape
///
/// @brief      APE_SHM_CHANNEL0
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

/** @defgroup APE_SHM_CHANNEL0_H    APE_SHM_CHANNEL0 */
/** @addtogroup APE_SHM_CHANNEL0_H
 * @{
 */
#ifndef APE_SHM_CHANNEL0_H
#define APE_SHM_CHANNEL0_H

#include <types.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_SHM_CHANNEL0_sim(void* base);
void init_APE_SHM_CHANNEL0(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_SHM_CHANNEL0_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_SHM_CHANNEL0_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_SHM_CHANNEL0_H_uint32_t;
#define APE_SHM_CHANNEL0_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_SHM_CHANNEL0_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_SHM_CHANNEL0_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_SHM_CHANNEL0_H_uint8_t;
typedef uint16_t APE_SHM_CHANNEL0_H_uint16_t;
typedef uint32_t APE_SHM_CHANNEL0_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_SHM_CHANNEL0_BASE ((volatile void*)0x60220900) /* Device SHM Registers, function 0 */
#define REG_SHM_CHANNEL0_SIZE (sizeof(SHM_CHANNEL_t))

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_INFO ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220900) /*  */
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_ENABLED_SHIFT 0u
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_ENABLED_MASK  0x1u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_ENABLED(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_ENABLED(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_TX_PASSTHROUGH_SHIFT 1u
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_TX_PASSTHROUGH_MASK  0x2u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_TX_PASSTHROUGH(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_TX_PASSTHROUGH(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_READY_SHIFT 2u
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_READY_MASK  0x4u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_READY(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_READY(__val__)  (((__val__) << 2u) & 0x4u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_INIT_SHIFT 3u
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_INIT_MASK  0x8u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_INIT(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_INIT(__val__)  (((__val__) << 3u) & 0x8u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_MFILT_SHIFT 4u
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_MFILT_MASK  0x10u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_MFILT(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_MFILT(__val__)  (((__val__) << 4u) & 0x10u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_BFILT_SHIFT 5u
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_BFILT_MASK  0x20u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_BFILT(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_BFILT(__val__)  (((__val__) << 5u) & 0x20u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_SERDES_SHIFT 6u
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_SERDES_MASK  0x40u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_SERDES(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_SERDES(__val__)  (((__val__) << 6u) & 0x40u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_VLAN_SHIFT 8u
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_VLAN_MASK  0x100u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_VLAN(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_VLAN(__val__)  (((__val__) << 8u) & 0x100u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_B2H_SHIFT 10u
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_B2H_MASK  0x400u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_B2H(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_B2H(__val__)  (((__val__) << 10u) & 0x400u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_B2N_SHIFT 11u
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_B2N_MASK  0x800u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_B2N(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_B2N(__val__)  (((__val__) << 11u) & 0x800u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_EEE_SHIFT 12u
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_EEE_MASK  0x1000u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_EEE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_EEE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_DRIVER_SHIFT 14u
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_DRIVER_MASK  0x4000u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_DRIVER(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_DRIVER(__val__)  (((__val__) << 14u) & 0x4000u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_PDEAD_SHIFT 15u
#define     SHM_CHANNEL0_NCSI_CHANNEL_INFO_PDEAD_MASK  0x8000u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_PDEAD(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_INFO_PDEAD(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelInfo. */
typedef register_container RegSHM_CHANNELNcsiChannelInfo_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_CHANNEL0_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief This can be modified via NCSI SELECT PACKAGE and NCSI DESELECT PACKAGE. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Enabled, 0, 1)
        /** @brief TX passthrough has been enabled by BMC NCSI command. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, TXPassthrough, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Ready, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Init, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, MFILT, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, BFILT, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, SERDES, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, VLAN, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_9_9, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, B2H, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, B2N, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, EEE, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_13_13, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Driver, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, PDead, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_31_16, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_31_16, 16, 16)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, PDead, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Driver, 14, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_13_13, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, EEE, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, B2N, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, B2H, 10, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_9_9, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, VLAN, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, SERDES, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, BFILT, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, MFILT, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Init, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Ready, 2, 1)
        /** @brief TX passthrough has been enabled by BMC NCSI command. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, TXPassthrough, 1, 1)
        /** @brief This can be modified via NCSI SELECT PACKAGE and NCSI DESELECT PACKAGE. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Enabled, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_CHANNEL0_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelInfo"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelInfo_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelInfo. */
        r32.setName("NcsiChannelInfo");
        bits.Enabled.setBaseRegister(&r32);
        bits.Enabled.setName("Enabled");
        bits.TXPassthrough.setBaseRegister(&r32);
        bits.TXPassthrough.setName("TXPassthrough");
        bits.Ready.setBaseRegister(&r32);
        bits.Ready.setName("Ready");
        bits.Init.setBaseRegister(&r32);
        bits.Init.setName("Init");
        bits.MFILT.setBaseRegister(&r32);
        bits.MFILT.setName("MFILT");
        bits.BFILT.setBaseRegister(&r32);
        bits.BFILT.setName("BFILT");
        bits.SERDES.setBaseRegister(&r32);
        bits.SERDES.setName("SERDES");
        bits.VLAN.setBaseRegister(&r32);
        bits.VLAN.setName("VLAN");
        bits.B2H.setBaseRegister(&r32);
        bits.B2H.setName("B2H");
        bits.B2N.setBaseRegister(&r32);
        bits.B2N.setName("B2N");
        bits.EEE.setBaseRegister(&r32);
        bits.EEE.setName("EEE");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.PDead.setBaseRegister(&r32);
        bits.PDead.setName("PDead");
    }
    RegSHM_CHANNELNcsiChannelInfo_t& operator=(const RegSHM_CHANNELNcsiChannelInfo_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelInfo_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MCID ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220904) /* AEN Management Controller ID, set by BMC when sending AEN ENABLE command and used when sending AENs. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMcid. */
typedef register_container RegSHM_CHANNELNcsiChannelMcid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMcid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMcid_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMcid. */
        r32.setName("NcsiChannelMcid");
    }
    RegSHM_CHANNELNcsiChannelMcid_t& operator=(const RegSHM_CHANNELNcsiChannelMcid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMcid_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_AEN ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220908) /* Set via NCSI ENABLE AEN. */
#define     SHM_CHANNEL0_NCSI_CHANNEL_AEN_ENABLE_LINK_STATUS_CHANGE_AEN_SHIFT 0u
#define     SHM_CHANNEL0_NCSI_CHANNEL_AEN_ENABLE_LINK_STATUS_CHANGE_AEN_MASK  0x1u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_AEN_ENABLE_LINK_STATUS_CHANGE_AEN(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_AEN_ENABLE_LINK_STATUS_CHANGE_AEN(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN_SHIFT 1u
#define     SHM_CHANNEL0_NCSI_CHANNEL_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN_MASK  0x2u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN_SHIFT 2u
#define     SHM_CHANNEL0_NCSI_CHANNEL_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN_MASK  0x4u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN(__val__)  (((__val__) << 2u) & 0x4u)

/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelAen. */
typedef register_container RegSHM_CHANNELNcsiChannelAen_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_CHANNEL0_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, EnableLinkStatusChangeAEN, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, EnableConfigurationRequiredAEN, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, EnableHostNCDriverStatusChangeAEN, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_31_3, 3, 29)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_31_3, 3, 29)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, EnableHostNCDriverStatusChangeAEN, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, EnableConfigurationRequiredAEN, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, EnableLinkStatusChangeAEN, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_CHANNEL0_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelAen"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelAen_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelAen. */
        r32.setName("NcsiChannelAen");
        bits.EnableLinkStatusChangeAEN.setBaseRegister(&r32);
        bits.EnableLinkStatusChangeAEN.setName("EnableLinkStatusChangeAEN");
        bits.EnableConfigurationRequiredAEN.setBaseRegister(&r32);
        bits.EnableConfigurationRequiredAEN.setName("EnableConfigurationRequiredAEN");
        bits.EnableHostNCDriverStatusChangeAEN.setBaseRegister(&r32);
        bits.EnableHostNCDriverStatusChangeAEN.setName("EnableHostNCDriverStatusChangeAEN");
    }
    RegSHM_CHANNELNcsiChannelAen_t& operator=(const RegSHM_CHANNELNcsiChannelAen_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelAen_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_BFILT ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x6022090c) /*  */
#define     SHM_CHANNEL0_NCSI_CHANNEL_BFILT_ARP_PACKET_SHIFT 0u
#define     SHM_CHANNEL0_NCSI_CHANNEL_BFILT_ARP_PACKET_MASK  0x1u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_BFILT_ARP_PACKET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_BFILT_ARP_PACKET(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_BFILT_DHCP_CLIENT_PACKET_SHIFT 1u
#define     SHM_CHANNEL0_NCSI_CHANNEL_BFILT_DHCP_CLIENT_PACKET_MASK  0x2u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_BFILT_DHCP_CLIENT_PACKET(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_BFILT_DHCP_CLIENT_PACKET(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_BFILT_DHCP_SERVER_PACKET_SHIFT 2u
#define     SHM_CHANNEL0_NCSI_CHANNEL_BFILT_DHCP_SERVER_PACKET_MASK  0x4u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_BFILT_DHCP_SERVER_PACKET(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_BFILT_DHCP_SERVER_PACKET(__val__)  (((__val__) << 2u) & 0x4u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_BFILT_NETBIOS_PACKET_SHIFT 3u
#define     SHM_CHANNEL0_NCSI_CHANNEL_BFILT_NETBIOS_PACKET_MASK  0x8u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_BFILT_NETBIOS_PACKET(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_BFILT_NETBIOS_PACKET(__val__)  (((__val__) << 3u) & 0x8u)

/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelBfilt. */
typedef register_container RegSHM_CHANNELNcsiChannelBfilt_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_CHANNEL0_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, ARPPacket, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, DHCPClientPacket, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, DHCPServerPacket, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, NetBIOSPacket, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_31_4, 4, 28)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_31_4, 4, 28)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, NetBIOSPacket, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, DHCPServerPacket, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, DHCPClientPacket, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, ARPPacket, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_CHANNEL0_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelBfilt"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelBfilt_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelBfilt. */
        r32.setName("NcsiChannelBfilt");
        bits.ARPPacket.setBaseRegister(&r32);
        bits.ARPPacket.setName("ARPPacket");
        bits.DHCPClientPacket.setBaseRegister(&r32);
        bits.DHCPClientPacket.setName("DHCPClientPacket");
        bits.DHCPServerPacket.setBaseRegister(&r32);
        bits.DHCPServerPacket.setName("DHCPServerPacket");
        bits.NetBIOSPacket.setBaseRegister(&r32);
        bits.NetBIOSPacket.setName("NetBIOSPacket");
    }
    RegSHM_CHANNELNcsiChannelBfilt_t& operator=(const RegSHM_CHANNELNcsiChannelBfilt_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelBfilt_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MFILT ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220910) /*  */
#define     SHM_CHANNEL0_NCSI_CHANNEL_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT_SHIFT 0u
#define     SHM_CHANNEL0_NCSI_CHANNEL_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT_MASK  0x1u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_MFILT_IPV6_ROUTER_ADVERTISEMENT_SHIFT 1u
#define     SHM_CHANNEL0_NCSI_CHANNEL_MFILT_IPV6_ROUTER_ADVERTISEMENT_MASK  0x2u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_MFILT_IPV6_ROUTER_ADVERTISEMENT(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_MFILT_IPV6_ROUTER_ADVERTISEMENT(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST_SHIFT 2u
#define     SHM_CHANNEL0_NCSI_CHANNEL_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST_MASK  0x4u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST(__val__)  (((__val__) << 2u) & 0x4u)

/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMfilt. */
typedef register_container RegSHM_CHANNELNcsiChannelMfilt_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_CHANNEL0_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, IPv6NeighbourAdvertisement, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, IPv6RouterAdvertisement, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, DHCPv6RelayandServerMulticast, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_31_3, 3, 29)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_31_3, 3, 29)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, DHCPv6RelayandServerMulticast, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, IPv6RouterAdvertisement, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, IPv6NeighbourAdvertisement, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_CHANNEL0_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMfilt"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMfilt_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMfilt. */
        r32.setName("NcsiChannelMfilt");
        bits.IPv6NeighbourAdvertisement.setBaseRegister(&r32);
        bits.IPv6NeighbourAdvertisement.setName("IPv6NeighbourAdvertisement");
        bits.IPv6RouterAdvertisement.setBaseRegister(&r32);
        bits.IPv6RouterAdvertisement.setName("IPv6RouterAdvertisement");
        bits.DHCPv6RelayandServerMulticast.setBaseRegister(&r32);
        bits.DHCPv6RelayandServerMulticast.setName("DHCPv6RelayandServerMulticast");
    }
    RegSHM_CHANNELNcsiChannelMfilt_t& operator=(const RegSHM_CHANNELNcsiChannelMfilt_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMfilt_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1 ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220914) /* This is the "Link Settings" value from NCSI Set Link. */
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_AUTONEGOTIATION_ENABLED_SHIFT 0u
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_AUTONEGOTIATION_ENABLED_MASK  0x1u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_AUTONEGOTIATION_ENABLED(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_AUTONEGOTIATION_ENABLED(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10M_ENABLE_SHIFT 1u
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10M_ENABLE_MASK  0x2u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10M_ENABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10M_ENABLE(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_100M_ENABLE_SHIFT 2u
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_100M_ENABLE_MASK  0x4u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_100M_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_100M_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_1000M_ENABLE_SHIFT 3u
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_1000M_ENABLE_MASK  0x8u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_1000M_ENABLE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_1000M_ENABLE(__val__)  (((__val__) << 3u) & 0x8u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10G_ENABLE_SHIFT 4u
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10G_ENABLE_MASK  0x10u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10G_ENABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_LINK_SPEED_10G_ENABLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_HALF_DUPLEX_ENABLE_SHIFT 8u
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_HALF_DUPLEX_ENABLE_MASK  0x100u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_HALF_DUPLEX_ENABLE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_HALF_DUPLEX_ENABLE(__val__)  (((__val__) << 8u) & 0x100u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_FULL_DUPLEX_ENABLE_SHIFT 9u
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_FULL_DUPLEX_ENABLE_MASK  0x200u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_FULL_DUPLEX_ENABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_FULL_DUPLEX_ENABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_PAUSE_CAPABILITY_ENABLE_SHIFT 10u
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_PAUSE_CAPABILITY_ENABLE_MASK  0x400u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_PAUSE_CAPABILITY_ENABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_PAUSE_CAPABILITY_ENABLE(__val__)  (((__val__) << 10u) & 0x400u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE_SHIFT 11u
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE_MASK  0x800u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE(__val__)  (((__val__) << 11u) & 0x800u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID_SHIFT 12u
#define     SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID_MASK  0x1000u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelSetting1. */
typedef register_container RegSHM_CHANNELNcsiChannelSetting1_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_CHANNEL0_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Autonegotiationenabled, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed10Menable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed100Menable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed1000Menable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed10Genable, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Halfduplexenable, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Fullduplexenable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Pausecapabilityenable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Asymmetricpausecapabilityenable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, OEMlinksettingsfieldvalid, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, OEMlinksettingsfieldvalid, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Asymmetricpausecapabilityenable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Pausecapabilityenable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Fullduplexenable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Halfduplexenable, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed10Genable, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed1000Menable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed100Menable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed10Menable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Autonegotiationenabled, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_CHANNEL0_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelSetting1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelSetting1_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelSetting1. */
        r32.setName("NcsiChannelSetting1");
        bits.Autonegotiationenabled.setBaseRegister(&r32);
        bits.Autonegotiationenabled.setName("Autonegotiationenabled");
        bits.LinkSpeed10Menable.setBaseRegister(&r32);
        bits.LinkSpeed10Menable.setName("LinkSpeed10Menable");
        bits.LinkSpeed100Menable.setBaseRegister(&r32);
        bits.LinkSpeed100Menable.setName("LinkSpeed100Menable");
        bits.LinkSpeed1000Menable.setBaseRegister(&r32);
        bits.LinkSpeed1000Menable.setName("LinkSpeed1000Menable");
        bits.LinkSpeed10Genable.setBaseRegister(&r32);
        bits.LinkSpeed10Genable.setName("LinkSpeed10Genable");
        bits.Halfduplexenable.setBaseRegister(&r32);
        bits.Halfduplexenable.setName("Halfduplexenable");
        bits.Fullduplexenable.setBaseRegister(&r32);
        bits.Fullduplexenable.setName("Fullduplexenable");
        bits.Pausecapabilityenable.setBaseRegister(&r32);
        bits.Pausecapabilityenable.setName("Pausecapabilityenable");
        bits.Asymmetricpausecapabilityenable.setBaseRegister(&r32);
        bits.Asymmetricpausecapabilityenable.setName("Asymmetricpausecapabilityenable");
        bits.OEMlinksettingsfieldvalid.setBaseRegister(&r32);
        bits.OEMlinksettingsfieldvalid.setName("OEMlinksettingsfieldvalid");
    }
    RegSHM_CHANNELNcsiChannelSetting1_t& operator=(const RegSHM_CHANNELNcsiChannelSetting1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelSetting1_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_SETTING_2 ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220918) /* This is the "OEM Settings" value from NCSI Set Link. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelSetting2. */
typedef register_container RegSHM_CHANNELNcsiChannelSetting2_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelSetting2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelSetting2_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelSetting2. */
        r32.setName("NcsiChannelSetting2");
    }
    RegSHM_CHANNELNcsiChannelSetting2_t& operator=(const RegSHM_CHANNELNcsiChannelSetting2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelSetting2_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_VLAN ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x6022091c) /* Receives VLAN mode from NCSI specification "Enable VLAN" command. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelVlan. */
typedef register_container RegSHM_CHANNELNcsiChannelVlan_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelVlan"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelVlan_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelVlan. */
        r32.setName("NcsiChannelVlan");
    }
    RegSHM_CHANNELNcsiChannelVlan_t& operator=(const RegSHM_CHANNELNcsiChannelVlan_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelVlan_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_ALT_HOST_MAC_HIGH ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220924) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelAltHostMacHigh. */
typedef register_container RegSHM_CHANNELNcsiChannelAltHostMacHigh_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelAltHostMacHigh"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelAltHostMacHigh_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelAltHostMacHigh. */
        r32.setName("NcsiChannelAltHostMacHigh");
    }
    RegSHM_CHANNELNcsiChannelAltHostMacHigh_t& operator=(const RegSHM_CHANNELNcsiChannelAltHostMacHigh_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelAltHostMacHigh_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_ALT_HOST_MAC_MID ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220928) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelAltHostMacMid. */
typedef register_container RegSHM_CHANNELNcsiChannelAltHostMacMid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelAltHostMacMid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelAltHostMacMid_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelAltHostMacMid. */
        r32.setName("NcsiChannelAltHostMacMid");
    }
    RegSHM_CHANNELNcsiChannelAltHostMacMid_t& operator=(const RegSHM_CHANNELNcsiChannelAltHostMacMid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelAltHostMacMid_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_ALT_HOST_MAC_LOW ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x6022092c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelAltHostMacLow. */
typedef register_container RegSHM_CHANNELNcsiChannelAltHostMacLow_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelAltHostMacLow"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelAltHostMacLow_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelAltHostMacLow. */
        r32.setName("NcsiChannelAltHostMacLow");
    }
    RegSHM_CHANNELNcsiChannelAltHostMacLow_t& operator=(const RegSHM_CHANNELNcsiChannelAltHostMacLow_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelAltHostMacLow_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC0_HIGH ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220934) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac0High. */
typedef register_container RegSHM_CHANNELNcsiChannelMac0High_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac0High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac0High_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac0High. */
        r32.setName("NcsiChannelMac0High");
    }
    RegSHM_CHANNELNcsiChannelMac0High_t& operator=(const RegSHM_CHANNELNcsiChannelMac0High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac0High_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC0_MID ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220938) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac0Mid. */
typedef register_container RegSHM_CHANNELNcsiChannelMac0Mid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac0Mid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac0Mid_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac0Mid. */
        r32.setName("NcsiChannelMac0Mid");
    }
    RegSHM_CHANNELNcsiChannelMac0Mid_t& operator=(const RegSHM_CHANNELNcsiChannelMac0Mid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac0Mid_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC0_LOW ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x6022093c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac0Low. */
typedef register_container RegSHM_CHANNELNcsiChannelMac0Low_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac0Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac0Low_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac0Low. */
        r32.setName("NcsiChannelMac0Low");
    }
    RegSHM_CHANNELNcsiChannelMac0Low_t& operator=(const RegSHM_CHANNELNcsiChannelMac0Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac0Low_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC1_HIGH ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220944) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac1High. */
typedef register_container RegSHM_CHANNELNcsiChannelMac1High_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac1High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac1High_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac1High. */
        r32.setName("NcsiChannelMac1High");
    }
    RegSHM_CHANNELNcsiChannelMac1High_t& operator=(const RegSHM_CHANNELNcsiChannelMac1High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac1High_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC1_MID ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220948) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac1Mid. */
typedef register_container RegSHM_CHANNELNcsiChannelMac1Mid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac1Mid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac1Mid_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac1Mid. */
        r32.setName("NcsiChannelMac1Mid");
    }
    RegSHM_CHANNELNcsiChannelMac1Mid_t& operator=(const RegSHM_CHANNELNcsiChannelMac1Mid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac1Mid_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC1_LOW ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x6022094c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac1Low. */
typedef register_container RegSHM_CHANNELNcsiChannelMac1Low_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac1Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac1Low_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac1Low. */
        r32.setName("NcsiChannelMac1Low");
    }
    RegSHM_CHANNELNcsiChannelMac1Low_t& operator=(const RegSHM_CHANNELNcsiChannelMac1Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac1Low_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC2_HIGH ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220954) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac2High. */
typedef register_container RegSHM_CHANNELNcsiChannelMac2High_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac2High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac2High_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac2High. */
        r32.setName("NcsiChannelMac2High");
    }
    RegSHM_CHANNELNcsiChannelMac2High_t& operator=(const RegSHM_CHANNELNcsiChannelMac2High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac2High_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC2_MID ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220958) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac2Mid. */
typedef register_container RegSHM_CHANNELNcsiChannelMac2Mid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac2Mid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac2Mid_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac2Mid. */
        r32.setName("NcsiChannelMac2Mid");
    }
    RegSHM_CHANNELNcsiChannelMac2Mid_t& operator=(const RegSHM_CHANNELNcsiChannelMac2Mid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac2Mid_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC2_LOW ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x6022095c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac2Low. */
typedef register_container RegSHM_CHANNELNcsiChannelMac2Low_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac2Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac2Low_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac2Low. */
        r32.setName("NcsiChannelMac2Low");
    }
    RegSHM_CHANNELNcsiChannelMac2Low_t& operator=(const RegSHM_CHANNELNcsiChannelMac2Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac2Low_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC3_HIGH ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220964) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac3High. */
typedef register_container RegSHM_CHANNELNcsiChannelMac3High_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac3High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac3High_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac3High. */
        r32.setName("NcsiChannelMac3High");
    }
    RegSHM_CHANNELNcsiChannelMac3High_t& operator=(const RegSHM_CHANNELNcsiChannelMac3High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac3High_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC3_MID ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220968) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac3Mid. */
typedef register_container RegSHM_CHANNELNcsiChannelMac3Mid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac3Mid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac3Mid_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac3Mid. */
        r32.setName("NcsiChannelMac3Mid");
    }
    RegSHM_CHANNELNcsiChannelMac3Mid_t& operator=(const RegSHM_CHANNELNcsiChannelMac3Mid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac3Mid_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC3_LOW ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x6022096c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac3Low. */
typedef register_container RegSHM_CHANNELNcsiChannelMac3Low_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac3Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac3Low_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac3Low. */
        r32.setName("NcsiChannelMac3Low");
    }
    RegSHM_CHANNELNcsiChannelMac3Low_t& operator=(const RegSHM_CHANNELNcsiChannelMac3Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac3Low_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC0_VLAN_VALID ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220970) /* Nonzero indicates VLAN field is valid */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac0VlanValid. */
typedef register_container RegSHM_CHANNELNcsiChannelMac0VlanValid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac0VlanValid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac0VlanValid_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac0VlanValid. */
        r32.setName("NcsiChannelMac0VlanValid");
    }
    RegSHM_CHANNELNcsiChannelMac0VlanValid_t& operator=(const RegSHM_CHANNELNcsiChannelMac0VlanValid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac0VlanValid_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC0_VLAN ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220974) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac0Vlan. */
typedef register_container RegSHM_CHANNELNcsiChannelMac0Vlan_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac0Vlan"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac0Vlan_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac0Vlan. */
        r32.setName("NcsiChannelMac0Vlan");
    }
    RegSHM_CHANNELNcsiChannelMac0Vlan_t& operator=(const RegSHM_CHANNELNcsiChannelMac0Vlan_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac0Vlan_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC1_VLAN_VALID ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220978) /* Nonzero indicates VLAN field is valid */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac1VlanValid. */
typedef register_container RegSHM_CHANNELNcsiChannelMac1VlanValid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac1VlanValid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac1VlanValid_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac1VlanValid. */
        r32.setName("NcsiChannelMac1VlanValid");
    }
    RegSHM_CHANNELNcsiChannelMac1VlanValid_t& operator=(const RegSHM_CHANNELNcsiChannelMac1VlanValid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac1VlanValid_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_MAC1_VLAN ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x6022097c) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelMac1Vlan. */
typedef register_container RegSHM_CHANNELNcsiChannelMac1Vlan_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelMac1Vlan"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelMac1Vlan_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelMac1Vlan. */
        r32.setName("NcsiChannelMac1Vlan");
    }
    RegSHM_CHANNELNcsiChannelMac1Vlan_t& operator=(const RegSHM_CHANNELNcsiChannelMac1Vlan_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelMac1Vlan_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_STATUS ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220980) /*  */
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_UP_SHIFT 0u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_UP_MASK  0x1u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_UP(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_UP(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_STATUS_SHIFT 1u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_STATUS_MASK  0x1eu
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_STATUS(__reg__)  (((__reg__) & 0x1e) >> 1u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_STATUS(__val__)  (((__val__) << 1u) & 0x1eu)
#define     SHM_CHANNEL_NCSI_CHANNEL_STATUS_LINK_STATUS_NO_LINK 0x0u
#define     SHM_CHANNEL_NCSI_CHANNEL_STATUS_LINK_STATUS_10BASE_T_HALF_DUPLEX 0x1u
#define     SHM_CHANNEL_NCSI_CHANNEL_STATUS_LINK_STATUS_10BASE_T_FULL_DUPLEX 0x2u
#define     SHM_CHANNEL_NCSI_CHANNEL_STATUS_LINK_STATUS_100BASE_TX_HALF_DUPLEX 0x3u
#define     SHM_CHANNEL_NCSI_CHANNEL_STATUS_LINK_STATUS_100BASE_T4 0x4u
#define     SHM_CHANNEL_NCSI_CHANNEL_STATUS_LINK_STATUS_100BASE_TX_FULL_DUPLEX 0x5u
#define     SHM_CHANNEL_NCSI_CHANNEL_STATUS_LINK_STATUS_1000BASE_T_HALF_DUPLEX 0x6u
#define     SHM_CHANNEL_NCSI_CHANNEL_STATUS_LINK_STATUS_1000BASE_T_FULL_DUPLEX 0x7u
#define     SHM_CHANNEL_NCSI_CHANNEL_STATUS_LINK_STATUS_10G_BASE_T 0x8u

#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_AUTONEGOTIATION_ENABLED_SHIFT 5u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_AUTONEGOTIATION_ENABLED_MASK  0x20u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_AUTONEGOTIATION_ENABLED(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_AUTONEGOTIATION_ENABLED(__val__)  (((__val__) << 5u) & 0x20u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_AUTONEGOTIATION_COMPLETE_SHIFT 6u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_AUTONEGOTIATION_COMPLETE_MASK  0x40u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_AUTONEGOTIATION_COMPLETE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_AUTONEGOTIATION_COMPLETE(__val__)  (((__val__) << 6u) & 0x40u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_PARALLEL_DETECTION_SHIFT 7u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_PARALLEL_DETECTION_MASK  0x80u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_PARALLEL_DETECTION(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_PARALLEL_DETECTION(__val__)  (((__val__) << 7u) & 0x80u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE_SHIFT 9u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE_MASK  0x200u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_HALF_DUPLEX_CAPABLE_SHIFT 10u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_HALF_DUPLEX_CAPABLE_MASK  0x400u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_HALF_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_1000M_HALF_DUPLEX_CAPABLE(__val__)  (((__val__) << 10u) & 0x400u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_100M_T4_CAPABLE_SHIFT 11u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_100M_T4_CAPABLE_MASK  0x800u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_100M_T4_CAPABLE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_100M_T4_CAPABLE(__val__)  (((__val__) << 11u) & 0x800u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_100M_TX_FULL_DUPLEX_CAPABLE_SHIFT 12u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_100M_TX_FULL_DUPLEX_CAPABLE_MASK  0x1000u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_100M_TX_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_100M_TX_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_100M_TX_HALF_DUPLEX_CAPABLE_SHIFT 13u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_100M_TX_HALF_DUPLEX_CAPABLE_MASK  0x2000u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_100M_TX_HALF_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_100M_TX_HALF_DUPLEX_CAPABLE(__val__)  (((__val__) << 13u) & 0x2000u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_10M_T_FULL_DUPLEX_CAPABLE_SHIFT 14u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_10M_T_FULL_DUPLEX_CAPABLE_MASK  0x4000u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_10M_T_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_10M_T_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 14u) & 0x4000u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_10M_T_HALF_DUPLEX_CAPABLE_SHIFT 15u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_10M_T_HALF_DUPLEX_CAPABLE_MASK  0x8000u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_10M_T_HALF_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_SPEED_10M_T_HALF_DUPLEX_CAPABLE(__val__)  (((__val__) << 15u) & 0x8000u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_TX_FLOW_CONTROL_FLAG_SHIFT 16u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_TX_FLOW_CONTROL_FLAG_MASK  0x10000u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_TX_FLOW_CONTROL_FLAG(__reg__)  (((__reg__) & 0x10000) >> 16u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_TX_FLOW_CONTROL_FLAG(__val__)  (((__val__) << 16u) & 0x10000u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_RX_FLOW_CONTROL_FLAG_SHIFT 17u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_RX_FLOW_CONTROL_FLAG_MASK  0x20000u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_RX_FLOW_CONTROL_FLAG(__reg__)  (((__reg__) & 0x20000) >> 17u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_RX_FLOW_CONTROL_FLAG(__val__)  (((__val__) << 17u) & 0x20000u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_PARTNER_ADVERTISED_FLOW_CONTROL_SHIFT 18u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_PARTNER_ADVERTISED_FLOW_CONTROL_MASK  0xc0000u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_PARTNER_ADVERTISED_FLOW_CONTROL(__reg__)  (((__reg__) & 0xc0000) >> 18u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_LINK_PARTNER_ADVERTISED_FLOW_CONTROL(__val__)  (((__val__) << 18u) & 0xc0000u)
#define     SHM_CHANNEL_NCSI_CHANNEL_STATUS_LINK_PARTNER_ADVERTISED_FLOW_CONTROL_NOT_CAPABLE 0x0u
#define     SHM_CHANNEL_NCSI_CHANNEL_STATUS_LINK_PARTNER_ADVERTISED_FLOW_CONTROL_SYMMETRIC_PAUSE 0x1u
#define     SHM_CHANNEL_NCSI_CHANNEL_STATUS_LINK_PARTNER_ADVERTISED_FLOW_CONTROL_ASYMMETRIC_PAUSE 0x2u
#define     SHM_CHANNEL_NCSI_CHANNEL_STATUS_LINK_PARTNER_ADVERTISED_FLOW_CONTROL_SYMMETRIC_AND_ASYMMETRIC_PAUSE 0x3u

#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_SERDES_LINK_SHIFT 20u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_SERDES_LINK_MASK  0x100000u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_SERDES_LINK(__reg__)  (((__reg__) & 0x100000) >> 20u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_SERDES_LINK(__val__)  (((__val__) << 20u) & 0x100000u)
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_OEM_LINK_STATUS_VALID_SHIFT 21u
#define     SHM_CHANNEL0_NCSI_CHANNEL_STATUS_OEM_LINK_STATUS_VALID_MASK  0x200000u
#define GET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_OEM_LINK_STATUS_VALID(__reg__)  (((__reg__) & 0x200000) >> 21u)
#define SET_SHM_CHANNEL0_NCSI_CHANNEL_STATUS_OEM_LINK_STATUS_VALID(__val__)  (((__val__) << 21u) & 0x200000u)

/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelStatus. */
typedef register_container RegSHM_CHANNELNcsiChannelStatus_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_CHANNEL0_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Linkup, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkStatus, 1, 4)
        /** @brief Auto-negotiation is enabled. This field always returns 0 if auto-negotiation is not supported. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, AutonegotiationEnabled, 5, 1)
        /** @brief Set if autonegotiation is complete. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, AutonegotiationComplete, 6, 1)
        /** @brief Link partner did not support auto-negotiation and parallel detection was used to get link. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, ParallelDetection, 7, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_8_8, 8, 1)
        /** @brief Link partner is 1000BASE-T full-duplex capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed1000MFullDuplexCapable, 9, 1)
        /** @brief Link partner is 1000BASE-T half-duplex capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed1000MHalfDuplexCapable, 10, 1)
        /** @brief Link partner is 100BASE-T4 capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed100M_T4Capable, 11, 1)
        /** @brief Link partner 100BASE-TX full-duplex capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed100M_TXFullDuplexCapable, 12, 1)
        /** @brief Link partner 100BASE-TX half-duplex capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed100M_TXHalfDuplexCapable, 13, 1)
        /** @brief Link partner 10BASE-T full-duplex capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed10M_TFullDuplexCapable, 14, 1)
        /** @brief Link partner 10BASE-T half-duplex capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed10M_THalfDuplexCapable, 15, 1)
        /** @brief Pause Flow Control enabled for TX on the external network interface. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, TXFlowControlFlag, 16, 1)
        /** @brief Pause Flow Control enabled for RX on the external network interface. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, RXFlowControlFlag, 17, 1)
        /** @brief Flow control supported by partner. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkPartnerAdvertisedFlowControl, 18, 2)
        /** @brief SerDes status. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, SerDesLink, 20, 1)
        /** @brief If set, OEM Link Status was populated and is valid. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, OEMLinkStatusValid, 21, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_31_22, 22, 10)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_31_22, 22, 10)
        /** @brief If set, OEM Link Status was populated and is valid. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, OEMLinkStatusValid, 21, 1)
        /** @brief SerDes status. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, SerDesLink, 20, 1)
        /** @brief Flow control supported by partner. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkPartnerAdvertisedFlowControl, 18, 2)
        /** @brief Pause Flow Control enabled for RX on the external network interface. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, RXFlowControlFlag, 17, 1)
        /** @brief Pause Flow Control enabled for TX on the external network interface. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, TXFlowControlFlag, 16, 1)
        /** @brief Link partner 10BASE-T half-duplex capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed10M_THalfDuplexCapable, 15, 1)
        /** @brief Link partner 10BASE-T full-duplex capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed10M_TFullDuplexCapable, 14, 1)
        /** @brief Link partner 100BASE-TX half-duplex capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed100M_TXHalfDuplexCapable, 13, 1)
        /** @brief Link partner 100BASE-TX full-duplex capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed100M_TXFullDuplexCapable, 12, 1)
        /** @brief Link partner is 100BASE-T4 capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed100M_T4Capable, 11, 1)
        /** @brief Link partner is 1000BASE-T half-duplex capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed1000MHalfDuplexCapable, 10, 1)
        /** @brief Link partner is 1000BASE-T full-duplex capable */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkSpeed1000MFullDuplexCapable, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, reserved_8_8, 8, 1)
        /** @brief Link partner did not support auto-negotiation and parallel detection was used to get link. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, ParallelDetection, 7, 1)
        /** @brief Set if autonegotiation is complete. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, AutonegotiationComplete, 6, 1)
        /** @brief Auto-negotiation is enabled. This field always returns 0 if auto-negotiation is not supported. */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, AutonegotiationEnabled, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, LinkStatus, 1, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_CHANNEL0_H_uint32_t, Linkup, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_CHANNEL0_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelStatus_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelStatus. */
        r32.setName("NcsiChannelStatus");
        bits.Linkup.setBaseRegister(&r32);
        bits.Linkup.setName("Linkup");
        bits.LinkStatus.setBaseRegister(&r32);
        bits.LinkStatus.setName("LinkStatus");
        bits.LinkStatus.addEnum("No Link", 0x0);
        bits.LinkStatus.addEnum("10BASE-T half-duplex", 0x1);
        bits.LinkStatus.addEnum("10BASE-T full-duplex", 0x2);
        bits.LinkStatus.addEnum("100BASE-TX half-duplex", 0x3);
        bits.LinkStatus.addEnum("100BASE-T4", 0x4);
        bits.LinkStatus.addEnum("100BASE-TX full-duplex", 0x5);
        bits.LinkStatus.addEnum("1000BASE-T half-duplex", 0x6);
        bits.LinkStatus.addEnum("1000BASE-T full-duplex", 0x7);
        bits.LinkStatus.addEnum("10G-BASE-T", 0x8);

        bits.AutonegotiationEnabled.setBaseRegister(&r32);
        bits.AutonegotiationEnabled.setName("AutonegotiationEnabled");
        bits.AutonegotiationComplete.setBaseRegister(&r32);
        bits.AutonegotiationComplete.setName("AutonegotiationComplete");
        bits.ParallelDetection.setBaseRegister(&r32);
        bits.ParallelDetection.setName("ParallelDetection");
        bits.LinkSpeed1000MFullDuplexCapable.setBaseRegister(&r32);
        bits.LinkSpeed1000MFullDuplexCapable.setName("LinkSpeed1000MFullDuplexCapable");
        bits.LinkSpeed1000MHalfDuplexCapable.setBaseRegister(&r32);
        bits.LinkSpeed1000MHalfDuplexCapable.setName("LinkSpeed1000MHalfDuplexCapable");
        bits.LinkSpeed100M_T4Capable.setBaseRegister(&r32);
        bits.LinkSpeed100M_T4Capable.setName("LinkSpeed100M_T4Capable");
        bits.LinkSpeed100M_TXFullDuplexCapable.setBaseRegister(&r32);
        bits.LinkSpeed100M_TXFullDuplexCapable.setName("LinkSpeed100M_TXFullDuplexCapable");
        bits.LinkSpeed100M_TXHalfDuplexCapable.setBaseRegister(&r32);
        bits.LinkSpeed100M_TXHalfDuplexCapable.setName("LinkSpeed100M_TXHalfDuplexCapable");
        bits.LinkSpeed10M_TFullDuplexCapable.setBaseRegister(&r32);
        bits.LinkSpeed10M_TFullDuplexCapable.setName("LinkSpeed10M_TFullDuplexCapable");
        bits.LinkSpeed10M_THalfDuplexCapable.setBaseRegister(&r32);
        bits.LinkSpeed10M_THalfDuplexCapable.setName("LinkSpeed10M_THalfDuplexCapable");
        bits.TXFlowControlFlag.setBaseRegister(&r32);
        bits.TXFlowControlFlag.setName("TXFlowControlFlag");
        bits.RXFlowControlFlag.setBaseRegister(&r32);
        bits.RXFlowControlFlag.setName("RXFlowControlFlag");
        bits.LinkPartnerAdvertisedFlowControl.setBaseRegister(&r32);
        bits.LinkPartnerAdvertisedFlowControl.setName("LinkPartnerAdvertisedFlowControl");
        bits.LinkPartnerAdvertisedFlowControl.addEnum("Not Capable", 0x0);
        bits.LinkPartnerAdvertisedFlowControl.addEnum("Symmetric Pause", 0x1);
        bits.LinkPartnerAdvertisedFlowControl.addEnum("Asymmetric Pause", 0x2);
        bits.LinkPartnerAdvertisedFlowControl.addEnum("Symmetric and Asymmetric Pause", 0x3);

        bits.SerDesLink.setBaseRegister(&r32);
        bits.SerDesLink.setName("SerDesLink");
        bits.OEMLinkStatusValid.setBaseRegister(&r32);
        bits.OEMLinkStatusValid.setName("OEMLinkStatusValid");
    }
    RegSHM_CHANNELNcsiChannelStatus_t& operator=(const RegSHM_CHANNELNcsiChannelStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelStatus_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_RESET_COUNT ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220984) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelResetCount. */
typedef register_container RegSHM_CHANNELNcsiChannelResetCount_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelResetCount"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelResetCount_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelResetCount. */
        r32.setName("NcsiChannelResetCount");
    }
    RegSHM_CHANNELNcsiChannelResetCount_t& operator=(const RegSHM_CHANNELNcsiChannelResetCount_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelResetCount_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_PXE ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220988) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelPxe. */
typedef register_container RegSHM_CHANNELNcsiChannelPxe_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelPxe"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelPxe_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelPxe. */
        r32.setName("NcsiChannelPxe");
    }
    RegSHM_CHANNELNcsiChannelPxe_t& operator=(const RegSHM_CHANNELNcsiChannelPxe_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelPxe_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_DROPFIL ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x6022098c) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelDropfil. */
typedef register_container RegSHM_CHANNELNcsiChannelDropfil_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelDropfil"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelDropfil_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelDropfil. */
        r32.setName("NcsiChannelDropfil");
    }
    RegSHM_CHANNELNcsiChannelDropfil_t& operator=(const RegSHM_CHANNELNcsiChannelDropfil_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelDropfil_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_SLINK ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x60220990) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelSlink. */
typedef register_container RegSHM_CHANNELNcsiChannelSlink_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelSlink"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelSlink_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelSlink. */
        r32.setName("NcsiChannelSlink");
    }
    RegSHM_CHANNELNcsiChannelSlink_t& operator=(const RegSHM_CHANNELNcsiChannelSlink_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelSlink_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_DBG ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x602209a0) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelDbg. */
typedef register_container RegSHM_CHANNELNcsiChannelDbg_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelDbg"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelDbg_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelDbg. */
        r32.setName("NcsiChannelDbg");
    }
    RegSHM_CHANNELNcsiChannelDbg_t& operator=(const RegSHM_CHANNELNcsiChannelDbg_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelDbg_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_CTRLSTAT_RX ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x602209b0) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatRx. */
typedef register_container RegSHM_CHANNELNcsiChannelCtrlstatRx_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelCtrlstatRx"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelCtrlstatRx_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatRx. */
        r32.setName("NcsiChannelCtrlstatRx");
    }
    RegSHM_CHANNELNcsiChannelCtrlstatRx_t& operator=(const RegSHM_CHANNELNcsiChannelCtrlstatRx_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelCtrlstatRx_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_CTRLSTAT_DROPPED ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x602209b4) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatDropped. */
typedef register_container RegSHM_CHANNELNcsiChannelCtrlstatDropped_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelCtrlstatDropped"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelCtrlstatDropped_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatDropped. */
        r32.setName("NcsiChannelCtrlstatDropped");
    }
    RegSHM_CHANNELNcsiChannelCtrlstatDropped_t& operator=(const RegSHM_CHANNELNcsiChannelCtrlstatDropped_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelCtrlstatDropped_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_CTRLSTAT_TYPE_ERR ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x602209b8) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatTypeErr. */
typedef register_container RegSHM_CHANNELNcsiChannelCtrlstatTypeErr_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelCtrlstatTypeErr"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelCtrlstatTypeErr_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatTypeErr. */
        r32.setName("NcsiChannelCtrlstatTypeErr");
    }
    RegSHM_CHANNELNcsiChannelCtrlstatTypeErr_t& operator=(const RegSHM_CHANNELNcsiChannelCtrlstatTypeErr_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelCtrlstatTypeErr_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_CTRLSTAT_BAD_CSUM ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x602209bc) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatBadCsum. */
typedef register_container RegSHM_CHANNELNcsiChannelCtrlstatBadCsum_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelCtrlstatBadCsum"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelCtrlstatBadCsum_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatBadCsum. */
        r32.setName("NcsiChannelCtrlstatBadCsum");
    }
    RegSHM_CHANNELNcsiChannelCtrlstatBadCsum_t& operator=(const RegSHM_CHANNELNcsiChannelCtrlstatBadCsum_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelCtrlstatBadCsum_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_CTRLSTAT_ALL_RX ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x602209c0) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatAllRx. */
typedef register_container RegSHM_CHANNELNcsiChannelCtrlstatAllRx_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelCtrlstatAllRx"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelCtrlstatAllRx_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatAllRx. */
        r32.setName("NcsiChannelCtrlstatAllRx");
    }
    RegSHM_CHANNELNcsiChannelCtrlstatAllRx_t& operator=(const RegSHM_CHANNELNcsiChannelCtrlstatAllRx_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelCtrlstatAllRx_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_CTRLSTAT_ALL_TX ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x602209c4) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatAllTx. */
typedef register_container RegSHM_CHANNELNcsiChannelCtrlstatAllTx_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelCtrlstatAllTx"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelCtrlstatAllTx_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatAllTx. */
        r32.setName("NcsiChannelCtrlstatAllTx");
    }
    RegSHM_CHANNELNcsiChannelCtrlstatAllTx_t& operator=(const RegSHM_CHANNELNcsiChannelCtrlstatAllTx_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelCtrlstatAllTx_t;

#define REG_SHM_CHANNEL0_NCSI_CHANNEL_CTRLSTAT_ALL_AEN ((volatile APE_SHM_CHANNEL0_H_uint32_t*)0x602209c8) /*  */
/** @brief Register definition for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatAllAen. */
typedef register_container RegSHM_CHANNELNcsiChannelCtrlstatAllAen_t {
    /** @brief 32bit direct register access. */
    APE_SHM_CHANNEL0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannelCtrlstatAllAen"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM_CHANNELNcsiChannelCtrlstatAllAen_t()
    {
        /** @brief constructor for @ref SHM_CHANNEL_t.NcsiChannelCtrlstatAllAen. */
        r32.setName("NcsiChannelCtrlstatAllAen");
    }
    RegSHM_CHANNELNcsiChannelCtrlstatAllAen_t& operator=(const RegSHM_CHANNELNcsiChannelCtrlstatAllAen_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM_CHANNELNcsiChannelCtrlstatAllAen_t;

/** @brief Component definition for @ref SHM_CHANNEL0. */
typedef struct SHM_CHANNEL_t {
    /** @brief  */
    RegSHM_CHANNELNcsiChannelInfo_t NcsiChannelInfo;

    /** @brief AEN Management Controller ID, set by BMC when sending AEN ENABLE command and used when sending AENs. */
    RegSHM_CHANNELNcsiChannelMcid_t NcsiChannelMcid;

    /** @brief Set via NCSI ENABLE AEN. */
    RegSHM_CHANNELNcsiChannelAen_t NcsiChannelAen;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelBfilt_t NcsiChannelBfilt;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelMfilt_t NcsiChannelMfilt;

    /** @brief This is the "Link Settings" value from NCSI Set Link. */
    RegSHM_CHANNELNcsiChannelSetting1_t NcsiChannelSetting1;

    /** @brief This is the "OEM Settings" value from NCSI Set Link. */
    RegSHM_CHANNELNcsiChannelSetting2_t NcsiChannelSetting2;

    /** @brief Receives VLAN mode from NCSI specification "Enable VLAN" command. */
    RegSHM_CHANNELNcsiChannelVlan_t NcsiChannelVlan;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_CHANNEL0_H_uint32_t reserved_32[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelAltHostMacHigh_t NcsiChannelAltHostMacHigh;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelAltHostMacMid_t NcsiChannelAltHostMacMid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelAltHostMacLow_t NcsiChannelAltHostMacLow;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_CHANNEL0_H_uint32_t reserved_48[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelMac0High_t NcsiChannelMac0High;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelMac0Mid_t NcsiChannelMac0Mid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelMac0Low_t NcsiChannelMac0Low;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_CHANNEL0_H_uint32_t reserved_64[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelMac1High_t NcsiChannelMac1High;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelMac1Mid_t NcsiChannelMac1Mid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelMac1Low_t NcsiChannelMac1Low;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_CHANNEL0_H_uint32_t reserved_80[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelMac2High_t NcsiChannelMac2High;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelMac2Mid_t NcsiChannelMac2Mid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelMac2Low_t NcsiChannelMac2Low;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_CHANNEL0_H_uint32_t reserved_96[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelMac3High_t NcsiChannelMac3High;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelMac3Mid_t NcsiChannelMac3Mid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegSHM_CHANNELNcsiChannelMac3Low_t NcsiChannelMac3Low;

    /** @brief Nonzero indicates VLAN field is valid */
    RegSHM_CHANNELNcsiChannelMac0VlanValid_t NcsiChannelMac0VlanValid;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelMac0Vlan_t NcsiChannelMac0Vlan;

    /** @brief Nonzero indicates VLAN field is valid */
    RegSHM_CHANNELNcsiChannelMac1VlanValid_t NcsiChannelMac1VlanValid;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelMac1Vlan_t NcsiChannelMac1Vlan;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelStatus_t NcsiChannelStatus;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelResetCount_t NcsiChannelResetCount;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelPxe_t NcsiChannelPxe;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelDropfil_t NcsiChannelDropfil;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelSlink_t NcsiChannelSlink;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_CHANNEL0_H_uint32_t reserved_148[3];

    /** @brief  */
    RegSHM_CHANNELNcsiChannelDbg_t NcsiChannelDbg;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_CHANNEL0_H_uint32_t reserved_164[3];

    /** @brief  */
    RegSHM_CHANNELNcsiChannelCtrlstatRx_t NcsiChannelCtrlstatRx;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelCtrlstatDropped_t NcsiChannelCtrlstatDropped;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelCtrlstatTypeErr_t NcsiChannelCtrlstatTypeErr;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelCtrlstatBadCsum_t NcsiChannelCtrlstatBadCsum;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelCtrlstatAllRx_t NcsiChannelCtrlstatAllRx;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelCtrlstatAllTx_t NcsiChannelCtrlstatAllTx;

    /** @brief  */
    RegSHM_CHANNELNcsiChannelCtrlstatAllAen_t NcsiChannelCtrlstatAllAen;

#ifdef CXX_SIMULATOR
    SHM_CHANNEL_t()
    {
        NcsiChannelInfo.r32.setComponentOffset(0x0);
        NcsiChannelMcid.r32.setComponentOffset(0x4);
        NcsiChannelAen.r32.setComponentOffset(0x8);
        NcsiChannelBfilt.r32.setComponentOffset(0xc);
        NcsiChannelMfilt.r32.setComponentOffset(0x10);
        NcsiChannelSetting1.r32.setComponentOffset(0x14);
        NcsiChannelSetting2.r32.setComponentOffset(0x18);
        NcsiChannelVlan.r32.setComponentOffset(0x1c);
        for(int i = 0; i < 1; i++)
        {
            reserved_32[i].setComponentOffset(0x20 + (i * 4));
        }
        NcsiChannelAltHostMacHigh.r32.setComponentOffset(0x24);
        NcsiChannelAltHostMacMid.r32.setComponentOffset(0x28);
        NcsiChannelAltHostMacLow.r32.setComponentOffset(0x2c);
        for(int i = 0; i < 1; i++)
        {
            reserved_48[i].setComponentOffset(0x30 + (i * 4));
        }
        NcsiChannelMac0High.r32.setComponentOffset(0x34);
        NcsiChannelMac0Mid.r32.setComponentOffset(0x38);
        NcsiChannelMac0Low.r32.setComponentOffset(0x3c);
        for(int i = 0; i < 1; i++)
        {
            reserved_64[i].setComponentOffset(0x40 + (i * 4));
        }
        NcsiChannelMac1High.r32.setComponentOffset(0x44);
        NcsiChannelMac1Mid.r32.setComponentOffset(0x48);
        NcsiChannelMac1Low.r32.setComponentOffset(0x4c);
        for(int i = 0; i < 1; i++)
        {
            reserved_80[i].setComponentOffset(0x50 + (i * 4));
        }
        NcsiChannelMac2High.r32.setComponentOffset(0x54);
        NcsiChannelMac2Mid.r32.setComponentOffset(0x58);
        NcsiChannelMac2Low.r32.setComponentOffset(0x5c);
        for(int i = 0; i < 1; i++)
        {
            reserved_96[i].setComponentOffset(0x60 + (i * 4));
        }
        NcsiChannelMac3High.r32.setComponentOffset(0x64);
        NcsiChannelMac3Mid.r32.setComponentOffset(0x68);
        NcsiChannelMac3Low.r32.setComponentOffset(0x6c);
        NcsiChannelMac0VlanValid.r32.setComponentOffset(0x70);
        NcsiChannelMac0Vlan.r32.setComponentOffset(0x74);
        NcsiChannelMac1VlanValid.r32.setComponentOffset(0x78);
        NcsiChannelMac1Vlan.r32.setComponentOffset(0x7c);
        NcsiChannelStatus.r32.setComponentOffset(0x80);
        NcsiChannelResetCount.r32.setComponentOffset(0x84);
        NcsiChannelPxe.r32.setComponentOffset(0x88);
        NcsiChannelDropfil.r32.setComponentOffset(0x8c);
        NcsiChannelSlink.r32.setComponentOffset(0x90);
        for(int i = 0; i < 3; i++)
        {
            reserved_148[i].setComponentOffset(0x94 + (i * 4));
        }
        NcsiChannelDbg.r32.setComponentOffset(0xa0);
        for(int i = 0; i < 3; i++)
        {
            reserved_164[i].setComponentOffset(0xa4 + (i * 4));
        }
        NcsiChannelCtrlstatRx.r32.setComponentOffset(0xb0);
        NcsiChannelCtrlstatDropped.r32.setComponentOffset(0xb4);
        NcsiChannelCtrlstatTypeErr.r32.setComponentOffset(0xb8);
        NcsiChannelCtrlstatBadCsum.r32.setComponentOffset(0xbc);
        NcsiChannelCtrlstatAllRx.r32.setComponentOffset(0xc0);
        NcsiChannelCtrlstatAllTx.r32.setComponentOffset(0xc4);
        NcsiChannelCtrlstatAllAen.r32.setComponentOffset(0xc8);
    }
    void print()
    {
        NcsiChannelInfo.print();
        NcsiChannelMcid.print();
        NcsiChannelAen.print();
        NcsiChannelBfilt.print();
        NcsiChannelMfilt.print();
        NcsiChannelSetting1.print();
        NcsiChannelSetting2.print();
        NcsiChannelVlan.print();
        for(int i = 0; i < 1; i++)
        {
            reserved_32[i].print();
        }
        NcsiChannelAltHostMacHigh.print();
        NcsiChannelAltHostMacMid.print();
        NcsiChannelAltHostMacLow.print();
        for(int i = 0; i < 1; i++)
        {
            reserved_48[i].print();
        }
        NcsiChannelMac0High.print();
        NcsiChannelMac0Mid.print();
        NcsiChannelMac0Low.print();
        for(int i = 0; i < 1; i++)
        {
            reserved_64[i].print();
        }
        NcsiChannelMac1High.print();
        NcsiChannelMac1Mid.print();
        NcsiChannelMac1Low.print();
        for(int i = 0; i < 1; i++)
        {
            reserved_80[i].print();
        }
        NcsiChannelMac2High.print();
        NcsiChannelMac2Mid.print();
        NcsiChannelMac2Low.print();
        for(int i = 0; i < 1; i++)
        {
            reserved_96[i].print();
        }
        NcsiChannelMac3High.print();
        NcsiChannelMac3Mid.print();
        NcsiChannelMac3Low.print();
        NcsiChannelMac0VlanValid.print();
        NcsiChannelMac0Vlan.print();
        NcsiChannelMac1VlanValid.print();
        NcsiChannelMac1Vlan.print();
        NcsiChannelStatus.print();
        NcsiChannelResetCount.print();
        NcsiChannelPxe.print();
        NcsiChannelDropfil.print();
        NcsiChannelSlink.print();
        for(int i = 0; i < 3; i++)
        {
            reserved_148[i].print();
        }
        NcsiChannelDbg.print();
        for(int i = 0; i < 3; i++)
        {
            reserved_164[i].print();
        }
        NcsiChannelCtrlstatRx.print();
        NcsiChannelCtrlstatDropped.print();
        NcsiChannelCtrlstatTypeErr.print();
        NcsiChannelCtrlstatBadCsum.print();
        NcsiChannelCtrlstatAllRx.print();
        NcsiChannelCtrlstatAllTx.print();
        NcsiChannelCtrlstatAllAen.print();
    }
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
} SHM_CHANNEL_t;

/** @brief Device SHM Registers, function 0 */
extern volatile SHM_CHANNEL_t SHM_CHANNEL0;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !APE_SHM_CHANNEL0_H */

/** @} */
