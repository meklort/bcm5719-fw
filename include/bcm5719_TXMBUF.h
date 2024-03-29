////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_TXMBUF.h
///
/// @project    bcm5719
///
/// @brief      bcm5719_TXMBUF
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

/** @defgroup BCM5719_TXMBUF_H    bcm5719_TXMBUF */
/** @addtogroup BCM5719_TXMBUF_H
 * @{
 */
#ifndef BCM5719_TXMBUF_H
#define BCM5719_TXMBUF_H

#include <types.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_bcm5719_TXMBUF_sim(void* base, uint32_t (*read)(uint32_t val, uint32_t offset, void *args), uint32_t (*write)(uint32_t val, uint32_t offset, void *args));
void init_bcm5719_TXMBUF(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> BCM5719_TXMBUF_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> BCM5719_TXMBUF_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> BCM5719_TXMBUF_H_uint32_t;
#define BCM5719_TXMBUF_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define BCM5719_TXMBUF_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define BCM5719_TXMBUF_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define BCM5719_TXMBUF_H_VOLATILE
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  BCM5719_TXMBUF_H_uint8_t;
typedef uint16_t BCM5719_TXMBUF_H_uint16_t;
typedef uint32_t BCM5719_TXMBUF_H_uint32_t;
#define register_container union
#define BCM5719_TXMBUF_H_VOLATILE volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_TXMBUF_BASE ((volatile void*)0x2c800) /* TX MBuf */
#define REG_TXMBUF_SIZE (0x7400)

#define REG_TXMBUF_WORD ((BCM5719_TXMBUF_H_VOLATILE BCM5719_TXMBUF_H_uint32_t*)0x2c800) /*  */
/** @brief Register definition for @ref TXMBUF_t.Word. */
typedef register_container RegTXMBUFWord_t {
    /** @brief 32bit direct register access. */
    BCM5719_TXMBUF_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Word"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegTXMBUFWord_t()
    {
        /** @brief constructor for @ref TXMBUF_t.Word. */
        r32.setName("Word");
    }
    RegTXMBUFWord_t& operator=(const RegTXMBUFWord_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegTXMBUFWord_t;

/** @brief Component definition for @ref TXMBUF. */
typedef struct TXMBUF_t {
    /** @brief  */
    RegTXMBUFWord_t Word[7424];

#ifdef CXX_SIMULATOR
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    TXMBUF_t() : mIndexReadCallback(0), mIndexReadCallbackArgs(0), mIndexWriteCallback(0), mIndexWriteCallbackArgs(0)
    {
        for(int i = 0; i < 7424; i++)
        {
            Word[i].r32.setComponentOffset(0x0 + (i * 4));
        }
    }
    void print()
    {
        for(int i = 0; i < 7424; i++)
        {
            Word[i].print();
        }
    }
    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
} TXMBUF_t;

/** @brief TX MBuf */
extern BCM5719_TXMBUF_H_VOLATILE TXMBUF_t TXMBUF;



#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#ifndef CXX_SIMULATOR
_Static_assert(sizeof(TXMBUF_t) == 29696, "sizeof(TXMBUF_t) must be 29696");
#endif

#endif /* !BCM5719_TXMBUF_H */

/** @} */
