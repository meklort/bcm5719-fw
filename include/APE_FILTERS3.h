////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_FILTERS3.h
///
/// @project    ape
///
/// @brief      APE_FILTERS3
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

/** @defgroup APE_FILTERS3_H    APE_FILTERS3 */
/** @addtogroup APE_FILTERS3_H
 * @{
 */
#ifndef APE_FILTERS3_H
#define APE_FILTERS3_H

#include <types.h>
#include "APE_FILTERS0.h"

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_FILTERS3_sim(void* base);
void init_APE_FILTERS3(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_FILTERS3_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_FILTERS3_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_FILTERS3_H_uint32_t;
#define APE_FILTERS3_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_FILTERS3_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_FILTERS3_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define APE_FILTERS3_H_VOLATILE
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_FILTERS3_H_uint8_t;
typedef uint16_t APE_FILTERS3_H_uint16_t;
typedef uint32_t APE_FILTERS3_H_uint32_t;
#define register_container union
#define APE_FILTERS3_H_VOLATILE volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_FILTERS3_BASE ((volatile void*)0xa0078000) /* Management Filter Registers, function 3 */
#define REG_FILTERS3_SIZE (sizeof(FILTERS_t))

#define REG_FILTERS3_ELEMENT_CONFIG ((APE_FILTERS3_H_VOLATILE APE_FILTERS3_H_uint32_t*)0xa0078000) /* Element Configuration Register. */
#define REG_FILTERS3_ELEMENT_PATTERN ((APE_FILTERS3_H_VOLATILE APE_FILTERS3_H_uint32_t*)0xa0078080) /* If RULE_MASK is set, low 16 bits are a bitmask and high 16 bits are the value masked by it. If it is not set, the entire field is a 32-bit match value. */
#define REG_FILTERS3_RULE_CONFIGURATION ((APE_FILTERS3_H_VOLATILE APE_FILTERS3_H_uint32_t*)0xa0078100) /*  */
#define REG_FILTERS3_RULE_SET ((APE_FILTERS3_H_VOLATILE APE_FILTERS3_H_uint32_t*)0xa0078104) /*  */
#define REG_FILTERS3_RULE_MASK ((APE_FILTERS3_H_VOLATILE APE_FILTERS3_H_uint32_t*)0xa0078184) /*  */
/** @brief Management Filter Registers, function 3 */
extern APE_FILTERS3_H_VOLATILE FILTERS_t FILTERS3;



#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#ifndef CXX_SIMULATOR
_Static_assert(sizeof(FILTERS_t) == 512, "sizeof(FILTERS_t) must be 512");
#endif

#endif /* !APE_FILTERS3_H */

/** @} */
