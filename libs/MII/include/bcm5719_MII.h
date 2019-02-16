////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_MII.h
///
/// @project    bcm5719
///
/// @brief      bcm5719_MII
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

/** @defgroup BCM5719_MII_H    bcm5719_MII */
/** @addtogroup BCM5719_MII_H
 * @{
 */
#ifndef BCM5719_MII_H
#define BCM5719_MII_H

#include <stdint.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_bcm5719_MII_mmap(void* base);
void init_bcm5719_MII(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> BCM5719_MII_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> BCM5719_MII_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> BCM5719_MII_H_uint32_t;
#define BCM5719_MII_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define BCM5719_MII_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define BCM5719_MII_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  BCM5719_MII_H_uint8_t;
typedef uint16_t BCM5719_MII_H_uint16_t;
typedef uint32_t BCM5719_MII_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_MII_BASE ((volatile void*)0x0) /* MII Registers */

#define REG_MII_CONTROL ((volatile BCM5719_MII_H_uint16_t*)0x0) /*  */
#define     MII_CONTROL_UNIDIRECTIONAL_MODE__GPHY_ONLY__SHIFT 5u
#define     MII_CONTROL_UNIDIRECTIONAL_MODE__GPHY_ONLY__MASK  0x20u
#define GET_MII_CONTROL_UNIDIRECTIONAL_MODE__GPHY_ONLY_(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_CONTROL_UNIDIRECTIONAL_MODE__GPHY_ONLY_(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_CONTROL_SPEED_SELECT_MSB_SHIFT 6u
#define     MII_CONTROL_SPEED_SELECT_MSB_MASK  0x40u
#define GET_MII_CONTROL_SPEED_SELECT_MSB(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_CONTROL_SPEED_SELECT_MSB(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_CONTROL_COLLISION_TEST_MODE_SHIFT 7u
#define     MII_CONTROL_COLLISION_TEST_MODE_MASK  0x80u
#define GET_MII_CONTROL_COLLISION_TEST_MODE(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_CONTROL_COLLISION_TEST_MODE(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_CONTROL_FULL_DUPLEX_MODE_SHIFT 8u
#define     MII_CONTROL_FULL_DUPLEX_MODE_MASK  0x100u
#define GET_MII_CONTROL_FULL_DUPLEX_MODE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_CONTROL_FULL_DUPLEX_MODE(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_CONTROL_RESTART_AUTONEGOTIATION_SHIFT 9u
#define     MII_CONTROL_RESTART_AUTONEGOTIATION_MASK  0x200u
#define GET_MII_CONTROL_RESTART_AUTONEGOTIATION(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_CONTROL_RESTART_AUTONEGOTIATION(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_CONTROL_ISOLATE__GPHY_ONLY__SHIFT 10u
#define     MII_CONTROL_ISOLATE__GPHY_ONLY__MASK  0x400u
#define GET_MII_CONTROL_ISOLATE__GPHY_ONLY_(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_CONTROL_ISOLATE__GPHY_ONLY_(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_CONTROL_POWER_DOWN_SHIFT 11u
#define     MII_CONTROL_POWER_DOWN_MASK  0x800u
#define GET_MII_CONTROL_POWER_DOWN(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_CONTROL_POWER_DOWN(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_CONTROL_AUTO_NEGOTIATION_ENABLE_SHIFT 12u
#define     MII_CONTROL_AUTO_NEGOTIATION_ENABLE_MASK  0x1000u
#define GET_MII_CONTROL_AUTO_NEGOTIATION_ENABLE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_CONTROL_AUTO_NEGOTIATION_ENABLE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_CONTROL_SPEED_SELECT_LSB_SHIFT 13u
#define     MII_CONTROL_SPEED_SELECT_LSB_MASK  0x2000u
#define GET_MII_CONTROL_SPEED_SELECT_LSB(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_CONTROL_SPEED_SELECT_LSB(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_CONTROL_SPEED_SELECT_LSB_10MBIT_DIV_S 0x0u
#define     MII_CONTROL_SPEED_SELECT_LSB_100MBIT_DIV_S 0x1u
#define     MII_CONTROL_SPEED_SELECT_LSB_1000MBIT_DIV_S 0x2u
#define     MII_CONTROL_SPEED_SELECT_LSB_RESERVED 0x3u

#define     MII_CONTROL_LOOPBACK_MODE_SHIFT 14u
#define     MII_CONTROL_LOOPBACK_MODE_MASK  0x4000u
#define GET_MII_CONTROL_LOOPBACK_MODE(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_CONTROL_LOOPBACK_MODE(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_CONTROL_RESET_SHIFT 15u
#define     MII_CONTROL_RESET_MASK  0x8000u
#define GET_MII_CONTROL_RESET(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_CONTROL_RESET(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.Control. */
typedef register_container RegMIIControl_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_4_0, 0, 5)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, UnidirectionalMode_GPHYonly_, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SpeedSelectMSB, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CollisionTestMode, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, FullDuplexMode, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RestartAutonegotiation, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Isolate_GPHYonly_, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PowerDown, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationEnable, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SpeedSelectLSB, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LoopbackMode, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Reset, 15, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIControl_t()
    {
        /** @brief constructor for @ref MII_t.Control. */
        bits.UnidirectionalMode_GPHYonly_.setBaseRegister(&r16);
        bits.SpeedSelectMSB.setBaseRegister(&r16);
        bits.CollisionTestMode.setBaseRegister(&r16);
        bits.FullDuplexMode.setBaseRegister(&r16);
        bits.RestartAutonegotiation.setBaseRegister(&r16);
        bits.Isolate_GPHYonly_.setBaseRegister(&r16);
        bits.PowerDown.setBaseRegister(&r16);
        bits.AutoNegotiationEnable.setBaseRegister(&r16);
        bits.SpeedSelectLSB.setBaseRegister(&r16);
        bits.LoopbackMode.setBaseRegister(&r16);
        bits.Reset.setBaseRegister(&r16);
    }
    RegMIIControl_t& operator=(const RegMIIControl_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIControl_t;

#define REG_MII_STATUS ((volatile BCM5719_MII_H_uint16_t*)0x2) /*  */
#define     MII_STATUS_EXTENDED_CAPABILITIES_SUPPORTED_SHIFT 0u
#define     MII_STATUS_EXTENDED_CAPABILITIES_SUPPORTED_MASK  0x1u
#define GET_MII_STATUS_EXTENDED_CAPABILITIES_SUPPORTED(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_MII_STATUS_EXTENDED_CAPABILITIES_SUPPORTED(__val__)  (((__val__) << 0u) & 0x1u)
#define     MII_STATUS_JABBER_DETECTED_SHIFT 1u
#define     MII_STATUS_JABBER_DETECTED_MASK  0x2u
#define GET_MII_STATUS_JABBER_DETECTED(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_MII_STATUS_JABBER_DETECTED(__val__)  (((__val__) << 1u) & 0x2u)
#define     MII_STATUS_LINK_OK_SHIFT 2u
#define     MII_STATUS_LINK_OK_MASK  0x4u
#define GET_MII_STATUS_LINK_OK(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_MII_STATUS_LINK_OK(__val__)  (((__val__) << 2u) & 0x4u)
#define     MII_STATUS_AUTO_NEGOTIATION_CAPABLE_SHIFT 3u
#define     MII_STATUS_AUTO_NEGOTIATION_CAPABLE_MASK  0x8u
#define GET_MII_STATUS_AUTO_NEGOTIATION_CAPABLE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_MII_STATUS_AUTO_NEGOTIATION_CAPABLE(__val__)  (((__val__) << 3u) & 0x8u)
#define     MII_STATUS_REMOTE_FAULT_DETECTED_SHIFT 4u
#define     MII_STATUS_REMOTE_FAULT_DETECTED_MASK  0x10u
#define GET_MII_STATUS_REMOTE_FAULT_DETECTED(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_STATUS_REMOTE_FAULT_DETECTED(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_STATUS_AUTO_NEGOTIATION_COMPLETE_SHIFT 5u
#define     MII_STATUS_AUTO_NEGOTIATION_COMPLETE_MASK  0x20u
#define GET_MII_STATUS_AUTO_NEGOTIATION_COMPLETE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_STATUS_AUTO_NEGOTIATION_COMPLETE(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_STATUS_MF_PREAMBLE_SUPPRESSION_SHIFT 6u
#define     MII_STATUS_MF_PREAMBLE_SUPPRESSION_MASK  0x40u
#define GET_MII_STATUS_MF_PREAMBLE_SUPPRESSION(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_STATUS_MF_PREAMBLE_SUPPRESSION(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_STATUS_UNIDIRECTIONAL_CAPABLE__GPHY_ONLY__SHIFT 7u
#define     MII_STATUS_UNIDIRECTIONAL_CAPABLE__GPHY_ONLY__MASK  0x80u
#define GET_MII_STATUS_UNIDIRECTIONAL_CAPABLE__GPHY_ONLY_(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_STATUS_UNIDIRECTIONAL_CAPABLE__GPHY_ONLY_(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_STATUS_EXTENDED_STATUS_SUPPORTED_SHIFT 8u
#define     MII_STATUS_EXTENDED_STATUS_SUPPORTED_MASK  0x100u
#define GET_MII_STATUS_EXTENDED_STATUS_SUPPORTED(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_STATUS_EXTENDED_STATUS_SUPPORTED(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_STATUS_100BASE_T2_HALF_DUPLEX_CAPABLE_SHIFT 9u
#define     MII_STATUS_100BASE_T2_HALF_DUPLEX_CAPABLE_MASK  0x200u
#define GET_MII_STATUS_100BASE_T2_HALF_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_STATUS_100BASE_T2_HALF_DUPLEX_CAPABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_STATUS_100BASE_T2_FULL_DUPLEX_CAPABLE_SHIFT 10u
#define     MII_STATUS_100BASE_T2_FULL_DUPLEX_CAPABLE_MASK  0x400u
#define GET_MII_STATUS_100BASE_T2_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_STATUS_100BASE_T2_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_STATUS_10BASE_T_HALF_DUPLEX_CAPABLE_SHIFT 11u
#define     MII_STATUS_10BASE_T_HALF_DUPLEX_CAPABLE_MASK  0x800u
#define GET_MII_STATUS_10BASE_T_HALF_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_STATUS_10BASE_T_HALF_DUPLEX_CAPABLE(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_STATUS_10BASE_T_FULL_DUPLEX_CAPABLE_SHIFT 12u
#define     MII_STATUS_10BASE_T_FULL_DUPLEX_CAPABLE_MASK  0x1000u
#define GET_MII_STATUS_10BASE_T_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_STATUS_10BASE_T_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_STATUS_100BASE_X_HALF_DUPLEX_CAPABLE_SHIFT 13u
#define     MII_STATUS_100BASE_X_HALF_DUPLEX_CAPABLE_MASK  0x2000u
#define GET_MII_STATUS_100BASE_X_HALF_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_STATUS_100BASE_X_HALF_DUPLEX_CAPABLE(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_STATUS_100BASE_X_FULL_DUPLEX_CAPABLE_SHIFT 14u
#define     MII_STATUS_100BASE_X_FULL_DUPLEX_CAPABLE_MASK  0x4000u
#define GET_MII_STATUS_100BASE_X_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_STATUS_100BASE_X_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_STATUS_100BASE_T4_CAPABLE_SHIFT 15u
#define     MII_STATUS_100BASE_T4_CAPABLE_MASK  0x8000u
#define GET_MII_STATUS_100BASE_T4_CAPABLE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_STATUS_100BASE_T4_CAPABLE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.Status. */
typedef register_container RegMIIStatus_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ExtendedCapabilitiesSupported, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, JabberDetected, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkOK, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationCapable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteFaultDetected, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationComplete, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MFPreambleSuppression, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, UnidirectionalCapable_GPHYonly_, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ExtendedStatusSupported, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_T2HalfDuplexCapable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_T2FullDuplexCapable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BASE_THalfDuplexCapable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BASE_TFullDuplexCapable, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_XHalfDuplexCapable, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_XFullDuplexCapable, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_T4Capable, 15, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIStatus_t()
    {
        /** @brief constructor for @ref MII_t.Status. */
        bits.ExtendedCapabilitiesSupported.setBaseRegister(&r16);
        bits.JabberDetected.setBaseRegister(&r16);
        bits.LinkOK.setBaseRegister(&r16);
        bits.AutoNegotiationCapable.setBaseRegister(&r16);
        bits.RemoteFaultDetected.setBaseRegister(&r16);
        bits.AutoNegotiationComplete.setBaseRegister(&r16);
        bits.MFPreambleSuppression.setBaseRegister(&r16);
        bits.UnidirectionalCapable_GPHYonly_.setBaseRegister(&r16);
        bits.ExtendedStatusSupported.setBaseRegister(&r16);
        bits._100BASE_T2HalfDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_T2FullDuplexCapable.setBaseRegister(&r16);
        bits._10BASE_THalfDuplexCapable.setBaseRegister(&r16);
        bits._10BASE_TFullDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_XHalfDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_XFullDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_T4Capable.setBaseRegister(&r16);
    }
    RegMIIStatus_t& operator=(const RegMIIStatus_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIStatus_t;

#define REG_MII_PHY_ID_HIGH ((volatile BCM5719_MII_H_uint16_t*)0x4) /*  */
#define     MII_PHY_ID_HIGH_OUI_HIGH_SHIFT 0u
#define     MII_PHY_ID_HIGH_OUI_HIGH_MASK  0xffffu
#define GET_MII_PHY_ID_HIGH_OUI_HIGH(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_MII_PHY_ID_HIGH_OUI_HIGH(__val__)  (((__val__) << 0u) & 0xffffu)

/** @brief Register definition for @ref MII_t.PhyIdHigh. */
typedef register_container RegMIIPhyIdHigh_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief Bits 3:18 of organizationally unique identifier */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, OUIHigh, 0, 16)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIPhyIdHigh_t()
    {
        /** @brief constructor for @ref MII_t.PhyIdHigh. */
        bits.OUIHigh.setBaseRegister(&r16);
    }
    RegMIIPhyIdHigh_t& operator=(const RegMIIPhyIdHigh_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIPhyIdHigh_t;

#define REG_MII_PHY_ID_LOW ((volatile BCM5719_MII_H_uint16_t*)0x6) /*  */
#define     MII_PHY_ID_LOW_REVISION_SHIFT 0u
#define     MII_PHY_ID_LOW_REVISION_MASK  0xfu
#define GET_MII_PHY_ID_LOW_REVISION(__reg__)  (((__reg__) & 0xf) >> 0u)
#define SET_MII_PHY_ID_LOW_REVISION(__val__)  (((__val__) << 0u) & 0xfu)
#define     MII_PHY_ID_LOW_MODEL_SHIFT 4u
#define     MII_PHY_ID_LOW_MODEL_MASK  0x3f0u
#define GET_MII_PHY_ID_LOW_MODEL(__reg__)  (((__reg__) & 0x3f0) >> 4u)
#define SET_MII_PHY_ID_LOW_MODEL(__val__)  (((__val__) << 4u) & 0x3f0u)
#define     MII_PHY_ID_LOW_OUI_LOW_SHIFT 10u
#define     MII_PHY_ID_LOW_OUI_LOW_MASK  0xfc00u
#define GET_MII_PHY_ID_LOW_OUI_LOW(__reg__)  (((__reg__) & 0xfc00) >> 10u)
#define SET_MII_PHY_ID_LOW_OUI_LOW(__val__)  (((__val__) << 10u) & 0xfc00u)

/** @brief Register definition for @ref MII_t.PhyIdLow. */
typedef register_container RegMIIPhyIdLow_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Revision, 0, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Model, 4, 6)
        /** @brief Bits 19:24 of organizationally unique identifier. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, OUILow, 10, 6)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIPhyIdLow_t()
    {
        /** @brief constructor for @ref MII_t.PhyIdLow. */
        bits.Revision.setBaseRegister(&r16);
        bits.Model.setBaseRegister(&r16);
        bits.OUILow.setBaseRegister(&r16);
    }
    RegMIIPhyIdLow_t& operator=(const RegMIIPhyIdLow_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIPhyIdLow_t;

#define REG_MII_AUTONEGOTIATION_ADVERTISEMENT ((volatile BCM5719_MII_H_uint16_t*)0x8) /* Bits in this register indicate what capability bits are advertised to the link partner. */
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_PROTOCOL_SELECT_SHIFT 0u
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_PROTOCOL_SELECT_MASK  0x1fu
#define GET_MII_AUTONEGOTIATION_ADVERTISEMENT_PROTOCOL_SELECT(__reg__)  (((__reg__) & 0x1f) >> 0u)
#define SET_MII_AUTONEGOTIATION_ADVERTISEMENT_PROTOCOL_SELECT(__val__)  (((__val__) << 0u) & 0x1fu)
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_PROTOCOL_SELECT_IEEE_802_3 0x1u

#define     MII_AUTONEGOTIATION_ADVERTISEMENT_10BASE_T_HALF_DUPLEX_CAPABLE_SHIFT 5u
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_10BASE_T_HALF_DUPLEX_CAPABLE_MASK  0x20u
#define GET_MII_AUTONEGOTIATION_ADVERTISEMENT_10BASE_T_HALF_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_AUTONEGOTIATION_ADVERTISEMENT_10BASE_T_HALF_DUPLEX_CAPABLE(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_10BASE_T_FULL_DUPLEX_CAPABLE_SHIFT 6u
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_10BASE_T_FULL_DUPLEX_CAPABLE_MASK  0x40u
#define GET_MII_AUTONEGOTIATION_ADVERTISEMENT_10BASE_T_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_AUTONEGOTIATION_ADVERTISEMENT_10BASE_T_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_100BASE_TX_HALF_DUPLEX_CAPABLE_SHIFT 7u
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_100BASE_TX_HALF_DUPLEX_CAPABLE_MASK  0x80u
#define GET_MII_AUTONEGOTIATION_ADVERTISEMENT_100BASE_TX_HALF_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_AUTONEGOTIATION_ADVERTISEMENT_100BASE_TX_HALF_DUPLEX_CAPABLE(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_100BASE_TX_FULL_DUPLEX_CAPABLE_SHIFT 8u
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_100BASE_TX_FULL_DUPLEX_CAPABLE_MASK  0x100u
#define GET_MII_AUTONEGOTIATION_ADVERTISEMENT_100BASE_TX_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_AUTONEGOTIATION_ADVERTISEMENT_100BASE_TX_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_100BASE_T4_CAPABLE_SHIFT 9u
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_100BASE_T4_CAPABLE_MASK  0x200u
#define GET_MII_AUTONEGOTIATION_ADVERTISEMENT_100BASE_T4_CAPABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_AUTONEGOTIATION_ADVERTISEMENT_100BASE_T4_CAPABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_PAUSE_CAPABLE_SHIFT 10u
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_PAUSE_CAPABLE_MASK  0x400u
#define GET_MII_AUTONEGOTIATION_ADVERTISEMENT_PAUSE_CAPABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_AUTONEGOTIATION_ADVERTISEMENT_PAUSE_CAPABLE(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_ASYMMETRIC_PAUSE_CAPABLE_SHIFT 11u
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_ASYMMETRIC_PAUSE_CAPABLE_MASK  0x800u
#define GET_MII_AUTONEGOTIATION_ADVERTISEMENT_ASYMMETRIC_PAUSE_CAPABLE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_AUTONEGOTIATION_ADVERTISEMENT_ASYMMETRIC_PAUSE_CAPABLE(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_REMOTE_FAULT_SHIFT 13u
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_REMOTE_FAULT_MASK  0x2000u
#define GET_MII_AUTONEGOTIATION_ADVERTISEMENT_REMOTE_FAULT(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_AUTONEGOTIATION_ADVERTISEMENT_REMOTE_FAULT(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_NEXT_PAGE_SHIFT 15u
#define     MII_AUTONEGOTIATION_ADVERTISEMENT_NEXT_PAGE_MASK  0x8000u
#define GET_MII_AUTONEGOTIATION_ADVERTISEMENT_NEXT_PAGE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_AUTONEGOTIATION_ADVERTISEMENT_NEXT_PAGE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.AutonegotiationAdvertisement. */
typedef register_container RegMIIAutonegotiationAdvertisement_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ProtocolSelect, 0, 5)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BASE_THalfDuplexCapable, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BASE_TFullDuplexCapable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_TXHalfDuplexCapable, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_TXFullDuplexCapable, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_T4Capable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PauseCapable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AsymmetricPauseCapable, 11, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_12_12, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteFault, 13, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_14_14, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPage, 15, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIAutonegotiationAdvertisement_t()
    {
        /** @brief constructor for @ref MII_t.AutonegotiationAdvertisement. */
        bits.ProtocolSelect.setBaseRegister(&r16);
        bits._10BASE_THalfDuplexCapable.setBaseRegister(&r16);
        bits._10BASE_TFullDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_TXHalfDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_TXFullDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_T4Capable.setBaseRegister(&r16);
        bits.PauseCapable.setBaseRegister(&r16);
        bits.AsymmetricPauseCapable.setBaseRegister(&r16);
        bits.RemoteFault.setBaseRegister(&r16);
        bits.NextPage.setBaseRegister(&r16);
    }
    RegMIIAutonegotiationAdvertisement_t& operator=(const RegMIIAutonegotiationAdvertisement_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIAutonegotiationAdvertisement_t;

#define REG_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE ((volatile BCM5719_MII_H_uint16_t*)0xa) /* Bits in this register indicate the capabilities of the link partner. */
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_PROTOCOL_SELECTOR_SHIFT 0u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_PROTOCOL_SELECTOR_MASK  0x1fu
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_PROTOCOL_SELECTOR(__reg__)  (((__reg__) & 0x1f) >> 0u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_PROTOCOL_SELECTOR(__val__)  (((__val__) << 0u) & 0x1fu)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_10BASE_T_HALF_DUPLEX_CAPABLE_SHIFT 5u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_10BASE_T_HALF_DUPLEX_CAPABLE_MASK  0x20u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_10BASE_T_HALF_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_10BASE_T_HALF_DUPLEX_CAPABLE(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_10BASE_T_FULL_DUPLEX_CAPABLE_SHIFT 6u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_10BASE_T_FULL_DUPLEX_CAPABLE_MASK  0x40u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_10BASE_T_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_10BASE_T_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_100BASE_TX_HALF_DUPLEX_CAPABLE_SHIFT 7u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_100BASE_TX_HALF_DUPLEX_CAPABLE_MASK  0x80u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_100BASE_TX_HALF_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_100BASE_TX_HALF_DUPLEX_CAPABLE(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_100BASE_TX_FULL_DUPLEX_CAPABLE_SHIFT 8u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_100BASE_TX_FULL_DUPLEX_CAPABLE_MASK  0x100u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_100BASE_TX_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_100BASE_TX_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_100BASE_T4_CAPABLE_SHIFT 9u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_100BASE_T4_CAPABLE_MASK  0x200u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_100BASE_T4_CAPABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_100BASE_T4_CAPABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_PAUSE_CAPABLE_SHIFT 10u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_PAUSE_CAPABLE_MASK  0x400u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_PAUSE_CAPABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_PAUSE_CAPABLE(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_ASYMMETRIC_PAUSE_CAPABLE_SHIFT 11u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_ASYMMETRIC_PAUSE_CAPABLE_MASK  0x800u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_ASYMMETRIC_PAUSE_CAPABLE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_ASYMMETRIC_PAUSE_CAPABLE(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_REMOTE_FAULT_SHIFT 13u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_REMOTE_FAULT_MASK  0x2000u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_REMOTE_FAULT(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_REMOTE_FAULT(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_ACKNOWLEDGE_SHIFT 14u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_ACKNOWLEDGE_MASK  0x4000u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_ACKNOWLEDGE(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_ACKNOWLEDGE(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_NEXT_PAGE_SHIFT 15u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_NEXT_PAGE_MASK  0x8000u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_NEXT_PAGE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE_NEXT_PAGE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.AutonegotiationLinkPartnerAbilityBasePage. */
typedef register_container RegMIIAutonegotiationLinkPartnerAbilityBasePage_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ProtocolSelector, 0, 5)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BASE_THalfDuplexCapable, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BASE_TFullDuplexCapable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_TXHalfDuplexCapable, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_TXFullDuplexCapable, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_T4Capable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PauseCapable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AsymmetricPauseCapable, 11, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_12_12, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteFault, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Acknowledge, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPage, 15, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIAutonegotiationLinkPartnerAbilityBasePage_t()
    {
        /** @brief constructor for @ref MII_t.AutonegotiationLinkPartnerAbilityBasePage. */
        bits.ProtocolSelector.setBaseRegister(&r16);
        bits._10BASE_THalfDuplexCapable.setBaseRegister(&r16);
        bits._10BASE_TFullDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_TXHalfDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_TXFullDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_T4Capable.setBaseRegister(&r16);
        bits.PauseCapable.setBaseRegister(&r16);
        bits.AsymmetricPauseCapable.setBaseRegister(&r16);
        bits.RemoteFault.setBaseRegister(&r16);
        bits.Acknowledge.setBaseRegister(&r16);
        bits.NextPage.setBaseRegister(&r16);
    }
    RegMIIAutonegotiationLinkPartnerAbilityBasePage_t& operator=(const RegMIIAutonegotiationLinkPartnerAbilityBasePage_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIAutonegotiationLinkPartnerAbilityBasePage_t;

#define REG_MII_AUTONEGOTIATION_EXPANSION ((volatile BCM5719_MII_H_uint16_t*)0xc) /*  */
#define     MII_AUTONEGOTIATION_EXPANSION_LINK_PARTNER_AUTONEGOTIATION_CAPABLE_SHIFT 0u
#define     MII_AUTONEGOTIATION_EXPANSION_LINK_PARTNER_AUTONEGOTIATION_CAPABLE_MASK  0x1u
#define GET_MII_AUTONEGOTIATION_EXPANSION_LINK_PARTNER_AUTONEGOTIATION_CAPABLE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_MII_AUTONEGOTIATION_EXPANSION_LINK_PARTNER_AUTONEGOTIATION_CAPABLE(__val__)  (((__val__) << 0u) & 0x1u)
#define     MII_AUTONEGOTIATION_EXPANSION_PAGE_RECEIVED_SHIFT 1u
#define     MII_AUTONEGOTIATION_EXPANSION_PAGE_RECEIVED_MASK  0x2u
#define GET_MII_AUTONEGOTIATION_EXPANSION_PAGE_RECEIVED(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_MII_AUTONEGOTIATION_EXPANSION_PAGE_RECEIVED(__val__)  (((__val__) << 1u) & 0x2u)
#define     MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_CAPABLE_SHIFT 2u
#define     MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_CAPABLE_MASK  0x4u
#define GET_MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_CAPABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_CAPABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     MII_AUTONEGOTIATION_EXPANSION_LINK_PARTNER_NEXT_PAGE_CAPABLE_SHIFT 3u
#define     MII_AUTONEGOTIATION_EXPANSION_LINK_PARTNER_NEXT_PAGE_CAPABLE_MASK  0x8u
#define GET_MII_AUTONEGOTIATION_EXPANSION_LINK_PARTNER_NEXT_PAGE_CAPABLE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_MII_AUTONEGOTIATION_EXPANSION_LINK_PARTNER_NEXT_PAGE_CAPABLE(__val__)  (((__val__) << 3u) & 0x8u)
#define     MII_AUTONEGOTIATION_EXPANSION_PARALLEL_DETECTION_FAULT_SHIFT 4u
#define     MII_AUTONEGOTIATION_EXPANSION_PARALLEL_DETECTION_FAULT_MASK  0x10u
#define GET_MII_AUTONEGOTIATION_EXPANSION_PARALLEL_DETECTION_FAULT(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_AUTONEGOTIATION_EXPANSION_PARALLEL_DETECTION_FAULT(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_RECEIVE_LOCATION_SHIFT 5u
#define     MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_RECEIVE_LOCATION_MASK  0x20u
#define GET_MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_RECEIVE_LOCATION(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_RECEIVE_LOCATION(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_RECEIVE_LOCATION_NEXT_PAGES_STORED_IN_REGISTER_0X05 0x0u
#define     MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_RECEIVE_LOCATION_NEXT_PAGES_STORED_IN_REGISTER_0X08 0x1u

#define     MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_RECEIVE_LOCATION_CAPABLE_SHIFT 6u
#define     MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_RECEIVE_LOCATION_CAPABLE_MASK  0x40u
#define GET_MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_RECEIVE_LOCATION_CAPABLE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_AUTONEGOTIATION_EXPANSION_NEXT_PAGE_RECEIVE_LOCATION_CAPABLE(__val__)  (((__val__) << 6u) & 0x40u)

/** @brief Register definition for @ref MII_t.AutonegotiationExpansion. */
typedef register_container RegMIIAutonegotiationExpansion_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkPartnerAutonegotiationCapable, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PageReceived, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPageCapable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkPartnerNextPageCapable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ParallelDetectionFault, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPageReceiveLocation, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPageReceiveLocationCapable, 6, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIAutonegotiationExpansion_t()
    {
        /** @brief constructor for @ref MII_t.AutonegotiationExpansion. */
        bits.LinkPartnerAutonegotiationCapable.setBaseRegister(&r16);
        bits.PageReceived.setBaseRegister(&r16);
        bits.NextPageCapable.setBaseRegister(&r16);
        bits.LinkPartnerNextPageCapable.setBaseRegister(&r16);
        bits.ParallelDetectionFault.setBaseRegister(&r16);
        bits.NextPageReceiveLocation.setBaseRegister(&r16);
        bits.NextPageReceiveLocationCapable.setBaseRegister(&r16);
    }
    RegMIIAutonegotiationExpansion_t& operator=(const RegMIIAutonegotiationExpansion_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIAutonegotiationExpansion_t;

#define REG_MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT ((volatile BCM5719_MII_H_uint16_t*)0xe) /*  */
#define     MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_CODE_FIELD_SHIFT 0u
#define     MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_CODE_FIELD_MASK  0x7ffu
#define GET_MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_CODE_FIELD(__reg__)  (((__reg__) & 0x7ff) >> 0u)
#define SET_MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_CODE_FIELD(__val__)  (((__val__) << 0u) & 0x7ffu)
#define     MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_TOGGLE_SHIFT 11u
#define     MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_TOGGLE_MASK  0x800u
#define GET_MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_TOGGLE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_TOGGLE(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_ACKNOWLEDGE_2_SHIFT 12u
#define     MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_ACKNOWLEDGE_2_MASK  0x1000u
#define GET_MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_ACKNOWLEDGE_2(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_ACKNOWLEDGE_2(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_MESSAGE_PAGE_SHIFT 13u
#define     MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_MESSAGE_PAGE_MASK  0x2000u
#define GET_MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_MESSAGE_PAGE(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_MESSAGE_PAGE(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_NEXT_PAGE_SHIFT 15u
#define     MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_NEXT_PAGE_MASK  0x8000u
#define GET_MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_NEXT_PAGE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT_NEXT_PAGE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.AutonegotiationNextPageTransmit. */
typedef register_container RegMIIAutonegotiationNextPageTransmit_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CodeField, 0, 11)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Toggle, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Acknowledge2, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MessagePage, 13, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_14_14, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPage, 15, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIAutonegotiationNextPageTransmit_t()
    {
        /** @brief constructor for @ref MII_t.AutonegotiationNextPageTransmit. */
        bits.CodeField.setBaseRegister(&r16);
        bits.Toggle.setBaseRegister(&r16);
        bits.Acknowledge2.setBaseRegister(&r16);
        bits.MessagePage.setBaseRegister(&r16);
        bits.NextPage.setBaseRegister(&r16);
    }
    RegMIIAutonegotiationNextPageTransmit_t& operator=(const RegMIIAutonegotiationNextPageTransmit_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIAutonegotiationNextPageTransmit_t;

#define REG_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE ((volatile BCM5719_MII_H_uint16_t*)0x10) /*  */
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_CODE_FIELD_SHIFT 0u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_CODE_FIELD_MASK  0x7ffu
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_CODE_FIELD(__reg__)  (((__reg__) & 0x7ff) >> 0u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_CODE_FIELD(__val__)  (((__val__) << 0u) & 0x7ffu)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_TOGGLE_2_SHIFT 11u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_TOGGLE_2_MASK  0x800u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_TOGGLE_2(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_TOGGLE_2(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_ACKNOWLEDGE_2_SHIFT 12u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_ACKNOWLEDGE_2_MASK  0x1000u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_ACKNOWLEDGE_2(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_ACKNOWLEDGE_2(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_MESSAGE_PAGE_SHIFT 13u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_MESSAGE_PAGE_MASK  0x2000u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_MESSAGE_PAGE(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_MESSAGE_PAGE(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_ACKNOWLEDGE_3_SHIFT 14u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_ACKNOWLEDGE_3_MASK  0x4000u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_ACKNOWLEDGE_3(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_ACKNOWLEDGE_3(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_NEXT_PAGE_SHIFT 15u
#define     MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_NEXT_PAGE_MASK  0x8000u
#define GET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_NEXT_PAGE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE_NEXT_PAGE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.AutonegotiationLinkPartnerAbilityNextPage. */
typedef register_container RegMIIAutonegotiationLinkPartnerAbilityNextPage_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CodeField, 0, 11)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Toggle2, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Acknowledge2, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MessagePage, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Acknowledge3, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPage, 15, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIAutonegotiationLinkPartnerAbilityNextPage_t()
    {
        /** @brief constructor for @ref MII_t.AutonegotiationLinkPartnerAbilityNextPage. */
        bits.CodeField.setBaseRegister(&r16);
        bits.Toggle2.setBaseRegister(&r16);
        bits.Acknowledge2.setBaseRegister(&r16);
        bits.MessagePage.setBaseRegister(&r16);
        bits.Acknowledge3.setBaseRegister(&r16);
        bits.NextPage.setBaseRegister(&r16);
    }
    RegMIIAutonegotiationLinkPartnerAbilityNextPage_t& operator=(const RegMIIAutonegotiationLinkPartnerAbilityNextPage_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIAutonegotiationLinkPartnerAbilityNextPage_t;

#define REG_MII_1000BASE_T_CONTROL ((volatile BCM5719_MII_H_uint16_t*)0x12) /*  */
#define     MII_1000BASE_T_CONTROL_ADVERTISE_1000BASE_T_HALF_DUPLEX_SHIFT 8u
#define     MII_1000BASE_T_CONTROL_ADVERTISE_1000BASE_T_HALF_DUPLEX_MASK  0x100u
#define GET_MII_1000BASE_T_CONTROL_ADVERTISE_1000BASE_T_HALF_DUPLEX(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_1000BASE_T_CONTROL_ADVERTISE_1000BASE_T_HALF_DUPLEX(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_1000BASE_T_CONTROL_ADVERTISE_1000BASE_T_FULL_DUPLEX_SHIFT 9u
#define     MII_1000BASE_T_CONTROL_ADVERTISE_1000BASE_T_FULL_DUPLEX_MASK  0x200u
#define GET_MII_1000BASE_T_CONTROL_ADVERTISE_1000BASE_T_FULL_DUPLEX(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_1000BASE_T_CONTROL_ADVERTISE_1000BASE_T_FULL_DUPLEX(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_1000BASE_T_CONTROL_REPEATER_DTE_SHIFT 10u
#define     MII_1000BASE_T_CONTROL_REPEATER_DTE_MASK  0x400u
#define GET_MII_1000BASE_T_CONTROL_REPEATER_DTE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_1000BASE_T_CONTROL_REPEATER_DTE(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_1000BASE_T_CONTROL_MASTER_SLAVE_CONFIG_VALUE_SHIFT 11u
#define     MII_1000BASE_T_CONTROL_MASTER_SLAVE_CONFIG_VALUE_MASK  0x800u
#define GET_MII_1000BASE_T_CONTROL_MASTER_SLAVE_CONFIG_VALUE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_1000BASE_T_CONTROL_MASTER_SLAVE_CONFIG_VALUE(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_1000BASE_T_CONTROL_MASTER_SLAVE_CONFIG_ENABLE_SHIFT 12u
#define     MII_1000BASE_T_CONTROL_MASTER_SLAVE_CONFIG_ENABLE_MASK  0x1000u
#define GET_MII_1000BASE_T_CONTROL_MASTER_SLAVE_CONFIG_ENABLE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_1000BASE_T_CONTROL_MASTER_SLAVE_CONFIG_ENABLE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_1000BASE_T_CONTROL_TEST_MODE_SHIFT 13u
#define     MII_1000BASE_T_CONTROL_TEST_MODE_MASK  0xe000u
#define GET_MII_1000BASE_T_CONTROL_TEST_MODE(__reg__)  (((__reg__) & 0xe000) >> 13u)
#define SET_MII_1000BASE_T_CONTROL_TEST_MODE(__val__)  (((__val__) << 13u) & 0xe000u)

/** @brief Register definition for @ref MII_t.1000baseTControl. */
typedef register_container RegMII1000baseTControl_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_7_0, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Advertise1000BASE_THalfDuplex, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Advertise1000BASE_TFullDuplex, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RepeaterDTE, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MasterSlaveConfigValue, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MasterSlaveConfigEnable, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TestMode, 13, 3)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMII1000baseTControl_t()
    {
        /** @brief constructor for @ref MII_t.1000baseTControl. */
        bits.Advertise1000BASE_THalfDuplex.setBaseRegister(&r16);
        bits.Advertise1000BASE_TFullDuplex.setBaseRegister(&r16);
        bits.RepeaterDTE.setBaseRegister(&r16);
        bits.MasterSlaveConfigValue.setBaseRegister(&r16);
        bits.MasterSlaveConfigEnable.setBaseRegister(&r16);
        bits.TestMode.setBaseRegister(&r16);
    }
    RegMII1000baseTControl_t& operator=(const RegMII1000baseTControl_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMII1000baseTControl_t;

#define REG_MII_1000BASE_T_STATUS ((volatile BCM5719_MII_H_uint16_t*)0x14) /*  */
#define     MII_1000BASE_T_STATUS_IDLE_ERROR_COUNT_SHIFT 0u
#define     MII_1000BASE_T_STATUS_IDLE_ERROR_COUNT_MASK  0xffu
#define GET_MII_1000BASE_T_STATUS_IDLE_ERROR_COUNT(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_MII_1000BASE_T_STATUS_IDLE_ERROR_COUNT(__val__)  (((__val__) << 0u) & 0xffu)
#define     MII_1000BASE_T_STATUS_LINK_PARTNER_1000BASE_T_HALF_DUPLEX_CAPABLE_SHIFT 10u
#define     MII_1000BASE_T_STATUS_LINK_PARTNER_1000BASE_T_HALF_DUPLEX_CAPABLE_MASK  0x400u
#define GET_MII_1000BASE_T_STATUS_LINK_PARTNER_1000BASE_T_HALF_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_1000BASE_T_STATUS_LINK_PARTNER_1000BASE_T_HALF_DUPLEX_CAPABLE(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_1000BASE_T_STATUS_LINK_PARTNER_1000BASE_T_FULL_DUPLEX_CAPABLE_SHIFT 11u
#define     MII_1000BASE_T_STATUS_LINK_PARTNER_1000BASE_T_FULL_DUPLEX_CAPABLE_MASK  0x800u
#define GET_MII_1000BASE_T_STATUS_LINK_PARTNER_1000BASE_T_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_1000BASE_T_STATUS_LINK_PARTNER_1000BASE_T_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_1000BASE_T_STATUS_REMOTE_RECEIVER_STATUS_SHIFT 12u
#define     MII_1000BASE_T_STATUS_REMOTE_RECEIVER_STATUS_MASK  0x1000u
#define GET_MII_1000BASE_T_STATUS_REMOTE_RECEIVER_STATUS(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_1000BASE_T_STATUS_REMOTE_RECEIVER_STATUS(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_1000BASE_T_STATUS_LOCAL_RECEIVER_STATUS_SHIFT 13u
#define     MII_1000BASE_T_STATUS_LOCAL_RECEIVER_STATUS_MASK  0x2000u
#define GET_MII_1000BASE_T_STATUS_LOCAL_RECEIVER_STATUS(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_1000BASE_T_STATUS_LOCAL_RECEIVER_STATUS(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_1000BASE_T_STATUS_MASTER_SLAVE_CONFIG_RESOLUTION_SHIFT 14u
#define     MII_1000BASE_T_STATUS_MASTER_SLAVE_CONFIG_RESOLUTION_MASK  0x4000u
#define GET_MII_1000BASE_T_STATUS_MASTER_SLAVE_CONFIG_RESOLUTION(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_1000BASE_T_STATUS_MASTER_SLAVE_CONFIG_RESOLUTION(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_1000BASE_T_STATUS_MASTER_SLAVE_CONFIG_FAULT_SHIFT 15u
#define     MII_1000BASE_T_STATUS_MASTER_SLAVE_CONFIG_FAULT_MASK  0x8000u
#define GET_MII_1000BASE_T_STATUS_MASTER_SLAVE_CONFIG_FAULT(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_1000BASE_T_STATUS_MASTER_SLAVE_CONFIG_FAULT(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.1000baseTStatus. */
typedef register_container RegMII1000baseTStatus_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, IdleErrorCount, 0, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_9_8, 8, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkPartner1000BASE_THalfDuplexCapable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkPartner1000BASE_TFullDuplexCapable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteReceiverStatus, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LocalReceiverStatus, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MasterSlaveConfigResolution, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MasterSlaveConfigFault, 15, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMII1000baseTStatus_t()
    {
        /** @brief constructor for @ref MII_t.1000baseTStatus. */
        bits.IdleErrorCount.setBaseRegister(&r16);
        bits.LinkPartner1000BASE_THalfDuplexCapable.setBaseRegister(&r16);
        bits.LinkPartner1000BASE_TFullDuplexCapable.setBaseRegister(&r16);
        bits.RemoteReceiverStatus.setBaseRegister(&r16);
        bits.LocalReceiverStatus.setBaseRegister(&r16);
        bits.MasterSlaveConfigResolution.setBaseRegister(&r16);
        bits.MasterSlaveConfigFault.setBaseRegister(&r16);
    }
    RegMII1000baseTStatus_t& operator=(const RegMII1000baseTStatus_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMII1000baseTStatus_t;

#define REG_MII_BROADREACH_LRE_ACCESS ((volatile BCM5719_MII_H_uint16_t*)0x1c) /* WTH is this. */
#define     MII_BROADREACH_LRE_ACCESS_LRE_REGISTER_ACCESS_STATUS_SHIFT 0u
#define     MII_BROADREACH_LRE_ACCESS_LRE_REGISTER_ACCESS_STATUS_MASK  0x1u
#define GET_MII_BROADREACH_LRE_ACCESS_LRE_REGISTER_ACCESS_STATUS(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_MII_BROADREACH_LRE_ACCESS_LRE_REGISTER_ACCESS_STATUS(__val__)  (((__val__) << 0u) & 0x1u)
#define     MII_BROADREACH_LRE_ACCESS_LRE_REGISTER_OVERRIDE_VALUE_SHIFT 1u
#define     MII_BROADREACH_LRE_ACCESS_LRE_REGISTER_OVERRIDE_VALUE_MASK  0x2u
#define GET_MII_BROADREACH_LRE_ACCESS_LRE_REGISTER_OVERRIDE_VALUE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_MII_BROADREACH_LRE_ACCESS_LRE_REGISTER_OVERRIDE_VALUE(__val__)  (((__val__) << 1u) & 0x2u)
#define     MII_BROADREACH_LRE_ACCESS_ENABLE_LRE_REGISTER_ACCESS_OVERRIDE_SHIFT 2u
#define     MII_BROADREACH_LRE_ACCESS_ENABLE_LRE_REGISTER_ACCESS_OVERRIDE_MASK  0x4u
#define GET_MII_BROADREACH_LRE_ACCESS_ENABLE_LRE_REGISTER_ACCESS_OVERRIDE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_MII_BROADREACH_LRE_ACCESS_ENABLE_LRE_REGISTER_ACCESS_OVERRIDE(__val__)  (((__val__) << 2u) & 0x4u)

/** @brief Register definition for @ref MII_t.BroadreachLreAccess. */
typedef register_container RegMIIBroadreachLreAccess_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LRERegisterAccessStatus, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LRERegisterOverrideValue, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnableLRERegisterAccessOverride, 2, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIBroadreachLreAccess_t()
    {
        /** @brief constructor for @ref MII_t.BroadreachLreAccess. */
        bits.LRERegisterAccessStatus.setBaseRegister(&r16);
        bits.LRERegisterOverrideValue.setBaseRegister(&r16);
        bits.EnableLRERegisterAccessOverride.setBaseRegister(&r16);
    }
    RegMIIBroadreachLreAccess_t& operator=(const RegMIIBroadreachLreAccess_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIBroadreachLreAccess_t;

#define REG_MII_IEEE_EXTENDED_STATUS ((volatile BCM5719_MII_H_uint16_t*)0x1e) /*  */
#define     MII_IEEE_EXTENDED_STATUS_1000BASE_T_HALF_DUPLEX_CAPABLE_SHIFT 12u
#define     MII_IEEE_EXTENDED_STATUS_1000BASE_T_HALF_DUPLEX_CAPABLE_MASK  0x1000u
#define GET_MII_IEEE_EXTENDED_STATUS_1000BASE_T_HALF_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_IEEE_EXTENDED_STATUS_1000BASE_T_HALF_DUPLEX_CAPABLE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_IEEE_EXTENDED_STATUS_1000BASE_T_FULL_DUPLEX_CAPABLE_SHIFT 13u
#define     MII_IEEE_EXTENDED_STATUS_1000BASE_T_FULL_DUPLEX_CAPABLE_MASK  0x2000u
#define GET_MII_IEEE_EXTENDED_STATUS_1000BASE_T_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_IEEE_EXTENDED_STATUS_1000BASE_T_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_IEEE_EXTENDED_STATUS_1000BASE_X_HALF_DUPLEX_CAPABLE_SHIFT 15u
#define     MII_IEEE_EXTENDED_STATUS_1000BASE_X_HALF_DUPLEX_CAPABLE_MASK  0x8000u
#define GET_MII_IEEE_EXTENDED_STATUS_1000BASE_X_HALF_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_IEEE_EXTENDED_STATUS_1000BASE_X_HALF_DUPLEX_CAPABLE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.IeeeExtendedStatus. */
typedef register_container RegMIIIeeeExtendedStatus_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_11_0, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _1000BASE_THalfDuplexCapable, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _1000BASE_TFullDuplexCapable, 13, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_14_14, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _1000BASE_XHalfDuplexCapable, 15, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIIeeeExtendedStatus_t()
    {
        /** @brief constructor for @ref MII_t.IeeeExtendedStatus. */
        bits._1000BASE_THalfDuplexCapable.setBaseRegister(&r16);
        bits._1000BASE_TFullDuplexCapable.setBaseRegister(&r16);
        bits._1000BASE_XHalfDuplexCapable.setBaseRegister(&r16);
    }
    RegMIIIeeeExtendedStatus_t& operator=(const RegMIIIeeeExtendedStatus_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIIeeeExtendedStatus_t;

#define REG_MII_PHY_EXTENDED_STATUS ((volatile BCM5719_MII_H_uint16_t*)0x22) /*  */
#define     MII_PHY_EXTENDED_STATUS_MLT3_CODE_ERROR_DETECTED_SHIFT 0u
#define     MII_PHY_EXTENDED_STATUS_MLT3_CODE_ERROR_DETECTED_MASK  0x1u
#define GET_MII_PHY_EXTENDED_STATUS_MLT3_CODE_ERROR_DETECTED(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_MII_PHY_EXTENDED_STATUS_MLT3_CODE_ERROR_DETECTED(__val__)  (((__val__) << 0u) & 0x1u)
#define     MII_PHY_EXTENDED_STATUS_LOCK_ERROR_DETECTED_SHIFT 1u
#define     MII_PHY_EXTENDED_STATUS_LOCK_ERROR_DETECTED_MASK  0x2u
#define GET_MII_PHY_EXTENDED_STATUS_LOCK_ERROR_DETECTED(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_MII_PHY_EXTENDED_STATUS_LOCK_ERROR_DETECTED(__val__)  (((__val__) << 1u) & 0x2u)
#define     MII_PHY_EXTENDED_STATUS_TRANSMIT_ERROR_DETECTED_SHIFT 2u
#define     MII_PHY_EXTENDED_STATUS_TRANSMIT_ERROR_DETECTED_MASK  0x4u
#define GET_MII_PHY_EXTENDED_STATUS_TRANSMIT_ERROR_DETECTED(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_MII_PHY_EXTENDED_STATUS_TRANSMIT_ERROR_DETECTED(__val__)  (((__val__) << 2u) & 0x4u)
#define     MII_PHY_EXTENDED_STATUS_RECEIVE_ERROR_DETECTED_SHIFT 3u
#define     MII_PHY_EXTENDED_STATUS_RECEIVE_ERROR_DETECTED_MASK  0x8u
#define GET_MII_PHY_EXTENDED_STATUS_RECEIVE_ERROR_DETECTED(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_MII_PHY_EXTENDED_STATUS_RECEIVE_ERROR_DETECTED(__val__)  (((__val__) << 3u) & 0x8u)
#define     MII_PHY_EXTENDED_STATUS_BAD_ESD_DETECTED_SHIFT 4u
#define     MII_PHY_EXTENDED_STATUS_BAD_ESD_DETECTED_MASK  0x10u
#define GET_MII_PHY_EXTENDED_STATUS_BAD_ESD_DETECTED(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_PHY_EXTENDED_STATUS_BAD_ESD_DETECTED(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_PHY_EXTENDED_STATUS_BAD_SSD_DETECTED_SHIFT 5u
#define     MII_PHY_EXTENDED_STATUS_BAD_SSD_DETECTED_MASK  0x20u
#define GET_MII_PHY_EXTENDED_STATUS_BAD_SSD_DETECTED(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_PHY_EXTENDED_STATUS_BAD_SSD_DETECTED(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_PHY_EXTENDED_STATUS_CARRIER_EXTENSION_ERROR_DETECTED_SHIFT 6u
#define     MII_PHY_EXTENDED_STATUS_CARRIER_EXTENSION_ERROR_DETECTED_MASK  0x40u
#define GET_MII_PHY_EXTENDED_STATUS_CARRIER_EXTENSION_ERROR_DETECTED(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_PHY_EXTENDED_STATUS_CARRIER_EXTENSION_ERROR_DETECTED(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_PHY_EXTENDED_STATUS_CRC_ERROR_DETECTED_SHIFT 7u
#define     MII_PHY_EXTENDED_STATUS_CRC_ERROR_DETECTED_MASK  0x80u
#define GET_MII_PHY_EXTENDED_STATUS_CRC_ERROR_DETECTED(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_PHY_EXTENDED_STATUS_CRC_ERROR_DETECTED(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_PHY_EXTENDED_STATUS_LINK_STATUS_SHIFT 8u
#define     MII_PHY_EXTENDED_STATUS_LINK_STATUS_MASK  0x100u
#define GET_MII_PHY_EXTENDED_STATUS_LINK_STATUS(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_PHY_EXTENDED_STATUS_LINK_STATUS(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_PHY_EXTENDED_STATUS_LOCKED_SHIFT 9u
#define     MII_PHY_EXTENDED_STATUS_LOCKED_MASK  0x200u
#define GET_MII_PHY_EXTENDED_STATUS_LOCKED(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_PHY_EXTENDED_STATUS_LOCKED(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_PHY_EXTENDED_STATUS_LOCAL_RECEIVER_STATUS_SHIFT 10u
#define     MII_PHY_EXTENDED_STATUS_LOCAL_RECEIVER_STATUS_MASK  0x400u
#define GET_MII_PHY_EXTENDED_STATUS_LOCAL_RECEIVER_STATUS(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_PHY_EXTENDED_STATUS_LOCAL_RECEIVER_STATUS(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_PHY_EXTENDED_STATUS_REMOTE_RECEIVER_STATUS_SHIFT 11u
#define     MII_PHY_EXTENDED_STATUS_REMOTE_RECEIVER_STATUS_MASK  0x800u
#define GET_MII_PHY_EXTENDED_STATUS_REMOTE_RECEIVER_STATUS(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_PHY_EXTENDED_STATUS_REMOTE_RECEIVER_STATUS(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_PHY_EXTENDED_STATUS_INTERRUPT_STATUS_SHIFT 12u
#define     MII_PHY_EXTENDED_STATUS_INTERRUPT_STATUS_MASK  0x1000u
#define GET_MII_PHY_EXTENDED_STATUS_INTERRUPT_STATUS(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_PHY_EXTENDED_STATUS_INTERRUPT_STATUS(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_PHY_EXTENDED_STATUS_MDI_CROSSOVER_STATE_SHIFT 13u
#define     MII_PHY_EXTENDED_STATUS_MDI_CROSSOVER_STATE_MASK  0x2000u
#define GET_MII_PHY_EXTENDED_STATUS_MDI_CROSSOVER_STATE(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_PHY_EXTENDED_STATUS_MDI_CROSSOVER_STATE(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_PHY_EXTENDED_STATUS_WIRESPEED_DOWNGRADE_SHIFT 14u
#define     MII_PHY_EXTENDED_STATUS_WIRESPEED_DOWNGRADE_MASK  0x4000u
#define GET_MII_PHY_EXTENDED_STATUS_WIRESPEED_DOWNGRADE(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_PHY_EXTENDED_STATUS_WIRESPEED_DOWNGRADE(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_PHY_EXTENDED_STATUS_AUTONEGOTIATION_BASE_PAGE_SELECTOR_FIELD_MISMATCH_SHIFT 15u
#define     MII_PHY_EXTENDED_STATUS_AUTONEGOTIATION_BASE_PAGE_SELECTOR_FIELD_MISMATCH_MASK  0x8000u
#define GET_MII_PHY_EXTENDED_STATUS_AUTONEGOTIATION_BASE_PAGE_SELECTOR_FIELD_MISMATCH(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_PHY_EXTENDED_STATUS_AUTONEGOTIATION_BASE_PAGE_SELECTOR_FIELD_MISMATCH(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.PhyExtendedStatus. */
typedef register_container RegMIIPhyExtendedStatus_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MLT3CodeErrorDetected, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LockErrorDetected, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TransmitErrorDetected, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ReceiveErrorDetected, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BadESDDetected, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BadSSDDetected, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CarrierExtensionErrorDetected, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CRCErrorDetected, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkStatus, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Locked, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LocalReceiverStatus, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteReceiverStatus, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, InterruptStatus, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MDICrossoverState, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WirespeedDowngrade, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutonegotiationBasePageSelectorFieldMismatch, 15, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIPhyExtendedStatus_t()
    {
        /** @brief constructor for @ref MII_t.PhyExtendedStatus. */
        bits.MLT3CodeErrorDetected.setBaseRegister(&r16);
        bits.LockErrorDetected.setBaseRegister(&r16);
        bits.TransmitErrorDetected.setBaseRegister(&r16);
        bits.ReceiveErrorDetected.setBaseRegister(&r16);
        bits.BadESDDetected.setBaseRegister(&r16);
        bits.BadSSDDetected.setBaseRegister(&r16);
        bits.CarrierExtensionErrorDetected.setBaseRegister(&r16);
        bits.CRCErrorDetected.setBaseRegister(&r16);
        bits.LinkStatus.setBaseRegister(&r16);
        bits.Locked.setBaseRegister(&r16);
        bits.LocalReceiverStatus.setBaseRegister(&r16);
        bits.RemoteReceiverStatus.setBaseRegister(&r16);
        bits.InterruptStatus.setBaseRegister(&r16);
        bits.MDICrossoverState.setBaseRegister(&r16);
        bits.WirespeedDowngrade.setBaseRegister(&r16);
        bits.AutonegotiationBasePageSelectorFieldMismatch.setBaseRegister(&r16);
    }
    RegMIIPhyExtendedStatus_t& operator=(const RegMIIPhyExtendedStatus_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIPhyExtendedStatus_t;

#define REG_MII_RECEIVE_ERROR_COUNTER ((volatile BCM5719_MII_H_uint16_t*)0x24) /*  */
#define     MII_RECEIVE_ERROR_COUNTER_RECEIVE_ERROR_COUNTER_SHIFT 0u
#define     MII_RECEIVE_ERROR_COUNTER_RECEIVE_ERROR_COUNTER_MASK  0xffffu
#define GET_MII_RECEIVE_ERROR_COUNTER_RECEIVE_ERROR_COUNTER(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_MII_RECEIVE_ERROR_COUNTER_RECEIVE_ERROR_COUNTER(__val__)  (((__val__) << 0u) & 0xffffu)

/** @brief Register definition for @ref MII_t.ReceiveErrorCounter. */
typedef register_container RegMIIReceiveErrorCounter_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ReceiveErrorCounter, 0, 16)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIReceiveErrorCounter_t()
    {
        /** @brief constructor for @ref MII_t.ReceiveErrorCounter. */
        bits.ReceiveErrorCounter.setBaseRegister(&r16);
    }
    RegMIIReceiveErrorCounter_t& operator=(const RegMIIReceiveErrorCounter_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIReceiveErrorCounter_t;

#define REG_MII_FALSE_CARRIER_SENSE_COUNTER ((volatile BCM5719_MII_H_uint16_t*)0x26) /*  */
#define     MII_FALSE_CARRIER_SENSE_COUNTER_FALSE_CARRIER_SENSE_COUNTER_SHIFT 0u
#define     MII_FALSE_CARRIER_SENSE_COUNTER_FALSE_CARRIER_SENSE_COUNTER_MASK  0xffu
#define GET_MII_FALSE_CARRIER_SENSE_COUNTER_FALSE_CARRIER_SENSE_COUNTER(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_MII_FALSE_CARRIER_SENSE_COUNTER_FALSE_CARRIER_SENSE_COUNTER(__val__)  (((__val__) << 0u) & 0xffu)
#define     MII_FALSE_CARRIER_SENSE_COUNTER_SERDES_BER_COUNTER_SHIFT 8u
#define     MII_FALSE_CARRIER_SENSE_COUNTER_SERDES_BER_COUNTER_MASK  0xff00u
#define GET_MII_FALSE_CARRIER_SENSE_COUNTER_SERDES_BER_COUNTER(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_MII_FALSE_CARRIER_SENSE_COUNTER_SERDES_BER_COUNTER(__val__)  (((__val__) << 8u) & 0xff00u)

/** @brief Register definition for @ref MII_t.FalseCarrierSenseCounter. */
typedef register_container RegMIIFalseCarrierSenseCounter_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, FalseCarrierSenseCounter, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SERDESBERCounter, 8, 8)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIFalseCarrierSenseCounter_t()
    {
        /** @brief constructor for @ref MII_t.FalseCarrierSenseCounter. */
        bits.FalseCarrierSenseCounter.setBaseRegister(&r16);
        bits.SERDESBERCounter.setBaseRegister(&r16);
    }
    RegMIIFalseCarrierSenseCounter_t& operator=(const RegMIIFalseCarrierSenseCounter_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIFalseCarrierSenseCounter_t;

#define REG_MII_LOCAL_REMOTE_RECEIVER_NOT_OK_COUNTER ((volatile BCM5719_MII_H_uint16_t*)0x28) /*  */
#define     MII_LOCAL_REMOTE_RECEIVER_NOT_OK_COUNTER_REMOTE_RECEIVER_NOT_OK_COUNTER_SHIFT 0u
#define     MII_LOCAL_REMOTE_RECEIVER_NOT_OK_COUNTER_REMOTE_RECEIVER_NOT_OK_COUNTER_MASK  0xffu
#define GET_MII_LOCAL_REMOTE_RECEIVER_NOT_OK_COUNTER_REMOTE_RECEIVER_NOT_OK_COUNTER(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_MII_LOCAL_REMOTE_RECEIVER_NOT_OK_COUNTER_REMOTE_RECEIVER_NOT_OK_COUNTER(__val__)  (((__val__) << 0u) & 0xffu)
#define     MII_LOCAL_REMOTE_RECEIVER_NOT_OK_COUNTER_LOCAL_RECEIVER_NOT_OK_COUNTER_SHIFT 8u
#define     MII_LOCAL_REMOTE_RECEIVER_NOT_OK_COUNTER_LOCAL_RECEIVER_NOT_OK_COUNTER_MASK  0xff00u
#define GET_MII_LOCAL_REMOTE_RECEIVER_NOT_OK_COUNTER_LOCAL_RECEIVER_NOT_OK_COUNTER(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_MII_LOCAL_REMOTE_RECEIVER_NOT_OK_COUNTER_LOCAL_RECEIVER_NOT_OK_COUNTER(__val__)  (((__val__) << 8u) & 0xff00u)

/** @brief Register definition for @ref MII_t.LocalRemoteReceiverNotOkCounter. */
typedef register_container RegMIILocalRemoteReceiverNotOkCounter_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteReceiverNotOKCounter, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LocalReceiverNotOKCounter, 8, 8)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIILocalRemoteReceiverNotOkCounter_t()
    {
        /** @brief constructor for @ref MII_t.LocalRemoteReceiverNotOkCounter. */
        bits.RemoteReceiverNotOKCounter.setBaseRegister(&r16);
        bits.LocalReceiverNotOKCounter.setBaseRegister(&r16);
    }
    RegMIILocalRemoteReceiverNotOkCounter_t& operator=(const RegMIILocalRemoteReceiverNotOkCounter_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIILocalRemoteReceiverNotOkCounter_t;

#define REG_MII_AUXILLARY_STATUS_SUMMARY ((volatile BCM5719_MII_H_uint16_t*)0x32) /*  */
#define     MII_AUXILLARY_STATUS_SUMMARY_PAUSE_RESOLUTION___TRANSMIT_DIRECTION_SHIFT 0u
#define     MII_AUXILLARY_STATUS_SUMMARY_PAUSE_RESOLUTION___TRANSMIT_DIRECTION_MASK  0x1u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_PAUSE_RESOLUTION___TRANSMIT_DIRECTION(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_PAUSE_RESOLUTION___TRANSMIT_DIRECTION(__val__)  (((__val__) << 0u) & 0x1u)
#define     MII_AUXILLARY_STATUS_SUMMARY_PAUSE_RESOLUTION___RECEIVE_DIRECTION_SHIFT 1u
#define     MII_AUXILLARY_STATUS_SUMMARY_PAUSE_RESOLUTION___RECEIVE_DIRECTION_MASK  0x2u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_PAUSE_RESOLUTION___RECEIVE_DIRECTION(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_PAUSE_RESOLUTION___RECEIVE_DIRECTION(__val__)  (((__val__) << 1u) & 0x2u)
#define     MII_AUXILLARY_STATUS_SUMMARY_LINK_STATUS_SHIFT 2u
#define     MII_AUXILLARY_STATUS_SUMMARY_LINK_STATUS_MASK  0x4u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_LINK_STATUS(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_LINK_STATUS(__val__)  (((__val__) << 2u) & 0x4u)
#define     MII_AUXILLARY_STATUS_SUMMARY_LINK_PARTNER_NEXT_PAGE_CAPABLE_SHIFT 3u
#define     MII_AUXILLARY_STATUS_SUMMARY_LINK_PARTNER_NEXT_PAGE_CAPABLE_MASK  0x8u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_LINK_PARTNER_NEXT_PAGE_CAPABLE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_LINK_PARTNER_NEXT_PAGE_CAPABLE(__val__)  (((__val__) << 3u) & 0x8u)
#define     MII_AUXILLARY_STATUS_SUMMARY_LINK_PARTNER_AUTONEGOTIATION_CAPABLE_SHIFT 4u
#define     MII_AUXILLARY_STATUS_SUMMARY_LINK_PARTNER_AUTONEGOTIATION_CAPABLE_MASK  0x10u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_LINK_PARTNER_AUTONEGOTIATION_CAPABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_LINK_PARTNER_AUTONEGOTIATION_CAPABLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_AUXILLARY_STATUS_SUMMARY_PAGE_RECEIVED_SHIFT 5u
#define     MII_AUXILLARY_STATUS_SUMMARY_PAGE_RECEIVED_MASK  0x20u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_PAGE_RECEIVED(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_PAGE_RECEIVED(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_AUXILLARY_STATUS_SUMMARY_REMOTE_FAULT_SHIFT 6u
#define     MII_AUXILLARY_STATUS_SUMMARY_REMOTE_FAULT_MASK  0x40u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_REMOTE_FAULT(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_REMOTE_FAULT(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_AUXILLARY_STATUS_SUMMARY_PARALLEL_DETECTION_FAULT_SHIFT 7u
#define     MII_AUXILLARY_STATUS_SUMMARY_PARALLEL_DETECTION_FAULT_MASK  0x80u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_PARALLEL_DETECTION_FAULT(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_PARALLEL_DETECTION_FAULT(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_HCD_SHIFT 8u
#define     MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_HCD_MASK  0x700u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_HCD(__reg__)  (((__reg__) & 0x700) >> 8u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_HCD(__val__)  (((__val__) << 8u) & 0x700u)
#define     MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_NEXT_PAGE_WAIT_SHIFT 11u
#define     MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_NEXT_PAGE_WAIT_MASK  0x800u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_NEXT_PAGE_WAIT(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_NEXT_PAGE_WAIT(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_ABILITY_DETECT_SHIFT 12u
#define     MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_ABILITY_DETECT_MASK  0x1000u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_ABILITY_DETECT(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_ABILITY_DETECT(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_ACK_DETECT_SHIFT 13u
#define     MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_ACK_DETECT_MASK  0x2000u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_ACK_DETECT(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_ACK_DETECT(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_COMPLETE_ACK_SHIFT 14u
#define     MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_COMPLETE_ACK_MASK  0x4000u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_COMPLETE_ACK(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_COMPLETE_ACK(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_COMPLETE_SHIFT 15u
#define     MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_COMPLETE_MASK  0x8000u
#define GET_MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_COMPLETE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_AUXILLARY_STATUS_SUMMARY_AUTONEGOTIATION_COMPLETE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.AuxillaryStatusSummary. */
typedef register_container RegMIIAuxillaryStatusSummary_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PauseResolution_TransmitDirection, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PauseResolution_ReceiveDirection, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkStatus, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkPartnerNextPageCapable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkPartnerAutonegotiationCapable, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PageReceived, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteFault, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ParallelDetectionFault, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutonegotiationHCD, 8, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutonegotiationNextPageWait, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutonegotiationAbilityDetect, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutonegotiationACKDetect, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutonegotiationCompleteACK, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutonegotiationComplete, 15, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIAuxillaryStatusSummary_t()
    {
        /** @brief constructor for @ref MII_t.AuxillaryStatusSummary. */
        bits.PauseResolution_TransmitDirection.setBaseRegister(&r16);
        bits.PauseResolution_ReceiveDirection.setBaseRegister(&r16);
        bits.LinkStatus.setBaseRegister(&r16);
        bits.LinkPartnerNextPageCapable.setBaseRegister(&r16);
        bits.LinkPartnerAutonegotiationCapable.setBaseRegister(&r16);
        bits.PageReceived.setBaseRegister(&r16);
        bits.RemoteFault.setBaseRegister(&r16);
        bits.ParallelDetectionFault.setBaseRegister(&r16);
        bits.AutonegotiationHCD.setBaseRegister(&r16);
        bits.AutonegotiationNextPageWait.setBaseRegister(&r16);
        bits.AutonegotiationAbilityDetect.setBaseRegister(&r16);
        bits.AutonegotiationACKDetect.setBaseRegister(&r16);
        bits.AutonegotiationCompleteACK.setBaseRegister(&r16);
        bits.AutonegotiationComplete.setBaseRegister(&r16);
    }
    RegMIIAuxillaryStatusSummary_t& operator=(const RegMIIAuxillaryStatusSummary_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIAuxillaryStatusSummary_t;

#define REG_MII_INTERRUPT_STATUS ((volatile BCM5719_MII_H_uint16_t*)0x34) /*  */
#define     MII_INTERRUPT_STATUS_CRC_ERROR_SHIFT 0u
#define     MII_INTERRUPT_STATUS_CRC_ERROR_MASK  0x1u
#define GET_MII_INTERRUPT_STATUS_CRC_ERROR(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_MII_INTERRUPT_STATUS_CRC_ERROR(__val__)  (((__val__) << 0u) & 0x1u)
#define     MII_INTERRUPT_STATUS_LINK_STATUS_CHANGE_SHIFT 1u
#define     MII_INTERRUPT_STATUS_LINK_STATUS_CHANGE_MASK  0x2u
#define GET_MII_INTERRUPT_STATUS_LINK_STATUS_CHANGE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_MII_INTERRUPT_STATUS_LINK_STATUS_CHANGE(__val__)  (((__val__) << 1u) & 0x2u)
#define     MII_INTERRUPT_STATUS_LINK_SPEED_CHANGE_SHIFT 2u
#define     MII_INTERRUPT_STATUS_LINK_SPEED_CHANGE_MASK  0x4u
#define GET_MII_INTERRUPT_STATUS_LINK_SPEED_CHANGE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_MII_INTERRUPT_STATUS_LINK_SPEED_CHANGE(__val__)  (((__val__) << 2u) & 0x4u)
#define     MII_INTERRUPT_STATUS_DUPLEX_MODE_CHANGE_SHIFT 3u
#define     MII_INTERRUPT_STATUS_DUPLEX_MODE_CHANGE_MASK  0x8u
#define GET_MII_INTERRUPT_STATUS_DUPLEX_MODE_CHANGE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_MII_INTERRUPT_STATUS_DUPLEX_MODE_CHANGE(__val__)  (((__val__) << 3u) & 0x8u)
#define     MII_INTERRUPT_STATUS_LOCAL_RECEIVER_STATUS_CHANGE_SHIFT 4u
#define     MII_INTERRUPT_STATUS_LOCAL_RECEIVER_STATUS_CHANGE_MASK  0x10u
#define GET_MII_INTERRUPT_STATUS_LOCAL_RECEIVER_STATUS_CHANGE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_INTERRUPT_STATUS_LOCAL_RECEIVER_STATUS_CHANGE(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_INTERRUPT_STATUS_REMOTE_RECEIVER_STATUS_CHANGE_SHIFT 5u
#define     MII_INTERRUPT_STATUS_REMOTE_RECEIVER_STATUS_CHANGE_MASK  0x20u
#define GET_MII_INTERRUPT_STATUS_REMOTE_RECEIVER_STATUS_CHANGE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_INTERRUPT_STATUS_REMOTE_RECEIVER_STATUS_CHANGE(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_INTERRUPT_STATUS_SCRAMBLER_SYNC_ERROR_SHIFT 6u
#define     MII_INTERRUPT_STATUS_SCRAMBLER_SYNC_ERROR_MASK  0x40u
#define GET_MII_INTERRUPT_STATUS_SCRAMBLER_SYNC_ERROR(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_INTERRUPT_STATUS_SCRAMBLER_SYNC_ERROR(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_INTERRUPT_STATUS_NEGOTIATED_UNSUPPORTED_HCD_SHIFT 7u
#define     MII_INTERRUPT_STATUS_NEGOTIATED_UNSUPPORTED_HCD_MASK  0x80u
#define GET_MII_INTERRUPT_STATUS_NEGOTIATED_UNSUPPORTED_HCD(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_INTERRUPT_STATUS_NEGOTIATED_UNSUPPORTED_HCD(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_INTERRUPT_STATUS_NO_HCD_SHIFT 8u
#define     MII_INTERRUPT_STATUS_NO_HCD_MASK  0x100u
#define GET_MII_INTERRUPT_STATUS_NO_HCD(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_INTERRUPT_STATUS_NO_HCD(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_INTERRUPT_STATUS_HCD_NO_LINK_SHIFT 9u
#define     MII_INTERRUPT_STATUS_HCD_NO_LINK_MASK  0x200u
#define GET_MII_INTERRUPT_STATUS_HCD_NO_LINK(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_INTERRUPT_STATUS_HCD_NO_LINK(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_INTERRUPT_STATUS_AUTONEGOTIATION_PAGE_RX_SHIFT 10u
#define     MII_INTERRUPT_STATUS_AUTONEGOTIATION_PAGE_RX_MASK  0x400u
#define GET_MII_INTERRUPT_STATUS_AUTONEGOTIATION_PAGE_RX(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_INTERRUPT_STATUS_AUTONEGOTIATION_PAGE_RX(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_INTERRUPT_STATUS_EXCEEDED_LOW_COUNTER_THRESHOLD_SHIFT 11u
#define     MII_INTERRUPT_STATUS_EXCEEDED_LOW_COUNTER_THRESHOLD_MASK  0x800u
#define GET_MII_INTERRUPT_STATUS_EXCEEDED_LOW_COUNTER_THRESHOLD(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_INTERRUPT_STATUS_EXCEEDED_LOW_COUNTER_THRESHOLD(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_INTERRUPT_STATUS_MDIX_STATUS_CHANGE_SHIFT 12u
#define     MII_INTERRUPT_STATUS_MDIX_STATUS_CHANGE_MASK  0x1000u
#define GET_MII_INTERRUPT_STATUS_MDIX_STATUS_CHANGE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_INTERRUPT_STATUS_MDIX_STATUS_CHANGE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_INTERRUPT_STATUS_ILLEGAL_PAIR_SWAP_SHIFT 14u
#define     MII_INTERRUPT_STATUS_ILLEGAL_PAIR_SWAP_MASK  0x4000u
#define GET_MII_INTERRUPT_STATUS_ILLEGAL_PAIR_SWAP(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_INTERRUPT_STATUS_ILLEGAL_PAIR_SWAP(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_INTERRUPT_STATUS_IP_STATUS_CHANGE_SHIFT 15u
#define     MII_INTERRUPT_STATUS_IP_STATUS_CHANGE_MASK  0x8000u
#define GET_MII_INTERRUPT_STATUS_IP_STATUS_CHANGE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_INTERRUPT_STATUS_IP_STATUS_CHANGE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.InterruptStatus. */
typedef register_container RegMIIInterruptStatus_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CRCError, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkStatusChange, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkSpeedChange, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DuplexModeChange, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LocalReceiverStatusChange, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteReceiverStatusChange, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ScramblerSyncError, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NegotiatedUnsupportedHCD, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NoHCD, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, HCDNoLink, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutonegotiationPageRX, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ExceededLowCounterThreshold, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MDIXStatusChange, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_13_13, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, IllegalPairSwap, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, IPStatusChange, 15, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIInterruptStatus_t()
    {
        /** @brief constructor for @ref MII_t.InterruptStatus. */
        bits.CRCError.setBaseRegister(&r16);
        bits.LinkStatusChange.setBaseRegister(&r16);
        bits.LinkSpeedChange.setBaseRegister(&r16);
        bits.DuplexModeChange.setBaseRegister(&r16);
        bits.LocalReceiverStatusChange.setBaseRegister(&r16);
        bits.RemoteReceiverStatusChange.setBaseRegister(&r16);
        bits.ScramblerSyncError.setBaseRegister(&r16);
        bits.NegotiatedUnsupportedHCD.setBaseRegister(&r16);
        bits.NoHCD.setBaseRegister(&r16);
        bits.HCDNoLink.setBaseRegister(&r16);
        bits.AutonegotiationPageRX.setBaseRegister(&r16);
        bits.ExceededLowCounterThreshold.setBaseRegister(&r16);
        bits.MDIXStatusChange.setBaseRegister(&r16);
        bits.IllegalPairSwap.setBaseRegister(&r16);
        bits.IPStatusChange.setBaseRegister(&r16);
    }
    RegMIIInterruptStatus_t& operator=(const RegMIIInterruptStatus_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIInterruptStatus_t;

#define REG_MII_INTERRUPT_MASK ((volatile BCM5719_MII_H_uint16_t*)0x36) /*  */
#define     MII_INTERRUPT_MASK_INTERRUPT_MASK_VECTOR_SHIFT 0u
#define     MII_INTERRUPT_MASK_INTERRUPT_MASK_VECTOR_MASK  0xffffu
#define GET_MII_INTERRUPT_MASK_INTERRUPT_MASK_VECTOR(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_MII_INTERRUPT_MASK_INTERRUPT_MASK_VECTOR(__val__)  (((__val__) << 0u) & 0xffffu)

/** @brief Register definition for @ref MII_t.InterruptMask. */
typedef register_container RegMIIInterruptMask_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, InterruptMaskVector, 0, 16)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIIInterruptMask_t()
    {
        /** @brief constructor for @ref MII_t.InterruptMask. */
        bits.InterruptMaskVector.setBaseRegister(&r16);
    }
    RegMIIInterruptMask_t& operator=(const RegMIIInterruptMask_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIInterruptMask_t;

#define REG_MII_TEST_1 ((volatile BCM5719_MII_H_uint16_t*)0x3c) /*  */
#define     MII_TEST_1_MAIN_DAC_TRIM_SHIFT 0u
#define     MII_TEST_1_MAIN_DAC_TRIM_MASK  0xfu
#define GET_MII_TEST_1_MAIN_DAC_TRIM(__reg__)  (((__reg__) & 0xf) >> 0u)
#define SET_MII_TEST_1_MAIN_DAC_TRIM(__val__)  (((__val__) << 0u) & 0xfu)
#define     MII_TEST_1_MAIN_DAC_ENABLE_SOFTWARE_TRIM_SETTING_SHIFT 4u
#define     MII_TEST_1_MAIN_DAC_ENABLE_SOFTWARE_TRIM_SETTING_MASK  0x10u
#define GET_MII_TEST_1_MAIN_DAC_ENABLE_SOFTWARE_TRIM_SETTING(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_TEST_1_MAIN_DAC_ENABLE_SOFTWARE_TRIM_SETTING(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_TEST_1_DISABLE_POLARITY_ENCODE_SHIFT 5u
#define     MII_TEST_1_DISABLE_POLARITY_ENCODE_MASK  0x20u
#define GET_MII_TEST_1_DISABLE_POLARITY_ENCODE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_TEST_1_DISABLE_POLARITY_ENCODE(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_TEST_1_RECEIVE_WATCHDOG_TIMER_DISABLE_SHIFT 6u
#define     MII_TEST_1_RECEIVE_WATCHDOG_TIMER_DISABLE_MASK  0x40u
#define GET_MII_TEST_1_RECEIVE_WATCHDOG_TIMER_DISABLE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_TEST_1_RECEIVE_WATCHDOG_TIMER_DISABLE(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_TEST_1_MANUAL_SWAP_MDI_STATE_SHIFT 7u
#define     MII_TEST_1_MANUAL_SWAP_MDI_STATE_MASK  0x80u
#define GET_MII_TEST_1_MANUAL_SWAP_MDI_STATE(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_TEST_1_MANUAL_SWAP_MDI_STATE(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_TEST_1_FAST_TIMERS_SHIFT 8u
#define     MII_TEST_1_FAST_TIMERS_MASK  0x100u
#define GET_MII_TEST_1_FAST_TIMERS(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_TEST_1_FAST_TIMERS(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_TEST_1_EXTERNAL_LINK_SHIFT 9u
#define     MII_TEST_1_EXTERNAL_LINK_MASK  0x200u
#define GET_MII_TEST_1_EXTERNAL_LINK(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_TEST_1_EXTERNAL_LINK(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_TEST_1_SCRAMBLER_TEST_SHIFT 10u
#define     MII_TEST_1_SCRAMBLER_TEST_MASK  0x400u
#define GET_MII_TEST_1_SCRAMBLER_TEST(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_TEST_1_SCRAMBLER_TEST(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_TEST_1_FORCE_LOCK_SHIFT 11u
#define     MII_TEST_1_FORCE_LOCK_MASK  0x800u
#define GET_MII_TEST_1_FORCE_LOCK(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_TEST_1_FORCE_LOCK(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_TEST_1_FORCE_LINK_SHIFT 12u
#define     MII_TEST_1_FORCE_LINK_MASK  0x1000u
#define GET_MII_TEST_1_FORCE_LINK(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_TEST_1_FORCE_LINK(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_TEST_1_COUNTER_TEST_MODE_SHIFT 13u
#define     MII_TEST_1_COUNTER_TEST_MODE_MASK  0x2000u
#define GET_MII_TEST_1_COUNTER_TEST_MODE(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_TEST_1_COUNTER_TEST_MODE(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_TEST_1_TRANSMIT_ERROR_CODE_VISIBILITY_SHIFT 14u
#define     MII_TEST_1_TRANSMIT_ERROR_CODE_VISIBILITY_MASK  0x4000u
#define GET_MII_TEST_1_TRANSMIT_ERROR_CODE_VISIBILITY(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_TEST_1_TRANSMIT_ERROR_CODE_VISIBILITY(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_TEST_1_CRC_ERROR_COUNT_VISIBILITY_SHIFT 15u
#define     MII_TEST_1_CRC_ERROR_COUNT_VISIBILITY_MASK  0x8000u
#define GET_MII_TEST_1_CRC_ERROR_COUNT_VISIBILITY(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_TEST_1_CRC_ERROR_COUNT_VISIBILITY(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.Test1. */
typedef register_container RegMIITest1_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MainDACTrim, 0, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MainDACEnableSoftwareTrimSetting, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisablePolarityEncode, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ReceiveWatchdogTimerDisable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ManualSwapMDIState, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, FastTimers, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ExternalLink, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ScramblerTest, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceLock, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceLink, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CounterTestMode, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TransmitErrorCodeVisibility, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CRCErrorCountVisibility, 15, 1)
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    RegMIITest1_t()
    {
        /** @brief constructor for @ref MII_t.Test1. */
        bits.MainDACTrim.setBaseRegister(&r16);
        bits.MainDACEnableSoftwareTrimSetting.setBaseRegister(&r16);
        bits.DisablePolarityEncode.setBaseRegister(&r16);
        bits.ReceiveWatchdogTimerDisable.setBaseRegister(&r16);
        bits.ManualSwapMDIState.setBaseRegister(&r16);
        bits.FastTimers.setBaseRegister(&r16);
        bits.ExternalLink.setBaseRegister(&r16);
        bits.ScramblerTest.setBaseRegister(&r16);
        bits.ForceLock.setBaseRegister(&r16);
        bits.ForceLink.setBaseRegister(&r16);
        bits.CounterTestMode.setBaseRegister(&r16);
        bits.TransmitErrorCodeVisibility.setBaseRegister(&r16);
        bits.CRCErrorCountVisibility.setBaseRegister(&r16);
    }
    RegMIITest1_t& operator=(const RegMIITest1_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIITest1_t;

/** @brief Component definition for @ref MII. */
typedef struct {
    /** @brief  */
    RegMIIControl_t Control;

    /** @brief  */
    RegMIIStatus_t Status;

    /** @brief  */
    RegMIIPhyIdHigh_t PhyIdHigh;

    /** @brief  */
    RegMIIPhyIdLow_t PhyIdLow;

    /** @brief Bits in this register indicate what capability bits are advertised to the link partner. */
    RegMIIAutonegotiationAdvertisement_t AutonegotiationAdvertisement;

    /** @brief Bits in this register indicate the capabilities of the link partner. */
    RegMIIAutonegotiationLinkPartnerAbilityBasePage_t AutonegotiationLinkPartnerAbilityBasePage;

    /** @brief  */
    RegMIIAutonegotiationExpansion_t AutonegotiationExpansion;

    /** @brief  */
    RegMIIAutonegotiationNextPageTransmit_t AutonegotiationNextPageTransmit;

    /** @brief  */
    RegMIIAutonegotiationLinkPartnerAbilityNextPage_t AutonegotiationLinkPartnerAbilityNextPage;

    /** @brief  */
    RegMII1000baseTControl_t _1000baseTControl;

    /** @brief  */
    RegMII1000baseTStatus_t _1000baseTStatus;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint8_t reserved_11[3];

    /** @brief WTH is this. */
    RegMIIBroadreachLreAccess_t BroadreachLreAccess;

    /** @brief  */
    RegMIIIeeeExtendedStatus_t IeeeExtendedStatus;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint8_t reserved_16[1];

    /** @brief  */
    RegMIIPhyExtendedStatus_t PhyExtendedStatus;

    /** @brief  */
    RegMIIReceiveErrorCounter_t ReceiveErrorCounter;

    /** @brief  */
    RegMIIFalseCarrierSenseCounter_t FalseCarrierSenseCounter;

    /** @brief  */
    RegMIILocalRemoteReceiverNotOkCounter_t LocalRemoteReceiverNotOkCounter;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint32_t reserved_21[1];

    /** @brief  */
    RegMIIAuxillaryStatusSummary_t AuxillaryStatusSummary;

    /** @brief  */
    RegMIIInterruptStatus_t InterruptStatus;

    /** @brief  */
    RegMIIInterruptMask_t InterruptMask;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint16_t reserved_28[1];

    /** @brief  */
    RegMIITest1_t Test1;

} MII_t;

/** @brief MII Registers */
extern volatile MII_t MII;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !BCM5719_MII_H */

/** @} */
