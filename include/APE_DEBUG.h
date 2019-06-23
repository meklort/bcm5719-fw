////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_DEBUG.h
///
/// @project    ape
///
/// @brief      APE_DEBUG
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

/** @defgroup APE_DEBUG_H    APE_DEBUG */
/** @addtogroup APE_DEBUG_H
 * @{
 */
#ifndef APE_DEBUG_H
#define APE_DEBUG_H

#include <types.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_DEBUG_sim(void* base);
void init_APE_DEBUG(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_DEBUG_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_DEBUG_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_DEBUG_H_uint32_t;
#define APE_DEBUG_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_DEBUG_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_DEBUG_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_DEBUG_H_uint8_t;
typedef uint16_t APE_DEBUG_H_uint16_t;
typedef uint32_t APE_DEBUG_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_DEBUG_BASE ((volatile void*)0x60221000) /* Device SHM Registers, function 1 for debug */
#define REG_DEBUG_SIZE (sizeof(DEBUG_t))

#define REG_DEBUG_WRITE_POINTER ((volatile APE_DEBUG_H_uint32_t*)0x60221000) /* Offset in the debug buffer to write data. */
#define     DEBUG_WRITE_POINTER_OFFSET_SHIFT 0u
#define     DEBUG_WRITE_POINTER_OFFSET_MASK  0xffffffffu
#define GET_DEBUG_WRITE_POINTER_OFFSET(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_DEBUG_WRITE_POINTER_OFFSET(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref DEBUG_t.WritePointer. */
typedef register_container RegDEBUGWritePointer_t {
    /** @brief 32bit direct register access. */
    APE_DEBUG_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEBUG_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief All bits */
        BITFIELD_MEMBER(APE_DEBUG_H_uint32_t, offset, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief All bits */
        BITFIELD_MEMBER(APE_DEBUG_H_uint32_t, offset, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEBUG_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "WritePointer"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEBUGWritePointer_t()
    {
        /** @brief constructor for @ref DEBUG_t.WritePointer. */
        r32.setName("WritePointer");
        bits.offset.setBaseRegister(&r32);
        bits.offset.setName("offset");
    }
    RegDEBUGWritePointer_t& operator=(const RegDEBUGWritePointer_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEBUGWritePointer_t;

#define REG_DEBUG_READ_POINTER ((volatile APE_DEBUG_H_uint32_t*)0x60221004) /* Offset in the debug buffer to read data. */
#define     DEBUG_READ_POINTER_OFFSET_SHIFT 0u
#define     DEBUG_READ_POINTER_OFFSET_MASK  0xffffffffu
#define GET_DEBUG_READ_POINTER_OFFSET(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_DEBUG_READ_POINTER_OFFSET(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref DEBUG_t.ReadPointer. */
typedef register_container RegDEBUGReadPointer_t {
    /** @brief 32bit direct register access. */
    APE_DEBUG_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEBUG_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief All bits */
        BITFIELD_MEMBER(APE_DEBUG_H_uint32_t, offset, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief All bits */
        BITFIELD_MEMBER(APE_DEBUG_H_uint32_t, offset, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEBUG_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ReadPointer"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEBUGReadPointer_t()
    {
        /** @brief constructor for @ref DEBUG_t.ReadPointer. */
        r32.setName("ReadPointer");
        bits.offset.setBaseRegister(&r32);
        bits.offset.setName("offset");
    }
    RegDEBUGReadPointer_t& operator=(const RegDEBUGReadPointer_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEBUGReadPointer_t;

#define REG_DEBUG_BUFFER ((volatile APE_DEBUG_H_uint32_t*)0x60221008) /* Debug memory */
#define     DEBUG_BUFFER_ALL_SHIFT 0u
#define     DEBUG_BUFFER_ALL_MASK  0xffffffffu
#define GET_DEBUG_BUFFER_ALL(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_DEBUG_BUFFER_ALL(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref DEBUG_t.Buffer. */
typedef register_container RegDEBUGBuffer_t {
    /** @brief 32bit direct register access. */
    APE_DEBUG_H_uint32_t r32;

    BITFIELD_BEGIN(APE_DEBUG_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief All bits */
        BITFIELD_MEMBER(APE_DEBUG_H_uint32_t, all, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief All bits */
        BITFIELD_MEMBER(APE_DEBUG_H_uint32_t, all, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_DEBUG_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Buffer"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegDEBUGBuffer_t()
    {
        /** @brief constructor for @ref DEBUG_t.Buffer. */
        r32.setName("Buffer");
        bits.all.setBaseRegister(&r32);
        bits.all.setName("all");
    }
    RegDEBUGBuffer_t& operator=(const RegDEBUGBuffer_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegDEBUGBuffer_t;

/** @brief Component definition for @ref DEBUG. */
typedef struct DEBUG_t {
    /** @brief Offset in the debug buffer to write data. */
    RegDEBUGWritePointer_t WritePointer;

    /** @brief Offset in the debug buffer to read data. */
    RegDEBUGReadPointer_t ReadPointer;

    /** @brief Debug memory */
    RegDEBUGBuffer_t Buffer[1022];

#ifdef CXX_SIMULATOR
    DEBUG_t()
    {
        WritePointer.r32.setComponentOffset(0x0);
        ReadPointer.r32.setComponentOffset(0x4);
        for(int i = 0; i < 1022; i++)
        {
            Buffer[i].r32.setComponentOffset(0x8 + (i * 4));
        }
    }
    void print()
    {
        WritePointer.print();
        ReadPointer.print();
        for(int i = 0; i < 1022; i++)
        {
            Buffer[i].print();
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
} DEBUG_t;

/** @brief Device SHM Registers, function 1 for debug */
extern volatile DEBUG_t DEBUG;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !APE_DEBUG_H */

/** @} */
