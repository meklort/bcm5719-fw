////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_GEN.h
///
/// @project    bcm5719
///
/// @brief      bcm5719_GEN
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

/** @defgroup BCM5719_GEN_H    bcm5719_GEN */
/** @addtogroup BCM5719_GEN_H
 * @{
 */
#ifndef BCM5719_GEN_H
#define BCM5719_GEN_H

#include <types.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_bcm5719_GEN_sim(void* base);
void init_bcm5719_GEN(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> BCM5719_GEN_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> BCM5719_GEN_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> BCM5719_GEN_H_uint32_t;
#define BCM5719_GEN_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define BCM5719_GEN_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define BCM5719_GEN_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  BCM5719_GEN_H_uint8_t;
typedef uint16_t BCM5719_GEN_H_uint16_t;
typedef uint32_t BCM5719_GEN_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_GEN_BASE ((volatile void*)0xb50) /* General Communication */
#define REG_GEN_SIZE (sizeof(GEN_t))

#define REG_GEN_GEN_FW_MBOX ((volatile BCM5719_GEN_H_uint32_t*)0xb50) /*  */
#define     GEN_GEN_FW_MBOX_MBOX_SHIFT 0u
#define     GEN_GEN_FW_MBOX_MBOX_MASK  0xffffffffu
#define GET_GEN_GEN_FW_MBOX_MBOX(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_GEN_GEN_FW_MBOX_MBOX(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     GEN_GEN_FW_MBOX_MBOX_BOOTCODE_READY 0xb49a89abu


/** @brief Register definition for @ref GEN_t.GenFwMbox. */
typedef register_container RegGENGenFwMbox_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_GEN_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, MBOX, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, MBOX, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_GEN_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenFwMbox"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenFwMbox_t()
    {
        /** @brief constructor for @ref GEN_t.GenFwMbox. */
        r32.setName("GenFwMbox");
        bits.MBOX.setBaseRegister(&r32);
        bits.MBOX.setName("MBOX");
    }
    RegGENGenFwMbox_t& operator=(const RegGENGenFwMbox_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenFwMbox_t;

#define REG_GEN_GEN_DATA_SIG ((volatile BCM5719_GEN_H_uint32_t*)0xb54) /*  */
#define     GEN_GEN_DATA_SIG_SIG_SHIFT 0u
#define     GEN_GEN_DATA_SIG_SIG_MASK  0xffffffffu
#define GET_GEN_GEN_DATA_SIG_SIG(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_GEN_GEN_DATA_SIG_SIG(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     GEN_GEN_DATA_SIG_SIG_STAGE2_MAGIC_INVALID 0xbad0000u
#define     GEN_GEN_DATA_SIG_SIG_STAGE2_CRC_INVALID 0xbad0001u
#define     GEN_GEN_DATA_SIG_SIG_DRIVER_READY 0x4b657654u


/** @brief Register definition for @ref GEN_t.GenDataSig. */
typedef register_container RegGENGenDataSig_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_GEN_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, SIG, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, SIG, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_GEN_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenDataSig"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenDataSig_t()
    {
        /** @brief constructor for @ref GEN_t.GenDataSig. */
        r32.setName("GenDataSig");
        bits.SIG.setBaseRegister(&r32);
        bits.SIG.setName("SIG");
    }
    RegGENGenDataSig_t& operator=(const RegGENGenDataSig_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenDataSig_t;

#define REG_GEN_GEN_CFG ((volatile BCM5719_GEN_H_uint32_t*)0xb58) /* TODO. */
#define     GEN_GEN_CFG_PHY_TYPE__GPHY_SHIFT 4u
#define     GEN_GEN_CFG_PHY_TYPE__GPHY_MASK  0x10u
#define GET_GEN_GEN_CFG_PHY_TYPE__GPHY(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_GEN_GEN_CFG_PHY_TYPE__GPHY(__val__)  (((__val__) << 4u) & 0x10u)
#define     GEN_GEN_CFG_PHY_TYPE__SERDES_SHIFT 5u
#define     GEN_GEN_CFG_PHY_TYPE__SERDES_MASK  0x20u
#define GET_GEN_GEN_CFG_PHY_TYPE__SERDES(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_GEN_GEN_CFG_PHY_TYPE__SERDES(__val__)  (((__val__) << 5u) & 0x20u)
#define     GEN_GEN_CFG_WOL_ENABLE_SHIFT 6u
#define     GEN_GEN_CFG_WOL_ENABLE_MASK  0x40u
#define GET_GEN_GEN_CFG_WOL_ENABLE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_GEN_GEN_CFG_WOL_ENABLE(__val__)  (((__val__) << 6u) & 0x40u)
#define     GEN_GEN_CFG_TODO_SHIFT 7u
#define     GEN_GEN_CFG_TODO_MASK  0xffffff80u
#define GET_GEN_GEN_CFG_TODO(__reg__)  (((__reg__) & 0xffffff80) >> 7u)
#define SET_GEN_GEN_CFG_TODO(__val__)  (((__val__) << 7u) & 0xffffff80u)

/** @brief Register definition for @ref GEN_t.GenCfg. */
typedef register_container RegGENGenCfg_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_GEN_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_3_0, 0, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PHYType_GPHY, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PHYType_SERDES, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, WOLEnable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, TODO, 7, 25)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, TODO, 7, 25)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, WOLEnable, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PHYType_SERDES, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PHYType_GPHY, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_3_0, 0, 4)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_GEN_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenCfg"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenCfg_t()
    {
        /** @brief constructor for @ref GEN_t.GenCfg. */
        r32.setName("GenCfg");
        bits.PHYType_GPHY.setBaseRegister(&r32);
        bits.PHYType_GPHY.setName("PHYType_GPHY");
        bits.PHYType_SERDES.setBaseRegister(&r32);
        bits.PHYType_SERDES.setName("PHYType_SERDES");
        bits.WOLEnable.setBaseRegister(&r32);
        bits.WOLEnable.setName("WOLEnable");
        bits.TODO.setBaseRegister(&r32);
        bits.TODO.setName("TODO");
    }
    RegGENGenCfg_t& operator=(const RegGENGenCfg_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenCfg_t;

#define REG_GEN_GEN_VERSION ((volatile BCM5719_GEN_H_uint32_t*)0xb5c) /* Unusual 16-bit field. */
/** @brief Register definition for @ref GEN_t.GenVersion. */
typedef register_container RegGENGenVersion_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenVersion"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenVersion_t()
    {
        /** @brief constructor for @ref GEN_t.GenVersion. */
        r32.setName("GenVersion");
    }
    RegGENGenVersion_t& operator=(const RegGENGenVersion_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenVersion_t;

#define REG_GEN_GEN_PHY_ID ((volatile BCM5719_GEN_H_uint32_t*)0xb74) /* Can be 0x5A5A_5A5A to indicate that this field is invalid; otherwise,       it is set to the MII PHY ID value. */
/** @brief Register definition for @ref GEN_t.GenPhyId. */
typedef register_container RegGENGenPhyId_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenPhyId"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenPhyId_t()
    {
        /** @brief constructor for @ref GEN_t.GenPhyId. */
        r32.setName("GenPhyId");
    }
    RegGENGenPhyId_t& operator=(const RegGENGenPhyId_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenPhyId_t;

#define REG_GEN_GEN_ASF_STATUS_MBOX ((volatile BCM5719_GEN_H_uint32_t*)0xc00) /* Sometimes set to BOOTCODE_READY_MAGIC. */
/** @brief Register definition for @ref GEN_t.GenAsfStatusMbox. */
typedef register_container RegGENGenAsfStatusMbox_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenAsfStatusMbox"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenAsfStatusMbox_t()
    {
        /** @brief constructor for @ref GEN_t.GenAsfStatusMbox. */
        r32.setName("GenAsfStatusMbox");
    }
    RegGENGenAsfStatusMbox_t& operator=(const RegGENGenAsfStatusMbox_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenAsfStatusMbox_t;

#define REG_GEN_GEN_FW_DRIVER_STATE_MBOX ((volatile BCM5719_GEN_H_uint32_t*)0xc04) /*  */
/** @brief Register definition for @ref GEN_t.GenFwDriverStateMbox. */
typedef register_container RegGENGenFwDriverStateMbox_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenFwDriverStateMbox"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenFwDriverStateMbox_t()
    {
        /** @brief constructor for @ref GEN_t.GenFwDriverStateMbox. */
        r32.setName("GenFwDriverStateMbox");
    }
    RegGENGenFwDriverStateMbox_t& operator=(const RegGENGenFwDriverStateMbox_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenFwDriverStateMbox_t;

#define REG_GEN_GEN_FW_RESET_TYPE_MBOX ((volatile BCM5719_GEN_H_uint32_t*)0xc08) /* TODO */
/** @brief Register definition for @ref GEN_t.GenFwResetTypeMbox. */
typedef register_container RegGENGenFwResetTypeMbox_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenFwResetTypeMbox"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenFwResetTypeMbox_t()
    {
        /** @brief constructor for @ref GEN_t.GenFwResetTypeMbox. */
        r32.setName("GenFwResetTypeMbox");
    }
    RegGENGenFwResetTypeMbox_t& operator=(const RegGENGenFwResetTypeMbox_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenFwResetTypeMbox_t;

#define REG_GEN_GEN_BC ((volatile BCM5719_GEN_H_uint32_t*)0xc0c) /* Set to 0xFEFE_0009 at S2 start. Possibly boot progress indicator.       Upper 16 is always 0xFEFE, possible validity indicator. Observed        lower16 values:     8       9 - Stage2 start */
/** @brief Register definition for @ref GEN_t.GenBc. */
typedef register_container RegGENGenBc_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenBc"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenBc_t()
    {
        /** @brief constructor for @ref GEN_t.GenBc. */
        r32.setName("GenBc");
    }
    RegGENGenBc_t& operator=(const RegGENGenBc_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenBc_t;

#define REG_GEN_GEN_MAC_ADDR_HIGH_MBOX ((volatile BCM5719_GEN_H_uint32_t*)0xc14) /*  */
/** @brief Register definition for @ref GEN_t.GenMacAddrHighMbox. */
typedef register_container RegGENGenMacAddrHighMbox_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenMacAddrHighMbox"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenMacAddrHighMbox_t()
    {
        /** @brief constructor for @ref GEN_t.GenMacAddrHighMbox. */
        r32.setName("GenMacAddrHighMbox");
    }
    RegGENGenMacAddrHighMbox_t& operator=(const RegGENGenMacAddrHighMbox_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenMacAddrHighMbox_t;

#define REG_GEN_GEN_MAC_ADDR_LOW_MBOX ((volatile BCM5719_GEN_H_uint32_t*)0xc18) /*  */
/** @brief Register definition for @ref GEN_t.GenMacAddrLowMbox. */
typedef register_container RegGENGenMacAddrLowMbox_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenMacAddrLowMbox"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenMacAddrLowMbox_t()
    {
        /** @brief constructor for @ref GEN_t.GenMacAddrLowMbox. */
        r32.setName("GenMacAddrLowMbox");
    }
    RegGENGenMacAddrLowMbox_t& operator=(const RegGENGenMacAddrLowMbox_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenMacAddrLowMbox_t;

#define REG_GEN_GEN_D8 ((volatile BCM5719_GEN_H_uint32_t*)0xc28) /* Field names are guessed. */
#define     GEN_GEN_D8_SKIP_MAIN_LOOP_INIT_SHIFT 0u
#define     GEN_GEN_D8_SKIP_MAIN_LOOP_INIT_MASK  0x1u
#define GET_GEN_GEN_D8_SKIP_MAIN_LOOP_INIT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_GEN_GEN_D8_SKIP_MAIN_LOOP_INIT(__val__)  (((__val__) << 0u) & 0x1u)
#define     GEN_GEN_D8_FORCE_WOL_SHIFT 1u
#define     GEN_GEN_D8_FORCE_WOL_MASK  0x2u
#define GET_GEN_GEN_D8_FORCE_WOL(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_GEN_GEN_D8_FORCE_WOL(__val__)  (((__val__) << 1u) & 0x2u)
#define     GEN_GEN_D8_NO_MODIFY_MISCELLANEOUS_CONTROL_SHIFT 4u
#define     GEN_GEN_D8_NO_MODIFY_MISCELLANEOUS_CONTROL_MASK  0x10u
#define GET_GEN_GEN_D8_NO_MODIFY_MISCELLANEOUS_CONTROL(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_GEN_GEN_D8_NO_MODIFY_MISCELLANEOUS_CONTROL(__val__)  (((__val__) << 4u) & 0x10u)
#define     GEN_GEN_D8_UNKNOWN_7_7_SHIFT 7u
#define     GEN_GEN_D8_UNKNOWN_7_7_MASK  0x80u
#define GET_GEN_GEN_D8_UNKNOWN_7_7(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_GEN_GEN_D8_UNKNOWN_7_7(__val__)  (((__val__) << 7u) & 0x80u)

/** @brief Register definition for @ref GEN_t.GenD8. */
typedef register_container RegGENGenD8_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_GEN_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, SkipMainLoopInit, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, ForceWOL, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_3_2, 2, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, NoModifyMiscellaneousControl, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_6_5, 5, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_7_7, 7, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_31_8, 8, 24)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_31_8, 8, 24)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_7_7, 7, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_6_5, 5, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, NoModifyMiscellaneousControl, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_3_2, 2, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, ForceWOL, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, SkipMainLoopInit, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_GEN_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenD8"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenD8_t()
    {
        /** @brief constructor for @ref GEN_t.GenD8. */
        r32.setName("GenD8");
        bits.SkipMainLoopInit.setBaseRegister(&r32);
        bits.SkipMainLoopInit.setName("SkipMainLoopInit");
        bits.ForceWOL.setBaseRegister(&r32);
        bits.ForceWOL.setName("ForceWOL");
        bits.NoModifyMiscellaneousControl.setBaseRegister(&r32);
        bits.NoModifyMiscellaneousControl.setName("NoModifyMiscellaneousControl");
        bits.unknown_7_7.setBaseRegister(&r32);
        bits.unknown_7_7.setName("unknown_7_7");
    }
    RegGENGenD8_t& operator=(const RegGENGenD8_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenD8_t;

#define REG_GEN_GEN_1DC ((volatile BCM5719_GEN_H_uint32_t*)0xd2c) /* Unknown. Some information from  */
/** @brief Register definition for @ref GEN_t.Gen1dc. */
typedef register_container RegGENGen1dc_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Gen1dc"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGen1dc_t()
    {
        /** @brief constructor for @ref GEN_t.Gen1dc. */
        r32.setName("Gen1dc");
    }
    RegGENGen1dc_t& operator=(const RegGENGen1dc_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGen1dc_t;

#define REG_GEN_GEN_WOL_MBOX ((volatile BCM5719_GEN_H_uint32_t*)0xd30) /* Register manual states "recommended value" is 0x474C_0000. */
/** @brief Register definition for @ref GEN_t.GenWolMbox. */
typedef register_container RegGENGenWolMbox_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenWolMbox"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenWolMbox_t()
    {
        /** @brief constructor for @ref GEN_t.GenWolMbox. */
        r32.setName("GenWolMbox");
    }
    RegGENGenWolMbox_t& operator=(const RegGENGenWolMbox_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenWolMbox_t;

#define REG_GEN_GEN_CFG_FEATURE ((volatile BCM5719_GEN_H_uint32_t*)0xd34) /*  */
#define     GEN_GEN_CFG_FEATURE_WOL_ENABLE_SHIFT 0u
#define     GEN_GEN_CFG_FEATURE_WOL_ENABLE_MASK  0x1u
#define GET_GEN_GEN_CFG_FEATURE_WOL_ENABLE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_GEN_GEN_CFG_FEATURE_WOL_ENABLE(__val__)  (((__val__) << 0u) & 0x1u)
#define     GEN_GEN_CFG_FEATURE_PXE_ENABLE_SHIFT 1u
#define     GEN_GEN_CFG_FEATURE_PXE_ENABLE_MASK  0x2u
#define GET_GEN_GEN_CFG_FEATURE_PXE_ENABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_GEN_GEN_CFG_FEATURE_PXE_ENABLE(__val__)  (((__val__) << 1u) & 0x2u)
#define     GEN_GEN_CFG_FEATURE_PXE_SPEED_SHIFT 2u
#define     GEN_GEN_CFG_FEATURE_PXE_SPEED_MASK  0x3cu
#define GET_GEN_GEN_CFG_FEATURE_PXE_SPEED(__reg__)  (((__reg__) & 0x3c) >> 2u)
#define SET_GEN_GEN_CFG_FEATURE_PXE_SPEED(__val__)  (((__val__) << 2u) & 0x3cu)
#define     GEN_GEN_CFG_FEATURE_ASF_ENABLE_SHIFT 7u
#define     GEN_GEN_CFG_FEATURE_ASF_ENABLE_MASK  0x80u
#define GET_GEN_GEN_CFG_FEATURE_ASF_ENABLE(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_GEN_GEN_CFG_FEATURE_ASF_ENABLE(__val__)  (((__val__) << 7u) & 0x80u)
#define     GEN_GEN_CFG_FEATURE_PXE_BAR_SIZE_SHIFT 8u
#define     GEN_GEN_CFG_FEATURE_PXE_BAR_SIZE_MASK  0xf00u
#define GET_GEN_GEN_CFG_FEATURE_PXE_BAR_SIZE(__reg__)  (((__reg__) & 0xf00) >> 8u)
#define SET_GEN_GEN_CFG_FEATURE_PXE_BAR_SIZE(__val__)  (((__val__) << 8u) & 0xf00u)
#define     GEN_GEN_CFG_FEATURE_DISABLE_SETUP_MESSAGE_SHIFT 12u
#define     GEN_GEN_CFG_FEATURE_DISABLE_SETUP_MESSAGE_MASK  0x1000u
#define GET_GEN_GEN_CFG_FEATURE_DISABLE_SETUP_MESSAGE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_GEN_GEN_CFG_FEATURE_DISABLE_SETUP_MESSAGE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     GEN_GEN_CFG_FEATURE_HOTKEY_OPTION_SHIFT 13u
#define     GEN_GEN_CFG_FEATURE_HOTKEY_OPTION_MASK  0x2000u
#define GET_GEN_GEN_CFG_FEATURE_HOTKEY_OPTION(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_GEN_GEN_CFG_FEATURE_HOTKEY_OPTION(__val__)  (((__val__) << 13u) & 0x2000u)
#define     GEN_GEN_CFG_FEATURE_PXE_BOOTSTRAP_TYPE_SHIFT 14u
#define     GEN_GEN_CFG_FEATURE_PXE_BOOTSTRAP_TYPE_MASK  0xc000u
#define GET_GEN_GEN_CFG_FEATURE_PXE_BOOTSTRAP_TYPE(__reg__)  (((__reg__) & 0xc000) >> 14u)
#define SET_GEN_GEN_CFG_FEATURE_PXE_BOOTSTRAP_TYPE(__val__)  (((__val__) << 14u) & 0xc000u)
#define     GEN_GEN_CFG_FEATURE_PXE_MESSAGE_TIMEOUT_SHIFT 16u
#define     GEN_GEN_CFG_FEATURE_PXE_MESSAGE_TIMEOUT_MASK  0xf0000u
#define GET_GEN_GEN_CFG_FEATURE_PXE_MESSAGE_TIMEOUT(__reg__)  (((__reg__) & 0xf0000) >> 16u)
#define SET_GEN_GEN_CFG_FEATURE_PXE_MESSAGE_TIMEOUT(__val__)  (((__val__) << 16u) & 0xf0000u)
#define     GEN_GEN_CFG_FEATURE_PXE_BOOT_PROTOCOL_SHIFT 20u
#define     GEN_GEN_CFG_FEATURE_PXE_BOOT_PROTOCOL_MASK  0x300000u
#define GET_GEN_GEN_CFG_FEATURE_PXE_BOOT_PROTOCOL(__reg__)  (((__reg__) & 0x300000) >> 20u)
#define SET_GEN_GEN_CFG_FEATURE_PXE_BOOT_PROTOCOL(__val__)  (((__val__) << 20u) & 0x300000u)
#define     GEN_GEN_CFG_FEATURE_LOM_DESIGN_SHIFT 22u
#define     GEN_GEN_CFG_FEATURE_LOM_DESIGN_MASK  0x400000u
#define GET_GEN_GEN_CFG_FEATURE_LOM_DESIGN(__reg__)  (((__reg__) & 0x400000) >> 22u)
#define SET_GEN_GEN_CFG_FEATURE_LOM_DESIGN(__val__)  (((__val__) << 22u) & 0x400000u)
#define     GEN_GEN_CFG_FEATURE_VAUX_CUTOFF_DELAY_SHIFT 23u
#define     GEN_GEN_CFG_FEATURE_VAUX_CUTOFF_DELAY_MASK  0x1800000u
#define GET_GEN_GEN_CFG_FEATURE_VAUX_CUTOFF_DELAY(__reg__)  (((__reg__) & 0x1800000) >> 23u)
#define SET_GEN_GEN_CFG_FEATURE_VAUX_CUTOFF_DELAY(__val__)  (((__val__) << 23u) & 0x1800000u)
#define     GEN_GEN_CFG_FEATURE_WOL_LIMIT_10_SHIFT 25u
#define     GEN_GEN_CFG_FEATURE_WOL_LIMIT_10_MASK  0x2000000u
#define GET_GEN_GEN_CFG_FEATURE_WOL_LIMIT_10(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_GEN_GEN_CFG_FEATURE_WOL_LIMIT_10(__val__)  (((__val__) << 25u) & 0x2000000u)
#define     GEN_GEN_CFG_FEATURE_LINK_IDLE_SHIFT 26u
#define     GEN_GEN_CFG_FEATURE_LINK_IDLE_MASK  0x4000000u
#define GET_GEN_GEN_CFG_FEATURE_LINK_IDLE(__reg__)  (((__reg__) & 0x4000000) >> 26u)
#define SET_GEN_GEN_CFG_FEATURE_LINK_IDLE(__val__)  (((__val__) << 26u) & 0x4000000u)
#define     GEN_GEN_CFG_FEATURE_UNKNOWN_27_27_SHIFT 27u
#define     GEN_GEN_CFG_FEATURE_UNKNOWN_27_27_MASK  0x8000000u
#define GET_GEN_GEN_CFG_FEATURE_UNKNOWN_27_27(__reg__)  (((__reg__) & 0x8000000) >> 27u)
#define SET_GEN_GEN_CFG_FEATURE_UNKNOWN_27_27(__val__)  (((__val__) << 27u) & 0x8000000u)
#define     GEN_GEN_CFG_FEATURE_CABLE_SENSE_SHIFT 28u
#define     GEN_GEN_CFG_FEATURE_CABLE_SENSE_MASK  0x10000000u
#define GET_GEN_GEN_CFG_FEATURE_CABLE_SENSE(__reg__)  (((__reg__) & 0x10000000) >> 28u)
#define SET_GEN_GEN_CFG_FEATURE_CABLE_SENSE(__val__)  (((__val__) << 28u) & 0x10000000u)
#define     GEN_GEN_CFG_FEATURE_MBA_VLAN_ENABLE_SHIFT 29u
#define     GEN_GEN_CFG_FEATURE_MBA_VLAN_ENABLE_MASK  0x20000000u
#define GET_GEN_GEN_CFG_FEATURE_MBA_VLAN_ENABLE(__reg__)  (((__reg__) & 0x20000000) >> 29u)
#define SET_GEN_GEN_CFG_FEATURE_MBA_VLAN_ENABLE(__val__)  (((__val__) << 29u) & 0x20000000u)
#define     GEN_GEN_CFG_FEATURE_LINK_AWARE_POWER_MODE_SHIFT 30u
#define     GEN_GEN_CFG_FEATURE_LINK_AWARE_POWER_MODE_MASK  0x40000000u
#define GET_GEN_GEN_CFG_FEATURE_LINK_AWARE_POWER_MODE(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_GEN_GEN_CFG_FEATURE_LINK_AWARE_POWER_MODE(__val__)  (((__val__) << 30u) & 0x40000000u)
#define     GEN_GEN_CFG_FEATURE_LINK_SPEED_POWER_MODE_SHIFT 31u
#define     GEN_GEN_CFG_FEATURE_LINK_SPEED_POWER_MODE_MASK  0x80000000u
#define GET_GEN_GEN_CFG_FEATURE_LINK_SPEED_POWER_MODE(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_GEN_GEN_CFG_FEATURE_LINK_SPEED_POWER_MODE(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref GEN_t.GenCfgFeature. */
typedef register_container RegGENGenCfgFeature_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_GEN_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, WOLEnable, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PXEEnable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PXESpeed, 2, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_6_6, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, ASFEnable, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PXEBARSize, 8, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, DisableSetupMessage, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, HotkeyOption, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PXEBootstrapType, 14, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PXEMessageTimeout, 16, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PXEBootProtocol, 20, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, LOMDesign, 22, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, VAUXCutoffDelay, 23, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, WOLLimit10, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, LinkIdle, 26, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_27_27, 27, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, CableSense, 28, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, MBAVLANEnable, 29, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, LinkAwarePowerMode, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, LinkSpeedPowerMode, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, LinkSpeedPowerMode, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, LinkAwarePowerMode, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, MBAVLANEnable, 29, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, CableSense, 28, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_27_27, 27, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, LinkIdle, 26, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, WOLLimit10, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, VAUXCutoffDelay, 23, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, LOMDesign, 22, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PXEBootProtocol, 20, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PXEMessageTimeout, 16, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PXEBootstrapType, 14, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, HotkeyOption, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, DisableSetupMessage, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PXEBARSize, 8, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, ASFEnable, 7, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_6_6, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PXESpeed, 2, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PXEEnable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, WOLEnable, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_GEN_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenCfgFeature"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenCfgFeature_t()
    {
        /** @brief constructor for @ref GEN_t.GenCfgFeature. */
        r32.setName("GenCfgFeature");
        bits.WOLEnable.setBaseRegister(&r32);
        bits.WOLEnable.setName("WOLEnable");
        bits.PXEEnable.setBaseRegister(&r32);
        bits.PXEEnable.setName("PXEEnable");
        bits.PXESpeed.setBaseRegister(&r32);
        bits.PXESpeed.setName("PXESpeed");
        bits.ASFEnable.setBaseRegister(&r32);
        bits.ASFEnable.setName("ASFEnable");
        bits.PXEBARSize.setBaseRegister(&r32);
        bits.PXEBARSize.setName("PXEBARSize");
        bits.DisableSetupMessage.setBaseRegister(&r32);
        bits.DisableSetupMessage.setName("DisableSetupMessage");
        bits.HotkeyOption.setBaseRegister(&r32);
        bits.HotkeyOption.setName("HotkeyOption");
        bits.PXEBootstrapType.setBaseRegister(&r32);
        bits.PXEBootstrapType.setName("PXEBootstrapType");
        bits.PXEMessageTimeout.setBaseRegister(&r32);
        bits.PXEMessageTimeout.setName("PXEMessageTimeout");
        bits.PXEBootProtocol.setBaseRegister(&r32);
        bits.PXEBootProtocol.setName("PXEBootProtocol");
        bits.LOMDesign.setBaseRegister(&r32);
        bits.LOMDesign.setName("LOMDesign");
        bits.VAUXCutoffDelay.setBaseRegister(&r32);
        bits.VAUXCutoffDelay.setName("VAUXCutoffDelay");
        bits.WOLLimit10.setBaseRegister(&r32);
        bits.WOLLimit10.setName("WOLLimit10");
        bits.LinkIdle.setBaseRegister(&r32);
        bits.LinkIdle.setName("LinkIdle");
        bits.unknown_27_27.setBaseRegister(&r32);
        bits.unknown_27_27.setName("unknown_27_27");
        bits.CableSense.setBaseRegister(&r32);
        bits.CableSense.setName("CableSense");
        bits.MBAVLANEnable.setBaseRegister(&r32);
        bits.MBAVLANEnable.setName("MBAVLANEnable");
        bits.LinkAwarePowerMode.setBaseRegister(&r32);
        bits.LinkAwarePowerMode.setName("LinkAwarePowerMode");
        bits.LinkSpeedPowerMode.setBaseRegister(&r32);
        bits.LinkSpeedPowerMode.setName("LinkSpeedPowerMode");
    }
    RegGENGenCfgFeature_t& operator=(const RegGENGenCfgFeature_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenCfgFeature_t;

#define REG_GEN_GEN_CFG_HW ((volatile BCM5719_GEN_H_uint32_t*)0xd38) /* Set from NVM. */
#define     GEN_GEN_CFG_HW_LEGACY_LED_CONTROL_SHIFT 2u
#define     GEN_GEN_CFG_HW_LEGACY_LED_CONTROL_MASK  0xcu
#define GET_GEN_GEN_CFG_HW_LEGACY_LED_CONTROL(__reg__)  (((__reg__) & 0xc) >> 2u)
#define SET_GEN_GEN_CFG_HW_LEGACY_LED_CONTROL(__val__)  (((__val__) << 2u) & 0xcu)
#define     GEN_GEN_CFG_HW_REVERSE_N_WAY_SHIFT 12u
#define     GEN_GEN_CFG_HW_REVERSE_N_WAY_MASK  0x1000u
#define GET_GEN_GEN_CFG_HW_REVERSE_N_WAY(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_GEN_GEN_CFG_HW_REVERSE_N_WAY(__val__)  (((__val__) << 12u) & 0x1000u)
#define     GEN_GEN_CFG_HW_MINI_PCI_SHIFT 13u
#define     GEN_GEN_CFG_HW_MINI_PCI_MASK  0x2000u
#define GET_GEN_GEN_CFG_HW_MINI_PCI(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_GEN_GEN_CFG_HW_MINI_PCI(__val__)  (((__val__) << 13u) & 0x2000u)
#define     GEN_GEN_CFG_HW_AUTO_POWERDOWN_ENABLE_SHIFT 14u
#define     GEN_GEN_CFG_HW_AUTO_POWERDOWN_ENABLE_MASK  0x4000u
#define GET_GEN_GEN_CFG_HW_AUTO_POWERDOWN_ENABLE(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_GEN_GEN_CFG_HW_AUTO_POWERDOWN_ENABLE(__val__)  (((__val__) << 14u) & 0x4000u)
#define     GEN_GEN_CFG_HW_SHASTA_LED_CONTROL_SHIFT 15u
#define     GEN_GEN_CFG_HW_SHASTA_LED_CONTROL_MASK  0x18000u
#define GET_GEN_GEN_CFG_HW_SHASTA_LED_CONTROL(__reg__)  (((__reg__) & 0x18000) >> 15u)
#define SET_GEN_GEN_CFG_HW_SHASTA_LED_CONTROL(__val__)  (((__val__) << 15u) & 0x18000u)
#define     GEN_GEN_CFG_HW_SHASTA_LED_CONTROL_LEGACY 0x0u
#define     GEN_GEN_CFG_HW_SHASTA_LED_CONTROL_SHARED 0x1u
#define     GEN_GEN_CFG_HW_SHASTA_LED_CONTROL_MAC 0x2u
#define     GEN_GEN_CFG_HW_SHASTA_LED_CONTROL_COMBO 0x3u

#define     GEN_GEN_CFG_HW_TIME_SYNC_MODE_ENABLE_SHIFT 17u
#define     GEN_GEN_CFG_HW_TIME_SYNC_MODE_ENABLE_MASK  0x20000u
#define GET_GEN_GEN_CFG_HW_TIME_SYNC_MODE_ENABLE(__reg__)  (((__reg__) & 0x20000) >> 17u)
#define SET_GEN_GEN_CFG_HW_TIME_SYNC_MODE_ENABLE(__val__)  (((__val__) << 17u) & 0x20000u)
#define     GEN_GEN_CFG_HW_TIMESYNC_GPIO_MAPPING_SHIFT 18u
#define     GEN_GEN_CFG_HW_TIMESYNC_GPIO_MAPPING_MASK  0xc0000u
#define GET_GEN_GEN_CFG_HW_TIMESYNC_GPIO_MAPPING(__reg__)  (((__reg__) & 0xc0000) >> 18u)
#define SET_GEN_GEN_CFG_HW_TIMESYNC_GPIO_MAPPING(__val__)  (((__val__) << 18u) & 0xc0000u)
#define     GEN_GEN_CFG_HW_APE_GPIO_0_MAPPING_SHIFT 20u
#define     GEN_GEN_CFG_HW_APE_GPIO_0_MAPPING_MASK  0x700000u
#define GET_GEN_GEN_CFG_HW_APE_GPIO_0_MAPPING(__reg__)  (((__reg__) & 0x700000) >> 20u)
#define SET_GEN_GEN_CFG_HW_APE_GPIO_0_MAPPING(__val__)  (((__val__) << 20u) & 0x700000u)
#define     GEN_GEN_CFG_HW_APE_GPIO_1_MAPPING_SHIFT 23u
#define     GEN_GEN_CFG_HW_APE_GPIO_1_MAPPING_MASK  0x3800000u
#define GET_GEN_GEN_CFG_HW_APE_GPIO_1_MAPPING(__reg__)  (((__reg__) & 0x3800000) >> 23u)
#define SET_GEN_GEN_CFG_HW_APE_GPIO_1_MAPPING(__val__)  (((__val__) << 23u) & 0x3800000u)
#define     GEN_GEN_CFG_HW_APE_GPIO_2_MAPPING_SHIFT 26u
#define     GEN_GEN_CFG_HW_APE_GPIO_2_MAPPING_MASK  0x1c000000u
#define GET_GEN_GEN_CFG_HW_APE_GPIO_2_MAPPING(__reg__)  (((__reg__) & 0x1c000000) >> 26u)
#define SET_GEN_GEN_CFG_HW_APE_GPIO_2_MAPPING(__val__)  (((__val__) << 26u) & 0x1c000000u)
#define     GEN_GEN_CFG_HW_APE_GPIO_3_MAPPING_SHIFT 29u
#define     GEN_GEN_CFG_HW_APE_GPIO_3_MAPPING_MASK  0xe0000000u
#define GET_GEN_GEN_CFG_HW_APE_GPIO_3_MAPPING(__reg__)  (((__reg__) & 0xe0000000) >> 29u)
#define SET_GEN_GEN_CFG_HW_APE_GPIO_3_MAPPING(__val__)  (((__val__) << 29u) & 0xe0000000u)

/** @brief Register definition for @ref GEN_t.GenCfgHw. */
typedef register_container RegGENGenCfgHw_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_GEN_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_1_0, 0, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, LegacyLEDControl, 2, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_11_4, 4, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, ReverseN_Way, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, MiniPCI, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, AutoPowerdownEnable, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, SHASTALEDControl, 15, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, TimeSyncModeEnable, 17, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, TimesyncGPIOMapping, 18, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, APEGPIO0Mapping, 20, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, APEGPIO1Mapping, 23, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, APEGPIO2Mapping, 26, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, APEGPIO3Mapping, 29, 3)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, APEGPIO3Mapping, 29, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, APEGPIO2Mapping, 26, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, APEGPIO1Mapping, 23, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, APEGPIO0Mapping, 20, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, TimesyncGPIOMapping, 18, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, TimeSyncModeEnable, 17, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, SHASTALEDControl, 15, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, AutoPowerdownEnable, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, MiniPCI, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, ReverseN_Way, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_11_4, 4, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, LegacyLEDControl, 2, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_1_0, 0, 2)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_GEN_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenCfgHw"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenCfgHw_t()
    {
        /** @brief constructor for @ref GEN_t.GenCfgHw. */
        r32.setName("GenCfgHw");
        bits.LegacyLEDControl.setBaseRegister(&r32);
        bits.LegacyLEDControl.setName("LegacyLEDControl");
        bits.ReverseN_Way.setBaseRegister(&r32);
        bits.ReverseN_Way.setName("ReverseN_Way");
        bits.MiniPCI.setBaseRegister(&r32);
        bits.MiniPCI.setName("MiniPCI");
        bits.AutoPowerdownEnable.setBaseRegister(&r32);
        bits.AutoPowerdownEnable.setName("AutoPowerdownEnable");
        bits.SHASTALEDControl.setBaseRegister(&r32);
        bits.SHASTALEDControl.setName("SHASTALEDControl");
        bits.TimeSyncModeEnable.setBaseRegister(&r32);
        bits.TimeSyncModeEnable.setName("TimeSyncModeEnable");
        bits.TimesyncGPIOMapping.setBaseRegister(&r32);
        bits.TimesyncGPIOMapping.setName("TimesyncGPIOMapping");
        bits.APEGPIO0Mapping.setBaseRegister(&r32);
        bits.APEGPIO0Mapping.setName("APEGPIO0Mapping");
        bits.APEGPIO1Mapping.setBaseRegister(&r32);
        bits.APEGPIO1Mapping.setName("APEGPIO1Mapping");
        bits.APEGPIO2Mapping.setBaseRegister(&r32);
        bits.APEGPIO2Mapping.setName("APEGPIO2Mapping");
        bits.APEGPIO3Mapping.setBaseRegister(&r32);
        bits.APEGPIO3Mapping.setName("APEGPIO3Mapping");
    }
    RegGENGenCfgHw_t& operator=(const RegGENGenCfgHw_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenCfgHw_t;

#define REG_GEN_GEN_CFG_SHARED ((volatile BCM5719_GEN_H_uint32_t*)0xd3c) /* Set from NVM. */
#define     GEN_GEN_CFG_SHARED_PORT_SWAP_SHIFT 0u
#define     GEN_GEN_CFG_SHARED_PORT_SWAP_MASK  0x1u
#define GET_GEN_GEN_CFG_SHARED_PORT_SWAP(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_GEN_GEN_CFG_SHARED_PORT_SWAP(__val__)  (((__val__) << 0u) & 0x1u)
#define     GEN_GEN_CFG_SHARED_ASPM_DEBOUNCE_SHIFT 1u
#define     GEN_GEN_CFG_SHARED_ASPM_DEBOUNCE_MASK  0x2u
#define GET_GEN_GEN_CFG_SHARED_ASPM_DEBOUNCE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_GEN_GEN_CFG_SHARED_ASPM_DEBOUNCE(__val__)  (((__val__) << 1u) & 0x2u)
#define     GEN_GEN_CFG_SHARED_FIBER_WOL_CAPABLE_SHIFT 2u
#define     GEN_GEN_CFG_SHARED_FIBER_WOL_CAPABLE_MASK  0x4u
#define GET_GEN_GEN_CFG_SHARED_FIBER_WOL_CAPABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_GEN_GEN_CFG_SHARED_FIBER_WOL_CAPABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     GEN_GEN_CFG_SHARED_DISABLE_POWER_SAVING_SHIFT 3u
#define     GEN_GEN_CFG_SHARED_DISABLE_POWER_SAVING_MASK  0x8u
#define GET_GEN_GEN_CFG_SHARED_DISABLE_POWER_SAVING(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_GEN_GEN_CFG_SHARED_DISABLE_POWER_SAVING(__val__)  (((__val__) << 3u) & 0x8u)
#define     GEN_GEN_CFG_SHARED_UNKNOWN_7_7_SHIFT 7u
#define     GEN_GEN_CFG_SHARED_UNKNOWN_7_7_MASK  0x80u
#define GET_GEN_GEN_CFG_SHARED_UNKNOWN_7_7(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_GEN_GEN_CFG_SHARED_UNKNOWN_7_7(__val__)  (((__val__) << 7u) & 0x80u)
#define     GEN_GEN_CFG_SHARED_UNKNOWN_8_8_SHIFT 8u
#define     GEN_GEN_CFG_SHARED_UNKNOWN_8_8_MASK  0x100u
#define GET_GEN_GEN_CFG_SHARED_UNKNOWN_8_8(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_GEN_GEN_CFG_SHARED_UNKNOWN_8_8(__val__)  (((__val__) << 8u) & 0x100u)
#define     GEN_GEN_CFG_SHARED_UNKNOWN_10_9_SHIFT 9u
#define     GEN_GEN_CFG_SHARED_UNKNOWN_10_9_MASK  0x600u
#define GET_GEN_GEN_CFG_SHARED_UNKNOWN_10_9(__reg__)  (((__reg__) & 0x600) >> 9u)
#define SET_GEN_GEN_CFG_SHARED_UNKNOWN_10_9(__val__)  (((__val__) << 9u) & 0x600u)
#define     GEN_GEN_CFG_SHARED_UNKNOWN_15_15_SHIFT 15u
#define     GEN_GEN_CFG_SHARED_UNKNOWN_15_15_MASK  0x8000u
#define GET_GEN_GEN_CFG_SHARED_UNKNOWN_15_15(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_GEN_GEN_CFG_SHARED_UNKNOWN_15_15(__val__)  (((__val__) << 15u) & 0x8000u)
#define     GEN_GEN_CFG_SHARED_LINK_FLAP_AVOID_SHIFT 22u
#define     GEN_GEN_CFG_SHARED_LINK_FLAP_AVOID_MASK  0x400000u
#define GET_GEN_GEN_CFG_SHARED_LINK_FLAP_AVOID(__reg__)  (((__reg__) & 0x400000) >> 22u)
#define SET_GEN_GEN_CFG_SHARED_LINK_FLAP_AVOID(__val__)  (((__val__) << 22u) & 0x400000u)
#define     GEN_GEN_CFG_SHARED_1G_ON_VAUX_OK_SHIFT 23u
#define     GEN_GEN_CFG_SHARED_1G_ON_VAUX_OK_MASK  0x800000u
#define GET_GEN_GEN_CFG_SHARED_1G_ON_VAUX_OK(__reg__)  (((__reg__) & 0x800000) >> 23u)
#define SET_GEN_GEN_CFG_SHARED_1G_ON_VAUX_OK(__val__)  (((__val__) << 23u) & 0x800000u)
#define     GEN_GEN_CFG_SHARED_UNKNOWN_27_26_SHIFT 26u
#define     GEN_GEN_CFG_SHARED_UNKNOWN_27_26_MASK  0xc000000u
#define GET_GEN_GEN_CFG_SHARED_UNKNOWN_27_26(__reg__)  (((__reg__) & 0xc000000) >> 26u)
#define SET_GEN_GEN_CFG_SHARED_UNKNOWN_27_26(__val__)  (((__val__) << 26u) & 0xc000000u)
#define     GEN_GEN_CFG_SHARED_UNKNOWN_29_28_SHIFT 28u
#define     GEN_GEN_CFG_SHARED_UNKNOWN_29_28_MASK  0x30000000u
#define GET_GEN_GEN_CFG_SHARED_UNKNOWN_29_28(__reg__)  (((__reg__) & 0x30000000) >> 28u)
#define SET_GEN_GEN_CFG_SHARED_UNKNOWN_29_28(__val__)  (((__val__) << 28u) & 0x30000000u)
#define     GEN_GEN_CFG_SHARED_UNKNOWN_31_30_SHIFT 30u
#define     GEN_GEN_CFG_SHARED_UNKNOWN_31_30_MASK  0xc0000000u
#define GET_GEN_GEN_CFG_SHARED_UNKNOWN_31_30(__reg__)  (((__reg__) & 0xc0000000) >> 30u)
#define SET_GEN_GEN_CFG_SHARED_UNKNOWN_31_30(__val__)  (((__val__) << 30u) & 0xc0000000u)

/** @brief Register definition for @ref GEN_t.GenCfgShared. */
typedef register_container RegGENGenCfgShared_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_GEN_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PortSwap, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, ASPMDebounce, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, FiberWoLCapable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, DisablePowerSaving, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_6_4, 4, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_8_8, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_10_9, 9, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_14_11, 11, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_15_15, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_21_16, 16, 6)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, LinkFlapAvoid, 22, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, _1GonVAUXOK, 23, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_25_24, 24, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_27_26, 26, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_29_28, 28, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_31_30, 30, 2)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_31_30, 30, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_29_28, 28, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_27_26, 26, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_25_24, 24, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, _1GonVAUXOK, 23, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, LinkFlapAvoid, 22, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_21_16, 16, 6)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_15_15, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_14_11, 11, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_10_9, 9, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_8_8, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_7_7, 7, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_6_4, 4, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, DisablePowerSaving, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, FiberWoLCapable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, ASPMDebounce, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, PortSwap, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_GEN_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenCfgShared"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenCfgShared_t()
    {
        /** @brief constructor for @ref GEN_t.GenCfgShared. */
        r32.setName("GenCfgShared");
        bits.PortSwap.setBaseRegister(&r32);
        bits.PortSwap.setName("PortSwap");
        bits.ASPMDebounce.setBaseRegister(&r32);
        bits.ASPMDebounce.setName("ASPMDebounce");
        bits.FiberWoLCapable.setBaseRegister(&r32);
        bits.FiberWoLCapable.setName("FiberWoLCapable");
        bits.DisablePowerSaving.setBaseRegister(&r32);
        bits.DisablePowerSaving.setName("DisablePowerSaving");
        bits.unknown_7_7.setBaseRegister(&r32);
        bits.unknown_7_7.setName("unknown_7_7");
        bits.unknown_8_8.setBaseRegister(&r32);
        bits.unknown_8_8.setName("unknown_8_8");
        bits.unknown_10_9.setBaseRegister(&r32);
        bits.unknown_10_9.setName("unknown_10_9");
        bits.unknown_15_15.setBaseRegister(&r32);
        bits.unknown_15_15.setName("unknown_15_15");
        bits.LinkFlapAvoid.setBaseRegister(&r32);
        bits.LinkFlapAvoid.setName("LinkFlapAvoid");
        bits._1GonVAUXOK.setBaseRegister(&r32);
        bits._1GonVAUXOK.setName("_1GonVAUXOK");
        bits.unknown_27_26.setBaseRegister(&r32);
        bits.unknown_27_26.setName("unknown_27_26");
        bits.unknown_29_28.setBaseRegister(&r32);
        bits.unknown_29_28.setName("unknown_29_28");
        bits.unknown_31_30.setBaseRegister(&r32);
        bits.unknown_31_30.setName("unknown_31_30");
    }
    RegGENGenCfgShared_t& operator=(const RegGENGenCfgShared_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenCfgShared_t;

#define REG_GEN_GEN_FW_VERSION ((volatile BCM5719_GEN_H_uint32_t*)0xd64) /* Set from NVM 0x096; firmware version and upper 16 bits of manufacturing date. */
/** @brief Register definition for @ref GEN_t.GenFwVersion. */
typedef register_container RegGENGenFwVersion_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenFwVersion"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenFwVersion_t()
    {
        /** @brief constructor for @ref GEN_t.GenFwVersion. */
        r32.setName("GenFwVersion");
    }
    RegGENGenFwVersion_t& operator=(const RegGENGenFwVersion_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenFwVersion_t;

#define REG_GEN_GEN_CFG_HW_2 ((volatile BCM5719_GEN_H_uint32_t*)0xdf8) /*  */
#define     GEN_GEN_CFG_HW_2_ENABLE_AUTONEGOTIATION_SHIFT 0u
#define     GEN_GEN_CFG_HW_2_ENABLE_AUTONEGOTIATION_MASK  0x1u
#define GET_GEN_GEN_CFG_HW_2_ENABLE_AUTONEGOTIATION(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_GEN_GEN_CFG_HW_2_ENABLE_AUTONEGOTIATION(__val__)  (((__val__) << 0u) & 0x1u)
#define     GEN_GEN_CFG_HW_2_EXPANSION_ROM_ENABLE_SHIFT 1u
#define     GEN_GEN_CFG_HW_2_EXPANSION_ROM_ENABLE_MASK  0x2u
#define GET_GEN_GEN_CFG_HW_2_EXPANSION_ROM_ENABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_GEN_GEN_CFG_HW_2_EXPANSION_ROM_ENABLE(__val__)  (((__val__) << 1u) & 0x2u)
#define     GEN_GEN_CFG_HW_2_UNKNOWN_2_2_SHIFT 2u
#define     GEN_GEN_CFG_HW_2_UNKNOWN_2_2_MASK  0x4u
#define GET_GEN_GEN_CFG_HW_2_UNKNOWN_2_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_GEN_GEN_CFG_HW_2_UNKNOWN_2_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_13_10_SHIFT 4u
#define     GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_13_10_MASK  0x30u
#define GET_GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_13_10(__reg__)  (((__reg__) & 0x30) >> 4u)
#define SET_GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_13_10(__val__)  (((__val__) << 4u) & 0x30u)
#define     GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_13_12_SHIFT 6u
#define     GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_13_12_MASK  0xc0u
#define GET_GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_13_12(__reg__)  (((__reg__) & 0xc0) >> 6u)
#define SET_GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_13_12(__val__)  (((__val__) << 6u) & 0xc0u)
#define     GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_10_10__01_SHIFT 21u
#define     GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_10_10__01_MASK  0x200000u
#define GET_GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_10_10__01(__reg__)  (((__reg__) & 0x200000) >> 21u)
#define SET_GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_10_10__01(__val__)  (((__val__) << 21u) & 0x200000u)
#define     GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_10_10__10_SHIFT 22u
#define     GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_10_10__10_MASK  0x400000u
#define GET_GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_10_10__10(__reg__)  (((__reg__) & 0x400000) >> 22u)
#define SET_GEN_GEN_CFG_HW_2_UNKNOWN_SERDES_10_10__10(__val__)  (((__val__) << 22u) & 0x400000u)

/** @brief Register definition for @ref GEN_t.GenCfgHw2. */
typedef register_container RegGENGenCfgHw2_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_GEN_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, EnableAutonegotiation, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, ExpansionROMEnable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_2_2, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, UnknownSERDES1310, 4, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, UnknownSERDES1312, 6, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_20_8, 8, 13)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, UnknownSERDES1010_01, 21, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, UnknownSERDES1010_10, 22, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_31_23, 23, 9)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_31_23, 23, 9)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, UnknownSERDES1010_10, 22, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, UnknownSERDES1010_01, 21, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_20_8, 8, 13)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, UnknownSERDES1312, 6, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, UnknownSERDES1310, 4, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_2_2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, ExpansionROMEnable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, EnableAutonegotiation, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_GEN_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenCfgHw2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenCfgHw2_t()
    {
        /** @brief constructor for @ref GEN_t.GenCfgHw2. */
        r32.setName("GenCfgHw2");
        bits.EnableAutonegotiation.setBaseRegister(&r32);
        bits.EnableAutonegotiation.setName("EnableAutonegotiation");
        bits.ExpansionROMEnable.setBaseRegister(&r32);
        bits.ExpansionROMEnable.setName("ExpansionROMEnable");
        bits.unknown_2_2.setBaseRegister(&r32);
        bits.unknown_2_2.setName("unknown_2_2");
        bits.UnknownSERDES1310.setBaseRegister(&r32);
        bits.UnknownSERDES1310.setName("UnknownSERDES1310");
        bits.UnknownSERDES1312.setBaseRegister(&r32);
        bits.UnknownSERDES1312.setName("UnknownSERDES1312");
        bits.UnknownSERDES1010_01.setBaseRegister(&r32);
        bits.UnknownSERDES1010_01.setName("UnknownSERDES1010_01");
        bits.UnknownSERDES1010_10.setBaseRegister(&r32);
        bits.UnknownSERDES1010_10.setName("UnknownSERDES1010_10");
    }
    RegGENGenCfgHw2_t& operator=(const RegGENGenCfgHw2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenCfgHw2_t;

#define REG_GEN_GEN_CPMU_STATUS ((volatile BCM5719_GEN_H_uint32_t*)0xe00) /* The upper 16 bits of this is the upper 16 bits of  */
/** @brief Register definition for @ref GEN_t.GenCpmuStatus. */
typedef register_container RegGENGenCpmuStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenCpmuStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenCpmuStatus_t()
    {
        /** @brief constructor for @ref GEN_t.GenCpmuStatus. */
        r32.setName("GenCpmuStatus");
    }
    RegGENGenCpmuStatus_t& operator=(const RegGENGenCpmuStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenCpmuStatus_t;

#define REG_GEN_GEN_CFG_5 ((volatile BCM5719_GEN_H_uint32_t*)0xe0c) /* Set from NVM 0x21C. */
#define     GEN_GEN_CFG_5_UNKNOWN_0_0_SHIFT 0u
#define     GEN_GEN_CFG_5_UNKNOWN_0_0_MASK  0x1u
#define GET_GEN_GEN_CFG_5_UNKNOWN_0_0(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_GEN_GEN_CFG_5_UNKNOWN_0_0(__val__)  (((__val__) << 0u) & 0x1u)
#define     GEN_GEN_CFG_5_DISABLE_1G_HALF_ADV_SHIFT 1u
#define     GEN_GEN_CFG_5_DISABLE_1G_HALF_ADV_MASK  0x2u
#define GET_GEN_GEN_CFG_5_DISABLE_1G_HALF_ADV(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_GEN_GEN_CFG_5_DISABLE_1G_HALF_ADV(__val__)  (((__val__) << 1u) & 0x2u)
#define     GEN_GEN_CFG_5_UNKNOWN_3_2_SHIFT 2u
#define     GEN_GEN_CFG_5_UNKNOWN_3_2_MASK  0xcu
#define GET_GEN_GEN_CFG_5_UNKNOWN_3_2(__reg__)  (((__reg__) & 0xc) >> 2u)
#define SET_GEN_GEN_CFG_5_UNKNOWN_3_2(__val__)  (((__val__) << 2u) & 0xcu)

/** @brief Register definition for @ref GEN_t.GenCfg5. */
typedef register_container RegGENGenCfg5_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_GEN_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_0_0, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, Disable1GHalfAdv, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_3_2, 2, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_31_4, 4, 28)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_31_4, 4, 28)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_3_2, 2, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, Disable1GHalfAdv, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, unknown_0_0, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_GEN_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenCfg5"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenCfg5_t()
    {
        /** @brief constructor for @ref GEN_t.GenCfg5. */
        r32.setName("GenCfg5");
        bits.unknown_0_0.setBaseRegister(&r32);
        bits.unknown_0_0.setName("unknown_0_0");
        bits.Disable1GHalfAdv.setBaseRegister(&r32);
        bits.Disable1GHalfAdv.setName("Disable1GHalfAdv");
        bits.unknown_3_2.setBaseRegister(&r32);
        bits.unknown_3_2.setName("unknown_3_2");
    }
    RegGENGenCfg5_t& operator=(const RegGENGenCfg5_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenCfg5_t;

#define REG_GEN_GEN_DBG_CONTROL_STATUS ((volatile BCM5719_GEN_H_uint32_t*)0xeb0) /* Firmware Debug Control */
#define     GEN_GEN_DBG_CONTROL_STATUS_DEBUG_ENABLED_SHIFT 0u
#define     GEN_GEN_DBG_CONTROL_STATUS_DEBUG_ENABLED_MASK  0x1u
#define GET_GEN_GEN_DBG_CONTROL_STATUS_DEBUG_ENABLED(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_GEN_GEN_DBG_CONTROL_STATUS_DEBUG_ENABLED(__val__)  (((__val__) << 0u) & 0x1u)
#define     GEN_GEN_DBG_CONTROL_STATUS_DATA_AVAILABLE_SHIFT 8u
#define     GEN_GEN_DBG_CONTROL_STATUS_DATA_AVAILABLE_MASK  0x100u
#define GET_GEN_GEN_DBG_CONTROL_STATUS_DATA_AVAILABLE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_GEN_GEN_DBG_CONTROL_STATUS_DATA_AVAILABLE(__val__)  (((__val__) << 8u) & 0x100u)

/** @brief Register definition for @ref GEN_t.GenDbgControlStatus. */
typedef register_container RegGENGenDbgControlStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_GEN_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, DebugEnabled, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_7_1, 1, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, DataAvailable, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_31_9, 9, 23)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_31_9, 9, 23)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, DataAvailable, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_7_1, 1, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, DebugEnabled, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_GEN_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenDbgControlStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenDbgControlStatus_t()
    {
        /** @brief constructor for @ref GEN_t.GenDbgControlStatus. */
        r32.setName("GenDbgControlStatus");
        bits.DebugEnabled.setBaseRegister(&r32);
        bits.DebugEnabled.setName("DebugEnabled");
        bits.DataAvailable.setBaseRegister(&r32);
        bits.DataAvailable.setName("DataAvailable");
    }
    RegGENGenDbgControlStatus_t& operator=(const RegGENGenDbgControlStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenDbgControlStatus_t;

#define REG_GEN_GEN_DBG_DATA ((volatile BCM5719_GEN_H_uint32_t*)0xeb4) /* Firmware Debug Data */
#define     GEN_GEN_DBG_DATA_DEBUG_BYTE_SHIFT 0u
#define     GEN_GEN_DBG_DATA_DEBUG_BYTE_MASK  0xffu
#define GET_GEN_GEN_DBG_DATA_DEBUG_BYTE(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_GEN_GEN_DBG_DATA_DEBUG_BYTE(__val__)  (((__val__) << 0u) & 0xffu)

/** @brief Register definition for @ref GEN_t.GenDbgData. */
typedef register_container RegGENGenDbgData_t {
    /** @brief 32bit direct register access. */
    BCM5719_GEN_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_GEN_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, DebugByte, 0, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_31_8, 8, 24)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, reserved_31_8, 8, 24)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_GEN_H_uint32_t, DebugByte, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_GEN_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GenDbgData"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegGENGenDbgData_t()
    {
        /** @brief constructor for @ref GEN_t.GenDbgData. */
        r32.setName("GenDbgData");
        bits.DebugByte.setBaseRegister(&r32);
        bits.DebugByte.setName("DebugByte");
    }
    RegGENGenDbgData_t& operator=(const RegGENGenDbgData_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegGENGenDbgData_t;

/** @brief Component definition for @ref GEN. */
typedef struct GEN_t {
    /** @brief  */
    RegGENGenFwMbox_t GenFwMbox;

    /** @brief  */
    RegGENGenDataSig_t GenDataSig;

    /** @brief TODO. */
    RegGENGenCfg_t GenCfg;

    /** @brief Unusual 16-bit field. */
    RegGENGenVersion_t GenVersion;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_GEN_H_uint32_t reserved_16[5];

    /** @brief Can be 0x5A5A_5A5A to indicate that this field is invalid; otherwise,       it is set to the MII PHY ID value. */
    RegGENGenPhyId_t GenPhyId;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_GEN_H_uint32_t reserved_40[34];

    /** @brief Sometimes set to BOOTCODE_READY_MAGIC. */
    RegGENGenAsfStatusMbox_t GenAsfStatusMbox;

    /** @brief  */
    RegGENGenFwDriverStateMbox_t GenFwDriverStateMbox;

    /** @brief TODO */
    RegGENGenFwResetTypeMbox_t GenFwResetTypeMbox;

    /** @brief Set to 0xFEFE_0009 at S2 start. Possibly boot progress indicator.       Upper 16 is always 0xFEFE, possible validity indicator. Observed        lower16 values:     8       9 - Stage2 start */
    RegGENGenBc_t GenBc;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_GEN_H_uint32_t reserved_192[1];

    /** @brief  */
    RegGENGenMacAddrHighMbox_t GenMacAddrHighMbox;

    /** @brief  */
    RegGENGenMacAddrLowMbox_t GenMacAddrLowMbox;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_GEN_H_uint32_t reserved_204[3];

    /** @brief Field names are guessed. */
    RegGENGenD8_t GenD8;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_GEN_H_uint32_t reserved_220[64];

    /** @brief Unknown. Some information from  */
    RegGENGen1dc_t Gen1dc;

    /** @brief Register manual states "recommended value" is 0x474C_0000. */
    RegGENGenWolMbox_t GenWolMbox;

    /** @brief  */
    RegGENGenCfgFeature_t GenCfgFeature;

    /** @brief Set from NVM. */
    RegGENGenCfgHw_t GenCfgHw;

    /** @brief Set from NVM. */
    RegGENGenCfgShared_t GenCfgShared;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_GEN_H_uint32_t reserved_496[9];

    /** @brief Set from NVM 0x096; firmware version and upper 16 bits of manufacturing date. */
    RegGENGenFwVersion_t GenFwVersion;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_GEN_H_uint32_t reserved_536[36];

    /** @brief  */
    RegGENGenCfgHw2_t GenCfgHw2;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_GEN_H_uint32_t reserved_684[1];

    /** @brief The upper 16 bits of this is the upper 16 bits of  */
    RegGENGenCpmuStatus_t GenCpmuStatus;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_GEN_H_uint32_t reserved_692[2];

    /** @brief Set from NVM 0x21C. */
    RegGENGenCfg5_t GenCfg5;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_GEN_H_uint32_t reserved_704[40];

    /** @brief Firmware Debug Control */
    RegGENGenDbgControlStatus_t GenDbgControlStatus;

    /** @brief Firmware Debug Data */
    RegGENGenDbgData_t GenDbgData;

#ifdef CXX_SIMULATOR
    GEN_t()
    {
        GenFwMbox.r32.setComponentOffset(0x0);
        GenDataSig.r32.setComponentOffset(0x4);
        GenCfg.r32.setComponentOffset(0x8);
        GenVersion.r32.setComponentOffset(0xc);
        GenPhyId.r32.setComponentOffset(0x24);
        GenAsfStatusMbox.r32.setComponentOffset(0xb0);
        GenFwDriverStateMbox.r32.setComponentOffset(0xb4);
        GenFwResetTypeMbox.r32.setComponentOffset(0xb8);
        GenBc.r32.setComponentOffset(0xbc);
        GenMacAddrHighMbox.r32.setComponentOffset(0xc4);
        GenMacAddrLowMbox.r32.setComponentOffset(0xc8);
        GenD8.r32.setComponentOffset(0xd8);
        Gen1dc.r32.setComponentOffset(0x1dc);
        GenWolMbox.r32.setComponentOffset(0x1e0);
        GenCfgFeature.r32.setComponentOffset(0x1e4);
        GenCfgHw.r32.setComponentOffset(0x1e8);
        GenCfgShared.r32.setComponentOffset(0x1ec);
        GenFwVersion.r32.setComponentOffset(0x214);
        GenCfgHw2.r32.setComponentOffset(0x2a8);
        GenCpmuStatus.r32.setComponentOffset(0x2b0);
        GenCfg5.r32.setComponentOffset(0x2bc);
        GenDbgControlStatus.r32.setComponentOffset(0x360);
        GenDbgData.r32.setComponentOffset(0x364);
    }
    void print()
    {
        GenFwMbox.print();
        GenDataSig.print();
        GenCfg.print();
        GenVersion.print();
        for(int i = 0; i < 5; i++)
        {
            reserved_16[i].print();
        }
        GenPhyId.print();
        for(int i = 0; i < 34; i++)
        {
            reserved_40[i].print();
        }
        GenAsfStatusMbox.print();
        GenFwDriverStateMbox.print();
        GenFwResetTypeMbox.print();
        GenBc.print();
        for(int i = 0; i < 1; i++)
        {
            reserved_192[i].print();
        }
        GenMacAddrHighMbox.print();
        GenMacAddrLowMbox.print();
        for(int i = 0; i < 3; i++)
        {
            reserved_204[i].print();
        }
        GenD8.print();
        for(int i = 0; i < 64; i++)
        {
            reserved_220[i].print();
        }
        Gen1dc.print();
        GenWolMbox.print();
        GenCfgFeature.print();
        GenCfgHw.print();
        GenCfgShared.print();
        for(int i = 0; i < 9; i++)
        {
            reserved_496[i].print();
        }
        GenFwVersion.print();
        for(int i = 0; i < 36; i++)
        {
            reserved_536[i].print();
        }
        GenCfgHw2.print();
        for(int i = 0; i < 1; i++)
        {
            reserved_684[i].print();
        }
        GenCpmuStatus.print();
        for(int i = 0; i < 2; i++)
        {
            reserved_692[i].print();
        }
        GenCfg5.print();
        for(int i = 0; i < 40; i++)
        {
            reserved_704[i].print();
        }
        GenDbgControlStatus.print();
        GenDbgData.print();
    }
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
} GEN_t;

/** @brief General Communication */
extern volatile GEN_t GEN;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !BCM5719_GEN_H */

/** @} */
