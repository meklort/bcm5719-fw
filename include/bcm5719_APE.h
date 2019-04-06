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
#define     APE_MODE_EVENT_1_SHIFT 5u
#define     APE_MODE_EVENT_1_MASK  0x20u
#define GET_APE_MODE_EVENT_1(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_MODE_EVENT_1(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_MODE_EVENT_2_SHIFT 6u
#define     APE_MODE_EVENT_2_MASK  0x40u
#define GET_APE_MODE_EVENT_2(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_MODE_EVENT_2(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_MODE_GRCINT_SHIFT 7u
#define     APE_MODE_GRCINT_MASK  0x80u
#define GET_APE_MODE_GRCINT(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_APE_MODE_GRCINT(__val__)  (((__val__) << 7u) & 0x80u)
#define     APE_MODE_MEMORY_ECC_SHIFT 18u
#define     APE_MODE_MEMORY_ECC_MASK  0x40000u
#define GET_APE_MODE_MEMORY_ECC(__reg__)  (((__reg__) & 0x40000) >> 18u)
#define SET_APE_MODE_MEMORY_ECC(__val__)  (((__val__) << 18u) & 0x40000u)

/** @brief Register definition for @ref APE_t.Mode. */
typedef register_container RegAPEMode_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Used to reset the APE block. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Reset, 0, 1)
        /** @brief APE is halted if set. Setting then unsetting this bit resets the APE to its reset vector, etc. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Halt, 1, 1)
        /** @brief Can be used to boot from RAM instead of NVM. Takes a full APE image with section headers, etc. so you still need to form a proper image. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, FastBoot, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, HostDiag, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_4_4, 4, 1)
        /** @brief Used to signal the APE that an event from the host is ready for processing in SHM. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Event1, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Event2, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, GRCint, 7, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_17_8, 8, 10)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, MemoryECC, 18, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_19, 19, 13)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_19, 19, 13)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, MemoryECC, 18, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_17_8, 8, 10)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, GRCint, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Event2, 6, 1)
        /** @brief Used to signal the APE that an event from the host is ready for processing in SHM. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Event1, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_4_4, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, HostDiag, 3, 1)
        /** @brief Can be used to boot from RAM instead of NVM. Takes a full APE image with section headers, etc. so you still need to form a proper image. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, FastBoot, 2, 1)
        /** @brief APE is halted if set. Setting then unsetting this bit resets the APE to its reset vector, etc. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Halt, 1, 1)
        /** @brief Used to reset the APE block. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Reset, 0, 1)
#else
#error Unknown Endian
#endif
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
        r32.setComponentOffset(0x0);
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.Reset.setComponentOffset(0x0);
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.Halt.setComponentOffset(0x0);
        bits.FastBoot.setBaseRegister(&r32);
        bits.FastBoot.setName("FastBoot");
        bits.FastBoot.setComponentOffset(0x0);
        bits.HostDiag.setBaseRegister(&r32);
        bits.HostDiag.setName("HostDiag");
        bits.HostDiag.setComponentOffset(0x0);
        bits.Event1.setBaseRegister(&r32);
        bits.Event1.setName("Event1");
        bits.Event1.setComponentOffset(0x0);
        bits.Event2.setBaseRegister(&r32);
        bits.Event2.setName("Event2");
        bits.Event2.setComponentOffset(0x0);
        bits.GRCint.setBaseRegister(&r32);
        bits.GRCint.setName("GRCint");
        bits.GRCint.setComponentOffset(0x0);
        bits.MemoryECC.setBaseRegister(&r32);
        bits.MemoryECC.setName("MemoryECC");
        bits.MemoryECC.setComponentOffset(0x0);
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
#define     APE_STATUS_NVRAM_CONTROL_RESET_SHIFT 3u
#define     APE_STATUS_NVRAM_CONTROL_RESET_MASK  0x8u
#define GET_APE_STATUS_NVRAM_CONTROL_RESET(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_STATUS_NVRAM_CONTROL_RESET(__val__)  (((__val__) << 3u) & 0x8u)
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
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PCIeReset, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_2_1, 1, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, NVRAMControlReset, 3, 1)
        /** @brief Indicates port is in D3 if set, otherwise the port is in D0-D2. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LAN0Dstate, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootMode, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_8_6, 6, 3)
        /** @brief Indicates port is in D3 if set, otherwise the port is in D0-D2. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LAN1Dstate, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_23_10, 10, 14)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootStatusB, 24, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootStatusA, 28, 4)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootStatusA, 28, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootStatusB, 24, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_23_10, 10, 14)
        /** @brief Indicates port is in D3 if set, otherwise the port is in D0-D2. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LAN1Dstate, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_8_6, 6, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BootMode, 5, 1)
        /** @brief Indicates port is in D3 if set, otherwise the port is in D0-D2. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LAN0Dstate, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, NVRAMControlReset, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_2_1, 1, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PCIeReset, 0, 1)
#else
#error Unknown Endian
#endif
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
        r32.setComponentOffset(0x4);
        bits.PCIeReset.setBaseRegister(&r32);
        bits.PCIeReset.setName("PCIeReset");
        bits.PCIeReset.setComponentOffset(0x4);
        bits.NVRAMControlReset.setBaseRegister(&r32);
        bits.NVRAMControlReset.setName("NVRAMControlReset");
        bits.NVRAMControlReset.setComponentOffset(0x4);
        bits.LAN0Dstate.setBaseRegister(&r32);
        bits.LAN0Dstate.setName("LAN0Dstate");
        bits.LAN0Dstate.setComponentOffset(0x4);
        bits.BootMode.setBaseRegister(&r32);
        bits.BootMode.setName("BootMode");
        bits.BootMode.setComponentOffset(0x4);
        bits.LAN1Dstate.setBaseRegister(&r32);
        bits.LAN1Dstate.setName("LAN1Dstate");
        bits.LAN1Dstate.setComponentOffset(0x4);
        bits.BootStatusB.setBaseRegister(&r32);
        bits.BootStatusB.setName("BootStatusB");
        bits.BootStatusB.setComponentOffset(0x4);
        bits.BootStatusA.setBaseRegister(&r32);
        bits.BootStatusA.setName("BootStatusA");
        bits.BootStatusA.setComponentOffset(0x4);
    }
    RegAPEStatus_t& operator=(const RegAPEStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEStatus_t;

#define REG_APE_GPIO_MESSAGE ((volatile BCM5719_APE_H_uint32_t*)0xc0010008) /* Related to APE fastboot. In that case the value of it is an APE memory address in the code region. If Fast Boot is set, and the low two bits of this are not 0b10, ROM hangs (you have to OR 0x2 into the address). Otherwise, they are masked off and the resulting value is used as the reset vector. The resulting value is also stored in this register (i.e., the low two bits are cleared).  */
/** @brief Register definition for @ref APE_t.GpioMessage. */
typedef register_container RegAPEGpioMessage_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GpioMessage"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEGpioMessage_t()
    {
        /** @brief constructor for @ref APE_t.GpioMessage. */
        r32.setName("GpioMessage");
        r32.setComponentOffset(0x8);
    }
    RegAPEGpioMessage_t& operator=(const RegAPEGpioMessage_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
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
#if defined(__LITTLE_ENDIAN__)
        /** @brief Event 1 */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, _1, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_1, 1, 31)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_1, 1, 31)
        /** @brief Event 1 */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, _1, 0, 1)
#else
#error Unknown Endian
#endif
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
        r32.setComponentOffset(0xc);
        bits._1.setBaseRegister(&r32);
        bits._1.setName("_1");
        bits._1.setComponentOffset(0xc);
    }
    RegAPEEvent_t& operator=(const RegAPEEvent_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEEvent_t;

#define REG_APE_RXBUFOFFSET_FUNC0 ((volatile BCM5719_APE_H_uint32_t*)0xc0010014) /* This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
#define     APE_RXBUFOFFSET_FUNC0_TAIL_SHIFT 0u
#define     APE_RXBUFOFFSET_FUNC0_TAIL_MASK  0xfffu
#define GET_APE_RXBUFOFFSET_FUNC0_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_RXBUFOFFSET_FUNC0_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_RXBUFOFFSET_FUNC0_HEAD_SHIFT 12u
#define     APE_RXBUFOFFSET_FUNC0_HEAD_MASK  0xfff000u
#define GET_APE_RXBUFOFFSET_FUNC0_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_RXBUFOFFSET_FUNC0_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_RXBUFOFFSET_FUNC0_COUNT_SHIFT 26u
#define     APE_RXBUFOFFSET_FUNC0_COUNT_MASK  0x3c000000u
#define GET_APE_RXBUFOFFSET_FUNC0_COUNT(__reg__)  (((__reg__) & 0x3c000000) >> 26u)
#define SET_APE_RXBUFOFFSET_FUNC0_COUNT(__val__)  (((__val__) << 26u) & 0x3c000000u)
#define     APE_RXBUFOFFSET_FUNC0_VALID_SHIFT 30u
#define     APE_RXBUFOFFSET_FUNC0_VALID_MASK  0x40000000u
#define GET_APE_RXBUFOFFSET_FUNC0_VALID(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_APE_RXBUFOFFSET_FUNC0_VALID(__val__)  (((__val__) << 30u) & 0x40000000u)

/** @brief Register definition for @ref APE_t.RxbufoffsetFunc0. */
typedef register_container RegAPERxbufoffsetFunc0_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_25_24, 24, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Count, 26, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Valid, 30, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Valid, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Count, 26, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_25_24, 24, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxbufoffsetFunc0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxbufoffsetFunc0_t()
    {
        /** @brief constructor for @ref APE_t.RxbufoffsetFunc0. */
        r32.setName("RxbufoffsetFunc0");
        r32.setComponentOffset(0x14);
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Tail.setComponentOffset(0x14);
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.Head.setComponentOffset(0x14);
        bits.Count.setBaseRegister(&r32);
        bits.Count.setName("Count");
        bits.Count.setComponentOffset(0x14);
        bits.Valid.setBaseRegister(&r32);
        bits.Valid.setName("Valid");
        bits.Valid.setComponentOffset(0x14);
    }
    RegAPERxbufoffsetFunc0_t& operator=(const RegAPERxbufoffsetFunc0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxbufoffsetFunc0_t;

#define REG_APE_RXBUFOFFSET_FUNC1 ((volatile BCM5719_APE_H_uint32_t*)0xc0010018) /* This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
#define     APE_RXBUFOFFSET_FUNC1_TAIL_SHIFT 0u
#define     APE_RXBUFOFFSET_FUNC1_TAIL_MASK  0xfffu
#define GET_APE_RXBUFOFFSET_FUNC1_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_RXBUFOFFSET_FUNC1_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_RXBUFOFFSET_FUNC1_HEAD_SHIFT 12u
#define     APE_RXBUFOFFSET_FUNC1_HEAD_MASK  0xfff000u
#define GET_APE_RXBUFOFFSET_FUNC1_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_RXBUFOFFSET_FUNC1_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_RXBUFOFFSET_FUNC1_COUNT_SHIFT 26u
#define     APE_RXBUFOFFSET_FUNC1_COUNT_MASK  0x3c000000u
#define GET_APE_RXBUFOFFSET_FUNC1_COUNT(__reg__)  (((__reg__) & 0x3c000000) >> 26u)
#define SET_APE_RXBUFOFFSET_FUNC1_COUNT(__val__)  (((__val__) << 26u) & 0x3c000000u)
#define     APE_RXBUFOFFSET_FUNC1_VALID_SHIFT 30u
#define     APE_RXBUFOFFSET_FUNC1_VALID_MASK  0x40000000u
#define GET_APE_RXBUFOFFSET_FUNC1_VALID(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_APE_RXBUFOFFSET_FUNC1_VALID(__val__)  (((__val__) << 30u) & 0x40000000u)

/** @brief Register definition for @ref APE_t.RxbufoffsetFunc1. */
typedef register_container RegAPERxbufoffsetFunc1_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_25_24, 24, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Count, 26, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Valid, 30, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Valid, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Count, 26, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_25_24, 24, 2)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxbufoffsetFunc1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxbufoffsetFunc1_t()
    {
        /** @brief constructor for @ref APE_t.RxbufoffsetFunc1. */
        r32.setName("RxbufoffsetFunc1");
        r32.setComponentOffset(0x18);
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Tail.setComponentOffset(0x18);
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.Head.setComponentOffset(0x18);
        bits.Count.setBaseRegister(&r32);
        bits.Count.setName("Count");
        bits.Count.setComponentOffset(0x18);
        bits.Valid.setBaseRegister(&r32);
        bits.Valid.setName("Valid");
        bits.Valid.setComponentOffset(0x18);
    }
    RegAPERxbufoffsetFunc1_t& operator=(const RegAPERxbufoffsetFunc1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxbufoffsetFunc1_t;

#define REG_APE_MODE_2 ((volatile BCM5719_APE_H_uint32_t*)0xc001002c) /* Expansion for  */
/** @brief Register definition for @ref APE_t.Mode2. */
typedef register_container RegAPEMode2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Mode2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEMode2_t()
    {
        /** @brief constructor for @ref APE_t.Mode2. */
        r32.setName("Mode2");
        r32.setComponentOffset(0x2c);
    }
    RegAPEMode2_t& operator=(const RegAPEMode2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEMode2_t;

#define REG_APE_STATUS_2 ((volatile BCM5719_APE_H_uint32_t*)0xc0010030) /*  */
/** @brief Register definition for @ref APE_t.Status2. */
typedef register_container RegAPEStatus2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Status2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEStatus2_t()
    {
        /** @brief constructor for @ref APE_t.Status2. */
        r32.setName("Status2");
        r32.setComponentOffset(0x30);
    }
    RegAPEStatus2_t& operator=(const RegAPEStatus2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEStatus2_t;

#define REG_APE_LOCK_GRANT__OBSOLETE_ ((volatile BCM5719_APE_H_uint32_t*)0xc001004c) /* See  */
/** @brief Register definition for @ref APE_t.LockGrantObsolete. */
typedef register_container RegAPELockGrantObsolete_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LockGrantObsolete"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPELockGrantObsolete_t()
    {
        /** @brief constructor for @ref APE_t.LockGrantObsolete. */
        r32.setName("LockGrantObsolete");
        r32.setComponentOffset(0x4c);
    }
    RegAPELockGrantObsolete_t& operator=(const RegAPELockGrantObsolete_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPELockGrantObsolete_t;

#define REG_APE_B0 ((volatile BCM5719_APE_H_uint32_t*)0xc00100b0) /* Unknown. */
/** @brief Register definition for @ref APE_t.B0. */
typedef register_container RegAPEB0_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "B0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEB0_t()
    {
        /** @brief constructor for @ref APE_t.B0. */
        r32.setName("B0");
        r32.setComponentOffset(0xb0);
    }
    RegAPEB0_t& operator=(const RegAPEB0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
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
#if defined(__LITTLE_ENDIAN__)
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
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_20, 20, 12)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_20, 20, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN3ModeOutput, 19, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN2ModeOutput, 18, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN1ModeOutput, 17, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN0ModeOutput, 16, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_15_12, 12, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN3UnknownOut, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN2UnknownOut, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN1UnknownOut, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN0UnknownOut, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_4, 4, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN3Unknown, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN2Unknown, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN1Unknown, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PIN0Unknown, 0, 1)
#else
#error Unknown Endian
#endif
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
        r32.setComponentOffset(0xb8);
        bits.PIN0Unknown.setBaseRegister(&r32);
        bits.PIN0Unknown.setName("PIN0Unknown");
        bits.PIN0Unknown.setComponentOffset(0xb8);
        bits.PIN1Unknown.setBaseRegister(&r32);
        bits.PIN1Unknown.setName("PIN1Unknown");
        bits.PIN1Unknown.setComponentOffset(0xb8);
        bits.PIN2Unknown.setBaseRegister(&r32);
        bits.PIN2Unknown.setName("PIN2Unknown");
        bits.PIN2Unknown.setComponentOffset(0xb8);
        bits.PIN3Unknown.setBaseRegister(&r32);
        bits.PIN3Unknown.setName("PIN3Unknown");
        bits.PIN3Unknown.setComponentOffset(0xb8);
        bits.PIN0UnknownOut.setBaseRegister(&r32);
        bits.PIN0UnknownOut.setName("PIN0UnknownOut");
        bits.PIN0UnknownOut.setComponentOffset(0xb8);
        bits.PIN1UnknownOut.setBaseRegister(&r32);
        bits.PIN1UnknownOut.setName("PIN1UnknownOut");
        bits.PIN1UnknownOut.setComponentOffset(0xb8);
        bits.PIN2UnknownOut.setBaseRegister(&r32);
        bits.PIN2UnknownOut.setName("PIN2UnknownOut");
        bits.PIN2UnknownOut.setComponentOffset(0xb8);
        bits.PIN3UnknownOut.setBaseRegister(&r32);
        bits.PIN3UnknownOut.setName("PIN3UnknownOut");
        bits.PIN3UnknownOut.setComponentOffset(0xb8);
        bits.PIN0ModeOutput.setBaseRegister(&r32);
        bits.PIN0ModeOutput.setName("PIN0ModeOutput");
        bits.PIN0ModeOutput.setComponentOffset(0xb8);
        bits.PIN1ModeOutput.setBaseRegister(&r32);
        bits.PIN1ModeOutput.setName("PIN1ModeOutput");
        bits.PIN1ModeOutput.setComponentOffset(0xb8);
        bits.PIN2ModeOutput.setBaseRegister(&r32);
        bits.PIN2ModeOutput.setName("PIN2ModeOutput");
        bits.PIN2ModeOutput.setComponentOffset(0xb8);
        bits.PIN3ModeOutput.setBaseRegister(&r32);
        bits.PIN3ModeOutput.setName("PIN3ModeOutput");
        bits.PIN3ModeOutput.setComponentOffset(0xb8);
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
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Gint"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEGint_t()
    {
        /** @brief constructor for @ref APE_t.Gint. */
        r32.setName("Gint");
        r32.setComponentOffset(0xbc);
    }
    RegAPEGint_t& operator=(const RegAPEGint_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
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
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Start, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_20_1, 1, 20)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ProgEnable, 21, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_22, 22, 10)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_22, 22, 10)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ProgEnable, 21, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_20_1, 1, 20)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Start, 0, 1)
#else
#error Unknown Endian
#endif
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
        r32.setComponentOffset(0xe8);
        bits.Start.setBaseRegister(&r32);
        bits.Start.setName("Start");
        bits.Start.setComponentOffset(0xe8);
        bits.ProgEnable.setBaseRegister(&r32);
        bits.ProgEnable.setName("ProgEnable");
        bits.ProgEnable.setComponentOffset(0xe8);
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
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, CommandDone, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_1, 1, 31)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_1, 1, 31)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, CommandDone, 0, 1)
#else
#error Unknown Endian
#endif
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
        r32.setComponentOffset(0xec);
        bits.CommandDone.setBaseRegister(&r32);
        bits.CommandDone.setName("CommandDone");
        bits.CommandDone.setComponentOffset(0xec);
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
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Address, 0, 31)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, CPUEnable, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, CPUEnable, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Address, 0, 31)
#else
#error Unknown Endian
#endif
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
        r32.setComponentOffset(0xf0);
        bits.Address.setBaseRegister(&r32);
        bits.Address.setName("Address");
        bits.Address.setComponentOffset(0xf0);
        bits.CPUEnable.setBaseRegister(&r32);
        bits.CPUEnable.setName("CPUEnable");
        bits.CPUEnable.setComponentOffset(0xf0);
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
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "OtpReadData"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEOtpReadData_t()
    {
        /** @brief constructor for @ref APE_t.OtpReadData. */
        r32.setName("OtpReadData");
        r32.setComponentOffset(0xf8);
    }
    RegAPEOtpReadData_t& operator=(const RegAPEOtpReadData_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
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
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, CPUStatus, 0, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_4, 4, 28)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_4, 4, 28)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, CPUStatus, 0, 4)
#else
#error Unknown Endian
#endif
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
        r32.setComponentOffset(0x108);
        bits.CPUStatus.setBaseRegister(&r32);
        bits.CPUStatus.setName("CPUStatus");
        bits.CPUStatus.setComponentOffset(0x108);
    }
    RegAPECm3_t& operator=(const RegAPECm3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPECm3_t;

#define REG_APE_PER_LOCK_REQUEST_PHY0 ((volatile BCM5719_APE_H_uint32_t*)0xc0018400) /* This register, and the following Per Lock Request registers work the same. The tg3 driver uses 0x0000_1000 (APELOCK_PER_REQ_DRIVER) for PHY ports (or always for function 0). */
#define     APE_PER_LOCK_REQUEST_PHY0_APE_SHIFT 0u
#define     APE_PER_LOCK_REQUEST_PHY0_APE_MASK  0x1u
#define GET_APE_PER_LOCK_REQUEST_PHY0_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_REQUEST_PHY0_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_REQUEST_PHY0_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_REQUEST_PHY0_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_REQUEST_PHY0_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_REQUEST_PHY0_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_REQUEST_PHY0_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_REQUEST_PHY0_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_REQUEST_PHY0_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_REQUEST_PHY0_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_REQUEST_PHY0_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_REQUEST_PHY0_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_REQUEST_PHY0_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_REQUEST_PHY0_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_REQUEST_PHY0_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_REQUEST_PHY0_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_REQUEST_PHY0_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_REQUEST_PHY0_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_REQUEST_PHY0_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_REQUEST_PHY0_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_REQUEST_PHY0_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_REQUEST_PHY0_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockRequestPhy0. */
typedef register_container RegAPEPerLockRequestPhy0_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestPhy0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockRequestPhy0_t()
    {
        /** @brief constructor for @ref APE_t.PerLockRequestPhy0. */
        r32.setName("PerLockRequestPhy0");
        r32.setComponentOffset(0x8400);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x8400);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x8400);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x8400);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x8400);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x8400);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x8400);
    }
    RegAPEPerLockRequestPhy0_t& operator=(const RegAPEPerLockRequestPhy0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockRequestPhy0_t;

#define REG_APE_PER_LOCK_REQUEST_GRC ((volatile BCM5719_APE_H_uint32_t*)0xc0018404) /*  */
#define     APE_PER_LOCK_REQUEST_GRC_APE_SHIFT 0u
#define     APE_PER_LOCK_REQUEST_GRC_APE_MASK  0x1u
#define GET_APE_PER_LOCK_REQUEST_GRC_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_REQUEST_GRC_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_REQUEST_GRC_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_REQUEST_GRC_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_REQUEST_GRC_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_REQUEST_GRC_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_REQUEST_GRC_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_REQUEST_GRC_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_REQUEST_GRC_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_REQUEST_GRC_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_REQUEST_GRC_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_REQUEST_GRC_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_REQUEST_GRC_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_REQUEST_GRC_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_REQUEST_GRC_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_REQUEST_GRC_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_REQUEST_GRC_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_REQUEST_GRC_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_REQUEST_GRC_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_REQUEST_GRC_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_REQUEST_GRC_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_REQUEST_GRC_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockRequestGrc. */
typedef register_container RegAPEPerLockRequestGrc_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestGrc"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockRequestGrc_t()
    {
        /** @brief constructor for @ref APE_t.PerLockRequestGrc. */
        r32.setName("PerLockRequestGrc");
        r32.setComponentOffset(0x8404);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x8404);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x8404);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x8404);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x8404);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x8404);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x8404);
    }
    RegAPEPerLockRequestGrc_t& operator=(const RegAPEPerLockRequestGrc_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockRequestGrc_t;

#define REG_APE_PER_LOCK_REQUEST_PHY1 ((volatile BCM5719_APE_H_uint32_t*)0xc0018408) /*  */
#define     APE_PER_LOCK_REQUEST_PHY1_APE_SHIFT 0u
#define     APE_PER_LOCK_REQUEST_PHY1_APE_MASK  0x1u
#define GET_APE_PER_LOCK_REQUEST_PHY1_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_REQUEST_PHY1_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_REQUEST_PHY1_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_REQUEST_PHY1_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_REQUEST_PHY1_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_REQUEST_PHY1_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_REQUEST_PHY1_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_REQUEST_PHY1_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_REQUEST_PHY1_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_REQUEST_PHY1_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_REQUEST_PHY1_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_REQUEST_PHY1_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_REQUEST_PHY1_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_REQUEST_PHY1_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_REQUEST_PHY1_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_REQUEST_PHY1_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_REQUEST_PHY1_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_REQUEST_PHY1_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_REQUEST_PHY1_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_REQUEST_PHY1_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_REQUEST_PHY1_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_REQUEST_PHY1_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockRequestPhy1. */
typedef register_container RegAPEPerLockRequestPhy1_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestPhy1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockRequestPhy1_t()
    {
        /** @brief constructor for @ref APE_t.PerLockRequestPhy1. */
        r32.setName("PerLockRequestPhy1");
        r32.setComponentOffset(0x8408);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x8408);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x8408);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x8408);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x8408);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x8408);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x8408);
    }
    RegAPEPerLockRequestPhy1_t& operator=(const RegAPEPerLockRequestPhy1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockRequestPhy1_t;

#define REG_APE_PER_LOCK_REQUEST_PHY2 ((volatile BCM5719_APE_H_uint32_t*)0xc001840c) /*  */
#define     APE_PER_LOCK_REQUEST_PHY2_APE_SHIFT 0u
#define     APE_PER_LOCK_REQUEST_PHY2_APE_MASK  0x1u
#define GET_APE_PER_LOCK_REQUEST_PHY2_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_REQUEST_PHY2_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_REQUEST_PHY2_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_REQUEST_PHY2_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_REQUEST_PHY2_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_REQUEST_PHY2_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_REQUEST_PHY2_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_REQUEST_PHY2_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_REQUEST_PHY2_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_REQUEST_PHY2_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_REQUEST_PHY2_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_REQUEST_PHY2_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_REQUEST_PHY2_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_REQUEST_PHY2_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_REQUEST_PHY2_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_REQUEST_PHY2_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_REQUEST_PHY2_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_REQUEST_PHY2_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_REQUEST_PHY2_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_REQUEST_PHY2_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_REQUEST_PHY2_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_REQUEST_PHY2_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockRequestPhy2. */
typedef register_container RegAPEPerLockRequestPhy2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestPhy2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockRequestPhy2_t()
    {
        /** @brief constructor for @ref APE_t.PerLockRequestPhy2. */
        r32.setName("PerLockRequestPhy2");
        r32.setComponentOffset(0x840c);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x840c);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x840c);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x840c);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x840c);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x840c);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x840c);
    }
    RegAPEPerLockRequestPhy2_t& operator=(const RegAPEPerLockRequestPhy2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockRequestPhy2_t;

#define REG_APE_PER_LOCK_REQUEST_MEM ((volatile BCM5719_APE_H_uint32_t*)0xc0018410) /*  */
#define     APE_PER_LOCK_REQUEST_MEM_APE_SHIFT 0u
#define     APE_PER_LOCK_REQUEST_MEM_APE_MASK  0x1u
#define GET_APE_PER_LOCK_REQUEST_MEM_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_REQUEST_MEM_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_REQUEST_MEM_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_REQUEST_MEM_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_REQUEST_MEM_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_REQUEST_MEM_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_REQUEST_MEM_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_REQUEST_MEM_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_REQUEST_MEM_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_REQUEST_MEM_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_REQUEST_MEM_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_REQUEST_MEM_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_REQUEST_MEM_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_REQUEST_MEM_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_REQUEST_MEM_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_REQUEST_MEM_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_REQUEST_MEM_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_REQUEST_MEM_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_REQUEST_MEM_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_REQUEST_MEM_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_REQUEST_MEM_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_REQUEST_MEM_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockRequestMem. */
typedef register_container RegAPEPerLockRequestMem_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestMem"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockRequestMem_t()
    {
        /** @brief constructor for @ref APE_t.PerLockRequestMem. */
        r32.setName("PerLockRequestMem");
        r32.setComponentOffset(0x8410);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x8410);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x8410);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x8410);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x8410);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x8410);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x8410);
    }
    RegAPEPerLockRequestMem_t& operator=(const RegAPEPerLockRequestMem_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockRequestMem_t;

#define REG_APE_PER_LOCK_REQUEST_PHY3 ((volatile BCM5719_APE_H_uint32_t*)0xc0018414) /*  */
#define     APE_PER_LOCK_REQUEST_PHY3_APE_SHIFT 0u
#define     APE_PER_LOCK_REQUEST_PHY3_APE_MASK  0x1u
#define GET_APE_PER_LOCK_REQUEST_PHY3_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_REQUEST_PHY3_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_REQUEST_PHY3_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_REQUEST_PHY3_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_REQUEST_PHY3_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_REQUEST_PHY3_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_REQUEST_PHY3_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_REQUEST_PHY3_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_REQUEST_PHY3_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_REQUEST_PHY3_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_REQUEST_PHY3_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_REQUEST_PHY3_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_REQUEST_PHY3_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_REQUEST_PHY3_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_REQUEST_PHY3_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_REQUEST_PHY3_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_REQUEST_PHY3_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_REQUEST_PHY3_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_REQUEST_PHY3_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_REQUEST_PHY3_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_REQUEST_PHY3_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_REQUEST_PHY3_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockRequestPhy3. */
typedef register_container RegAPEPerLockRequestPhy3_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestPhy3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockRequestPhy3_t()
    {
        /** @brief constructor for @ref APE_t.PerLockRequestPhy3. */
        r32.setName("PerLockRequestPhy3");
        r32.setComponentOffset(0x8414);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x8414);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x8414);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x8414);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x8414);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x8414);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x8414);
    }
    RegAPEPerLockRequestPhy3_t& operator=(const RegAPEPerLockRequestPhy3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockRequestPhy3_t;

#define REG_APE_PER_LOCK_REQUEST_PORT6 ((volatile BCM5719_APE_H_uint32_t*)0xc0018418) /*  */
#define     APE_PER_LOCK_REQUEST_PORT6_APE_SHIFT 0u
#define     APE_PER_LOCK_REQUEST_PORT6_APE_MASK  0x1u
#define GET_APE_PER_LOCK_REQUEST_PORT6_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_REQUEST_PORT6_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_REQUEST_PORT6_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_REQUEST_PORT6_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_REQUEST_PORT6_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_REQUEST_PORT6_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_REQUEST_PORT6_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_REQUEST_PORT6_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_REQUEST_PORT6_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_REQUEST_PORT6_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_REQUEST_PORT6_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_REQUEST_PORT6_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_REQUEST_PORT6_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_REQUEST_PORT6_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_REQUEST_PORT6_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_REQUEST_PORT6_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_REQUEST_PORT6_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_REQUEST_PORT6_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_REQUEST_PORT6_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_REQUEST_PORT6_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_REQUEST_PORT6_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_REQUEST_PORT6_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockRequestPort6. */
typedef register_container RegAPEPerLockRequestPort6_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestPort6"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockRequestPort6_t()
    {
        /** @brief constructor for @ref APE_t.PerLockRequestPort6. */
        r32.setName("PerLockRequestPort6");
        r32.setComponentOffset(0x8418);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x8418);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x8418);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x8418);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x8418);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x8418);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x8418);
    }
    RegAPEPerLockRequestPort6_t& operator=(const RegAPEPerLockRequestPort6_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockRequestPort6_t;

#define REG_APE_PER_LOCK_REQUEST_GPIO ((volatile BCM5719_APE_H_uint32_t*)0xc001841c) /*  */
#define     APE_PER_LOCK_REQUEST_GPIO_APE_SHIFT 0u
#define     APE_PER_LOCK_REQUEST_GPIO_APE_MASK  0x1u
#define GET_APE_PER_LOCK_REQUEST_GPIO_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_REQUEST_GPIO_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_REQUEST_GPIO_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_REQUEST_GPIO_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_REQUEST_GPIO_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_REQUEST_GPIO_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_REQUEST_GPIO_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_REQUEST_GPIO_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_REQUEST_GPIO_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_REQUEST_GPIO_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_REQUEST_GPIO_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_REQUEST_GPIO_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_REQUEST_GPIO_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_REQUEST_GPIO_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_REQUEST_GPIO_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_REQUEST_GPIO_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_REQUEST_GPIO_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_REQUEST_GPIO_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_REQUEST_GPIO_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_REQUEST_GPIO_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_REQUEST_GPIO_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_REQUEST_GPIO_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockRequestGpio. */
typedef register_container RegAPEPerLockRequestGpio_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockRequestGpio"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockRequestGpio_t()
    {
        /** @brief constructor for @ref APE_t.PerLockRequestGpio. */
        r32.setName("PerLockRequestGpio");
        r32.setComponentOffset(0x841c);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x841c);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x841c);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x841c);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x841c);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x841c);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x841c);
    }
    RegAPEPerLockRequestGpio_t& operator=(const RegAPEPerLockRequestGpio_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockRequestGpio_t;

#define REG_APE_PER_LOCK_GRANT_PHY0 ((volatile BCM5719_APE_H_uint32_t*)0xc0018420) /*  */
#define     APE_PER_LOCK_GRANT_PHY0_APE_SHIFT 0u
#define     APE_PER_LOCK_GRANT_PHY0_APE_MASK  0x1u
#define GET_APE_PER_LOCK_GRANT_PHY0_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_GRANT_PHY0_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_GRANT_PHY0_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_GRANT_PHY0_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_GRANT_PHY0_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_GRANT_PHY0_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_GRANT_PHY0_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_GRANT_PHY0_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_GRANT_PHY0_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_GRANT_PHY0_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_GRANT_PHY0_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_GRANT_PHY0_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_GRANT_PHY0_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_GRANT_PHY0_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_GRANT_PHY0_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_GRANT_PHY0_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_GRANT_PHY0_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_GRANT_PHY0_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_GRANT_PHY0_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_GRANT_PHY0_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_GRANT_PHY0_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_GRANT_PHY0_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockGrantPhy0. */
typedef register_container RegAPEPerLockGrantPhy0_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantPhy0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockGrantPhy0_t()
    {
        /** @brief constructor for @ref APE_t.PerLockGrantPhy0. */
        r32.setName("PerLockGrantPhy0");
        r32.setComponentOffset(0x8420);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x8420);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x8420);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x8420);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x8420);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x8420);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x8420);
    }
    RegAPEPerLockGrantPhy0_t& operator=(const RegAPEPerLockGrantPhy0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockGrantPhy0_t;

#define REG_APE_PER_LOCK_GRANT_GRC ((volatile BCM5719_APE_H_uint32_t*)0xc0018424) /*  */
#define     APE_PER_LOCK_GRANT_GRC_APE_SHIFT 0u
#define     APE_PER_LOCK_GRANT_GRC_APE_MASK  0x1u
#define GET_APE_PER_LOCK_GRANT_GRC_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_GRANT_GRC_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_GRANT_GRC_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_GRANT_GRC_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_GRANT_GRC_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_GRANT_GRC_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_GRANT_GRC_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_GRANT_GRC_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_GRANT_GRC_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_GRANT_GRC_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_GRANT_GRC_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_GRANT_GRC_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_GRANT_GRC_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_GRANT_GRC_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_GRANT_GRC_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_GRANT_GRC_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_GRANT_GRC_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_GRANT_GRC_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_GRANT_GRC_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_GRANT_GRC_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_GRANT_GRC_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_GRANT_GRC_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockGrantGrc. */
typedef register_container RegAPEPerLockGrantGrc_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantGrc"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockGrantGrc_t()
    {
        /** @brief constructor for @ref APE_t.PerLockGrantGrc. */
        r32.setName("PerLockGrantGrc");
        r32.setComponentOffset(0x8424);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x8424);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x8424);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x8424);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x8424);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x8424);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x8424);
    }
    RegAPEPerLockGrantGrc_t& operator=(const RegAPEPerLockGrantGrc_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockGrantGrc_t;

#define REG_APE_PER_LOCK_GRANT_PHY1 ((volatile BCM5719_APE_H_uint32_t*)0xc0018428) /*  */
#define     APE_PER_LOCK_GRANT_PHY1_APE_SHIFT 0u
#define     APE_PER_LOCK_GRANT_PHY1_APE_MASK  0x1u
#define GET_APE_PER_LOCK_GRANT_PHY1_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_GRANT_PHY1_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_GRANT_PHY1_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_GRANT_PHY1_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_GRANT_PHY1_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_GRANT_PHY1_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_GRANT_PHY1_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_GRANT_PHY1_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_GRANT_PHY1_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_GRANT_PHY1_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_GRANT_PHY1_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_GRANT_PHY1_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_GRANT_PHY1_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_GRANT_PHY1_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_GRANT_PHY1_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_GRANT_PHY1_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_GRANT_PHY1_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_GRANT_PHY1_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_GRANT_PHY1_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_GRANT_PHY1_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_GRANT_PHY1_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_GRANT_PHY1_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockGrantPhy1. */
typedef register_container RegAPEPerLockGrantPhy1_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantPhy1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockGrantPhy1_t()
    {
        /** @brief constructor for @ref APE_t.PerLockGrantPhy1. */
        r32.setName("PerLockGrantPhy1");
        r32.setComponentOffset(0x8428);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x8428);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x8428);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x8428);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x8428);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x8428);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x8428);
    }
    RegAPEPerLockGrantPhy1_t& operator=(const RegAPEPerLockGrantPhy1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockGrantPhy1_t;

#define REG_APE_PER_LOCK_GRANT_PHY2 ((volatile BCM5719_APE_H_uint32_t*)0xc001842c) /*  */
#define     APE_PER_LOCK_GRANT_PHY2_APE_SHIFT 0u
#define     APE_PER_LOCK_GRANT_PHY2_APE_MASK  0x1u
#define GET_APE_PER_LOCK_GRANT_PHY2_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_GRANT_PHY2_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_GRANT_PHY2_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_GRANT_PHY2_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_GRANT_PHY2_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_GRANT_PHY2_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_GRANT_PHY2_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_GRANT_PHY2_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_GRANT_PHY2_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_GRANT_PHY2_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_GRANT_PHY2_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_GRANT_PHY2_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_GRANT_PHY2_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_GRANT_PHY2_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_GRANT_PHY2_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_GRANT_PHY2_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_GRANT_PHY2_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_GRANT_PHY2_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_GRANT_PHY2_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_GRANT_PHY2_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_GRANT_PHY2_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_GRANT_PHY2_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockGrantPhy2. */
typedef register_container RegAPEPerLockGrantPhy2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantPhy2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockGrantPhy2_t()
    {
        /** @brief constructor for @ref APE_t.PerLockGrantPhy2. */
        r32.setName("PerLockGrantPhy2");
        r32.setComponentOffset(0x842c);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x842c);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x842c);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x842c);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x842c);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x842c);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x842c);
    }
    RegAPEPerLockGrantPhy2_t& operator=(const RegAPEPerLockGrantPhy2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockGrantPhy2_t;

#define REG_APE_PER_LOCK_GRANT_MEM ((volatile BCM5719_APE_H_uint32_t*)0xc0018430) /*  */
#define     APE_PER_LOCK_GRANT_MEM_APE_SHIFT 0u
#define     APE_PER_LOCK_GRANT_MEM_APE_MASK  0x1u
#define GET_APE_PER_LOCK_GRANT_MEM_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_GRANT_MEM_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_GRANT_MEM_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_GRANT_MEM_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_GRANT_MEM_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_GRANT_MEM_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_GRANT_MEM_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_GRANT_MEM_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_GRANT_MEM_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_GRANT_MEM_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_GRANT_MEM_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_GRANT_MEM_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_GRANT_MEM_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_GRANT_MEM_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_GRANT_MEM_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_GRANT_MEM_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_GRANT_MEM_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_GRANT_MEM_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_GRANT_MEM_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_GRANT_MEM_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_GRANT_MEM_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_GRANT_MEM_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockGrantMem. */
typedef register_container RegAPEPerLockGrantMem_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantMem"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockGrantMem_t()
    {
        /** @brief constructor for @ref APE_t.PerLockGrantMem. */
        r32.setName("PerLockGrantMem");
        r32.setComponentOffset(0x8430);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x8430);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x8430);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x8430);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x8430);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x8430);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x8430);
    }
    RegAPEPerLockGrantMem_t& operator=(const RegAPEPerLockGrantMem_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockGrantMem_t;

#define REG_APE_PER_LOCK_GRANT_PHY3 ((volatile BCM5719_APE_H_uint32_t*)0xc0018434) /*  */
#define     APE_PER_LOCK_GRANT_PHY3_APE_SHIFT 0u
#define     APE_PER_LOCK_GRANT_PHY3_APE_MASK  0x1u
#define GET_APE_PER_LOCK_GRANT_PHY3_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_GRANT_PHY3_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_GRANT_PHY3_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_GRANT_PHY3_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_GRANT_PHY3_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_GRANT_PHY3_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_GRANT_PHY3_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_GRANT_PHY3_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_GRANT_PHY3_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_GRANT_PHY3_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_GRANT_PHY3_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_GRANT_PHY3_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_GRANT_PHY3_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_GRANT_PHY3_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_GRANT_PHY3_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_GRANT_PHY3_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_GRANT_PHY3_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_GRANT_PHY3_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_GRANT_PHY3_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_GRANT_PHY3_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_GRANT_PHY3_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_GRANT_PHY3_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockGrantPhy3. */
typedef register_container RegAPEPerLockGrantPhy3_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantPhy3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockGrantPhy3_t()
    {
        /** @brief constructor for @ref APE_t.PerLockGrantPhy3. */
        r32.setName("PerLockGrantPhy3");
        r32.setComponentOffset(0x8434);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x8434);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x8434);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x8434);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x8434);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x8434);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x8434);
    }
    RegAPEPerLockGrantPhy3_t& operator=(const RegAPEPerLockGrantPhy3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockGrantPhy3_t;

#define REG_APE_PER_LOCK_GRANT_PORT6 ((volatile BCM5719_APE_H_uint32_t*)0xc0018438) /*  */
#define     APE_PER_LOCK_GRANT_PORT6_APE_SHIFT 0u
#define     APE_PER_LOCK_GRANT_PORT6_APE_MASK  0x1u
#define GET_APE_PER_LOCK_GRANT_PORT6_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_GRANT_PORT6_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_GRANT_PORT6_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_GRANT_PORT6_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_GRANT_PORT6_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_GRANT_PORT6_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_GRANT_PORT6_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_GRANT_PORT6_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_GRANT_PORT6_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_GRANT_PORT6_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_GRANT_PORT6_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_GRANT_PORT6_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_GRANT_PORT6_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_GRANT_PORT6_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_GRANT_PORT6_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_GRANT_PORT6_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_GRANT_PORT6_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_GRANT_PORT6_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_GRANT_PORT6_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_GRANT_PORT6_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_GRANT_PORT6_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_GRANT_PORT6_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockGrantPort6. */
typedef register_container RegAPEPerLockGrantPort6_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantPort6"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockGrantPort6_t()
    {
        /** @brief constructor for @ref APE_t.PerLockGrantPort6. */
        r32.setName("PerLockGrantPort6");
        r32.setComponentOffset(0x8438);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x8438);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x8438);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x8438);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x8438);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x8438);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x8438);
    }
    RegAPEPerLockGrantPort6_t& operator=(const RegAPEPerLockGrantPort6_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockGrantPort6_t;

#define REG_APE_PER_LOCK_GRANT_GPIO ((volatile BCM5719_APE_H_uint32_t*)0xc001843c) /*  */
#define     APE_PER_LOCK_GRANT_GPIO_APE_SHIFT 0u
#define     APE_PER_LOCK_GRANT_GPIO_APE_MASK  0x1u
#define GET_APE_PER_LOCK_GRANT_GPIO_APE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_PER_LOCK_GRANT_GPIO_APE(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_PER_LOCK_GRANT_GPIO_FUNCTION_1_SHIFT 1u
#define     APE_PER_LOCK_GRANT_GPIO_FUNCTION_1_MASK  0x2u
#define GET_APE_PER_LOCK_GRANT_GPIO_FUNCTION_1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_PER_LOCK_GRANT_GPIO_FUNCTION_1(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_PER_LOCK_GRANT_GPIO_FUNCTION_2_SHIFT 2u
#define     APE_PER_LOCK_GRANT_GPIO_FUNCTION_2_MASK  0x4u
#define GET_APE_PER_LOCK_GRANT_GPIO_FUNCTION_2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_PER_LOCK_GRANT_GPIO_FUNCTION_2(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_PER_LOCK_GRANT_GPIO_FUNCTION_3_SHIFT 3u
#define     APE_PER_LOCK_GRANT_GPIO_FUNCTION_3_MASK  0x8u
#define GET_APE_PER_LOCK_GRANT_GPIO_FUNCTION_3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_PER_LOCK_GRANT_GPIO_FUNCTION_3(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_PER_LOCK_GRANT_GPIO_BOOTCODE_SHIFT 4u
#define     APE_PER_LOCK_GRANT_GPIO_BOOTCODE_MASK  0x10u
#define GET_APE_PER_LOCK_GRANT_GPIO_BOOTCODE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_PER_LOCK_GRANT_GPIO_BOOTCODE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_PER_LOCK_GRANT_GPIO_DRIVER_SHIFT 12u
#define     APE_PER_LOCK_GRANT_GPIO_DRIVER_MASK  0x1000u
#define GET_APE_PER_LOCK_GRANT_GPIO_DRIVER(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_PER_LOCK_GRANT_GPIO_DRIVER(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.PerLockGrantGpio. */
typedef register_container RegAPEPerLockGrantGpio_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_11_5, 5, 7)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Bootcode, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function2, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Function1, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, APE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "PerLockGrantGpio"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEPerLockGrantGpio_t()
    {
        /** @brief constructor for @ref APE_t.PerLockGrantGpio. */
        r32.setName("PerLockGrantGpio");
        r32.setComponentOffset(0x843c);
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.APE.setComponentOffset(0x843c);
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function1.setComponentOffset(0x843c);
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function2.setComponentOffset(0x843c);
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Function3.setComponentOffset(0x843c);
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Bootcode.setComponentOffset(0x843c);
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
        bits.Driver.setComponentOffset(0x843c);
    }
    RegAPEPerLockGrantGpio_t& operator=(const RegAPEPerLockGrantGpio_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockGrantGpio_t;

/** @brief Component definition for @ref APE. */
typedef struct {
    /** @brief More of these bits can be found in diagnostic utilities, but they don't seem too interesting. */
    RegAPEMode_t Mode;

    /** @brief  */
    RegAPEStatus_t Status;

    /** @brief Related to APE fastboot. In that case the value of it is an APE memory address in the code region. If Fast Boot is set, and the low two bits of this are not 0b10, ROM hangs (you have to OR 0x2 into the address). Otherwise, they are masked off and the resulting value is used as the reset vector. The resulting value is also stored in this register (i.e., the low two bits are cleared).  */
    RegAPEGpioMessage_t GpioMessage;

    /** @brief  */
    RegAPEEvent_t Event;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_16[1];

    /** @brief This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
    RegAPERxbufoffsetFunc0_t RxbufoffsetFunc0;

    /** @brief This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
    RegAPERxbufoffsetFunc1_t RxbufoffsetFunc1;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_28[4];

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
    BCM5719_APE_H_uint32_t reserved_268[8381];

    /** @brief This register, and the following Per Lock Request registers work the same. The tg3 driver uses 0x0000_1000 (APELOCK_PER_REQ_DRIVER) for PHY ports (or always for function 0). */
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

#ifdef CXX_SIMULATOR
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
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
