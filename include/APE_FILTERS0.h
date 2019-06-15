////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_FILTERS0.h
///
/// @project    ape
///
/// @brief      APE_FILTERS0
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

/** @defgroup APE_FILTERS0_H    APE_FILTERS0 */
/** @addtogroup APE_FILTERS0_H
 * @{
 */
#ifndef APE_FILTERS0_H
#define APE_FILTERS0_H

#include <types.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_FILTERS0_sim(void* base);
void init_APE_FILTERS0(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_FILTERS0_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_FILTERS0_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_FILTERS0_H_uint32_t;
#define APE_FILTERS0_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_FILTERS0_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_FILTERS0_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_FILTERS0_H_uint8_t;
typedef uint16_t APE_FILTERS0_H_uint16_t;
typedef uint32_t APE_FILTERS0_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_FILTERS0_BASE ((volatile void*)0xa0048000) /* Management Filter Registers, function 0 */
#define REG_FILTERS0_SIZE (sizeof(FILTERS_t))

#define REG_FILTERS0_ELEMENT_CONFIG ((volatile APE_FILTERS0_H_uint32_t*)0xa0048000) /* Element Configuration Register. */
#define     FILTERS0_ELEMENT_CONFIG_RULE_OFFSET_SHIFT 0u
#define     FILTERS0_ELEMENT_CONFIG_RULE_OFFSET_MASK  0xffu
#define GET_FILTERS0_ELEMENT_CONFIG_RULE_OFFSET(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_FILTERS0_ELEMENT_CONFIG_RULE_OFFSET(__val__)  (((__val__) << 0u) & 0xffu)
#define     FILTERS0_ELEMENT_CONFIG_RULE_CLASS_SHIFT 8u
#define     FILTERS0_ELEMENT_CONFIG_RULE_CLASS_MASK  0x1f00u
#define GET_FILTERS0_ELEMENT_CONFIG_RULE_CLASS(__reg__)  (((__reg__) & 0x1f00) >> 8u)
#define SET_FILTERS0_ELEMENT_CONFIG_RULE_CLASS(__val__)  (((__val__) << 8u) & 0x1f00u)
#define     FILTERS0_ELEMENT_CONFIG_RULE_HEADER_SHIFT 13u
#define     FILTERS0_ELEMENT_CONFIG_RULE_HEADER_MASK  0xe000u
#define GET_FILTERS0_ELEMENT_CONFIG_RULE_HEADER(__reg__)  (((__reg__) & 0xe000) >> 13u)
#define SET_FILTERS0_ELEMENT_CONFIG_RULE_HEADER(__val__)  (((__val__) << 13u) & 0xe000u)
#define     FILTERS_ELEMENT_CONFIG_RULE_HEADER_SOF 0x0u
#define     FILTERS_ELEMENT_CONFIG_RULE_HEADER_IP 0x1u
#define     FILTERS_ELEMENT_CONFIG_RULE_HEADER_TCP 0x2u
#define     FILTERS_ELEMENT_CONFIG_RULE_HEADER_UDP 0x3u
#define     FILTERS_ELEMENT_CONFIG_RULE_HEADER_DATA 0x4u
#define     FILTERS_ELEMENT_CONFIG_RULE_HEADER_ICMPV4 0x5u
#define     FILTERS_ELEMENT_CONFIG_RULE_HEADER_ICMPV6 0x6u
#define     FILTERS_ELEMENT_CONFIG_RULE_HEADER_VLAN 0x7u

#define     FILTERS0_ELEMENT_CONFIG_RULE_OP_SHIFT 16u
#define     FILTERS0_ELEMENT_CONFIG_RULE_OP_MASK  0x30000u
#define GET_FILTERS0_ELEMENT_CONFIG_RULE_OP(__reg__)  (((__reg__) & 0x30000) >> 16u)
#define SET_FILTERS0_ELEMENT_CONFIG_RULE_OP(__val__)  (((__val__) << 16u) & 0x30000u)
#define     FILTERS_ELEMENT_CONFIG_RULE_OP_EQ 0x0u
#define     FILTERS_ELEMENT_CONFIG_RULE_OP_NE 0x1u
#define     FILTERS_ELEMENT_CONFIG_RULE_OP_GT 0x2u
#define     FILTERS_ELEMENT_CONFIG_RULE_OP_LT 0x3u

#define     FILTERS0_ELEMENT_CONFIG_RULE_MAP_SHIFT 24u
#define     FILTERS0_ELEMENT_CONFIG_RULE_MAP_MASK  0x1000000u
#define GET_FILTERS0_ELEMENT_CONFIG_RULE_MAP(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_FILTERS0_ELEMENT_CONFIG_RULE_MAP(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     FILTERS0_ELEMENT_CONFIG_RULE_DISCARD_SHIFT 25u
#define     FILTERS0_ELEMENT_CONFIG_RULE_DISCARD_MASK  0x2000000u
#define GET_FILTERS0_ELEMENT_CONFIG_RULE_DISCARD(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_FILTERS0_ELEMENT_CONFIG_RULE_DISCARD(__val__)  (((__val__) << 25u) & 0x2000000u)
#define     FILTERS0_ELEMENT_CONFIG_RULE_MASK_SHIFT 26u
#define     FILTERS0_ELEMENT_CONFIG_RULE_MASK_MASK  0x4000000u
#define GET_FILTERS0_ELEMENT_CONFIG_RULE_MASK(__reg__)  (((__reg__) & 0x4000000) >> 26u)
#define SET_FILTERS0_ELEMENT_CONFIG_RULE_MASK(__val__)  (((__val__) << 26u) & 0x4000000u)
#define     FILTERS0_ELEMENT_CONFIG_RULE_P3_SHIFT 27u
#define     FILTERS0_ELEMENT_CONFIG_RULE_P3_MASK  0x8000000u
#define GET_FILTERS0_ELEMENT_CONFIG_RULE_P3(__reg__)  (((__reg__) & 0x8000000) >> 27u)
#define SET_FILTERS0_ELEMENT_CONFIG_RULE_P3(__val__)  (((__val__) << 27u) & 0x8000000u)
#define     FILTERS0_ELEMENT_CONFIG_RULE_P2_SHIFT 28u
#define     FILTERS0_ELEMENT_CONFIG_RULE_P2_MASK  0x10000000u
#define GET_FILTERS0_ELEMENT_CONFIG_RULE_P2(__reg__)  (((__reg__) & 0x10000000) >> 28u)
#define SET_FILTERS0_ELEMENT_CONFIG_RULE_P2(__val__)  (((__val__) << 28u) & 0x10000000u)
#define     FILTERS0_ELEMENT_CONFIG_RULE_P1_SHIFT 29u
#define     FILTERS0_ELEMENT_CONFIG_RULE_P1_MASK  0x20000000u
#define GET_FILTERS0_ELEMENT_CONFIG_RULE_P1(__reg__)  (((__reg__) & 0x20000000) >> 29u)
#define SET_FILTERS0_ELEMENT_CONFIG_RULE_P1(__val__)  (((__val__) << 29u) & 0x20000000u)
#define     FILTERS0_ELEMENT_CONFIG_RULE_AND_SHIFT 30u
#define     FILTERS0_ELEMENT_CONFIG_RULE_AND_MASK  0x40000000u
#define GET_FILTERS0_ELEMENT_CONFIG_RULE_AND(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_FILTERS0_ELEMENT_CONFIG_RULE_AND(__val__)  (((__val__) << 30u) & 0x40000000u)
#define     FILTERS0_ELEMENT_CONFIG_RULE_ENABLE_SHIFT 31u
#define     FILTERS0_ELEMENT_CONFIG_RULE_ENABLE_MASK  0x80000000u
#define GET_FILTERS0_ELEMENT_CONFIG_RULE_ENABLE(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_FILTERS0_ELEMENT_CONFIG_RULE_ENABLE(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref FILTERS_t.ElementConfig. */
typedef register_container RegFILTERSElementConfig_t {
    /** @brief 32bit direct register access. */
    APE_FILTERS0_H_uint32_t r32;

    BITFIELD_BEGIN(APE_FILTERS0_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleOffset, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleClass, 8, 5)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleHeader, 13, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleOp, 16, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, reserved_23_18, 18, 6)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleMap, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleDiscard, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleMask, 26, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleP3, 27, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleP2, 28, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleP1, 29, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleAnd, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleEnable, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleEnable, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleAnd, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleP1, 29, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleP2, 28, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleP3, 27, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleMask, 26, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleDiscard, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleMap, 24, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, reserved_23_18, 18, 6)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleOp, 16, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleHeader, 13, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleClass, 8, 5)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, RuleOffset, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_FILTERS0_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ElementConfig"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegFILTERSElementConfig_t()
    {
        /** @brief constructor for @ref FILTERS_t.ElementConfig. */
        r32.setName("ElementConfig");
        bits.RuleOffset.setBaseRegister(&r32);
        bits.RuleOffset.setName("RuleOffset");
        bits.RuleClass.setBaseRegister(&r32);
        bits.RuleClass.setName("RuleClass");
        bits.RuleHeader.setBaseRegister(&r32);
        bits.RuleHeader.setName("RuleHeader");
        bits.RuleOp.setBaseRegister(&r32);
        bits.RuleOp.setName("RuleOp");
        bits.RuleMap.setBaseRegister(&r32);
        bits.RuleMap.setName("RuleMap");
        bits.RuleDiscard.setBaseRegister(&r32);
        bits.RuleDiscard.setName("RuleDiscard");
        bits.RuleMask.setBaseRegister(&r32);
        bits.RuleMask.setName("RuleMask");
        bits.RuleP3.setBaseRegister(&r32);
        bits.RuleP3.setName("RuleP3");
        bits.RuleP2.setBaseRegister(&r32);
        bits.RuleP2.setName("RuleP2");
        bits.RuleP1.setBaseRegister(&r32);
        bits.RuleP1.setName("RuleP1");
        bits.RuleAnd.setBaseRegister(&r32);
        bits.RuleAnd.setName("RuleAnd");
        bits.RuleEnable.setBaseRegister(&r32);
        bits.RuleEnable.setName("RuleEnable");
    }
    RegFILTERSElementConfig_t& operator=(const RegFILTERSElementConfig_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegFILTERSElementConfig_t;

#define REG_FILTERS0_ELEMENT_PATTERN ((volatile APE_FILTERS0_H_uint32_t*)0xa0048080) /* If RULE_MASK is set, low 16 bits are a bitmask and high 16 bits are the value masked by it. If it is not set, the entire field is a 32-bit match value. */
/** @brief Register definition for @ref FILTERS_t.ElementPattern. */
typedef register_container RegFILTERSElementPattern_t {
    /** @brief 32bit direct register access. */
    APE_FILTERS0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ElementPattern"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegFILTERSElementPattern_t()
    {
        /** @brief constructor for @ref FILTERS_t.ElementPattern. */
        r32.setName("ElementPattern");
    }
    RegFILTERSElementPattern_t& operator=(const RegFILTERSElementPattern_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegFILTERSElementPattern_t;

#define REG_FILTERS0_RULE_CONFIGURATION ((volatile APE_FILTERS0_H_uint32_t*)0xa0048100) /*  */
#define     FILTERS0_RULE_CONFIGURATION_FILTER_SET_DISABLE_SHIFT 0u
#define     FILTERS0_RULE_CONFIGURATION_FILTER_SET_DISABLE_MASK  0x1u
#define GET_FILTERS0_RULE_CONFIGURATION_FILTER_SET_DISABLE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_FILTERS0_RULE_CONFIGURATION_FILTER_SET_DISABLE(__val__)  (((__val__) << 0u) & 0x1u)
#define     FILTERS0_RULE_CONFIGURATION_DIRECT_IP_FRAGMENT_TO_APE_SHIFT 31u
#define     FILTERS0_RULE_CONFIGURATION_DIRECT_IP_FRAGMENT_TO_APE_MASK  0x80000000u
#define GET_FILTERS0_RULE_CONFIGURATION_DIRECT_IP_FRAGMENT_TO_APE(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_FILTERS0_RULE_CONFIGURATION_DIRECT_IP_FRAGMENT_TO_APE(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref FILTERS_t.RuleConfiguration. */
typedef register_container RegFILTERSRuleConfiguration_t {
    /** @brief 32bit direct register access. */
    APE_FILTERS0_H_uint32_t r32;

    BITFIELD_BEGIN(APE_FILTERS0_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, FilterSetDisable, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, reserved_30_1, 1, 30)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, DirectIPFragmenttoAPE, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, DirectIPFragmenttoAPE, 31, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, reserved_30_1, 1, 30)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, FilterSetDisable, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_FILTERS0_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RuleConfiguration"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegFILTERSRuleConfiguration_t()
    {
        /** @brief constructor for @ref FILTERS_t.RuleConfiguration. */
        r32.setName("RuleConfiguration");
        bits.FilterSetDisable.setBaseRegister(&r32);
        bits.FilterSetDisable.setName("FilterSetDisable");
        bits.DirectIPFragmenttoAPE.setBaseRegister(&r32);
        bits.DirectIPFragmenttoAPE.setName("DirectIPFragmenttoAPE");
    }
    RegFILTERSRuleConfiguration_t& operator=(const RegFILTERSRuleConfiguration_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegFILTERSRuleConfiguration_t;

#define REG_FILTERS0_RULE_SET ((volatile APE_FILTERS0_H_uint32_t*)0xa0048104) /*  */
#define     FILTERS0_RULE_SET_ACTION_SHIFT 0u
#define     FILTERS0_RULE_SET_ACTION_MASK  0x3u
#define GET_FILTERS0_RULE_SET_ACTION(__reg__)  (((__reg__) & 0x3) >> 0u)
#define SET_FILTERS0_RULE_SET_ACTION(__val__)  (((__val__) << 0u) & 0x3u)
#define     FILTERS_RULE_SET_ACTION_TO_APE_ONLY 0x0u
#define     FILTERS_RULE_SET_ACTION_TO_APE_AND_HOST 0x1u
#define     FILTERS_RULE_SET_ACTION_DISCARD 0x2u

#define     FILTERS0_RULE_SET_COUNT_SHIFT 3u
#define     FILTERS0_RULE_SET_COUNT_MASK  0x7fff8u
#define GET_FILTERS0_RULE_SET_COUNT(__reg__)  (((__reg__) & 0x7fff8) >> 3u)
#define SET_FILTERS0_RULE_SET_COUNT(__val__)  (((__val__) << 3u) & 0x7fff8u)
#define     FILTERS0_RULE_SET_ENABLE_SHIFT 31u
#define     FILTERS0_RULE_SET_ENABLE_MASK  0x80000000u
#define GET_FILTERS0_RULE_SET_ENABLE(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_FILTERS0_RULE_SET_ENABLE(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref FILTERS_t.RuleSet. */
typedef register_container RegFILTERSRuleSet_t {
    /** @brief 32bit direct register access. */
    APE_FILTERS0_H_uint32_t r32;

    BITFIELD_BEGIN(APE_FILTERS0_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, Action, 0, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, reserved_2_2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, Count, 3, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, reserved_30_19, 19, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, Enable, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, Enable, 31, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, reserved_30_19, 19, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, Count, 3, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, reserved_2_2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_FILTERS0_H_uint32_t, Action, 0, 2)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_FILTERS0_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RuleSet"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegFILTERSRuleSet_t()
    {
        /** @brief constructor for @ref FILTERS_t.RuleSet. */
        r32.setName("RuleSet");
        bits.Action.setBaseRegister(&r32);
        bits.Action.setName("Action");
        bits.Count.setBaseRegister(&r32);
        bits.Count.setName("Count");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
    }
    RegFILTERSRuleSet_t& operator=(const RegFILTERSRuleSet_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegFILTERSRuleSet_t;

#define REG_FILTERS0_RULE_MASK ((volatile APE_FILTERS0_H_uint32_t*)0xa0048184) /*  */
/** @brief Register definition for @ref FILTERS_t.RuleMask. */
typedef register_container RegFILTERSRuleMask_t {
    /** @brief 32bit direct register access. */
    APE_FILTERS0_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RuleMask"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegFILTERSRuleMask_t()
    {
        /** @brief constructor for @ref FILTERS_t.RuleMask. */
        r32.setName("RuleMask");
    }
    RegFILTERSRuleMask_t& operator=(const RegFILTERSRuleMask_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegFILTERSRuleMask_t;

/** @brief Component definition for @ref FILTERS0. */
typedef struct FILTERS_t {
    /** @brief Element Configuration Register. */
    RegFILTERSElementConfig_t ElementConfig[32];

    /** @brief If RULE_MASK is set, low 16 bits are a bitmask and high 16 bits are the value masked by it. If it is not set, the entire field is a 32-bit match value. */
    RegFILTERSElementPattern_t ElementPattern[32];

    /** @brief  */
    RegFILTERSRuleConfiguration_t RuleConfiguration;

    /** @brief  */
    RegFILTERSRuleSet_t RuleSet[31];

    /** @brief Reserved bytes to pad out data structure. */
    APE_FILTERS0_H_uint32_t reserved_384[1];

    /** @brief  */
    RegFILTERSRuleMask_t RuleMask[31];

#ifdef CXX_SIMULATOR
    FILTERS_t()
    {
        for(int i = 0; i < 32; i++)
        {
            ElementConfig[i].r32.setComponentOffset(0x0 + (i * 4));
        }
        for(int i = 0; i < 32; i++)
        {
            ElementPattern[i].r32.setComponentOffset(0x80 + (i * 4));
        }
        RuleConfiguration.r32.setComponentOffset(0x100);
        for(int i = 0; i < 31; i++)
        {
            RuleSet[i].r32.setComponentOffset(0x104 + (i * 4));
        }
        for(int i = 0; i < 31; i++)
        {
            RuleMask[i].r32.setComponentOffset(0x184 + (i * 4));
        }
    }
    void print()
    {
        for(int i = 0; i < 32; i++)
        {
            ElementConfig[i].print();
        }
        for(int i = 0; i < 32; i++)
        {
            ElementPattern[i].print();
        }
        RuleConfiguration.print();
        for(int i = 0; i < 31; i++)
        {
            RuleSet[i].print();
        }
        for(int i = 0; i < 1; i++)
        {
            reserved_384[i].print();
        }
        for(int i = 0; i < 31; i++)
        {
            RuleMask[i].print();
        }
    }
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
} FILTERS_t;

/** @brief Management Filter Registers, function 0 */
extern volatile FILTERS_t FILTERS0;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !APE_FILTERS0_H */

/** @} */
