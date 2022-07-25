////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_APE_PERI.h
///
/// @project    bcm5719
///
/// @brief      bcm5719_APE_PERI
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

/** @defgroup BCM5719_APE_PERI_H    bcm5719_APE_PERI */
/** @addtogroup BCM5719_APE_PERI_H
 * @{
 */
#ifndef BCM5719_APE_PERI_H
#define BCM5719_APE_PERI_H

#include <types.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_bcm5719_APE_PERI_sim(void* base, uint32_t (*read)(uint32_t val, uint32_t offset, void *args), uint32_t (*write)(uint32_t val, uint32_t offset, void *args));
void init_bcm5719_APE_PERI(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> BCM5719_APE_PERI_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> BCM5719_APE_PERI_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> BCM5719_APE_PERI_H_uint32_t;
#define BCM5719_APE_PERI_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define BCM5719_APE_PERI_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define BCM5719_APE_PERI_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define BCM5719_APE_PERI_H_VOLATILE
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  BCM5719_APE_PERI_H_uint8_t;
typedef uint16_t BCM5719_APE_PERI_H_uint16_t;
typedef uint32_t BCM5719_APE_PERI_H_uint32_t;
#define register_container union
#define BCM5719_APE_PERI_H_VOLATILE volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_APE_PERI_BASE ((volatile void*)0xc0018000) /* Device APE Peripheral Registers */
#define REG_APE_PERI_SIZE (sizeof(APE_PERI_t))

#define REG_APE_PERI_BMC_TO_NC_RX_STATUS ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018300) /*  */
#define     APE_PERI_BMC_TO_NC_RX_STATUS_NEW_SHIFT 0u
#define     APE_PERI_BMC_TO_NC_RX_STATUS_NEW_MASK  0x1u
#define GET_APE_PERI_BMC_TO_NC_RX_STATUS_NEW(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_BMC_TO_NC_RX_STATUS_NEW(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_BMC_TO_NC_RX_STATUS_BAD_SHIFT 1u
#define     APE_PERI_BMC_TO_NC_RX_STATUS_BAD_MASK  0x2u
#define GET_APE_PERI_BMC_TO_NC_RX_STATUS_BAD(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_BMC_TO_NC_RX_STATUS_BAD(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_BMC_TO_NC_RX_STATUS_PASSTHRU_SHIFT 2u
#define     APE_PERI_BMC_TO_NC_RX_STATUS_PASSTHRU_MASK  0x4u
#define GET_APE_PERI_BMC_TO_NC_RX_STATUS_PASSTHRU(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_BMC_TO_NC_RX_STATUS_PASSTHRU(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_BMC_TO_NC_RX_STATUS_SA_HIT_VALID_SHIFT 3u
#define     APE_PERI_BMC_TO_NC_RX_STATUS_SA_HIT_VALID_MASK  0x8u
#define GET_APE_PERI_BMC_TO_NC_RX_STATUS_SA_HIT_VALID(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_BMC_TO_NC_RX_STATUS_SA_HIT_VALID(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_BMC_TO_NC_RX_STATUS_VLAN_SHIFT 4u
#define     APE_PERI_BMC_TO_NC_RX_STATUS_VLAN_MASK  0x10u
#define GET_APE_PERI_BMC_TO_NC_RX_STATUS_VLAN(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_BMC_TO_NC_RX_STATUS_VLAN(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_BMC_TO_NC_RX_STATUS_UNDERFLOW_SHIFT 5u
#define     APE_PERI_BMC_TO_NC_RX_STATUS_UNDERFLOW_MASK  0x20u
#define GET_APE_PERI_BMC_TO_NC_RX_STATUS_UNDERFLOW(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_PERI_BMC_TO_NC_RX_STATUS_UNDERFLOW(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_PERI_BMC_TO_NC_RX_STATUS_ENDOFFRAME_SHIFT 6u
#define     APE_PERI_BMC_TO_NC_RX_STATUS_ENDOFFRAME_MASK  0x40u
#define GET_APE_PERI_BMC_TO_NC_RX_STATUS_ENDOFFRAME(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_PERI_BMC_TO_NC_RX_STATUS_ENDOFFRAME(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_PERI_BMC_TO_NC_RX_STATUS_IN_PROGRESS_SHIFT 7u
#define     APE_PERI_BMC_TO_NC_RX_STATUS_IN_PROGRESS_MASK  0x80u
#define GET_APE_PERI_BMC_TO_NC_RX_STATUS_IN_PROGRESS(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_APE_PERI_BMC_TO_NC_RX_STATUS_IN_PROGRESS(__val__)  (((__val__) << 7u) & 0x80u)
#define     APE_PERI_BMC_TO_NC_RX_STATUS_FLUSHING_SHIFT 8u
#define     APE_PERI_BMC_TO_NC_RX_STATUS_FLUSHING_MASK  0x100u
#define GET_APE_PERI_BMC_TO_NC_RX_STATUS_FLUSHING(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_APE_PERI_BMC_TO_NC_RX_STATUS_FLUSHING(__val__)  (((__val__) << 8u) & 0x100u)
#define     APE_PERI_BMC_TO_NC_RX_STATUS_FLUSH_DONE_SHIFT 9u
#define     APE_PERI_BMC_TO_NC_RX_STATUS_FLUSH_DONE_MASK  0x200u
#define GET_APE_PERI_BMC_TO_NC_RX_STATUS_FLUSH_DONE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_APE_PERI_BMC_TO_NC_RX_STATUS_FLUSH_DONE(__val__)  (((__val__) << 9u) & 0x200u)
#define     APE_PERI_BMC_TO_NC_RX_STATUS_SA_HIT_SHIFT 10u
#define     APE_PERI_BMC_TO_NC_RX_STATUS_SA_HIT_MASK  0x7c00u
#define GET_APE_PERI_BMC_TO_NC_RX_STATUS_SA_HIT(__reg__)  (((__reg__) & 0x7c00) >> 10u)
#define SET_APE_PERI_BMC_TO_NC_RX_STATUS_SA_HIT(__val__)  (((__val__) << 10u) & 0x7c00u)
#define     APE_PERI_BMC_TO_NC_RX_STATUS_PACKET_LENGTH_SHIFT 16u
#define     APE_PERI_BMC_TO_NC_RX_STATUS_PACKET_LENGTH_MASK  0x7ff0000u
#define GET_APE_PERI_BMC_TO_NC_RX_STATUS_PACKET_LENGTH(__reg__)  (((__reg__) & 0x7ff0000) >> 16u)
#define SET_APE_PERI_BMC_TO_NC_RX_STATUS_PACKET_LENGTH(__val__)  (((__val__) << 16u) & 0x7ff0000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcRxStatus. */
typedef register_container RegAPE_PERIBmcToNcRxStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, New, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bad, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Passthru, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, SAHitValid, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, VLAN, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Underflow, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, EndOfFrame, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, InProgress, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Flushing, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, FlushDone, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, SAhit, 10, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_15, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, PacketLength, 16, 11)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_27, 27, 5)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_27, 27, 5)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, PacketLength, 16, 11)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_15, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, SAhit, 10, 5)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, FlushDone, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Flushing, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, InProgress, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, EndOfFrame, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Underflow, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, VLAN, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, SAHitValid, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Passthru, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bad, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, New, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcRxStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcRxStatus_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcRxStatus. */
        r32.setName("BmcToNcRxStatus");
        bits.New.setBaseRegister(&r32);
        bits.New.setName("New");
        bits.Bad.setBaseRegister(&r32);
        bits.Bad.setName("Bad");
        bits.Passthru.setBaseRegister(&r32);
        bits.Passthru.setName("Passthru");
        bits.SAHitValid.setBaseRegister(&r32);
        bits.SAHitValid.setName("SAHitValid");
        bits.VLAN.setBaseRegister(&r32);
        bits.VLAN.setName("VLAN");
        bits.Underflow.setBaseRegister(&r32);
        bits.Underflow.setName("Underflow");
        bits.EndOfFrame.setBaseRegister(&r32);
        bits.EndOfFrame.setName("EndOfFrame");
        bits.InProgress.setBaseRegister(&r32);
        bits.InProgress.setName("InProgress");
        bits.Flushing.setBaseRegister(&r32);
        bits.Flushing.setName("Flushing");
        bits.FlushDone.setBaseRegister(&r32);
        bits.FlushDone.setName("FlushDone");
        bits.SAhit.setBaseRegister(&r32);
        bits.SAhit.setName("SAhit");
        bits.PacketLength.setBaseRegister(&r32);
        bits.PacketLength.setName("PacketLength");
    }
    RegAPE_PERIBmcToNcRxStatus_t& operator=(const RegAPE_PERIBmcToNcRxStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcRxStatus_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_HIGH ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018304) /* Upper four bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_HIGH_HIGH_SHIFT 0u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_HIGH_HIGH_MASK  0xffffffffu
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_HIGH_HIGH(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_HIGH_HIGH(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacHigh. */
typedef register_container RegAPE_PERIBmcToNcSourceMacHigh_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacHigh"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacHigh_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacHigh. */
        r32.setName("BmcToNcSourceMacHigh");
        bits.High.setBaseRegister(&r32);
        bits.High.setName("High");
    }
    RegAPE_PERIBmcToNcSourceMacHigh_t& operator=(const RegAPE_PERIBmcToNcSourceMacHigh_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacHigh_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_LOW ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018308) /* Lower two bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_LOW_LOW_SHIFT 16u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_LOW_LOW_MASK  0xffff0000u
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_LOW_LOW(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_LOW_LOW(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacLow. */
typedef register_container RegAPE_PERIBmcToNcSourceMacLow_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacLow"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacLow_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacLow. */
        r32.setName("BmcToNcSourceMacLow");
        bits.Low.setBaseRegister(&r32);
        bits.Low.setName("Low");
    }
    RegAPE_PERIBmcToNcSourceMacLow_t& operator=(const RegAPE_PERIBmcToNcSourceMacLow_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacLow_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_0_HIGH ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc001830c) /* Upper four bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_0_HIGH_HIGH_SHIFT 0u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_0_HIGH_HIGH_MASK  0xffffffffu
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_0_HIGH_HIGH(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_0_HIGH_HIGH(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch0High. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch0High_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch0High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch0High_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch0High. */
        r32.setName("BmcToNcSourceMacMatch0High");
        bits.High.setBaseRegister(&r32);
        bits.High.setName("High");
    }
    RegAPE_PERIBmcToNcSourceMacMatch0High_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch0High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch0High_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_0_LOW ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018310) /* Lower two bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_0_LOW_LOW_SHIFT 16u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_0_LOW_LOW_MASK  0xffff0000u
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_0_LOW_LOW(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_0_LOW_LOW(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch0Low. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch0Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch0Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch0Low_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch0Low. */
        r32.setName("BmcToNcSourceMacMatch0Low");
        bits.Low.setBaseRegister(&r32);
        bits.Low.setName("Low");
    }
    RegAPE_PERIBmcToNcSourceMacMatch0Low_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch0Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch0Low_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_1_HIGH ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018314) /* Upper four bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_1_HIGH_HIGH_SHIFT 0u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_1_HIGH_HIGH_MASK  0xffffffffu
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_1_HIGH_HIGH(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_1_HIGH_HIGH(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch1High. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch1High_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch1High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch1High_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch1High. */
        r32.setName("BmcToNcSourceMacMatch1High");
        bits.High.setBaseRegister(&r32);
        bits.High.setName("High");
    }
    RegAPE_PERIBmcToNcSourceMacMatch1High_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch1High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch1High_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_1_LOW ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018318) /* Lower two bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_1_LOW_LOW_SHIFT 16u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_1_LOW_LOW_MASK  0xffff0000u
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_1_LOW_LOW(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_1_LOW_LOW(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch1Low. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch1Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch1Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch1Low_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch1Low. */
        r32.setName("BmcToNcSourceMacMatch1Low");
        bits.Low.setBaseRegister(&r32);
        bits.Low.setName("Low");
    }
    RegAPE_PERIBmcToNcSourceMacMatch1Low_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch1Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch1Low_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_2_HIGH ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc001831c) /* Upper four bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_2_HIGH_HIGH_SHIFT 0u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_2_HIGH_HIGH_MASK  0xffffffffu
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_2_HIGH_HIGH(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_2_HIGH_HIGH(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch2High. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch2High_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch2High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch2High_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch2High. */
        r32.setName("BmcToNcSourceMacMatch2High");
        bits.High.setBaseRegister(&r32);
        bits.High.setName("High");
    }
    RegAPE_PERIBmcToNcSourceMacMatch2High_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch2High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch2High_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_2_LOW ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018320) /* Lower two bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_2_LOW_LOW_SHIFT 16u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_2_LOW_LOW_MASK  0xffff0000u
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_2_LOW_LOW(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_2_LOW_LOW(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch2Low. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch2Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch2Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch2Low_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch2Low. */
        r32.setName("BmcToNcSourceMacMatch2Low");
        bits.Low.setBaseRegister(&r32);
        bits.Low.setName("Low");
    }
    RegAPE_PERIBmcToNcSourceMacMatch2Low_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch2Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch2Low_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_3_HIGH ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018324) /* Upper four bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_3_HIGH_HIGH_SHIFT 0u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_3_HIGH_HIGH_MASK  0xffffffffu
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_3_HIGH_HIGH(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_3_HIGH_HIGH(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch3High. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch3High_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch3High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch3High_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch3High. */
        r32.setName("BmcToNcSourceMacMatch3High");
        bits.High.setBaseRegister(&r32);
        bits.High.setName("High");
    }
    RegAPE_PERIBmcToNcSourceMacMatch3High_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch3High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch3High_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_3_LOW ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018328) /* Lower two bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_3_LOW_LOW_SHIFT 16u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_3_LOW_LOW_MASK  0xffff0000u
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_3_LOW_LOW(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_3_LOW_LOW(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch3Low. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch3Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch3Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch3Low_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch3Low. */
        r32.setName("BmcToNcSourceMacMatch3Low");
        bits.Low.setBaseRegister(&r32);
        bits.Low.setName("Low");
    }
    RegAPE_PERIBmcToNcSourceMacMatch3Low_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch3Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch3Low_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_4_HIGH ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc001832c) /* Upper four bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_4_HIGH_HIGH_SHIFT 0u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_4_HIGH_HIGH_MASK  0xffffffffu
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_4_HIGH_HIGH(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_4_HIGH_HIGH(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch4High. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch4High_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch4High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch4High_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch4High. */
        r32.setName("BmcToNcSourceMacMatch4High");
        bits.High.setBaseRegister(&r32);
        bits.High.setName("High");
    }
    RegAPE_PERIBmcToNcSourceMacMatch4High_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch4High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch4High_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_4_LOW ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018330) /* Lower two bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_4_LOW_LOW_SHIFT 16u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_4_LOW_LOW_MASK  0xffff0000u
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_4_LOW_LOW(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_4_LOW_LOW(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch4Low. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch4Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch4Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch4Low_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch4Low. */
        r32.setName("BmcToNcSourceMacMatch4Low");
        bits.Low.setBaseRegister(&r32);
        bits.Low.setName("Low");
    }
    RegAPE_PERIBmcToNcSourceMacMatch4Low_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch4Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch4Low_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_5_HIGH ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018334) /* Upper four bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_5_HIGH_HIGH_SHIFT 0u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_5_HIGH_HIGH_MASK  0xffffffffu
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_5_HIGH_HIGH(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_5_HIGH_HIGH(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch5High. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch5High_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch5High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch5High_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch5High. */
        r32.setName("BmcToNcSourceMacMatch5High");
        bits.High.setBaseRegister(&r32);
        bits.High.setName("High");
    }
    RegAPE_PERIBmcToNcSourceMacMatch5High_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch5High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch5High_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_5_LOW ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018338) /* Lower two bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_5_LOW_LOW_SHIFT 16u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_5_LOW_LOW_MASK  0xffff0000u
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_5_LOW_LOW(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_5_LOW_LOW(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch5Low. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch5Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch5Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch5Low_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch5Low. */
        r32.setName("BmcToNcSourceMacMatch5Low");
        bits.Low.setBaseRegister(&r32);
        bits.Low.setName("Low");
    }
    RegAPE_PERIBmcToNcSourceMacMatch5Low_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch5Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch5Low_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_6_HIGH ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc001833c) /* Upper four bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_6_HIGH_HIGH_SHIFT 0u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_6_HIGH_HIGH_MASK  0xffffffffu
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_6_HIGH_HIGH(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_6_HIGH_HIGH(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch6High. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch6High_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch6High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch6High_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch6High. */
        r32.setName("BmcToNcSourceMacMatch6High");
        bits.High.setBaseRegister(&r32);
        bits.High.setName("High");
    }
    RegAPE_PERIBmcToNcSourceMacMatch6High_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch6High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch6High_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_6_LOW ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018340) /* Lower two bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_6_LOW_LOW_SHIFT 16u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_6_LOW_LOW_MASK  0xffff0000u
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_6_LOW_LOW(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_6_LOW_LOW(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch6Low. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch6Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch6Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch6Low_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch6Low. */
        r32.setName("BmcToNcSourceMacMatch6Low");
        bits.Low.setBaseRegister(&r32);
        bits.Low.setName("Low");
    }
    RegAPE_PERIBmcToNcSourceMacMatch6Low_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch6Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch6Low_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_7_HIGH ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018344) /* Upper four bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_7_HIGH_HIGH_SHIFT 0u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_7_HIGH_HIGH_MASK  0xffffffffu
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_7_HIGH_HIGH(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_7_HIGH_HIGH(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch7High. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch7High_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Upper four bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, High, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch7High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch7High_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch7High. */
        r32.setName("BmcToNcSourceMacMatch7High");
        bits.High.setBaseRegister(&r32);
        bits.High.setName("High");
    }
    RegAPE_PERIBmcToNcSourceMacMatch7High_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch7High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch7High_t;

#define REG_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_7_LOW ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018348) /* Lower two bytes of the MAC */
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_7_LOW_LOW_SHIFT 16u
#define     APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_7_LOW_LOW_MASK  0xffff0000u
#define GET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_7_LOW_LOW(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_APE_PERI_BMC_TO_NC_SOURCE_MAC_MATCH_7_LOW_LOW(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcSourceMacMatch7Low. */
typedef register_container RegAPE_PERIBmcToNcSourceMacMatch7Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Lower two bytes of the MAC */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Low, 16, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcSourceMacMatch7Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcSourceMacMatch7Low_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcSourceMacMatch7Low. */
        r32.setName("BmcToNcSourceMacMatch7Low");
        bits.Low.setBaseRegister(&r32);
        bits.Low.setName("Low");
    }
    RegAPE_PERIBmcToNcSourceMacMatch7Low_t& operator=(const RegAPE_PERIBmcToNcSourceMacMatch7Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcSourceMacMatch7Low_t;

#define REG_APE_PERI_BMC_TO_NC_RX_VLAN ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc001834c) /*  */
#define     APE_PERI_BMC_TO_NC_RX_VLAN_VLAN_SHIFT 16u
#define     APE_PERI_BMC_TO_NC_RX_VLAN_VLAN_MASK  0xffff0000u
#define GET_APE_PERI_BMC_TO_NC_RX_VLAN_VLAN(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_APE_PERI_BMC_TO_NC_RX_VLAN_VLAN(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcRxVlan. */
typedef register_container RegAPE_PERIBmcToNcRxVlan_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, VLAN, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, VLAN, 16, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_0, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcRxVlan"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcRxVlan_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcRxVlan. */
        r32.setName("BmcToNcRxVlan");
        bits.VLAN.setBaseRegister(&r32);
        bits.VLAN.setName("VLAN");
    }
    RegAPE_PERIBmcToNcRxVlan_t& operator=(const RegAPE_PERIBmcToNcRxVlan_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcRxVlan_t;

#define REG_APE_PERI_BMC_TO_NC_READ_BUFFER ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018350) /*  */
/** @brief Register definition for @ref APE_PERI_t.BmcToNcReadBuffer. */
typedef register_container RegAPE_PERIBmcToNcReadBuffer_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcReadBuffer"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcReadBuffer_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcReadBuffer. */
        r32.setName("BmcToNcReadBuffer");
    }
    RegAPE_PERIBmcToNcReadBuffer_t& operator=(const RegAPE_PERIBmcToNcReadBuffer_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcReadBuffer_t;

#define REG_APE_PERI_BMC_TO_NC_RX_CONTROL ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018354) /*  */
#define     APE_PERI_BMC_TO_NC_RX_CONTROL_HWM_SHIFT 0u
#define     APE_PERI_BMC_TO_NC_RX_CONTROL_HWM_MASK  0x7ffu
#define GET_APE_PERI_BMC_TO_NC_RX_CONTROL_HWM(__reg__)  (((__reg__) & 0x7ff) >> 0u)
#define SET_APE_PERI_BMC_TO_NC_RX_CONTROL_HWM(__val__)  (((__val__) << 0u) & 0x7ffu)
#define     APE_PERI_BMC_TO_NC_RX_CONTROL_FLOW_CONTROL_SHIFT 24u
#define     APE_PERI_BMC_TO_NC_RX_CONTROL_FLOW_CONTROL_MASK  0x1000000u
#define GET_APE_PERI_BMC_TO_NC_RX_CONTROL_FLOW_CONTROL(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_APE_PERI_BMC_TO_NC_RX_CONTROL_FLOW_CONTROL(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     APE_PERI_BMC_TO_NC_RX_CONTROL_RESET_BAD_SHIFT 25u
#define     APE_PERI_BMC_TO_NC_RX_CONTROL_RESET_BAD_MASK  0x2000000u
#define GET_APE_PERI_BMC_TO_NC_RX_CONTROL_RESET_BAD(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_APE_PERI_BMC_TO_NC_RX_CONTROL_RESET_BAD(__val__)  (((__val__) << 25u) & 0x2000000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcRxControl. */
typedef register_container RegAPE_PERIBmcToNcRxControl_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, HWM, 0, 11)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_23_11, 11, 13)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, FlowControl, 24, 1)
        /** @brief Or'd after receiving Status.Bad frame */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, ResetBad, 25, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_26, 26, 6)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_26, 26, 6)
        /** @brief Or'd after receiving Status.Bad frame */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, ResetBad, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, FlowControl, 24, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_23_11, 11, 13)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, HWM, 0, 11)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcRxControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcRxControl_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcRxControl. */
        r32.setName("BmcToNcRxControl");
        bits.HWM.setBaseRegister(&r32);
        bits.HWM.setName("HWM");
        bits.FlowControl.setBaseRegister(&r32);
        bits.FlowControl.setName("FlowControl");
        bits.ResetBad.setBaseRegister(&r32);
        bits.ResetBad.setName("ResetBad");
    }
    RegAPE_PERIBmcToNcRxControl_t& operator=(const RegAPE_PERIBmcToNcRxControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcRxControl_t;

#define REG_APE_PERI_BMC_TO_NC_RX_STATUS_1 ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018358) /*  */
/** @brief Register definition for @ref APE_PERI_t.BmcToNcRxStatus1. */
typedef register_container RegAPE_PERIBmcToNcRxStatus1_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcRxStatus1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcRxStatus1_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcRxStatus1. */
        r32.setName("BmcToNcRxStatus1");
    }
    RegAPE_PERIBmcToNcRxStatus1_t& operator=(const RegAPE_PERIBmcToNcRxStatus1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcRxStatus1_t;

#define REG_APE_PERI_BMC_TO_NC_RX_STATUS_2 ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc001835c) /*  */
/** @brief Register definition for @ref APE_PERI_t.BmcToNcRxStatus2. */
typedef register_container RegAPE_PERIBmcToNcRxStatus2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcRxStatus2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcRxStatus2_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcRxStatus2. */
        r32.setName("BmcToNcRxStatus2");
    }
    RegAPE_PERIBmcToNcRxStatus2_t& operator=(const RegAPE_PERIBmcToNcRxStatus2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcRxStatus2_t;

#define REG_APE_PERI_BMC_TO_NC_TX_STATUS ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018370) /*  */
#define     APE_PERI_BMC_TO_NC_TX_STATUS_UNDERRUN_SHIFT 0u
#define     APE_PERI_BMC_TO_NC_TX_STATUS_UNDERRUN_MASK  0x1u
#define GET_APE_PERI_BMC_TO_NC_TX_STATUS_UNDERRUN(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_BMC_TO_NC_TX_STATUS_UNDERRUN(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_BMC_TO_NC_TX_STATUS_HIT_LWM_SHIFT 1u
#define     APE_PERI_BMC_TO_NC_TX_STATUS_HIT_LWM_MASK  0x2u
#define GET_APE_PERI_BMC_TO_NC_TX_STATUS_HIT_LWM(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_BMC_TO_NC_TX_STATUS_HIT_LWM(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_BMC_TO_NC_TX_STATUS_EMPTY_SHIFT 2u
#define     APE_PERI_BMC_TO_NC_TX_STATUS_EMPTY_MASK  0x4u
#define GET_APE_PERI_BMC_TO_NC_TX_STATUS_EMPTY(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_BMC_TO_NC_TX_STATUS_EMPTY(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_BMC_TO_NC_TX_STATUS_FULL_SHIFT 3u
#define     APE_PERI_BMC_TO_NC_TX_STATUS_FULL_MASK  0x8u
#define GET_APE_PERI_BMC_TO_NC_TX_STATUS_FULL(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_BMC_TO_NC_TX_STATUS_FULL(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_BMC_TO_NC_TX_STATUS_LAST_FULL_COUNT_SHIFT 4u
#define     APE_PERI_BMC_TO_NC_TX_STATUS_LAST_FULL_COUNT_MASK  0x10u
#define GET_APE_PERI_BMC_TO_NC_TX_STATUS_LAST_FULL_COUNT(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_BMC_TO_NC_TX_STATUS_LAST_FULL_COUNT(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_BMC_TO_NC_TX_STATUS_IN_FIFO_SHIFT 16u
#define     APE_PERI_BMC_TO_NC_TX_STATUS_IN_FIFO_MASK  0x7ff0000u
#define GET_APE_PERI_BMC_TO_NC_TX_STATUS_IN_FIFO(__reg__)  (((__reg__) & 0x7ff0000) >> 16u)
#define SET_APE_PERI_BMC_TO_NC_TX_STATUS_IN_FIFO(__val__)  (((__val__) << 16u) & 0x7ff0000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcTxStatus. */
typedef register_container RegAPE_PERIBmcToNcTxStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Underrun, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, HitLWM, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Empty, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Full, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, LastFullCount, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_5, 5, 11)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, InFifo, 16, 11)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_27, 27, 5)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_27, 27, 5)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, InFifo, 16, 11)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_5, 5, 11)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, LastFullCount, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Full, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Empty, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, HitLWM, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Underrun, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcTxStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcTxStatus_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcTxStatus. */
        r32.setName("BmcToNcTxStatus");
        bits.Underrun.setBaseRegister(&r32);
        bits.Underrun.setName("Underrun");
        bits.HitLWM.setBaseRegister(&r32);
        bits.HitLWM.setName("HitLWM");
        bits.Empty.setBaseRegister(&r32);
        bits.Empty.setName("Empty");
        bits.Full.setBaseRegister(&r32);
        bits.Full.setName("Full");
        bits.LastFullCount.setBaseRegister(&r32);
        bits.LastFullCount.setName("LastFullCount");
        bits.InFifo.setBaseRegister(&r32);
        bits.InFifo.setName("InFifo");
    }
    RegAPE_PERIBmcToNcTxStatus_t& operator=(const RegAPE_PERIBmcToNcTxStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcTxStatus_t;

#define REG_APE_PERI_BMC_TO_NC_TX_CONTROL ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018374) /*  */
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_UNDERRUN_SHIFT 0u
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_UNDERRUN_MASK  0x1u
#define GET_APE_PERI_BMC_TO_NC_TX_CONTROL_UNDERRUN(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_BMC_TO_NC_TX_CONTROL_UNDERRUN(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_HIT_LWM_SHIFT 1u
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_HIT_LWM_MASK  0x2u
#define GET_APE_PERI_BMC_TO_NC_TX_CONTROL_HIT_LWM(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_BMC_TO_NC_TX_CONTROL_HIT_LWM(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_EMPTY_SHIFT 2u
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_EMPTY_MASK  0x4u
#define GET_APE_PERI_BMC_TO_NC_TX_CONTROL_EMPTY(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_BMC_TO_NC_TX_CONTROL_EMPTY(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_FULL_SHIFT 3u
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_FULL_MASK  0x8u
#define GET_APE_PERI_BMC_TO_NC_TX_CONTROL_FULL(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_BMC_TO_NC_TX_CONTROL_FULL(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_LAST_FULL_COUNT_SHIFT 4u
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_LAST_FULL_COUNT_MASK  0x10u
#define GET_APE_PERI_BMC_TO_NC_TX_CONTROL_LAST_FULL_COUNT(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_BMC_TO_NC_TX_CONTROL_LAST_FULL_COUNT(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_STORE_FORWARD_SHIFT 8u
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_STORE_FORWARD_MASK  0x100u
#define GET_APE_PERI_BMC_TO_NC_TX_CONTROL_STORE_FORWARD(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_APE_PERI_BMC_TO_NC_TX_CONTROL_STORE_FORWARD(__val__)  (((__val__) << 8u) & 0x100u)
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_POISON_SHIFT 9u
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_POISON_MASK  0x200u
#define GET_APE_PERI_BMC_TO_NC_TX_CONTROL_POISON(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_APE_PERI_BMC_TO_NC_TX_CONTROL_POISON(__val__)  (((__val__) << 9u) & 0x200u)
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_XOFF_SHIFT 10u
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_XOFF_MASK  0x400u
#define GET_APE_PERI_BMC_TO_NC_TX_CONTROL_XOFF(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_APE_PERI_BMC_TO_NC_TX_CONTROL_XOFF(__val__)  (((__val__) << 10u) & 0x400u)
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_LAST_BYTE_COUNT_SHIFT 11u
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_LAST_BYTE_COUNT_MASK  0x1800u
#define GET_APE_PERI_BMC_TO_NC_TX_CONTROL_LAST_BYTE_COUNT(__reg__)  (((__reg__) & 0x1800) >> 11u)
#define SET_APE_PERI_BMC_TO_NC_TX_CONTROL_LAST_BYTE_COUNT(__val__)  (((__val__) << 11u) & 0x1800u)
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_LWM_SHIFT 16u
#define     APE_PERI_BMC_TO_NC_TX_CONTROL_LWM_MASK  0x7ff0000u
#define GET_APE_PERI_BMC_TO_NC_TX_CONTROL_LWM(__reg__)  (((__reg__) & 0x7ff0000) >> 16u)
#define SET_APE_PERI_BMC_TO_NC_TX_CONTROL_LWM(__val__)  (((__val__) << 16u) & 0x7ff0000u)

/** @brief Register definition for @ref APE_PERI_t.BmcToNcTxControl. */
typedef register_container RegAPE_PERIBmcToNcTxControl_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Underrun, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, HitLWM, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Empty, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Full, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, LastFullCount, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, StoreForward, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Poison, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, XOFF, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, LastByteCount, 11, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_13, 13, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, LWM, 16, 11)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_27, 27, 5)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_27, 27, 5)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, LWM, 16, 11)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_13, 13, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, LastByteCount, 11, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, XOFF, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Poison, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, StoreForward, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, LastFullCount, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Full, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Empty, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, HitLWM, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Underrun, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcTxControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcTxControl_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcTxControl. */
        r32.setName("BmcToNcTxControl");
        bits.Underrun.setBaseRegister(&r32);
        bits.Underrun.setName("Underrun");
        bits.HitLWM.setBaseRegister(&r32);
        bits.HitLWM.setName("HitLWM");
        bits.Empty.setBaseRegister(&r32);
        bits.Empty.setName("Empty");
        bits.Full.setBaseRegister(&r32);
        bits.Full.setName("Full");
        bits.LastFullCount.setBaseRegister(&r32);
        bits.LastFullCount.setName("LastFullCount");
        bits.StoreForward.setBaseRegister(&r32);
        bits.StoreForward.setName("StoreForward");
        bits.Poison.setBaseRegister(&r32);
        bits.Poison.setName("Poison");
        bits.XOFF.setBaseRegister(&r32);
        bits.XOFF.setName("XOFF");
        bits.LastByteCount.setBaseRegister(&r32);
        bits.LastByteCount.setName("LastByteCount");
        bits.LWM.setBaseRegister(&r32);
        bits.LWM.setName("LWM");
    }
    RegAPE_PERIBmcToNcTxControl_t& operator=(const RegAPE_PERIBmcToNcTxControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcTxControl_t;

#define REG_APE_PERI_BMC_TO_NC_TX_BUFFER ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018378) /*  */
/** @brief Register definition for @ref APE_PERI_t.BmcToNcTxBuffer. */
typedef register_container RegAPE_PERIBmcToNcTxBuffer_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcTxBuffer"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcTxBuffer_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcTxBuffer. */
        r32.setName("BmcToNcTxBuffer");
    }
    RegAPE_PERIBmcToNcTxBuffer_t& operator=(const RegAPE_PERIBmcToNcTxBuffer_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcTxBuffer_t;

#define REG_APE_PERI_BMC_TO_NC_TX_BUFFER_LAST ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc001837c) /*  */
/** @brief Register definition for @ref APE_PERI_t.BmcToNcTxBufferLast. */
typedef register_container RegAPE_PERIBmcToNcTxBufferLast_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcTxBufferLast"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcTxBufferLast_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcTxBufferLast. */
        r32.setName("BmcToNcTxBufferLast");
    }
    RegAPE_PERIBmcToNcTxBufferLast_t& operator=(const RegAPE_PERIBmcToNcTxBufferLast_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcTxBufferLast_t;

#define REG_APE_PERI_BMC_TO_NC_TX_STATUS_1 ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018380) /*  */
/** @brief Register definition for @ref APE_PERI_t.BmcToNcTxStatus1. */
typedef register_container RegAPE_PERIBmcToNcTxStatus1_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BmcToNcTxStatus1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIBmcToNcTxStatus1_t()
    {
        /** @brief constructor for @ref APE_PERI_t.BmcToNcTxStatus1. */
        r32.setName("BmcToNcTxStatus1");
    }
    RegAPE_PERIBmcToNcTxStatus1_t& operator=(const RegAPE_PERIBmcToNcTxStatus1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIBmcToNcTxStatus1_t;

#define REG_APE_PERI_RMU_CONTROL ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc00183a0) /*  */
#define     APE_PERI_RMU_CONTROL_RESET_TX_SHIFT 0u
#define     APE_PERI_RMU_CONTROL_RESET_TX_MASK  0x1u
#define GET_APE_PERI_RMU_CONTROL_RESET_TX(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_RMU_CONTROL_RESET_TX(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_RMU_CONTROL_RESET_RX_SHIFT 1u
#define     APE_PERI_RMU_CONTROL_RESET_RX_MASK  0x2u
#define GET_APE_PERI_RMU_CONTROL_RESET_RX(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_RMU_CONTROL_RESET_RX(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_RMU_CONTROL_AUTO_DRV_SHIFT 2u
#define     APE_PERI_RMU_CONTROL_AUTO_DRV_MASK  0x4u
#define GET_APE_PERI_RMU_CONTROL_AUTO_DRV(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_RMU_CONTROL_AUTO_DRV(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_RMU_CONTROL_TX_DRV_SHIFT 3u
#define     APE_PERI_RMU_CONTROL_TX_DRV_MASK  0x8u
#define GET_APE_PERI_RMU_CONTROL_TX_DRV(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_RMU_CONTROL_TX_DRV(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_RMU_CONTROL_LPBK_SHIFT 4u
#define     APE_PERI_RMU_CONTROL_LPBK_MASK  0x10u
#define GET_APE_PERI_RMU_CONTROL_LPBK(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_RMU_CONTROL_LPBK(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_RMU_CONTROL_TX_SHIFT 5u
#define     APE_PERI_RMU_CONTROL_TX_MASK  0x20u
#define GET_APE_PERI_RMU_CONTROL_TX(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_PERI_RMU_CONTROL_TX(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_PERI_RMU_CONTROL_RX_SHIFT 6u
#define     APE_PERI_RMU_CONTROL_RX_MASK  0x40u
#define GET_APE_PERI_RMU_CONTROL_RX(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_PERI_RMU_CONTROL_RX(__val__)  (((__val__) << 6u) & 0x40u)

/** @brief Register definition for @ref APE_PERI_t.RmuControl. */
typedef register_container RegAPE_PERIRmuControl_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, ResetTX, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, ResetRX, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, AutoDrv, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, TXDrv, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, LPBK, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, TX, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, RX, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_7, 7, 25)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_7, 7, 25)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, RX, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, TX, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, LPBK, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, TXDrv, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, AutoDrv, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, ResetRX, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, ResetTX, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RmuControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIRmuControl_t()
    {
        /** @brief constructor for @ref APE_PERI_t.RmuControl. */
        r32.setName("RmuControl");
        bits.ResetTX.setBaseRegister(&r32);
        bits.ResetTX.setName("ResetTX");
        bits.ResetRX.setBaseRegister(&r32);
        bits.ResetRX.setName("ResetRX");
        bits.AutoDrv.setBaseRegister(&r32);
        bits.AutoDrv.setName("AutoDrv");
        bits.TXDrv.setBaseRegister(&r32);
        bits.TXDrv.setName("TXDrv");
        bits.LPBK.setBaseRegister(&r32);
        bits.LPBK.setName("LPBK");
        bits.TX.setBaseRegister(&r32);
        bits.TX.setName("TX");
        bits.RX.setBaseRegister(&r32);
        bits.RX.setName("RX");
    }
    RegAPE_PERIRmuControl_t& operator=(const RegAPE_PERIRmuControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIRmuControl_t;

#define REG_APE_PERI_ARB_CONTROL ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc00183a4) /*  */
#define     APE_PERI_ARB_CONTROL_PACKAGE_ID_SHIFT 0u
#define     APE_PERI_ARB_CONTROL_PACKAGE_ID_MASK  0x7u
#define GET_APE_PERI_ARB_CONTROL_PACKAGE_ID(__reg__)  (((__reg__) & 0x7) >> 0u)
#define SET_APE_PERI_ARB_CONTROL_PACKAGE_ID(__val__)  (((__val__) << 0u) & 0x7u)
#define     APE_PERI_ARB_CONTROL_DISABLE_SHIFT 3u
#define     APE_PERI_ARB_CONTROL_DISABLE_MASK  0x8u
#define GET_APE_PERI_ARB_CONTROL_DISABLE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_ARB_CONTROL_DISABLE(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_ARB_CONTROL_START_SHIFT 4u
#define     APE_PERI_ARB_CONTROL_START_MASK  0x10u
#define GET_APE_PERI_ARB_CONTROL_START(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_ARB_CONTROL_START(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_ARB_CONTROL_BYPASS_SHIFT 5u
#define     APE_PERI_ARB_CONTROL_BYPASS_MASK  0x20u
#define GET_APE_PERI_ARB_CONTROL_BYPASS(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_PERI_ARB_CONTROL_BYPASS(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_PERI_ARB_CONTROL_ARB_BYPASS_SHIFT 6u
#define     APE_PERI_ARB_CONTROL_ARB_BYPASS_MASK  0x40u
#define GET_APE_PERI_ARB_CONTROL_ARB_BYPASS(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_PERI_ARB_CONTROL_ARB_BYPASS(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_PERI_ARB_CONTROL_XOFF_DISABLE_SHIFT 7u
#define     APE_PERI_ARB_CONTROL_XOFF_DISABLE_MASK  0x80u
#define GET_APE_PERI_ARB_CONTROL_XOFF_DISABLE(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_APE_PERI_ARB_CONTROL_XOFF_DISABLE(__val__)  (((__val__) << 7u) & 0x80u)
#define     APE_PERI_ARB_CONTROL_TKNREL_SHIFT 8u
#define     APE_PERI_ARB_CONTROL_TKNREL_MASK  0x1f00u
#define GET_APE_PERI_ARB_CONTROL_TKNREL(__reg__)  (((__reg__) & 0x1f00) >> 8u)
#define SET_APE_PERI_ARB_CONTROL_TKNREL(__val__)  (((__val__) << 8u) & 0x1f00u)
#define     APE_PERI_ARB_CONTROL_TO_SHIFT 16u
#define     APE_PERI_ARB_CONTROL_TO_MASK  0xffff0000u
#define GET_APE_PERI_ARB_CONTROL_TO(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_APE_PERI_ARB_CONTROL_TO(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref APE_PERI_t.ArbControl. */
typedef register_container RegAPE_PERIArbControl_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief NC-SI Package ID */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, PackageID, 0, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Disable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Start, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bypass, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, ARBBypass, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, XOFFDisable, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, TKNREL, 8, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_13, 13, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, TO, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, TO, 16, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_15_13, 13, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, TKNREL, 8, 5)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, XOFFDisable, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, ARBBypass, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bypass, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Start, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Disable, 3, 1)
        /** @brief NC-SI Package ID */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, PackageID, 0, 3)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ArbControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIArbControl_t()
    {
        /** @brief constructor for @ref APE_PERI_t.ArbControl. */
        r32.setName("ArbControl");
        bits.PackageID.setBaseRegister(&r32);
        bits.PackageID.setName("PackageID");
        bits.Disable.setBaseRegister(&r32);
        bits.Disable.setName("Disable");
        bits.Start.setBaseRegister(&r32);
        bits.Start.setName("Start");
        bits.Bypass.setBaseRegister(&r32);
        bits.Bypass.setName("Bypass");
        bits.ARBBypass.setBaseRegister(&r32);
        bits.ARBBypass.setName("ARBBypass");
        bits.XOFFDisable.setBaseRegister(&r32);
        bits.XOFFDisable.setName("XOFFDisable");
        bits.TKNREL.setBaseRegister(&r32);
        bits.TKNREL.setName("TKNREL");
        bits.TO.setBaseRegister(&r32);
        bits.TO.setName("TO");
    }
    RegAPE_PERIArbControl_t& operator=(const RegAPE_PERIArbControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIArbControl_t;

#define REG_APE_PERI_PER_LOCK_REQUEST_PHY0 ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018400) /* This register, and the following Per Lock Request registers work the same. The tg3 driver uses 0x0000_1000 (APELOCK_PER_REQ_DRIVER) for PHY ports (or always for function 0). */
#define     APE_PERI_PER_LOCK_REQUEST_PHY0_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_REQUEST_PHY0_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY0_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY0_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY0_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_REQUEST_PHY0_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY0_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY0_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY0_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_REQUEST_PHY0_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY0_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY0_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY0_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_REQUEST_PHY0_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY0_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY0_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY0_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_REQUEST_PHY0_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY0_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY0_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY0_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_REQUEST_PHY0_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY0_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY0_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockRequestPhy0. */
typedef register_container RegAPE_PERIPerLockRequestPhy0_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestPhy0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockRequestPhy0_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockRequestPhy0. */
        r32.setName("PerLockRequestPhy0");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockRequestPhy0_t& operator=(const RegAPE_PERIPerLockRequestPhy0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockRequestPhy0_t;

#define REG_APE_PERI_PER_LOCK_REQUEST_GRC ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018404) /*  */
#define     APE_PERI_PER_LOCK_REQUEST_GRC_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_REQUEST_GRC_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_REQUEST_GRC_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_REQUEST_GRC_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_REQUEST_GRC_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_REQUEST_GRC_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_REQUEST_GRC_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_REQUEST_GRC_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_REQUEST_GRC_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_REQUEST_GRC_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_REQUEST_GRC_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_REQUEST_GRC_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_REQUEST_GRC_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_REQUEST_GRC_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_REQUEST_GRC_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_REQUEST_GRC_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_REQUEST_GRC_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_REQUEST_GRC_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_REQUEST_GRC_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_REQUEST_GRC_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_REQUEST_GRC_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_REQUEST_GRC_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_REQUEST_GRC_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_REQUEST_GRC_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockRequestGrc. */
typedef register_container RegAPE_PERIPerLockRequestGrc_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestGrc"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockRequestGrc_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockRequestGrc. */
        r32.setName("PerLockRequestGrc");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockRequestGrc_t& operator=(const RegAPE_PERIPerLockRequestGrc_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockRequestGrc_t;

#define REG_APE_PERI_PER_LOCK_REQUEST_PHY1 ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018408) /*  */
#define     APE_PERI_PER_LOCK_REQUEST_PHY1_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_REQUEST_PHY1_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY1_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY1_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY1_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_REQUEST_PHY1_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY1_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY1_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY1_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_REQUEST_PHY1_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY1_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY1_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY1_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_REQUEST_PHY1_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY1_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY1_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY1_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_REQUEST_PHY1_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY1_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY1_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY1_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_REQUEST_PHY1_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY1_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY1_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockRequestPhy1. */
typedef register_container RegAPE_PERIPerLockRequestPhy1_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestPhy1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockRequestPhy1_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockRequestPhy1. */
        r32.setName("PerLockRequestPhy1");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockRequestPhy1_t& operator=(const RegAPE_PERIPerLockRequestPhy1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockRequestPhy1_t;

#define REG_APE_PERI_PER_LOCK_REQUEST_PHY2 ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc001840c) /*  */
#define     APE_PERI_PER_LOCK_REQUEST_PHY2_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_REQUEST_PHY2_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY2_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY2_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY2_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_REQUEST_PHY2_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY2_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY2_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY2_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_REQUEST_PHY2_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY2_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY2_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY2_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_REQUEST_PHY2_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY2_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY2_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY2_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_REQUEST_PHY2_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY2_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY2_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY2_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_REQUEST_PHY2_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY2_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY2_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockRequestPhy2. */
typedef register_container RegAPE_PERIPerLockRequestPhy2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestPhy2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockRequestPhy2_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockRequestPhy2. */
        r32.setName("PerLockRequestPhy2");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockRequestPhy2_t& operator=(const RegAPE_PERIPerLockRequestPhy2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockRequestPhy2_t;

#define REG_APE_PERI_PER_LOCK_REQUEST_MEM ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018410) /*  */
#define     APE_PERI_PER_LOCK_REQUEST_MEM_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_REQUEST_MEM_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_REQUEST_MEM_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_REQUEST_MEM_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_REQUEST_MEM_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_REQUEST_MEM_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_REQUEST_MEM_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_REQUEST_MEM_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_REQUEST_MEM_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_REQUEST_MEM_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_REQUEST_MEM_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_REQUEST_MEM_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_REQUEST_MEM_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_REQUEST_MEM_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_REQUEST_MEM_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_REQUEST_MEM_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_REQUEST_MEM_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_REQUEST_MEM_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_REQUEST_MEM_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_REQUEST_MEM_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_REQUEST_MEM_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_REQUEST_MEM_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_REQUEST_MEM_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_REQUEST_MEM_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockRequestMem. */
typedef register_container RegAPE_PERIPerLockRequestMem_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestMem"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockRequestMem_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockRequestMem. */
        r32.setName("PerLockRequestMem");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockRequestMem_t& operator=(const RegAPE_PERIPerLockRequestMem_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockRequestMem_t;

#define REG_APE_PERI_PER_LOCK_REQUEST_PHY3 ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018414) /*  */
#define     APE_PERI_PER_LOCK_REQUEST_PHY3_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_REQUEST_PHY3_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY3_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY3_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY3_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_REQUEST_PHY3_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY3_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY3_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY3_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_REQUEST_PHY3_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY3_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY3_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY3_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_REQUEST_PHY3_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY3_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY3_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY3_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_REQUEST_PHY3_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY3_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY3_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_REQUEST_PHY3_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_REQUEST_PHY3_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_REQUEST_PHY3_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PHY3_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockRequestPhy3. */
typedef register_container RegAPE_PERIPerLockRequestPhy3_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestPhy3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockRequestPhy3_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockRequestPhy3. */
        r32.setName("PerLockRequestPhy3");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockRequestPhy3_t& operator=(const RegAPE_PERIPerLockRequestPhy3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockRequestPhy3_t;

#define REG_APE_PERI_PER_LOCK_REQUEST_PORT6 ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018418) /*  */
#define     APE_PERI_PER_LOCK_REQUEST_PORT6_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_REQUEST_PORT6_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_REQUEST_PORT6_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PORT6_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_REQUEST_PORT6_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_REQUEST_PORT6_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_REQUEST_PORT6_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PORT6_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_REQUEST_PORT6_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_REQUEST_PORT6_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_REQUEST_PORT6_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PORT6_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_REQUEST_PORT6_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_REQUEST_PORT6_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_REQUEST_PORT6_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PORT6_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_REQUEST_PORT6_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_REQUEST_PORT6_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_REQUEST_PORT6_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PORT6_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_REQUEST_PORT6_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_REQUEST_PORT6_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_REQUEST_PORT6_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_REQUEST_PORT6_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockRequestPort6. */
typedef register_container RegAPE_PERIPerLockRequestPort6_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestPort6"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockRequestPort6_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockRequestPort6. */
        r32.setName("PerLockRequestPort6");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockRequestPort6_t& operator=(const RegAPE_PERIPerLockRequestPort6_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockRequestPort6_t;

#define REG_APE_PERI_PER_LOCK_REQUEST_GPIO ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc001841c) /*  */
#define     APE_PERI_PER_LOCK_REQUEST_GPIO_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_REQUEST_GPIO_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_REQUEST_GPIO_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_REQUEST_GPIO_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_REQUEST_GPIO_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_REQUEST_GPIO_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_REQUEST_GPIO_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_REQUEST_GPIO_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_REQUEST_GPIO_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_REQUEST_GPIO_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_REQUEST_GPIO_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_REQUEST_GPIO_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_REQUEST_GPIO_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_REQUEST_GPIO_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_REQUEST_GPIO_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_REQUEST_GPIO_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_REQUEST_GPIO_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_REQUEST_GPIO_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_REQUEST_GPIO_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_REQUEST_GPIO_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_REQUEST_GPIO_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_REQUEST_GPIO_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_REQUEST_GPIO_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_REQUEST_GPIO_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockRequestGpio. */
typedef register_container RegAPE_PERIPerLockRequestGpio_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestGpio"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockRequestGpio_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockRequestGpio. */
        r32.setName("PerLockRequestGpio");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockRequestGpio_t& operator=(const RegAPE_PERIPerLockRequestGpio_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockRequestGpio_t;

#define REG_APE_PERI_PER_LOCK_GRANT_PHY0 ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018420) /*  */
#define     APE_PERI_PER_LOCK_GRANT_PHY0_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_GRANT_PHY0_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY0_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY0_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_GRANT_PHY0_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_GRANT_PHY0_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY0_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY0_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_GRANT_PHY0_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_GRANT_PHY0_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY0_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY0_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_GRANT_PHY0_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_GRANT_PHY0_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY0_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY0_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_GRANT_PHY0_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_GRANT_PHY0_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY0_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY0_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_GRANT_PHY0_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_GRANT_PHY0_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY0_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY0_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockGrantPhy0. */
typedef register_container RegAPE_PERIPerLockGrantPhy0_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantPhy0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockGrantPhy0_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockGrantPhy0. */
        r32.setName("PerLockGrantPhy0");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockGrantPhy0_t& operator=(const RegAPE_PERIPerLockGrantPhy0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockGrantPhy0_t;

#define REG_APE_PERI_PER_LOCK_GRANT_GRC ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018424) /*  */
#define     APE_PERI_PER_LOCK_GRANT_GRC_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_GRANT_GRC_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_GRANT_GRC_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_GRANT_GRC_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_GRANT_GRC_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_GRANT_GRC_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_GRANT_GRC_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_GRANT_GRC_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_GRANT_GRC_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_GRANT_GRC_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_GRANT_GRC_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_GRANT_GRC_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_GRANT_GRC_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_GRANT_GRC_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_GRANT_GRC_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_GRANT_GRC_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_GRANT_GRC_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_GRANT_GRC_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_GRANT_GRC_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_GRANT_GRC_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_GRANT_GRC_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_GRANT_GRC_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_GRANT_GRC_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_GRANT_GRC_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockGrantGrc. */
typedef register_container RegAPE_PERIPerLockGrantGrc_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantGrc"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockGrantGrc_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockGrantGrc. */
        r32.setName("PerLockGrantGrc");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockGrantGrc_t& operator=(const RegAPE_PERIPerLockGrantGrc_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockGrantGrc_t;

#define REG_APE_PERI_PER_LOCK_GRANT_PHY1 ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018428) /*  */
#define     APE_PERI_PER_LOCK_GRANT_PHY1_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_GRANT_PHY1_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY1_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY1_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_GRANT_PHY1_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_GRANT_PHY1_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY1_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY1_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_GRANT_PHY1_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_GRANT_PHY1_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY1_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY1_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_GRANT_PHY1_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_GRANT_PHY1_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY1_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY1_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_GRANT_PHY1_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_GRANT_PHY1_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY1_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY1_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_GRANT_PHY1_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_GRANT_PHY1_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY1_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY1_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockGrantPhy1. */
typedef register_container RegAPE_PERIPerLockGrantPhy1_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantPhy1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockGrantPhy1_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockGrantPhy1. */
        r32.setName("PerLockGrantPhy1");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockGrantPhy1_t& operator=(const RegAPE_PERIPerLockGrantPhy1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockGrantPhy1_t;

#define REG_APE_PERI_PER_LOCK_GRANT_PHY2 ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc001842c) /*  */
#define     APE_PERI_PER_LOCK_GRANT_PHY2_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_GRANT_PHY2_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY2_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY2_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_GRANT_PHY2_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_GRANT_PHY2_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY2_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY2_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_GRANT_PHY2_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_GRANT_PHY2_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY2_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY2_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_GRANT_PHY2_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_GRANT_PHY2_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY2_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY2_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_GRANT_PHY2_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_GRANT_PHY2_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY2_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY2_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_GRANT_PHY2_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_GRANT_PHY2_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY2_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY2_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockGrantPhy2. */
typedef register_container RegAPE_PERIPerLockGrantPhy2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantPhy2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockGrantPhy2_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockGrantPhy2. */
        r32.setName("PerLockGrantPhy2");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockGrantPhy2_t& operator=(const RegAPE_PERIPerLockGrantPhy2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockGrantPhy2_t;

#define REG_APE_PERI_PER_LOCK_GRANT_MEM ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018430) /*  */
#define     APE_PERI_PER_LOCK_GRANT_MEM_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_GRANT_MEM_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_GRANT_MEM_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_GRANT_MEM_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_GRANT_MEM_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_GRANT_MEM_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_GRANT_MEM_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_GRANT_MEM_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_GRANT_MEM_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_GRANT_MEM_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_GRANT_MEM_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_GRANT_MEM_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_GRANT_MEM_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_GRANT_MEM_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_GRANT_MEM_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_GRANT_MEM_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_GRANT_MEM_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_GRANT_MEM_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_GRANT_MEM_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_GRANT_MEM_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_GRANT_MEM_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_GRANT_MEM_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_GRANT_MEM_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_GRANT_MEM_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockGrantMem. */
typedef register_container RegAPE_PERIPerLockGrantMem_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantMem"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockGrantMem_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockGrantMem. */
        r32.setName("PerLockGrantMem");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockGrantMem_t& operator=(const RegAPE_PERIPerLockGrantMem_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockGrantMem_t;

#define REG_APE_PERI_PER_LOCK_GRANT_PHY3 ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018434) /*  */
#define     APE_PERI_PER_LOCK_GRANT_PHY3_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_GRANT_PHY3_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY3_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY3_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_GRANT_PHY3_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_GRANT_PHY3_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY3_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY3_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_GRANT_PHY3_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_GRANT_PHY3_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY3_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY3_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_GRANT_PHY3_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_GRANT_PHY3_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY3_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY3_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_GRANT_PHY3_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_GRANT_PHY3_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY3_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY3_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_GRANT_PHY3_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_GRANT_PHY3_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_GRANT_PHY3_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_GRANT_PHY3_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockGrantPhy3. */
typedef register_container RegAPE_PERIPerLockGrantPhy3_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantPhy3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockGrantPhy3_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockGrantPhy3. */
        r32.setName("PerLockGrantPhy3");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockGrantPhy3_t& operator=(const RegAPE_PERIPerLockGrantPhy3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockGrantPhy3_t;

#define REG_APE_PERI_PER_LOCK_GRANT_PORT6 ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc0018438) /*  */
#define     APE_PERI_PER_LOCK_GRANT_PORT6_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_GRANT_PORT6_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_GRANT_PORT6_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_GRANT_PORT6_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_GRANT_PORT6_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_GRANT_PORT6_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_GRANT_PORT6_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_GRANT_PORT6_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_GRANT_PORT6_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_GRANT_PORT6_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_GRANT_PORT6_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_GRANT_PORT6_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_GRANT_PORT6_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_GRANT_PORT6_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_GRANT_PORT6_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_GRANT_PORT6_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_GRANT_PORT6_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_GRANT_PORT6_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_GRANT_PORT6_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_GRANT_PORT6_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_GRANT_PORT6_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_GRANT_PORT6_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_GRANT_PORT6_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_GRANT_PORT6_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockGrantPort6. */
typedef register_container RegAPE_PERIPerLockGrantPort6_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantPort6"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockGrantPort6_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockGrantPort6. */
        r32.setName("PerLockGrantPort6");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockGrantPort6_t& operator=(const RegAPE_PERIPerLockGrantPort6_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockGrantPort6_t;

#define REG_APE_PERI_PER_LOCK_GRANT_GPIO ((BCM5719_APE_PERI_H_VOLATILE BCM5719_APE_PERI_H_uint32_t*)0xc001843c) /*  */
#define     APE_PERI_PER_LOCK_GRANT_GPIO_APE_SHIFT 0u
#define     APE_PERI_PER_LOCK_GRANT_GPIO_APE_MASK  0x1u
#define GET_APE_PERI_PER_LOCK_GRANT_GPIO_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PERI_PER_LOCK_GRANT_GPIO_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PERI_PER_LOCK_GRANT_GPIO_FUNCTION_1_SHIFT 1u
#define     APE_PERI_PER_LOCK_GRANT_GPIO_FUNCTION_1_MASK  0x2u
#define GET_APE_PERI_PER_LOCK_GRANT_GPIO_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PERI_PER_LOCK_GRANT_GPIO_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PERI_PER_LOCK_GRANT_GPIO_FUNCTION_2_SHIFT 2u
#define     APE_PERI_PER_LOCK_GRANT_GPIO_FUNCTION_2_MASK  0x4u
#define GET_APE_PERI_PER_LOCK_GRANT_GPIO_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PERI_PER_LOCK_GRANT_GPIO_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PERI_PER_LOCK_GRANT_GPIO_FUNCTION_3_SHIFT 3u
#define     APE_PERI_PER_LOCK_GRANT_GPIO_FUNCTION_3_MASK  0x8u
#define GET_APE_PERI_PER_LOCK_GRANT_GPIO_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PERI_PER_LOCK_GRANT_GPIO_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PERI_PER_LOCK_GRANT_GPIO_BOOTCODE_SHIFT 4u
#define     APE_PERI_PER_LOCK_GRANT_GPIO_BOOTCODE_MASK  0x10u
#define GET_APE_PERI_PER_LOCK_GRANT_GPIO_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PERI_PER_LOCK_GRANT_GPIO_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PERI_PER_LOCK_GRANT_GPIO_DRIVER_SHIFT 12u
#define     APE_PERI_PER_LOCK_GRANT_GPIO_DRIVER_MASK  0x1000u
#define GET_APE_PERI_PER_LOCK_GRANT_GPIO_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PERI_PER_LOCK_GRANT_GPIO_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_PERI_t.PerLockGrantGpio. */
typedef register_container RegAPE_PERIPerLockGrantGpio_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_PERI_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_PERI_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_PERI_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_PERI_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantGpio"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPE_PERIPerLockGrantGpio_t()
    {
        /** @brief constructor for @ref APE_PERI_t.PerLockGrantGpio. */
        r32.setName("PerLockGrantGpio");
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPE_PERIPerLockGrantGpio_t& operator=(const RegAPE_PERIPerLockGrantGpio_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPE_PERIPerLockGrantGpio_t;

/** @brief Component definition for @ref APE_PERI. */
typedef struct APE_PERI_t {
    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_PERI_H_uint32_t reserved_0[192];

    /** @brief  */
    RegAPE_PERIBmcToNcRxStatus_t BmcToNcRxStatus;

    /** @brief Upper four bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacHigh_t BmcToNcSourceMacHigh;

    /** @brief Lower two bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacLow_t BmcToNcSourceMacLow;

    /** @brief Upper four bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch0High_t BmcToNcSourceMacMatch0High;

    /** @brief Lower two bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch0Low_t BmcToNcSourceMacMatch0Low;

    /** @brief Upper four bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch1High_t BmcToNcSourceMacMatch1High;

    /** @brief Lower two bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch1Low_t BmcToNcSourceMacMatch1Low;

    /** @brief Upper four bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch2High_t BmcToNcSourceMacMatch2High;

    /** @brief Lower two bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch2Low_t BmcToNcSourceMacMatch2Low;

    /** @brief Upper four bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch3High_t BmcToNcSourceMacMatch3High;

    /** @brief Lower two bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch3Low_t BmcToNcSourceMacMatch3Low;

    /** @brief Upper four bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch4High_t BmcToNcSourceMacMatch4High;

    /** @brief Lower two bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch4Low_t BmcToNcSourceMacMatch4Low;

    /** @brief Upper four bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch5High_t BmcToNcSourceMacMatch5High;

    /** @brief Lower two bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch5Low_t BmcToNcSourceMacMatch5Low;

    /** @brief Upper four bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch6High_t BmcToNcSourceMacMatch6High;

    /** @brief Lower two bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch6Low_t BmcToNcSourceMacMatch6Low;

    /** @brief Upper four bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch7High_t BmcToNcSourceMacMatch7High;

    /** @brief Lower two bytes of the MAC */
    RegAPE_PERIBmcToNcSourceMacMatch7Low_t BmcToNcSourceMacMatch7Low;

    /** @brief  */
    RegAPE_PERIBmcToNcRxVlan_t BmcToNcRxVlan;

    /** @brief  */
    RegAPE_PERIBmcToNcReadBuffer_t BmcToNcReadBuffer;

    /** @brief  */
    RegAPE_PERIBmcToNcRxControl_t BmcToNcRxControl;

    /** @brief  */
    RegAPE_PERIBmcToNcRxStatus1_t BmcToNcRxStatus1;

    /** @brief  */
    RegAPE_PERIBmcToNcRxStatus2_t BmcToNcRxStatus2;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_PERI_H_uint32_t reserved_864[4];

    /** @brief  */
    RegAPE_PERIBmcToNcTxStatus_t BmcToNcTxStatus;

    /** @brief  */
    RegAPE_PERIBmcToNcTxControl_t BmcToNcTxControl;

    /** @brief  */
    RegAPE_PERIBmcToNcTxBuffer_t BmcToNcTxBuffer;

    /** @brief  */
    RegAPE_PERIBmcToNcTxBufferLast_t BmcToNcTxBufferLast;

    /** @brief  */
    RegAPE_PERIBmcToNcTxStatus1_t BmcToNcTxStatus1;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_PERI_H_uint32_t reserved_900[7];

    /** @brief  */
    RegAPE_PERIRmuControl_t RmuControl;

    /** @brief  */
    RegAPE_PERIArbControl_t ArbControl;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_PERI_H_uint32_t reserved_936[22];

    /** @brief This register, and the following Per Lock Request registers work the same. The tg3 driver uses 0x0000_1000 (APELOCK_PER_REQ_DRIVER) for PHY ports (or always for function 0). */
    RegAPE_PERIPerLockRequestPhy0_t PerLockRequestPhy0;

    /** @brief  */
    RegAPE_PERIPerLockRequestGrc_t PerLockRequestGrc;

    /** @brief  */
    RegAPE_PERIPerLockRequestPhy1_t PerLockRequestPhy1;

    /** @brief  */
    RegAPE_PERIPerLockRequestPhy2_t PerLockRequestPhy2;

    /** @brief  */
    RegAPE_PERIPerLockRequestMem_t PerLockRequestMem;

    /** @brief  */
    RegAPE_PERIPerLockRequestPhy3_t PerLockRequestPhy3;

    /** @brief  */
    RegAPE_PERIPerLockRequestPort6_t PerLockRequestPort6;

    /** @brief  */
    RegAPE_PERIPerLockRequestGpio_t PerLockRequestGpio;

    /** @brief  */
    RegAPE_PERIPerLockGrantPhy0_t PerLockGrantPhy0;

    /** @brief  */
    RegAPE_PERIPerLockGrantGrc_t PerLockGrantGrc;

    /** @brief  */
    RegAPE_PERIPerLockGrantPhy1_t PerLockGrantPhy1;

    /** @brief  */
    RegAPE_PERIPerLockGrantPhy2_t PerLockGrantPhy2;

    /** @brief  */
    RegAPE_PERIPerLockGrantMem_t PerLockGrantMem;

    /** @brief  */
    RegAPE_PERIPerLockGrantPhy3_t PerLockGrantPhy3;

    /** @brief  */
    RegAPE_PERIPerLockGrantPort6_t PerLockGrantPort6;

    /** @brief  */
    RegAPE_PERIPerLockGrantGpio_t PerLockGrantGpio;

#ifdef CXX_SIMULATOR
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    APE_PERI_t() : mIndexReadCallback(0), mIndexReadCallbackArgs(0), mIndexWriteCallback(0), mIndexWriteCallbackArgs(0)
    {
        for(int i = 0; i < 192; i++)
        {
            reserved_0[i].setComponentOffset(0x0 + (i * 4));
        }
        BmcToNcRxStatus.r32.setComponentOffset(0x300);
        BmcToNcSourceMacHigh.r32.setComponentOffset(0x304);
        BmcToNcSourceMacLow.r32.setComponentOffset(0x308);
        BmcToNcSourceMacMatch0High.r32.setComponentOffset(0x30c);
        BmcToNcSourceMacMatch0Low.r32.setComponentOffset(0x310);
        BmcToNcSourceMacMatch1High.r32.setComponentOffset(0x314);
        BmcToNcSourceMacMatch1Low.r32.setComponentOffset(0x318);
        BmcToNcSourceMacMatch2High.r32.setComponentOffset(0x31c);
        BmcToNcSourceMacMatch2Low.r32.setComponentOffset(0x320);
        BmcToNcSourceMacMatch3High.r32.setComponentOffset(0x324);
        BmcToNcSourceMacMatch3Low.r32.setComponentOffset(0x328);
        BmcToNcSourceMacMatch4High.r32.setComponentOffset(0x32c);
        BmcToNcSourceMacMatch4Low.r32.setComponentOffset(0x330);
        BmcToNcSourceMacMatch5High.r32.setComponentOffset(0x334);
        BmcToNcSourceMacMatch5Low.r32.setComponentOffset(0x338);
        BmcToNcSourceMacMatch6High.r32.setComponentOffset(0x33c);
        BmcToNcSourceMacMatch6Low.r32.setComponentOffset(0x340);
        BmcToNcSourceMacMatch7High.r32.setComponentOffset(0x344);
        BmcToNcSourceMacMatch7Low.r32.setComponentOffset(0x348);
        BmcToNcRxVlan.r32.setComponentOffset(0x34c);
        BmcToNcReadBuffer.r32.setComponentOffset(0x350);
        BmcToNcRxControl.r32.setComponentOffset(0x354);
        BmcToNcRxStatus1.r32.setComponentOffset(0x358);
        BmcToNcRxStatus2.r32.setComponentOffset(0x35c);
        for(int i = 0; i < 4; i++)
        {
            reserved_864[i].setComponentOffset(0x360 + (i * 4));
        }
        BmcToNcTxStatus.r32.setComponentOffset(0x370);
        BmcToNcTxControl.r32.setComponentOffset(0x374);
        BmcToNcTxBuffer.r32.setComponentOffset(0x378);
        BmcToNcTxBufferLast.r32.setComponentOffset(0x37c);
        BmcToNcTxStatus1.r32.setComponentOffset(0x380);
        for(int i = 0; i < 7; i++)
        {
            reserved_900[i].setComponentOffset(0x384 + (i * 4));
        }
        RmuControl.r32.setComponentOffset(0x3a0);
        ArbControl.r32.setComponentOffset(0x3a4);
        for(int i = 0; i < 22; i++)
        {
            reserved_936[i].setComponentOffset(0x3a8 + (i * 4));
        }
        PerLockRequestPhy0.r32.setComponentOffset(0x400);
        PerLockRequestGrc.r32.setComponentOffset(0x404);
        PerLockRequestPhy1.r32.setComponentOffset(0x408);
        PerLockRequestPhy2.r32.setComponentOffset(0x40c);
        PerLockRequestMem.r32.setComponentOffset(0x410);
        PerLockRequestPhy3.r32.setComponentOffset(0x414);
        PerLockRequestPort6.r32.setComponentOffset(0x418);
        PerLockRequestGpio.r32.setComponentOffset(0x41c);
        PerLockGrantPhy0.r32.setComponentOffset(0x420);
        PerLockGrantGrc.r32.setComponentOffset(0x424);
        PerLockGrantPhy1.r32.setComponentOffset(0x428);
        PerLockGrantPhy2.r32.setComponentOffset(0x42c);
        PerLockGrantMem.r32.setComponentOffset(0x430);
        PerLockGrantPhy3.r32.setComponentOffset(0x434);
        PerLockGrantPort6.r32.setComponentOffset(0x438);
        PerLockGrantGpio.r32.setComponentOffset(0x43c);
    }
    void print()
    {
        for(int i = 0; i < 192; i++)
        {
            reserved_0[i].print();
        }
        BmcToNcRxStatus.print();
        BmcToNcSourceMacHigh.print();
        BmcToNcSourceMacLow.print();
        BmcToNcSourceMacMatch0High.print();
        BmcToNcSourceMacMatch0Low.print();
        BmcToNcSourceMacMatch1High.print();
        BmcToNcSourceMacMatch1Low.print();
        BmcToNcSourceMacMatch2High.print();
        BmcToNcSourceMacMatch2Low.print();
        BmcToNcSourceMacMatch3High.print();
        BmcToNcSourceMacMatch3Low.print();
        BmcToNcSourceMacMatch4High.print();
        BmcToNcSourceMacMatch4Low.print();
        BmcToNcSourceMacMatch5High.print();
        BmcToNcSourceMacMatch5Low.print();
        BmcToNcSourceMacMatch6High.print();
        BmcToNcSourceMacMatch6Low.print();
        BmcToNcSourceMacMatch7High.print();
        BmcToNcSourceMacMatch7Low.print();
        BmcToNcRxVlan.print();
        BmcToNcReadBuffer.print();
        BmcToNcRxControl.print();
        BmcToNcRxStatus1.print();
        BmcToNcRxStatus2.print();
        for(int i = 0; i < 4; i++)
        {
            reserved_864[i].print();
        }
        BmcToNcTxStatus.print();
        BmcToNcTxControl.print();
        BmcToNcTxBuffer.print();
        BmcToNcTxBufferLast.print();
        BmcToNcTxStatus1.print();
        for(int i = 0; i < 7; i++)
        {
            reserved_900[i].print();
        }
        RmuControl.print();
        ArbControl.print();
        for(int i = 0; i < 22; i++)
        {
            reserved_936[i].print();
        }
        PerLockRequestPhy0.print();
        PerLockRequestGrc.print();
        PerLockRequestPhy1.print();
        PerLockRequestPhy2.print();
        PerLockRequestMem.print();
        PerLockRequestPhy3.print();
        PerLockRequestPort6.print();
        PerLockRequestGpio.print();
        PerLockGrantPhy0.print();
        PerLockGrantGrc.print();
        PerLockGrantPhy1.print();
        PerLockGrantPhy2.print();
        PerLockGrantMem.print();
        PerLockGrantPhy3.print();
        PerLockGrantPort6.print();
        PerLockGrantGpio.print();
    }
    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
} APE_PERI_t;

/** @brief Device APE Peripheral Registers */
extern BCM5719_APE_PERI_H_VOLATILE APE_PERI_t APE_PERI;



#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#ifndef CXX_SIMULATOR
_Static_assert(sizeof(APE_PERI_t) == 1088, "sizeof(APE_PERI_t) must be 1088");
#endif

#endif /* !BCM5719_APE_PERI_H */

/** @} */
