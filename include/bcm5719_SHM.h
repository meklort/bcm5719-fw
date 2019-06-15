////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_SHM.h
///
/// @project    bcm5719
///
/// @brief      bcm5719_SHM
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

/** @defgroup BCM5719_SHM_H    bcm5719_SHM */
/** @addtogroup BCM5719_SHM_H
 * @{
 */
#ifndef BCM5719_SHM_H
#define BCM5719_SHM_H

#include <types.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_bcm5719_SHM_sim(void* base);
void init_bcm5719_SHM(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> BCM5719_SHM_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> BCM5719_SHM_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> BCM5719_SHM_H_uint32_t;
#define BCM5719_SHM_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define BCM5719_SHM_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define BCM5719_SHM_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  BCM5719_SHM_H_uint8_t;
typedef uint16_t BCM5719_SHM_H_uint16_t;
typedef uint32_t BCM5719_SHM_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_SHM_BASE ((volatile void*)0xc0014000) /* Device SHM Registers */
#define REG_SHM_SIZE (sizeof(SHM_t))

#define REG_SHM_SEG_SIG ((volatile BCM5719_SHM_H_uint32_t*)0xc0014000) /* APE_APE_MAGIC ('APE!') when all is well. */
#define     SHM_SEG_SIG_SIG_SHIFT 0u
#define     SHM_SEG_SIG_SIG_MASK  0xffffffffu
#define GET_SHM_SEG_SIG_SIG(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_SHM_SEG_SIG_SIG(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     SHM_SEG_SIG_SIG_LOADER 0x10ad10adu


/** @brief Register definition for @ref SHM_t.SegSig. */
typedef register_container RegSHMSegSig_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Sig, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Sig, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SegSig"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMSegSig_t()
    {
        /** @brief constructor for @ref SHM_t.SegSig. */
        r32.setName("SegSig");
        bits.Sig.setBaseRegister(&r32);
        bits.Sig.setName("Sig");
    }
    RegSHMSegSig_t& operator=(const RegSHMSegSig_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMSegSig_t;

#define REG_SHM_APE_SEG_LENGTH ((volatile BCM5719_SHM_H_uint32_t*)0xc0014004) /* Set to 0x34. */
/** @brief Register definition for @ref SHM_t.ApeSegLength. */
typedef register_container RegSHMApeSegLength_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ApeSegLength"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMApeSegLength_t()
    {
        /** @brief constructor for @ref SHM_t.ApeSegLength. */
        r32.setName("ApeSegLength");
    }
    RegSHMApeSegLength_t& operator=(const RegSHMApeSegLength_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMApeSegLength_t;

#define REG_SHM_FW_STATUS ((volatile BCM5719_SHM_H_uint32_t*)0xc001400c) /*  */
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
    BCM5719_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_7_0, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Ready, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_27_9, 9, 19)
        /** @brief If this is all-ones, it appears to mean the APE FW is halted. */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, unknown_31_28, 28, 4)
#elif defined(__BIG_ENDIAN__)
        /** @brief If this is all-ones, it appears to mean the APE FW is halted. */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, unknown_31_28, 28, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_27_9, 9, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Ready, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_7_0, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "FwStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMFwStatus_t()
    {
        /** @brief constructor for @ref SHM_t.FwStatus. */
        r32.setName("FwStatus");
        bits.Ready.setBaseRegister(&r32);
        bits.Ready.setName("Ready");
        bits.unknown_31_28.setBaseRegister(&r32);
        bits.unknown_31_28.setName("unknown_31_28");
    }
    RegSHMFwStatus_t& operator=(const RegSHMFwStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMFwStatus_t;

#define REG_SHM_FW_FEATURES ((volatile BCM5719_SHM_H_uint32_t*)0xc0014010) /*  */
#define     SHM_FW_FEATURES_NCSI_SHIFT 1u
#define     SHM_FW_FEATURES_NCSI_MASK  0x2u
#define GET_SHM_FW_FEATURES_NCSI(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_SHM_FW_FEATURES_NCSI(__val__)  (((__val__) << 1u) & 0x2u)

/** @brief Register definition for @ref SHM_t.FwFeatures. */
typedef register_container RegSHMFwFeatures_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_0_0, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, NCSI, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_31_2, 2, 30)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_31_2, 2, 30)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, NCSI, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_0_0, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "FwFeatures"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMFwFeatures_t()
    {
        /** @brief constructor for @ref SHM_t.FwFeatures. */
        r32.setName("FwFeatures");
        bits.NCSI.setBaseRegister(&r32);
        bits.NCSI.setName("NCSI");
    }
    RegSHMFwFeatures_t& operator=(const RegSHMFwFeatures_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMFwFeatures_t;

#define REG_SHM_4014 ((volatile BCM5719_SHM_H_uint32_t*)0xc0014014) /* Unknown. */
/** @brief Register definition for @ref SHM_t.4014. */
typedef register_container RegSHM4014_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "4014"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM4014_t()
    {
        /** @brief constructor for @ref SHM_t.4014. */
        r32.setName("4014");
    }
    RegSHM4014_t& operator=(const RegSHM4014_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM4014_t;

#define REG_SHM_FW_VERSION ((volatile BCM5719_SHM_H_uint32_t*)0xc0014018) /*  */
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
    BCM5719_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Build, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Revision, 8, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Minor, 16, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Major, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Major, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Minor, 16, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Revision, 8, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Build, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "FwVersion"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMFwVersion_t()
    {
        /** @brief constructor for @ref SHM_t.FwVersion. */
        r32.setName("FwVersion");
        bits.Build.setBaseRegister(&r32);
        bits.Build.setName("Build");
        bits.Revision.setBaseRegister(&r32);
        bits.Revision.setName("Revision");
        bits.Minor.setBaseRegister(&r32);
        bits.Minor.setName("Minor");
        bits.Major.setBaseRegister(&r32);
        bits.Major.setName("Major");
    }
    RegSHMFwVersion_t& operator=(const RegSHMFwVersion_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMFwVersion_t;

#define REG_SHM_SEG_MESSAGE_BUFFER_OFFSET ((volatile BCM5719_SHM_H_uint32_t*)0xc001401c) /* Specifies the offset of a scratchpad area, relative to the  start of the APE SHM area (i.e., relative to APE_REG(0x4000)). */
/** @brief Register definition for @ref SHM_t.SegMessageBufferOffset. */
typedef register_container RegSHMSegMessageBufferOffset_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SegMessageBufferOffset"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMSegMessageBufferOffset_t()
    {
        /** @brief constructor for @ref SHM_t.SegMessageBufferOffset. */
        r32.setName("SegMessageBufferOffset");
    }
    RegSHMSegMessageBufferOffset_t& operator=(const RegSHMSegMessageBufferOffset_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMSegMessageBufferOffset_t;

#define REG_SHM_SEG_MESSAGE_BUFFER_LENGTH ((volatile BCM5719_SHM_H_uint32_t*)0xc0014020) /* Specifies the size of the scratchpad area in bytes. */
/** @brief Register definition for @ref SHM_t.SegMessageBufferLength. */
typedef register_container RegSHMSegMessageBufferLength_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SegMessageBufferLength"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMSegMessageBufferLength_t()
    {
        /** @brief constructor for @ref SHM_t.SegMessageBufferLength. */
        r32.setName("SegMessageBufferLength");
    }
    RegSHMSegMessageBufferLength_t& operator=(const RegSHMSegMessageBufferLength_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMSegMessageBufferLength_t;

#define REG_SHM_4024 ((volatile BCM5719_SHM_H_uint32_t*)0xc0014024) /* Unknown. Bootcode related. */
/** @brief Register definition for @ref SHM_t.4024. */
typedef register_container RegSHM4024_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "4024"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM4024_t()
    {
        /** @brief constructor for @ref SHM_t.4024. */
        r32.setName("4024");
    }
    RegSHM4024_t& operator=(const RegSHM4024_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM4024_t;

#define REG_SHM_4028 ((volatile BCM5719_SHM_H_uint32_t*)0xc0014028) /* Unknown. Bootcode related. */
/** @brief Register definition for @ref SHM_t.4028. */
typedef register_container RegSHM4028_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "4028"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHM4028_t()
    {
        /** @brief constructor for @ref SHM_t.4028. */
        r32.setName("4028");
    }
    RegSHM4028_t& operator=(const RegSHM4028_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHM4028_t;

#define REG_SHM_LOADER_COMMAND ((volatile BCM5719_SHM_H_uint32_t*)0xc0014038) /* Command sent when using the the APE loader. Zero once handled. */
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
    BCM5719_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Command, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Command, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LoaderCommand"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMLoaderCommand_t()
    {
        /** @brief constructor for @ref SHM_t.LoaderCommand. */
        r32.setName("LoaderCommand");
        bits.Command.setBaseRegister(&r32);
        bits.Command.setName("Command");
    }
    RegSHMLoaderCommand_t& operator=(const RegSHMLoaderCommand_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMLoaderCommand_t;

#define REG_SHM_LOADER_ARG0 ((volatile BCM5719_SHM_H_uint32_t*)0xc001403c) /* Argument 0 for the APE loader. */
/** @brief Register definition for @ref SHM_t.LoaderArg0. */
typedef register_container RegSHMLoaderArg0_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LoaderArg0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMLoaderArg0_t()
    {
        /** @brief constructor for @ref SHM_t.LoaderArg0. */
        r32.setName("LoaderArg0");
    }
    RegSHMLoaderArg0_t& operator=(const RegSHMLoaderArg0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMLoaderArg0_t;

#define REG_SHM_LOADER_ARG1 ((volatile BCM5719_SHM_H_uint32_t*)0xc0014040) /* Argument 1 for the APE loader. */
/** @brief Register definition for @ref SHM_t.LoaderArg1. */
typedef register_container RegSHMLoaderArg1_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LoaderArg1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMLoaderArg1_t()
    {
        /** @brief constructor for @ref SHM_t.LoaderArg1. */
        r32.setName("LoaderArg1");
    }
    RegSHMLoaderArg1_t& operator=(const RegSHMLoaderArg1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMLoaderArg1_t;

#define REG_SHM_RCPU_SEG_SIG ((volatile BCM5719_SHM_H_uint32_t*)0xc0014100) /* Set to APE_RCPU_MAGIC ('RCPU') by RX CPU. */
#define     SHM_RCPU_SEG_SIG_SIG_SHIFT 0u
#define     SHM_RCPU_SEG_SIG_SIG_MASK  0xffffffffu
#define GET_SHM_RCPU_SEG_SIG_SIG(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_SHM_RCPU_SEG_SIG_SIG(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     SHM_RCPU_SEG_SIG_SIG_RCPU_MAGIC 0x52435055u


/** @brief Register definition for @ref SHM_t.RcpuSegSig. */
typedef register_container RegSHMRcpuSegSig_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Sig, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Sig, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuSegSig"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuSegSig_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuSegSig. */
        r32.setName("RcpuSegSig");
        bits.Sig.setBaseRegister(&r32);
        bits.Sig.setName("Sig");
    }
    RegSHMRcpuSegSig_t& operator=(const RegSHMRcpuSegSig_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuSegSig_t;

#define REG_SHM_RCPU_SEG_LENGTH ((volatile BCM5719_SHM_H_uint32_t*)0xc0014104) /* Set to 0x34. */
/** @brief Register definition for @ref SHM_t.RcpuSegLength. */
typedef register_container RegSHMRcpuSegLength_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuSegLength"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuSegLength_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuSegLength. */
        r32.setName("RcpuSegLength");
    }
    RegSHMRcpuSegLength_t& operator=(const RegSHMRcpuSegLength_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuSegLength_t;

#define REG_SHM_RCPU_INIT_COUNT ((volatile BCM5719_SHM_H_uint32_t*)0xc0014108) /* Incremented by RX CPU every boot. */
/** @brief Register definition for @ref SHM_t.RcpuInitCount. */
typedef register_container RegSHMRcpuInitCount_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuInitCount"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuInitCount_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuInitCount. */
        r32.setName("RcpuInitCount");
    }
    RegSHMRcpuInitCount_t& operator=(const RegSHMRcpuInitCount_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuInitCount_t;

#define REG_SHM_RCPU_FW_VERSION ((volatile BCM5719_SHM_H_uint32_t*)0xc001410c) /* Set to the bootcode version. e.g. 0x0127 -> v1.39. */
/** @brief Register definition for @ref SHM_t.RcpuFwVersion. */
typedef register_container RegSHMRcpuFwVersion_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuFwVersion"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuFwVersion_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuFwVersion. */
        r32.setName("RcpuFwVersion");
    }
    RegSHMRcpuFwVersion_t& operator=(const RegSHMRcpuFwVersion_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuFwVersion_t;

#define REG_SHM_RCPU_CFG_FEATURE ((volatile BCM5719_SHM_H_uint32_t*)0xc0014110) /* Set to  */
/** @brief Register definition for @ref SHM_t.RcpuCfgFeature. */
typedef register_container RegSHMRcpuCfgFeature_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuCfgFeature"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuCfgFeature_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuCfgFeature. */
        r32.setName("RcpuCfgFeature");
    }
    RegSHMRcpuCfgFeature_t& operator=(const RegSHMRcpuCfgFeature_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuCfgFeature_t;

#define REG_SHM_RCPU_PCI_VENDOR_DEVICE_ID ((volatile BCM5719_SHM_H_uint32_t*)0xc0014114) /* Set to PCI Vendor/Device ID by S2. */
/** @brief Register definition for @ref SHM_t.RcpuPciVendorDeviceId. */
typedef register_container RegSHMRcpuPciVendorDeviceId_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuPciVendorDeviceId"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuPciVendorDeviceId_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuPciVendorDeviceId. */
        r32.setName("RcpuPciVendorDeviceId");
    }
    RegSHMRcpuPciVendorDeviceId_t& operator=(const RegSHMRcpuPciVendorDeviceId_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuPciVendorDeviceId_t;

#define REG_SHM_RCPU_PCI_SUBSYSTEM_ID ((volatile BCM5719_SHM_H_uint32_t*)0xc0014118) /* Set to PCI Subsystem Vendor/Subsystem ID by S2. */
/** @brief Register definition for @ref SHM_t.RcpuPciSubsystemId. */
typedef register_container RegSHMRcpuPciSubsystemId_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuPciSubsystemId"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuPciSubsystemId_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuPciSubsystemId. */
        r32.setName("RcpuPciSubsystemId");
    }
    RegSHMRcpuPciSubsystemId_t& operator=(const RegSHMRcpuPciSubsystemId_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuPciSubsystemId_t;

#define REG_SHM_RCPU_APE_RESET_COUNT ((volatile BCM5719_SHM_H_uint32_t*)0xc001411c) /* Unknown. Incremented by frobnicating routine. */
/** @brief Register definition for @ref SHM_t.RcpuApeResetCount. */
typedef register_container RegSHMRcpuApeResetCount_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuApeResetCount"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuApeResetCount_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuApeResetCount. */
        r32.setName("RcpuApeResetCount");
    }
    RegSHMRcpuApeResetCount_t& operator=(const RegSHMRcpuApeResetCount_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuApeResetCount_t;

#define REG_SHM_RCPU_LAST_APE_STATUS ((volatile BCM5719_SHM_H_uint32_t*)0xc0014120) /* Unknown. Written by frobnicating routine. */
/** @brief Register definition for @ref SHM_t.RcpuLastApeStatus. */
typedef register_container RegSHMRcpuLastApeStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuLastApeStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuLastApeStatus_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuLastApeStatus. */
        r32.setName("RcpuLastApeStatus");
    }
    RegSHMRcpuLastApeStatus_t& operator=(const RegSHMRcpuLastApeStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuLastApeStatus_t;

#define REG_SHM_RCPU_LAST_APE_FW_STATUS ((volatile BCM5719_SHM_H_uint32_t*)0xc0014124) /* Unknown.  */
/** @brief Register definition for @ref SHM_t.RcpuLastApeFwStatus. */
typedef register_container RegSHMRcpuLastApeFwStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuLastApeFwStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuLastApeFwStatus_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuLastApeFwStatus. */
        r32.setName("RcpuLastApeFwStatus");
    }
    RegSHMRcpuLastApeFwStatus_t& operator=(const RegSHMRcpuLastApeFwStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuLastApeFwStatus_t;

#define REG_SHM_RCPU_CFG_HW ((volatile BCM5719_SHM_H_uint32_t*)0xc0014128) /* Set from  */
/** @brief Register definition for @ref SHM_t.RcpuCfgHw. */
typedef register_container RegSHMRcpuCfgHw_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuCfgHw"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuCfgHw_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuCfgHw. */
        r32.setName("RcpuCfgHw");
    }
    RegSHMRcpuCfgHw_t& operator=(const RegSHMRcpuCfgHw_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuCfgHw_t;

#define REG_SHM_RCPU_CFG_HW_2 ((volatile BCM5719_SHM_H_uint32_t*)0xc001412c) /* Set from  */
/** @brief Register definition for @ref SHM_t.RcpuCfgHw2. */
typedef register_container RegSHMRcpuCfgHw2_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuCfgHw2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuCfgHw2_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuCfgHw2. */
        r32.setName("RcpuCfgHw2");
    }
    RegSHMRcpuCfgHw2_t& operator=(const RegSHMRcpuCfgHw2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuCfgHw2_t;

#define REG_SHM_RCPU_CPMU_STATUS ((volatile BCM5719_SHM_H_uint32_t*)0xc0014130) /* Set from  */
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
    BCM5719_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Address, 0, 16)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Status, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Status, 16, 16)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Address, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuCpmuStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMRcpuCpmuStatus_t()
    {
        /** @brief constructor for @ref SHM_t.RcpuCpmuStatus. */
        r32.setName("RcpuCpmuStatus");
        bits.Address.setBaseRegister(&r32);
        bits.Address.setName("Address");
        bits.Status.setBaseRegister(&r32);
        bits.Status.setName("Status");
    }
    RegSHMRcpuCpmuStatus_t& operator=(const RegSHMRcpuCpmuStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMRcpuCpmuStatus_t;

#define REG_SHM_HOST_SEG_SIG ((volatile BCM5719_SHM_H_uint32_t*)0xc0014200) /* Set to APE_HOST_MAGIC ('HOST') to indicate the section is valid. */
/** @brief Register definition for @ref SHM_t.HostSegSig. */
typedef register_container RegSHMHostSegSig_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HostSegSig"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHostSegSig_t()
    {
        /** @brief constructor for @ref SHM_t.HostSegSig. */
        r32.setName("HostSegSig");
    }
    RegSHMHostSegSig_t& operator=(const RegSHMHostSegSig_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHostSegSig_t;

#define REG_SHM_HOST_SEG_LEN ((volatile BCM5719_SHM_H_uint32_t*)0xc0014204) /* Set to 0x20. */
/** @brief Register definition for @ref SHM_t.HostSegLen. */
typedef register_container RegSHMHostSegLen_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HostSegLen"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHostSegLen_t()
    {
        /** @brief constructor for @ref SHM_t.HostSegLen. */
        r32.setName("HostSegLen");
    }
    RegSHMHostSegLen_t& operator=(const RegSHMHostSegLen_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHostSegLen_t;

#define REG_SHM_HOST_INIT_COUNT ((volatile BCM5719_SHM_H_uint32_t*)0xc0014208) /* Incremented by host on every initialization. */
/** @brief Register definition for @ref SHM_t.HostInitCount. */
typedef register_container RegSHMHostInitCount_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HostInitCount"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHostInitCount_t()
    {
        /** @brief constructor for @ref SHM_t.HostInitCount. */
        r32.setName("HostInitCount");
    }
    RegSHMHostInitCount_t& operator=(const RegSHMHostInitCount_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHostInitCount_t;

#define REG_SHM_HOST_DRIVER_ID ((volatile BCM5719_SHM_H_uint32_t*)0xc001420c) /* Linux sets this to 0xF0MM_mm00, where M is the major version  of Linux and m is the minor version. */
/** @brief Register definition for @ref SHM_t.HostDriverId. */
typedef register_container RegSHMHostDriverId_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HostDriverId"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHostDriverId_t()
    {
        /** @brief constructor for @ref SHM_t.HostDriverId. */
        r32.setName("HostDriverId");
    }
    RegSHMHostDriverId_t& operator=(const RegSHMHostDriverId_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHostDriverId_t;

#define REG_SHM_HOST_BEHAVIOR ((volatile BCM5719_SHM_H_uint32_t*)0xc0014210) /*  */
#define     SHM_HOST_BEHAVIOR_NO_PHYLOCK_SHIFT 0u
#define     SHM_HOST_BEHAVIOR_NO_PHYLOCK_MASK  0x1u
#define GET_SHM_HOST_BEHAVIOR_NO_PHYLOCK(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_SHM_HOST_BEHAVIOR_NO_PHYLOCK(__val__)  (((__val__) << 0u) & 0x1u)

/** @brief Register definition for @ref SHM_t.HostBehavior. */
typedef register_container RegSHMHostBehavior_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, NoPHYLock, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_31_1, 1, 31)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_31_1, 1, 31)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, NoPHYLock, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HostBehavior"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHostBehavior_t()
    {
        /** @brief constructor for @ref SHM_t.HostBehavior. */
        r32.setName("HostBehavior");
        bits.NoPHYLock.setBaseRegister(&r32);
        bits.NoPHYLock.setName("NoPHYLock");
    }
    RegSHMHostBehavior_t& operator=(const RegSHMHostBehavior_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHostBehavior_t;

#define REG_SHM_HEARTBEAT_INTERVAL ((volatile BCM5719_SHM_H_uint32_t*)0xc0014214) /* In milliseconds. Set to 0 to disable heartbeating. */
/** @brief Register definition for @ref SHM_t.HeartbeatInterval. */
typedef register_container RegSHMHeartbeatInterval_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HeartbeatInterval"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHeartbeatInterval_t()
    {
        /** @brief constructor for @ref SHM_t.HeartbeatInterval. */
        r32.setName("HeartbeatInterval");
    }
    RegSHMHeartbeatInterval_t& operator=(const RegSHMHeartbeatInterval_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHeartbeatInterval_t;

#define REG_SHM_HEARTBEAT_COUNT ((volatile BCM5719_SHM_H_uint32_t*)0xc0014218) /*  */
/** @brief Register definition for @ref SHM_t.HeartbeatCount. */
typedef register_container RegSHMHeartbeatCount_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HeartbeatCount"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHeartbeatCount_t()
    {
        /** @brief constructor for @ref SHM_t.HeartbeatCount. */
        r32.setName("HeartbeatCount");
    }
    RegSHMHeartbeatCount_t& operator=(const RegSHMHeartbeatCount_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHeartbeatCount_t;

#define REG_SHM_HOST_DRIVER_STATE ((volatile BCM5719_SHM_H_uint32_t*)0xc001421c) /*  */
/** @brief Register definition for @ref SHM_t.HostDriverState. */
typedef register_container RegSHMHostDriverState_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HostDriverState"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMHostDriverState_t()
    {
        /** @brief constructor for @ref SHM_t.HostDriverState. */
        r32.setName("HostDriverState");
    }
    RegSHMHostDriverState_t& operator=(const RegSHMHostDriverState_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMHostDriverState_t;

#define REG_SHM_WOL_SPEED ((volatile BCM5719_SHM_H_uint32_t*)0xc0014224) /*  */
/** @brief Register definition for @ref SHM_t.WolSpeed. */
typedef register_container RegSHMWolSpeed_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "WolSpeed"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMWolSpeed_t()
    {
        /** @brief constructor for @ref SHM_t.WolSpeed. */
        r32.setName("WolSpeed");
    }
    RegSHMWolSpeed_t& operator=(const RegSHMWolSpeed_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMWolSpeed_t;

#define REG_SHM_EVENT_STATUS ((volatile BCM5719_SHM_H_uint32_t*)0xc0014300) /*  */
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
    BCM5719_SHM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_SHM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_3_0, 0, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, DriverEvent, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Command, 8, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, State, 16, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_30_19, 19, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Pending, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Pending, 31, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_30_19, 19, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, State, 16, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, Command, 8, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, DriverEvent, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_SHM_H_uint32_t, reserved_3_0, 0, 4)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_SHM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EventStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMEventStatus_t()
    {
        /** @brief constructor for @ref SHM_t.EventStatus. */
        r32.setName("EventStatus");
        bits.DriverEvent.setBaseRegister(&r32);
        bits.DriverEvent.setName("DriverEvent");
        bits.Command.setBaseRegister(&r32);
        bits.Command.setName("Command");
        bits.State.setBaseRegister(&r32);
        bits.State.setName("State");
        bits.Pending.setBaseRegister(&r32);
        bits.Pending.setName("Pending");
    }
    RegSHMEventStatus_t& operator=(const RegSHMEventStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMEventStatus_t;

#define REG_SHM_PROT_MAGIC ((volatile BCM5719_SHM_H_uint32_t*)0xc0014308) /* This is set to APE_PROT_MAGIC ('PROT') on all functions.  If it is 'PROT', the following fields (MAC0_HIGH/LOW) are valid */
/** @brief Register definition for @ref SHM_t.ProtMagic. */
typedef register_container RegSHMProtMagic_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ProtMagic"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMProtMagic_t()
    {
        /** @brief constructor for @ref SHM_t.ProtMagic. */
        r32.setName("ProtMagic");
    }
    RegSHMProtMagic_t& operator=(const RegSHMProtMagic_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMProtMagic_t;

#define REG_SHM_PROT_MAC0_HIGH ((volatile BCM5719_SHM_H_uint32_t*)0xc0014314) /* High 16 bits of MAC address 0. Only valid if  */
/** @brief Register definition for @ref SHM_t.ProtMac0High. */
typedef register_container RegSHMProtMac0High_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ProtMac0High"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMProtMac0High_t()
    {
        /** @brief constructor for @ref SHM_t.ProtMac0High. */
        r32.setName("ProtMac0High");
    }
    RegSHMProtMac0High_t& operator=(const RegSHMProtMac0High_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMProtMac0High_t;

#define REG_SHM_PROT_MAC0_LOW ((volatile BCM5719_SHM_H_uint32_t*)0xc0014318) /* Low 16 bits of MAC address 0. */
/** @brief Register definition for @ref SHM_t.ProtMac0Low. */
typedef register_container RegSHMProtMac0Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ProtMac0Low"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMProtMac0Low_t()
    {
        /** @brief constructor for @ref SHM_t.ProtMac0Low. */
        r32.setName("ProtMac0Low");
    }
    RegSHMProtMac0Low_t& operator=(const RegSHMProtMac0Low_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMProtMac0Low_t;

#define REG_SHM_NCSI_SIG ((volatile BCM5719_SHM_H_uint32_t*)0xc0014800) /* Set to NCSI_MAGIC ('NCSI') by APE firmware. NOTE: all words in the NCSI section are available in the function 0 SHM area only. */
/** @brief Register definition for @ref SHM_t.NcsiSig. */
typedef register_container RegSHMNcsiSig_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiSig"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiSig_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiSig. */
        r32.setName("NcsiSig");
    }
    RegSHMNcsiSig_t& operator=(const RegSHMNcsiSig_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiSig_t;

#define REG_SHM_NCSI_BUILD_TIME ((volatile BCM5719_SHM_H_uint32_t*)0xc0014810) /* ASCII string spanning three 32-bit words. Unused trailing bytes   are set to zero. */
/** @brief Register definition for @ref SHM_t.NcsiBuildTime. */
typedef register_container RegSHMNcsiBuildTime_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiBuildTime"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiBuildTime_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiBuildTime. */
        r32.setName("NcsiBuildTime");
    }
    RegSHMNcsiBuildTime_t& operator=(const RegSHMNcsiBuildTime_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiBuildTime_t;

#define REG_SHM_NCSI_BUILD_TIME_2 ((volatile BCM5719_SHM_H_uint32_t*)0xc0014814) /*  */
/** @brief Register definition for @ref SHM_t.NcsiBuildTime2. */
typedef register_container RegSHMNcsiBuildTime2_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiBuildTime2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiBuildTime2_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiBuildTime2. */
        r32.setName("NcsiBuildTime2");
    }
    RegSHMNcsiBuildTime2_t& operator=(const RegSHMNcsiBuildTime2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiBuildTime2_t;

#define REG_SHM_NCSI_BUILD_TIME_3 ((volatile BCM5719_SHM_H_uint32_t*)0xc0014818) /*  */
/** @brief Register definition for @ref SHM_t.NcsiBuildTime3. */
typedef register_container RegSHMNcsiBuildTime3_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiBuildTime3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiBuildTime3_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiBuildTime3. */
        r32.setName("NcsiBuildTime3");
    }
    RegSHMNcsiBuildTime3_t& operator=(const RegSHMNcsiBuildTime3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiBuildTime3_t;

#define REG_SHM_NCSI_BUILD_DATE ((volatile BCM5719_SHM_H_uint32_t*)0xc001481c) /* ASCII string spanning three 32-bit words. Unused trailing bytes   are set to zero. */
/** @brief Register definition for @ref SHM_t.NcsiBuildDate. */
typedef register_container RegSHMNcsiBuildDate_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiBuildDate"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiBuildDate_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiBuildDate. */
        r32.setName("NcsiBuildDate");
    }
    RegSHMNcsiBuildDate_t& operator=(const RegSHMNcsiBuildDate_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiBuildDate_t;

#define REG_SHM_NCSI_BUILD_DATE_2 ((volatile BCM5719_SHM_H_uint32_t*)0xc0014820) /*  */
/** @brief Register definition for @ref SHM_t.NcsiBuildDate2. */
typedef register_container RegSHMNcsiBuildDate2_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiBuildDate2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiBuildDate2_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiBuildDate2. */
        r32.setName("NcsiBuildDate2");
    }
    RegSHMNcsiBuildDate2_t& operator=(const RegSHMNcsiBuildDate2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiBuildDate2_t;

#define REG_SHM_NCSI_BUILD_DATE_3 ((volatile BCM5719_SHM_H_uint32_t*)0xc0014824) /*  */
/** @brief Register definition for @ref SHM_t.NcsiBuildDate3. */
typedef register_container RegSHMNcsiBuildDate3_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiBuildDate3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMNcsiBuildDate3_t()
    {
        /** @brief constructor for @ref SHM_t.NcsiBuildDate3. */
        r32.setName("NcsiBuildDate3");
    }
    RegSHMNcsiBuildDate3_t& operator=(const RegSHMNcsiBuildDate3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMNcsiBuildDate3_t;

#define REG_SHM_CHIP_ID ((volatile BCM5719_SHM_H_uint32_t*)0xc0014890) /* The APE code copies the contents of Chip ID to this word */
/** @brief Register definition for @ref SHM_t.ChipId. */
typedef register_container RegSHMChipId_t {
    /** @brief 32bit direct register access. */
    BCM5719_SHM_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ChipId"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegSHMChipId_t()
    {
        /** @brief constructor for @ref SHM_t.ChipId. */
        r32.setName("ChipId");
    }
    RegSHMChipId_t& operator=(const RegSHMChipId_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegSHMChipId_t;

/** @brief Component definition for @ref SHM. */
typedef struct SHM_t {
    /** @brief APE_APE_MAGIC ('APE!') when all is well. */
    RegSHMSegSig_t SegSig;

    /** @brief Set to 0x34. */
    RegSHMApeSegLength_t ApeSegLength;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_SHM_H_uint32_t reserved_8[1];

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
    BCM5719_SHM_H_uint32_t reserved_44[3];

    /** @brief Command sent when using the the APE loader. Zero once handled. */
    RegSHMLoaderCommand_t LoaderCommand;

    /** @brief Argument 0 for the APE loader. */
    RegSHMLoaderArg0_t LoaderArg0;

    /** @brief Argument 1 for the APE loader. */
    RegSHMLoaderArg1_t LoaderArg1;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_SHM_H_uint32_t reserved_68[47];

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
    BCM5719_SHM_H_uint32_t reserved_308[51];

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
    BCM5719_SHM_H_uint32_t reserved_544[1];

    /** @brief  */
    RegSHMWolSpeed_t WolSpeed;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_SHM_H_uint32_t reserved_552[54];

    /** @brief  */
    RegSHMEventStatus_t EventStatus;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_SHM_H_uint32_t reserved_772[1];

    /** @brief This is set to APE_PROT_MAGIC ('PROT') on all functions.  If it is 'PROT', the following fields (MAC0_HIGH/LOW) are valid */
    RegSHMProtMagic_t ProtMagic;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_SHM_H_uint32_t reserved_780[2];

    /** @brief High 16 bits of MAC address 0. Only valid if  */
    RegSHMProtMac0High_t ProtMac0High;

    /** @brief Low 16 bits of MAC address 0. */
    RegSHMProtMac0Low_t ProtMac0Low;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_SHM_H_uint32_t reserved_796[313];

    /** @brief Set to NCSI_MAGIC ('NCSI') by APE firmware. NOTE: all words in the NCSI section are available in the function 0 SHM area only. */
    RegSHMNcsiSig_t NcsiSig;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_SHM_H_uint32_t reserved_2052[3];

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
    BCM5719_SHM_H_uint32_t reserved_2088[26];

    /** @brief The APE code copies the contents of Chip ID to this word */
    RegSHMChipId_t ChipId;

#ifdef CXX_SIMULATOR
    SHM_t()
    {
        SegSig.r32.setComponentOffset(0x0);
        ApeSegLength.r32.setComponentOffset(0x4);
        FwStatus.r32.setComponentOffset(0xc);
        FwFeatures.r32.setComponentOffset(0x10);
        _4014.r32.setComponentOffset(0x14);
        FwVersion.r32.setComponentOffset(0x18);
        SegMessageBufferOffset.r32.setComponentOffset(0x1c);
        SegMessageBufferLength.r32.setComponentOffset(0x20);
        _4024.r32.setComponentOffset(0x24);
        _4028.r32.setComponentOffset(0x28);
        LoaderCommand.r32.setComponentOffset(0x38);
        LoaderArg0.r32.setComponentOffset(0x3c);
        LoaderArg1.r32.setComponentOffset(0x40);
        RcpuSegSig.r32.setComponentOffset(0x100);
        RcpuSegLength.r32.setComponentOffset(0x104);
        RcpuInitCount.r32.setComponentOffset(0x108);
        RcpuFwVersion.r32.setComponentOffset(0x10c);
        RcpuCfgFeature.r32.setComponentOffset(0x110);
        RcpuPciVendorDeviceId.r32.setComponentOffset(0x114);
        RcpuPciSubsystemId.r32.setComponentOffset(0x118);
        RcpuApeResetCount.r32.setComponentOffset(0x11c);
        RcpuLastApeStatus.r32.setComponentOffset(0x120);
        RcpuLastApeFwStatus.r32.setComponentOffset(0x124);
        RcpuCfgHw.r32.setComponentOffset(0x128);
        RcpuCfgHw2.r32.setComponentOffset(0x12c);
        RcpuCpmuStatus.r32.setComponentOffset(0x130);
        HostSegSig.r32.setComponentOffset(0x200);
        HostSegLen.r32.setComponentOffset(0x204);
        HostInitCount.r32.setComponentOffset(0x208);
        HostDriverId.r32.setComponentOffset(0x20c);
        HostBehavior.r32.setComponentOffset(0x210);
        HeartbeatInterval.r32.setComponentOffset(0x214);
        HeartbeatCount.r32.setComponentOffset(0x218);
        HostDriverState.r32.setComponentOffset(0x21c);
        WolSpeed.r32.setComponentOffset(0x224);
        EventStatus.r32.setComponentOffset(0x300);
        ProtMagic.r32.setComponentOffset(0x308);
        ProtMac0High.r32.setComponentOffset(0x314);
        ProtMac0Low.r32.setComponentOffset(0x318);
        NcsiSig.r32.setComponentOffset(0x800);
        NcsiBuildTime.r32.setComponentOffset(0x810);
        NcsiBuildTime2.r32.setComponentOffset(0x814);
        NcsiBuildTime3.r32.setComponentOffset(0x818);
        NcsiBuildDate.r32.setComponentOffset(0x81c);
        NcsiBuildDate2.r32.setComponentOffset(0x820);
        NcsiBuildDate3.r32.setComponentOffset(0x824);
        ChipId.r32.setComponentOffset(0x890);
    }
    void print()
    {
        SegSig.print();
        ApeSegLength.print();
        FwStatus.print();
        FwFeatures.print();
        _4014.print();
        FwVersion.print();
        SegMessageBufferOffset.print();
        SegMessageBufferLength.print();
        _4024.print();
        _4028.print();
        LoaderCommand.print();
        LoaderArg0.print();
        LoaderArg1.print();
        RcpuSegSig.print();
        RcpuSegLength.print();
        RcpuInitCount.print();
        RcpuFwVersion.print();
        RcpuCfgFeature.print();
        RcpuPciVendorDeviceId.print();
        RcpuPciSubsystemId.print();
        RcpuApeResetCount.print();
        RcpuLastApeStatus.print();
        RcpuLastApeFwStatus.print();
        RcpuCfgHw.print();
        RcpuCfgHw2.print();
        RcpuCpmuStatus.print();
        HostSegSig.print();
        HostSegLen.print();
        HostInitCount.print();
        HostDriverId.print();
        HostBehavior.print();
        HeartbeatInterval.print();
        HeartbeatCount.print();
        HostDriverState.print();
        WolSpeed.print();
        EventStatus.print();
        ProtMagic.print();
        ProtMac0High.print();
        ProtMac0Low.print();
        NcsiSig.print();
        NcsiBuildTime.print();
        NcsiBuildTime2.print();
        NcsiBuildTime3.print();
        NcsiBuildDate.print();
        NcsiBuildDate2.print();
        NcsiBuildDate3.print();
        ChipId.print();
    }
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
} SHM_t;

/** @brief Device SHM Registers */
extern volatile SHM_t SHM;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !BCM5719_SHM_H */

/** @} */
