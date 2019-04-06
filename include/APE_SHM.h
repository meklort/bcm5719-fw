////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_SHM.h
///
/// @project    ape
///
/// @brief      APE_SHM
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

/** @defgroup APE_SHM_H    APE_SHM */
/** @addtogroup APE_SHM_H
 * @{
 */
#ifndef APE_SHM_H
#define APE_SHM_H

#include <stdint.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_SHM_mmap(void* base);
void init_APE_SHM(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_SHM_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_SHM_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_SHM_H_uint32_t;
#define APE_SHM_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_SHM_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_SHM_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_SHM_H_uint8_t;
typedef uint16_t APE_SHM_H_uint16_t;
typedef uint32_t APE_SHM_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_SHM_BASE ((volatile void*)0x60220000) /* Device SHM Registers, function 0 */
#define REG_SHM_SIZE (sizeof(SHM_t))

#define REG_SHM_SEG_SIG ((volatile APE_SHM_H_uint32_t*)0x60220000) /* APE_APE_MAGIC ('APE!') when all is well. */
#define     SHM_SEG_SIG_SIG_SHIFT 0u
#define     SHM_SEG_SIG_SIG_MASK  0xffffffffu
#define GET_SHM_SEG_SIG_SIG(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_SHM_SEG_SIG_SIG(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     SHM_SEG_SIG_SIG_LOADER 0x10ad10adu


/** @brief Register definition for @ref SHM_t.SegSig. */
typedef register_container RegSHMSegSig_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Sig, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Sig, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SegSig"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMSegSig_t()
    {
        /** @brief constructor for @ref SHM_t.SegSig. */
        r32.setName("SegSig");
        r32.setComponentOffset(0x0);
        bits.Sig.setBaseRegister(&r32);
        bits.Sig.setName("Sig");
        bits.Sig.setComponentOffset(0x0);
    }
    RegSHMSegSig_t& operator=(const RegSHMSegSig_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMSegSig_t;

#define REG_SHM_APE_SEG_LENGTH ((volatile APE_SHM_H_uint32_t*)0x60220004) /* Set to 0x34. */
/** @brief Register definition for @ref SHM_t.ApeSegLength. */
typedef register_container RegSHMApeSegLength_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ApeSegLength"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMApeSegLength_t()
    {
        /** @brief constructor for @ref SHM_t.ApeSegLength. */
        r32.setName("ApeSegLength");
        r32.setComponentOffset(0x4);
    }
    RegSHMApeSegLength_t& operator=(const RegSHMApeSegLength_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMApeSegLength_t;

#define REG_SHM_FW_STATUS ((volatile APE_SHM_H_uint32_t*)0x6022000c) /*  */
#define     SHM_FW_STATUS_READY_SHIFT 8u
#define     SHM_FW_STATUS_READY_MASK  0x100u
#define GET_SHM_FW_STATUS_READY(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_SHM_FW_STATUS_READY(__val__)  (((__val__) << 8u) & 0x100u)
#define     SHM_FW_STATUS_UNKNOWN_31_28_SHIFT 28u
#define     SHM_FW_STATUS_UNKNOWN_31_28_MASK  0xf0000000u
#define GET_SHM_FW_STATUS_UNKNOWN_31_28(__reg__)  (((__reg__) & 0xf0000000) >> 28u)
#define SET_SHM_FW_STATUS_UNKNOWN_31_28(__val__)  (((__val__) << 28u) & 0xf0000000u)

/** @brief Register definition for @ref SHM_t.FwStatus. */
typedef register_container RegSHMFwStatus_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_7_0, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Ready, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_27_9, 9, 19)
        /** @brief If this is all-ones, it appears to mean the APE FW is halted. */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, unknown_31_28, 28, 4)
#elif defined(__BIG_ENDIAN__)
        /** @brief If this is all-ones, it appears to mean the APE FW is halted. */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, unknown_31_28, 28, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_27_9, 9, 19)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Ready, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_7_0, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "FwStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMFwStatus_t()
    {
        /** @brief constructor for @ref SHM_t.FwStatus. */
        r32.setName("FwStatus");
        r32.setComponentOffset(0xc);
        bits.Ready.setBaseRegister(&r32);
        bits.Ready.setName("Ready");
        bits.Ready.setComponentOffset(0xc);
        bits.unknown_31_28.setBaseRegister(&r32);
        bits.unknown_31_28.setName("unknown_31_28");
        bits.unknown_31_28.setComponentOffset(0xc);
    }
    RegSHMFwStatus_t& operator=(const RegSHMFwStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMFwStatus_t;

#define REG_SHM_FW_FEATURES ((volatile APE_SHM_H_uint32_t*)0x60220010) /*  */
#define     SHM_FW_FEATURES_NCSI_SHIFT 1u
#define     SHM_FW_FEATURES_NCSI_MASK  0x2u
#define GET_SHM_FW_FEATURES_NCSI(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_FW_FEATURES_NCSI(__val__)  (((__val__) << 1u) & 0x2u)

/** @brief Register definition for @ref SHM_t.FwFeatures. */
typedef register_container RegSHMFwFeatures_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_0_0, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, NCSI, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_2, 2, 30)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_2, 2, 30)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, NCSI, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_0_0, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "FwFeatures"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMFwFeatures_t()
    {
        /** @brief constructor for @ref SHM_t.FwFeatures. */
        r32.setName("FwFeatures");
        r32.setComponentOffset(0x10);
        bits.NCSI.setBaseRegister(&r32);
        bits.NCSI.setName("NCSI");
        bits.NCSI.setComponentOffset(0x10);
    }
    RegSHMFwFeatures_t& operator=(const RegSHMFwFeatures_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMFwFeatures_t;

#define REG_SHM_4014 ((volatile APE_SHM_H_uint32_t*)0x60220014) /* Unknown. */
/** @brief Register definition for @ref SHM_t.4014. */
typedef register_container RegSHM4014_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "4014"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM4014_t()
    {
        /** @brief constructor for @ref SHM_t.4014. */
        r32.setName("4014");
        r32.setComponentOffset(0x14);
    }
    RegSHM4014_t& operator=(const RegSHM4014_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM4014_t;

#define REG_SHM_FW_VERSION ((volatile APE_SHM_H_uint32_t*)0x60220018) /*  */
#define     SHM_FW_VERSION_BUILD_SHIFT 0u
#define     SHM_FW_VERSION_BUILD_MASK  0xffu
#define GET_SHM_FW_VERSION_BUILD(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_SHM_FW_VERSION_BUILD(__val__)  (((__val__) << 0u) & 0xffu)
#define     SHM_FW_VERSION_REVISION_SHIFT 8u
#define     SHM_FW_VERSION_REVISION_MASK  0xff00u
#define GET_SHM_FW_VERSION_REVISION(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_SHM_FW_VERSION_REVISION(__val__)  (((__val__) << 8u) & 0xff00u)
#define     SHM_FW_VERSION_MINOR_SHIFT 16u
#define     SHM_FW_VERSION_MINOR_MASK  0xff0000u
#define GET_SHM_FW_VERSION_MINOR(__reg__)  (((__reg__) & 0xff0000) >> 16u)
#define SET_SHM_FW_VERSION_MINOR(__val__)  (((__val__) << 16u) & 0xff0000u)
#define     SHM_FW_VERSION_MAJOR_SHIFT 24u
#define     SHM_FW_VERSION_MAJOR_MASK  0xff000000u
#define GET_SHM_FW_VERSION_MAJOR(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_SHM_FW_VERSION_MAJOR(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref SHM_t.FwVersion. */
typedef register_container RegSHMFwVersion_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Build, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Revision, 8, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Minor, 16, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Major, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Major, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Minor, 16, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Revision, 8, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Build, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "FwVersion"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMFwVersion_t()
    {
        /** @brief constructor for @ref SHM_t.FwVersion. */
        r32.setName("FwVersion");
        r32.setComponentOffset(0x18);
        bits.Build.setBaseRegister(&r32);
        bits.Build.setName("Build");
        bits.Build.setComponentOffset(0x18);
        bits.Revision.setBaseRegister(&r32);
        bits.Revision.setName("Revision");
        bits.Revision.setComponentOffset(0x18);
        bits.Minor.setBaseRegister(&r32);
        bits.Minor.setName("Minor");
        bits.Minor.setComponentOffset(0x18);
        bits.Major.setBaseRegister(&r32);
        bits.Major.setName("Major");
        bits.Major.setComponentOffset(0x18);
    }
    RegSHMFwVersion_t& operator=(const RegSHMFwVersion_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMFwVersion_t;

#define REG_SHM_SEG_MESSAGE_BUFFER_OFFSET ((volatile APE_SHM_H_uint32_t*)0x6022001c) /* Specifies the offset of a scratchpad area, relative to the  start of the APE SHM area (i.e., relative to APE_REG(0x4000)). */
/** @brief Register definition for @ref SHM_t.SegMessageBufferOffset. */
typedef register_container RegSHMSegMessageBufferOffset_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SegMessageBufferOffset"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMSegMessageBufferOffset_t()
    {
        /** @brief constructor for @ref SHM_t.SegMessageBufferOffset. */
        r32.setName("SegMessageBufferOffset");
        r32.setComponentOffset(0x1c);
    }
    RegSHMSegMessageBufferOffset_t& operator=(const RegSHMSegMessageBufferOffset_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMSegMessageBufferOffset_t;

#define REG_SHM_SEG_MESSAGE_BUFFER_LENGTH ((volatile APE_SHM_H_uint32_t*)0x60220020) /* Specifies the size of the scratchpad area in bytes. */
/** @brief Register definition for @ref SHM_t.SegMessageBufferLength. */
typedef register_container RegSHMSegMessageBufferLength_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SegMessageBufferLength"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMSegMessageBufferLength_t()
    {
        /** @brief constructor for @ref SHM_t.SegMessageBufferLength. */
        r32.setName("SegMessageBufferLength");
        r32.setComponentOffset(0x20);
    }
    RegSHMSegMessageBufferLength_t& operator=(const RegSHMSegMessageBufferLength_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMSegMessageBufferLength_t;

#define REG_SHM_4024 ((volatile APE_SHM_H_uint32_t*)0x60220024) /* Unknown. Bootcode related. */
/** @brief Register definition for @ref SHM_t.4024. */
typedef register_container RegSHM4024_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "4024"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM4024_t()
    {
        /** @brief constructor for @ref SHM_t.4024. */
        r32.setName("4024");
        r32.setComponentOffset(0x24);
    }
    RegSHM4024_t& operator=(const RegSHM4024_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM4024_t;

#define REG_SHM_4028 ((volatile APE_SHM_H_uint32_t*)0x60220028) /* Unknown. Bootcode related. */
/** @brief Register definition for @ref SHM_t.4028. */
typedef register_container RegSHM4028_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "4028"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM4028_t()
    {
        /** @brief constructor for @ref SHM_t.4028. */
        r32.setName("4028");
        r32.setComponentOffset(0x28);
    }
    RegSHM4028_t& operator=(const RegSHM4028_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM4028_t;

#define REG_SHM_LOADER_COMMAND ((volatile APE_SHM_H_uint32_t*)0x60220038) /* Command sent when using the the APE loader. Zero once handled. */
#define     SHM_LOADER_COMMAND_COMMAND_SHIFT 0u
#define     SHM_LOADER_COMMAND_COMMAND_MASK  0xffffffffu
#define GET_SHM_LOADER_COMMAND_COMMAND(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_SHM_LOADER_COMMAND_COMMAND(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     SHM_LOADER_COMMAND_COMMAND_NOP 0x0u
#define     SHM_LOADER_COMMAND_COMMAND_READ_MEM 0x1u
#define     SHM_LOADER_COMMAND_COMMAND_WRITE_MEM 0x2u
#define     SHM_LOADER_COMMAND_COMMAND_CALL 0x3u


/** @brief Register definition for @ref SHM_t.LoaderCommand. */
typedef register_container RegSHMLoaderCommand_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Command, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Command, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LoaderCommand"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMLoaderCommand_t()
    {
        /** @brief constructor for @ref SHM_t.LoaderCommand. */
        r32.setName("LoaderCommand");
        r32.setComponentOffset(0x38);
        bits.Command.setBaseRegister(&r32);
        bits.Command.setName("Command");
        bits.Command.setComponentOffset(0x38);
    }
    RegSHMLoaderCommand_t& operator=(const RegSHMLoaderCommand_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMLoaderCommand_t;

#define REG_SHM_LOADER_ARG0 ((volatile APE_SHM_H_uint32_t*)0x6022003c) /* Argument 0 for the APE loader. */
/** @brief Register definition for @ref SHM_t.LoaderArg0. */
typedef register_container RegSHMLoaderArg0_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LoaderArg0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMLoaderArg0_t()
    {
        /** @brief constructor for @ref SHM_t.LoaderArg0. */
        r32.setName("LoaderArg0");
        r32.setComponentOffset(0x3c);
    }
    RegSHMLoaderArg0_t& operator=(const RegSHMLoaderArg0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMLoaderArg0_t;

#define REG_SHM_LOADER_ARG1 ((volatile APE_SHM_H_uint32_t*)0x60220040) /* Argument 1 for the APE loader. */
/** @brief Register definition for @ref SHM_t.LoaderArg1. */
typedef register_container RegSHMLoaderArg1_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LoaderArg1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMLoaderArg1_t()
    {
        /** @brief constructor for @ref SHM_t.LoaderArg1. */
        r32.setName("LoaderArg1");
        r32.setComponentOffset(0x40);
    }
    RegSHMLoaderArg1_t& operator=(const RegSHMLoaderArg1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMLoaderArg1_t;

#define REG_SHM_RCPU_SEG_SIG ((volatile APE_SHM_H_uint32_t*)0x60220100) /* Set to APE_RCPU_MAGIC ('RCPU') by RX CPU. */
#define     SHM_RCPU_SEG_SIG_SIG_SHIFT 0u
#define     SHM_RCPU_SEG_SIG_SIG_MASK  0xffffffffu
#define GET_SHM_RCPU_SEG_SIG_SIG(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_SHM_RCPU_SEG_SIG_SIG(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     SHM_RCPU_SEG_SIG_SIG_RCPU_MAGIC 0x52435055u


/** @brief Register definition for @ref SHM_t.RcpuSegSig. */
typedef register_container RegSHMRcpuSegSig_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Sig, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Sig, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuSegSig"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuSegSig_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuSegSig. */
        r32.setName("RcpuSegSig");
        r32.setComponentOffset(0x100);
        bits.Sig.setBaseRegister(&r32);
        bits.Sig.setName("Sig");
        bits.Sig.setComponentOffset(0x100);
    }
    RegSHMRcpuSegSig_t& operator=(const RegSHMRcpuSegSig_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuSegSig_t;

#define REG_SHM_RCPU_SEG_LENGTH ((volatile APE_SHM_H_uint32_t*)0x60220104) /* Set to 0x34. */
/** @brief Register definition for @ref SHM_t.RcpuSegLength. */
typedef register_container RegSHMRcpuSegLength_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuSegLength"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuSegLength_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuSegLength. */
        r32.setName("RcpuSegLength");
        r32.setComponentOffset(0x104);
    }
    RegSHMRcpuSegLength_t& operator=(const RegSHMRcpuSegLength_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuSegLength_t;

#define REG_SHM_RCPU_INIT_COUNT ((volatile APE_SHM_H_uint32_t*)0x60220108) /* Incremented by RX CPU every boot. */
/** @brief Register definition for @ref SHM_t.RcpuInitCount. */
typedef register_container RegSHMRcpuInitCount_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuInitCount"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuInitCount_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuInitCount. */
        r32.setName("RcpuInitCount");
        r32.setComponentOffset(0x108);
    }
    RegSHMRcpuInitCount_t& operator=(const RegSHMRcpuInitCount_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuInitCount_t;

#define REG_SHM_RCPU_FW_VERSION ((volatile APE_SHM_H_uint32_t*)0x6022010c) /* Set to the bootcode version. e.g. 0x0127 -> v1.39. */
/** @brief Register definition for @ref SHM_t.RcpuFwVersion. */
typedef register_container RegSHMRcpuFwVersion_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuFwVersion"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuFwVersion_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuFwVersion. */
        r32.setName("RcpuFwVersion");
        r32.setComponentOffset(0x10c);
    }
    RegSHMRcpuFwVersion_t& operator=(const RegSHMRcpuFwVersion_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuFwVersion_t;

#define REG_SHM_RCPU_CFG_FEATURE ((volatile APE_SHM_H_uint32_t*)0x60220110) /* Set to  */
/** @brief Register definition for @ref SHM_t.RcpuCfgFeature. */
typedef register_container RegSHMRcpuCfgFeature_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuCfgFeature"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuCfgFeature_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuCfgFeature. */
        r32.setName("RcpuCfgFeature");
        r32.setComponentOffset(0x110);
    }
    RegSHMRcpuCfgFeature_t& operator=(const RegSHMRcpuCfgFeature_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuCfgFeature_t;

#define REG_SHM_RCPU_PCI_VENDOR_DEVICE_ID ((volatile APE_SHM_H_uint32_t*)0x60220114) /* Set to PCI Vendor/Device ID by S2. */
/** @brief Register definition for @ref SHM_t.RcpuPciVendorDeviceId. */
typedef register_container RegSHMRcpuPciVendorDeviceId_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuPciVendorDeviceId"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuPciVendorDeviceId_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuPciVendorDeviceId. */
        r32.setName("RcpuPciVendorDeviceId");
        r32.setComponentOffset(0x114);
    }
    RegSHMRcpuPciVendorDeviceId_t& operator=(const RegSHMRcpuPciVendorDeviceId_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuPciVendorDeviceId_t;

#define REG_SHM_RCPU_PCI_SUBSYSTEM_ID ((volatile APE_SHM_H_uint32_t*)0x60220118) /* Set to PCI Subsystem Vendor/Subsystem ID by S2. */
/** @brief Register definition for @ref SHM_t.RcpuPciSubsystemId. */
typedef register_container RegSHMRcpuPciSubsystemId_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuPciSubsystemId"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuPciSubsystemId_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuPciSubsystemId. */
        r32.setName("RcpuPciSubsystemId");
        r32.setComponentOffset(0x118);
    }
    RegSHMRcpuPciSubsystemId_t& operator=(const RegSHMRcpuPciSubsystemId_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuPciSubsystemId_t;

#define REG_SHM_RCPU_APE_RESET_COUNT ((volatile APE_SHM_H_uint32_t*)0x6022011c) /* Unknown. Incremented by frobnicating routine. */
/** @brief Register definition for @ref SHM_t.RcpuApeResetCount. */
typedef register_container RegSHMRcpuApeResetCount_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuApeResetCount"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuApeResetCount_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuApeResetCount. */
        r32.setName("RcpuApeResetCount");
        r32.setComponentOffset(0x11c);
    }
    RegSHMRcpuApeResetCount_t& operator=(const RegSHMRcpuApeResetCount_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuApeResetCount_t;

#define REG_SHM_RCPU_LAST_APE_STATUS ((volatile APE_SHM_H_uint32_t*)0x60220120) /* Unknown. Written by frobnicating routine. */
/** @brief Register definition for @ref SHM_t.RcpuLastApeStatus. */
typedef register_container RegSHMRcpuLastApeStatus_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuLastApeStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuLastApeStatus_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuLastApeStatus. */
        r32.setName("RcpuLastApeStatus");
        r32.setComponentOffset(0x120);
    }
    RegSHMRcpuLastApeStatus_t& operator=(const RegSHMRcpuLastApeStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuLastApeStatus_t;

#define REG_SHM_RCPU_LAST_APE_FW_STATUS ((volatile APE_SHM_H_uint32_t*)0x60220124) /* Unknown.  */
/** @brief Register definition for @ref SHM_t.RcpuLastApeFwStatus. */
typedef register_container RegSHMRcpuLastApeFwStatus_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuLastApeFwStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuLastApeFwStatus_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuLastApeFwStatus. */
        r32.setName("RcpuLastApeFwStatus");
        r32.setComponentOffset(0x124);
    }
    RegSHMRcpuLastApeFwStatus_t& operator=(const RegSHMRcpuLastApeFwStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuLastApeFwStatus_t;

#define REG_SHM_RCPU_CFG_HW ((volatile APE_SHM_H_uint32_t*)0x60220128) /* Set from  */
/** @brief Register definition for @ref SHM_t.RcpuCfgHw. */
typedef register_container RegSHMRcpuCfgHw_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuCfgHw"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuCfgHw_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuCfgHw. */
        r32.setName("RcpuCfgHw");
        r32.setComponentOffset(0x128);
    }
    RegSHMRcpuCfgHw_t& operator=(const RegSHMRcpuCfgHw_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuCfgHw_t;

#define REG_SHM_RCPU_CFG_HW_2 ((volatile APE_SHM_H_uint32_t*)0x6022012c) /* Set from  */
/** @brief Register definition for @ref SHM_t.RcpuCfgHw2. */
typedef register_container RegSHMRcpuCfgHw2_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuCfgHw2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuCfgHw2_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuCfgHw2. */
        r32.setName("RcpuCfgHw2");
        r32.setComponentOffset(0x12c);
    }
    RegSHMRcpuCfgHw2_t& operator=(const RegSHMRcpuCfgHw2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuCfgHw2_t;

#define REG_SHM_RCPU_CPMU_STATUS ((volatile APE_SHM_H_uint32_t*)0x60220130) /* Set from  */
#define     SHM_RCPU_CPMU_STATUS_ADDRESS_SHIFT 0u
#define     SHM_RCPU_CPMU_STATUS_ADDRESS_MASK  0xffffu
#define GET_SHM_RCPU_CPMU_STATUS_ADDRESS(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_SHM_RCPU_CPMU_STATUS_ADDRESS(__val__)  (((__val__) << 0u) & 0xffffu)
#define     SHM_RCPU_CPMU_STATUS_ADDRESS_ADDRESS 0x362cu

#define     SHM_RCPU_CPMU_STATUS_STATUS_SHIFT 16u
#define     SHM_RCPU_CPMU_STATUS_STATUS_MASK  0xffff0000u
#define GET_SHM_RCPU_CPMU_STATUS_STATUS(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_SHM_RCPU_CPMU_STATUS_STATUS(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref SHM_t.RcpuCpmuStatus. */
typedef register_container RegSHMRcpuCpmuStatus_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Address, 0, 16)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Status, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Status, 16, 16)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Address, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuCpmuStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuCpmuStatus_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuCpmuStatus. */
        r32.setName("RcpuCpmuStatus");
        r32.setComponentOffset(0x130);
        bits.Address.setBaseRegister(&r32);
        bits.Address.setName("Address");
        bits.Address.setComponentOffset(0x130);
        bits.Status.setBaseRegister(&r32);
        bits.Status.setName("Status");
        bits.Status.setComponentOffset(0x130);
    }
    RegSHMRcpuCpmuStatus_t& operator=(const RegSHMRcpuCpmuStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuCpmuStatus_t;

#define REG_SHM_HOST_SEG_SIG ((volatile APE_SHM_H_uint32_t*)0x60220200) /* Set to APE_HOST_MAGIC ('HOST') to indicate the section is valid. */
/** @brief Register definition for @ref SHM_t.HostSegSig. */
typedef register_container RegSHMHostSegSig_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HostSegSig"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHostSegSig_t()
    {
        /** @brief constructor for @ref SHM_t.HostSegSig. */
        r32.setName("HostSegSig");
        r32.setComponentOffset(0x200);
    }
    RegSHMHostSegSig_t& operator=(const RegSHMHostSegSig_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHostSegSig_t;

#define REG_SHM_HOST_SEG_LEN ((volatile APE_SHM_H_uint32_t*)0x60220204) /* Set to 0x20. */
/** @brief Register definition for @ref SHM_t.HostSegLen. */
typedef register_container RegSHMHostSegLen_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HostSegLen"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHostSegLen_t()
    {
        /** @brief constructor for @ref SHM_t.HostSegLen. */
        r32.setName("HostSegLen");
        r32.setComponentOffset(0x204);
    }
    RegSHMHostSegLen_t& operator=(const RegSHMHostSegLen_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHostSegLen_t;

#define REG_SHM_HOST_INIT_COUNT ((volatile APE_SHM_H_uint32_t*)0x60220208) /* Incremented by host on every initialization. */
/** @brief Register definition for @ref SHM_t.HostInitCount. */
typedef register_container RegSHMHostInitCount_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HostInitCount"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHostInitCount_t()
    {
        /** @brief constructor for @ref SHM_t.HostInitCount. */
        r32.setName("HostInitCount");
        r32.setComponentOffset(0x208);
    }
    RegSHMHostInitCount_t& operator=(const RegSHMHostInitCount_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHostInitCount_t;

#define REG_SHM_HOST_DRIVER_ID ((volatile APE_SHM_H_uint32_t*)0x6022020c) /* Linux sets this to 0xF0MM_mm00, where M is the major version  of Linux and m is the minor version. */
/** @brief Register definition for @ref SHM_t.HostDriverId. */
typedef register_container RegSHMHostDriverId_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HostDriverId"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHostDriverId_t()
    {
        /** @brief constructor for @ref SHM_t.HostDriverId. */
        r32.setName("HostDriverId");
        r32.setComponentOffset(0x20c);
    }
    RegSHMHostDriverId_t& operator=(const RegSHMHostDriverId_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHostDriverId_t;

#define REG_SHM_HOST_BEHAVIOR ((volatile APE_SHM_H_uint32_t*)0x60220210) /*  */
#define     SHM_HOST_BEHAVIOR_NO_PHYLOCK_SHIFT 0u
#define     SHM_HOST_BEHAVIOR_NO_PHYLOCK_MASK  0x1u
#define GET_SHM_HOST_BEHAVIOR_NO_PHYLOCK(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_HOST_BEHAVIOR_NO_PHYLOCK(__val__)  (((__val__) << 0u) & 0x1u)

/** @brief Register definition for @ref SHM_t.HostBehavior. */
typedef register_container RegSHMHostBehavior_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, NoPHYLock, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_1, 1, 31)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_1, 1, 31)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, NoPHYLock, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HostBehavior"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHostBehavior_t()
    {
        /** @brief constructor for @ref SHM_t.HostBehavior. */
        r32.setName("HostBehavior");
        r32.setComponentOffset(0x210);
        bits.NoPHYLock.setBaseRegister(&r32);
        bits.NoPHYLock.setName("NoPHYLock");
        bits.NoPHYLock.setComponentOffset(0x210);
    }
    RegSHMHostBehavior_t& operator=(const RegSHMHostBehavior_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHostBehavior_t;

#define REG_SHM_HEARTBEAT_INTERVAL ((volatile APE_SHM_H_uint32_t*)0x60220214) /* In milliseconds. Set to 0 to disable heartbeating. */
/** @brief Register definition for @ref SHM_t.HeartbeatInterval. */
typedef register_container RegSHMHeartbeatInterval_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HeartbeatInterval"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHeartbeatInterval_t()
    {
        /** @brief constructor for @ref SHM_t.HeartbeatInterval. */
        r32.setName("HeartbeatInterval");
        r32.setComponentOffset(0x214);
    }
    RegSHMHeartbeatInterval_t& operator=(const RegSHMHeartbeatInterval_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHeartbeatInterval_t;

#define REG_SHM_HEARTBEAT_COUNT ((volatile APE_SHM_H_uint32_t*)0x60220218) /*  */
/** @brief Register definition for @ref SHM_t.HeartbeatCount. */
typedef register_container RegSHMHeartbeatCount_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HeartbeatCount"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHeartbeatCount_t()
    {
        /** @brief constructor for @ref SHM_t.HeartbeatCount. */
        r32.setName("HeartbeatCount");
        r32.setComponentOffset(0x218);
    }
    RegSHMHeartbeatCount_t& operator=(const RegSHMHeartbeatCount_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHeartbeatCount_t;

#define REG_SHM_HOST_DRIVER_STATE ((volatile APE_SHM_H_uint32_t*)0x6022021c) /*  */
/** @brief Register definition for @ref SHM_t.HostDriverState. */
typedef register_container RegSHMHostDriverState_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HostDriverState"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHostDriverState_t()
    {
        /** @brief constructor for @ref SHM_t.HostDriverState. */
        r32.setName("HostDriverState");
        r32.setComponentOffset(0x21c);
    }
    RegSHMHostDriverState_t& operator=(const RegSHMHostDriverState_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHostDriverState_t;

#define REG_SHM_WOL_SPEED ((volatile APE_SHM_H_uint32_t*)0x60220224) /*  */
/** @brief Register definition for @ref SHM_t.WolSpeed. */
typedef register_container RegSHMWolSpeed_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "WolSpeed"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMWolSpeed_t()
    {
        /** @brief constructor for @ref SHM_t.WolSpeed. */
        r32.setName("WolSpeed");
        r32.setComponentOffset(0x224);
    }
    RegSHMWolSpeed_t& operator=(const RegSHMWolSpeed_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMWolSpeed_t;

#define REG_SHM_EVENT_STATUS ((volatile APE_SHM_H_uint32_t*)0x60220300) /*  */
#define     SHM_EVENT_STATUS_DRIVER_EVENT_SHIFT 4u
#define     SHM_EVENT_STATUS_DRIVER_EVENT_MASK  0x10u
#define GET_SHM_EVENT_STATUS_DRIVER_EVENT(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_SHM_EVENT_STATUS_DRIVER_EVENT(__val__)  (((__val__) << 4u) & 0x10u)
#define     SHM_EVENT_STATUS_COMMAND_SHIFT 8u
#define     SHM_EVENT_STATUS_COMMAND_MASK  0xff00u
#define GET_SHM_EVENT_STATUS_COMMAND(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_SHM_EVENT_STATUS_COMMAND(__val__)  (((__val__) << 8u) & 0xff00u)
#define     SHM_EVENT_STATUS_COMMAND_STATE_CHANGE 0x5u
#define     SHM_EVENT_STATUS_COMMAND_SCRATCHPAD_READ 0x16u
#define     SHM_EVENT_STATUS_COMMAND_SCRATCHPAD_WRITE 0x17u

#define     SHM_EVENT_STATUS_STATE_SHIFT 16u
#define     SHM_EVENT_STATUS_STATE_MASK  0x70000u
#define GET_SHM_EVENT_STATUS_STATE(__reg__)  (((__reg__) & 0x70000) >> 16u)
#define SET_SHM_EVENT_STATUS_STATE(__val__)  (((__val__) << 16u) & 0x70000u)
#define     SHM_EVENT_STATUS_STATE_START 0x1u
#define     SHM_EVENT_STATUS_STATE_UNLOAD 0x2u
#define     SHM_EVENT_STATUS_STATE_WOL 0x3u
#define     SHM_EVENT_STATUS_STATE_SUSPEND 0x4u

#define     SHM_EVENT_STATUS_PENDING_SHIFT 31u
#define     SHM_EVENT_STATUS_PENDING_MASK  0x80000000u
#define GET_SHM_EVENT_STATUS_PENDING(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_SHM_EVENT_STATUS_PENDING(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref SHM_t.EventStatus. */
typedef register_container RegSHMEventStatus_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_3_0, 0, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, DriverEvent, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Command, 8, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, State, 16, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_30_19, 19, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Pending, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Pending, 31, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_30_19, 19, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, State, 16, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Command, 8, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, DriverEvent, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_3_0, 0, 4)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EventStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMEventStatus_t()
    {
        /** @brief constructor for @ref SHM_t.EventStatus. */
        r32.setName("EventStatus");
        r32.setComponentOffset(0x300);
        bits.DriverEvent.setBaseRegister(&r32);
        bits.DriverEvent.setName("DriverEvent");
        bits.DriverEvent.setComponentOffset(0x300);
        bits.Command.setBaseRegister(&r32);
        bits.Command.setName("Command");
        bits.Command.setComponentOffset(0x300);
        bits.State.setBaseRegister(&r32);
        bits.State.setName("State");
        bits.State.setComponentOffset(0x300);
        bits.Pending.setBaseRegister(&r32);
        bits.Pending.setName("Pending");
        bits.Pending.setComponentOffset(0x300);
    }
    RegSHMEventStatus_t& operator=(const RegSHMEventStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMEventStatus_t;

#define REG_SHM_PROT_MAGIC ((volatile APE_SHM_H_uint32_t*)0x60220308) /* This is set to APE_PROT_MAGIC ('PROT') on all functions.  If it is 'PROT', the following fields (MAC0_HIGH/LOW) are valid */
/** @brief Register definition for @ref SHM_t.ProtMagic. */
typedef register_container RegSHMProtMagic_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ProtMagic"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMProtMagic_t()
    {
        /** @brief constructor for @ref SHM_t.ProtMagic. */
        r32.setName("ProtMagic");
        r32.setComponentOffset(0x308);
    }
    RegSHMProtMagic_t& operator=(const RegSHMProtMagic_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMProtMagic_t;

#define REG_SHM_PROT_MAC0_HIGH ((volatile APE_SHM_H_uint32_t*)0x60220314) /* High 16 bits of MAC address 0. Only valid if  */
/** @brief Register definition for @ref SHM_t.ProtMac0High. */
typedef register_container RegSHMProtMac0High_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ProtMac0High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMProtMac0High_t()
    {
        /** @brief constructor for @ref SHM_t.ProtMac0High. */
        r32.setName("ProtMac0High");
        r32.setComponentOffset(0x314);
    }
    RegSHMProtMac0High_t& operator=(const RegSHMProtMac0High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMProtMac0High_t;

#define REG_SHM_PROT_MAC0_LOW ((volatile APE_SHM_H_uint32_t*)0x60220318) /* Low 16 bits of MAC address 0. */
/** @brief Register definition for @ref SHM_t.ProtMac0Low. */
typedef register_container RegSHMProtMac0Low_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ProtMac0Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMProtMac0Low_t()
    {
        /** @brief constructor for @ref SHM_t.ProtMac0Low. */
        r32.setName("ProtMac0Low");
        r32.setComponentOffset(0x318);
    }
    RegSHMProtMac0Low_t& operator=(const RegSHMProtMac0Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMProtMac0Low_t;

#define REG_SHM_NCSI_SIG ((volatile APE_SHM_H_uint32_t*)0x60220800) /* Set to NCSI_MAGIC ('NCSI') by APE firmware. NOTE: all words in the NCSI section are available in the function 0 SHM area only. */
/** @brief Register definition for @ref SHM_t.NcsiSig. */
typedef register_container RegSHMNcsiSig_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiSig"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiSig_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiSig. */
        r32.setName("NcsiSig");
        r32.setComponentOffset(0x800);
    }
    RegSHMNcsiSig_t& operator=(const RegSHMNcsiSig_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiSig_t;

#define REG_SHM_NCSI_BUILD_TIME ((volatile APE_SHM_H_uint32_t*)0x60220810) /* ASCII string spanning three 32-bit words. Unused trailing bytes   are set to zero. */
/** @brief Register definition for @ref SHM_t.NcsiBuildTime. */
typedef register_container RegSHMNcsiBuildTime_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiBuildTime"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiBuildTime_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiBuildTime. */
        r32.setName("NcsiBuildTime");
        r32.setComponentOffset(0x810);
    }
    RegSHMNcsiBuildTime_t& operator=(const RegSHMNcsiBuildTime_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiBuildTime_t;

#define REG_SHM_NCSI_BUILD_TIME_2 ((volatile APE_SHM_H_uint32_t*)0x60220814) /*  */
/** @brief Register definition for @ref SHM_t.NcsiBuildTime2. */
typedef register_container RegSHMNcsiBuildTime2_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiBuildTime2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiBuildTime2_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiBuildTime2. */
        r32.setName("NcsiBuildTime2");
        r32.setComponentOffset(0x814);
    }
    RegSHMNcsiBuildTime2_t& operator=(const RegSHMNcsiBuildTime2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiBuildTime2_t;

#define REG_SHM_NCSI_BUILD_TIME_3 ((volatile APE_SHM_H_uint32_t*)0x60220818) /*  */
/** @brief Register definition for @ref SHM_t.NcsiBuildTime3. */
typedef register_container RegSHMNcsiBuildTime3_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiBuildTime3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiBuildTime3_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiBuildTime3. */
        r32.setName("NcsiBuildTime3");
        r32.setComponentOffset(0x818);
    }
    RegSHMNcsiBuildTime3_t& operator=(const RegSHMNcsiBuildTime3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiBuildTime3_t;

#define REG_SHM_NCSI_BUILD_DATE ((volatile APE_SHM_H_uint32_t*)0x6022081c) /* ASCII string spanning three 32-bit words. Unused trailing bytes   are set to zero. */
/** @brief Register definition for @ref SHM_t.NcsiBuildDate. */
typedef register_container RegSHMNcsiBuildDate_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiBuildDate"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiBuildDate_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiBuildDate. */
        r32.setName("NcsiBuildDate");
        r32.setComponentOffset(0x81c);
    }
    RegSHMNcsiBuildDate_t& operator=(const RegSHMNcsiBuildDate_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiBuildDate_t;

#define REG_SHM_NCSI_BUILD_DATE_2 ((volatile APE_SHM_H_uint32_t*)0x60220820) /*  */
/** @brief Register definition for @ref SHM_t.NcsiBuildDate2. */
typedef register_container RegSHMNcsiBuildDate2_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiBuildDate2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiBuildDate2_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiBuildDate2. */
        r32.setName("NcsiBuildDate2");
        r32.setComponentOffset(0x820);
    }
    RegSHMNcsiBuildDate2_t& operator=(const RegSHMNcsiBuildDate2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiBuildDate2_t;

#define REG_SHM_NCSI_BUILD_DATE_3 ((volatile APE_SHM_H_uint32_t*)0x60220824) /*  */
/** @brief Register definition for @ref SHM_t.NcsiBuildDate3. */
typedef register_container RegSHMNcsiBuildDate3_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiBuildDate3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiBuildDate3_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiBuildDate3. */
        r32.setName("NcsiBuildDate3");
        r32.setComponentOffset(0x824);
    }
    RegSHMNcsiBuildDate3_t& operator=(const RegSHMNcsiBuildDate3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiBuildDate3_t;

#define REG_SHM_CHIP_ID ((volatile APE_SHM_H_uint32_t*)0x60220890) /* The APE code copies the contents of Chip ID to this word */
/** @brief Register definition for @ref SHM_t.ChipId. */
typedef register_container RegSHMChipId_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ChipId"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMChipId_t()
    {
        /** @brief constructor for @ref SHM_t.ChipId. */
        r32.setName("ChipId");
        r32.setComponentOffset(0x890);
    }
    RegSHMChipId_t& operator=(const RegSHMChipId_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMChipId_t;

#define REG_SHM_NCSI_CHANNEL0_INFO ((volatile APE_SHM_H_uint32_t*)0x60220900) /*  */
#define     SHM_NCSI_CHANNEL0_INFO_ENABLED_SHIFT 0u
#define     SHM_NCSI_CHANNEL0_INFO_ENABLED_MASK  0x1u
#define GET_SHM_NCSI_CHANNEL0_INFO_ENABLED(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_NCSI_CHANNEL0_INFO_ENABLED(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_NCSI_CHANNEL0_INFO_TX_PASSTHROUGH_SHIFT 1u
#define     SHM_NCSI_CHANNEL0_INFO_TX_PASSTHROUGH_MASK  0x2u
#define GET_SHM_NCSI_CHANNEL0_INFO_TX_PASSTHROUGH(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_NCSI_CHANNEL0_INFO_TX_PASSTHROUGH(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_NCSI_CHANNEL0_INFO_READY_SHIFT 2u
#define     SHM_NCSI_CHANNEL0_INFO_READY_MASK  0x4u
#define GET_SHM_NCSI_CHANNEL0_INFO_READY(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_NCSI_CHANNEL0_INFO_READY(__val__)  (((__val__) << 2u) & 0x4u)
#define     SHM_NCSI_CHANNEL0_INFO_INIT_SHIFT 3u
#define     SHM_NCSI_CHANNEL0_INFO_INIT_MASK  0x8u
#define GET_SHM_NCSI_CHANNEL0_INFO_INIT(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_SHM_NCSI_CHANNEL0_INFO_INIT(__val__)  (((__val__) << 3u) & 0x8u)
#define     SHM_NCSI_CHANNEL0_INFO_MFILT_SHIFT 4u
#define     SHM_NCSI_CHANNEL0_INFO_MFILT_MASK  0x10u
#define GET_SHM_NCSI_CHANNEL0_INFO_MFILT(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_SHM_NCSI_CHANNEL0_INFO_MFILT(__val__)  (((__val__) << 4u) & 0x10u)
#define     SHM_NCSI_CHANNEL0_INFO_BFILT_SHIFT 5u
#define     SHM_NCSI_CHANNEL0_INFO_BFILT_MASK  0x20u
#define GET_SHM_NCSI_CHANNEL0_INFO_BFILT(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_SHM_NCSI_CHANNEL0_INFO_BFILT(__val__)  (((__val__) << 5u) & 0x20u)
#define     SHM_NCSI_CHANNEL0_INFO_SERDES_SHIFT 6u
#define     SHM_NCSI_CHANNEL0_INFO_SERDES_MASK  0x40u
#define GET_SHM_NCSI_CHANNEL0_INFO_SERDES(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_SHM_NCSI_CHANNEL0_INFO_SERDES(__val__)  (((__val__) << 6u) & 0x40u)
#define     SHM_NCSI_CHANNEL0_INFO_VLAN_SHIFT 8u
#define     SHM_NCSI_CHANNEL0_INFO_VLAN_MASK  0x100u
#define GET_SHM_NCSI_CHANNEL0_INFO_VLAN(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_SHM_NCSI_CHANNEL0_INFO_VLAN(__val__)  (((__val__) << 8u) & 0x100u)
#define     SHM_NCSI_CHANNEL0_INFO_B2H_SHIFT 10u
#define     SHM_NCSI_CHANNEL0_INFO_B2H_MASK  0x400u
#define GET_SHM_NCSI_CHANNEL0_INFO_B2H(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_SHM_NCSI_CHANNEL0_INFO_B2H(__val__)  (((__val__) << 10u) & 0x400u)
#define     SHM_NCSI_CHANNEL0_INFO_B2N_SHIFT 11u
#define     SHM_NCSI_CHANNEL0_INFO_B2N_MASK  0x800u
#define GET_SHM_NCSI_CHANNEL0_INFO_B2N(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_SHM_NCSI_CHANNEL0_INFO_B2N(__val__)  (((__val__) << 11u) & 0x800u)
#define     SHM_NCSI_CHANNEL0_INFO_EEE_SHIFT 12u
#define     SHM_NCSI_CHANNEL0_INFO_EEE_MASK  0x1000u
#define GET_SHM_NCSI_CHANNEL0_INFO_EEE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_SHM_NCSI_CHANNEL0_INFO_EEE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     SHM_NCSI_CHANNEL0_INFO_DRIVER_SHIFT 14u
#define     SHM_NCSI_CHANNEL0_INFO_DRIVER_MASK  0x4000u
#define GET_SHM_NCSI_CHANNEL0_INFO_DRIVER(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_SHM_NCSI_CHANNEL0_INFO_DRIVER(__val__)  (((__val__) << 14u) & 0x4000u)
#define     SHM_NCSI_CHANNEL0_INFO_PDEAD_SHIFT 15u
#define     SHM_NCSI_CHANNEL0_INFO_PDEAD_MASK  0x8000u
#define GET_SHM_NCSI_CHANNEL0_INFO_PDEAD(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_SHM_NCSI_CHANNEL0_INFO_PDEAD(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref SHM_t.NcsiChannel0Info. */
typedef register_container RegSHMNcsiChannel0Info_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief This can be modified via NCSI SELECT PACKAGE and NCSI DESELECT PACKAGE. */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Enabled, 0, 1)
        /** @brief TX passthrough has been enabled by BMC NCSI command. */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, TXPassthrough, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Ready, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Init, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, MFILT, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, BFILT, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, SERDES, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, VLAN, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_9_9, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, B2H, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, B2N, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, EEE, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_13_13, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Driver, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, PDead, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_16, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_16, 16, 16)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, PDead, 15, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Driver, 14, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_13_13, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, EEE, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, B2N, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, B2H, 10, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_9_9, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, VLAN, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, SERDES, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, BFILT, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, MFILT, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Init, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Ready, 2, 1)
        /** @brief TX passthrough has been enabled by BMC NCSI command. */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, TXPassthrough, 1, 1)
        /** @brief This can be modified via NCSI SELECT PACKAGE and NCSI DESELECT PACKAGE. */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Enabled, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Info"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Info_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Info. */
        r32.setName("NcsiChannel0Info");
        r32.setComponentOffset(0x900);
        bits.Enabled.setBaseRegister(&r32);
        bits.Enabled.setName("Enabled");
        bits.Enabled.setComponentOffset(0x900);
        bits.TXPassthrough.setBaseRegister(&r32);
        bits.TXPassthrough.setName("TXPassthrough");
        bits.TXPassthrough.setComponentOffset(0x900);
        bits.Ready.setBaseRegister(&r32);
        bits.Ready.setName("Ready");
        bits.Ready.setComponentOffset(0x900);
        bits.Init.setBaseRegister(&r32);
        bits.Init.setName("Init");
        bits.Init.setComponentOffset(0x900);
        bits.MFILT.setBaseRegister(&r32);
        bits.MFILT.setName("MFILT");
        bits.MFILT.setComponentOffset(0x900);
        bits.BFILT.setBaseRegister(&r32);
        bits.BFILT.setName("BFILT");
        bits.BFILT.setComponentOffset(0x900);
        bits.SERDES.setBaseRegister(&r32);
        bits.SERDES.setName("SERDES");
        bits.SERDES.setComponentOffset(0x900);
        bits.VLAN.setBaseRegister(&r32);
        bits.VLAN.setName("VLAN");
        bits.VLAN.setComponentOffset(0x900);
        bits.B2H.setBaseRegister(&r32);
        bits.B2H.setName("B2H");
        bits.B2H.setComponentOffset(0x900);
        bits.B2N.setBaseRegister(&r32);
        bits.B2N.setName("B2N");
        bits.B2N.setComponentOffset(0x900);
        bits.EEE.setBaseRegister(&r32);
        bits.EEE.setName("EEE");
        bits.EEE.setComponentOffset(0x900);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x900);
        bits.PDead.setBaseRegister(&r32);
        bits.PDead.setName("PDead");
        bits.PDead.setComponentOffset(0x900);
    }
    RegSHMNcsiChannel0Info_t& operator=(const RegSHMNcsiChannel0Info_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Info_t;

#define REG_SHM_NCSI_CHANNEL0_MCID ((volatile APE_SHM_H_uint32_t*)0x60220904) /* AEN Management Controller ID, set by BMC when sending AEN ENABLE command and used when sending AENs. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mcid. */
typedef register_container RegSHMNcsiChannel0Mcid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mcid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mcid_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mcid. */
        r32.setName("NcsiChannel0Mcid");
        r32.setComponentOffset(0x904);
    }
    RegSHMNcsiChannel0Mcid_t& operator=(const RegSHMNcsiChannel0Mcid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mcid_t;

#define REG_SHM_NCSI_CHANNEL0_AEN ((volatile APE_SHM_H_uint32_t*)0x60220908) /* Set via NCSI ENABLE AEN. */
#define     SHM_NCSI_CHANNEL0_AEN_ENABLE_LINK_STATUS_CHANGE_AEN_SHIFT 0u
#define     SHM_NCSI_CHANNEL0_AEN_ENABLE_LINK_STATUS_CHANGE_AEN_MASK  0x1u
#define GET_SHM_NCSI_CHANNEL0_AEN_ENABLE_LINK_STATUS_CHANGE_AEN(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_NCSI_CHANNEL0_AEN_ENABLE_LINK_STATUS_CHANGE_AEN(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_NCSI_CHANNEL0_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN_SHIFT 1u
#define     SHM_NCSI_CHANNEL0_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN_MASK  0x2u
#define GET_SHM_NCSI_CHANNEL0_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_NCSI_CHANNEL0_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_NCSI_CHANNEL0_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN_SHIFT 2u
#define     SHM_NCSI_CHANNEL0_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN_MASK  0x4u
#define GET_SHM_NCSI_CHANNEL0_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_NCSI_CHANNEL0_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN(__val__)  (((__val__) << 2u) & 0x4u)

/** @brief Register definition for @ref SHM_t.NcsiChannel0Aen. */
typedef register_container RegSHMNcsiChannel0Aen_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, EnableLinkStatusChangeAEN, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, EnableConfigurationRequiredAEN, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, EnableHostNCDriverStatusChangeAEN, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_3, 3, 29)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_3, 3, 29)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, EnableHostNCDriverStatusChangeAEN, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, EnableConfigurationRequiredAEN, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, EnableLinkStatusChangeAEN, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Aen"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Aen_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Aen. */
        r32.setName("NcsiChannel0Aen");
        r32.setComponentOffset(0x908);
        bits.EnableLinkStatusChangeAEN.setBaseRegister(&r32);
        bits.EnableLinkStatusChangeAEN.setName("EnableLinkStatusChangeAEN");
        bits.EnableLinkStatusChangeAEN.setComponentOffset(0x908);
        bits.EnableConfigurationRequiredAEN.setBaseRegister(&r32);
        bits.EnableConfigurationRequiredAEN.setName("EnableConfigurationRequiredAEN");
        bits.EnableConfigurationRequiredAEN.setComponentOffset(0x908);
        bits.EnableHostNCDriverStatusChangeAEN.setBaseRegister(&r32);
        bits.EnableHostNCDriverStatusChangeAEN.setName("EnableHostNCDriverStatusChangeAEN");
        bits.EnableHostNCDriverStatusChangeAEN.setComponentOffset(0x908);
    }
    RegSHMNcsiChannel0Aen_t& operator=(const RegSHMNcsiChannel0Aen_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Aen_t;

#define REG_SHM_NCSI_CHANNEL0_BFILT ((volatile APE_SHM_H_uint32_t*)0x6022090c) /*  */
#define     SHM_NCSI_CHANNEL0_BFILT_ARP_PACKET_SHIFT 0u
#define     SHM_NCSI_CHANNEL0_BFILT_ARP_PACKET_MASK  0x1u
#define GET_SHM_NCSI_CHANNEL0_BFILT_ARP_PACKET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_NCSI_CHANNEL0_BFILT_ARP_PACKET(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_NCSI_CHANNEL0_BFILT_DHCP_CLIENT_PACKET_SHIFT 1u
#define     SHM_NCSI_CHANNEL0_BFILT_DHCP_CLIENT_PACKET_MASK  0x2u
#define GET_SHM_NCSI_CHANNEL0_BFILT_DHCP_CLIENT_PACKET(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_NCSI_CHANNEL0_BFILT_DHCP_CLIENT_PACKET(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_NCSI_CHANNEL0_BFILT_DHCP_SERVER_PACKET_SHIFT 2u
#define     SHM_NCSI_CHANNEL0_BFILT_DHCP_SERVER_PACKET_MASK  0x4u
#define GET_SHM_NCSI_CHANNEL0_BFILT_DHCP_SERVER_PACKET(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_NCSI_CHANNEL0_BFILT_DHCP_SERVER_PACKET(__val__)  (((__val__) << 2u) & 0x4u)
#define     SHM_NCSI_CHANNEL0_BFILT_NETBIOS_PACKET_SHIFT 3u
#define     SHM_NCSI_CHANNEL0_BFILT_NETBIOS_PACKET_MASK  0x8u
#define GET_SHM_NCSI_CHANNEL0_BFILT_NETBIOS_PACKET(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_SHM_NCSI_CHANNEL0_BFILT_NETBIOS_PACKET(__val__)  (((__val__) << 3u) & 0x8u)

/** @brief Register definition for @ref SHM_t.NcsiChannel0Bfilt. */
typedef register_container RegSHMNcsiChannel0Bfilt_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, ARPPacket, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, DHCPClientPacket, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, DHCPServerPacket, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, NetBIOSPacket, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_4, 4, 28)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_4, 4, 28)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, NetBIOSPacket, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, DHCPServerPacket, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, DHCPClientPacket, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, ARPPacket, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Bfilt"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Bfilt_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Bfilt. */
        r32.setName("NcsiChannel0Bfilt");
        r32.setComponentOffset(0x90c);
        bits.ARPPacket.setBaseRegister(&r32);
        bits.ARPPacket.setName("ARPPacket");
        bits.ARPPacket.setComponentOffset(0x90c);
        bits.DHCPClientPacket.setBaseRegister(&r32);
        bits.DHCPClientPacket.setName("DHCPClientPacket");
        bits.DHCPClientPacket.setComponentOffset(0x90c);
        bits.DHCPServerPacket.setBaseRegister(&r32);
        bits.DHCPServerPacket.setName("DHCPServerPacket");
        bits.DHCPServerPacket.setComponentOffset(0x90c);
        bits.NetBIOSPacket.setBaseRegister(&r32);
        bits.NetBIOSPacket.setName("NetBIOSPacket");
        bits.NetBIOSPacket.setComponentOffset(0x90c);
    }
    RegSHMNcsiChannel0Bfilt_t& operator=(const RegSHMNcsiChannel0Bfilt_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Bfilt_t;

#define REG_SHM_NCSI_CHANNEL0_MFILT ((volatile APE_SHM_H_uint32_t*)0x60220910) /*  */
#define     SHM_NCSI_CHANNEL0_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT_SHIFT 0u
#define     SHM_NCSI_CHANNEL0_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT_MASK  0x1u
#define GET_SHM_NCSI_CHANNEL0_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_NCSI_CHANNEL0_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_NCSI_CHANNEL0_MFILT_IPV6_ROUTER_ADVERTISEMENT_SHIFT 1u
#define     SHM_NCSI_CHANNEL0_MFILT_IPV6_ROUTER_ADVERTISEMENT_MASK  0x2u
#define GET_SHM_NCSI_CHANNEL0_MFILT_IPV6_ROUTER_ADVERTISEMENT(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_NCSI_CHANNEL0_MFILT_IPV6_ROUTER_ADVERTISEMENT(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_NCSI_CHANNEL0_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST_SHIFT 2u
#define     SHM_NCSI_CHANNEL0_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST_MASK  0x4u
#define GET_SHM_NCSI_CHANNEL0_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_NCSI_CHANNEL0_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST(__val__)  (((__val__) << 2u) & 0x4u)

/** @brief Register definition for @ref SHM_t.NcsiChannel0Mfilt. */
typedef register_container RegSHMNcsiChannel0Mfilt_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, IPv6NeighbourAdvertisement, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, IPv6RouterAdvertisement, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, DHCPv6RelayandServerMulticast, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_3, 3, 29)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_3, 3, 29)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, DHCPv6RelayandServerMulticast, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, IPv6RouterAdvertisement, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, IPv6NeighbourAdvertisement, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mfilt"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mfilt_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mfilt. */
        r32.setName("NcsiChannel0Mfilt");
        r32.setComponentOffset(0x910);
        bits.IPv6NeighbourAdvertisement.setBaseRegister(&r32);
        bits.IPv6NeighbourAdvertisement.setName("IPv6NeighbourAdvertisement");
        bits.IPv6NeighbourAdvertisement.setComponentOffset(0x910);
        bits.IPv6RouterAdvertisement.setBaseRegister(&r32);
        bits.IPv6RouterAdvertisement.setName("IPv6RouterAdvertisement");
        bits.IPv6RouterAdvertisement.setComponentOffset(0x910);
        bits.DHCPv6RelayandServerMulticast.setBaseRegister(&r32);
        bits.DHCPv6RelayandServerMulticast.setName("DHCPv6RelayandServerMulticast");
        bits.DHCPv6RelayandServerMulticast.setComponentOffset(0x910);
    }
    RegSHMNcsiChannel0Mfilt_t& operator=(const RegSHMNcsiChannel0Mfilt_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mfilt_t;

#define REG_SHM_NCSI_CHANNEL0_SETTING_1 ((volatile APE_SHM_H_uint32_t*)0x60220914) /* This is the "Link Settings" value from NCSI Set Link. */
#define     SHM_NCSI_CHANNEL0_SETTING_1_AUTONEGOTIATION_ENABLED_SHIFT 0u
#define     SHM_NCSI_CHANNEL0_SETTING_1_AUTONEGOTIATION_ENABLED_MASK  0x1u
#define GET_SHM_NCSI_CHANNEL0_SETTING_1_AUTONEGOTIATION_ENABLED(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_NCSI_CHANNEL0_SETTING_1_AUTONEGOTIATION_ENABLED(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10M_ENABLE_SHIFT 1u
#define     SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10M_ENABLE_MASK  0x2u
#define GET_SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10M_ENABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10M_ENABLE(__val__)  (((__val__) << 1u) & 0x2u)
#define     SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_100M_ENABLE_SHIFT 2u
#define     SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_100M_ENABLE_MASK  0x4u
#define GET_SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_100M_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_100M_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_1000M_ENABLE_SHIFT 3u
#define     SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_1000M_ENABLE_MASK  0x8u
#define GET_SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_1000M_ENABLE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_1000M_ENABLE(__val__)  (((__val__) << 3u) & 0x8u)
#define     SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10G_ENABLE_SHIFT 4u
#define     SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10G_ENABLE_MASK  0x10u
#define GET_SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10G_ENABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_SHM_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10G_ENABLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     SHM_NCSI_CHANNEL0_SETTING_1_HALF_DUPLEX_ENABLE_SHIFT 8u
#define     SHM_NCSI_CHANNEL0_SETTING_1_HALF_DUPLEX_ENABLE_MASK  0x100u
#define GET_SHM_NCSI_CHANNEL0_SETTING_1_HALF_DUPLEX_ENABLE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_SHM_NCSI_CHANNEL0_SETTING_1_HALF_DUPLEX_ENABLE(__val__)  (((__val__) << 8u) & 0x100u)
#define     SHM_NCSI_CHANNEL0_SETTING_1_FULL_DUPLEX_ENABLE_SHIFT 9u
#define     SHM_NCSI_CHANNEL0_SETTING_1_FULL_DUPLEX_ENABLE_MASK  0x200u
#define GET_SHM_NCSI_CHANNEL0_SETTING_1_FULL_DUPLEX_ENABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_SHM_NCSI_CHANNEL0_SETTING_1_FULL_DUPLEX_ENABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     SHM_NCSI_CHANNEL0_SETTING_1_PAUSE_CAPABILITY_ENABLE_SHIFT 10u
#define     SHM_NCSI_CHANNEL0_SETTING_1_PAUSE_CAPABILITY_ENABLE_MASK  0x400u
#define GET_SHM_NCSI_CHANNEL0_SETTING_1_PAUSE_CAPABILITY_ENABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_SHM_NCSI_CHANNEL0_SETTING_1_PAUSE_CAPABILITY_ENABLE(__val__)  (((__val__) << 10u) & 0x400u)
#define     SHM_NCSI_CHANNEL0_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE_SHIFT 11u
#define     SHM_NCSI_CHANNEL0_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE_MASK  0x800u
#define GET_SHM_NCSI_CHANNEL0_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_SHM_NCSI_CHANNEL0_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE(__val__)  (((__val__) << 11u) & 0x800u)
#define     SHM_NCSI_CHANNEL0_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID_SHIFT 12u
#define     SHM_NCSI_CHANNEL0_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID_MASK  0x1000u
#define GET_SHM_NCSI_CHANNEL0_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_SHM_NCSI_CHANNEL0_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref SHM_t.NcsiChannel0Setting1. */
typedef register_container RegSHMNcsiChannel0Setting1_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Autonegotiationenabled, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkSpeed10Menable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkSpeed100Menable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkSpeed1000Menable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkSpeed10Genable, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Halfduplexenable, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Fullduplexenable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Pausecapabilityenable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Asymmetricpausecapabilityenable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, OEMlinksettingsfieldvalid, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, OEMlinksettingsfieldvalid, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Asymmetricpausecapabilityenable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Pausecapabilityenable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Fullduplexenable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Halfduplexenable, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkSpeed10Genable, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkSpeed1000Menable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkSpeed100Menable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkSpeed10Menable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Autonegotiationenabled, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Setting1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Setting1_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Setting1. */
        r32.setName("NcsiChannel0Setting1");
        r32.setComponentOffset(0x914);
        bits.Autonegotiationenabled.setBaseRegister(&r32);
        bits.Autonegotiationenabled.setName("Autonegotiationenabled");
        bits.Autonegotiationenabled.setComponentOffset(0x914);
        bits.LinkSpeed10Menable.setBaseRegister(&r32);
        bits.LinkSpeed10Menable.setName("LinkSpeed10Menable");
        bits.LinkSpeed10Menable.setComponentOffset(0x914);
        bits.LinkSpeed100Menable.setBaseRegister(&r32);
        bits.LinkSpeed100Menable.setName("LinkSpeed100Menable");
        bits.LinkSpeed100Menable.setComponentOffset(0x914);
        bits.LinkSpeed1000Menable.setBaseRegister(&r32);
        bits.LinkSpeed1000Menable.setName("LinkSpeed1000Menable");
        bits.LinkSpeed1000Menable.setComponentOffset(0x914);
        bits.LinkSpeed10Genable.setBaseRegister(&r32);
        bits.LinkSpeed10Genable.setName("LinkSpeed10Genable");
        bits.LinkSpeed10Genable.setComponentOffset(0x914);
        bits.Halfduplexenable.setBaseRegister(&r32);
        bits.Halfduplexenable.setName("Halfduplexenable");
        bits.Halfduplexenable.setComponentOffset(0x914);
        bits.Fullduplexenable.setBaseRegister(&r32);
        bits.Fullduplexenable.setName("Fullduplexenable");
        bits.Fullduplexenable.setComponentOffset(0x914);
        bits.Pausecapabilityenable.setBaseRegister(&r32);
        bits.Pausecapabilityenable.setName("Pausecapabilityenable");
        bits.Pausecapabilityenable.setComponentOffset(0x914);
        bits.Asymmetricpausecapabilityenable.setBaseRegister(&r32);
        bits.Asymmetricpausecapabilityenable.setName("Asymmetricpausecapabilityenable");
        bits.Asymmetricpausecapabilityenable.setComponentOffset(0x914);
        bits.OEMlinksettingsfieldvalid.setBaseRegister(&r32);
        bits.OEMlinksettingsfieldvalid.setName("OEMlinksettingsfieldvalid");
        bits.OEMlinksettingsfieldvalid.setComponentOffset(0x914);
    }
    RegSHMNcsiChannel0Setting1_t& operator=(const RegSHMNcsiChannel0Setting1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Setting1_t;

#define REG_SHM_NCSI_CHANNEL0_SETTING_2 ((volatile APE_SHM_H_uint32_t*)0x60220918) /* This is the "OEM Settings" value from NCSI Set Link. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Setting2. */
typedef register_container RegSHMNcsiChannel0Setting2_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Setting2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Setting2_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Setting2. */
        r32.setName("NcsiChannel0Setting2");
        r32.setComponentOffset(0x918);
    }
    RegSHMNcsiChannel0Setting2_t& operator=(const RegSHMNcsiChannel0Setting2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Setting2_t;

#define REG_SHM_NCSI_CHANNEL0_VLAN ((volatile APE_SHM_H_uint32_t*)0x6022091c) /* Receives VLAN mode from NCSI specification "Enable VLAN" command. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Vlan. */
typedef register_container RegSHMNcsiChannel0Vlan_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Vlan"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Vlan_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Vlan. */
        r32.setName("NcsiChannel0Vlan");
        r32.setComponentOffset(0x91c);
    }
    RegSHMNcsiChannel0Vlan_t& operator=(const RegSHMNcsiChannel0Vlan_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Vlan_t;

#define REG_SHM_NCSI_CHANNEL0_ALT_HOST_MAC_HIGH ((volatile APE_SHM_H_uint32_t*)0x60220924) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0AltHostMacHigh. */
typedef register_container RegSHMNcsiChannel0AltHostMacHigh_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0AltHostMacHigh"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0AltHostMacHigh_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0AltHostMacHigh. */
        r32.setName("NcsiChannel0AltHostMacHigh");
        r32.setComponentOffset(0x924);
    }
    RegSHMNcsiChannel0AltHostMacHigh_t& operator=(const RegSHMNcsiChannel0AltHostMacHigh_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0AltHostMacHigh_t;

#define REG_SHM_NCSI_CHANNEL0_ALT_HOST_MAC_MID ((volatile APE_SHM_H_uint32_t*)0x60220928) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0AltHostMacMid. */
typedef register_container RegSHMNcsiChannel0AltHostMacMid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0AltHostMacMid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0AltHostMacMid_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0AltHostMacMid. */
        r32.setName("NcsiChannel0AltHostMacMid");
        r32.setComponentOffset(0x928);
    }
    RegSHMNcsiChannel0AltHostMacMid_t& operator=(const RegSHMNcsiChannel0AltHostMacMid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0AltHostMacMid_t;

#define REG_SHM_NCSI_CHANNEL0_ALT_HOST_MAC_LOW ((volatile APE_SHM_H_uint32_t*)0x6022092c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0AltHostMacLow. */
typedef register_container RegSHMNcsiChannel0AltHostMacLow_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0AltHostMacLow"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0AltHostMacLow_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0AltHostMacLow. */
        r32.setName("NcsiChannel0AltHostMacLow");
        r32.setComponentOffset(0x92c);
    }
    RegSHMNcsiChannel0AltHostMacLow_t& operator=(const RegSHMNcsiChannel0AltHostMacLow_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0AltHostMacLow_t;

#define REG_SHM_NCSI_CHANNEL0_MAC0_HIGH ((volatile APE_SHM_H_uint32_t*)0x60220934) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac0High. */
typedef register_container RegSHMNcsiChannel0Mac0High_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac0High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac0High_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac0High. */
        r32.setName("NcsiChannel0Mac0High");
        r32.setComponentOffset(0x934);
    }
    RegSHMNcsiChannel0Mac0High_t& operator=(const RegSHMNcsiChannel0Mac0High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac0High_t;

#define REG_SHM_NCSI_CHANNEL0_MAC0_MID ((volatile APE_SHM_H_uint32_t*)0x60220938) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac0Mid. */
typedef register_container RegSHMNcsiChannel0Mac0Mid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac0Mid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac0Mid_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac0Mid. */
        r32.setName("NcsiChannel0Mac0Mid");
        r32.setComponentOffset(0x938);
    }
    RegSHMNcsiChannel0Mac0Mid_t& operator=(const RegSHMNcsiChannel0Mac0Mid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac0Mid_t;

#define REG_SHM_NCSI_CHANNEL0_MAC0_LOW ((volatile APE_SHM_H_uint32_t*)0x6022093c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac0Low. */
typedef register_container RegSHMNcsiChannel0Mac0Low_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac0Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac0Low_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac0Low. */
        r32.setName("NcsiChannel0Mac0Low");
        r32.setComponentOffset(0x93c);
    }
    RegSHMNcsiChannel0Mac0Low_t& operator=(const RegSHMNcsiChannel0Mac0Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac0Low_t;

#define REG_SHM_NCSI_CHANNEL0_MAC1_HIGH ((volatile APE_SHM_H_uint32_t*)0x60220944) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac1High. */
typedef register_container RegSHMNcsiChannel0Mac1High_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac1High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac1High_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac1High. */
        r32.setName("NcsiChannel0Mac1High");
        r32.setComponentOffset(0x944);
    }
    RegSHMNcsiChannel0Mac1High_t& operator=(const RegSHMNcsiChannel0Mac1High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac1High_t;

#define REG_SHM_NCSI_CHANNEL0_MAC1_MID ((volatile APE_SHM_H_uint32_t*)0x60220948) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac1Mid. */
typedef register_container RegSHMNcsiChannel0Mac1Mid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac1Mid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac1Mid_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac1Mid. */
        r32.setName("NcsiChannel0Mac1Mid");
        r32.setComponentOffset(0x948);
    }
    RegSHMNcsiChannel0Mac1Mid_t& operator=(const RegSHMNcsiChannel0Mac1Mid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac1Mid_t;

#define REG_SHM_NCSI_CHANNEL0_MAC1_LOW ((volatile APE_SHM_H_uint32_t*)0x6022094c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac1Low. */
typedef register_container RegSHMNcsiChannel0Mac1Low_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac1Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac1Low_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac1Low. */
        r32.setName("NcsiChannel0Mac1Low");
        r32.setComponentOffset(0x94c);
    }
    RegSHMNcsiChannel0Mac1Low_t& operator=(const RegSHMNcsiChannel0Mac1Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac1Low_t;

#define REG_SHM_NCSI_CHANNEL0_MAC2_HIGH ((volatile APE_SHM_H_uint32_t*)0x60220954) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac2High. */
typedef register_container RegSHMNcsiChannel0Mac2High_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac2High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac2High_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac2High. */
        r32.setName("NcsiChannel0Mac2High");
        r32.setComponentOffset(0x954);
    }
    RegSHMNcsiChannel0Mac2High_t& operator=(const RegSHMNcsiChannel0Mac2High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac2High_t;

#define REG_SHM_NCSI_CHANNEL0_MAC2_MID ((volatile APE_SHM_H_uint32_t*)0x60220958) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac2Mid. */
typedef register_container RegSHMNcsiChannel0Mac2Mid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac2Mid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac2Mid_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac2Mid. */
        r32.setName("NcsiChannel0Mac2Mid");
        r32.setComponentOffset(0x958);
    }
    RegSHMNcsiChannel0Mac2Mid_t& operator=(const RegSHMNcsiChannel0Mac2Mid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac2Mid_t;

#define REG_SHM_NCSI_CHANNEL0_MAC2_LOW ((volatile APE_SHM_H_uint32_t*)0x6022095c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac2Low. */
typedef register_container RegSHMNcsiChannel0Mac2Low_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac2Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac2Low_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac2Low. */
        r32.setName("NcsiChannel0Mac2Low");
        r32.setComponentOffset(0x95c);
    }
    RegSHMNcsiChannel0Mac2Low_t& operator=(const RegSHMNcsiChannel0Mac2Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac2Low_t;

#define REG_SHM_NCSI_CHANNEL0_MAC3_HIGH ((volatile APE_SHM_H_uint32_t*)0x60220964) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac3High. */
typedef register_container RegSHMNcsiChannel0Mac3High_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac3High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac3High_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac3High. */
        r32.setName("NcsiChannel0Mac3High");
        r32.setComponentOffset(0x964);
    }
    RegSHMNcsiChannel0Mac3High_t& operator=(const RegSHMNcsiChannel0Mac3High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac3High_t;

#define REG_SHM_NCSI_CHANNEL0_MAC3_MID ((volatile APE_SHM_H_uint32_t*)0x60220968) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac3Mid. */
typedef register_container RegSHMNcsiChannel0Mac3Mid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac3Mid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac3Mid_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac3Mid. */
        r32.setName("NcsiChannel0Mac3Mid");
        r32.setComponentOffset(0x968);
    }
    RegSHMNcsiChannel0Mac3Mid_t& operator=(const RegSHMNcsiChannel0Mac3Mid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac3Mid_t;

#define REG_SHM_NCSI_CHANNEL0_MAC3_LOW ((volatile APE_SHM_H_uint32_t*)0x6022096c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac3Low. */
typedef register_container RegSHMNcsiChannel0Mac3Low_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac3Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac3Low_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac3Low. */
        r32.setName("NcsiChannel0Mac3Low");
        r32.setComponentOffset(0x96c);
    }
    RegSHMNcsiChannel0Mac3Low_t& operator=(const RegSHMNcsiChannel0Mac3Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac3Low_t;

#define REG_SHM_NCSI_CHANNEL0_MAC0_VLAN_VALID ((volatile APE_SHM_H_uint32_t*)0x60220970) /* Nonzero indicates VLAN field is valid */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac0VlanValid. */
typedef register_container RegSHMNcsiChannel0Mac0VlanValid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac0VlanValid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac0VlanValid_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac0VlanValid. */
        r32.setName("NcsiChannel0Mac0VlanValid");
        r32.setComponentOffset(0x970);
    }
    RegSHMNcsiChannel0Mac0VlanValid_t& operator=(const RegSHMNcsiChannel0Mac0VlanValid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac0VlanValid_t;

#define REG_SHM_NCSI_CHANNEL0_MAC0_VLAN ((volatile APE_SHM_H_uint32_t*)0x60220974) /*  */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac0Vlan. */
typedef register_container RegSHMNcsiChannel0Mac0Vlan_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac0Vlan"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac0Vlan_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac0Vlan. */
        r32.setName("NcsiChannel0Mac0Vlan");
        r32.setComponentOffset(0x974);
    }
    RegSHMNcsiChannel0Mac0Vlan_t& operator=(const RegSHMNcsiChannel0Mac0Vlan_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac0Vlan_t;

#define REG_SHM_NCSI_CHANNEL0_MAC1_VLAN_VALID ((volatile APE_SHM_H_uint32_t*)0x60220978) /* Nonzero indicates VLAN field is valid */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac1VlanValid. */
typedef register_container RegSHMNcsiChannel0Mac1VlanValid_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac1VlanValid"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac1VlanValid_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac1VlanValid. */
        r32.setName("NcsiChannel0Mac1VlanValid");
        r32.setComponentOffset(0x978);
    }
    RegSHMNcsiChannel0Mac1VlanValid_t& operator=(const RegSHMNcsiChannel0Mac1VlanValid_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac1VlanValid_t;

#define REG_SHM_NCSI_CHANNEL0_MAC1_VLAN ((volatile APE_SHM_H_uint32_t*)0x6022097c) /*  */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Mac1Vlan. */
typedef register_container RegSHMNcsiChannel0Mac1Vlan_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mac1Vlan"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Mac1Vlan_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Mac1Vlan. */
        r32.setName("NcsiChannel0Mac1Vlan");
        r32.setComponentOffset(0x97c);
    }
    RegSHMNcsiChannel0Mac1Vlan_t& operator=(const RegSHMNcsiChannel0Mac1Vlan_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Mac1Vlan_t;

#define REG_SHM_NCSI_CHANNEL0_STATUS ((volatile APE_SHM_H_uint32_t*)0x60220980) /*  */
#define     SHM_NCSI_CHANNEL0_STATUS_LINK_UP_SHIFT 0u
#define     SHM_NCSI_CHANNEL0_STATUS_LINK_UP_MASK  0x1u
#define GET_SHM_NCSI_CHANNEL0_STATUS_LINK_UP(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_NCSI_CHANNEL0_STATUS_LINK_UP(__val__)  (((__val__) << 0u) & 0x1u)
#define     SHM_NCSI_CHANNEL0_STATUS_LINK_STATUS_SHIFT 1u
#define     SHM_NCSI_CHANNEL0_STATUS_LINK_STATUS_MASK  0x1eu
#define GET_SHM_NCSI_CHANNEL0_STATUS_LINK_STATUS(__reg__)  (((__reg__) & 0x1e) >> 1u)
#define SET_SHM_NCSI_CHANNEL0_STATUS_LINK_STATUS(__val__)  (((__val__) << 1u) & 0x1eu)
#define     SHM_NCSI_CHANNEL0_STATUS_SERDES_SHIFT 5u
#define     SHM_NCSI_CHANNEL0_STATUS_SERDES_MASK  0x20u
#define GET_SHM_NCSI_CHANNEL0_STATUS_SERDES(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_SHM_NCSI_CHANNEL0_STATUS_SERDES(__val__)  (((__val__) << 5u) & 0x20u)
#define     SHM_NCSI_CHANNEL0_STATUS_AUTONEGOTIATION_COMPLETE_SHIFT 6u
#define     SHM_NCSI_CHANNEL0_STATUS_AUTONEGOTIATION_COMPLETE_MASK  0x40u
#define GET_SHM_NCSI_CHANNEL0_STATUS_AUTONEGOTIATION_COMPLETE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_SHM_NCSI_CHANNEL0_STATUS_AUTONEGOTIATION_COMPLETE(__val__)  (((__val__) << 6u) & 0x40u)
#define     SHM_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE_SHIFT 9u
#define     SHM_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE_MASK  0x200u
#define GET_SHM_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_SHM_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     SHM_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_HALS_DUPLEX_CAPABLE_SHIFT 10u
#define     SHM_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_HALS_DUPLEX_CAPABLE_MASK  0x400u
#define GET_SHM_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_HALS_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_SHM_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_HALS_DUPLEX_CAPABLE(__val__)  (((__val__) << 10u) & 0x400u)

/** @brief Register definition for @ref SHM_t.NcsiChannel0Status. */
typedef register_container RegSHMNcsiChannel0Status_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(APE_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Linkup, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkStatus, 1, 4)
        /** @brief Set from MII_REG_CONTROL__AUTO_NEGOTIATION_ENABLE. Set unconditionally in SERDES case. */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, SERDES, 5, 1)
        /** @brief Set if autonegotiation is complete. */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, AutonegotiationComplete, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_8_7, 7, 2)
        /** @brief Link partner 1000BASE-T full duplex capable */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkSpeed1000MFullDuplexCapable, 9, 1)
        /** @brief Link partner 1000BASE-T half duplex capable */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkSpeed1000MHalsDuplexCapable, 10, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_11, 11, 21)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_31_11, 11, 21)
        /** @brief Link partner 1000BASE-T half duplex capable */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkSpeed1000MHalsDuplexCapable, 10, 1)
        /** @brief Link partner 1000BASE-T full duplex capable */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkSpeed1000MFullDuplexCapable, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, reserved_8_7, 7, 2)
        /** @brief Set if autonegotiation is complete. */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, AutonegotiationComplete, 6, 1)
        /** @brief Set from MII_REG_CONTROL__AUTO_NEGOTIATION_ENABLE. Set unconditionally in SERDES case. */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, SERDES, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, LinkStatus, 1, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_SHM_H_uint32_t, Linkup, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Status"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Status_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Status. */
        r32.setName("NcsiChannel0Status");
        r32.setComponentOffset(0x980);
        bits.Linkup.setBaseRegister(&r32);
        bits.Linkup.setName("Linkup");
        bits.Linkup.setComponentOffset(0x980);
        bits.LinkStatus.setBaseRegister(&r32);
        bits.LinkStatus.setName("LinkStatus");
        bits.LinkStatus.setComponentOffset(0x980);
        bits.SERDES.setBaseRegister(&r32);
        bits.SERDES.setName("SERDES");
        bits.SERDES.setComponentOffset(0x980);
        bits.AutonegotiationComplete.setBaseRegister(&r32);
        bits.AutonegotiationComplete.setName("AutonegotiationComplete");
        bits.AutonegotiationComplete.setComponentOffset(0x980);
        bits.LinkSpeed1000MFullDuplexCapable.setBaseRegister(&r32);
        bits.LinkSpeed1000MFullDuplexCapable.setName("LinkSpeed1000MFullDuplexCapable");
        bits.LinkSpeed1000MFullDuplexCapable.setComponentOffset(0x980);
        bits.LinkSpeed1000MHalsDuplexCapable.setBaseRegister(&r32);
        bits.LinkSpeed1000MHalsDuplexCapable.setName("LinkSpeed1000MHalsDuplexCapable");
        bits.LinkSpeed1000MHalsDuplexCapable.setComponentOffset(0x980);
    }
    RegSHMNcsiChannel0Status_t& operator=(const RegSHMNcsiChannel0Status_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Status_t;

#define REG_SHM_NCSI_CHANNEL0_RESET_COUNT ((volatile APE_SHM_H_uint32_t*)0x60220984) /*  */
/** @brief Register definition for @ref SHM_t.NcsiChannel0ResetCount. */
typedef register_container RegSHMNcsiChannel0ResetCount_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0ResetCount"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0ResetCount_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0ResetCount. */
        r32.setName("NcsiChannel0ResetCount");
        r32.setComponentOffset(0x984);
    }
    RegSHMNcsiChannel0ResetCount_t& operator=(const RegSHMNcsiChannel0ResetCount_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0ResetCount_t;

#define REG_SHM_NCSI_CHANNEL0_PXE ((volatile APE_SHM_H_uint32_t*)0x60220988) /*  */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Pxe. */
typedef register_container RegSHMNcsiChannel0Pxe_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Pxe"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Pxe_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Pxe. */
        r32.setName("NcsiChannel0Pxe");
        r32.setComponentOffset(0x988);
    }
    RegSHMNcsiChannel0Pxe_t& operator=(const RegSHMNcsiChannel0Pxe_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Pxe_t;

#define REG_SHM_NCSI_CHANNEL0_DROPFIL ((volatile APE_SHM_H_uint32_t*)0x6022098c) /*  */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Dropfil. */
typedef register_container RegSHMNcsiChannel0Dropfil_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Dropfil"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Dropfil_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Dropfil. */
        r32.setName("NcsiChannel0Dropfil");
        r32.setComponentOffset(0x98c);
    }
    RegSHMNcsiChannel0Dropfil_t& operator=(const RegSHMNcsiChannel0Dropfil_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Dropfil_t;

#define REG_SHM_NCSI_CHANNEL0_SLINK ((volatile APE_SHM_H_uint32_t*)0x60220990) /*  */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Slink. */
typedef register_container RegSHMNcsiChannel0Slink_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Slink"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Slink_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Slink. */
        r32.setName("NcsiChannel0Slink");
        r32.setComponentOffset(0x990);
    }
    RegSHMNcsiChannel0Slink_t& operator=(const RegSHMNcsiChannel0Slink_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Slink_t;

#define REG_SHM_NCSI_CHANNEL0_DBG ((volatile APE_SHM_H_uint32_t*)0x602209a0) /*  */
/** @brief Register definition for @ref SHM_t.NcsiChannel0Dbg. */
typedef register_container RegSHMNcsiChannel0Dbg_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Dbg"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0Dbg_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0Dbg. */
        r32.setName("NcsiChannel0Dbg");
        r32.setComponentOffset(0x9a0);
    }
    RegSHMNcsiChannel0Dbg_t& operator=(const RegSHMNcsiChannel0Dbg_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0Dbg_t;

#define REG_SHM_NCSI_CHANNEL0_CTRLSTAT_RX ((volatile APE_SHM_H_uint32_t*)0x602209b0) /*  */
/** @brief Register definition for @ref SHM_t.NcsiChannel0CtrlstatRx. */
typedef register_container RegSHMNcsiChannel0CtrlstatRx_t {
    /** @brief 32bit direct register access. */
    APE_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0CtrlstatRx"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiChannel0CtrlstatRx_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiChannel0CtrlstatRx. */
        r32.setName("NcsiChannel0CtrlstatRx");
        r32.setComponentOffset(0x9b0);
    }
    RegSHMNcsiChannel0CtrlstatRx_t& operator=(const RegSHMNcsiChannel0CtrlstatRx_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiChannel0CtrlstatRx_t;

/** @brief Component definition for @ref SHM. */
typedef struct {
    /** @brief APE_APE_MAGIC ('APE!') when all is well. */
    RegSHMSegSig_t SegSig;

    /** @brief Set to 0x34. */
    RegSHMApeSegLength_t ApeSegLength;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_8[1];

    /** @brief  */
    RegSHMFwStatus_t FwStatus;

    /** @brief  */
    RegSHMFwFeatures_t FwFeatures;

    /** @brief Unknown. */
    RegSHM4014_t _4014;

    /** @brief  */
    RegSHMFwVersion_t FwVersion;

    /** @brief Specifies the offset of a scratchpad area, relative to the  start of the APE SHM area (i.e., relative to APE_REG(0x4000)). */
    RegSHMSegMessageBufferOffset_t SegMessageBufferOffset;

    /** @brief Specifies the size of the scratchpad area in bytes. */
    RegSHMSegMessageBufferLength_t SegMessageBufferLength;

    /** @brief Unknown. Bootcode related. */
    RegSHM4024_t _4024;

    /** @brief Unknown. Bootcode related. */
    RegSHM4028_t _4028;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_44[3];

    /** @brief Command sent when using the the APE loader. Zero once handled. */
    RegSHMLoaderCommand_t LoaderCommand;

    /** @brief Argument 0 for the APE loader. */
    RegSHMLoaderArg0_t LoaderArg0;

    /** @brief Argument 1 for the APE loader. */
    RegSHMLoaderArg1_t LoaderArg1;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_68[47];

    /** @brief Set to APE_RCPU_MAGIC ('RCPU') by RX CPU. */
    RegSHMRcpuSegSig_t RcpuSegSig;

    /** @brief Set to 0x34. */
    RegSHMRcpuSegLength_t RcpuSegLength;

    /** @brief Incremented by RX CPU every boot. */
    RegSHMRcpuInitCount_t RcpuInitCount;

    /** @brief Set to the bootcode version. e.g. 0x0127 -> v1.39. */
    RegSHMRcpuFwVersion_t RcpuFwVersion;

    /** @brief Set to  */
    RegSHMRcpuCfgFeature_t RcpuCfgFeature;

    /** @brief Set to PCI Vendor/Device ID by S2. */
    RegSHMRcpuPciVendorDeviceId_t RcpuPciVendorDeviceId;

    /** @brief Set to PCI Subsystem Vendor/Subsystem ID by S2. */
    RegSHMRcpuPciSubsystemId_t RcpuPciSubsystemId;

    /** @brief Unknown. Incremented by frobnicating routine. */
    RegSHMRcpuApeResetCount_t RcpuApeResetCount;

    /** @brief Unknown. Written by frobnicating routine. */
    RegSHMRcpuLastApeStatus_t RcpuLastApeStatus;

    /** @brief Unknown.  */
    RegSHMRcpuLastApeFwStatus_t RcpuLastApeFwStatus;

    /** @brief Set from  */
    RegSHMRcpuCfgHw_t RcpuCfgHw;

    /** @brief Set from  */
    RegSHMRcpuCfgHw2_t RcpuCfgHw2;

    /** @brief Set from  */
    RegSHMRcpuCpmuStatus_t RcpuCpmuStatus;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_308[51];

    /** @brief Set to APE_HOST_MAGIC ('HOST') to indicate the section is valid. */
    RegSHMHostSegSig_t HostSegSig;

    /** @brief Set to 0x20. */
    RegSHMHostSegLen_t HostSegLen;

    /** @brief Incremented by host on every initialization. */
    RegSHMHostInitCount_t HostInitCount;

    /** @brief Linux sets this to 0xF0MM_mm00, where M is the major version  of Linux and m is the minor version. */
    RegSHMHostDriverId_t HostDriverId;

    /** @brief  */
    RegSHMHostBehavior_t HostBehavior;

    /** @brief In milliseconds. Set to 0 to disable heartbeating. */
    RegSHMHeartbeatInterval_t HeartbeatInterval;

    /** @brief  */
    RegSHMHeartbeatCount_t HeartbeatCount;

    /** @brief  */
    RegSHMHostDriverState_t HostDriverState;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_544[1];

    /** @brief  */
    RegSHMWolSpeed_t WolSpeed;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_552[54];

    /** @brief  */
    RegSHMEventStatus_t EventStatus;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_772[1];

    /** @brief This is set to APE_PROT_MAGIC ('PROT') on all functions.  If it is 'PROT', the following fields (MAC0_HIGH/LOW) are valid */
    RegSHMProtMagic_t ProtMagic;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_780[2];

    /** @brief High 16 bits of MAC address 0. Only valid if  */
    RegSHMProtMac0High_t ProtMac0High;

    /** @brief Low 16 bits of MAC address 0. */
    RegSHMProtMac0Low_t ProtMac0Low;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_796[313];

    /** @brief Set to NCSI_MAGIC ('NCSI') by APE firmware. NOTE: all words in the NCSI section are available in the function 0 SHM area only. */
    RegSHMNcsiSig_t NcsiSig;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_2052[3];

    /** @brief ASCII string spanning three 32-bit words. Unused trailing bytes   are set to zero. */
    RegSHMNcsiBuildTime_t NcsiBuildTime;

    /** @brief  */
    RegSHMNcsiBuildTime2_t NcsiBuildTime2;

    /** @brief  */
    RegSHMNcsiBuildTime3_t NcsiBuildTime3;

    /** @brief ASCII string spanning three 32-bit words. Unused trailing bytes   are set to zero. */
    RegSHMNcsiBuildDate_t NcsiBuildDate;

    /** @brief  */
    RegSHMNcsiBuildDate2_t NcsiBuildDate2;

    /** @brief  */
    RegSHMNcsiBuildDate3_t NcsiBuildDate3;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_2088[26];

    /** @brief The APE code copies the contents of Chip ID to this word */
    RegSHMChipId_t ChipId;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_2196[27];

    /** @brief  */
    RegSHMNcsiChannel0Info_t NcsiChannel0Info;

    /** @brief AEN Management Controller ID, set by BMC when sending AEN ENABLE command and used when sending AENs. */
    RegSHMNcsiChannel0Mcid_t NcsiChannel0Mcid;

    /** @brief Set via NCSI ENABLE AEN. */
    RegSHMNcsiChannel0Aen_t NcsiChannel0Aen;

    /** @brief  */
    RegSHMNcsiChannel0Bfilt_t NcsiChannel0Bfilt;

    /** @brief  */
    RegSHMNcsiChannel0Mfilt_t NcsiChannel0Mfilt;

    /** @brief This is the "Link Settings" value from NCSI Set Link. */
    RegSHMNcsiChannel0Setting1_t NcsiChannel0Setting1;

    /** @brief This is the "OEM Settings" value from NCSI Set Link. */
    RegSHMNcsiChannel0Setting2_t NcsiChannel0Setting2;

    /** @brief Receives VLAN mode from NCSI specification "Enable VLAN" command. */
    RegSHMNcsiChannel0Vlan_t NcsiChannel0Vlan;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_2336[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegSHMNcsiChannel0AltHostMacHigh_t NcsiChannel0AltHostMacHigh;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegSHMNcsiChannel0AltHostMacMid_t NcsiChannel0AltHostMacMid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegSHMNcsiChannel0AltHostMacLow_t NcsiChannel0AltHostMacLow;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_2352[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegSHMNcsiChannel0Mac0High_t NcsiChannel0Mac0High;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegSHMNcsiChannel0Mac0Mid_t NcsiChannel0Mac0Mid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegSHMNcsiChannel0Mac0Low_t NcsiChannel0Mac0Low;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_2368[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegSHMNcsiChannel0Mac1High_t NcsiChannel0Mac1High;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegSHMNcsiChannel0Mac1Mid_t NcsiChannel0Mac1Mid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegSHMNcsiChannel0Mac1Low_t NcsiChannel0Mac1Low;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_2384[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegSHMNcsiChannel0Mac2High_t NcsiChannel0Mac2High;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegSHMNcsiChannel0Mac2Mid_t NcsiChannel0Mac2Mid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegSHMNcsiChannel0Mac2Low_t NcsiChannel0Mac2Low;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_2400[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegSHMNcsiChannel0Mac3High_t NcsiChannel0Mac3High;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegSHMNcsiChannel0Mac3Mid_t NcsiChannel0Mac3Mid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegSHMNcsiChannel0Mac3Low_t NcsiChannel0Mac3Low;

    /** @brief Nonzero indicates VLAN field is valid */
    RegSHMNcsiChannel0Mac0VlanValid_t NcsiChannel0Mac0VlanValid;

    /** @brief  */
    RegSHMNcsiChannel0Mac0Vlan_t NcsiChannel0Mac0Vlan;

    /** @brief Nonzero indicates VLAN field is valid */
    RegSHMNcsiChannel0Mac1VlanValid_t NcsiChannel0Mac1VlanValid;

    /** @brief  */
    RegSHMNcsiChannel0Mac1Vlan_t NcsiChannel0Mac1Vlan;

    /** @brief  */
    RegSHMNcsiChannel0Status_t NcsiChannel0Status;

    /** @brief  */
    RegSHMNcsiChannel0ResetCount_t NcsiChannel0ResetCount;

    /** @brief  */
    RegSHMNcsiChannel0Pxe_t NcsiChannel0Pxe;

    /** @brief  */
    RegSHMNcsiChannel0Dropfil_t NcsiChannel0Dropfil;

    /** @brief  */
    RegSHMNcsiChannel0Slink_t NcsiChannel0Slink;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_2452[3];

    /** @brief  */
    RegSHMNcsiChannel0Dbg_t NcsiChannel0Dbg;

    /** @brief Reserved bytes to pad out data structure. */
    APE_SHM_H_uint32_t reserved_2468[3];

    /** @brief  */
    RegSHMNcsiChannel0CtrlstatRx_t NcsiChannel0CtrlstatRx;

#ifdef CXX_SIMULATOR
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
} SHM_t;

/** @brief Device SHM Registers, function 0 */
extern volatile SHM_t SHM;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !APE_SHM_H */

/** @} */
