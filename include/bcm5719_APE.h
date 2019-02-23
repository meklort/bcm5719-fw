////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_APE.h
///
/// @project    bcm5719
///
/// @brief      bcm5719_APE
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

/** @defgroup BCM5719_APE_H    bcm5719_APE */
/** @addtogroup BCM5719_APE_H
 * @{
 */
#ifndef BCM5719_APE_H
#define BCM5719_APE_H

#include <stdint.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_bcm5719_APE_mmap(void* base);
void init_bcm5719_APE(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> BCM5719_APE_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> BCM5719_APE_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> BCM5719_APE_H_uint32_t;
#define BCM5719_APE_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define BCM5719_APE_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define BCM5719_APE_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  BCM5719_APE_H_uint8_t;
typedef uint16_t BCM5719_APE_H_uint16_t;
typedef uint32_t BCM5719_APE_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_APE_BASE ((volatile void*)0xc0010000) /* Device APE Registers */
#define REG_APE_SIZE (sizeof(APE_t))

#define REG_APE_MODE ((volatile BCM5719_APE_H_uint32_t*)0xc0010000) /* More of these bits can be found in diagnostic utilities, but they don't seem too interesting. */
#define     APE_MODE_RESET_SHIFT 0u
#define     APE_MODE_RESET_MASK  0x1u
#define GET_APE_MODE_RESET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_MODE_RESET(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_MODE_HALT_SHIFT 1u
#define     APE_MODE_HALT_MASK  0x2u
#define GET_APE_MODE_HALT(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_MODE_HALT(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_MODE_FAST_BOOT_SHIFT 2u
#define     APE_MODE_FAST_BOOT_MASK  0x4u
#define GET_APE_MODE_FAST_BOOT(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_MODE_FAST_BOOT(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_MODE_HOST_DIAG_SHIFT 3u
#define     APE_MODE_HOST_DIAG_MASK  0x8u
#define GET_APE_MODE_HOST_DIAG(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_MODE_HOST_DIAG(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_MODE_MEMORY_ECC_SHIFT 18u
#define     APE_MODE_MEMORY_ECC_MASK  0x40000u
#define GET_APE_MODE_MEMORY_ECC(__reg__)  (((__reg__) & 0x40000) >> 18u)
#define SET_APE_MODE_MEMORY_ECC(__val__)  (((__val__) << 18u) & 0x40000u)

/** @brief Register definition for @ref APE_t.Mode. */
typedef register_container RegAPEMode_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Reset, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Halt, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, FastBoot, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, HostDiag, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_17_4, 4, 14)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, MemoryECC, 18, 1)
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Mode"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEMode_t()
    {
        /** @brief constructor for @ref APE_t.Mode. */
        r32.setName("Mode");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.FastBoot.setBaseRegister(&r32);
        bits.FastBoot.setName("FastBoot");
        bits.HostDiag.setBaseRegister(&r32);
        bits.HostDiag.setName("HostDiag");
        bits.MemoryECC.setBaseRegister(&r32);
        bits.MemoryECC.setName("MemoryECC");
    }
    RegAPEMode_t& operator=(const RegAPEMode_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEMode_t;

#define REG_APE_STATUS ((volatile BCM5719_APE_H_uint32_t*)0xc0010004) /*  */
#define     APE_STATUS_PCIE_RESET_SHIFT 0u
#define     APE_STATUS_PCIE_RESET_MASK  0x1u
#define GET_APE_STATUS_PCIE_RESET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_STATUS_PCIE_RESET(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_STATUS_LAN_0_DSTATE_SHIFT 4u
#define     APE_STATUS_LAN_0_DSTATE_MASK  0x10u
#define GET_APE_STATUS_LAN_0_DSTATE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_STATUS_LAN_0_DSTATE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_STATUS_BOOT_MODE_SHIFT 5u
#define     APE_STATUS_BOOT_MODE_MASK  0x20u
#define GET_APE_STATUS_BOOT_MODE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_STATUS_BOOT_MODE(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_STATUS_BOOT_MODE_NVRAM 0x0u
#define     APE_STATUS_BOOT_MODE_FAST 0x1u

#define     APE_STATUS_NVRAM_CONTROL_RESET_SHIFT 7u
#define     APE_STATUS_NVRAM_CONTROL_RESET_MASK  0x80u
#define GET_APE_STATUS_NVRAM_CONTROL_RESET(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_APE_STATUS_NVRAM_CONTROL_RESET(__val__)  (((__val__) << 7u) & 0x80u)
#define     APE_STATUS_LAN_1_DSTATE_SHIFT 9u
#define     APE_STATUS_LAN_1_DSTATE_MASK  0x200u
#define GET_APE_STATUS_LAN_1_DSTATE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_APE_STATUS_LAN_1_DSTATE(__val__)  (((__val__) << 9u) & 0x200u)
#define     APE_STATUS_BOOT_STATUS_B_SHIFT 24u
#define     APE_STATUS_BOOT_STATUS_B_MASK  0xf000000u
#define GET_APE_STATUS_BOOT_STATUS_B(__reg__)  (((__reg__) & 0xf000000) >> 24u)
#define SET_APE_STATUS_BOOT_STATUS_B(__val__)  (((__val__) << 24u) & 0xf000000u)
#define     APE_STATUS_BOOT_STATUS_B_PROG_0 0x0u
#define     APE_STATUS_BOOT_STATUS_B_PROG_1 0x1u
#define     APE_STATUS_BOOT_STATUS_B_BPC_ENTER 0x2u
#define     APE_STATUS_BOOT_STATUS_B_DECODE 0x3u
#define     APE_STATUS_BOOT_STATUS_B_READ_NVRAM_HEADER 0x4u
#define     APE_STATUS_BOOT_STATUS_B_READ_CODE 0x5u
#define     APE_STATUS_BOOT_STATUS_B_JUMP 0x6u
#define     APE_STATUS_BOOT_STATUS_B_PROG_7 0x7u
#define     APE_STATUS_BOOT_STATUS_B_BPC_SUCCESS 0x8u

#define     APE_STATUS_BOOT_STATUS_A_SHIFT 28u
#define     APE_STATUS_BOOT_STATUS_A_MASK  0xf0000000u
#define GET_APE_STATUS_BOOT_STATUS_A(__reg__)  (((__reg__) & 0xf0000000) >> 28u)
#define SET_APE_STATUS_BOOT_STATUS_A(__val__)  (((__val__) << 28u) & 0xf0000000u)
#define     APE_STATUS_BOOT_STATUS_A_NONE 0x0u
#define     APE_STATUS_BOOT_STATUS_A_NMI_EXCEPTION 0x1u
#define     APE_STATUS_BOOT_STATUS_A_FAULT_EXCEPTION 0x2u
#define     APE_STATUS_BOOT_STATUS_A_MEMORY_CHECK 0x3u
#define     APE_STATUS_BOOT_STATUS_A_UNKNOWN_4 0x4u
#define     APE_STATUS_BOOT_STATUS_A_ROMLOADER_DISABLED 0x5u
#define     APE_STATUS_BOOT_STATUS_A_MAGIC_NUMBER 0x6u
#define     APE_STATUS_BOOT_STATUS_A_APE_INIT_CODE 0x7u
#define     APE_STATUS_BOOT_STATUS_A_HEADER_CHECKSUM 0x8u
#define     APE_STATUS_BOOT_STATUS_A_APE_HEADER 0x9u
#define     APE_STATUS_BOOT_STATUS_A_IMAGE_CHECKSUM 0xau
#define     APE_STATUS_BOOT_STATUS_A_NVRAM_CHECKSUM 0xbu
#define     APE_STATUS_BOOT_STATUS_A_INVALID_TYPE 0xcu
#define     APE_STATUS_BOOT_STATUS_A_ROM_LOADER_CHECKSUM 0xdu
#define     APE_STATUS_BOOT_STATUS_A_INVALID_UNZIP_LEN 0xeu
#define     APE_STATUS_BOOT_STATUS_A_UNKNOWN_F 0xfu


/** @brief Register definition for @ref APE_t.Status. */
typedef register_container RegAPEStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PCIeReset, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_3_1, 1, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LAN0Dstate, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootMode, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_6_6, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, NVRAMControlReset, 7, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_8_8, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LAN1Dstate, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_23_10, 10, 14)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootStatusB, 24, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootStatusA, 28, 4)
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Status"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEStatus_t()
    {
        /** @brief constructor for @ref APE_t.Status. */
        r32.setName("Status");
        bits.PCIeReset.setBaseRegister(&r32);
        bits.PCIeReset.setName("PCIeReset");
        bits.LAN0Dstate.setBaseRegister(&r32);
        bits.LAN0Dstate.setName("LAN0Dstate");
        bits.BootMode.setBaseRegister(&r32);
        bits.BootMode.setName("BootMode");
        bits.NVRAMControlReset.setBaseRegister(&r32);
        bits.NVRAMControlReset.setName("NVRAMControlReset");
        bits.LAN1Dstate.setBaseRegister(&r32);
        bits.LAN1Dstate.setName("LAN1Dstate");
        bits.BootStatusB.setBaseRegister(&r32);
        bits.BootStatusB.setName("BootStatusB");
        bits.BootStatusA.setBaseRegister(&r32);
        bits.BootStatusA.setName("BootStatusA");
    }
    RegAPEStatus_t& operator=(const RegAPEStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEStatus_t;

#define REG_APE_GPIO_MESSAGE ((volatile BCM5719_APE_H_uint32_t*)0xc0010008) /*  */
/** @brief Register definition for @ref APE_t.GpioMessage. */
typedef register_container RegAPEGpioMessage_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEGpioMessage_t;

#define REG_APE_EVENT ((volatile BCM5719_APE_H_uint32_t*)0xc001000c) /*  */
#define     APE_EVENT_1_SHIFT 0u
#define     APE_EVENT_1_MASK  0x1u
#define GET_APE_EVENT_1(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_EVENT_1(__val__)  (((__val__) << 0u) & 0x1u)

/** @brief Register definition for @ref APE_t.Event. */
typedef register_container RegAPEEvent_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, _1, 0, 1)
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Event"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEEvent_t()
    {
        /** @brief constructor for @ref APE_t.Event. */
        r32.setName("Event");
        bits._1.setBaseRegister(&r32);
        bits._1.setName("_1");
    }
    RegAPEEvent_t& operator=(const RegAPEEvent_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEEvent_t;

#define REG_APE_MODE_2 ((volatile BCM5719_APE_H_uint32_t*)0xc001002c) /* Expansion for  */
/** @brief Register definition for @ref APE_t.Mode2. */
typedef register_container RegAPEMode2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEMode2_t;

#define REG_APE_STATUS_2 ((volatile BCM5719_APE_H_uint32_t*)0xc0010030) /*  */
/** @brief Register definition for @ref APE_t.Status2. */
typedef register_container RegAPEStatus2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEStatus2_t;

#define REG_APE_LOCK_GRANT__OBSOLETE_ ((volatile BCM5719_APE_H_uint32_t*)0xc001004c) /* See  */
/** @brief Register definition for @ref APE_t.LockGrantObsolete. */
typedef register_container RegAPELockGrantObsolete_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPELockGrantObsolete_t;

#define REG_APE_B0 ((volatile BCM5719_APE_H_uint32_t*)0xc00100b0) /* Unknown. */
/** @brief Register definition for @ref APE_t.B0. */
typedef register_container RegAPEB0_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEB0_t;

#define REG_APE_GPIO ((volatile BCM5719_APE_H_uint32_t*)0xc00100b8) /*  */
#define     APE_GPIO_PIN0_UNKNOWN_SHIFT 0u
#define     APE_GPIO_PIN0_UNKNOWN_MASK  0x1u
#define GET_APE_GPIO_PIN0_UNKNOWN(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_GPIO_PIN0_UNKNOWN(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_GPIO_PIN1_UNKNOWN_SHIFT 1u
#define     APE_GPIO_PIN1_UNKNOWN_MASK  0x2u
#define GET_APE_GPIO_PIN1_UNKNOWN(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_GPIO_PIN1_UNKNOWN(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_GPIO_PIN2_UNKNOWN_SHIFT 2u
#define     APE_GPIO_PIN2_UNKNOWN_MASK  0x4u
#define GET_APE_GPIO_PIN2_UNKNOWN(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_GPIO_PIN2_UNKNOWN(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_GPIO_PIN3_UNKNOWN_SHIFT 3u
#define     APE_GPIO_PIN3_UNKNOWN_MASK  0x8u
#define GET_APE_GPIO_PIN3_UNKNOWN(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_GPIO_PIN3_UNKNOWN(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_GPIO_PIN0_UNKNOWN_OUT_SHIFT 8u
#define     APE_GPIO_PIN0_UNKNOWN_OUT_MASK  0x100u
#define GET_APE_GPIO_PIN0_UNKNOWN_OUT(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_APE_GPIO_PIN0_UNKNOWN_OUT(__val__)  (((__val__) << 8u) & 0x100u)
#define     APE_GPIO_PIN1_UNKNOWN_OUT_SHIFT 9u
#define     APE_GPIO_PIN1_UNKNOWN_OUT_MASK  0x200u
#define GET_APE_GPIO_PIN1_UNKNOWN_OUT(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_APE_GPIO_PIN1_UNKNOWN_OUT(__val__)  (((__val__) << 9u) & 0x200u)
#define     APE_GPIO_PIN2_UNKNOWN_OUT_SHIFT 10u
#define     APE_GPIO_PIN2_UNKNOWN_OUT_MASK  0x400u
#define GET_APE_GPIO_PIN2_UNKNOWN_OUT(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_APE_GPIO_PIN2_UNKNOWN_OUT(__val__)  (((__val__) << 10u) & 0x400u)
#define     APE_GPIO_PIN3_UNKNOWN_OUT_SHIFT 11u
#define     APE_GPIO_PIN3_UNKNOWN_OUT_MASK  0x800u
#define GET_APE_GPIO_PIN3_UNKNOWN_OUT(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_APE_GPIO_PIN3_UNKNOWN_OUT(__val__)  (((__val__) << 11u) & 0x800u)
#define     APE_GPIO_PIN0_MODE_OUTPUT_SHIFT 16u
#define     APE_GPIO_PIN0_MODE_OUTPUT_MASK  0x10000u
#define GET_APE_GPIO_PIN0_MODE_OUTPUT(__reg__)  (((__reg__) & 0x10000) >> 16u)
#define SET_APE_GPIO_PIN0_MODE_OUTPUT(__val__)  (((__val__) << 16u) & 0x10000u)
#define     APE_GPIO_PIN1_MODE_OUTPUT_SHIFT 17u
#define     APE_GPIO_PIN1_MODE_OUTPUT_MASK  0x20000u
#define GET_APE_GPIO_PIN1_MODE_OUTPUT(__reg__)  (((__reg__) & 0x20000) >> 17u)
#define SET_APE_GPIO_PIN1_MODE_OUTPUT(__val__)  (((__val__) << 17u) & 0x20000u)
#define     APE_GPIO_PIN2_MODE_OUTPUT_SHIFT 18u
#define     APE_GPIO_PIN2_MODE_OUTPUT_MASK  0x40000u
#define GET_APE_GPIO_PIN2_MODE_OUTPUT(__reg__)  (((__reg__) & 0x40000) >> 18u)
#define SET_APE_GPIO_PIN2_MODE_OUTPUT(__val__)  (((__val__) << 18u) & 0x40000u)
#define     APE_GPIO_PIN3_MODE_OUTPUT_SHIFT 19u
#define     APE_GPIO_PIN3_MODE_OUTPUT_MASK  0x80000u
#define GET_APE_GPIO_PIN3_MODE_OUTPUT(__reg__)  (((__reg__) & 0x80000) >> 19u)
#define SET_APE_GPIO_PIN3_MODE_OUTPUT(__val__)  (((__val__) << 19u) & 0x80000u)

/** @brief Register definition for @ref APE_t.Gpio. */
typedef register_container RegAPEGpio_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN0Unknown, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN1Unknown, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN2Unknown, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN3Unknown, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_4, 4, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN0UnknownOut, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN1UnknownOut, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN2UnknownOut, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN3UnknownOut, 11, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_15_12, 12, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN0ModeOutput, 16, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN1ModeOutput, 17, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN2ModeOutput, 18, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN3ModeOutput, 19, 1)
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Gpio"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEGpio_t()
    {
        /** @brief constructor for @ref APE_t.Gpio. */
        r32.setName("Gpio");
        bits.PIN0Unknown.setBaseRegister(&r32);
        bits.PIN0Unknown.setName("PIN0Unknown");
        bits.PIN1Unknown.setBaseRegister(&r32);
        bits.PIN1Unknown.setName("PIN1Unknown");
        bits.PIN2Unknown.setBaseRegister(&r32);
        bits.PIN2Unknown.setName("PIN2Unknown");
        bits.PIN3Unknown.setBaseRegister(&r32);
        bits.PIN3Unknown.setName("PIN3Unknown");
        bits.PIN0UnknownOut.setBaseRegister(&r32);
        bits.PIN0UnknownOut.setName("PIN0UnknownOut");
        bits.PIN1UnknownOut.setBaseRegister(&r32);
        bits.PIN1UnknownOut.setName("PIN1UnknownOut");
        bits.PIN2UnknownOut.setBaseRegister(&r32);
        bits.PIN2UnknownOut.setName("PIN2UnknownOut");
        bits.PIN3UnknownOut.setBaseRegister(&r32);
        bits.PIN3UnknownOut.setName("PIN3UnknownOut");
        bits.PIN0ModeOutput.setBaseRegister(&r32);
        bits.PIN0ModeOutput.setName("PIN0ModeOutput");
        bits.PIN1ModeOutput.setBaseRegister(&r32);
        bits.PIN1ModeOutput.setName("PIN1ModeOutput");
        bits.PIN2ModeOutput.setBaseRegister(&r32);
        bits.PIN2ModeOutput.setName("PIN2ModeOutput");
        bits.PIN3ModeOutput.setBaseRegister(&r32);
        bits.PIN3ModeOutput.setName("PIN3ModeOutput");
    }
    RegAPEGpio_t& operator=(const RegAPEGpio_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEGpio_t;

#define REG_APE_GINT ((volatile BCM5719_APE_H_uint32_t*)0xc00100bc) /* TODO: See diag for field info. */
/** @brief Register definition for @ref APE_t.Gint. */
typedef register_container RegAPEGint_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEGint_t;

#define REG_APE_OTP_CONTROL ((volatile BCM5719_APE_H_uint32_t*)0xc00100e8) /*  */
#define     APE_OTP_CONTROL_START_SHIFT 0u
#define     APE_OTP_CONTROL_START_MASK  0x1u
#define GET_APE_OTP_CONTROL_START(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_OTP_CONTROL_START(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_OTP_CONTROL_PROG_ENABLE_SHIFT 21u
#define     APE_OTP_CONTROL_PROG_ENABLE_MASK  0x200000u
#define GET_APE_OTP_CONTROL_PROG_ENABLE(__reg__)  (((__reg__) & 0x200000) >> 21u)
#define SET_APE_OTP_CONTROL_PROG_ENABLE(__val__)  (((__val__) << 21u) & 0x200000u)

/** @brief Register definition for @ref APE_t.OtpControl. */
typedef register_container RegAPEOtpControl_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Start, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_20_1, 1, 20)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ProgEnable, 21, 1)
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "OtpControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEOtpControl_t()
    {
        /** @brief constructor for @ref APE_t.OtpControl. */
        r32.setName("OtpControl");
        bits.Start.setBaseRegister(&r32);
        bits.Start.setName("Start");
        bits.ProgEnable.setBaseRegister(&r32);
        bits.ProgEnable.setName("ProgEnable");
    }
    RegAPEOtpControl_t& operator=(const RegAPEOtpControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEOtpControl_t;

#define REG_APE_OTP_STATUS ((volatile BCM5719_APE_H_uint32_t*)0xc00100ec) /*  */
#define     APE_OTP_STATUS_COMMAND_DONE_SHIFT 0u
#define     APE_OTP_STATUS_COMMAND_DONE_MASK  0x1u
#define GET_APE_OTP_STATUS_COMMAND_DONE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_OTP_STATUS_COMMAND_DONE(__val__)  (((__val__) << 0u) & 0x1u)

/** @brief Register definition for @ref APE_t.OtpStatus. */
typedef register_container RegAPEOtpStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, CommandDone, 0, 1)
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "OtpStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEOtpStatus_t()
    {
        /** @brief constructor for @ref APE_t.OtpStatus. */
        r32.setName("OtpStatus");
        bits.CommandDone.setBaseRegister(&r32);
        bits.CommandDone.setName("CommandDone");
    }
    RegAPEOtpStatus_t& operator=(const RegAPEOtpStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEOtpStatus_t;

#define REG_APE_OTP_ADDR ((volatile BCM5719_APE_H_uint32_t*)0xc00100f0) /*  */
#define     APE_OTP_ADDR_ADDRESS_SHIFT 0u
#define     APE_OTP_ADDR_ADDRESS_MASK  0x7fffffffu
#define GET_APE_OTP_ADDR_ADDRESS(__reg__)  (((__reg__) & 0x7fffffff) >> 0u)
#define SET_APE_OTP_ADDR_ADDRESS(__val__)  (((__val__) << 0u) & 0x7fffffffu)
#define     APE_OTP_ADDR_CPU_ENABLE_SHIFT 31u
#define     APE_OTP_ADDR_CPU_ENABLE_MASK  0x80000000u
#define GET_APE_OTP_ADDR_CPU_ENABLE(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_APE_OTP_ADDR_CPU_ENABLE(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref APE_t.OtpAddr. */
typedef register_container RegAPEOtpAddr_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Address, 0, 31)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, CPUEnable, 31, 1)
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "OtpAddr"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEOtpAddr_t()
    {
        /** @brief constructor for @ref APE_t.OtpAddr. */
        r32.setName("OtpAddr");
        bits.Address.setBaseRegister(&r32);
        bits.Address.setName("Address");
        bits.CPUEnable.setBaseRegister(&r32);
        bits.CPUEnable.setName("CPUEnable");
    }
    RegAPEOtpAddr_t& operator=(const RegAPEOtpAddr_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEOtpAddr_t;

#define REG_APE_OTP_READ_DATA ((volatile BCM5719_APE_H_uint32_t*)0xc00100f8) /*  */
/** @brief Register definition for @ref APE_t.OtpReadData. */
typedef register_container RegAPEOtpReadData_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEOtpReadData_t;

#define REG_APE_CM3 ((volatile BCM5719_APE_H_uint32_t*)0xc0010108) /* Seems CPU control related. */
#define     APE_CM3_CPU_STATUS_SHIFT 0u
#define     APE_CM3_CPU_STATUS_MASK  0xfu
#define GET_APE_CM3_CPU_STATUS(__reg__)  (((__reg__) & 0xf) >> 0u)
#define SET_APE_CM3_CPU_STATUS(__val__)  (((__val__) << 0u) & 0xfu)
#define     APE_CM3_CPU_STATUS_RUNNING 0x0u
#define     APE_CM3_CPU_STATUS_HALTED 0x1u
#define     APE_CM3_CPU_STATUS_LOCKED_OUT 0x2u
#define     APE_CM3_CPU_STATUS_SLEEPING 0x3u
#define     APE_CM3_CPU_STATUS_DEEP_SLEEP 0x4u
#define     APE_CM3_CPU_STATUS_INTERRUPT_PENDING 0x8u
#define     APE_CM3_CPU_STATUS_INTERRUPT_ENTRY 0x9u
#define     APE_CM3_CPU_STATUS_INTERRUPT_EXIT 0xau
#define     APE_CM3_CPU_STATUS_INTERRUPT_RETURN 0xbu


/** @brief Register definition for @ref APE_t.Cm3. */
typedef register_container RegAPECm3_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, CPUStatus, 0, 4)
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Cm3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPECm3_t()
    {
        /** @brief constructor for @ref APE_t.Cm3. */
        r32.setName("Cm3");
        bits.CPUStatus.setBaseRegister(&r32);
        bits.CPUStatus.setName("CPUStatus");
    }
    RegAPECm3_t& operator=(const RegAPECm3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPECm3_t;

#define REG_APE_SEG_SIG ((volatile BCM5719_APE_H_uint32_t*)0xc0014000) /* APE_APE_MAGIC ('APE!') when all is well. */
/** @brief Register definition for @ref APE_t.SegSig. */
typedef register_container RegAPESegSig_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPESegSig_t;

#define REG_APE_FW_STATUS ((volatile BCM5719_APE_H_uint32_t*)0xc001400c) /*  */
#define     APE_FW_STATUS_READY_SHIFT 8u
#define     APE_FW_STATUS_READY_MASK  0x100u
#define GET_APE_FW_STATUS_READY(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_APE_FW_STATUS_READY(__val__)  (((__val__) << 8u) & 0x100u)
#define     APE_FW_STATUS_UNKNOWN_31_28_SHIFT 28u
#define     APE_FW_STATUS_UNKNOWN_31_28_MASK  0xf0000000u
#define GET_APE_FW_STATUS_UNKNOWN_31_28(__reg__)  (((__reg__) & 0xf0000000) >> 28u)
#define SET_APE_FW_STATUS_UNKNOWN_31_28(__val__)  (((__val__) << 28u) & 0xf0000000u)

/** @brief Register definition for @ref APE_t.FwStatus. */
typedef register_container RegAPEFwStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_0, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Ready, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_27_9, 9, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, unknown_31_28, 28, 4)
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "FwStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEFwStatus_t()
    {
        /** @brief constructor for @ref APE_t.FwStatus. */
        r32.setName("FwStatus");
        bits.Ready.setBaseRegister(&r32);
        bits.Ready.setName("Ready");
        bits.unknown_31_28.setBaseRegister(&r32);
        bits.unknown_31_28.setName("unknown_31_28");
    }
    RegAPEFwStatus_t& operator=(const RegAPEFwStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEFwStatus_t;

#define REG_APE_FW_FEATURES ((volatile BCM5719_APE_H_uint32_t*)0xc0014010) /*  */
#define     APE_FW_FEATURES_NCSI_SHIFT 1u
#define     APE_FW_FEATURES_NCSI_MASK  0x2u
#define GET_APE_FW_FEATURES_NCSI(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_FW_FEATURES_NCSI(__val__)  (((__val__) << 1u) & 0x2u)

/** @brief Register definition for @ref APE_t.FwFeatures. */
typedef register_container RegAPEFwFeatures_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_0_0, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, NCSI, 1, 1)
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "FwFeatures"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEFwFeatures_t()
    {
        /** @brief constructor for @ref APE_t.FwFeatures. */
        r32.setName("FwFeatures");
        bits.NCSI.setBaseRegister(&r32);
        bits.NCSI.setName("NCSI");
    }
    RegAPEFwFeatures_t& operator=(const RegAPEFwFeatures_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEFwFeatures_t;

#define REG_APE_4014 ((volatile BCM5719_APE_H_uint32_t*)0xc0014014) /* Unknown. */
/** @brief Register definition for @ref APE_t.4014. */
typedef register_container RegAPE4014_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPE4014_t;

#define REG_APE_FW_VERSION ((volatile BCM5719_APE_H_uint32_t*)0xc0014018) /*  */
#define     APE_FW_VERSION_BUILD_SHIFT 0u
#define     APE_FW_VERSION_BUILD_MASK  0xffu
#define GET_APE_FW_VERSION_BUILD(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_APE_FW_VERSION_BUILD(__val__)  (((__val__) << 0u) & 0xffu)
#define     APE_FW_VERSION_REVISION_SHIFT 8u
#define     APE_FW_VERSION_REVISION_MASK  0xff00u
#define GET_APE_FW_VERSION_REVISION(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_APE_FW_VERSION_REVISION(__val__)  (((__val__) << 8u) & 0xff00u)
#define     APE_FW_VERSION_MINOR_SHIFT 16u
#define     APE_FW_VERSION_MINOR_MASK  0xff0000u
#define GET_APE_FW_VERSION_MINOR(__reg__)  (((__reg__) & 0xff0000) >> 16u)
#define SET_APE_FW_VERSION_MINOR(__val__)  (((__val__) << 16u) & 0xff0000u)
#define     APE_FW_VERSION_MAJOR_SHIFT 24u
#define     APE_FW_VERSION_MAJOR_MASK  0xff000000u
#define GET_APE_FW_VERSION_MAJOR(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_APE_FW_VERSION_MAJOR(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref APE_t.FwVersion. */
typedef register_container RegAPEFwVersion_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Build, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Revision, 8, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Minor, 16, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Major, 24, 8)
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "FwVersion"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEFwVersion_t()
    {
        /** @brief constructor for @ref APE_t.FwVersion. */
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
    RegAPEFwVersion_t& operator=(const RegAPEFwVersion_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEFwVersion_t;

#define REG_APE_SEG_MESSAGE_BUFFER_OFFSET ((volatile BCM5719_APE_H_uint32_t*)0xc001401c) /* Specifies the offset of a scratchpad area, relative to the  start of the APE SHM area (i.e., relative to APE_REG(0x4000)). */
/** @brief Register definition for @ref APE_t.SegMessageBufferOffset. */
typedef register_container RegAPESegMessageBufferOffset_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPESegMessageBufferOffset_t;

#define REG_APE_SEG_MESSAGE_BUFFER_LENGTH ((volatile BCM5719_APE_H_uint32_t*)0xc0014020) /* Specifies the size of the scratchpad area in bytes. */
/** @brief Register definition for @ref APE_t.SegMessageBufferLength. */
typedef register_container RegAPESegMessageBufferLength_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPESegMessageBufferLength_t;

#define REG_APE_4024 ((volatile BCM5719_APE_H_uint32_t*)0xc0014024) /* Unknown. Bootcode related. */
/** @brief Register definition for @ref APE_t.4024. */
typedef register_container RegAPE4024_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPE4024_t;

#define REG_APE_4028 ((volatile BCM5719_APE_H_uint32_t*)0xc0014028) /* Unknown. Bootcode related. */
/** @brief Register definition for @ref APE_t.4028. */
typedef register_container RegAPE4028_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPE4028_t;

#define REG_APE_RCPU_SEG_SIG ((volatile BCM5719_APE_H_uint32_t*)0xc0014100) /* Set to APE_RCPU_MAGIC ('RCPU') by RX CPU. */
/** @brief Register definition for @ref APE_t.RcpuSegSig. */
typedef register_container RegAPERcpuSegSig_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPERcpuSegSig_t;

#define REG_APE_RCPU_SEG_LENGTH ((volatile BCM5719_APE_H_uint32_t*)0xc0014104) /* Set to 0x34. */
/** @brief Register definition for @ref APE_t.RcpuSegLength. */
typedef register_container RegAPERcpuSegLength_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPERcpuSegLength_t;

#define REG_APE_RCPU_INIT_COUNT ((volatile BCM5719_APE_H_uint32_t*)0xc0014108) /* Incremented by RX CPU every boot. */
/** @brief Register definition for @ref APE_t.RcpuInitCount. */
typedef register_container RegAPERcpuInitCount_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPERcpuInitCount_t;

#define REG_APE_RCPU_FW_VERSION ((volatile BCM5719_APE_H_uint32_t*)0xc001410c) /* Set to the bootcode version. e.g. 0x0127 -> v1.39. */
/** @brief Register definition for @ref APE_t.RcpuFwVersion. */
typedef register_container RegAPERcpuFwVersion_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPERcpuFwVersion_t;

#define REG_APE_RCPU_CFG_FEATURE ((volatile BCM5719_APE_H_uint32_t*)0xc0014110) /* Set to  */
/** @brief Register definition for @ref APE_t.RcpuCfgFeature. */
typedef register_container RegAPERcpuCfgFeature_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPERcpuCfgFeature_t;

#define REG_APE_RCPU_PCI_VENDOR_DEVICE_ID ((volatile BCM5719_APE_H_uint32_t*)0xc0014114) /* Set to PCI Vendor/Device ID by S2. */
/** @brief Register definition for @ref APE_t.RcpuPciVendorDeviceId. */
typedef register_container RegAPERcpuPciVendorDeviceId_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPERcpuPciVendorDeviceId_t;

#define REG_APE_RCPU_PCI_SUBSYSTEM_ID ((volatile BCM5719_APE_H_uint32_t*)0xc0014118) /* Set to PCI Subsystem Vendor/Subsystem ID by S2. */
/** @brief Register definition for @ref APE_t.RcpuPciSubsystemId. */
typedef register_container RegAPERcpuPciSubsystemId_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPERcpuPciSubsystemId_t;

#define REG_APE_411C ((volatile BCM5719_APE_H_uint32_t*)0xc001411c) /* Unknown. Incremented by frobnicating routine. */
/** @brief Register definition for @ref APE_t.411c. */
typedef register_container RegAPE411c_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPE411c_t;

#define REG_APE_4120 ((volatile BCM5719_APE_H_uint32_t*)0xc0014120) /* Unknown. Written by frobnicating routine. */
/** @brief Register definition for @ref APE_t.4120. */
typedef register_container RegAPE4120_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPE4120_t;

#define REG_APE_4124 ((volatile BCM5719_APE_H_uint32_t*)0xc0014124) /* Unknown.  */
/** @brief Register definition for @ref APE_t.4124. */
typedef register_container RegAPE4124_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPE4124_t;

#define REG_APE_RCPU_CFG_HW ((volatile BCM5719_APE_H_uint32_t*)0xc0014128) /* Set from  */
/** @brief Register definition for @ref APE_t.RcpuCfgHw. */
typedef register_container RegAPERcpuCfgHw_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPERcpuCfgHw_t;

#define REG_APE_RCPU_CFG_HW_2 ((volatile BCM5719_APE_H_uint32_t*)0xc001412c) /* Set from  */
/** @brief Register definition for @ref APE_t.RcpuCfgHw2. */
typedef register_container RegAPERcpuCfgHw2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPERcpuCfgHw2_t;

#define REG_APE_RCPU_CPMU_STATUS ((volatile BCM5719_APE_H_uint32_t*)0xc0014130) /* Set from  */
/** @brief Register definition for @ref APE_t.RcpuCpmuStatus. */
typedef register_container RegAPERcpuCpmuStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPERcpuCpmuStatus_t;

#define REG_APE_HOST_SEG_SIG ((volatile BCM5719_APE_H_uint32_t*)0xc0014200) /* Set to APE_HOST_MAGIC ('HOST') to indicate the section is valid. */
/** @brief Register definition for @ref APE_t.HostSegSig. */
typedef register_container RegAPEHostSegSig_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEHostSegSig_t;

#define REG_APE_HOST_SEG_LEN ((volatile BCM5719_APE_H_uint32_t*)0xc0014204) /* Set to 0x20. */
/** @brief Register definition for @ref APE_t.HostSegLen. */
typedef register_container RegAPEHostSegLen_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEHostSegLen_t;

#define REG_APE_HOST_INIT_COUNT ((volatile BCM5719_APE_H_uint32_t*)0xc0014208) /* Incremented by host on every initialization. */
/** @brief Register definition for @ref APE_t.HostInitCount. */
typedef register_container RegAPEHostInitCount_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEHostInitCount_t;

#define REG_APE_HOST_DRIVER_ID ((volatile BCM5719_APE_H_uint32_t*)0xc001420c) /* Linux sets this to 0xF0MM_mm00, where M is the major version  of Linux and m is the minor version. */
/** @brief Register definition for @ref APE_t.HostDriverId. */
typedef register_container RegAPEHostDriverId_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEHostDriverId_t;

#define REG_APE_HOST_BEHAVIOR ((volatile BCM5719_APE_H_uint32_t*)0xc0014210) /*  */
#define     APE_HOST_BEHAVIOR_NO_PHYLOCK_SHIFT 0u
#define     APE_HOST_BEHAVIOR_NO_PHYLOCK_MASK  0x1u
#define GET_APE_HOST_BEHAVIOR_NO_PHYLOCK(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_HOST_BEHAVIOR_NO_PHYLOCK(__val__)  (((__val__) << 0u) & 0x1u)

/** @brief Register definition for @ref APE_t.HostBehavior. */
typedef register_container RegAPEHostBehavior_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, NoPHYLock, 0, 1)
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HostBehavior"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEHostBehavior_t()
    {
        /** @brief constructor for @ref APE_t.HostBehavior. */
        r32.setName("HostBehavior");
        bits.NoPHYLock.setBaseRegister(&r32);
        bits.NoPHYLock.setName("NoPHYLock");
    }
    RegAPEHostBehavior_t& operator=(const RegAPEHostBehavior_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEHostBehavior_t;

#define REG_APE_HEARTBEAT_INTERVAL ((volatile BCM5719_APE_H_uint32_t*)0xc0014214) /* In milliseconds. Set to 0 to disable heartbeating. */
/** @brief Register definition for @ref APE_t.HeartbeatInterval. */
typedef register_container RegAPEHeartbeatInterval_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEHeartbeatInterval_t;

#define REG_APE_HEARTBEAT_COUNT ((volatile BCM5719_APE_H_uint32_t*)0xc0014218) /*  */
/** @brief Register definition for @ref APE_t.HeartbeatCount. */
typedef register_container RegAPEHeartbeatCount_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEHeartbeatCount_t;

#define REG_APE_HOST_DRIVER_STATE ((volatile BCM5719_APE_H_uint32_t*)0xc001421c) /*  */
/** @brief Register definition for @ref APE_t.HostDriverState. */
typedef register_container RegAPEHostDriverState_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEHostDriverState_t;

#define REG_APE_WOL_SPEED ((volatile BCM5719_APE_H_uint32_t*)0xc0014224) /*  */
/** @brief Register definition for @ref APE_t.WolSpeed. */
typedef register_container RegAPEWolSpeed_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEWolSpeed_t;

#define REG_APE_EVENT_STATUS ((volatile BCM5719_APE_H_uint32_t*)0xc0014300) /*  */
#define     APE_EVENT_STATUS_DRIVER_EVENT_SHIFT 4u
#define     APE_EVENT_STATUS_DRIVER_EVENT_MASK  0x10u
#define GET_APE_EVENT_STATUS_DRIVER_EVENT(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_EVENT_STATUS_DRIVER_EVENT(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_EVENT_STATUS_COMMAND_SHIFT 8u
#define     APE_EVENT_STATUS_COMMAND_MASK  0xff00u
#define GET_APE_EVENT_STATUS_COMMAND(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_APE_EVENT_STATUS_COMMAND(__val__)  (((__val__) << 8u) & 0xff00u)
#define     APE_EVENT_STATUS_COMMAND_STATE_CHANGE 0x5u
#define     APE_EVENT_STATUS_COMMAND_SCRATCHPAD_READ 0x16u
#define     APE_EVENT_STATUS_COMMAND_SCRATCHPAD_WRITE 0x17u

#define     APE_EVENT_STATUS_STATE_SHIFT 16u
#define     APE_EVENT_STATUS_STATE_MASK  0x70000u
#define GET_APE_EVENT_STATUS_STATE(__reg__)  (((__reg__) & 0x70000) >> 16u)
#define SET_APE_EVENT_STATUS_STATE(__val__)  (((__val__) << 16u) & 0x70000u)
#define     APE_EVENT_STATUS_STATE_START 0x1u
#define     APE_EVENT_STATUS_STATE_UNLOAD 0x2u
#define     APE_EVENT_STATUS_STATE_WOL 0x3u
#define     APE_EVENT_STATUS_STATE_SUSPEND 0x4u

#define     APE_EVENT_STATUS_PENDING_SHIFT 31u
#define     APE_EVENT_STATUS_PENDING_MASK  0x80000000u
#define GET_APE_EVENT_STATUS_PENDING(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_APE_EVENT_STATUS_PENDING(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref APE_t.EventStatus. */
typedef register_container RegAPEEventStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_3_0, 0, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, DriverEvent, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Command, 8, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, State, 16, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_30_19, 19, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Pending, 31, 1)
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "EventStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEEventStatus_t()
    {
        /** @brief constructor for @ref APE_t.EventStatus. */
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
    RegAPEEventStatus_t& operator=(const RegAPEEventStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEEventStatus_t;

#define REG_APE_PROT_MAGIC ((volatile BCM5719_APE_H_uint32_t*)0xc0014308) /* This is set to APE_PROT_MAGIC ('PROT') on all functions.  If it is 'PROT', the following fields (MAC0_HIGH/LOW) are valid */
/** @brief Register definition for @ref APE_t.ProtMagic. */
typedef register_container RegAPEProtMagic_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEProtMagic_t;

#define REG_APE_PROT_MAC0_HIGH ((volatile BCM5719_APE_H_uint32_t*)0xc0014314) /* High 16 bits of MAC address 0. Only valid if  */
/** @brief Register definition for @ref APE_t.ProtMac0High. */
typedef register_container RegAPEProtMac0High_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEProtMac0High_t;

#define REG_APE_PROT_MAC0_LOW ((volatile BCM5719_APE_H_uint32_t*)0xc0014318) /* Low 16 bits of MAC address 0. */
/** @brief Register definition for @ref APE_t.ProtMac0Low. */
typedef register_container RegAPEProtMac0Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEProtMac0Low_t;

#define REG_APE_NCSI_SIG ((volatile BCM5719_APE_H_uint32_t*)0xc0014800) /* Set to NCSI_MAGIC ('NCSI') by APE firmware. */
/** @brief Register definition for @ref APE_t.NcsiSig. */
typedef register_container RegAPENcsiSig_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiSig_t;

#define REG_APE_NCSI_BUILD_TIME ((volatile BCM5719_APE_H_uint32_t*)0xc0014810) /* ASCII string spanning three 32-bit words. Unused trailing bytes   are set to zero. */
/** @brief Register definition for @ref APE_t.NcsiBuildTime. */
typedef register_container RegAPENcsiBuildTime_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiBuildTime_t;

#define REG_APE_NCSI_BUILD_TIME_2 ((volatile BCM5719_APE_H_uint32_t*)0xc0014814) /*  */
/** @brief Register definition for @ref APE_t.NcsiBuildTime2. */
typedef register_container RegAPENcsiBuildTime2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiBuildTime2_t;

#define REG_APE_NCSI_BUILD_TIME_3 ((volatile BCM5719_APE_H_uint32_t*)0xc0014818) /*  */
/** @brief Register definition for @ref APE_t.NcsiBuildTime3. */
typedef register_container RegAPENcsiBuildTime3_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiBuildTime3_t;

#define REG_APE_NCSI_BUILD_DATE ((volatile BCM5719_APE_H_uint32_t*)0xc001481c) /* ASCII string spanning three 32-bit words. Unused trailing bytes   are set to zero. */
/** @brief Register definition for @ref APE_t.NcsiBuildDate. */
typedef register_container RegAPENcsiBuildDate_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiBuildDate_t;

#define REG_APE_NCSI_BUILD_DATE_2 ((volatile BCM5719_APE_H_uint32_t*)0xc0014820) /*  */
/** @brief Register definition for @ref APE_t.NcsiBuildDate2. */
typedef register_container RegAPENcsiBuildDate2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiBuildDate2_t;

#define REG_APE_NCSI_BUILD_DATE_3 ((volatile BCM5719_APE_H_uint32_t*)0xc0014824) /*  */
/** @brief Register definition for @ref APE_t.NcsiBuildDate3. */
typedef register_container RegAPENcsiBuildDate3_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiBuildDate3_t;

#define REG_APE_CHIP_ID ((volatile BCM5719_APE_H_uint32_t*)0xc0014890) /* The APE code copies the contents of  */
/** @brief Register definition for @ref APE_t.ChipId. */
typedef register_container RegAPEChipId_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEChipId_t;

#define REG_APE_PER_LOCK_REQUEST_PHY0 ((volatile BCM5719_APE_H_uint32_t*)0xc0018400) /* This register, and the following Per Lock Request registers work the   same. The tg3 driver uses 0x0000_1000 (APELOCK_PER_REQ_DRIVER)  for PHY ports (or always for function 0). */
/** @brief Register definition for @ref APE_t.PerLockRequestPhy0. */
typedef register_container RegAPEPerLockRequestPhy0_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockRequestPhy0_t;

#define REG_APE_PER_LOCK_REQUEST_GRC ((volatile BCM5719_APE_H_uint32_t*)0xc0018404) /*  */
/** @brief Register definition for @ref APE_t.PerLockRequestGrc. */
typedef register_container RegAPEPerLockRequestGrc_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockRequestGrc_t;

#define REG_APE_PER_LOCK_REQUEST_PHY1 ((volatile BCM5719_APE_H_uint32_t*)0xc0018408) /*  */
/** @brief Register definition for @ref APE_t.PerLockRequestPhy1. */
typedef register_container RegAPEPerLockRequestPhy1_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockRequestPhy1_t;

#define REG_APE_PER_LOCK_REQUEST_PHY2 ((volatile BCM5719_APE_H_uint32_t*)0xc001840c) /*  */
/** @brief Register definition for @ref APE_t.PerLockRequestPhy2. */
typedef register_container RegAPEPerLockRequestPhy2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockRequestPhy2_t;

#define REG_APE_PER_LOCK_REQUEST_MEM ((volatile BCM5719_APE_H_uint32_t*)0xc0018410) /*  */
/** @brief Register definition for @ref APE_t.PerLockRequestMem. */
typedef register_container RegAPEPerLockRequestMem_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockRequestMem_t;

#define REG_APE_PER_LOCK_REQUEST_PHY3 ((volatile BCM5719_APE_H_uint32_t*)0xc0018414) /*  */
/** @brief Register definition for @ref APE_t.PerLockRequestPhy3. */
typedef register_container RegAPEPerLockRequestPhy3_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockRequestPhy3_t;

#define REG_APE_PER_LOCK_REQUEST_PORT6 ((volatile BCM5719_APE_H_uint32_t*)0xc0018418) /*  */
/** @brief Register definition for @ref APE_t.PerLockRequestPort6. */
typedef register_container RegAPEPerLockRequestPort6_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockRequestPort6_t;

#define REG_APE_PER_LOCK_REQUEST_GPIO ((volatile BCM5719_APE_H_uint32_t*)0xc001841c) /*  */
/** @brief Register definition for @ref APE_t.PerLockRequestGpio. */
typedef register_container RegAPEPerLockRequestGpio_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockRequestGpio_t;

#define REG_APE_PER_LOCK_GRANT_PHY0 ((volatile BCM5719_APE_H_uint32_t*)0xc0018420) /*  */
/** @brief Register definition for @ref APE_t.PerLockGrantPhy0. */
typedef register_container RegAPEPerLockGrantPhy0_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockGrantPhy0_t;

#define REG_APE_PER_LOCK_GRANT_GRC ((volatile BCM5719_APE_H_uint32_t*)0xc0018424) /*  */
/** @brief Register definition for @ref APE_t.PerLockGrantGrc. */
typedef register_container RegAPEPerLockGrantGrc_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockGrantGrc_t;

#define REG_APE_PER_LOCK_GRANT_PHY1 ((volatile BCM5719_APE_H_uint32_t*)0xc0018428) /*  */
/** @brief Register definition for @ref APE_t.PerLockGrantPhy1. */
typedef register_container RegAPEPerLockGrantPhy1_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockGrantPhy1_t;

#define REG_APE_PER_LOCK_GRANT_PHY2 ((volatile BCM5719_APE_H_uint32_t*)0xc001842c) /*  */
/** @brief Register definition for @ref APE_t.PerLockGrantPhy2. */
typedef register_container RegAPEPerLockGrantPhy2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockGrantPhy2_t;

#define REG_APE_PER_LOCK_GRANT_MEM ((volatile BCM5719_APE_H_uint32_t*)0xc0018430) /*  */
/** @brief Register definition for @ref APE_t.PerLockGrantMem. */
typedef register_container RegAPEPerLockGrantMem_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockGrantMem_t;

#define REG_APE_PER_LOCK_GRANT_PHY3 ((volatile BCM5719_APE_H_uint32_t*)0xc0018434) /*  */
/** @brief Register definition for @ref APE_t.PerLockGrantPhy3. */
typedef register_container RegAPEPerLockGrantPhy3_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockGrantPhy3_t;

#define REG_APE_PER_LOCK_GRANT_PORT6 ((volatile BCM5719_APE_H_uint32_t*)0xc0018438) /*  */
/** @brief Register definition for @ref APE_t.PerLockGrantPort6. */
typedef register_container RegAPEPerLockGrantPort6_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockGrantPort6_t;

#define REG_APE_PER_LOCK_GRANT_GPIO ((volatile BCM5719_APE_H_uint32_t*)0xc001843c) /*  */
/** @brief Register definition for @ref APE_t.PerLockGrantGpio. */
typedef register_container RegAPEPerLockGrantGpio_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEPerLockGrantGpio_t;

/** @brief Component definition for @ref APE. */
typedef struct {
    /** @brief More of these bits can be found in diagnostic utilities, but they don't seem too interesting. */
    RegAPEMode_t Mode;

    /** @brief  */
    RegAPEStatus_t Status;

    /** @brief  */
    RegAPEGpioMessage_t GpioMessage;

    /** @brief  */
    RegAPEEvent_t Event;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_16[7];

    /** @brief Expansion for  */
    RegAPEMode2_t Mode2;

    /** @brief  */
    RegAPEStatus2_t Status2;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_52[6];

    /** @brief See  */
    RegAPELockGrantObsolete_t LockGrantObsolete;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_80[24];

    /** @brief Unknown. */
    RegAPEB0_t B0;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_180[1];

    /** @brief  */
    RegAPEGpio_t Gpio;

    /** @brief TODO: See diag for field info. */
    RegAPEGint_t Gint;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_192[10];

    /** @brief  */
    RegAPEOtpControl_t OtpControl;

    /** @brief  */
    RegAPEOtpStatus_t OtpStatus;

    /** @brief  */
    RegAPEOtpAddr_t OtpAddr;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_244[1];

    /** @brief  */
    RegAPEOtpReadData_t OtpReadData;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_252[3];

    /** @brief Seems CPU control related. */
    RegAPECm3_t Cm3;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_268[4029];

    /** @brief APE_APE_MAGIC ('APE!') when all is well. */
    RegAPESegSig_t SegSig;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_16388[2];

    /** @brief  */
    RegAPEFwStatus_t FwStatus;

    /** @brief  */
    RegAPEFwFeatures_t FwFeatures;

    /** @brief Unknown. */
    RegAPE4014_t _4014;

    /** @brief  */
    RegAPEFwVersion_t FwVersion;

    /** @brief Specifies the offset of a scratchpad area, relative to the  start of the APE SHM area (i.e., relative to APE_REG(0x4000)). */
    RegAPESegMessageBufferOffset_t SegMessageBufferOffset;

    /** @brief Specifies the size of the scratchpad area in bytes. */
    RegAPESegMessageBufferLength_t SegMessageBufferLength;

    /** @brief Unknown. Bootcode related. */
    RegAPE4024_t _4024;

    /** @brief Unknown. Bootcode related. */
    RegAPE4028_t _4028;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_16428[53];

    /** @brief Set to APE_RCPU_MAGIC ('RCPU') by RX CPU. */
    RegAPERcpuSegSig_t RcpuSegSig;

    /** @brief Set to 0x34. */
    RegAPERcpuSegLength_t RcpuSegLength;

    /** @brief Incremented by RX CPU every boot. */
    RegAPERcpuInitCount_t RcpuInitCount;

    /** @brief Set to the bootcode version. e.g. 0x0127 -> v1.39. */
    RegAPERcpuFwVersion_t RcpuFwVersion;

    /** @brief Set to  */
    RegAPERcpuCfgFeature_t RcpuCfgFeature;

    /** @brief Set to PCI Vendor/Device ID by S2. */
    RegAPERcpuPciVendorDeviceId_t RcpuPciVendorDeviceId;

    /** @brief Set to PCI Subsystem Vendor/Subsystem ID by S2. */
    RegAPERcpuPciSubsystemId_t RcpuPciSubsystemId;

    /** @brief Unknown. Incremented by frobnicating routine. */
    RegAPE411c_t _411c;

    /** @brief Unknown. Written by frobnicating routine. */
    RegAPE4120_t _4120;

    /** @brief Unknown.  */
    RegAPE4124_t _4124;

    /** @brief Set from  */
    RegAPERcpuCfgHw_t RcpuCfgHw;

    /** @brief Set from  */
    RegAPERcpuCfgHw2_t RcpuCfgHw2;

    /** @brief Set from  */
    RegAPERcpuCpmuStatus_t RcpuCpmuStatus;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_16692[51];

    /** @brief Set to APE_HOST_MAGIC ('HOST') to indicate the section is valid. */
    RegAPEHostSegSig_t HostSegSig;

    /** @brief Set to 0x20. */
    RegAPEHostSegLen_t HostSegLen;

    /** @brief Incremented by host on every initialization. */
    RegAPEHostInitCount_t HostInitCount;

    /** @brief Linux sets this to 0xF0MM_mm00, where M is the major version  of Linux and m is the minor version. */
    RegAPEHostDriverId_t HostDriverId;

    /** @brief  */
    RegAPEHostBehavior_t HostBehavior;

    /** @brief In milliseconds. Set to 0 to disable heartbeating. */
    RegAPEHeartbeatInterval_t HeartbeatInterval;

    /** @brief  */
    RegAPEHeartbeatCount_t HeartbeatCount;

    /** @brief  */
    RegAPEHostDriverState_t HostDriverState;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_16928[1];

    /** @brief  */
    RegAPEWolSpeed_t WolSpeed;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_16936[54];

    /** @brief  */
    RegAPEEventStatus_t EventStatus;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_17156[1];

    /** @brief This is set to APE_PROT_MAGIC ('PROT') on all functions.  If it is 'PROT', the following fields (MAC0_HIGH/LOW) are valid */
    RegAPEProtMagic_t ProtMagic;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_17164[2];

    /** @brief High 16 bits of MAC address 0. Only valid if  */
    RegAPEProtMac0High_t ProtMac0High;

    /** @brief Low 16 bits of MAC address 0. */
    RegAPEProtMac0Low_t ProtMac0Low;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_17180[313];

    /** @brief Set to NCSI_MAGIC ('NCSI') by APE firmware. */
    RegAPENcsiSig_t NcsiSig;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_18436[3];

    /** @brief ASCII string spanning three 32-bit words. Unused trailing bytes   are set to zero. */
    RegAPENcsiBuildTime_t NcsiBuildTime;

    /** @brief  */
    RegAPENcsiBuildTime2_t NcsiBuildTime2;

    /** @brief  */
    RegAPENcsiBuildTime3_t NcsiBuildTime3;

    /** @brief ASCII string spanning three 32-bit words. Unused trailing bytes   are set to zero. */
    RegAPENcsiBuildDate_t NcsiBuildDate;

    /** @brief  */
    RegAPENcsiBuildDate2_t NcsiBuildDate2;

    /** @brief  */
    RegAPENcsiBuildDate3_t NcsiBuildDate3;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_18472[26];

    /** @brief The APE code copies the contents of  */
    RegAPEChipId_t ChipId;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_18580[3803];

    /** @brief This register, and the following Per Lock Request registers work the   same. The tg3 driver uses 0x0000_1000 (APELOCK_PER_REQ_DRIVER)  for PHY ports (or always for function 0). */
    RegAPEPerLockRequestPhy0_t PerLockRequestPhy0;

    /** @brief  */
    RegAPEPerLockRequestGrc_t PerLockRequestGrc;

    /** @brief  */
    RegAPEPerLockRequestPhy1_t PerLockRequestPhy1;

    /** @brief  */
    RegAPEPerLockRequestPhy2_t PerLockRequestPhy2;

    /** @brief  */
    RegAPEPerLockRequestMem_t PerLockRequestMem;

    /** @brief  */
    RegAPEPerLockRequestPhy3_t PerLockRequestPhy3;

    /** @brief  */
    RegAPEPerLockRequestPort6_t PerLockRequestPort6;

    /** @brief  */
    RegAPEPerLockRequestGpio_t PerLockRequestGpio;

    /** @brief  */
    RegAPEPerLockGrantPhy0_t PerLockGrantPhy0;

    /** @brief  */
    RegAPEPerLockGrantGrc_t PerLockGrantGrc;

    /** @brief  */
    RegAPEPerLockGrantPhy1_t PerLockGrantPhy1;

    /** @brief  */
    RegAPEPerLockGrantPhy2_t PerLockGrantPhy2;

    /** @brief  */
    RegAPEPerLockGrantMem_t PerLockGrantMem;

    /** @brief  */
    RegAPEPerLockGrantPhy3_t PerLockGrantPhy3;

    /** @brief  */
    RegAPEPerLockGrantPort6_t PerLockGrantPort6;

    /** @brief  */
    RegAPEPerLockGrantGpio_t PerLockGrantGpio;

} APE_t;

/** @brief Device APE Registers */
extern volatile APE_t APE;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !BCM5719_APE_H */

/** @} */
