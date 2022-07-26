////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_TX_PORT0.h
///
/// @project    ape
///
/// @brief      APE_TX_PORT0
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

/** @defgroup APE_TX_PORT0_H    APE_TX_PORT0 */
/** @addtogroup APE_TX_PORT0_H
 * @{
 */
#ifndef APE_TX_PORT0_H
#define APE_TX_PORT0_H

#include <types.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_TX_PORT0_sim(void* base, uint32_t (*read)(uint32_t val, uint32_t offset, void *args), uint32_t (*write)(uint32_t val, uint32_t offset, void *args));
void init_APE_TX_PORT0(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_TX_PORT0_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_TX_PORT0_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_TX_PORT0_H_uint32_t;
#define APE_TX_PORT0_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_TX_PORT0_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_TX_PORT0_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define APE_TX_PORT0_H_VOLATILE
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_TX_PORT0_H_uint8_t;
typedef uint16_t APE_TX_PORT0_H_uint16_t;
typedef uint32_t APE_TX_PORT0_H_uint32_t;
#define register_container union
#define APE_TX_PORT0_H_VOLATILE volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_TX_PORT0_BASE ((volatile void*)0xa0020000) /* TX to network port, function 0 */
#define REG_TX_PORT0_SIZE (sizeof(TX_PORT_t))

#define REG_TX_PORT0_OUT ((APE_TX_PORT0_H_VOLATILE APE_TX_PORT0_H_uint32_t*)0xa0020000) /* This is the memory range into which frames are directed towards the network by the APE firmware. */
#define     TX_PORT0_OUT_ALL_SHIFT 0u
#define     TX_PORT0_OUT_ALL_MASK  0xffffffffu
#define GET_TX_PORT0_OUT_ALL(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_TX_PORT0_OUT_ALL(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     TX_PORT_OUT_ALL_CONTROL_WORD 0x0u
#define     TX_PORT_OUT_ALL_ADDITIONAL_PAYLOAD_WORD 0x2u
#define     TX_PORT_OUT_ALL_FRAME_LEN_WORD 0x3u
#define     TX_PORT_OUT_ALL_NUM_BLOCKS_WORD 0x9u
#define     TX_PORT_OUT_ALL_FIRST_PAYLOAD_WORD 0xcu
#define     TX_PORT_OUT_ALL_BLOCK_WORDS 0x20u
#define     TX_PORT_OUT_ALL_BLOCK_BYTES 0x80u


/** @brief Register definition for @ref TX_PORT_t.Out. */
typedef register_container RegTX_PORTOut_t {
    /** @brief 32bit direct register access. */
    APE_TX_PORT0_H_uint32_t r32;

    BITFIELD_BEGIN(APE_TX_PORT0_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief All bits */
        BITFIELD_MEMBER(APE_TX_PORT0_H_uint32_t, all, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief All bits */
        BITFIELD_MEMBER(APE_TX_PORT0_H_uint32_t, all, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_TX_PORT0_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Out"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegTX_PORTOut_t()
    {
        /** @brief constructor for @ref TX_PORT_t.Out. */
        r32.setName("Out");
        bits.all.setBaseRegister(&r32);
        bits.all.setName("all");
        bits.all.addEnum("Control Word", 0x0);
        bits.all.addEnum("Additional Payload Word", 0x2);
        bits.all.addEnum("Frame Len Word", 0x3);
        bits.all.addEnum("Num Blocks Word", 0x9);
        bits.all.addEnum("First Payload Word", 0xc);
        bits.all.addEnum("BLOCK_WORDS", 0x20);
        bits.all.addEnum("BLOCK_BYTES", 0x80);

    }
    RegTX_PORTOut_t& operator=(const RegTX_PORTOut_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegTX_PORTOut_t;

/** @brief Component definition for @ref TX_PORT0. */
typedef struct TX_PORT_t {
    /** @brief This is the memory range into which frames are directed towards the network by the APE firmware. */
    RegTX_PORTOut_t Out[2048];

#ifdef CXX_SIMULATOR
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    TX_PORT_t() : mIndexReadCallback(0), mIndexReadCallbackArgs(0), mIndexWriteCallback(0), mIndexWriteCallbackArgs(0)
    {
        for(int i = 0; i < 2048; i++)
        {
            Out[i].r32.setComponentOffset(0x0 + (i * 4));
        }
    }
    void print()
    {
        for(int i = 0; i < 2048; i++)
        {
            Out[i].print();
        }
    }
    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
} TX_PORT_t;

/** @brief TX to network port, function 0 */
extern APE_TX_PORT0_H_VOLATILE TX_PORT_t TX_PORT0;



#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#ifndef CXX_SIMULATOR
_Static_assert(sizeof(TX_PORT_t) == 8192, "sizeof(TX_PORT_t) must be 8192");
#endif

#endif /* !APE_TX_PORT0_H */

/** @} */
