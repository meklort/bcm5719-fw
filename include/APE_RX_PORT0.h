////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_RX_PORT0.h
///
/// @project    ape
///
/// @brief      APE_RX_PORT0
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

/** @defgroup APE_RX_PORT0_H    APE_RX_PORT0 */
/** @addtogroup APE_RX_PORT0_H
 * @{
 */
#ifndef APE_RX_PORT0_H
#define APE_RX_PORT0_H

#include <stdint.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_RX_PORT0_sim(void* base);
void init_APE_RX_PORT0(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_RX_PORT0_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_RX_PORT0_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_RX_PORT0_H_uint32_t;
#define APE_RX_PORT0_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_RX_PORT0_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_RX_PORT0_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_RX_PORT0_H_uint8_t;
typedef uint16_t APE_RX_PORT0_H_uint16_t;
typedef uint32_t APE_RX_PORT0_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_RX_PORT0_BASE ((volatile void*)0xa0000000) /* RX from network port, function 0 */
#define REG_RX_PORT0_SIZE (sizeof(RX_PORT_t))

#define REG_RX_PORT0_IN ((volatile APE_RX_PORT0_H_uint32_t*)0xa0000000) /* This is the memory range into which frames are directed towards the APE by the hardware. */
#define     RX_PORT0_IN_ALL_SHIFT 0u
#define     RX_PORT0_IN_ALL_MASK  0xffffffffu
#define GET_RX_PORT0_IN_ALL(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_RX_PORT0_IN_ALL(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     RX_PORT_IN_ALL_CONTROL_WORD 0x0u
#define     RX_PORT_IN_ALL_ADDITIONAL_PAYLOAD_WORD 0x2u
#define     RX_PORT_IN_ALL_FIRST_PAYLOAD_WORD 0xcu
#define     RX_PORT_IN_ALL_BLOCK_WORDS 0x20u
#define     RX_PORT_IN_ALL_BLOCK_BYTES 0x80u


/** @brief Register definition for @ref RX_PORT_t.In. */
typedef register_container RegRX_PORTIn_t {
    /** @brief 32bit direct register access. */
    APE_RX_PORT0_H_uint32_t r32;

    BITFIELD_BEGIN(APE_RX_PORT0_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief All bits */
        BITFIELD_MEMBER(APE_RX_PORT0_H_uint32_t, all, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief All bits */
        BITFIELD_MEMBER(APE_RX_PORT0_H_uint32_t, all, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_RX_PORT0_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "In"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegRX_PORTIn_t()
    {
        /** @brief constructor for @ref RX_PORT_t.In. */
        r32.setName("In");
        bits.all.setBaseRegister(&r32);
        bits.all.setName("all");
    }
    RegRX_PORTIn_t& operator=(const RegRX_PORTIn_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegRX_PORTIn_t;

/** @brief Component definition for @ref RX_PORT0. */
typedef struct RX_PORT_t {
    /** @brief This is the memory range into which frames are directed towards the APE by the hardware. */
    RegRX_PORTIn_t In[4096];

#ifdef CXX_SIMULATOR
    RX_PORT_t()
    {
        for(int i = 0; i < 4096; i++)
        {
            In[i].r32.setComponentOffset(0x0 + (i * 4));
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
} RX_PORT_t;

/** @brief RX from network port, function 0 */
extern volatile RX_PORT_t RX_PORT0;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !APE_RX_PORT0_H */

/** @} */
