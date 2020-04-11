////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_SDBCACHE.h
///
/// @project    bcm5719
///
/// @brief      bcm5719_SDBCACHE
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

/** @defgroup BCM5719_SDBCACHE_H    bcm5719_SDBCACHE */
/** @addtogroup BCM5719_SDBCACHE_H
 * @{
 */
#ifndef BCM5719_SDBCACHE_H
#define BCM5719_SDBCACHE_H

#include <types.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_bcm5719_SDBCACHE_sim(void* base);
void init_bcm5719_SDBCACHE(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> BCM5719_SDBCACHE_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> BCM5719_SDBCACHE_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> BCM5719_SDBCACHE_H_uint32_t;
#define BCM5719_SDBCACHE_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define BCM5719_SDBCACHE_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define BCM5719_SDBCACHE_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  BCM5719_SDBCACHE_H_uint8_t;
typedef uint16_t BCM5719_SDBCACHE_H_uint16_t;
typedef uint32_t BCM5719_SDBCACHE_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_SDBCACHE_BASE ((volatile void*)0x20000) /* SBD Cache */
#define REG_SDBCACHE_SIZE (0xc800)

#define REG_SDBCACHE_WORD ((volatile BCM5719_SDBCACHE_H_uint32_t*)0x20000) /*  */
/** @brief Register definition for @ref SDBCACHE_t.Word. */
typedef register_container RegSDBCACHEWord_t {
    /** @brief 32bit direct register access. */
    BCM5719_SDBCACHE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Word"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSDBCACHEWord_t()
    {
        /** @brief constructor for @ref SDBCACHE_t.Word. */
        r32.setName("Word");
    }
    RegSDBCACHEWord_t& operator=(const RegSDBCACHEWord_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSDBCACHEWord_t;

/** @brief Component definition for @ref SDBCACHE. */
typedef struct SDBCACHE_t {
    /** @brief  */
    RegSDBCACHEWord_t Word[12800];

#ifdef CXX_SIMULATOR
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    SDBCACHE_t() : mIndexReadCallback(0), mIndexReadCallbackArgs(0), mIndexWriteCallback(0), mIndexWriteCallbackArgs(0)
    {
        for(int i = 0; i < 12800; i++)
        {
            Word[i].r32.setComponentOffset(0x0 + (i * 4));
        }
    }
    void print()
    {
        for(int i = 0; i < 12800; i++)
        {
            Word[i].print();
        }
    }
    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
} SDBCACHE_t;

/** @brief SBD Cache */
extern volatile SDBCACHE_t SDBCACHE;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#ifndef CXX_SIMULATOR
_Static_assert(sizeof(SDBCACHE_t) == 51200, "sizeof(SDBCACHE_t) must be 51200");
#endif

#endif /* !BCM5719_SDBCACHE_H */

/** @} */
