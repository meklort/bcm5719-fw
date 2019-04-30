////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_TX_PORT3.h
///
/// @project    ape
///
/// @brief      APE_TX_PORT3
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

/** @defgroup APE_TX_PORT3_H    APE_TX_PORT3 */
/** @addtogroup APE_TX_PORT3_H
 * @{
 */
#ifndef APE_TX_PORT3_H
#define APE_TX_PORT3_H

#include <stdint.h>
#include "APE_TX_PORT.h"

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_TX_PORT3_sim(void* base);
void init_APE_TX_PORT3(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_TX_PORT3_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_TX_PORT3_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_TX_PORT3_H_uint32_t;
#define APE_TX_PORT3_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_TX_PORT3_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_TX_PORT3_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_TX_PORT3_H_uint8_t;
typedef uint16_t APE_TX_PORT3_H_uint16_t;
typedef uint32_t APE_TX_PORT3_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_TX_PORT3_BASE ((volatile void*)0xa0026000) /* TX to network port, function 3 */
#define REG_TX_PORT3_SIZE (sizeof(TX_PORT_t))

#define REG_TX_PORT3_OUT ((volatile APE_TX_PORT3_H_uint32_t*)0xa0026000) /* This is the memory range into which frames are directed towards the network byte the APE firmware. */
#define     TX_PORT3_OUT_ALL_SHIFT 0u
#define     TX_PORT3_OUT_ALL_MASK  0xffffffffu
#define GET_TX_PORT3_OUT_ALL(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_TX_PORT3_OUT_ALL(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     TX_PORT3_OUT_ALL_CONTROL_WORD 0x0u
#define     TX_PORT3_OUT_ALL_ADDITIONAL_PAYLOAD_WORD 0x2u
#define     TX_PORT3_OUT_ALL_FRAME_LEN_WORD 0x3u
#define     TX_PORT3_OUT_ALL_NUM_BLOCKS_WORD 0x9u
#define     TX_PORT3_OUT_ALL_FIRST_PAYLOAD_WORD 0xcu
#define     TX_PORT3_OUT_ALL_BLOCK_WORDS 0x20u
#define     TX_PORT3_OUT_ALL_BLOCK_BYTES 0x80u


/** @brief TX to network port, function 3 */
extern volatile TX_PORT_t TX_PORT3;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !APE_TX_PORT3_H */

/** @} */
