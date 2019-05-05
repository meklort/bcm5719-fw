////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_FILTERS2.h
///
/// @project    ape
///
/// @brief      APE_FILTERS2
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

/** @defgroup APE_FILTERS2_H    APE_FILTERS2 */
/** @addtogroup APE_FILTERS2_H
 * @{
 */
#ifndef APE_FILTERS2_H
#define APE_FILTERS2_H

#include <stdint.h>
#include "APE_FILTERS.h"

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_FILTERS2_sim(void* base);
void init_APE_FILTERS2(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_FILTERS2_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_FILTERS2_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_FILTERS2_H_uint32_t;
#define APE_FILTERS2_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_FILTERS2_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_FILTERS2_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_FILTERS2_H_uint8_t;
typedef uint16_t APE_FILTERS2_H_uint16_t;
typedef uint32_t APE_FILTERS2_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_FILTERS2_BASE ((volatile void*)0xa0068000) /* Management Filter Registers, function 2 */
#define REG_FILTERS2_SIZE (sizeof(FILTERS_t))

#define REG_FILTERS2_ELEMENT_CONFIG ((volatile APE_FILTERS2_H_uint32_t*)0xa0068000) /* Element Configuration Register. */
#define     FILTERS2_ELEMENT_CONFIG_RULE_OFFSET_SHIFT 0u
#define     FILTERS2_ELEMENT_CONFIG_RULE_OFFSET_MASK  0xffu
#define GET_FILTERS2_ELEMENT_CONFIG_RULE_OFFSET(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_FILTERS2_ELEMENT_CONFIG_RULE_OFFSET(__val__)  (((__val__) << 0u) & 0xffu)
#define     FILTERS2_ELEMENT_CONFIG_RULE_CLASS_SHIFT 8u
#define     FILTERS2_ELEMENT_CONFIG_RULE_CLASS_MASK  0x1f00u
#define GET_FILTERS2_ELEMENT_CONFIG_RULE_CLASS(__reg__)  (((__reg__) & 0x1f00) >> 8u)
#define SET_FILTERS2_ELEMENT_CONFIG_RULE_CLASS(__val__)  (((__val__) << 8u) & 0x1f00u)
#define     FILTERS2_ELEMENT_CONFIG_RULE_HEADER_SHIFT 13u
#define     FILTERS2_ELEMENT_CONFIG_RULE_HEADER_MASK  0xe000u
#define GET_FILTERS2_ELEMENT_CONFIG_RULE_HEADER(__reg__)  (((__reg__) & 0xe000) >> 13u)
#define SET_FILTERS2_ELEMENT_CONFIG_RULE_HEADER(__val__)  (((__val__) << 13u) & 0xe000u)
#define     FILTERS2_ELEMENT_CONFIG_RULE_HEADER_SOF 0x0u
#define     FILTERS2_ELEMENT_CONFIG_RULE_HEADER_IP 0x1u
#define     FILTERS2_ELEMENT_CONFIG_RULE_HEADER_TCP 0x2u
#define     FILTERS2_ELEMENT_CONFIG_RULE_HEADER_UDP 0x3u
#define     FILTERS2_ELEMENT_CONFIG_RULE_HEADER_DATA 0x4u
#define     FILTERS2_ELEMENT_CONFIG_RULE_HEADER_ICMPV4 0x5u
#define     FILTERS2_ELEMENT_CONFIG_RULE_HEADER_ICMPV6 0x6u
#define     FILTERS2_ELEMENT_CONFIG_RULE_HEADER_VLAN 0x7u

#define     FILTERS2_ELEMENT_CONFIG_RULE_OP_SHIFT 16u
#define     FILTERS2_ELEMENT_CONFIG_RULE_OP_MASK  0x30000u
#define GET_FILTERS2_ELEMENT_CONFIG_RULE_OP(__reg__)  (((__reg__) & 0x30000) >> 16u)
#define SET_FILTERS2_ELEMENT_CONFIG_RULE_OP(__val__)  (((__val__) << 16u) & 0x30000u)
#define     FILTERS2_ELEMENT_CONFIG_RULE_OP_EQ 0x0u
#define     FILTERS2_ELEMENT_CONFIG_RULE_OP_NE 0x1u
#define     FILTERS2_ELEMENT_CONFIG_RULE_OP_GT 0x2u
#define     FILTERS2_ELEMENT_CONFIG_RULE_OP_LT 0x3u

#define     FILTERS2_ELEMENT_CONFIG_RULE_MAP_SHIFT 24u
#define     FILTERS2_ELEMENT_CONFIG_RULE_MAP_MASK  0x1000000u
#define GET_FILTERS2_ELEMENT_CONFIG_RULE_MAP(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_FILTERS2_ELEMENT_CONFIG_RULE_MAP(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     FILTERS2_ELEMENT_CONFIG_RULE_DISCARD_SHIFT 25u
#define     FILTERS2_ELEMENT_CONFIG_RULE_DISCARD_MASK  0x2000000u
#define GET_FILTERS2_ELEMENT_CONFIG_RULE_DISCARD(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_FILTERS2_ELEMENT_CONFIG_RULE_DISCARD(__val__)  (((__val__) << 25u) & 0x2000000u)
#define     FILTERS2_ELEMENT_CONFIG_RULE_MASK_SHIFT 26u
#define     FILTERS2_ELEMENT_CONFIG_RULE_MASK_MASK  0x4000000u
#define GET_FILTERS2_ELEMENT_CONFIG_RULE_MASK(__reg__)  (((__reg__) & 0x4000000) >> 26u)
#define SET_FILTERS2_ELEMENT_CONFIG_RULE_MASK(__val__)  (((__val__) << 26u) & 0x4000000u)
#define     FILTERS2_ELEMENT_CONFIG_RULE_P3_SHIFT 27u
#define     FILTERS2_ELEMENT_CONFIG_RULE_P3_MASK  0x8000000u
#define GET_FILTERS2_ELEMENT_CONFIG_RULE_P3(__reg__)  (((__reg__) & 0x8000000) >> 27u)
#define SET_FILTERS2_ELEMENT_CONFIG_RULE_P3(__val__)  (((__val__) << 27u) & 0x8000000u)
#define     FILTERS2_ELEMENT_CONFIG_RULE_P2_SHIFT 28u
#define     FILTERS2_ELEMENT_CONFIG_RULE_P2_MASK  0x10000000u
#define GET_FILTERS2_ELEMENT_CONFIG_RULE_P2(__reg__)  (((__reg__) & 0x10000000) >> 28u)
#define SET_FILTERS2_ELEMENT_CONFIG_RULE_P2(__val__)  (((__val__) << 28u) & 0x10000000u)
#define     FILTERS2_ELEMENT_CONFIG_RULE_P1_SHIFT 29u
#define     FILTERS2_ELEMENT_CONFIG_RULE_P1_MASK  0x20000000u
#define GET_FILTERS2_ELEMENT_CONFIG_RULE_P1(__reg__)  (((__reg__) & 0x20000000) >> 29u)
#define SET_FILTERS2_ELEMENT_CONFIG_RULE_P1(__val__)  (((__val__) << 29u) & 0x20000000u)
#define     FILTERS2_ELEMENT_CONFIG_RULE_AND_SHIFT 30u
#define     FILTERS2_ELEMENT_CONFIG_RULE_AND_MASK  0x40000000u
#define GET_FILTERS2_ELEMENT_CONFIG_RULE_AND(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_FILTERS2_ELEMENT_CONFIG_RULE_AND(__val__)  (((__val__) << 30u) & 0x40000000u)
#define     FILTERS2_ELEMENT_CONFIG_RULE_ENABLE_SHIFT 31u
#define     FILTERS2_ELEMENT_CONFIG_RULE_ENABLE_MASK  0x80000000u
#define GET_FILTERS2_ELEMENT_CONFIG_RULE_ENABLE(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_FILTERS2_ELEMENT_CONFIG_RULE_ENABLE(__val__)  (((__val__) << 31u) & 0x80000000u)

#define REG_FILTERS2_ELEMENT_PATTERN ((volatile APE_FILTERS2_H_uint32_t*)0xa0068080) /* If RULE_MASK is set, low 16 bits are a bitmask and high 16 bits are the value masked by it. If it is not set, the entire field is a 32-bit match value. */
#define REG_FILTERS2_RULE_CONFIGURATION ((volatile APE_FILTERS2_H_uint32_t*)0xa0068100) /*  */
#define     FILTERS2_RULE_CONFIGURATION_FILTER_SET_DISABLE_SHIFT 0u
#define     FILTERS2_RULE_CONFIGURATION_FILTER_SET_DISABLE_MASK  0x1u
#define GET_FILTERS2_RULE_CONFIGURATION_FILTER_SET_DISABLE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_FILTERS2_RULE_CONFIGURATION_FILTER_SET_DISABLE(__val__)  (((__val__) << 0u) & 0x1u)
#define     FILTERS2_RULE_CONFIGURATION_DIRECT_IP_FRAGMENT_TO_APE_SHIFT 31u
#define     FILTERS2_RULE_CONFIGURATION_DIRECT_IP_FRAGMENT_TO_APE_MASK  0x80000000u
#define GET_FILTERS2_RULE_CONFIGURATION_DIRECT_IP_FRAGMENT_TO_APE(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_FILTERS2_RULE_CONFIGURATION_DIRECT_IP_FRAGMENT_TO_APE(__val__)  (((__val__) << 31u) & 0x80000000u)

#define REG_FILTERS2_RULE_SET ((volatile APE_FILTERS2_H_uint32_t*)0xa0068104) /*  */
#define     FILTERS2_RULE_SET_ACTION_SHIFT 0u
#define     FILTERS2_RULE_SET_ACTION_MASK  0x3u
#define GET_FILTERS2_RULE_SET_ACTION(__reg__)  (((__reg__) & 0x3) >> 0u)
#define SET_FILTERS2_RULE_SET_ACTION(__val__)  (((__val__) << 0u) & 0x3u)
#define     FILTERS2_RULE_SET_ACTION_TO_APE_ONLY 0x0u
#define     FILTERS2_RULE_SET_ACTION_TO_APE_AND_HOST 0x1u
#define     FILTERS2_RULE_SET_ACTION_DISCARD 0x2u

#define     FILTERS2_RULE_SET_COUNT_SHIFT 3u
#define     FILTERS2_RULE_SET_COUNT_MASK  0x7fff8u
#define GET_FILTERS2_RULE_SET_COUNT(__reg__)  (((__reg__) & 0x7fff8) >> 3u)
#define SET_FILTERS2_RULE_SET_COUNT(__val__)  (((__val__) << 3u) & 0x7fff8u)
#define     FILTERS2_RULE_SET_ENABLE_SHIFT 31u
#define     FILTERS2_RULE_SET_ENABLE_MASK  0x80000000u
#define GET_FILTERS2_RULE_SET_ENABLE(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_FILTERS2_RULE_SET_ENABLE(__val__)  (((__val__) << 31u) & 0x80000000u)

#define REG_FILTERS2_RULE_MASK ((volatile APE_FILTERS2_H_uint32_t*)0xa0068184) /*  */
/** @brief Management Filter Registers, function 2 */
extern volatile FILTERS_t FILTERS2;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !APE_FILTERS2_H */

/** @} */
