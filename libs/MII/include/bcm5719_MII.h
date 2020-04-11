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

/** @defgroup BCM5719_MII_H    bcm5719_MII */
/** @addtogroup BCM5719_MII_H
 * @{
 */
#ifndef BCM5719_MII_H
#define BCM5719_MII_H

#include <types.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_bcm5719_MII_sim(void* base);
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
#define REG_MII_SIZE (sizeof(MII_t))

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
#if defined(__LITTLE_ENDIAN__)
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
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Reset, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LoopbackMode, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SpeedSelectLSB, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationEnable, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PowerDown, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Isolate_GPHYonly_, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RestartAutonegotiation, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, FullDuplexMode, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CollisionTestMode, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SpeedSelectMSB, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, UnidirectionalMode_GPHYonly_, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_4_0, 0, 5)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Control"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIControl_t()
    {
        /** @brief constructor for @ref MII_t.Control. */
        r16.setName("Control");
        bits.UnidirectionalMode_GPHYonly_.setBaseRegister(&r16);
        bits.UnidirectionalMode_GPHYonly_.setName("UnidirectionalMode_GPHYonly_");
        bits.SpeedSelectMSB.setBaseRegister(&r16);
        bits.SpeedSelectMSB.setName("SpeedSelectMSB");
        bits.CollisionTestMode.setBaseRegister(&r16);
        bits.CollisionTestMode.setName("CollisionTestMode");
        bits.FullDuplexMode.setBaseRegister(&r16);
        bits.FullDuplexMode.setName("FullDuplexMode");
        bits.RestartAutonegotiation.setBaseRegister(&r16);
        bits.RestartAutonegotiation.setName("RestartAutonegotiation");
        bits.Isolate_GPHYonly_.setBaseRegister(&r16);
        bits.Isolate_GPHYonly_.setName("Isolate_GPHYonly_");
        bits.PowerDown.setBaseRegister(&r16);
        bits.PowerDown.setName("PowerDown");
        bits.AutoNegotiationEnable.setBaseRegister(&r16);
        bits.AutoNegotiationEnable.setName("AutoNegotiationEnable");
        bits.SpeedSelectLSB.setBaseRegister(&r16);
        bits.SpeedSelectLSB.setName("SpeedSelectLSB");
        bits.SpeedSelectLSB.addEnum("10Mbit/s", 0x0);
        bits.SpeedSelectLSB.addEnum("100Mbit/s", 0x1);
        bits.SpeedSelectLSB.addEnum("1000Mbit/s", 0x2);
        bits.SpeedSelectLSB.addEnum("Reserved", 0x3);

        bits.LoopbackMode.setBaseRegister(&r16);
        bits.LoopbackMode.setName("LoopbackMode");
        bits.Reset.setBaseRegister(&r16);
        bits.Reset.setName("Reset");
    }
    RegMIIControl_t& operator=(const RegMIIControl_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIControl_t;

#define REG_MII_STATUS ((volatile BCM5719_MII_H_uint16_t*)0x1) /*  */
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
#if defined(__LITTLE_ENDIAN__)
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
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_T4Capable, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_XFullDuplexCapable, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_XHalfDuplexCapable, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BASE_TFullDuplexCapable, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BASE_THalfDuplexCapable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_T2FullDuplexCapable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_T2HalfDuplexCapable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ExtendedStatusSupported, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, UnidirectionalCapable_GPHYonly_, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MFPreambleSuppression, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationComplete, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteFaultDetected, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationCapable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkOK, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, JabberDetected, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ExtendedCapabilitiesSupported, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Status"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIStatus_t()
    {
        /** @brief constructor for @ref MII_t.Status. */
        r16.setName("Status");
        bits.ExtendedCapabilitiesSupported.setBaseRegister(&r16);
        bits.ExtendedCapabilitiesSupported.setName("ExtendedCapabilitiesSupported");
        bits.JabberDetected.setBaseRegister(&r16);
        bits.JabberDetected.setName("JabberDetected");
        bits.LinkOK.setBaseRegister(&r16);
        bits.LinkOK.setName("LinkOK");
        bits.AutoNegotiationCapable.setBaseRegister(&r16);
        bits.AutoNegotiationCapable.setName("AutoNegotiationCapable");
        bits.RemoteFaultDetected.setBaseRegister(&r16);
        bits.RemoteFaultDetected.setName("RemoteFaultDetected");
        bits.AutoNegotiationComplete.setBaseRegister(&r16);
        bits.AutoNegotiationComplete.setName("AutoNegotiationComplete");
        bits.MFPreambleSuppression.setBaseRegister(&r16);
        bits.MFPreambleSuppression.setName("MFPreambleSuppression");
        bits.UnidirectionalCapable_GPHYonly_.setBaseRegister(&r16);
        bits.UnidirectionalCapable_GPHYonly_.setName("UnidirectionalCapable_GPHYonly_");
        bits.ExtendedStatusSupported.setBaseRegister(&r16);
        bits.ExtendedStatusSupported.setName("ExtendedStatusSupported");
        bits._100BASE_T2HalfDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_T2HalfDuplexCapable.setName("_100BASE_T2HalfDuplexCapable");
        bits._100BASE_T2FullDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_T2FullDuplexCapable.setName("_100BASE_T2FullDuplexCapable");
        bits._10BASE_THalfDuplexCapable.setBaseRegister(&r16);
        bits._10BASE_THalfDuplexCapable.setName("_10BASE_THalfDuplexCapable");
        bits._10BASE_TFullDuplexCapable.setBaseRegister(&r16);
        bits._10BASE_TFullDuplexCapable.setName("_10BASE_TFullDuplexCapable");
        bits._100BASE_XHalfDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_XHalfDuplexCapable.setName("_100BASE_XHalfDuplexCapable");
        bits._100BASE_XFullDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_XFullDuplexCapable.setName("_100BASE_XFullDuplexCapable");
        bits._100BASE_T4Capable.setBaseRegister(&r16);
        bits._100BASE_T4Capable.setName("_100BASE_T4Capable");
    }
    RegMIIStatus_t& operator=(const RegMIIStatus_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIStatus_t;

#define REG_MII_PHY_ID_HIGH ((volatile BCM5719_MII_H_uint16_t*)0x2) /*  */
#define     MII_PHY_ID_HIGH_OUI_HIGH_SHIFT 0u
#define     MII_PHY_ID_HIGH_OUI_HIGH_MASK  0xffffu
#define GET_MII_PHY_ID_HIGH_OUI_HIGH(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_MII_PHY_ID_HIGH_OUI_HIGH(__val__)  (((__val__) << 0u) & 0xffffu)

/** @brief Register definition for @ref MII_t.PhyIdHigh. */
typedef register_container RegMIIPhyIdHigh_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Bits 3:18 of organizationally unique identifier */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, OUIHigh, 0, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Bits 3:18 of organizationally unique identifier */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, OUIHigh, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PhyIdHigh"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIPhyIdHigh_t()
    {
        /** @brief constructor for @ref MII_t.PhyIdHigh. */
        r16.setName("PhyIdHigh");
        bits.OUIHigh.setBaseRegister(&r16);
        bits.OUIHigh.setName("OUIHigh");
    }
    RegMIIPhyIdHigh_t& operator=(const RegMIIPhyIdHigh_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIPhyIdHigh_t;

#define REG_MII_PHY_ID_LOW ((volatile BCM5719_MII_H_uint16_t*)0x3) /*  */
#define     MII_PHY_ID_LOW_REVISION_SHIFT 0u
#define     MII_PHY_ID_LOW_REVISION_MASK  0xfu
#define GET_MII_PHY_ID_LOW_REVISION(__reg__)  (((__reg__) & 0xf) >> 0u)
#define SET_MII_PHY_ID_LOW_REVISION(__val__)  (((__val__) << 0u) & 0xfu)
#define     MII_PHY_ID_LOW_MODEL_SHIFT 4u
#define     MII_PHY_ID_LOW_MODEL_MASK  0x3f0u
#define GET_MII_PHY_ID_LOW_MODEL(__reg__)  (((__reg__) & 0x3f0) >> 4u)
#define SET_MII_PHY_ID_LOW_MODEL(__val__)  (((__val__) << 4u) & 0x3f0u)
#define     MII_PHY_ID_LOW_MODEL_5718 0x20u
#define     MII_PHY_ID_LOW_MODEL_5719 0x22u
#define     MII_PHY_ID_LOW_MODEL_5717B0 0x22u
#define     MII_PHY_ID_LOW_MODEL_5720 0x36u
#define     MII_PHY_ID_LOW_MODEL_5717C0 0x36u

#define     MII_PHY_ID_LOW_OUI_LOW_SHIFT 10u
#define     MII_PHY_ID_LOW_OUI_LOW_MASK  0xfc00u
#define GET_MII_PHY_ID_LOW_OUI_LOW(__reg__)  (((__reg__) & 0xfc00) >> 10u)
#define SET_MII_PHY_ID_LOW_OUI_LOW(__val__)  (((__val__) << 10u) & 0xfc00u)

/** @brief Register definition for @ref MII_t.PhyIdLow. */
typedef register_container RegMIIPhyIdLow_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Device revision number */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Revision, 0, 4)
        /** @brief Device model number */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Model, 4, 6)
        /** @brief Bits 19:24 of organizationally unique identifier. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, OUILow, 10, 6)
#elif defined(__BIG_ENDIAN__)
        /** @brief Bits 19:24 of organizationally unique identifier. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, OUILow, 10, 6)
        /** @brief Device model number */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Model, 4, 6)
        /** @brief Device revision number */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Revision, 0, 4)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PhyIdLow"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIPhyIdLow_t()
    {
        /** @brief constructor for @ref MII_t.PhyIdLow. */
        r16.setName("PhyIdLow");
        bits.Revision.setBaseRegister(&r16);
        bits.Revision.setName("Revision");
        bits.Model.setBaseRegister(&r16);
        bits.Model.setName("Model");
        bits.Model.addEnum("5718", 0x20);
        bits.Model.addEnum("5719", 0x22);
        bits.Model.addEnum("5717B0", 0x22);
        bits.Model.addEnum("5720", 0x36);
        bits.Model.addEnum("5717C0", 0x36);

        bits.OUILow.setBaseRegister(&r16);
        bits.OUILow.setName("OUILow");
    }
    RegMIIPhyIdLow_t& operator=(const RegMIIPhyIdLow_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIPhyIdLow_t;

#define REG_MII_AUTONEGOTIATION_ADVERTISEMENT ((volatile BCM5719_MII_H_uint16_t*)0x4) /* Bits in this register indicate what capability bits are advertised to the link partner. */
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
#if defined(__LITTLE_ENDIAN__)
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
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPage, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_14_14, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteFault, 13, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_12_12, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AsymmetricPauseCapable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PauseCapable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_T4Capable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_TXFullDuplexCapable, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_TXHalfDuplexCapable, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BASE_TFullDuplexCapable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BASE_THalfDuplexCapable, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ProtocolSelect, 0, 5)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "AutonegotiationAdvertisement"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIAutonegotiationAdvertisement_t()
    {
        /** @brief constructor for @ref MII_t.AutonegotiationAdvertisement. */
        r16.setName("AutonegotiationAdvertisement");
        bits.ProtocolSelect.setBaseRegister(&r16);
        bits.ProtocolSelect.setName("ProtocolSelect");
        bits.ProtocolSelect.addEnum("IEEE 802.3", 0x1);

        bits._10BASE_THalfDuplexCapable.setBaseRegister(&r16);
        bits._10BASE_THalfDuplexCapable.setName("_10BASE_THalfDuplexCapable");
        bits._10BASE_TFullDuplexCapable.setBaseRegister(&r16);
        bits._10BASE_TFullDuplexCapable.setName("_10BASE_TFullDuplexCapable");
        bits._100BASE_TXHalfDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_TXHalfDuplexCapable.setName("_100BASE_TXHalfDuplexCapable");
        bits._100BASE_TXFullDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_TXFullDuplexCapable.setName("_100BASE_TXFullDuplexCapable");
        bits._100BASE_T4Capable.setBaseRegister(&r16);
        bits._100BASE_T4Capable.setName("_100BASE_T4Capable");
        bits.PauseCapable.setBaseRegister(&r16);
        bits.PauseCapable.setName("PauseCapable");
        bits.AsymmetricPauseCapable.setBaseRegister(&r16);
        bits.AsymmetricPauseCapable.setName("AsymmetricPauseCapable");
        bits.RemoteFault.setBaseRegister(&r16);
        bits.RemoteFault.setName("RemoteFault");
        bits.NextPage.setBaseRegister(&r16);
        bits.NextPage.setName("NextPage");
    }
    RegMIIAutonegotiationAdvertisement_t& operator=(const RegMIIAutonegotiationAdvertisement_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIAutonegotiationAdvertisement_t;

#define REG_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_BASE_PAGE ((volatile BCM5719_MII_H_uint16_t*)0x5) /* Bits in this register indicate the capabilities of the link partner. */
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
#if defined(__LITTLE_ENDIAN__)
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
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPage, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Acknowledge, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteFault, 13, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_12_12, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AsymmetricPauseCapable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PauseCapable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_T4Capable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_TXFullDuplexCapable, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100BASE_TXHalfDuplexCapable, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BASE_TFullDuplexCapable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BASE_THalfDuplexCapable, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ProtocolSelector, 0, 5)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "AutonegotiationLinkPartnerAbilityBasePage"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIAutonegotiationLinkPartnerAbilityBasePage_t()
    {
        /** @brief constructor for @ref MII_t.AutonegotiationLinkPartnerAbilityBasePage. */
        r16.setName("AutonegotiationLinkPartnerAbilityBasePage");
        bits.ProtocolSelector.setBaseRegister(&r16);
        bits.ProtocolSelector.setName("ProtocolSelector");
        bits._10BASE_THalfDuplexCapable.setBaseRegister(&r16);
        bits._10BASE_THalfDuplexCapable.setName("_10BASE_THalfDuplexCapable");
        bits._10BASE_TFullDuplexCapable.setBaseRegister(&r16);
        bits._10BASE_TFullDuplexCapable.setName("_10BASE_TFullDuplexCapable");
        bits._100BASE_TXHalfDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_TXHalfDuplexCapable.setName("_100BASE_TXHalfDuplexCapable");
        bits._100BASE_TXFullDuplexCapable.setBaseRegister(&r16);
        bits._100BASE_TXFullDuplexCapable.setName("_100BASE_TXFullDuplexCapable");
        bits._100BASE_T4Capable.setBaseRegister(&r16);
        bits._100BASE_T4Capable.setName("_100BASE_T4Capable");
        bits.PauseCapable.setBaseRegister(&r16);
        bits.PauseCapable.setName("PauseCapable");
        bits.AsymmetricPauseCapable.setBaseRegister(&r16);
        bits.AsymmetricPauseCapable.setName("AsymmetricPauseCapable");
        bits.RemoteFault.setBaseRegister(&r16);
        bits.RemoteFault.setName("RemoteFault");
        bits.Acknowledge.setBaseRegister(&r16);
        bits.Acknowledge.setName("Acknowledge");
        bits.NextPage.setBaseRegister(&r16);
        bits.NextPage.setName("NextPage");
    }
    RegMIIAutonegotiationLinkPartnerAbilityBasePage_t& operator=(const RegMIIAutonegotiationLinkPartnerAbilityBasePage_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIAutonegotiationLinkPartnerAbilityBasePage_t;

#define REG_MII_AUTONEGOTIATION_EXPANSION ((volatile BCM5719_MII_H_uint16_t*)0x6) /*  */
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
#if defined(__LITTLE_ENDIAN__)
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
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_15_7, 7, 9)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_15_7, 7, 9)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPageReceiveLocationCapable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPageReceiveLocation, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ParallelDetectionFault, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkPartnerNextPageCapable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPageCapable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PageReceived, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkPartnerAutonegotiationCapable, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "AutonegotiationExpansion"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIAutonegotiationExpansion_t()
    {
        /** @brief constructor for @ref MII_t.AutonegotiationExpansion. */
        r16.setName("AutonegotiationExpansion");
        bits.LinkPartnerAutonegotiationCapable.setBaseRegister(&r16);
        bits.LinkPartnerAutonegotiationCapable.setName("LinkPartnerAutonegotiationCapable");
        bits.PageReceived.setBaseRegister(&r16);
        bits.PageReceived.setName("PageReceived");
        bits.NextPageCapable.setBaseRegister(&r16);
        bits.NextPageCapable.setName("NextPageCapable");
        bits.LinkPartnerNextPageCapable.setBaseRegister(&r16);
        bits.LinkPartnerNextPageCapable.setName("LinkPartnerNextPageCapable");
        bits.ParallelDetectionFault.setBaseRegister(&r16);
        bits.ParallelDetectionFault.setName("ParallelDetectionFault");
        bits.NextPageReceiveLocation.setBaseRegister(&r16);
        bits.NextPageReceiveLocation.setName("NextPageReceiveLocation");
        bits.NextPageReceiveLocation.addEnum("Next pages stored in register 0x05", 0x0);
        bits.NextPageReceiveLocation.addEnum("Next pages stored in register 0x08", 0x1);

        bits.NextPageReceiveLocationCapable.setBaseRegister(&r16);
        bits.NextPageReceiveLocationCapable.setName("NextPageReceiveLocationCapable");
    }
    RegMIIAutonegotiationExpansion_t& operator=(const RegMIIAutonegotiationExpansion_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIAutonegotiationExpansion_t;

#define REG_MII_AUTONEGOTIATION_NEXT_PAGE_TRANSMIT ((volatile BCM5719_MII_H_uint16_t*)0x7) /*  */
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
#if defined(__LITTLE_ENDIAN__)
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
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPage, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_14_14, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MessagePage, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Acknowledge2, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Toggle, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CodeField, 0, 11)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "AutonegotiationNextPageTransmit"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIAutonegotiationNextPageTransmit_t()
    {
        /** @brief constructor for @ref MII_t.AutonegotiationNextPageTransmit. */
        r16.setName("AutonegotiationNextPageTransmit");
        bits.CodeField.setBaseRegister(&r16);
        bits.CodeField.setName("CodeField");
        bits.Toggle.setBaseRegister(&r16);
        bits.Toggle.setName("Toggle");
        bits.Acknowledge2.setBaseRegister(&r16);
        bits.Acknowledge2.setName("Acknowledge2");
        bits.MessagePage.setBaseRegister(&r16);
        bits.MessagePage.setName("MessagePage");
        bits.NextPage.setBaseRegister(&r16);
        bits.NextPage.setName("NextPage");
    }
    RegMIIAutonegotiationNextPageTransmit_t& operator=(const RegMIIAutonegotiationNextPageTransmit_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIAutonegotiationNextPageTransmit_t;

#define REG_MII_AUTONEGOTIATION_LINK_PARTNER_ABILITY_NEXT_PAGE ((volatile BCM5719_MII_H_uint16_t*)0x8) /*  */
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
#if defined(__LITTLE_ENDIAN__)
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
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NextPage, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Acknowledge3, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MessagePage, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Acknowledge2, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Toggle2, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CodeField, 0, 11)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "AutonegotiationLinkPartnerAbilityNextPage"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIAutonegotiationLinkPartnerAbilityNextPage_t()
    {
        /** @brief constructor for @ref MII_t.AutonegotiationLinkPartnerAbilityNextPage. */
        r16.setName("AutonegotiationLinkPartnerAbilityNextPage");
        bits.CodeField.setBaseRegister(&r16);
        bits.CodeField.setName("CodeField");
        bits.Toggle2.setBaseRegister(&r16);
        bits.Toggle2.setName("Toggle2");
        bits.Acknowledge2.setBaseRegister(&r16);
        bits.Acknowledge2.setName("Acknowledge2");
        bits.MessagePage.setBaseRegister(&r16);
        bits.MessagePage.setName("MessagePage");
        bits.Acknowledge3.setBaseRegister(&r16);
        bits.Acknowledge3.setName("Acknowledge3");
        bits.NextPage.setBaseRegister(&r16);
        bits.NextPage.setName("NextPage");
    }
    RegMIIAutonegotiationLinkPartnerAbilityNextPage_t& operator=(const RegMIIAutonegotiationLinkPartnerAbilityNextPage_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIAutonegotiationLinkPartnerAbilityNextPage_t;

#define REG_MII_1000BASE_T_CONTROL ((volatile BCM5719_MII_H_uint16_t*)0x9) /*  */
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
#if defined(__LITTLE_ENDIAN__)
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
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TestMode, 13, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MasterSlaveConfigEnable, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MasterSlaveConfigValue, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RepeaterDTE, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Advertise1000BASE_TFullDuplex, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Advertise1000BASE_THalfDuplex, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_7_0, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "1000baseTControl"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMII1000baseTControl_t()
    {
        /** @brief constructor for @ref MII_t.1000baseTControl. */
        r16.setName("1000baseTControl");
        bits.Advertise1000BASE_THalfDuplex.setBaseRegister(&r16);
        bits.Advertise1000BASE_THalfDuplex.setName("Advertise1000BASE_THalfDuplex");
        bits.Advertise1000BASE_TFullDuplex.setBaseRegister(&r16);
        bits.Advertise1000BASE_TFullDuplex.setName("Advertise1000BASE_TFullDuplex");
        bits.RepeaterDTE.setBaseRegister(&r16);
        bits.RepeaterDTE.setName("RepeaterDTE");
        bits.MasterSlaveConfigValue.setBaseRegister(&r16);
        bits.MasterSlaveConfigValue.setName("MasterSlaveConfigValue");
        bits.MasterSlaveConfigEnable.setBaseRegister(&r16);
        bits.MasterSlaveConfigEnable.setName("MasterSlaveConfigEnable");
        bits.TestMode.setBaseRegister(&r16);
        bits.TestMode.setName("TestMode");
    }
    RegMII1000baseTControl_t& operator=(const RegMII1000baseTControl_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMII1000baseTControl_t;

#define REG_MII_1000BASE_T_STATUS ((volatile BCM5719_MII_H_uint16_t*)0xa) /*  */
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
#if defined(__LITTLE_ENDIAN__)
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
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MasterSlaveConfigFault, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MasterSlaveConfigResolution, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LocalReceiverStatus, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteReceiverStatus, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkPartner1000BASE_TFullDuplexCapable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkPartner1000BASE_THalfDuplexCapable, 10, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_9_8, 8, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, IdleErrorCount, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "1000baseTStatus"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMII1000baseTStatus_t()
    {
        /** @brief constructor for @ref MII_t.1000baseTStatus. */
        r16.setName("1000baseTStatus");
        bits.IdleErrorCount.setBaseRegister(&r16);
        bits.IdleErrorCount.setName("IdleErrorCount");
        bits.LinkPartner1000BASE_THalfDuplexCapable.setBaseRegister(&r16);
        bits.LinkPartner1000BASE_THalfDuplexCapable.setName("LinkPartner1000BASE_THalfDuplexCapable");
        bits.LinkPartner1000BASE_TFullDuplexCapable.setBaseRegister(&r16);
        bits.LinkPartner1000BASE_TFullDuplexCapable.setName("LinkPartner1000BASE_TFullDuplexCapable");
        bits.RemoteReceiverStatus.setBaseRegister(&r16);
        bits.RemoteReceiverStatus.setName("RemoteReceiverStatus");
        bits.LocalReceiverStatus.setBaseRegister(&r16);
        bits.LocalReceiverStatus.setName("LocalReceiverStatus");
        bits.MasterSlaveConfigResolution.setBaseRegister(&r16);
        bits.MasterSlaveConfigResolution.setName("MasterSlaveConfigResolution");
        bits.MasterSlaveConfigFault.setBaseRegister(&r16);
        bits.MasterSlaveConfigFault.setName("MasterSlaveConfigFault");
    }
    RegMII1000baseTStatus_t& operator=(const RegMII1000baseTStatus_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMII1000baseTStatus_t;

#define REG_MII_BROADREACH_LRE_ACCESS ((volatile BCM5719_MII_H_uint16_t*)0xe) /* WTH is this. */
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
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LRERegisterAccessStatus, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LRERegisterOverrideValue, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnableLRERegisterAccessOverride, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_15_3, 3, 13)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_15_3, 3, 13)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnableLRERegisterAccessOverride, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LRERegisterOverrideValue, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LRERegisterAccessStatus, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BroadreachLreAccess"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIBroadreachLreAccess_t()
    {
        /** @brief constructor for @ref MII_t.BroadreachLreAccess. */
        r16.setName("BroadreachLreAccess");
        bits.LRERegisterAccessStatus.setBaseRegister(&r16);
        bits.LRERegisterAccessStatus.setName("LRERegisterAccessStatus");
        bits.LRERegisterOverrideValue.setBaseRegister(&r16);
        bits.LRERegisterOverrideValue.setName("LRERegisterOverrideValue");
        bits.EnableLRERegisterAccessOverride.setBaseRegister(&r16);
        bits.EnableLRERegisterAccessOverride.setName("EnableLRERegisterAccessOverride");
    }
    RegMIIBroadreachLreAccess_t& operator=(const RegMIIBroadreachLreAccess_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIBroadreachLreAccess_t;

#define REG_MII_IEEE_EXTENDED_STATUS ((volatile BCM5719_MII_H_uint16_t*)0xf) /*  */
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
#if defined(__LITTLE_ENDIAN__)
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
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _1000BASE_XHalfDuplexCapable, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_14_14, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _1000BASE_TFullDuplexCapable, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _1000BASE_THalfDuplexCapable, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_11_0, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "IeeeExtendedStatus"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIIeeeExtendedStatus_t()
    {
        /** @brief constructor for @ref MII_t.IeeeExtendedStatus. */
        r16.setName("IeeeExtendedStatus");
        bits._1000BASE_THalfDuplexCapable.setBaseRegister(&r16);
        bits._1000BASE_THalfDuplexCapable.setName("_1000BASE_THalfDuplexCapable");
        bits._1000BASE_TFullDuplexCapable.setBaseRegister(&r16);
        bits._1000BASE_TFullDuplexCapable.setName("_1000BASE_TFullDuplexCapable");
        bits._1000BASE_XHalfDuplexCapable.setBaseRegister(&r16);
        bits._1000BASE_XHalfDuplexCapable.setName("_1000BASE_XHalfDuplexCapable");
    }
    RegMIIIeeeExtendedStatus_t& operator=(const RegMIIIeeeExtendedStatus_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIIeeeExtendedStatus_t;

#define REG_MII_PHY_EXTENDED_CONTROL ((volatile BCM5719_MII_H_uint16_t*)0x10) /*  */
#define     MII_PHY_EXTENDED_CONTROL_GMII_DIV_RGMII_FIFO_ELASTICITY_LSB_SHIFT 0u
#define     MII_PHY_EXTENDED_CONTROL_GMII_DIV_RGMII_FIFO_ELASTICITY_LSB_MASK  0x1u
#define GET_MII_PHY_EXTENDED_CONTROL_GMII_DIV_RGMII_FIFO_ELASTICITY_LSB(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_MII_PHY_EXTENDED_CONTROL_GMII_DIV_RGMII_FIFO_ELASTICITY_LSB(__val__)  (((__val__) << 0u) & 0x1u)
#define     MII_PHY_EXTENDED_CONTROL_UNIDIRECTIONAL_ENABLE_SHIFT 1u
#define     MII_PHY_EXTENDED_CONTROL_UNIDIRECTIONAL_ENABLE_MASK  0x2u
#define GET_MII_PHY_EXTENDED_CONTROL_UNIDIRECTIONAL_ENABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_MII_PHY_EXTENDED_CONTROL_UNIDIRECTIONAL_ENABLE(__val__)  (((__val__) << 1u) & 0x2u)
#define     MII_PHY_EXTENDED_CONTROL_BLOCK_TXEN_MODE_SHIFT 2u
#define     MII_PHY_EXTENDED_CONTROL_BLOCK_TXEN_MODE_MASK  0x4u
#define GET_MII_PHY_EXTENDED_CONTROL_BLOCK_TXEN_MODE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_MII_PHY_EXTENDED_CONTROL_BLOCK_TXEN_MODE(__val__)  (((__val__) << 2u) & 0x4u)
#define     MII_PHY_EXTENDED_CONTROL_FORCE_LEDS_OFF_SHIFT 3u
#define     MII_PHY_EXTENDED_CONTROL_FORCE_LEDS_OFF_MASK  0x8u
#define GET_MII_PHY_EXTENDED_CONTROL_FORCE_LEDS_OFF(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_MII_PHY_EXTENDED_CONTROL_FORCE_LEDS_OFF(__val__)  (((__val__) << 3u) & 0x8u)
#define     MII_PHY_EXTENDED_CONTROL_FORCE_LEDS_ON_SHIFT 4u
#define     MII_PHY_EXTENDED_CONTROL_FORCE_LEDS_ON_MASK  0x10u
#define GET_MII_PHY_EXTENDED_CONTROL_FORCE_LEDS_ON(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_PHY_EXTENDED_CONTROL_FORCE_LEDS_ON(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_PHY_EXTENDED_CONTROL_ENABLE_LED_TRAFFIC_MODE_SHIFT 5u
#define     MII_PHY_EXTENDED_CONTROL_ENABLE_LED_TRAFFIC_MODE_MASK  0x20u
#define GET_MII_PHY_EXTENDED_CONTROL_ENABLE_LED_TRAFFIC_MODE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_PHY_EXTENDED_CONTROL_ENABLE_LED_TRAFFIC_MODE(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_PHY_EXTENDED_CONTROL_RESET_SCRAMBLER_SHIFT 6u
#define     MII_PHY_EXTENDED_CONTROL_RESET_SCRAMBLER_MASK  0x40u
#define GET_MII_PHY_EXTENDED_CONTROL_RESET_SCRAMBLER(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_PHY_EXTENDED_CONTROL_RESET_SCRAMBLER(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_PHY_EXTENDED_CONTROL_BYPASS_ALIGNMENT_SHIFT 7u
#define     MII_PHY_EXTENDED_CONTROL_BYPASS_ALIGNMENT_MASK  0x80u
#define GET_MII_PHY_EXTENDED_CONTROL_BYPASS_ALIGNMENT(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_PHY_EXTENDED_CONTROL_BYPASS_ALIGNMENT(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_PHY_EXTENDED_CONTROL_BYPASS_NRZI_DIV_MLT3_SHIFT 8u
#define     MII_PHY_EXTENDED_CONTROL_BYPASS_NRZI_DIV_MLT3_MASK  0x100u
#define GET_MII_PHY_EXTENDED_CONTROL_BYPASS_NRZI_DIV_MLT3(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_PHY_EXTENDED_CONTROL_BYPASS_NRZI_DIV_MLT3(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_PHY_EXTENDED_CONTROL_BYPASS_SCRAMBLER_SHIFT 9u
#define     MII_PHY_EXTENDED_CONTROL_BYPASS_SCRAMBLER_MASK  0x200u
#define GET_MII_PHY_EXTENDED_CONTROL_BYPASS_SCRAMBLER(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_PHY_EXTENDED_CONTROL_BYPASS_SCRAMBLER(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_PHY_EXTENDED_CONTROL_BYPASS_ENCODER_SHIFT 10u
#define     MII_PHY_EXTENDED_CONTROL_BYPASS_ENCODER_MASK  0x400u
#define GET_MII_PHY_EXTENDED_CONTROL_BYPASS_ENCODER(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_PHY_EXTENDED_CONTROL_BYPASS_ENCODER(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_PHY_EXTENDED_CONTROL_FORCE_INTERRUPT_SHIFT 11u
#define     MII_PHY_EXTENDED_CONTROL_FORCE_INTERRUPT_MASK  0x800u
#define GET_MII_PHY_EXTENDED_CONTROL_FORCE_INTERRUPT(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_PHY_EXTENDED_CONTROL_FORCE_INTERRUPT(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_PHY_EXTENDED_CONTROL_INTERRUPT_DISABLE_SHIFT 12u
#define     MII_PHY_EXTENDED_CONTROL_INTERRUPT_DISABLE_MASK  0x1000u
#define GET_MII_PHY_EXTENDED_CONTROL_INTERRUPT_DISABLE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_PHY_EXTENDED_CONTROL_INTERRUPT_DISABLE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_PHY_EXTENDED_CONTROL_TRANSMIT_DISABLE_SHIFT 13u
#define     MII_PHY_EXTENDED_CONTROL_TRANSMIT_DISABLE_MASK  0x2000u
#define GET_MII_PHY_EXTENDED_CONTROL_TRANSMIT_DISABLE(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_PHY_EXTENDED_CONTROL_TRANSMIT_DISABLE(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_PHY_EXTENDED_CONTROL_DISABLE_AUTOMATIC_MDI_CROSSOVER_SHIFT 14u
#define     MII_PHY_EXTENDED_CONTROL_DISABLE_AUTOMATIC_MDI_CROSSOVER_MASK  0x4000u
#define GET_MII_PHY_EXTENDED_CONTROL_DISABLE_AUTOMATIC_MDI_CROSSOVER(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_PHY_EXTENDED_CONTROL_DISABLE_AUTOMATIC_MDI_CROSSOVER(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_PHY_EXTENDED_CONTROL_MAC_DIV_PHY_INTERFACE_MODE_SHIFT 15u
#define     MII_PHY_EXTENDED_CONTROL_MAC_DIV_PHY_INTERFACE_MODE_MASK  0x8000u
#define GET_MII_PHY_EXTENDED_CONTROL_MAC_DIV_PHY_INTERFACE_MODE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_PHY_EXTENDED_CONTROL_MAC_DIV_PHY_INTERFACE_MODE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.PhyExtendedControl. */
typedef register_container RegMIIPhyExtendedControl_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, GMII_DIV_RGMIIFIFOElasticityLSB, 0, 1)
        /** @brief When set, able to transmit packets when no link */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, UnidirectionalEnable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BlockTXENMode, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceLEDsOff, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceLEDsOn, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnableLEDTrafficMode, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ResetScrambler, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BypassAlignment, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BypassNRZI_DIV_MLT3, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BypassScrambler, 9, 1)
        /** @brief bypass 4B5B encoder and decoder */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BypassEncoder, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceInterrupt, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, InterruptDisable, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TransmitDisable, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisableAutomaticMDICrossover, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MAC_DIV_PHYInterfaceMode, 15, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MAC_DIV_PHYInterfaceMode, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisableAutomaticMDICrossover, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TransmitDisable, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, InterruptDisable, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceInterrupt, 11, 1)
        /** @brief bypass 4B5B encoder and decoder */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BypassEncoder, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BypassScrambler, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BypassNRZI_DIV_MLT3, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BypassAlignment, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ResetScrambler, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnableLEDTrafficMode, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceLEDsOn, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceLEDsOff, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BlockTXENMode, 2, 1)
        /** @brief When set, able to transmit packets when no link */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, UnidirectionalEnable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, GMII_DIV_RGMIIFIFOElasticityLSB, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PhyExtendedControl"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIPhyExtendedControl_t()
    {
        /** @brief constructor for @ref MII_t.PhyExtendedControl. */
        r16.setName("PhyExtendedControl");
        bits.GMII_DIV_RGMIIFIFOElasticityLSB.setBaseRegister(&r16);
        bits.GMII_DIV_RGMIIFIFOElasticityLSB.setName("GMII_DIV_RGMIIFIFOElasticityLSB");
        bits.UnidirectionalEnable.setBaseRegister(&r16);
        bits.UnidirectionalEnable.setName("UnidirectionalEnable");
        bits.BlockTXENMode.setBaseRegister(&r16);
        bits.BlockTXENMode.setName("BlockTXENMode");
        bits.ForceLEDsOff.setBaseRegister(&r16);
        bits.ForceLEDsOff.setName("ForceLEDsOff");
        bits.ForceLEDsOn.setBaseRegister(&r16);
        bits.ForceLEDsOn.setName("ForceLEDsOn");
        bits.EnableLEDTrafficMode.setBaseRegister(&r16);
        bits.EnableLEDTrafficMode.setName("EnableLEDTrafficMode");
        bits.ResetScrambler.setBaseRegister(&r16);
        bits.ResetScrambler.setName("ResetScrambler");
        bits.BypassAlignment.setBaseRegister(&r16);
        bits.BypassAlignment.setName("BypassAlignment");
        bits.BypassNRZI_DIV_MLT3.setBaseRegister(&r16);
        bits.BypassNRZI_DIV_MLT3.setName("BypassNRZI_DIV_MLT3");
        bits.BypassScrambler.setBaseRegister(&r16);
        bits.BypassScrambler.setName("BypassScrambler");
        bits.BypassEncoder.setBaseRegister(&r16);
        bits.BypassEncoder.setName("BypassEncoder");
        bits.ForceInterrupt.setBaseRegister(&r16);
        bits.ForceInterrupt.setName("ForceInterrupt");
        bits.InterruptDisable.setBaseRegister(&r16);
        bits.InterruptDisable.setName("InterruptDisable");
        bits.TransmitDisable.setBaseRegister(&r16);
        bits.TransmitDisable.setName("TransmitDisable");
        bits.DisableAutomaticMDICrossover.setBaseRegister(&r16);
        bits.DisableAutomaticMDICrossover.setName("DisableAutomaticMDICrossover");
        bits.MAC_DIV_PHYInterfaceMode.setBaseRegister(&r16);
        bits.MAC_DIV_PHYInterfaceMode.setName("MAC_DIV_PHYInterfaceMode");
    }
    RegMIIPhyExtendedControl_t& operator=(const RegMIIPhyExtendedControl_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIPhyExtendedControl_t;

#define REG_MII_PHY_EXTENDED_STATUS ((volatile BCM5719_MII_H_uint16_t*)0x11) /*  */
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
#if defined(__LITTLE_ENDIAN__)
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
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutonegotiationBasePageSelectorFieldMismatch, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WirespeedDowngrade, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MDICrossoverState, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, InterruptStatus, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteReceiverStatus, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LocalReceiverStatus, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Locked, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkStatus, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CRCErrorDetected, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CarrierExtensionErrorDetected, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BadSSDDetected, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BadESDDetected, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ReceiveErrorDetected, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TransmitErrorDetected, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LockErrorDetected, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MLT3CodeErrorDetected, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PhyExtendedStatus"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIPhyExtendedStatus_t()
    {
        /** @brief constructor for @ref MII_t.PhyExtendedStatus. */
        r16.setName("PhyExtendedStatus");
        bits.MLT3CodeErrorDetected.setBaseRegister(&r16);
        bits.MLT3CodeErrorDetected.setName("MLT3CodeErrorDetected");
        bits.LockErrorDetected.setBaseRegister(&r16);
        bits.LockErrorDetected.setName("LockErrorDetected");
        bits.TransmitErrorDetected.setBaseRegister(&r16);
        bits.TransmitErrorDetected.setName("TransmitErrorDetected");
        bits.ReceiveErrorDetected.setBaseRegister(&r16);
        bits.ReceiveErrorDetected.setName("ReceiveErrorDetected");
        bits.BadESDDetected.setBaseRegister(&r16);
        bits.BadESDDetected.setName("BadESDDetected");
        bits.BadSSDDetected.setBaseRegister(&r16);
        bits.BadSSDDetected.setName("BadSSDDetected");
        bits.CarrierExtensionErrorDetected.setBaseRegister(&r16);
        bits.CarrierExtensionErrorDetected.setName("CarrierExtensionErrorDetected");
        bits.CRCErrorDetected.setBaseRegister(&r16);
        bits.CRCErrorDetected.setName("CRCErrorDetected");
        bits.LinkStatus.setBaseRegister(&r16);
        bits.LinkStatus.setName("LinkStatus");
        bits.Locked.setBaseRegister(&r16);
        bits.Locked.setName("Locked");
        bits.LocalReceiverStatus.setBaseRegister(&r16);
        bits.LocalReceiverStatus.setName("LocalReceiverStatus");
        bits.RemoteReceiverStatus.setBaseRegister(&r16);
        bits.RemoteReceiverStatus.setName("RemoteReceiverStatus");
        bits.InterruptStatus.setBaseRegister(&r16);
        bits.InterruptStatus.setName("InterruptStatus");
        bits.MDICrossoverState.setBaseRegister(&r16);
        bits.MDICrossoverState.setName("MDICrossoverState");
        bits.WirespeedDowngrade.setBaseRegister(&r16);
        bits.WirespeedDowngrade.setName("WirespeedDowngrade");
        bits.AutonegotiationBasePageSelectorFieldMismatch.setBaseRegister(&r16);
        bits.AutonegotiationBasePageSelectorFieldMismatch.setName("AutonegotiationBasePageSelectorFieldMismatch");
    }
    RegMIIPhyExtendedStatus_t& operator=(const RegMIIPhyExtendedStatus_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIPhyExtendedStatus_t;

#define REG_MII_RECEIVE_ERROR_COUNTER ((volatile BCM5719_MII_H_uint16_t*)0x12) /*  */
#define     MII_RECEIVE_ERROR_COUNTER_RECEIVE_ERROR_COUNTER_SHIFT 0u
#define     MII_RECEIVE_ERROR_COUNTER_RECEIVE_ERROR_COUNTER_MASK  0xffffu
#define GET_MII_RECEIVE_ERROR_COUNTER_RECEIVE_ERROR_COUNTER(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_MII_RECEIVE_ERROR_COUNTER_RECEIVE_ERROR_COUNTER(__val__)  (((__val__) << 0u) & 0xffffu)

/** @brief Register definition for @ref MII_t.ReceiveErrorCounter. */
typedef register_container RegMIIReceiveErrorCounter_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ReceiveErrorCounter, 0, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ReceiveErrorCounter, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ReceiveErrorCounter"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIReceiveErrorCounter_t()
    {
        /** @brief constructor for @ref MII_t.ReceiveErrorCounter. */
        r16.setName("ReceiveErrorCounter");
        bits.ReceiveErrorCounter.setBaseRegister(&r16);
        bits.ReceiveErrorCounter.setName("ReceiveErrorCounter");
    }
    RegMIIReceiveErrorCounter_t& operator=(const RegMIIReceiveErrorCounter_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIReceiveErrorCounter_t;

#define REG_MII_FALSE_CARRIER_SENSE_COUNTER ((volatile BCM5719_MII_H_uint16_t*)0x13) /*  */
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
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, FalseCarrierSenseCounter, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SERDESBERCounter, 8, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SERDESBERCounter, 8, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, FalseCarrierSenseCounter, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "FalseCarrierSenseCounter"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIFalseCarrierSenseCounter_t()
    {
        /** @brief constructor for @ref MII_t.FalseCarrierSenseCounter. */
        r16.setName("FalseCarrierSenseCounter");
        bits.FalseCarrierSenseCounter.setBaseRegister(&r16);
        bits.FalseCarrierSenseCounter.setName("FalseCarrierSenseCounter");
        bits.SERDESBERCounter.setBaseRegister(&r16);
        bits.SERDESBERCounter.setName("SERDESBERCounter");
    }
    RegMIIFalseCarrierSenseCounter_t& operator=(const RegMIIFalseCarrierSenseCounter_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIFalseCarrierSenseCounter_t;

#define REG_MII_LOCAL_REMOTE_RECEIVER_NOT_OK_COUNTER ((volatile BCM5719_MII_H_uint16_t*)0x14) /*  */
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
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteReceiverNotOKCounter, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LocalReceiverNotOKCounter, 8, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LocalReceiverNotOKCounter, 8, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteReceiverNotOKCounter, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LocalRemoteReceiverNotOkCounter"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIILocalRemoteReceiverNotOkCounter_t()
    {
        /** @brief constructor for @ref MII_t.LocalRemoteReceiverNotOkCounter. */
        r16.setName("LocalRemoteReceiverNotOkCounter");
        bits.RemoteReceiverNotOKCounter.setBaseRegister(&r16);
        bits.RemoteReceiverNotOKCounter.setName("RemoteReceiverNotOKCounter");
        bits.LocalReceiverNotOKCounter.setBaseRegister(&r16);
        bits.LocalReceiverNotOKCounter.setName("LocalReceiverNotOKCounter");
    }
    RegMIILocalRemoteReceiverNotOkCounter_t& operator=(const RegMIILocalRemoteReceiverNotOkCounter_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIILocalRemoteReceiverNotOkCounter_t;

#define REG_MII_DSP_COEFFICIENT_READ_WRITE_PORT ((volatile BCM5719_MII_H_uint16_t*)0x15) /*  */
/** @brief Register definition for @ref MII_t.DspCoefficientReadWritePort. */
typedef register_container RegMIIDspCoefficientReadWritePort_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "DspCoefficientReadWritePort"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIDspCoefficientReadWritePort_t()
    {
        /** @brief constructor for @ref MII_t.DspCoefficientReadWritePort. */
        r16.setName("DspCoefficientReadWritePort");
    }
    RegMIIDspCoefficientReadWritePort_t& operator=(const RegMIIDspCoefficientReadWritePort_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIDspCoefficientReadWritePort_t;

#define REG_MII_DSP_CONTROL ((volatile BCM5719_MII_H_uint16_t*)0x16) /*  */
/** @brief Register definition for @ref MII_t.DspControl. */
typedef register_container RegMIIDspControl_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "DspControl"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIDspControl_t()
    {
        /** @brief constructor for @ref MII_t.DspControl. */
        r16.setName("DspControl");
    }
    RegMIIDspControl_t& operator=(const RegMIIDspControl_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIDspControl_t;

#define REG_MII_DSP_COEFFICIENT_ADDRESS ((volatile BCM5719_MII_H_uint16_t*)0x17) /*  */
/** @brief Register definition for @ref MII_t.DspCoefficientAddress. */
typedef register_container RegMIIDspCoefficientAddress_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "DspCoefficientAddress"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIDspCoefficientAddress_t()
    {
        /** @brief constructor for @ref MII_t.DspCoefficientAddress. */
        r16.setName("DspCoefficientAddress");
    }
    RegMIIDspCoefficientAddress_t& operator=(const RegMIIDspCoefficientAddress_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIDspCoefficientAddress_t;

#define REG_MII_AUXILIARY_CONTROL ((volatile BCM5719_MII_H_uint16_t*)0x18) /* Note: Shadow Register Selector: 0 */
#define     MII_AUXILIARY_CONTROL_SHADOW_REGISTER_SELECTOR_SHIFT 0u
#define     MII_AUXILIARY_CONTROL_SHADOW_REGISTER_SELECTOR_MASK  0x7u
#define GET_MII_AUXILIARY_CONTROL_SHADOW_REGISTER_SELECTOR(__reg__)  (((__reg__) & 0x7) >> 0u)
#define SET_MII_AUXILIARY_CONTROL_SHADOW_REGISTER_SELECTOR(__val__)  (((__val__) << 0u) & 0x7u)
#define     MII_AUXILIARY_CONTROL_DIAGNOSTIC_MODE_SHIFT 3u
#define     MII_AUXILIARY_CONTROL_DIAGNOSTIC_MODE_MASK  0x8u
#define GET_MII_AUXILIARY_CONTROL_DIAGNOSTIC_MODE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_MII_AUXILIARY_CONTROL_DIAGNOSTIC_MODE(__val__)  (((__val__) << 3u) & 0x8u)
#define     MII_AUXILIARY_CONTROL_DISABLE_INVERSE_PRF_SHIFT 6u
#define     MII_AUXILIARY_CONTROL_DISABLE_INVERSE_PRF_MASK  0x40u
#define GET_MII_AUXILIARY_CONTROL_DISABLE_INVERSE_PRF(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_AUXILIARY_CONTROL_DISABLE_INVERSE_PRF(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_AUXILIARY_CONTROL_DISABLE_PARTIAL_RESPONSE_FILTER_SHIFT 7u
#define     MII_AUXILIARY_CONTROL_DISABLE_PARTIAL_RESPONSE_FILTER_MASK  0x80u
#define GET_MII_AUXILIARY_CONTROL_DISABLE_PARTIAL_RESPONSE_FILTER(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_AUXILIARY_CONTROL_DISABLE_PARTIAL_RESPONSE_FILTER(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_AUXILIARY_CONTROL_RECEIVE_SLICING_SHIFT 8u
#define     MII_AUXILIARY_CONTROL_RECEIVE_SLICING_MASK  0x300u
#define GET_MII_AUXILIARY_CONTROL_RECEIVE_SLICING(__reg__)  (((__reg__) & 0x300) >> 8u)
#define SET_MII_AUXILIARY_CONTROL_RECEIVE_SLICING(__val__)  (((__val__) << 8u) & 0x300u)
#define     MII_AUXILIARY_CONTROL_TRANSMIT_6DB_CODING_SHIFT 10u
#define     MII_AUXILIARY_CONTROL_TRANSMIT_6DB_CODING_MASK  0x400u
#define GET_MII_AUXILIARY_CONTROL_TRANSMIT_6DB_CODING(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_AUXILIARY_CONTROL_TRANSMIT_6DB_CODING(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_AUXILIARY_CONTROL_ENABLE_SM_DSP_CLOCK_SHIFT 11u
#define     MII_AUXILIARY_CONTROL_ENABLE_SM_DSP_CLOCK_MASK  0x800u
#define GET_MII_AUXILIARY_CONTROL_ENABLE_SM_DSP_CLOCK(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_AUXILIARY_CONTROL_ENABLE_SM_DSP_CLOCK(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_AUXILIARY_CONTROL_EDGERATE_CONTROL_SHIFT 12u
#define     MII_AUXILIARY_CONTROL_EDGERATE_CONTROL_MASK  0x3000u
#define GET_MII_AUXILIARY_CONTROL_EDGERATE_CONTROL(__reg__)  (((__reg__) & 0x3000) >> 12u)
#define SET_MII_AUXILIARY_CONTROL_EDGERATE_CONTROL(__val__)  (((__val__) << 12u) & 0x3000u)
#define     MII_AUXILIARY_CONTROL_EXTENDED_PACKET_LENGTH_SHIFT 14u
#define     MII_AUXILIARY_CONTROL_EXTENDED_PACKET_LENGTH_MASK  0x4000u
#define GET_MII_AUXILIARY_CONTROL_EXTENDED_PACKET_LENGTH(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_AUXILIARY_CONTROL_EXTENDED_PACKET_LENGTH(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_AUXILIARY_CONTROL_EXTERNAL_LOOPBACK_SHIFT 15u
#define     MII_AUXILIARY_CONTROL_EXTERNAL_LOOPBACK_MASK  0x8000u
#define GET_MII_AUXILIARY_CONTROL_EXTERNAL_LOOPBACK(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_AUXILIARY_CONTROL_EXTERNAL_LOOPBACK(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.AuxiliaryControl. */
typedef register_container RegMIIAuxiliaryControl_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Writes to the selected shadow register are done on a single cycle (no setup required). Reads are selected by first writing to register 18h, shadow 7, bits 14:12. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 0, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DiagnosticMode, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_5_4, 4, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisableInversePRF, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisablePartialResponseFilter, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ReceiveSlicing, 8, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Transmit6dBCoding, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnableSM_DSPClock, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EdgerateControl, 12, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ExtendedPacketLength, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ExternalLoopback, 15, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ExternalLoopback, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ExtendedPacketLength, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EdgerateControl, 12, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnableSM_DSPClock, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Transmit6dBCoding, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ReceiveSlicing, 8, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisablePartialResponseFilter, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisableInversePRF, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_5_4, 4, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DiagnosticMode, 3, 1)
        /** @brief Writes to the selected shadow register are done on a single cycle (no setup required). Reads are selected by first writing to register 18h, shadow 7, bits 14:12. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 0, 3)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "AuxiliaryControl"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIAuxiliaryControl_t()
    {
        /** @brief constructor for @ref MII_t.AuxiliaryControl. */
        r16.setName("AuxiliaryControl");
        bits.ShadowRegisterSelector.setBaseRegister(&r16);
        bits.ShadowRegisterSelector.setName("ShadowRegisterSelector");
        bits.DiagnosticMode.setBaseRegister(&r16);
        bits.DiagnosticMode.setName("DiagnosticMode");
        bits.DisableInversePRF.setBaseRegister(&r16);
        bits.DisableInversePRF.setName("DisableInversePRF");
        bits.DisablePartialResponseFilter.setBaseRegister(&r16);
        bits.DisablePartialResponseFilter.setName("DisablePartialResponseFilter");
        bits.ReceiveSlicing.setBaseRegister(&r16);
        bits.ReceiveSlicing.setName("ReceiveSlicing");
        bits.Transmit6dBCoding.setBaseRegister(&r16);
        bits.Transmit6dBCoding.setName("Transmit6dBCoding");
        bits.EnableSM_DSPClock.setBaseRegister(&r16);
        bits.EnableSM_DSPClock.setName("EnableSM_DSPClock");
        bits.EdgerateControl.setBaseRegister(&r16);
        bits.EdgerateControl.setName("EdgerateControl");
        bits.ExtendedPacketLength.setBaseRegister(&r16);
        bits.ExtendedPacketLength.setName("ExtendedPacketLength");
        bits.ExternalLoopback.setBaseRegister(&r16);
        bits.ExternalLoopback.setName("ExternalLoopback");
    }
    RegMIIAuxiliaryControl_t& operator=(const RegMIIAuxiliaryControl_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIAuxiliaryControl_t;

#define REG_MII_AUXILIARY_STATUS_SUMMARY ((volatile BCM5719_MII_H_uint16_t*)0x19) /*  */
#define     MII_AUXILIARY_STATUS_SUMMARY_PAUSE_RESOLUTION___TRANSMIT_DIRECTION_SHIFT 0u
#define     MII_AUXILIARY_STATUS_SUMMARY_PAUSE_RESOLUTION___TRANSMIT_DIRECTION_MASK  0x1u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_PAUSE_RESOLUTION___TRANSMIT_DIRECTION(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_PAUSE_RESOLUTION___TRANSMIT_DIRECTION(__val__)  (((__val__) << 0u) & 0x1u)
#define     MII_AUXILIARY_STATUS_SUMMARY_PAUSE_RESOLUTION___RECEIVE_DIRECTION_SHIFT 1u
#define     MII_AUXILIARY_STATUS_SUMMARY_PAUSE_RESOLUTION___RECEIVE_DIRECTION_MASK  0x2u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_PAUSE_RESOLUTION___RECEIVE_DIRECTION(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_PAUSE_RESOLUTION___RECEIVE_DIRECTION(__val__)  (((__val__) << 1u) & 0x2u)
#define     MII_AUXILIARY_STATUS_SUMMARY_LINK_STATUS_SHIFT 2u
#define     MII_AUXILIARY_STATUS_SUMMARY_LINK_STATUS_MASK  0x4u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_LINK_STATUS(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_LINK_STATUS(__val__)  (((__val__) << 2u) & 0x4u)
#define     MII_AUXILIARY_STATUS_SUMMARY_LINK_PARTNER_NEXT_PAGE_CAPABLE_SHIFT 3u
#define     MII_AUXILIARY_STATUS_SUMMARY_LINK_PARTNER_NEXT_PAGE_CAPABLE_MASK  0x8u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_LINK_PARTNER_NEXT_PAGE_CAPABLE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_LINK_PARTNER_NEXT_PAGE_CAPABLE(__val__)  (((__val__) << 3u) & 0x8u)
#define     MII_AUXILIARY_STATUS_SUMMARY_LINK_PARTNER_AUTONEGOTIATION_CAPABLE_SHIFT 4u
#define     MII_AUXILIARY_STATUS_SUMMARY_LINK_PARTNER_AUTONEGOTIATION_CAPABLE_MASK  0x10u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_LINK_PARTNER_AUTONEGOTIATION_CAPABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_LINK_PARTNER_AUTONEGOTIATION_CAPABLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_AUXILIARY_STATUS_SUMMARY_PAGE_RECEIVED_SHIFT 5u
#define     MII_AUXILIARY_STATUS_SUMMARY_PAGE_RECEIVED_MASK  0x20u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_PAGE_RECEIVED(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_PAGE_RECEIVED(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_AUXILIARY_STATUS_SUMMARY_REMOTE_FAULT_SHIFT 6u
#define     MII_AUXILIARY_STATUS_SUMMARY_REMOTE_FAULT_MASK  0x40u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_REMOTE_FAULT(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_REMOTE_FAULT(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_AUXILIARY_STATUS_SUMMARY_PARALLEL_DETECTION_FAULT_SHIFT 7u
#define     MII_AUXILIARY_STATUS_SUMMARY_PARALLEL_DETECTION_FAULT_MASK  0x80u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_PARALLEL_DETECTION_FAULT(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_PARALLEL_DETECTION_FAULT(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_SHIFT 8u
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_MASK  0x700u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD(__reg__)  (((__reg__) & 0x700) >> 8u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD(__val__)  (((__val__) << 8u) & 0x700u)
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_NO_HCD 0x0u
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_10BASE_T_HALF_DUPLEX 0x1u
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_10BASE_T_FULL_DUPLEX 0x2u
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_100BASE_TX_HALF_DUPLEX 0x3u
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_100BASE_T4 0x4u
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_100BASE_TX_FULL_DUPLEX 0x5u
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_1000BASE_T_HALF_DUPLEX 0x6u
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_HCD_1000BASE_T_FULL_DUPLEX 0x7u

#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_NEXT_PAGE_WAIT_SHIFT 11u
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_NEXT_PAGE_WAIT_MASK  0x800u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_NEXT_PAGE_WAIT(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_NEXT_PAGE_WAIT(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_ABILITY_DETECT_SHIFT 12u
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_ABILITY_DETECT_MASK  0x1000u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_ABILITY_DETECT(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_ABILITY_DETECT(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_ACK_DETECT_SHIFT 13u
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_ACK_DETECT_MASK  0x2000u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_ACK_DETECT(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_ACK_DETECT(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_COMPLETE_ACK_SHIFT 14u
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_COMPLETE_ACK_MASK  0x4000u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_COMPLETE_ACK(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_COMPLETE_ACK(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_COMPLETE_SHIFT 15u
#define     MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_COMPLETE_MASK  0x8000u
#define GET_MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_COMPLETE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_AUXILIARY_STATUS_SUMMARY_AUTO_NEGOTIATION_COMPLETE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.AuxiliaryStatusSummary. */
typedef register_container RegMIIAuxiliaryStatusSummary_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
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
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationHCD, 8, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationNextPageWait, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationAbilityDetect, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationACKDetect, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationCompleteACK, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationComplete, 15, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationComplete, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationCompleteACK, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationACKDetect, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationAbilityDetect, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationNextPageWait, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutoNegotiationHCD, 8, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ParallelDetectionFault, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteFault, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PageReceived, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkPartnerAutonegotiationCapable, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkPartnerNextPageCapable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkStatus, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PauseResolution_ReceiveDirection, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PauseResolution_TransmitDirection, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "AuxiliaryStatusSummary"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIAuxiliaryStatusSummary_t()
    {
        /** @brief constructor for @ref MII_t.AuxiliaryStatusSummary. */
        r16.setName("AuxiliaryStatusSummary");
        bits.PauseResolution_TransmitDirection.setBaseRegister(&r16);
        bits.PauseResolution_TransmitDirection.setName("PauseResolution_TransmitDirection");
        bits.PauseResolution_ReceiveDirection.setBaseRegister(&r16);
        bits.PauseResolution_ReceiveDirection.setName("PauseResolution_ReceiveDirection");
        bits.LinkStatus.setBaseRegister(&r16);
        bits.LinkStatus.setName("LinkStatus");
        bits.LinkPartnerNextPageCapable.setBaseRegister(&r16);
        bits.LinkPartnerNextPageCapable.setName("LinkPartnerNextPageCapable");
        bits.LinkPartnerAutonegotiationCapable.setBaseRegister(&r16);
        bits.LinkPartnerAutonegotiationCapable.setName("LinkPartnerAutonegotiationCapable");
        bits.PageReceived.setBaseRegister(&r16);
        bits.PageReceived.setName("PageReceived");
        bits.RemoteFault.setBaseRegister(&r16);
        bits.RemoteFault.setName("RemoteFault");
        bits.ParallelDetectionFault.setBaseRegister(&r16);
        bits.ParallelDetectionFault.setName("ParallelDetectionFault");
        bits.AutoNegotiationHCD.setBaseRegister(&r16);
        bits.AutoNegotiationHCD.setName("AutoNegotiationHCD");
        bits.AutoNegotiationHCD.addEnum("NO HCD", 0x0);
        bits.AutoNegotiationHCD.addEnum("10BASE-T Half Duplex", 0x1);
        bits.AutoNegotiationHCD.addEnum("10BASE-T Full Duplex", 0x2);
        bits.AutoNegotiationHCD.addEnum("100BASE-TX Half Duplex", 0x3);
        bits.AutoNegotiationHCD.addEnum("100BASE-T4", 0x4);
        bits.AutoNegotiationHCD.addEnum("100BASE-TX Full Duplex", 0x5);
        bits.AutoNegotiationHCD.addEnum("1000BASE-T Half Duplex", 0x6);
        bits.AutoNegotiationHCD.addEnum("1000BASE-T Full Duplex", 0x7);

        bits.AutoNegotiationNextPageWait.setBaseRegister(&r16);
        bits.AutoNegotiationNextPageWait.setName("AutoNegotiationNextPageWait");
        bits.AutoNegotiationAbilityDetect.setBaseRegister(&r16);
        bits.AutoNegotiationAbilityDetect.setName("AutoNegotiationAbilityDetect");
        bits.AutoNegotiationACKDetect.setBaseRegister(&r16);
        bits.AutoNegotiationACKDetect.setName("AutoNegotiationACKDetect");
        bits.AutoNegotiationCompleteACK.setBaseRegister(&r16);
        bits.AutoNegotiationCompleteACK.setName("AutoNegotiationCompleteACK");
        bits.AutoNegotiationComplete.setBaseRegister(&r16);
        bits.AutoNegotiationComplete.setName("AutoNegotiationComplete");
    }
    RegMIIAuxiliaryStatusSummary_t& operator=(const RegMIIAuxiliaryStatusSummary_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIAuxiliaryStatusSummary_t;

#define REG_MII_INTERRUPT_STATUS ((volatile BCM5719_MII_H_uint16_t*)0x1a) /*  */
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
#if defined(__LITTLE_ENDIAN__)
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
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, IPStatusChange, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, IllegalPairSwap, 14, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_13_13, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MDIXStatusChange, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ExceededLowCounterThreshold, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, AutonegotiationPageRX, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, HCDNoLink, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NoHCD, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, NegotiatedUnsupportedHCD, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ScramblerSyncError, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteReceiverStatusChange, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LocalReceiverStatusChange, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DuplexModeChange, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkSpeedChange, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkStatusChange, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CRCError, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "InterruptStatus"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIInterruptStatus_t()
    {
        /** @brief constructor for @ref MII_t.InterruptStatus. */
        r16.setName("InterruptStatus");
        bits.CRCError.setBaseRegister(&r16);
        bits.CRCError.setName("CRCError");
        bits.LinkStatusChange.setBaseRegister(&r16);
        bits.LinkStatusChange.setName("LinkStatusChange");
        bits.LinkSpeedChange.setBaseRegister(&r16);
        bits.LinkSpeedChange.setName("LinkSpeedChange");
        bits.DuplexModeChange.setBaseRegister(&r16);
        bits.DuplexModeChange.setName("DuplexModeChange");
        bits.LocalReceiverStatusChange.setBaseRegister(&r16);
        bits.LocalReceiverStatusChange.setName("LocalReceiverStatusChange");
        bits.RemoteReceiverStatusChange.setBaseRegister(&r16);
        bits.RemoteReceiverStatusChange.setName("RemoteReceiverStatusChange");
        bits.ScramblerSyncError.setBaseRegister(&r16);
        bits.ScramblerSyncError.setName("ScramblerSyncError");
        bits.NegotiatedUnsupportedHCD.setBaseRegister(&r16);
        bits.NegotiatedUnsupportedHCD.setName("NegotiatedUnsupportedHCD");
        bits.NoHCD.setBaseRegister(&r16);
        bits.NoHCD.setName("NoHCD");
        bits.HCDNoLink.setBaseRegister(&r16);
        bits.HCDNoLink.setName("HCDNoLink");
        bits.AutonegotiationPageRX.setBaseRegister(&r16);
        bits.AutonegotiationPageRX.setName("AutonegotiationPageRX");
        bits.ExceededLowCounterThreshold.setBaseRegister(&r16);
        bits.ExceededLowCounterThreshold.setName("ExceededLowCounterThreshold");
        bits.MDIXStatusChange.setBaseRegister(&r16);
        bits.MDIXStatusChange.setName("MDIXStatusChange");
        bits.IllegalPairSwap.setBaseRegister(&r16);
        bits.IllegalPairSwap.setName("IllegalPairSwap");
        bits.IPStatusChange.setBaseRegister(&r16);
        bits.IPStatusChange.setName("IPStatusChange");
    }
    RegMIIInterruptStatus_t& operator=(const RegMIIInterruptStatus_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIInterruptStatus_t;

#define REG_MII_INTERRUPT_MASK ((volatile BCM5719_MII_H_uint16_t*)0x1b) /*  */
#define     MII_INTERRUPT_MASK_INTERRUPT_MASK_VECTOR_SHIFT 0u
#define     MII_INTERRUPT_MASK_INTERRUPT_MASK_VECTOR_MASK  0xffffu
#define GET_MII_INTERRUPT_MASK_INTERRUPT_MASK_VECTOR(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_MII_INTERRUPT_MASK_INTERRUPT_MASK_VECTOR(__val__)  (((__val__) << 0u) & 0xffffu)

/** @brief Register definition for @ref MII_t.InterruptMask. */
typedef register_container RegMIIInterruptMask_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, InterruptMaskVector, 0, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, InterruptMaskVector, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "InterruptMask"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIInterruptMask_t()
    {
        /** @brief constructor for @ref MII_t.InterruptMask. */
        r16.setName("InterruptMask");
        bits.InterruptMaskVector.setBaseRegister(&r16);
        bits.InterruptMaskVector.setName("InterruptMaskVector");
    }
    RegMIIInterruptMask_t& operator=(const RegMIIInterruptMask_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIInterruptMask_t;

#define REG_MII_CABLETRON_LED ((volatile BCM5719_MII_H_uint16_t*)0x1c) /* Note: Shadow Register Selector: 0 */
#define     MII_CABLETRON_LED_CABLETRON_LED_SHIFT 0u
#define     MII_CABLETRON_LED_CABLETRON_LED_MASK  0xffu
#define GET_MII_CABLETRON_LED_CABLETRON_LED(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_MII_CABLETRON_LED_CABLETRON_LED(__val__)  (((__val__) << 0u) & 0xffu)
#define     MII_CABLETRON_LED_SHADOW_REGISTER_SELECTOR_SHIFT 10u
#define     MII_CABLETRON_LED_SHADOW_REGISTER_SELECTOR_MASK  0x7c00u
#define GET_MII_CABLETRON_LED_SHADOW_REGISTER_SELECTOR(__reg__)  (((__reg__) & 0x7c00) >> 10u)
#define SET_MII_CABLETRON_LED_SHADOW_REGISTER_SELECTOR(__val__)  (((__val__) << 10u) & 0x7c00u)
#define     MII_CABLETRON_LED_WRITE_ENABLE_SHIFT 15u
#define     MII_CABLETRON_LED_WRITE_ENABLE_MASK  0x8000u
#define GET_MII_CABLETRON_LED_WRITE_ENABLE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_CABLETRON_LED_WRITE_ENABLE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.CabletronLed. */
typedef register_container RegMIICabletronLed_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CabletronLED, 0, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_9_8, 8, 2)
        /** @brief Writes to the selected shadow register are done by first setting up the register. Reads can be done immediately after selecting the shadow register. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 10, 5)
        /** @brief Write bits [9:0] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Write bits [9:0] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
        /** @brief Writes to the selected shadow register are done by first setting up the register. Reads can be done immediately after selecting the shadow register. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 10, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_9_8, 8, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CabletronLED, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "CabletronLed"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIICabletronLed_t()
    {
        /** @brief constructor for @ref MII_t.CabletronLed. */
        r16.setName("CabletronLed");
        bits.CabletronLED.setBaseRegister(&r16);
        bits.CabletronLED.setName("CabletronLED");
        bits.ShadowRegisterSelector.setBaseRegister(&r16);
        bits.ShadowRegisterSelector.setName("ShadowRegisterSelector");
        bits.WriteEnable.setBaseRegister(&r16);
        bits.WriteEnable.setName("WriteEnable");
    }
    RegMIICabletronLed_t& operator=(const RegMIICabletronLed_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIICabletronLed_t;

#define REG_MII_TEST_1 ((volatile BCM5719_MII_H_uint16_t*)0x1e) /*  */
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
#if defined(__LITTLE_ENDIAN__)
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
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CRCErrorCountVisibility, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TransmitErrorCodeVisibility, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CounterTestMode, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceLink, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceLock, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ScramblerTest, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ExternalLink, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, FastTimers, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ManualSwapMDIState, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ReceiveWatchdogTimerDisable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisablePolarityEncode, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MainDACEnableSoftwareTrimSetting, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MainDACTrim, 0, 4)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Test1"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIITest1_t()
    {
        /** @brief constructor for @ref MII_t.Test1. */
        r16.setName("Test1");
        bits.MainDACTrim.setBaseRegister(&r16);
        bits.MainDACTrim.setName("MainDACTrim");
        bits.MainDACEnableSoftwareTrimSetting.setBaseRegister(&r16);
        bits.MainDACEnableSoftwareTrimSetting.setName("MainDACEnableSoftwareTrimSetting");
        bits.DisablePolarityEncode.setBaseRegister(&r16);
        bits.DisablePolarityEncode.setName("DisablePolarityEncode");
        bits.ReceiveWatchdogTimerDisable.setBaseRegister(&r16);
        bits.ReceiveWatchdogTimerDisable.setName("ReceiveWatchdogTimerDisable");
        bits.ManualSwapMDIState.setBaseRegister(&r16);
        bits.ManualSwapMDIState.setName("ManualSwapMDIState");
        bits.FastTimers.setBaseRegister(&r16);
        bits.FastTimers.setName("FastTimers");
        bits.ExternalLink.setBaseRegister(&r16);
        bits.ExternalLink.setName("ExternalLink");
        bits.ScramblerTest.setBaseRegister(&r16);
        bits.ScramblerTest.setName("ScramblerTest");
        bits.ForceLock.setBaseRegister(&r16);
        bits.ForceLock.setName("ForceLock");
        bits.ForceLink.setBaseRegister(&r16);
        bits.ForceLink.setName("ForceLink");
        bits.CounterTestMode.setBaseRegister(&r16);
        bits.CounterTestMode.setName("CounterTestMode");
        bits.TransmitErrorCodeVisibility.setBaseRegister(&r16);
        bits.TransmitErrorCodeVisibility.setName("TransmitErrorCodeVisibility");
        bits.CRCErrorCountVisibility.setBaseRegister(&r16);
        bits.CRCErrorCountVisibility.setName("CRCErrorCountVisibility");
    }
    RegMIITest1_t& operator=(const RegMIITest1_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIITest1_t;

#define REG_MII_BLOCK_SELECT ((volatile BCM5719_MII_H_uint16_t*)0x1f) /* Pages in the specified register block. */
/** @brief Register definition for @ref MII_t.BlockSelect. */
typedef register_container RegMIIBlockSelect_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BlockSelect"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIBlockSelect_t()
    {
        /** @brief constructor for @ref MII_t.BlockSelect. */
        r16.setName("BlockSelect");
    }
    RegMIIBlockSelect_t& operator=(const RegMIIBlockSelect_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIBlockSelect_t;

#define REG_MII_10BASE_T ((volatile BCM5719_MII_H_uint16_t*)0x118) /* Note: Shadow Register Selector: 1 */
#define     MII_10BASE_T_SHADOW_REGISTER_SELECTOR_SHIFT 0u
#define     MII_10BASE_T_SHADOW_REGISTER_SELECTOR_MASK  0x7u
#define GET_MII_10BASE_T_SHADOW_REGISTER_SELECTOR(__reg__)  (((__reg__) & 0x7) >> 0u)
#define SET_MII_10BASE_T_SHADOW_REGISTER_SELECTOR(__val__)  (((__val__) << 0u) & 0x7u)
#define     MII_10BASE_T_10BASE_T_POLARITY_ERROR_COUNT_MAX_SHIFT 3u
#define     MII_10BASE_T_10BASE_T_POLARITY_ERROR_COUNT_MAX_MASK  0x8u
#define GET_MII_10BASE_T_10BASE_T_POLARITY_ERROR_COUNT_MAX(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_MII_10BASE_T_10BASE_T_POLARITY_ERROR_COUNT_MAX(__val__)  (((__val__) << 3u) & 0x8u)
#define     MII_10BASE_T_10BASE_T_NO_DRIBBLE_SHIFT 4u
#define     MII_10BASE_T_10BASE_T_NO_DRIBBLE_MASK  0x10u
#define GET_MII_10BASE_T_10BASE_T_NO_DRIBBLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_10BASE_T_10BASE_T_NO_DRIBBLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_10BASE_T_SQE_ENABLE_MODE_SHIFT 5u
#define     MII_10BASE_T_SQE_ENABLE_MODE_MASK  0x20u
#define GET_MII_10BASE_T_SQE_ENABLE_MODE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_10BASE_T_SQE_ENABLE_MODE(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_10BASE_T_10BT_ECHO_MODE_SHIFT 6u
#define     MII_10BASE_T_10BT_ECHO_MODE_MASK  0x40u
#define GET_MII_10BASE_T_10BT_ECHO_MODE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_10BASE_T_10BT_ECHO_MODE(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_10BASE_T_10BASE_T_SIGNAL_DETECT_THRESHOLD_SHIFT 7u
#define     MII_10BASE_T_10BASE_T_SIGNAL_DETECT_THRESHOLD_MASK  0x80u
#define GET_MII_10BASE_T_10BASE_T_SIGNAL_DETECT_THRESHOLD(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_10BASE_T_10BASE_T_SIGNAL_DETECT_THRESHOLD(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_10BASE_T_10BASE_T_SIGNAL_DETECT_AUTOSWITCH_SHIFT 8u
#define     MII_10BASE_T_10BASE_T_SIGNAL_DETECT_AUTOSWITCH_MASK  0x100u
#define GET_MII_10BASE_T_10BASE_T_SIGNAL_DETECT_AUTOSWITCH(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_10BASE_T_10BASE_T_SIGNAL_DETECT_AUTOSWITCH(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_10BASE_T_JABBER_DISABLE_SHIFT 9u
#define     MII_10BASE_T_JABBER_DISABLE_MASK  0x200u
#define GET_MII_10BASE_T_JABBER_DISABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_10BASE_T_JABBER_DISABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_10BASE_T_CLASS_A_DIV_B_LINE_DRIVER_SELECT_SHIFT 10u
#define     MII_10BASE_T_CLASS_A_DIV_B_LINE_DRIVER_SELECT_MASK  0x400u
#define GET_MII_10BASE_T_CLASS_A_DIV_B_LINE_DRIVER_SELECT(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_10BASE_T_CLASS_A_DIV_B_LINE_DRIVER_SELECT(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_10BASE_T_10_BT_TXC_INVERT_MODE_SHIFT 11u
#define     MII_10BASE_T_10_BT_TXC_INVERT_MODE_MASK  0x800u
#define GET_MII_10BASE_T_10_BT_TXC_INVERT_MODE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_10BASE_T_10_BT_TXC_INVERT_MODE(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_10BASE_T_BLOCK_RXDV_EXTENSION_SHIFT 12u
#define     MII_10BASE_T_BLOCK_RXDV_EXTENSION_MASK  0x1000u
#define GET_MII_10BASE_T_BLOCK_RXDV_EXTENSION(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_10BASE_T_BLOCK_RXDV_EXTENSION(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_10BASE_T_POLARITY_ERROR_SHIFT 13u
#define     MII_10BASE_T_POLARITY_ERROR_MASK  0x2000u
#define GET_MII_10BASE_T_POLARITY_ERROR(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_10BASE_T_POLARITY_ERROR(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_10BASE_T_EOF_ERROR_SHIFT 14u
#define     MII_10BASE_T_EOF_ERROR_MASK  0x4000u
#define GET_MII_10BASE_T_EOF_ERROR(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_10BASE_T_EOF_ERROR(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_10BASE_T_MANCHESTER_CODE_ERROR_SHIFT 15u
#define     MII_10BASE_T_MANCHESTER_CODE_ERROR_MASK  0x8000u
#define GET_MII_10BASE_T_MANCHESTER_CODE_ERROR(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_10BASE_T_MANCHESTER_CODE_ERROR(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.10baseT. */
typedef register_container RegMII10baseT_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Writes to the selected shadow register are done on a single cycle (no setup required). Reads are selected by first writing to register 18h, shadow 7, bits 14:12. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 0, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10Base_TPolarityErrorCountMax, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10Base_TNoDribble, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SQEEnableMode, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTEchoMode, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10Base_TSignalDetectThreshold, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10Base_TSignalDetectAutoswitch, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, JabberDisable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ClassA_DIV_BLineDriverSelect, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTTXCInvertMode, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BlockRXDVExtension, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PolarityError, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EOFError, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ManchesterCodeError, 15, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ManchesterCodeError, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EOFError, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PolarityError, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BlockRXDVExtension, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTTXCInvertMode, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ClassA_DIV_BLineDriverSelect, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, JabberDisable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10Base_TSignalDetectAutoswitch, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10Base_TSignalDetectThreshold, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTEchoMode, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SQEEnableMode, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10Base_TNoDribble, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10Base_TPolarityErrorCountMax, 3, 1)
        /** @brief Writes to the selected shadow register are done on a single cycle (no setup required). Reads are selected by first writing to register 18h, shadow 7, bits 14:12. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 0, 3)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "10baseT"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMII10baseT_t()
    {
        /** @brief constructor for @ref MII_t.10baseT. */
        r16.setName("10baseT");
        bits.ShadowRegisterSelector.setBaseRegister(&r16);
        bits.ShadowRegisterSelector.setName("ShadowRegisterSelector");
        bits._10Base_TPolarityErrorCountMax.setBaseRegister(&r16);
        bits._10Base_TPolarityErrorCountMax.setName("_10Base_TPolarityErrorCountMax");
        bits._10Base_TNoDribble.setBaseRegister(&r16);
        bits._10Base_TNoDribble.setName("_10Base_TNoDribble");
        bits.SQEEnableMode.setBaseRegister(&r16);
        bits.SQEEnableMode.setName("SQEEnableMode");
        bits._10BTEchoMode.setBaseRegister(&r16);
        bits._10BTEchoMode.setName("_10BTEchoMode");
        bits._10Base_TSignalDetectThreshold.setBaseRegister(&r16);
        bits._10Base_TSignalDetectThreshold.setName("_10Base_TSignalDetectThreshold");
        bits._10Base_TSignalDetectAutoswitch.setBaseRegister(&r16);
        bits._10Base_TSignalDetectAutoswitch.setName("_10Base_TSignalDetectAutoswitch");
        bits.JabberDisable.setBaseRegister(&r16);
        bits.JabberDisable.setName("JabberDisable");
        bits.ClassA_DIV_BLineDriverSelect.setBaseRegister(&r16);
        bits.ClassA_DIV_BLineDriverSelect.setName("ClassA_DIV_BLineDriverSelect");
        bits._10BTTXCInvertMode.setBaseRegister(&r16);
        bits._10BTTXCInvertMode.setName("_10BTTXCInvertMode");
        bits.BlockRXDVExtension.setBaseRegister(&r16);
        bits.BlockRXDVExtension.setName("BlockRXDVExtension");
        bits.PolarityError.setBaseRegister(&r16);
        bits.PolarityError.setName("PolarityError");
        bits.EOFError.setBaseRegister(&r16);
        bits.EOFError.setName("EOFError");
        bits.ManchesterCodeError.setBaseRegister(&r16);
        bits.ManchesterCodeError.setName("ManchesterCodeError");
    }
    RegMII10baseT_t& operator=(const RegMII10baseT_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMII10baseT_t;

#define REG_MII_DLL_SELECTION ((volatile BCM5719_MII_H_uint16_t*)0x11c) /* Note: Shadow Register Selector: 1 */
#define     MII_DLL_SELECTION_HIGH_QUALITY_CLOCK_TEST_MODE_SHIFT 0u
#define     MII_DLL_SELECTION_HIGH_QUALITY_CLOCK_TEST_MODE_MASK  0x3fu
#define GET_MII_DLL_SELECTION_HIGH_QUALITY_CLOCK_TEST_MODE(__reg__)  (((__reg__) & 0x3f) >> 0u)
#define SET_MII_DLL_SELECTION_HIGH_QUALITY_CLOCK_TEST_MODE(__val__)  (((__val__) << 0u) & 0x3fu)
#define     MII_DLL_SELECTION_SHADOW_REGISTER_SELECTOR_SHIFT 10u
#define     MII_DLL_SELECTION_SHADOW_REGISTER_SELECTOR_MASK  0x7c00u
#define GET_MII_DLL_SELECTION_SHADOW_REGISTER_SELECTOR(__reg__)  (((__reg__) & 0x7c00) >> 10u)
#define SET_MII_DLL_SELECTION_SHADOW_REGISTER_SELECTOR(__val__)  (((__val__) << 10u) & 0x7c00u)
#define     MII_DLL_SELECTION_WRITE_ENABLE_SHIFT 15u
#define     MII_DLL_SELECTION_WRITE_ENABLE_MASK  0x8000u
#define GET_MII_DLL_SELECTION_WRITE_ENABLE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_DLL_SELECTION_WRITE_ENABLE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.DllSelection. */
typedef register_container RegMIIDllSelection_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, HighQualityClockTestMode, 0, 6)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_9_6, 6, 4)
        /** @brief Writes to the selected shadow register are done by first setting up the register. Reads can be done immediately after selecting the shadow register. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 10, 5)
        /** @brief Write bits [9:0] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Write bits [9:0] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
        /** @brief Writes to the selected shadow register are done by first setting up the register. Reads can be done immediately after selecting the shadow register. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 10, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_9_6, 6, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, HighQualityClockTestMode, 0, 6)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "DllSelection"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIDllSelection_t()
    {
        /** @brief constructor for @ref MII_t.DllSelection. */
        r16.setName("DllSelection");
        bits.HighQualityClockTestMode.setBaseRegister(&r16);
        bits.HighQualityClockTestMode.setName("HighQualityClockTestMode");
        bits.ShadowRegisterSelector.setBaseRegister(&r16);
        bits.ShadowRegisterSelector.setName("ShadowRegisterSelector");
        bits.WriteEnable.setBaseRegister(&r16);
        bits.WriteEnable.setName("WriteEnable");
    }
    RegMIIDllSelection_t& operator=(const RegMIIDllSelection_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIDllSelection_t;

#define REG_MII_POWER_AND_MII_CONTROL ((volatile BCM5719_MII_H_uint16_t*)0x218) /* Note: Shadow Register Selector: 2 */
#define     MII_POWER_AND_MII_CONTROL_SHADOW_REGISTER_SELECTOR_SHIFT 0u
#define     MII_POWER_AND_MII_CONTROL_SHADOW_REGISTER_SELECTOR_MASK  0x7u
#define GET_MII_POWER_AND_MII_CONTROL_SHADOW_REGISTER_SELECTOR(__reg__)  (((__reg__) & 0x7) >> 0u)
#define SET_MII_POWER_AND_MII_CONTROL_SHADOW_REGISTER_SELECTOR(__val__)  (((__val__) << 0u) & 0x7u)
#define     MII_POWER_AND_MII_CONTROL_SUPER_ISOLATE_SHIFT 5u
#define     MII_POWER_AND_MII_CONTROL_SUPER_ISOLATE_MASK  0x20u
#define GET_MII_POWER_AND_MII_CONTROL_SUPER_ISOLATE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_POWER_AND_MII_CONTROL_SUPER_ISOLATE(__val__)  (((__val__) << 5u) & 0x20u)

/** @brief Register definition for @ref MII_t.PowerAndMiiControl. */
typedef register_container RegMIIPowerAndMiiControl_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Writes to the selected shadow register are done on a single cycle (no setup required). Reads are selected by first writing to register 18h, shadow 7, bits 14:12. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 0, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_4_3, 3, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SuperIsolate, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_15_6, 6, 10)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_15_6, 6, 10)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SuperIsolate, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_4_3, 3, 2)
        /** @brief Writes to the selected shadow register are done on a single cycle (no setup required). Reads are selected by first writing to register 18h, shadow 7, bits 14:12. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 0, 3)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PowerAndMiiControl"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIPowerAndMiiControl_t()
    {
        /** @brief constructor for @ref MII_t.PowerAndMiiControl. */
        r16.setName("PowerAndMiiControl");
        bits.ShadowRegisterSelector.setBaseRegister(&r16);
        bits.ShadowRegisterSelector.setName("ShadowRegisterSelector");
        bits.SuperIsolate.setBaseRegister(&r16);
        bits.SuperIsolate.setName("SuperIsolate");
    }
    RegMIIPowerAndMiiControl_t& operator=(const RegMIIPowerAndMiiControl_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIPowerAndMiiControl_t;

#define REG_MII_SPARE_CONTROL_1 ((volatile BCM5719_MII_H_uint16_t*)0x21c) /* Note: Shadow Register Selector: 2 */
#define     MII_SPARE_CONTROL_1_LINK_LED_MODE_SHIFT 0u
#define     MII_SPARE_CONTROL_1_LINK_LED_MODE_MASK  0x1u
#define GET_MII_SPARE_CONTROL_1_LINK_LED_MODE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_MII_SPARE_CONTROL_1_LINK_LED_MODE(__val__)  (((__val__) << 0u) & 0x1u)
#define     MII_SPARE_CONTROL_1_LOST_TOKEN_FIX_DISABLE_SHIFT 1u
#define     MII_SPARE_CONTROL_1_LOST_TOKEN_FIX_DISABLE_MASK  0x2u
#define GET_MII_SPARE_CONTROL_1_LOST_TOKEN_FIX_DISABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_MII_SPARE_CONTROL_1_LOST_TOKEN_FIX_DISABLE(__val__)  (((__val__) << 1u) & 0x2u)
#define     MII_SPARE_CONTROL_1_BICOLOR_LINK_SPEED_LED_MODE_SHIFT 2u
#define     MII_SPARE_CONTROL_1_BICOLOR_LINK_SPEED_LED_MODE_MASK  0x4u
#define GET_MII_SPARE_CONTROL_1_BICOLOR_LINK_SPEED_LED_MODE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_MII_SPARE_CONTROL_1_BICOLOR_LINK_SPEED_LED_MODE(__val__)  (((__val__) << 2u) & 0x4u)
#define     MII_SPARE_CONTROL_1_100FX_MODE_COPPER_PATH_SHIFT 4u
#define     MII_SPARE_CONTROL_1_100FX_MODE_COPPER_PATH_MASK  0x10u
#define GET_MII_SPARE_CONTROL_1_100FX_MODE_COPPER_PATH(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_SPARE_CONTROL_1_100FX_MODE_COPPER_PATH(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_SPARE_CONTROL_1_USE_FILTERED_SD_SHIFT 5u
#define     MII_SPARE_CONTROL_1_USE_FILTERED_SD_MASK  0x20u
#define GET_MII_SPARE_CONTROL_1_USE_FILTERED_SD(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_SPARE_CONTROL_1_USE_FILTERED_SD(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_SPARE_CONTROL_1_CFC_INITFILTER_ENABLE_SHIFT 6u
#define     MII_SPARE_CONTROL_1_CFC_INITFILTER_ENABLE_MASK  0x40u
#define GET_MII_SPARE_CONTROL_1_CFC_INITFILTER_ENABLE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_SPARE_CONTROL_1_CFC_INITFILTER_ENABLE(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_SPARE_CONTROL_1_INVERT_SD_PIN_SHIFT 7u
#define     MII_SPARE_CONTROL_1_INVERT_SD_PIN_MASK  0x80u
#define GET_MII_SPARE_CONTROL_1_INVERT_SD_PIN(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_SPARE_CONTROL_1_INVERT_SD_PIN(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_SPARE_CONTROL_1_FORCE_SD_ON_SHIFT 8u
#define     MII_SPARE_CONTROL_1_FORCE_SD_ON_MASK  0x100u
#define GET_MII_SPARE_CONTROL_1_FORCE_SD_ON(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_SPARE_CONTROL_1_FORCE_SD_ON(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_SPARE_CONTROL_1_SD_STATUS_SHIFT 9u
#define     MII_SPARE_CONTROL_1_SD_STATUS_MASK  0x200u
#define GET_MII_SPARE_CONTROL_1_SD_STATUS(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_SPARE_CONTROL_1_SD_STATUS(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_SPARE_CONTROL_1_SHADOW_REGISTER_SELECTOR_SHIFT 10u
#define     MII_SPARE_CONTROL_1_SHADOW_REGISTER_SELECTOR_MASK  0x7c00u
#define GET_MII_SPARE_CONTROL_1_SHADOW_REGISTER_SELECTOR(__reg__)  (((__reg__) & 0x7c00) >> 10u)
#define SET_MII_SPARE_CONTROL_1_SHADOW_REGISTER_SELECTOR(__val__)  (((__val__) << 10u) & 0x7c00u)
#define     MII_SPARE_CONTROL_1_WRITE_ENABLE_SHIFT 15u
#define     MII_SPARE_CONTROL_1_WRITE_ENABLE_MASK  0x8000u
#define GET_MII_SPARE_CONTROL_1_WRITE_ENABLE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_SPARE_CONTROL_1_WRITE_ENABLE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.SpareControl1. */
typedef register_container RegMIISpareControl1_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkLEDMode, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LostTokenFixDisable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BicolorLinkSpeedLEDMode, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100FXModeCopperPath, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, UseFilteredSD, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CFC_INITFILTEREnable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, InvertSDPin, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceSDOn, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SDStatus, 9, 1)
        /** @brief Writes to the selected shadow register are done by first setting up the register. Reads can be done immediately after selecting the shadow register. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 10, 5)
        /** @brief Write bits [9:0] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Write bits [9:0] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
        /** @brief Writes to the selected shadow register are done by first setting up the register. Reads can be done immediately after selecting the shadow register. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 10, 5)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SDStatus, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceSDOn, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, InvertSDPin, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CFC_INITFILTEREnable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, UseFilteredSD, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _100FXModeCopperPath, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BicolorLinkSpeedLEDMode, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LostTokenFixDisable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LinkLEDMode, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SpareControl1"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIISpareControl1_t()
    {
        /** @brief constructor for @ref MII_t.SpareControl1. */
        r16.setName("SpareControl1");
        bits.LinkLEDMode.setBaseRegister(&r16);
        bits.LinkLEDMode.setName("LinkLEDMode");
        bits.LostTokenFixDisable.setBaseRegister(&r16);
        bits.LostTokenFixDisable.setName("LostTokenFixDisable");
        bits.BicolorLinkSpeedLEDMode.setBaseRegister(&r16);
        bits.BicolorLinkSpeedLEDMode.setName("BicolorLinkSpeedLEDMode");
        bits._100FXModeCopperPath.setBaseRegister(&r16);
        bits._100FXModeCopperPath.setName("_100FXModeCopperPath");
        bits.UseFilteredSD.setBaseRegister(&r16);
        bits.UseFilteredSD.setName("UseFilteredSD");
        bits.CFC_INITFILTEREnable.setBaseRegister(&r16);
        bits.CFC_INITFILTEREnable.setName("CFC_INITFILTEREnable");
        bits.InvertSDPin.setBaseRegister(&r16);
        bits.InvertSDPin.setName("InvertSDPin");
        bits.ForceSDOn.setBaseRegister(&r16);
        bits.ForceSDOn.setName("ForceSDOn");
        bits.SDStatus.setBaseRegister(&r16);
        bits.SDStatus.setName("SDStatus");
        bits.ShadowRegisterSelector.setBaseRegister(&r16);
        bits.ShadowRegisterSelector.setName("ShadowRegisterSelector");
        bits.WriteEnable.setBaseRegister(&r16);
        bits.WriteEnable.setName("WriteEnable");
    }
    RegMIISpareControl1_t& operator=(const RegMIISpareControl1_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIISpareControl1_t;

#define REG_MII_CLOCK_ALIGNMENT_CONTROL ((volatile BCM5719_MII_H_uint16_t*)0x31c) /* Note: Shadow Register Selector: 3 */
#define     MII_CLOCK_ALIGNMENT_CONTROL_DELAY_LINE_SELECTOR_SHIFT 0u
#define     MII_CLOCK_ALIGNMENT_CONTROL_DELAY_LINE_SELECTOR_MASK  0xfu
#define GET_MII_CLOCK_ALIGNMENT_CONTROL_DELAY_LINE_SELECTOR(__reg__)  (((__reg__) & 0xf) >> 0u)
#define SET_MII_CLOCK_ALIGNMENT_CONTROL_DELAY_LINE_SELECTOR(__val__)  (((__val__) << 0u) & 0xfu)
#define     MII_CLOCK_ALIGNMENT_CONTROL_DELAY_VALUE_SHIFT 4u
#define     MII_CLOCK_ALIGNMENT_CONTROL_DELAY_VALUE_MASK  0x70u
#define GET_MII_CLOCK_ALIGNMENT_CONTROL_DELAY_VALUE(__reg__)  (((__reg__) & 0x70) >> 4u)
#define SET_MII_CLOCK_ALIGNMENT_CONTROL_DELAY_VALUE(__val__)  (((__val__) << 4u) & 0x70u)
#define     MII_CLOCK_ALIGNMENT_CONTROL_RXCLK_ALIGNMENT_STROBE_SHIFT 7u
#define     MII_CLOCK_ALIGNMENT_CONTROL_RXCLK_ALIGNMENT_STROBE_MASK  0x80u
#define GET_MII_CLOCK_ALIGNMENT_CONTROL_RXCLK_ALIGNMENT_STROBE(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_CLOCK_ALIGNMENT_CONTROL_RXCLK_ALIGNMENT_STROBE(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_CLOCK_ALIGNMENT_CONTROL_GMII_CLOCK_ALIGNMENT_STROBE_SHIFT 8u
#define     MII_CLOCK_ALIGNMENT_CONTROL_GMII_CLOCK_ALIGNMENT_STROBE_MASK  0x100u
#define GET_MII_CLOCK_ALIGNMENT_CONTROL_GMII_CLOCK_ALIGNMENT_STROBE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_CLOCK_ALIGNMENT_CONTROL_GMII_CLOCK_ALIGNMENT_STROBE(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_CLOCK_ALIGNMENT_CONTROL_GTXCLK_DELAY_BYPASS_DISABLE_SHIFT 9u
#define     MII_CLOCK_ALIGNMENT_CONTROL_GTXCLK_DELAY_BYPASS_DISABLE_MASK  0x200u
#define GET_MII_CLOCK_ALIGNMENT_CONTROL_GTXCLK_DELAY_BYPASS_DISABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_CLOCK_ALIGNMENT_CONTROL_GTXCLK_DELAY_BYPASS_DISABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_CLOCK_ALIGNMENT_CONTROL_SHADOW_REGISTER_SELECTOR_SHIFT 10u
#define     MII_CLOCK_ALIGNMENT_CONTROL_SHADOW_REGISTER_SELECTOR_MASK  0x7c00u
#define GET_MII_CLOCK_ALIGNMENT_CONTROL_SHADOW_REGISTER_SELECTOR(__reg__)  (((__reg__) & 0x7c00) >> 10u)
#define SET_MII_CLOCK_ALIGNMENT_CONTROL_SHADOW_REGISTER_SELECTOR(__val__)  (((__val__) << 10u) & 0x7c00u)
#define     MII_CLOCK_ALIGNMENT_CONTROL_WRITE_ENABLE_SHIFT 15u
#define     MII_CLOCK_ALIGNMENT_CONTROL_WRITE_ENABLE_MASK  0x8000u
#define GET_MII_CLOCK_ALIGNMENT_CONTROL_WRITE_ENABLE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_CLOCK_ALIGNMENT_CONTROL_WRITE_ENABLE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.ClockAlignmentControl. */
typedef register_container RegMIIClockAlignmentControl_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DelayLineSelector, 0, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DelayValue, 4, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RXCLKAlignmentStrobe, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, GMIIClockAlignmentStrobe, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, GTXCLKDelayBypassDisable, 9, 1)
        /** @brief Writes to the selected shadow register are done by first setting up the register. Reads can be done immediately after selecting the shadow register. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 10, 5)
        /** @brief Write bits [9:0] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Write bits [9:0] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
        /** @brief Writes to the selected shadow register are done by first setting up the register. Reads can be done immediately after selecting the shadow register. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 10, 5)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, GTXCLKDelayBypassDisable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, GMIIClockAlignmentStrobe, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RXCLKAlignmentStrobe, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DelayValue, 4, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DelayLineSelector, 0, 4)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ClockAlignmentControl"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIClockAlignmentControl_t()
    {
        /** @brief constructor for @ref MII_t.ClockAlignmentControl. */
        r16.setName("ClockAlignmentControl");
        bits.DelayLineSelector.setBaseRegister(&r16);
        bits.DelayLineSelector.setName("DelayLineSelector");
        bits.DelayValue.setBaseRegister(&r16);
        bits.DelayValue.setName("DelayValue");
        bits.RXCLKAlignmentStrobe.setBaseRegister(&r16);
        bits.RXCLKAlignmentStrobe.setName("RXCLKAlignmentStrobe");
        bits.GMIIClockAlignmentStrobe.setBaseRegister(&r16);
        bits.GMIIClockAlignmentStrobe.setName("GMIIClockAlignmentStrobe");
        bits.GTXCLKDelayBypassDisable.setBaseRegister(&r16);
        bits.GTXCLKDelayBypassDisable.setName("GTXCLKDelayBypassDisable");
        bits.ShadowRegisterSelector.setBaseRegister(&r16);
        bits.ShadowRegisterSelector.setName("ShadowRegisterSelector");
        bits.WriteEnable.setBaseRegister(&r16);
        bits.WriteEnable.setName("WriteEnable");
    }
    RegMIIClockAlignmentControl_t& operator=(const RegMIIClockAlignmentControl_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIClockAlignmentControl_t;

#define REG_MII_MISC_TEST_1 ((volatile BCM5719_MII_H_uint16_t*)0x418) /* Note: Shadow Register Selector: 4 */
#define     MII_MISC_TEST_1_SHADOW_REGISTER_SELECTOR_SHIFT 0u
#define     MII_MISC_TEST_1_SHADOW_REGISTER_SELECTOR_MASK  0x7u
#define GET_MII_MISC_TEST_1_SHADOW_REGISTER_SELECTOR(__reg__)  (((__reg__) & 0x7) >> 0u)
#define SET_MII_MISC_TEST_1_SHADOW_REGISTER_SELECTOR(__val__)  (((__val__) << 0u) & 0x7u)
#define     MII_MISC_TEST_1_HALFOUT_SHIFT 3u
#define     MII_MISC_TEST_1_HALFOUT_MASK  0x8u
#define GET_MII_MISC_TEST_1_HALFOUT(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_MII_MISC_TEST_1_HALFOUT(__val__)  (((__val__) << 3u) & 0x8u)
#define     MII_MISC_TEST_1_SWAP_RXMDIX_SHIFT 4u
#define     MII_MISC_TEST_1_SWAP_RXMDIX_MASK  0x10u
#define GET_MII_MISC_TEST_1_SWAP_RXMDIX(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_MISC_TEST_1_SWAP_RXMDIX(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_MISC_TEST_1_10BT_BYPASS_CRS_SHIFT 5u
#define     MII_MISC_TEST_1_10BT_BYPASS_CRS_MASK  0x20u
#define GET_MII_MISC_TEST_1_10BT_BYPASS_CRS(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_MISC_TEST_1_10BT_BYPASS_CRS(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_MISC_TEST_1_10BT_BYPASS_ADC_SHIFT 6u
#define     MII_MISC_TEST_1_10BT_BYPASS_ADC_MASK  0x40u
#define GET_MII_MISC_TEST_1_10BT_BYPASS_ADC(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_MISC_TEST_1_10BT_BYPASS_ADC(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_MISC_TEST_1_10BT_CLOCK_RESET_ENABLE_SHIFT 7u
#define     MII_MISC_TEST_1_10BT_CLOCK_RESET_ENABLE_MASK  0x80u
#define GET_MII_MISC_TEST_1_10BT_CLOCK_RESET_ENABLE(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_MISC_TEST_1_10BT_CLOCK_RESET_ENABLE(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_MISC_TEST_1_10BT_IDLE_BYPASS_SHIFT 8u
#define     MII_MISC_TEST_1_10BT_IDLE_BYPASS_MASK  0x100u
#define GET_MII_MISC_TEST_1_10BT_IDLE_BYPASS(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_MISC_TEST_1_10BT_IDLE_BYPASS(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_MISC_TEST_1_10BT_POLARITY_BYPASS_SHIFT 9u
#define     MII_MISC_TEST_1_10BT_POLARITY_BYPASS_MASK  0x200u
#define GET_MII_MISC_TEST_1_10BT_POLARITY_BYPASS(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_MISC_TEST_1_10BT_POLARITY_BYPASS(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_MISC_TEST_1_10BT_WAKEUP_SHIFT 10u
#define     MII_MISC_TEST_1_10BT_WAKEUP_MASK  0x400u
#define GET_MII_MISC_TEST_1_10BT_WAKEUP(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_MISC_TEST_1_10BT_WAKEUP(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_MISC_TEST_1_REMOTE_LOOPBACK_TRISTATE_SHIFT 11u
#define     MII_MISC_TEST_1_REMOTE_LOOPBACK_TRISTATE_MASK  0x800u
#define GET_MII_MISC_TEST_1_REMOTE_LOOPBACK_TRISTATE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_MISC_TEST_1_REMOTE_LOOPBACK_TRISTATE(__val__)  (((__val__) << 11u) & 0x800u)

/** @brief Register definition for @ref MII_t.MiscTest1. */
typedef register_container RegMIIMiscTest1_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Writes to the selected shadow register are done on a single cycle (no setup required). Reads are selected by first writing to register 18h, shadow 7, bits 14:12. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 0, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Halfout, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SwapRXMDIX, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTBypassCRS, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTBypassADC, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTClockResetEnable, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTIdleBypass, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTPolarityBypass, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTWakeup, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteLoopbackTristate, 11, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_15_12, 12, 4)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_15_12, 12, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RemoteLoopbackTristate, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTWakeup, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTPolarityBypass, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTIdleBypass, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTClockResetEnable, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTBypassADC, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTBypassCRS, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SwapRXMDIX, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Halfout, 3, 1)
        /** @brief Writes to the selected shadow register are done on a single cycle (no setup required). Reads are selected by first writing to register 18h, shadow 7, bits 14:12. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 0, 3)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MiscTest1"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIMiscTest1_t()
    {
        /** @brief constructor for @ref MII_t.MiscTest1. */
        r16.setName("MiscTest1");
        bits.ShadowRegisterSelector.setBaseRegister(&r16);
        bits.ShadowRegisterSelector.setName("ShadowRegisterSelector");
        bits.Halfout.setBaseRegister(&r16);
        bits.Halfout.setName("Halfout");
        bits.SwapRXMDIX.setBaseRegister(&r16);
        bits.SwapRXMDIX.setName("SwapRXMDIX");
        bits._10BTBypassCRS.setBaseRegister(&r16);
        bits._10BTBypassCRS.setName("_10BTBypassCRS");
        bits._10BTBypassADC.setBaseRegister(&r16);
        bits._10BTBypassADC.setName("_10BTBypassADC");
        bits._10BTClockResetEnable.setBaseRegister(&r16);
        bits._10BTClockResetEnable.setName("_10BTClockResetEnable");
        bits._10BTIdleBypass.setBaseRegister(&r16);
        bits._10BTIdleBypass.setName("_10BTIdleBypass");
        bits._10BTPolarityBypass.setBaseRegister(&r16);
        bits._10BTPolarityBypass.setName("_10BTPolarityBypass");
        bits._10BTWakeup.setBaseRegister(&r16);
        bits._10BTWakeup.setName("_10BTWakeup");
        bits.RemoteLoopbackTristate.setBaseRegister(&r16);
        bits.RemoteLoopbackTristate.setName("RemoteLoopbackTristate");
    }
    RegMIIMiscTest1_t& operator=(const RegMIIMiscTest1_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIMiscTest1_t;

#define REG_MII_SPARE_CONTROL_2 ((volatile BCM5719_MII_H_uint16_t*)0x41c) /* Note: Shadow Register Selector: 4 */
#define     MII_SPARE_CONTROL_2_TEST_ON_BYTE_7_0_SHIFT 0u
#define     MII_SPARE_CONTROL_2_TEST_ON_BYTE_7_0_MASK  0x1u
#define GET_MII_SPARE_CONTROL_2_TEST_ON_BYTE_7_0(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_MII_SPARE_CONTROL_2_TEST_ON_BYTE_7_0(__val__)  (((__val__) << 0u) & 0x1u)
#define     MII_SPARE_CONTROL_2_ENERGY_DETECT_ON_INTR_PIN_SHIFT 1u
#define     MII_SPARE_CONTROL_2_ENERGY_DETECT_ON_INTR_PIN_MASK  0x2u
#define GET_MII_SPARE_CONTROL_2_ENERGY_DETECT_ON_INTR_PIN(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_MII_SPARE_CONTROL_2_ENERGY_DETECT_ON_INTR_PIN(__val__)  (((__val__) << 1u) & 0x2u)
#define     MII_SPARE_CONTROL_2_WIRESPEED_RETRY_LIMIT_SHIFT 2u
#define     MII_SPARE_CONTROL_2_WIRESPEED_RETRY_LIMIT_MASK  0x1cu
#define GET_MII_SPARE_CONTROL_2_WIRESPEED_RETRY_LIMIT(__reg__)  (((__reg__) & 0x1c) >> 2u)
#define SET_MII_SPARE_CONTROL_2_WIRESPEED_RETRY_LIMIT(__val__)  (((__val__) << 2u) & 0x1cu)
#define     MII_SPARE_CONTROL_2_ENABLE_TXC_RXC_TRISTATE_SHIFT 5u
#define     MII_SPARE_CONTROL_2_ENABLE_TXC_RXC_TRISTATE_MASK  0x20u
#define GET_MII_SPARE_CONTROL_2_ENABLE_TXC_RXC_TRISTATE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_SPARE_CONTROL_2_ENABLE_TXC_RXC_TRISTATE(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_SPARE_CONTROL_2_DISABLE_PHYA2_SHIFT 6u
#define     MII_SPARE_CONTROL_2_DISABLE_PHYA2_MASK  0x40u
#define GET_MII_SPARE_CONTROL_2_DISABLE_PHYA2(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_SPARE_CONTROL_2_DISABLE_PHYA2(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_SPARE_CONTROL_2_SELECT_TPOUT_RXD_SHIFT 7u
#define     MII_SPARE_CONTROL_2_SELECT_TPOUT_RXD_MASK  0x80u
#define GET_MII_SPARE_CONTROL_2_SELECT_TPOUT_RXD(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_SPARE_CONTROL_2_SELECT_TPOUT_RXD(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_SPARE_CONTROL_2_WIRESPEED_RETRY_DISABLE_SHIFT 8u
#define     MII_SPARE_CONTROL_2_WIRESPEED_RETRY_DISABLE_MASK  0x100u
#define GET_MII_SPARE_CONTROL_2_WIRESPEED_RETRY_DISABLE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_SPARE_CONTROL_2_WIRESPEED_RETRY_DISABLE(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_SPARE_CONTROL_2_SHADOW_REGISTER_SELECTOR_SHIFT 10u
#define     MII_SPARE_CONTROL_2_SHADOW_REGISTER_SELECTOR_MASK  0x7c00u
#define GET_MII_SPARE_CONTROL_2_SHADOW_REGISTER_SELECTOR(__reg__)  (((__reg__) & 0x7c00) >> 10u)
#define SET_MII_SPARE_CONTROL_2_SHADOW_REGISTER_SELECTOR(__val__)  (((__val__) << 10u) & 0x7c00u)
#define     MII_SPARE_CONTROL_2_WRITE_ENABLE_SHIFT 15u
#define     MII_SPARE_CONTROL_2_WRITE_ENABLE_MASK  0x8000u
#define GET_MII_SPARE_CONTROL_2_WRITE_ENABLE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_SPARE_CONTROL_2_WRITE_ENABLE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.SpareControl2. */
typedef register_container RegMIISpareControl2_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TestOnByte7_0, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnergyDetectOnIntrPin, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WirespeedRetryLimit, 2, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnableTXCRXCTristate, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisablePHYA2, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SelectTPOUT_RXD, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WirespeedRetryDisable, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_9_9, 9, 1)
        /** @brief Writes to the selected shadow register are done by first setting up the register. Reads can be done immediately after selecting the shadow register. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 10, 5)
        /** @brief Write bits [9:0] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Write bits [9:0] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
        /** @brief Writes to the selected shadow register are done by first setting up the register. Reads can be done immediately after selecting the shadow register. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 10, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_9_9, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WirespeedRetryDisable, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SelectTPOUT_RXD, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisablePHYA2, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnableTXCRXCTristate, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WirespeedRetryLimit, 2, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnergyDetectOnIntrPin, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TestOnByte7_0, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SpareControl2"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIISpareControl2_t()
    {
        /** @brief constructor for @ref MII_t.SpareControl2. */
        r16.setName("SpareControl2");
        bits.TestOnByte7_0.setBaseRegister(&r16);
        bits.TestOnByte7_0.setName("TestOnByte7_0");
        bits.EnergyDetectOnIntrPin.setBaseRegister(&r16);
        bits.EnergyDetectOnIntrPin.setName("EnergyDetectOnIntrPin");
        bits.WirespeedRetryLimit.setBaseRegister(&r16);
        bits.WirespeedRetryLimit.setName("WirespeedRetryLimit");
        bits.EnableTXCRXCTristate.setBaseRegister(&r16);
        bits.EnableTXCRXCTristate.setName("EnableTXCRXCTristate");
        bits.DisablePHYA2.setBaseRegister(&r16);
        bits.DisablePHYA2.setName("DisablePHYA2");
        bits.SelectTPOUT_RXD.setBaseRegister(&r16);
        bits.SelectTPOUT_RXD.setName("SelectTPOUT_RXD");
        bits.WirespeedRetryDisable.setBaseRegister(&r16);
        bits.WirespeedRetryDisable.setName("WirespeedRetryDisable");
        bits.ShadowRegisterSelector.setBaseRegister(&r16);
        bits.ShadowRegisterSelector.setName("ShadowRegisterSelector");
        bits.WriteEnable.setBaseRegister(&r16);
        bits.WriteEnable.setName("WriteEnable");
    }
    RegMIISpareControl2_t& operator=(const RegMIISpareControl2_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIISpareControl2_t;

#define REG_MII_MISC_TEST_2 ((volatile BCM5719_MII_H_uint16_t*)0x518) /* Note: Shadow Register Selector: 5 */
#define     MII_MISC_TEST_2_SHADOW_REGISTER_SELECTOR_SHIFT 0u
#define     MII_MISC_TEST_2_SHADOW_REGISTER_SELECTOR_MASK  0x7u
#define GET_MII_MISC_TEST_2_SHADOW_REGISTER_SELECTOR(__reg__)  (((__reg__) & 0x7) >> 0u)
#define SET_MII_MISC_TEST_2_SHADOW_REGISTER_SELECTOR(__val__)  (((__val__) << 0u) & 0x7u)
#define     MII_MISC_TEST_2_EN_PWRDNTDAC_SHIFT 3u
#define     MII_MISC_TEST_2_EN_PWRDNTDAC_MASK  0x8u
#define GET_MII_MISC_TEST_2_EN_PWRDNTDAC(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_MII_MISC_TEST_2_EN_PWRDNTDAC(__val__)  (((__val__) << 3u) & 0x8u)
#define     MII_MISC_TEST_2_ENABLE_FORCE_MDIX_SHIFT 4u
#define     MII_MISC_TEST_2_ENABLE_FORCE_MDIX_MASK  0x10u
#define GET_MII_MISC_TEST_2_ENABLE_FORCE_MDIX(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_MISC_TEST_2_ENABLE_FORCE_MDIX(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_MISC_TEST_2_ENABLE_EC_AS_NEXT_SHIFT 5u
#define     MII_MISC_TEST_2_ENABLE_EC_AS_NEXT_MASK  0x20u
#define GET_MII_MISC_TEST_2_ENABLE_EC_AS_NEXT(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_MISC_TEST_2_ENABLE_EC_AS_NEXT(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_MISC_TEST_2_OLD_PCS_ENCODING_TX_SHIFT 6u
#define     MII_MISC_TEST_2_OLD_PCS_ENCODING_TX_MASK  0x40u
#define GET_MII_MISC_TEST_2_OLD_PCS_ENCODING_TX(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_MISC_TEST_2_OLD_PCS_ENCODING_TX(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_MISC_TEST_2_OLD_PCS_ENCODING_RX_SHIFT 7u
#define     MII_MISC_TEST_2_OLD_PCS_ENCODING_RX_MASK  0x80u
#define GET_MII_MISC_TEST_2_OLD_PCS_ENCODING_RX(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_MISC_TEST_2_OLD_PCS_ENCODING_RX(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_MISC_TEST_2_DISABLE_AUTO_ENCODING_CORRECTION_SHIFT 8u
#define     MII_MISC_TEST_2_DISABLE_AUTO_ENCODING_CORRECTION_MASK  0x100u
#define GET_MII_MISC_TEST_2_DISABLE_AUTO_ENCODING_CORRECTION(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_MISC_TEST_2_DISABLE_AUTO_ENCODING_CORRECTION(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_MISC_TEST_2_ENC_ERROR_SCALE_SHIFT 10u
#define     MII_MISC_TEST_2_ENC_ERROR_SCALE_MASK  0xc00u
#define GET_MII_MISC_TEST_2_ENC_ERROR_SCALE(__reg__)  (((__reg__) & 0xc00) >> 10u)
#define SET_MII_MISC_TEST_2_ENC_ERROR_SCALE(__val__)  (((__val__) << 10u) & 0xc00u)
#define     MII_MISC_TEST_2_CLASS_A_DIV_B_ENABLE_SHIFT 12u
#define     MII_MISC_TEST_2_CLASS_A_DIV_B_ENABLE_MASK  0x1000u
#define GET_MII_MISC_TEST_2_CLASS_A_DIV_B_ENABLE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_MII_MISC_TEST_2_CLASS_A_DIV_B_ENABLE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     MII_MISC_TEST_2_CLASS_A_DIV_B_DVT_ENABLE_SHIFT 13u
#define     MII_MISC_TEST_2_CLASS_A_DIV_B_DVT_ENABLE_MASK  0x2000u
#define GET_MII_MISC_TEST_2_CLASS_A_DIV_B_DVT_ENABLE(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_MII_MISC_TEST_2_CLASS_A_DIV_B_DVT_ENABLE(__val__)  (((__val__) << 13u) & 0x2000u)
#define     MII_MISC_TEST_2_ADCFIFO_TX_FIX_SHIFT 14u
#define     MII_MISC_TEST_2_ADCFIFO_TX_FIX_MASK  0x4000u
#define GET_MII_MISC_TEST_2_ADCFIFO_TX_FIX(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_MII_MISC_TEST_2_ADCFIFO_TX_FIX(__val__)  (((__val__) << 14u) & 0x4000u)
#define     MII_MISC_TEST_2_COPPER_ENERGY_DETECT_OVERRIDE_SHIFT 15u
#define     MII_MISC_TEST_2_COPPER_ENERGY_DETECT_OVERRIDE_MASK  0x8000u
#define GET_MII_MISC_TEST_2_COPPER_ENERGY_DETECT_OVERRIDE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_MISC_TEST_2_COPPER_ENERGY_DETECT_OVERRIDE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.MiscTest2. */
typedef register_container RegMIIMiscTest2_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Writes to the selected shadow register are done on a single cycle (no setup required). Reads are selected by first writing to register 18h, shadow 7, bits 14:12. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 0, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnPWRDNTDAC, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Enableforce_mdix, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnableECasNEXT, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, OldPCSEncodingTX, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, OldPCSEncodingRX, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisableAutoEncodingCorrection, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_9_9, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ENCErrorScale, 10, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ClassA_DIV_BEnable, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ClassA_DIV_BDVTEnable, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ADCFIFOTXFix, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CopperEnergyDetectOverride, 15, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CopperEnergyDetectOverride, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ADCFIFOTXFix, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ClassA_DIV_BDVTEnable, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ClassA_DIV_BEnable, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ENCErrorScale, 10, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, reserved_9_9, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisableAutoEncodingCorrection, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, OldPCSEncodingRX, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, OldPCSEncodingTX, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnableECasNEXT, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Enableforce_mdix, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnPWRDNTDAC, 3, 1)
        /** @brief Writes to the selected shadow register are done on a single cycle (no setup required). Reads are selected by first writing to register 18h, shadow 7, bits 14:12. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 0, 3)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MiscTest2"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIMiscTest2_t()
    {
        /** @brief constructor for @ref MII_t.MiscTest2. */
        r16.setName("MiscTest2");
        bits.ShadowRegisterSelector.setBaseRegister(&r16);
        bits.ShadowRegisterSelector.setName("ShadowRegisterSelector");
        bits.EnPWRDNTDAC.setBaseRegister(&r16);
        bits.EnPWRDNTDAC.setName("EnPWRDNTDAC");
        bits.Enableforce_mdix.setBaseRegister(&r16);
        bits.Enableforce_mdix.setName("Enableforce_mdix");
        bits.EnableECasNEXT.setBaseRegister(&r16);
        bits.EnableECasNEXT.setName("EnableECasNEXT");
        bits.OldPCSEncodingTX.setBaseRegister(&r16);
        bits.OldPCSEncodingTX.setName("OldPCSEncodingTX");
        bits.OldPCSEncodingRX.setBaseRegister(&r16);
        bits.OldPCSEncodingRX.setName("OldPCSEncodingRX");
        bits.DisableAutoEncodingCorrection.setBaseRegister(&r16);
        bits.DisableAutoEncodingCorrection.setName("DisableAutoEncodingCorrection");
        bits.ENCErrorScale.setBaseRegister(&r16);
        bits.ENCErrorScale.setName("ENCErrorScale");
        bits.ClassA_DIV_BEnable.setBaseRegister(&r16);
        bits.ClassA_DIV_BEnable.setName("ClassA_DIV_BEnable");
        bits.ClassA_DIV_BDVTEnable.setBaseRegister(&r16);
        bits.ClassA_DIV_BDVTEnable.setName("ClassA_DIV_BDVTEnable");
        bits.ADCFIFOTXFix.setBaseRegister(&r16);
        bits.ADCFIFOTXFix.setName("ADCFIFOTXFix");
        bits.CopperEnergyDetectOverride.setBaseRegister(&r16);
        bits.CopperEnergyDetectOverride.setName("CopperEnergyDetectOverride");
    }
    RegMIIMiscTest2_t& operator=(const RegMIIMiscTest2_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIMiscTest2_t;

#define REG_MII_SPARE_CONTROL_3 ((volatile BCM5719_MII_H_uint16_t*)0x51c) /* Note: Shadow Register Selector: 3 */
#define     MII_SPARE_CONTROL_3_CLK125_OUTPUT_ENABLE_SHIFT 0u
#define     MII_SPARE_CONTROL_3_CLK125_OUTPUT_ENABLE_MASK  0x1u
#define GET_MII_SPARE_CONTROL_3_CLK125_OUTPUT_ENABLE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_MII_SPARE_CONTROL_3_CLK125_OUTPUT_ENABLE(__val__)  (((__val__) << 0u) & 0x1u)
#define     MII_SPARE_CONTROL_3_AUTO_POWER_DOWN_DLL_OFF_DISABLE_SHIFT 1u
#define     MII_SPARE_CONTROL_3_AUTO_POWER_DOWN_DLL_OFF_DISABLE_MASK  0x2u
#define GET_MII_SPARE_CONTROL_3_AUTO_POWER_DOWN_DLL_OFF_DISABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_MII_SPARE_CONTROL_3_AUTO_POWER_DOWN_DLL_OFF_DISABLE(__val__)  (((__val__) << 1u) & 0x2u)
#define     MII_SPARE_CONTROL_3_SIGDET_DEASSERT_TIMER_LENGTHEN_SHIFT 2u
#define     MII_SPARE_CONTROL_3_SIGDET_DEASSERT_TIMER_LENGTHEN_MASK  0x4u
#define GET_MII_SPARE_CONTROL_3_SIGDET_DEASSERT_TIMER_LENGTHEN(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_MII_SPARE_CONTROL_3_SIGDET_DEASSERT_TIMER_LENGTHEN(__val__)  (((__val__) << 2u) & 0x4u)
#define     MII_SPARE_CONTROL_3_DISABLE_LOW_POWER_TOBASE_T_LINK_MODE_SHIFT 3u
#define     MII_SPARE_CONTROL_3_DISABLE_LOW_POWER_TOBASE_T_LINK_MODE_MASK  0x8u
#define GET_MII_SPARE_CONTROL_3_DISABLE_LOW_POWER_TOBASE_T_LINK_MODE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_MII_SPARE_CONTROL_3_DISABLE_LOW_POWER_TOBASE_T_LINK_MODE(__val__)  (((__val__) << 3u) & 0x8u)
#define     MII_SPARE_CONTROL_3_LOW_POWER_ENC_DISABLE_SHIFT 4u
#define     MII_SPARE_CONTROL_3_LOW_POWER_ENC_DISABLE_MASK  0x10u
#define GET_MII_SPARE_CONTROL_3_LOW_POWER_ENC_DISABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_SPARE_CONTROL_3_LOW_POWER_ENC_DISABLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_SPARE_CONTROL_3_ENERGY_DETECT_CHANGE_MUX_SELECT_SHIFT 5u
#define     MII_SPARE_CONTROL_3_ENERGY_DETECT_CHANGE_MUX_SELECT_MASK  0x20u
#define GET_MII_SPARE_CONTROL_3_ENERGY_DETECT_CHANGE_MUX_SELECT(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_SPARE_CONTROL_3_ENERGY_DETECT_CHANGE_MUX_SELECT(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_SPARE_CONTROL_3_TXC_OFF_ENABLE_SHIFT 6u
#define     MII_SPARE_CONTROL_3_TXC_OFF_ENABLE_MASK  0x40u
#define GET_MII_SPARE_CONTROL_3_TXC_OFF_ENABLE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_SPARE_CONTROL_3_TXC_OFF_ENABLE(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_SPARE_CONTROL_3_10BT_CARRIER_REJECT_FILTER_ENABLE_SHIFT 7u
#define     MII_SPARE_CONTROL_3_10BT_CARRIER_REJECT_FILTER_ENABLE_MASK  0x80u
#define GET_MII_SPARE_CONTROL_3_10BT_CARRIER_REJECT_FILTER_ENABLE(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_SPARE_CONTROL_3_10BT_CARRIER_REJECT_FILTER_ENABLE(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_SPARE_CONTROL_3_TXC_RXC_DISABLE_DURING_AUTO_POWER_DOWN_SHIFT 8u
#define     MII_SPARE_CONTROL_3_TXC_RXC_DISABLE_DURING_AUTO_POWER_DOWN_MASK  0x100u
#define GET_MII_SPARE_CONTROL_3_TXC_RXC_DISABLE_DURING_AUTO_POWER_DOWN(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_SPARE_CONTROL_3_TXC_RXC_DISABLE_DURING_AUTO_POWER_DOWN(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_SPARE_CONTROL_3_DLL_LOCK_ENABLE_DURING_AUTO_POWER_DOWN_SHIFT 9u
#define     MII_SPARE_CONTROL_3_DLL_LOCK_ENABLE_DURING_AUTO_POWER_DOWN_MASK  0x200u
#define GET_MII_SPARE_CONTROL_3_DLL_LOCK_ENABLE_DURING_AUTO_POWER_DOWN(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_SPARE_CONTROL_3_DLL_LOCK_ENABLE_DURING_AUTO_POWER_DOWN(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_SPARE_CONTROL_3_SHADOW_REGISTER_SELECTOR_SHIFT 10u
#define     MII_SPARE_CONTROL_3_SHADOW_REGISTER_SELECTOR_MASK  0x7c00u
#define GET_MII_SPARE_CONTROL_3_SHADOW_REGISTER_SELECTOR(__reg__)  (((__reg__) & 0x7c00) >> 10u)
#define SET_MII_SPARE_CONTROL_3_SHADOW_REGISTER_SELECTOR(__val__)  (((__val__) << 10u) & 0x7c00u)
#define     MII_SPARE_CONTROL_3_WRITE_ENABLE_SHIFT 15u
#define     MII_SPARE_CONTROL_3_WRITE_ENABLE_MASK  0x8000u
#define GET_MII_SPARE_CONTROL_3_WRITE_ENABLE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_SPARE_CONTROL_3_WRITE_ENABLE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.SpareControl3. */
typedef register_container RegMIISpareControl3_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CLK125OutputEnable, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Auto_PowerDownDLLOffDisable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SIGDETDeassertTimerLengthen, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisableLowPowerTOBase_TLinkMode, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LowPowerENCDisable, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnergyDetectChangeMuxSelect, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TXCOffEnable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTCarrierRejectFilterEnable, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TXCRXCDisableDuringAutoPowerDown, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DLLLockEnableDuringAutoPowerDown, 9, 1)
        /** @brief Writes to the selected shadow register are done by first setting up the register. Reads can be done immediately after selecting the shadow register. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 10, 5)
        /** @brief Write bits [9:0] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Write bits [9:0] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
        /** @brief Writes to the selected shadow register are done by first setting up the register. Reads can be done immediately after selecting the shadow register. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 10, 5)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DLLLockEnableDuringAutoPowerDown, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TXCRXCDisableDuringAutoPowerDown, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, _10BTCarrierRejectFilterEnable, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, TXCOffEnable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, EnergyDetectChangeMuxSelect, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, LowPowerENCDisable, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, DisableLowPowerTOBase_TLinkMode, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, SIGDETDeassertTimerLengthen, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, Auto_PowerDownDLLOffDisable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, CLK125OutputEnable, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SpareControl3"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIISpareControl3_t()
    {
        /** @brief constructor for @ref MII_t.SpareControl3. */
        r16.setName("SpareControl3");
        bits.CLK125OutputEnable.setBaseRegister(&r16);
        bits.CLK125OutputEnable.setName("CLK125OutputEnable");
        bits.Auto_PowerDownDLLOffDisable.setBaseRegister(&r16);
        bits.Auto_PowerDownDLLOffDisable.setName("Auto_PowerDownDLLOffDisable");
        bits.SIGDETDeassertTimerLengthen.setBaseRegister(&r16);
        bits.SIGDETDeassertTimerLengthen.setName("SIGDETDeassertTimerLengthen");
        bits.DisableLowPowerTOBase_TLinkMode.setBaseRegister(&r16);
        bits.DisableLowPowerTOBase_TLinkMode.setName("DisableLowPowerTOBase_TLinkMode");
        bits.LowPowerENCDisable.setBaseRegister(&r16);
        bits.LowPowerENCDisable.setName("LowPowerENCDisable");
        bits.EnergyDetectChangeMuxSelect.setBaseRegister(&r16);
        bits.EnergyDetectChangeMuxSelect.setName("EnergyDetectChangeMuxSelect");
        bits.TXCOffEnable.setBaseRegister(&r16);
        bits.TXCOffEnable.setName("TXCOffEnable");
        bits._10BTCarrierRejectFilterEnable.setBaseRegister(&r16);
        bits._10BTCarrierRejectFilterEnable.setName("_10BTCarrierRejectFilterEnable");
        bits.TXCRXCDisableDuringAutoPowerDown.setBaseRegister(&r16);
        bits.TXCRXCDisableDuringAutoPowerDown.setName("TXCRXCDisableDuringAutoPowerDown");
        bits.DLLLockEnableDuringAutoPowerDown.setBaseRegister(&r16);
        bits.DLLLockEnableDuringAutoPowerDown.setName("DLLLockEnableDuringAutoPowerDown");
        bits.ShadowRegisterSelector.setBaseRegister(&r16);
        bits.ShadowRegisterSelector.setName("ShadowRegisterSelector");
        bits.WriteEnable.setBaseRegister(&r16);
        bits.WriteEnable.setName("WriteEnable");
    }
    RegMIISpareControl3_t& operator=(const RegMIISpareControl3_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIISpareControl3_t;

#define REG_MII_MISCELLANEOUS_CONTROL ((volatile BCM5719_MII_H_uint16_t*)0x718) /* Note: Shadow Register Selector: 7 */
#define     MII_MISCELLANEOUS_CONTROL_SHADOW_REGISTER_SELECTOR_SHIFT 0u
#define     MII_MISCELLANEOUS_CONTROL_SHADOW_REGISTER_SELECTOR_MASK  0x7u
#define GET_MII_MISCELLANEOUS_CONTROL_SHADOW_REGISTER_SELECTOR(__reg__)  (((__reg__) & 0x7) >> 0u)
#define SET_MII_MISCELLANEOUS_CONTROL_SHADOW_REGISTER_SELECTOR(__val__)  (((__val__) << 0u) & 0x7u)
#define     MII_MISCELLANEOUS_CONTROL_MDIO_ALL_PHY_SELECT_SHIFT 3u
#define     MII_MISCELLANEOUS_CONTROL_MDIO_ALL_PHY_SELECT_MASK  0x8u
#define GET_MII_MISCELLANEOUS_CONTROL_MDIO_ALL_PHY_SELECT(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_MII_MISCELLANEOUS_CONTROL_MDIO_ALL_PHY_SELECT(__val__)  (((__val__) << 3u) & 0x8u)
#define     MII_MISCELLANEOUS_CONTROL_WIRESPEED_ENABLE_SHIFT 4u
#define     MII_MISCELLANEOUS_CONTROL_WIRESPEED_ENABLE_MASK  0x10u
#define GET_MII_MISCELLANEOUS_CONTROL_WIRESPEED_ENABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_MII_MISCELLANEOUS_CONTROL_WIRESPEED_ENABLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     MII_MISCELLANEOUS_CONTROL_RGMII_OUT_OF_BAND_STATUS_DISABLE_SHIFT 5u
#define     MII_MISCELLANEOUS_CONTROL_RGMII_OUT_OF_BAND_STATUS_DISABLE_MASK  0x20u
#define GET_MII_MISCELLANEOUS_CONTROL_RGMII_OUT_OF_BAND_STATUS_DISABLE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_MII_MISCELLANEOUS_CONTROL_RGMII_OUT_OF_BAND_STATUS_DISABLE(__val__)  (((__val__) << 5u) & 0x20u)
#define     MII_MISCELLANEOUS_CONTROL_RGMII_RXER_MODE_SHIFT 6u
#define     MII_MISCELLANEOUS_CONTROL_RGMII_RXER_MODE_MASK  0x40u
#define GET_MII_MISCELLANEOUS_CONTROL_RGMII_RXER_MODE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_MII_MISCELLANEOUS_CONTROL_RGMII_RXER_MODE(__val__)  (((__val__) << 6u) & 0x40u)
#define     MII_MISCELLANEOUS_CONTROL_RGMII_MODE_SHIFT 7u
#define     MII_MISCELLANEOUS_CONTROL_RGMII_MODE_MASK  0x80u
#define GET_MII_MISCELLANEOUS_CONTROL_RGMII_MODE(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_MII_MISCELLANEOUS_CONTROL_RGMII_MODE(__val__)  (((__val__) << 7u) & 0x80u)
#define     MII_MISCELLANEOUS_CONTROL_RGMII_TIMING_MODE_SHIFT 8u
#define     MII_MISCELLANEOUS_CONTROL_RGMII_TIMING_MODE_MASK  0x100u
#define GET_MII_MISCELLANEOUS_CONTROL_RGMII_TIMING_MODE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_MII_MISCELLANEOUS_CONTROL_RGMII_TIMING_MODE(__val__)  (((__val__) << 8u) & 0x100u)
#define     MII_MISCELLANEOUS_CONTROL_FORCE_AUTO_MDIX_MODE_SHIFT 9u
#define     MII_MISCELLANEOUS_CONTROL_FORCE_AUTO_MDIX_MODE_MASK  0x200u
#define GET_MII_MISCELLANEOUS_CONTROL_FORCE_AUTO_MDIX_MODE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_MII_MISCELLANEOUS_CONTROL_FORCE_AUTO_MDIX_MODE(__val__)  (((__val__) << 9u) & 0x200u)
#define     MII_MISCELLANEOUS_CONTROL_BYPASS_WIRESPEED_TIMER_SHIFT 10u
#define     MII_MISCELLANEOUS_CONTROL_BYPASS_WIRESPEED_TIMER_MASK  0x400u
#define GET_MII_MISCELLANEOUS_CONTROL_BYPASS_WIRESPEED_TIMER(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_MII_MISCELLANEOUS_CONTROL_BYPASS_WIRESPEED_TIMER(__val__)  (((__val__) << 10u) & 0x400u)
#define     MII_MISCELLANEOUS_CONTROL_PACKET_COUNTER_MODE_SHIFT 11u
#define     MII_MISCELLANEOUS_CONTROL_PACKET_COUNTER_MODE_MASK  0x800u
#define GET_MII_MISCELLANEOUS_CONTROL_PACKET_COUNTER_MODE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_MII_MISCELLANEOUS_CONTROL_PACKET_COUNTER_MODE(__val__)  (((__val__) << 11u) & 0x800u)
#define     MII_MISCELLANEOUS_CONTROL_SHADOW_REGISTER_READ_SELECTOR_SHIFT 12u
#define     MII_MISCELLANEOUS_CONTROL_SHADOW_REGISTER_READ_SELECTOR_MASK  0x7000u
#define GET_MII_MISCELLANEOUS_CONTROL_SHADOW_REGISTER_READ_SELECTOR(__reg__)  (((__reg__) & 0x7000) >> 12u)
#define SET_MII_MISCELLANEOUS_CONTROL_SHADOW_REGISTER_READ_SELECTOR(__val__)  (((__val__) << 12u) & 0x7000u)
#define     MII_MISCELLANEOUS_CONTROL_WRITE_ENABLE_SHIFT 15u
#define     MII_MISCELLANEOUS_CONTROL_WRITE_ENABLE_MASK  0x8000u
#define GET_MII_MISCELLANEOUS_CONTROL_WRITE_ENABLE(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_MII_MISCELLANEOUS_CONTROL_WRITE_ENABLE(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref MII_t.MiscellaneousControl. */
typedef register_container RegMIIMiscellaneousControl_t {
    /** @brief 16bit direct register access. */
    BCM5719_MII_H_uint16_t r16;

    BITFIELD_BEGIN(BCM5719_MII_H_uint16_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Writes to the selected shadow register are done on a single cycle (no setup required). Reads are selected by first writing to register 18h, shadow 7, bits 14:12. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 0, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MDIOAllPhySelect, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WirespeedEnable, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RGMIIOut_Of_BandStatusDisable, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RGMIIRXERMode, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RGMIIMode, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RGMIITimingMode, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceAutoMDIXMode, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BypassWirespeedTimer, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PacketCounterMode, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterReadSelector, 12, 3)
        /** @brief Enables writes to bits [8:3] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Enables writes to bits [8:3] */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WriteEnable, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterReadSelector, 12, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, PacketCounterMode, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, BypassWirespeedTimer, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ForceAutoMDIXMode, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RGMIITimingMode, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RGMIIMode, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RGMIIRXERMode, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, RGMIIOut_Of_BandStatusDisable, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, WirespeedEnable, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, MDIOAllPhySelect, 3, 1)
        /** @brief Writes to the selected shadow register are done on a single cycle (no setup required). Reads are selected by first writing to register 18h, shadow 7, bits 14:12. */
        BITFIELD_MEMBER(BCM5719_MII_H_uint16_t, ShadowRegisterSelector, 0, 3)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_MII_H_uint16_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MiscellaneousControl"; }

    /** @brief Print register value. */
    void print(void) { r16.print(); }

    RegMIIMiscellaneousControl_t()
    {
        /** @brief constructor for @ref MII_t.MiscellaneousControl. */
        r16.setName("MiscellaneousControl");
        bits.ShadowRegisterSelector.setBaseRegister(&r16);
        bits.ShadowRegisterSelector.setName("ShadowRegisterSelector");
        bits.MDIOAllPhySelect.setBaseRegister(&r16);
        bits.MDIOAllPhySelect.setName("MDIOAllPhySelect");
        bits.WirespeedEnable.setBaseRegister(&r16);
        bits.WirespeedEnable.setName("WirespeedEnable");
        bits.RGMIIOut_Of_BandStatusDisable.setBaseRegister(&r16);
        bits.RGMIIOut_Of_BandStatusDisable.setName("RGMIIOut_Of_BandStatusDisable");
        bits.RGMIIRXERMode.setBaseRegister(&r16);
        bits.RGMIIRXERMode.setName("RGMIIRXERMode");
        bits.RGMIIMode.setBaseRegister(&r16);
        bits.RGMIIMode.setName("RGMIIMode");
        bits.RGMIITimingMode.setBaseRegister(&r16);
        bits.RGMIITimingMode.setName("RGMIITimingMode");
        bits.ForceAutoMDIXMode.setBaseRegister(&r16);
        bits.ForceAutoMDIXMode.setName("ForceAutoMDIXMode");
        bits.BypassWirespeedTimer.setBaseRegister(&r16);
        bits.BypassWirespeedTimer.setName("BypassWirespeedTimer");
        bits.PacketCounterMode.setBaseRegister(&r16);
        bits.PacketCounterMode.setName("PacketCounterMode");
        bits.ShadowRegisterReadSelector.setBaseRegister(&r16);
        bits.ShadowRegisterReadSelector.setName("ShadowRegisterReadSelector");
        bits.WriteEnable.setBaseRegister(&r16);
        bits.WriteEnable.setName("WriteEnable");
    }
    RegMIIMiscellaneousControl_t& operator=(const RegMIIMiscellaneousControl_t& other)
    {
        r16 = other.r16;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegMIIMiscellaneousControl_t;

/** @brief Component definition for @ref MII. */
typedef struct MII_t {
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
    BCM5719_MII_H_uint16_t reserved_11[3];

    /** @brief WTH is this. */
    RegMIIBroadreachLreAccess_t BroadreachLreAccess;

    /** @brief  */
    RegMIIIeeeExtendedStatus_t IeeeExtendedStatus;

    /** @brief  */
    RegMIIPhyExtendedControl_t PhyExtendedControl;

    /** @brief  */
    RegMIIPhyExtendedStatus_t PhyExtendedStatus;

    /** @brief  */
    RegMIIReceiveErrorCounter_t ReceiveErrorCounter;

    /** @brief  */
    RegMIIFalseCarrierSenseCounter_t FalseCarrierSenseCounter;

    /** @brief  */
    RegMIILocalRemoteReceiverNotOkCounter_t LocalRemoteReceiverNotOkCounter;

    /** @brief  */
    RegMIIDspCoefficientReadWritePort_t DspCoefficientReadWritePort;

    /** @brief  */
    RegMIIDspControl_t DspControl;

    /** @brief  */
    RegMIIDspCoefficientAddress_t DspCoefficientAddress;

    /** @brief Note: Shadow Register Selector: 0 */
    RegMIIAuxiliaryControl_t AuxiliaryControl;

    /** @brief  */
    RegMIIAuxiliaryStatusSummary_t AuxiliaryStatusSummary;

    /** @brief  */
    RegMIIInterruptStatus_t InterruptStatus;

    /** @brief  */
    RegMIIInterruptMask_t InterruptMask;

    /** @brief Note: Shadow Register Selector: 0 */
    RegMIICabletronLed_t CabletronLed;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint16_t reserved_29[1];

    /** @brief  */
    RegMIITest1_t Test1;

    /** @brief Pages in the specified register block. */
    RegMIIBlockSelect_t BlockSelect;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint32_t reserved_32[124];

    /** @brief Note: Shadow Register Selector: 1 */
    RegMII10baseT_t _10baseT;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint16_t reserved_281[3];

    /** @brief Note: Shadow Register Selector: 1 */
    RegMIIDllSelection_t DllSelection;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint16_t reserved_285[251];

    /** @brief Note: Shadow Register Selector: 2 */
    RegMIIPowerAndMiiControl_t PowerAndMiiControl;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint16_t reserved_537[3];

    /** @brief Note: Shadow Register Selector: 2 */
    RegMIISpareControl1_t SpareControl1;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint16_t reserved_541[255];

    /** @brief Note: Shadow Register Selector: 3 */
    RegMIIClockAlignmentControl_t ClockAlignmentControl;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint16_t reserved_797[251];

    /** @brief Note: Shadow Register Selector: 4 */
    RegMIIMiscTest1_t MiscTest1;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint16_t reserved_1049[3];

    /** @brief Note: Shadow Register Selector: 4 */
    RegMIISpareControl2_t SpareControl2;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint16_t reserved_1053[251];

    /** @brief Note: Shadow Register Selector: 5 */
    RegMIIMiscTest2_t MiscTest2;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint16_t reserved_1305[3];

    /** @brief Note: Shadow Register Selector: 3 */
    RegMIISpareControl3_t SpareControl3;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_MII_H_uint16_t reserved_1309[507];

    /** @brief Note: Shadow Register Selector: 7 */
    RegMIIMiscellaneousControl_t MiscellaneousControl;

#ifdef CXX_SIMULATOR
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    MII_t() : mIndexReadCallback(0), mIndexReadCallbackArgs(0), mIndexWriteCallback(0), mIndexWriteCallbackArgs(0)
    {
        Control.r16.setComponentOffset(0x0);
        Status.r16.setComponentOffset(0x1);
        PhyIdHigh.r16.setComponentOffset(0x2);
        PhyIdLow.r16.setComponentOffset(0x3);
        AutonegotiationAdvertisement.r16.setComponentOffset(0x4);
        AutonegotiationLinkPartnerAbilityBasePage.r16.setComponentOffset(0x5);
        AutonegotiationExpansion.r16.setComponentOffset(0x6);
        AutonegotiationNextPageTransmit.r16.setComponentOffset(0x7);
        AutonegotiationLinkPartnerAbilityNextPage.r16.setComponentOffset(0x8);
        _1000baseTControl.r16.setComponentOffset(0x9);
        _1000baseTStatus.r16.setComponentOffset(0xa);
        for(int i = 0; i < 3; i++)
        {
            reserved_11[i].setComponentOffset(0xb + (i * 2));
        }
        BroadreachLreAccess.r16.setComponentOffset(0xe);
        IeeeExtendedStatus.r16.setComponentOffset(0xf);
        PhyExtendedControl.r16.setComponentOffset(0x10);
        PhyExtendedStatus.r16.setComponentOffset(0x11);
        ReceiveErrorCounter.r16.setComponentOffset(0x12);
        FalseCarrierSenseCounter.r16.setComponentOffset(0x13);
        LocalRemoteReceiverNotOkCounter.r16.setComponentOffset(0x14);
        DspCoefficientReadWritePort.r16.setComponentOffset(0x15);
        DspControl.r16.setComponentOffset(0x16);
        DspCoefficientAddress.r16.setComponentOffset(0x17);
        AuxiliaryControl.r16.setComponentOffset(0x18);
        AuxiliaryStatusSummary.r16.setComponentOffset(0x19);
        InterruptStatus.r16.setComponentOffset(0x1a);
        InterruptMask.r16.setComponentOffset(0x1b);
        CabletronLed.r16.setComponentOffset(0x1c);
        for(int i = 0; i < 1; i++)
        {
            reserved_29[i].setComponentOffset(0x1d + (i * 2));
        }
        Test1.r16.setComponentOffset(0x1e);
        BlockSelect.r16.setComponentOffset(0x1f);
        for(int i = 0; i < 62; i++)
        {
            reserved_32[i].setComponentOffset(0x20 + (i * 2));
        }
        _10baseT.r16.setComponentOffset(0x118);
        for(int i = 0; i < 3; i++)
        {
            reserved_281[i].setComponentOffset(0x119 + (i * 2));
        }
        DllSelection.r16.setComponentOffset(0x11c);
        for(int i = 0; i < 251; i++)
        {
            reserved_285[i].setComponentOffset(0x11d + (i * 2));
        }
        PowerAndMiiControl.r16.setComponentOffset(0x218);
        for(int i = 0; i < 3; i++)
        {
            reserved_537[i].setComponentOffset(0x219 + (i * 2));
        }
        SpareControl1.r16.setComponentOffset(0x21c);
        for(int i = 0; i < 255; i++)
        {
            reserved_541[i].setComponentOffset(0x21d + (i * 2));
        }
        ClockAlignmentControl.r16.setComponentOffset(0x31c);
        for(int i = 0; i < 251; i++)
        {
            reserved_797[i].setComponentOffset(0x31d + (i * 2));
        }
        MiscTest1.r16.setComponentOffset(0x418);
        for(int i = 0; i < 3; i++)
        {
            reserved_1049[i].setComponentOffset(0x419 + (i * 2));
        }
        SpareControl2.r16.setComponentOffset(0x41c);
        for(int i = 0; i < 251; i++)
        {
            reserved_1053[i].setComponentOffset(0x41d + (i * 2));
        }
        MiscTest2.r16.setComponentOffset(0x518);
        for(int i = 0; i < 3; i++)
        {
            reserved_1305[i].setComponentOffset(0x519 + (i * 2));
        }
        SpareControl3.r16.setComponentOffset(0x51c);
        for(int i = 0; i < 507; i++)
        {
            reserved_1309[i].setComponentOffset(0x51d + (i * 2));
        }
        MiscellaneousControl.r16.setComponentOffset(0x718);
    }
    void print()
    {
        Control.print();
        Status.print();
        PhyIdHigh.print();
        PhyIdLow.print();
        AutonegotiationAdvertisement.print();
        AutonegotiationLinkPartnerAbilityBasePage.print();
        AutonegotiationExpansion.print();
        AutonegotiationNextPageTransmit.print();
        AutonegotiationLinkPartnerAbilityNextPage.print();
        _1000baseTControl.print();
        _1000baseTStatus.print();
        for(int i = 0; i < 3; i++)
        {
            reserved_11[i].print();
        }
        BroadreachLreAccess.print();
        IeeeExtendedStatus.print();
        PhyExtendedControl.print();
        PhyExtendedStatus.print();
        ReceiveErrorCounter.print();
        FalseCarrierSenseCounter.print();
        LocalRemoteReceiverNotOkCounter.print();
        DspCoefficientReadWritePort.print();
        DspControl.print();
        DspCoefficientAddress.print();
        AuxiliaryControl.print();
        AuxiliaryStatusSummary.print();
        InterruptStatus.print();
        InterruptMask.print();
        CabletronLed.print();
        for(int i = 0; i < 1; i++)
        {
            reserved_29[i].print();
        }
        Test1.print();
        BlockSelect.print();
        for(int i = 0; i < 62; i++)
        {
            reserved_32[i].print();
        }
        _10baseT.print();
        for(int i = 0; i < 3; i++)
        {
            reserved_281[i].print();
        }
        DllSelection.print();
        for(int i = 0; i < 251; i++)
        {
            reserved_285[i].print();
        }
        PowerAndMiiControl.print();
        for(int i = 0; i < 3; i++)
        {
            reserved_537[i].print();
        }
        SpareControl1.print();
        for(int i = 0; i < 255; i++)
        {
            reserved_541[i].print();
        }
        ClockAlignmentControl.print();
        for(int i = 0; i < 251; i++)
        {
            reserved_797[i].print();
        }
        MiscTest1.print();
        for(int i = 0; i < 3; i++)
        {
            reserved_1049[i].print();
        }
        SpareControl2.print();
        for(int i = 0; i < 251; i++)
        {
            reserved_1053[i].print();
        }
        MiscTest2.print();
        for(int i = 0; i < 3; i++)
        {
            reserved_1305[i].print();
        }
        SpareControl3.print();
        for(int i = 0; i < 507; i++)
        {
            reserved_1309[i].print();
        }
        MiscellaneousControl.print();
    }
    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
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

#ifndef CXX_SIMULATOR
_Static_assert(sizeof(MII_t) == 3636, "sizeof(MII_t) must be 3636");
#endif

#endif /* !BCM5719_MII_H */

/** @} */
