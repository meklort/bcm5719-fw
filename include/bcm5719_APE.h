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
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.FastBoot.setBaseRegister(&r32);
        bits.FastBoot.setName("FastBoot");
        bits.HostDiag.setBaseRegister(&r32);
        bits.HostDiag.setName("HostDiag");
        bits.Event1.setBaseRegister(&r32);
        bits.Event1.setName("Event1");
        bits.Event2.setBaseRegister(&r32);
        bits.Event2.setName("Event2");
        bits.GRCint.setBaseRegister(&r32);
        bits.GRCint.setName("GRCint");
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
        bits.PCIeReset.setBaseRegister(&r32);
        bits.PCIeReset.setName("PCIeReset");
        bits.NVRAMControlReset.setBaseRegister(&r32);
        bits.NVRAMControlReset.setName("NVRAMControlReset");
        bits.LAN0Dstate.setBaseRegister(&r32);
        bits.LAN0Dstate.setName("LAN0Dstate");
        bits.BootMode.setBaseRegister(&r32);
        bits.BootMode.setName("BootMode");
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

#define REG_APE_GPIO_MESSAGE ((volatile BCM5719_APE_H_uint32_t*)0xc0010008) /* Related to APE fastboot. In that case the value of it is an APE memory address in the code region. If Fast Boot is set, and the low two bits of this are not 0b10, ROM hangs (you have to OR 0x2 into the address). Otherwise, they are masked off and the resulting value is used as the reset vector. The resulting value is also stored in this register (i.e., the low two bits are cleared).  */
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
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.Count.setBaseRegister(&r32);
        bits.Count.setName("Count");
        bits.Valid.setBaseRegister(&r32);
        bits.Valid.setName("Valid");
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
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.Count.setBaseRegister(&r32);
        bits.Count.setName("Count");
        bits.Valid.setBaseRegister(&r32);
        bits.Valid.setName("Valid");
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
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_0, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Ready, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_27_9, 9, 19)
        /** @brief If this is all-ones, it appears to mean the APE FW is halted. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, unknown_31_28, 28, 4)
#elif defined(__BIG_ENDIAN__)
        /** @brief If this is all-ones, it appears to mean the APE FW is halted. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, unknown_31_28, 28, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_27_9, 9, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Ready, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_0, 0, 8)
#else
#error Unknown Endian
#endif
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
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_0_0, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, NCSI, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_2, 2, 30)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_2, 2, 30)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, NCSI, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_0_0, 0, 1)
#else
#error Unknown Endian
#endif
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
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Build, 0, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Revision, 8, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Minor, 16, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Major, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Major, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Minor, 16, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Revision, 8, 8)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Build, 0, 8)
#else
#error Unknown Endian
#endif
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
#define     APE_RCPU_SEG_SIG_SIG_SHIFT 0u
#define     APE_RCPU_SEG_SIG_SIG_MASK  0xffffffffu
#define GET_APE_RCPU_SEG_SIG_SIG(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_APE_RCPU_SEG_SIG_SIG(__val__)  (((__val__) << 0u) & 0xffffffffu)
#define     APE_RCPU_SEG_SIG_SIG_RCPU_MAGIC 0x52435055u


/** @brief Register definition for @ref APE_t.RcpuSegSig. */
typedef register_container RegAPERcpuSegSig_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Sig, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Sig, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuSegSig"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERcpuSegSig_t()
    {
        /** @brief constructor for @ref APE_t.RcpuSegSig. */
        r32.setName("RcpuSegSig");
        bits.Sig.setBaseRegister(&r32);
        bits.Sig.setName("Sig");
    }
    RegAPERcpuSegSig_t& operator=(const RegAPERcpuSegSig_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
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

#define REG_APE_RCPU_APE_RESET_COUNT ((volatile BCM5719_APE_H_uint32_t*)0xc001411c) /* Unknown. Incremented by frobnicating routine. */
/** @brief Register definition for @ref APE_t.RcpuApeResetCount. */
typedef register_container RegAPERcpuApeResetCount_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPERcpuApeResetCount_t;

#define REG_APE_RCPU_LAST_APE_STATUS ((volatile BCM5719_APE_H_uint32_t*)0xc0014120) /* Unknown. Written by frobnicating routine. */
/** @brief Register definition for @ref APE_t.RcpuLastApeStatus. */
typedef register_container RegAPERcpuLastApeStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPERcpuLastApeStatus_t;

#define REG_APE_RCPU_LAST_APE_FW_STATUS ((volatile BCM5719_APE_H_uint32_t*)0xc0014124) /* Unknown.  */
/** @brief Register definition for @ref APE_t.RcpuLastApeFwStatus. */
typedef register_container RegAPERcpuLastApeFwStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPERcpuLastApeFwStatus_t;

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
#define     APE_RCPU_CPMU_STATUS_ADDRESS_SHIFT 0u
#define     APE_RCPU_CPMU_STATUS_ADDRESS_MASK  0xffffu
#define GET_APE_RCPU_CPMU_STATUS_ADDRESS(__reg__)  (((__reg__) & 0xffff) >> 0u)
#define SET_APE_RCPU_CPMU_STATUS_ADDRESS(__val__)  (((__val__) << 0u) & 0xffffu)
#define     APE_RCPU_CPMU_STATUS_ADDRESS_ADDRESS 0x362cu

#define     APE_RCPU_CPMU_STATUS_STATUS_SHIFT 16u
#define     APE_RCPU_CPMU_STATUS_STATUS_MASK  0xffff0000u
#define GET_APE_RCPU_CPMU_STATUS_STATUS(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_APE_RCPU_CPMU_STATUS_STATUS(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref APE_t.RcpuCpmuStatus. */
typedef register_container RegAPERcpuCpmuStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Address, 0, 16)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Status, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Status, 16, 16)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Address, 0, 16)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RcpuCpmuStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERcpuCpmuStatus_t()
    {
        /** @brief constructor for @ref APE_t.RcpuCpmuStatus. */
        r32.setName("RcpuCpmuStatus");
        bits.Address.setBaseRegister(&r32);
        bits.Address.setName("Address");
        bits.Status.setBaseRegister(&r32);
        bits.Status.setName("Status");
    }
    RegAPERcpuCpmuStatus_t& operator=(const RegAPERcpuCpmuStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
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
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, NoPHYLock, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_1, 1, 31)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_1, 1, 31)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, NoPHYLock, 0, 1)
#else
#error Unknown Endian
#endif
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
#if defined(__LITTLE_ENDIAN__)
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
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Pending, 31, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_30_19, 19, 12)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, State, 16, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Command, 8, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, DriverEvent, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_3_0, 0, 4)
#else
#error Unknown Endian
#endif
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

#define REG_APE_NCSI_SIG ((volatile BCM5719_APE_H_uint32_t*)0xc0014800) /* Set to NCSI_MAGIC ('NCSI') by APE firmware. NOTE: all words in the NCSI section are available in the function 0 SHM area only. */
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

#define REG_APE_CHIP_ID ((volatile BCM5719_APE_H_uint32_t*)0xc0014890) /* The APE code copies the contents of Chip ID to this word */
/** @brief Register definition for @ref APE_t.ChipId. */
typedef register_container RegAPEChipId_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPEChipId_t;

#define REG_APE_NCSI_CHANNEL0_INFO ((volatile BCM5719_APE_H_uint32_t*)0xc0014900) /*  */
#define     APE_NCSI_CHANNEL0_INFO_ENABLED_SHIFT 0u
#define     APE_NCSI_CHANNEL0_INFO_ENABLED_MASK  0x1u
#define GET_APE_NCSI_CHANNEL0_INFO_ENABLED(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_NCSI_CHANNEL0_INFO_ENABLED(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_NCSI_CHANNEL0_INFO_TX_PASSTHROUGH_SHIFT 1u
#define     APE_NCSI_CHANNEL0_INFO_TX_PASSTHROUGH_MASK  0x2u
#define GET_APE_NCSI_CHANNEL0_INFO_TX_PASSTHROUGH(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_NCSI_CHANNEL0_INFO_TX_PASSTHROUGH(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_NCSI_CHANNEL0_INFO_READY_SHIFT 2u
#define     APE_NCSI_CHANNEL0_INFO_READY_MASK  0x4u
#define GET_APE_NCSI_CHANNEL0_INFO_READY(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_NCSI_CHANNEL0_INFO_READY(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_NCSI_CHANNEL0_INFO_INIT_SHIFT 3u
#define     APE_NCSI_CHANNEL0_INFO_INIT_MASK  0x8u
#define GET_APE_NCSI_CHANNEL0_INFO_INIT(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_NCSI_CHANNEL0_INFO_INIT(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_NCSI_CHANNEL0_INFO_MFILT_SHIFT 4u
#define     APE_NCSI_CHANNEL0_INFO_MFILT_MASK  0x10u
#define GET_APE_NCSI_CHANNEL0_INFO_MFILT(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_NCSI_CHANNEL0_INFO_MFILT(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_NCSI_CHANNEL0_INFO_BFILT_SHIFT 5u
#define     APE_NCSI_CHANNEL0_INFO_BFILT_MASK  0x20u
#define GET_APE_NCSI_CHANNEL0_INFO_BFILT(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_NCSI_CHANNEL0_INFO_BFILT(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_NCSI_CHANNEL0_INFO_SERDES_SHIFT 6u
#define     APE_NCSI_CHANNEL0_INFO_SERDES_MASK  0x40u
#define GET_APE_NCSI_CHANNEL0_INFO_SERDES(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_NCSI_CHANNEL0_INFO_SERDES(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_NCSI_CHANNEL0_INFO_VLAN_SHIFT 8u
#define     APE_NCSI_CHANNEL0_INFO_VLAN_MASK  0x100u
#define GET_APE_NCSI_CHANNEL0_INFO_VLAN(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_APE_NCSI_CHANNEL0_INFO_VLAN(__val__)  (((__val__) << 8u) & 0x100u)
#define     APE_NCSI_CHANNEL0_INFO_B2H_SHIFT 10u
#define     APE_NCSI_CHANNEL0_INFO_B2H_MASK  0x400u
#define GET_APE_NCSI_CHANNEL0_INFO_B2H(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_APE_NCSI_CHANNEL0_INFO_B2H(__val__)  (((__val__) << 10u) & 0x400u)
#define     APE_NCSI_CHANNEL0_INFO_B2N_SHIFT 11u
#define     APE_NCSI_CHANNEL0_INFO_B2N_MASK  0x800u
#define GET_APE_NCSI_CHANNEL0_INFO_B2N(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_APE_NCSI_CHANNEL0_INFO_B2N(__val__)  (((__val__) << 11u) & 0x800u)
#define     APE_NCSI_CHANNEL0_INFO_EEE_SHIFT 12u
#define     APE_NCSI_CHANNEL0_INFO_EEE_MASK  0x1000u
#define GET_APE_NCSI_CHANNEL0_INFO_EEE(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_NCSI_CHANNEL0_INFO_EEE(__val__)  (((__val__) << 12u) & 0x1000u)
#define     APE_NCSI_CHANNEL0_INFO_PDEAD_SHIFT 14u
#define     APE_NCSI_CHANNEL0_INFO_PDEAD_MASK  0x4000u
#define GET_APE_NCSI_CHANNEL0_INFO_PDEAD(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_APE_NCSI_CHANNEL0_INFO_PDEAD(__val__)  (((__val__) << 14u) & 0x4000u)
#define     APE_NCSI_CHANNEL0_INFO_DRIVER_SHIFT 14u
#define     APE_NCSI_CHANNEL0_INFO_DRIVER_MASK  0x4000u
#define GET_APE_NCSI_CHANNEL0_INFO_DRIVER(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_APE_NCSI_CHANNEL0_INFO_DRIVER(__val__)  (((__val__) << 14u) & 0x4000u)

/** @brief Register definition for @ref APE_t.NcsiChannel0Info. */
typedef register_container RegAPENcsiChannel0Info_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief This can be modified via NCSI SELECT PACKAGE and NCSI DESELECT PACKAGE. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Enabled, 0, 1)
        /** @brief TX passthrough has been enabled by BMC NCSI command. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, TXPassthrough, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Ready, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Init, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, MFILT, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BFILT, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, SERDES, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, VLAN, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_9_9, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, B2H, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, B2N, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, EEE, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_13_13, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PDead, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 14, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_15, 15, 17)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_15, 15, 17)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Driver, 14, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, PDead, 14, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_13_13, 13, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, EEE, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, B2N, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, B2H, 10, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_9_9, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, VLAN, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, SERDES, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, BFILT, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, MFILT, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Init, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Ready, 2, 1)
        /** @brief TX passthrough has been enabled by BMC NCSI command. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, TXPassthrough, 1, 1)
        /** @brief This can be modified via NCSI SELECT PACKAGE and NCSI DESELECT PACKAGE. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Enabled, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Info"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPENcsiChannel0Info_t()
    {
        /** @brief constructor for @ref APE_t.NcsiChannel0Info. */
        r32.setName("NcsiChannel0Info");
        bits.Enabled.setBaseRegister(&r32);
        bits.Enabled.setName("Enabled");
        bits.TXPassthrough.setBaseRegister(&r32);
        bits.TXPassthrough.setName("TXPassthrough");
        bits.Ready.setBaseRegister(&r32);
        bits.Ready.setName("Ready");
        bits.Init.setBaseRegister(&r32);
        bits.Init.setName("Init");
        bits.MFILT.setBaseRegister(&r32);
        bits.MFILT.setName("MFILT");
        bits.BFILT.setBaseRegister(&r32);
        bits.BFILT.setName("BFILT");
        bits.SERDES.setBaseRegister(&r32);
        bits.SERDES.setName("SERDES");
        bits.VLAN.setBaseRegister(&r32);
        bits.VLAN.setName("VLAN");
        bits.B2H.setBaseRegister(&r32);
        bits.B2H.setName("B2H");
        bits.B2N.setBaseRegister(&r32);
        bits.B2N.setName("B2N");
        bits.EEE.setBaseRegister(&r32);
        bits.EEE.setName("EEE");
        bits.PDead.setBaseRegister(&r32);
        bits.PDead.setName("PDead");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPENcsiChannel0Info_t& operator=(const RegAPENcsiChannel0Info_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPENcsiChannel0Info_t;

#define REG_APE_NCSI_CHANNEL0_MCID ((volatile BCM5719_APE_H_uint32_t*)0xc0014904) /* AEN Management Controller ID, set by BMC when sending AEN ENABLE command and used when sending AENs. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mcid. */
typedef register_container RegAPENcsiChannel0Mcid_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mcid_t;

#define REG_APE_NCSI_CHANNEL0_AEN ((volatile BCM5719_APE_H_uint32_t*)0xc0014908) /* Set via NCSI ENABLE AEN. */
#define     APE_NCSI_CHANNEL0_AEN_ENABLE_LINK_STATUS_CHANGE_AEN_SHIFT 0u
#define     APE_NCSI_CHANNEL0_AEN_ENABLE_LINK_STATUS_CHANGE_AEN_MASK  0x1u
#define GET_APE_NCSI_CHANNEL0_AEN_ENABLE_LINK_STATUS_CHANGE_AEN(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_NCSI_CHANNEL0_AEN_ENABLE_LINK_STATUS_CHANGE_AEN(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_NCSI_CHANNEL0_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN_SHIFT 1u
#define     APE_NCSI_CHANNEL0_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN_MASK  0x2u
#define GET_APE_NCSI_CHANNEL0_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_NCSI_CHANNEL0_AEN_ENABLE_CONFIGURATION_REQUIRED_AEN(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_NCSI_CHANNEL0_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN_SHIFT 2u
#define     APE_NCSI_CHANNEL0_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN_MASK  0x4u
#define GET_APE_NCSI_CHANNEL0_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_NCSI_CHANNEL0_AEN_ENABLE_HOST_NC_DRIVER_STATUS_CHANGE_AEN(__val__)  (((__val__) << 2u) & 0x4u)

/** @brief Register definition for @ref APE_t.NcsiChannel0Aen. */
typedef register_container RegAPENcsiChannel0Aen_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, EnableLinkStatusChangeAEN, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, EnableConfigurationRequiredAEN, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, EnableHostNCDriverStatusChangeAEN, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_3, 3, 29)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_3, 3, 29)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, EnableHostNCDriverStatusChangeAEN, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, EnableConfigurationRequiredAEN, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, EnableLinkStatusChangeAEN, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Aen"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPENcsiChannel0Aen_t()
    {
        /** @brief constructor for @ref APE_t.NcsiChannel0Aen. */
        r32.setName("NcsiChannel0Aen");
        bits.EnableLinkStatusChangeAEN.setBaseRegister(&r32);
        bits.EnableLinkStatusChangeAEN.setName("EnableLinkStatusChangeAEN");
        bits.EnableConfigurationRequiredAEN.setBaseRegister(&r32);
        bits.EnableConfigurationRequiredAEN.setName("EnableConfigurationRequiredAEN");
        bits.EnableHostNCDriverStatusChangeAEN.setBaseRegister(&r32);
        bits.EnableHostNCDriverStatusChangeAEN.setName("EnableHostNCDriverStatusChangeAEN");
    }
    RegAPENcsiChannel0Aen_t& operator=(const RegAPENcsiChannel0Aen_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPENcsiChannel0Aen_t;

#define REG_APE_NCSI_CHANNEL0_BFILT ((volatile BCM5719_APE_H_uint32_t*)0xc001490c) /*  */
#define     APE_NCSI_CHANNEL0_BFILT_ARP_PACKET_SHIFT 0u
#define     APE_NCSI_CHANNEL0_BFILT_ARP_PACKET_MASK  0x1u
#define GET_APE_NCSI_CHANNEL0_BFILT_ARP_PACKET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_NCSI_CHANNEL0_BFILT_ARP_PACKET(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_NCSI_CHANNEL0_BFILT_DHCP_CLIENT_PACKET_SHIFT 1u
#define     APE_NCSI_CHANNEL0_BFILT_DHCP_CLIENT_PACKET_MASK  0x2u
#define GET_APE_NCSI_CHANNEL0_BFILT_DHCP_CLIENT_PACKET(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_NCSI_CHANNEL0_BFILT_DHCP_CLIENT_PACKET(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_NCSI_CHANNEL0_BFILT_DHCP_SERVER_PACKET_SHIFT 2u
#define     APE_NCSI_CHANNEL0_BFILT_DHCP_SERVER_PACKET_MASK  0x4u
#define GET_APE_NCSI_CHANNEL0_BFILT_DHCP_SERVER_PACKET(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_NCSI_CHANNEL0_BFILT_DHCP_SERVER_PACKET(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_NCSI_CHANNEL0_BFILT_NETBIOS_PACKET_SHIFT 3u
#define     APE_NCSI_CHANNEL0_BFILT_NETBIOS_PACKET_MASK  0x8u
#define GET_APE_NCSI_CHANNEL0_BFILT_NETBIOS_PACKET(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_NCSI_CHANNEL0_BFILT_NETBIOS_PACKET(__val__)  (((__val__) << 3u) & 0x8u)

/** @brief Register definition for @ref APE_t.NcsiChannel0Bfilt. */
typedef register_container RegAPENcsiChannel0Bfilt_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ARPPacket, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, DHCPClientPacket, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, DHCPServerPacket, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, NetBIOSPacket, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_4, 4, 28)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_4, 4, 28)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, NetBIOSPacket, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, DHCPServerPacket, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, DHCPClientPacket, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, ARPPacket, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Bfilt"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPENcsiChannel0Bfilt_t()
    {
        /** @brief constructor for @ref APE_t.NcsiChannel0Bfilt. */
        r32.setName("NcsiChannel0Bfilt");
        bits.ARPPacket.setBaseRegister(&r32);
        bits.ARPPacket.setName("ARPPacket");
        bits.DHCPClientPacket.setBaseRegister(&r32);
        bits.DHCPClientPacket.setName("DHCPClientPacket");
        bits.DHCPServerPacket.setBaseRegister(&r32);
        bits.DHCPServerPacket.setName("DHCPServerPacket");
        bits.NetBIOSPacket.setBaseRegister(&r32);
        bits.NetBIOSPacket.setName("NetBIOSPacket");
    }
    RegAPENcsiChannel0Bfilt_t& operator=(const RegAPENcsiChannel0Bfilt_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPENcsiChannel0Bfilt_t;

#define REG_APE_NCSI_CHANNEL0_MFILT ((volatile BCM5719_APE_H_uint32_t*)0xc0014910) /*  */
#define     APE_NCSI_CHANNEL0_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT_SHIFT 0u
#define     APE_NCSI_CHANNEL0_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT_MASK  0x1u
#define GET_APE_NCSI_CHANNEL0_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_NCSI_CHANNEL0_MFILT_IPV6_NEIGHBOUR_ADVERTISEMENT(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_NCSI_CHANNEL0_MFILT_IPV6_ROUTER_ADVERTISEMENT_SHIFT 1u
#define     APE_NCSI_CHANNEL0_MFILT_IPV6_ROUTER_ADVERTISEMENT_MASK  0x2u
#define GET_APE_NCSI_CHANNEL0_MFILT_IPV6_ROUTER_ADVERTISEMENT(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_NCSI_CHANNEL0_MFILT_IPV6_ROUTER_ADVERTISEMENT(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_NCSI_CHANNEL0_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST_SHIFT 2u
#define     APE_NCSI_CHANNEL0_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST_MASK  0x4u
#define GET_APE_NCSI_CHANNEL0_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_NCSI_CHANNEL0_MFILT_DHCPV6_RELAY_AND_SERVER_MULTICAST(__val__)  (((__val__) << 2u) & 0x4u)

/** @brief Register definition for @ref APE_t.NcsiChannel0Mfilt. */
typedef register_container RegAPENcsiChannel0Mfilt_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, IPv6NeighbourAdvertisement, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, IPv6RouterAdvertisement, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, DHCPv6RelayandServerMulticast, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_3, 3, 29)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_3, 3, 29)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, DHCPv6RelayandServerMulticast, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, IPv6RouterAdvertisement, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, IPv6NeighbourAdvertisement, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Mfilt"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPENcsiChannel0Mfilt_t()
    {
        /** @brief constructor for @ref APE_t.NcsiChannel0Mfilt. */
        r32.setName("NcsiChannel0Mfilt");
        bits.IPv6NeighbourAdvertisement.setBaseRegister(&r32);
        bits.IPv6NeighbourAdvertisement.setName("IPv6NeighbourAdvertisement");
        bits.IPv6RouterAdvertisement.setBaseRegister(&r32);
        bits.IPv6RouterAdvertisement.setName("IPv6RouterAdvertisement");
        bits.DHCPv6RelayandServerMulticast.setBaseRegister(&r32);
        bits.DHCPv6RelayandServerMulticast.setName("DHCPv6RelayandServerMulticast");
    }
    RegAPENcsiChannel0Mfilt_t& operator=(const RegAPENcsiChannel0Mfilt_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPENcsiChannel0Mfilt_t;

#define REG_APE_NCSI_CHANNEL0_SETTING_1 ((volatile BCM5719_APE_H_uint32_t*)0xc0014914) /* This is the "Link Settings" value from NCSI Set Link. */
#define     APE_NCSI_CHANNEL0_SETTING_1_AUTONEGOTIATION_ENABLED_SHIFT 0u
#define     APE_NCSI_CHANNEL0_SETTING_1_AUTONEGOTIATION_ENABLED_MASK  0x1u
#define GET_APE_NCSI_CHANNEL0_SETTING_1_AUTONEGOTIATION_ENABLED(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_NCSI_CHANNEL0_SETTING_1_AUTONEGOTIATION_ENABLED(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10M_ENABLE_SHIFT 1u
#define     APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10M_ENABLE_MASK  0x2u
#define GET_APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10M_ENABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10M_ENABLE(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_100M_ENABLE_SHIFT 2u
#define     APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_100M_ENABLE_MASK  0x4u
#define GET_APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_100M_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_100M_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_1000M_ENABLE_SHIFT 3u
#define     APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_1000M_ENABLE_MASK  0x8u
#define GET_APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_1000M_ENABLE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_1000M_ENABLE(__val__)  (((__val__) << 3u) & 0x8u)
#define     APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10G_ENABLE_SHIFT 4u
#define     APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10G_ENABLE_MASK  0x10u
#define GET_APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10G_ENABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_NCSI_CHANNEL0_SETTING_1_LINK_SPEED_10G_ENABLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_NCSI_CHANNEL0_SETTING_1_HALF_DUPLEX_ENABLE_SHIFT 8u
#define     APE_NCSI_CHANNEL0_SETTING_1_HALF_DUPLEX_ENABLE_MASK  0x100u
#define GET_APE_NCSI_CHANNEL0_SETTING_1_HALF_DUPLEX_ENABLE(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_APE_NCSI_CHANNEL0_SETTING_1_HALF_DUPLEX_ENABLE(__val__)  (((__val__) << 8u) & 0x100u)
#define     APE_NCSI_CHANNEL0_SETTING_1_FULL_DUPLEX_ENABLE_SHIFT 9u
#define     APE_NCSI_CHANNEL0_SETTING_1_FULL_DUPLEX_ENABLE_MASK  0x200u
#define GET_APE_NCSI_CHANNEL0_SETTING_1_FULL_DUPLEX_ENABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_APE_NCSI_CHANNEL0_SETTING_1_FULL_DUPLEX_ENABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     APE_NCSI_CHANNEL0_SETTING_1_PAUSE_CAPABILITY_ENABLE_SHIFT 10u
#define     APE_NCSI_CHANNEL0_SETTING_1_PAUSE_CAPABILITY_ENABLE_MASK  0x400u
#define GET_APE_NCSI_CHANNEL0_SETTING_1_PAUSE_CAPABILITY_ENABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_APE_NCSI_CHANNEL0_SETTING_1_PAUSE_CAPABILITY_ENABLE(__val__)  (((__val__) << 10u) & 0x400u)
#define     APE_NCSI_CHANNEL0_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE_SHIFT 11u
#define     APE_NCSI_CHANNEL0_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE_MASK  0x800u
#define GET_APE_NCSI_CHANNEL0_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_APE_NCSI_CHANNEL0_SETTING_1_ASYMMETRIC_PAUSE_CAPABILITY_ENABLE(__val__)  (((__val__) << 11u) & 0x800u)
#define     APE_NCSI_CHANNEL0_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID_SHIFT 12u
#define     APE_NCSI_CHANNEL0_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID_MASK  0x1000u
#define GET_APE_NCSI_CHANNEL0_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_NCSI_CHANNEL0_SETTING_1_OEM_LINK_SETTINGS_FIELD_VALID(__val__)  (((__val__) << 12u) & 0x1000u)

/** @brief Register definition for @ref APE_t.NcsiChannel0Setting1. */
typedef register_container RegAPENcsiChannel0Setting1_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Autonegotiationenabled, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkSpeed10Menable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkSpeed100Menable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkSpeed1000Menable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkSpeed10Genable, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Halfduplexenable, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Fullduplexenable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Pausecapabilityenable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Asymmetricpausecapabilityenable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, OEMlinksettingsfieldvalid, 12, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_13, 13, 19)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, OEMlinksettingsfieldvalid, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Asymmetricpausecapabilityenable, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Pausecapabilityenable, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Fullduplexenable, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Halfduplexenable, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkSpeed10Genable, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkSpeed1000Menable, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkSpeed100Menable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkSpeed10Menable, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Autonegotiationenabled, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Setting1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPENcsiChannel0Setting1_t()
    {
        /** @brief constructor for @ref APE_t.NcsiChannel0Setting1. */
        r32.setName("NcsiChannel0Setting1");
        bits.Autonegotiationenabled.setBaseRegister(&r32);
        bits.Autonegotiationenabled.setName("Autonegotiationenabled");
        bits.LinkSpeed10Menable.setBaseRegister(&r32);
        bits.LinkSpeed10Menable.setName("LinkSpeed10Menable");
        bits.LinkSpeed100Menable.setBaseRegister(&r32);
        bits.LinkSpeed100Menable.setName("LinkSpeed100Menable");
        bits.LinkSpeed1000Menable.setBaseRegister(&r32);
        bits.LinkSpeed1000Menable.setName("LinkSpeed1000Menable");
        bits.LinkSpeed10Genable.setBaseRegister(&r32);
        bits.LinkSpeed10Genable.setName("LinkSpeed10Genable");
        bits.Halfduplexenable.setBaseRegister(&r32);
        bits.Halfduplexenable.setName("Halfduplexenable");
        bits.Fullduplexenable.setBaseRegister(&r32);
        bits.Fullduplexenable.setName("Fullduplexenable");
        bits.Pausecapabilityenable.setBaseRegister(&r32);
        bits.Pausecapabilityenable.setName("Pausecapabilityenable");
        bits.Asymmetricpausecapabilityenable.setBaseRegister(&r32);
        bits.Asymmetricpausecapabilityenable.setName("Asymmetricpausecapabilityenable");
        bits.OEMlinksettingsfieldvalid.setBaseRegister(&r32);
        bits.OEMlinksettingsfieldvalid.setName("OEMlinksettingsfieldvalid");
    }
    RegAPENcsiChannel0Setting1_t& operator=(const RegAPENcsiChannel0Setting1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPENcsiChannel0Setting1_t;

#define REG_APE_NCSI_CHANNEL0_SETTING_2 ((volatile BCM5719_APE_H_uint32_t*)0xc0014918) /* This is the "OEM Settings" value from NCSI Set Link. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Setting2. */
typedef register_container RegAPENcsiChannel0Setting2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Setting2_t;

#define REG_APE_NCSI_CHANNEL0_VLAN ((volatile BCM5719_APE_H_uint32_t*)0xc001491c) /* Receives VLAN mode from NCSI specification "Enable VLAN" command. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Vlan. */
typedef register_container RegAPENcsiChannel0Vlan_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Vlan_t;

#define REG_APE_NCSI_CHANNEL0_ALT_HOST_MAC_HIGH ((volatile BCM5719_APE_H_uint32_t*)0xc0014924) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0AltHostMacHigh. */
typedef register_container RegAPENcsiChannel0AltHostMacHigh_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0AltHostMacHigh_t;

#define REG_APE_NCSI_CHANNEL0_ALT_HOST_MAC_MID ((volatile BCM5719_APE_H_uint32_t*)0xc0014928) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0AltHostMacMid. */
typedef register_container RegAPENcsiChannel0AltHostMacMid_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0AltHostMacMid_t;

#define REG_APE_NCSI_CHANNEL0_ALT_HOST_MAC_LOW ((volatile BCM5719_APE_H_uint32_t*)0xc001492c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0AltHostMacLow. */
typedef register_container RegAPENcsiChannel0AltHostMacLow_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0AltHostMacLow_t;

#define REG_APE_NCSI_CHANNEL0_MAC0_HIGH ((volatile BCM5719_APE_H_uint32_t*)0xc0014934) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac0High. */
typedef register_container RegAPENcsiChannel0Mac0High_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac0High_t;

#define REG_APE_NCSI_CHANNEL0_MAC0_MID ((volatile BCM5719_APE_H_uint32_t*)0xc0014938) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac0Mid. */
typedef register_container RegAPENcsiChannel0Mac0Mid_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac0Mid_t;

#define REG_APE_NCSI_CHANNEL0_MAC0_LOW ((volatile BCM5719_APE_H_uint32_t*)0xc001493c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac0Low. */
typedef register_container RegAPENcsiChannel0Mac0Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac0Low_t;

#define REG_APE_NCSI_CHANNEL0_MAC1_HIGH ((volatile BCM5719_APE_H_uint32_t*)0xc0014944) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac1High. */
typedef register_container RegAPENcsiChannel0Mac1High_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac1High_t;

#define REG_APE_NCSI_CHANNEL0_MAC1_MID ((volatile BCM5719_APE_H_uint32_t*)0xc0014948) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac1Mid. */
typedef register_container RegAPENcsiChannel0Mac1Mid_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac1Mid_t;

#define REG_APE_NCSI_CHANNEL0_MAC1_LOW ((volatile BCM5719_APE_H_uint32_t*)0xc001494c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac1Low. */
typedef register_container RegAPENcsiChannel0Mac1Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac1Low_t;

#define REG_APE_NCSI_CHANNEL0_MAC2_HIGH ((volatile BCM5719_APE_H_uint32_t*)0xc0014954) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac2High. */
typedef register_container RegAPENcsiChannel0Mac2High_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac2High_t;

#define REG_APE_NCSI_CHANNEL0_MAC2_MID ((volatile BCM5719_APE_H_uint32_t*)0xc0014958) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac2Mid. */
typedef register_container RegAPENcsiChannel0Mac2Mid_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac2Mid_t;

#define REG_APE_NCSI_CHANNEL0_MAC2_LOW ((volatile BCM5719_APE_H_uint32_t*)0xc001495c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac2Low. */
typedef register_container RegAPENcsiChannel0Mac2Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac2Low_t;

#define REG_APE_NCSI_CHANNEL0_MAC3_HIGH ((volatile BCM5719_APE_H_uint32_t*)0xc0014964) /* Lower 16 bits of this word contains upper 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac3High. */
typedef register_container RegAPENcsiChannel0Mac3High_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac3High_t;

#define REG_APE_NCSI_CHANNEL0_MAC3_MID ((volatile BCM5719_APE_H_uint32_t*)0xc0014968) /* Lower 16 bits of this word contains mid 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac3Mid. */
typedef register_container RegAPENcsiChannel0Mac3Mid_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac3Mid_t;

#define REG_APE_NCSI_CHANNEL0_MAC3_LOW ((volatile BCM5719_APE_H_uint32_t*)0xc001496c) /* Lower 16 bits of this word contains low 16 bits of the MAC. */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac3Low. */
typedef register_container RegAPENcsiChannel0Mac3Low_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac3Low_t;

#define REG_APE_NCSI_CHANNEL0_MAC0_VLAN_VALID ((volatile BCM5719_APE_H_uint32_t*)0xc0014970) /* Nonzero indicates VLAN field is valid */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac0VlanValid. */
typedef register_container RegAPENcsiChannel0Mac0VlanValid_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac0VlanValid_t;

#define REG_APE_NCSI_CHANNEL0_MAC0_VLAN ((volatile BCM5719_APE_H_uint32_t*)0xc0014974) /*  */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac0Vlan. */
typedef register_container RegAPENcsiChannel0Mac0Vlan_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac0Vlan_t;

#define REG_APE_NCSI_CHANNEL0_MAC1_VLAN_VALID ((volatile BCM5719_APE_H_uint32_t*)0xc0014978) /* Nonzero indicates VLAN field is valid */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac1VlanValid. */
typedef register_container RegAPENcsiChannel0Mac1VlanValid_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac1VlanValid_t;

#define REG_APE_NCSI_CHANNEL0_MAC1_VLAN ((volatile BCM5719_APE_H_uint32_t*)0xc001497c) /*  */
/** @brief Register definition for @ref APE_t.NcsiChannel0Mac1Vlan. */
typedef register_container RegAPENcsiChannel0Mac1Vlan_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Mac1Vlan_t;

#define REG_APE_NCSI_CHANNEL0_STATUS ((volatile BCM5719_APE_H_uint32_t*)0xc0014980) /*  */
#define     APE_NCSI_CHANNEL0_STATUS_LINK_UP_SHIFT 0u
#define     APE_NCSI_CHANNEL0_STATUS_LINK_UP_MASK  0x1u
#define GET_APE_NCSI_CHANNEL0_STATUS_LINK_UP(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_NCSI_CHANNEL0_STATUS_LINK_UP(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_NCSI_CHANNEL0_STATUS_LINK_STATUS_SHIFT 1u
#define     APE_NCSI_CHANNEL0_STATUS_LINK_STATUS_MASK  0x1eu
#define GET_APE_NCSI_CHANNEL0_STATUS_LINK_STATUS(__reg__)  (((__reg__) & 0x1e) >> 1u)
#define SET_APE_NCSI_CHANNEL0_STATUS_LINK_STATUS(__val__)  (((__val__) << 1u) & 0x1eu)
#define     APE_NCSI_CHANNEL0_STATUS_SERDES_SHIFT 5u
#define     APE_NCSI_CHANNEL0_STATUS_SERDES_MASK  0x20u
#define GET_APE_NCSI_CHANNEL0_STATUS_SERDES(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_NCSI_CHANNEL0_STATUS_SERDES(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_NCSI_CHANNEL0_STATUS_AUTONEGOTIATION_COMPLETE_SHIFT 6u
#define     APE_NCSI_CHANNEL0_STATUS_AUTONEGOTIATION_COMPLETE_MASK  0x40u
#define GET_APE_NCSI_CHANNEL0_STATUS_AUTONEGOTIATION_COMPLETE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_NCSI_CHANNEL0_STATUS_AUTONEGOTIATION_COMPLETE(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE_SHIFT 9u
#define     APE_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE_MASK  0x200u
#define GET_APE_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_APE_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_FULL_DUPLEX_CAPABLE(__val__)  (((__val__) << 9u) & 0x200u)
#define     APE_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_HALS_DUPLEX_CAPABLE_SHIFT 10u
#define     APE_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_HALS_DUPLEX_CAPABLE_MASK  0x400u
#define GET_APE_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_HALS_DUPLEX_CAPABLE(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_APE_NCSI_CHANNEL0_STATUS_LINK_SPEED_1000M_HALS_DUPLEX_CAPABLE(__val__)  (((__val__) << 10u) & 0x400u)

/** @brief Register definition for @ref APE_t.NcsiChannel0Status. */
typedef register_container RegAPENcsiChannel0Status_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Linkup, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkStatus, 1, 4)
        /** @brief Set from MII_REG_CONTROL__AUTO_NEGOTIATION_ENABLE. Set unconditionally in SERDES case. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, SERDES, 5, 1)
        /** @brief Set if autonegotiation is complete. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, AutonegotiationComplete, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_8_7, 7, 2)
        /** @brief Link partner 1000BASE-T full duplex capable */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkSpeed1000MFullDuplexCapable, 9, 1)
        /** @brief Link partner 1000BASE-T half duplex capable */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkSpeed1000MHalsDuplexCapable, 10, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_11, 11, 21)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_31_11, 11, 21)
        /** @brief Link partner 1000BASE-T half duplex capable */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkSpeed1000MHalsDuplexCapable, 10, 1)
        /** @brief Link partner 1000BASE-T full duplex capable */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkSpeed1000MFullDuplexCapable, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, reserved_8_7, 7, 2)
        /** @brief Set if autonegotiation is complete. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, AutonegotiationComplete, 6, 1)
        /** @brief Set from MII_REG_CONTROL__AUTO_NEGOTIATION_ENABLE. Set unconditionally in SERDES case. */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, SERDES, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, LinkStatus, 1, 4)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_APE_H_uint32_t, Linkup, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NcsiChannel0Status"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPENcsiChannel0Status_t()
    {
        /** @brief constructor for @ref APE_t.NcsiChannel0Status. */
        r32.setName("NcsiChannel0Status");
        bits.Linkup.setBaseRegister(&r32);
        bits.Linkup.setName("Linkup");
        bits.LinkStatus.setBaseRegister(&r32);
        bits.LinkStatus.setName("LinkStatus");
        bits.SERDES.setBaseRegister(&r32);
        bits.SERDES.setName("SERDES");
        bits.AutonegotiationComplete.setBaseRegister(&r32);
        bits.AutonegotiationComplete.setName("AutonegotiationComplete");
        bits.LinkSpeed1000MFullDuplexCapable.setBaseRegister(&r32);
        bits.LinkSpeed1000MFullDuplexCapable.setName("LinkSpeed1000MFullDuplexCapable");
        bits.LinkSpeed1000MHalsDuplexCapable.setBaseRegister(&r32);
        bits.LinkSpeed1000MHalsDuplexCapable.setName("LinkSpeed1000MHalsDuplexCapable");
    }
    RegAPENcsiChannel0Status_t& operator=(const RegAPENcsiChannel0Status_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPENcsiChannel0Status_t;

#define REG_APE_NCSI_CHANNEL0_RESET_COUNT ((volatile BCM5719_APE_H_uint32_t*)0xc0014984) /*  */
/** @brief Register definition for @ref APE_t.NcsiChannel0ResetCount. */
typedef register_container RegAPENcsiChannel0ResetCount_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0ResetCount_t;

#define REG_APE_NCSI_CHANNEL0_PXE ((volatile BCM5719_APE_H_uint32_t*)0xc0014988) /*  */
/** @brief Register definition for @ref APE_t.NcsiChannel0Pxe. */
typedef register_container RegAPENcsiChannel0Pxe_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Pxe_t;

#define REG_APE_NCSI_CHANNEL0_DROPFIL ((volatile BCM5719_APE_H_uint32_t*)0xc001498c) /*  */
/** @brief Register definition for @ref APE_t.NcsiChannel0Dropfil. */
typedef register_container RegAPENcsiChannel0Dropfil_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Dropfil_t;

#define REG_APE_NCSI_CHANNEL0_SLINK ((volatile BCM5719_APE_H_uint32_t*)0xc0014990) /*  */
/** @brief Register definition for @ref APE_t.NcsiChannel0Slink. */
typedef register_container RegAPENcsiChannel0Slink_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Slink_t;

#define REG_APE_NCSI_CHANNEL0_DBG ((volatile BCM5719_APE_H_uint32_t*)0xc00149a0) /*  */
/** @brief Register definition for @ref APE_t.NcsiChannel0Dbg. */
typedef register_container RegAPENcsiChannel0Dbg_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0Dbg_t;

#define REG_APE_NCSI_CHANNEL0_CTRLSTAT_RX ((volatile BCM5719_APE_H_uint32_t*)0xc00149b0) /*  */
/** @brief Register definition for @ref APE_t.NcsiChannel0CtrlstatRx. */
typedef register_container RegAPENcsiChannel0CtrlstatRx_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
} RegAPENcsiChannel0CtrlstatRx_t;

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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
    }
    RegAPEPerLockGrantPhy1_t& operator=(const RegAPEPerLockGrantPhy1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEPerLockGrantPhy1_t;

#define REG_APE_PER_LOCK_GRANT_PHY2 ((volatile BCM5719_APE_H_uint32_t*)0xc001842c) /*  */
/** @brief Register definition for @ref APE_t.PerLockGrantPhy2. */
typedef register_container RegAPEPerLockGrantPhy2_t {
    /** @brief 32bit direct register access. */
    BCM5719_APE_H_uint32_t r32;
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
        bits.APE.setBaseRegister(&r32);
        bits.APE.setName("APE");
        bits.Function1.setBaseRegister(&r32);
        bits.Function1.setName("Function1");
        bits.Function2.setBaseRegister(&r32);
        bits.Function2.setName("Function2");
        bits.Function3.setBaseRegister(&r32);
        bits.Function3.setName("Function3");
        bits.Bootcode.setBaseRegister(&r32);
        bits.Bootcode.setName("Bootcode");
        bits.Driver.setBaseRegister(&r32);
        bits.Driver.setName("Driver");
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
    RegAPERcpuApeResetCount_t RcpuApeResetCount;

    /** @brief Unknown. Written by frobnicating routine. */
    RegAPERcpuLastApeStatus_t RcpuLastApeStatus;

    /** @brief Unknown.  */
    RegAPERcpuLastApeFwStatus_t RcpuLastApeFwStatus;

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

    /** @brief Set to NCSI_MAGIC ('NCSI') by APE firmware. NOTE: all words in the NCSI section are available in the function 0 SHM area only. */
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

    /** @brief The APE code copies the contents of Chip ID to this word */
    RegAPEChipId_t ChipId;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_18580[27];

    /** @brief  */
    RegAPENcsiChannel0Info_t NcsiChannel0Info;

    /** @brief AEN Management Controller ID, set by BMC when sending AEN ENABLE command and used when sending AENs. */
    RegAPENcsiChannel0Mcid_t NcsiChannel0Mcid;

    /** @brief Set via NCSI ENABLE AEN. */
    RegAPENcsiChannel0Aen_t NcsiChannel0Aen;

    /** @brief  */
    RegAPENcsiChannel0Bfilt_t NcsiChannel0Bfilt;

    /** @brief  */
    RegAPENcsiChannel0Mfilt_t NcsiChannel0Mfilt;

    /** @brief This is the "Link Settings" value from NCSI Set Link. */
    RegAPENcsiChannel0Setting1_t NcsiChannel0Setting1;

    /** @brief This is the "OEM Settings" value from NCSI Set Link. */
    RegAPENcsiChannel0Setting2_t NcsiChannel0Setting2;

    /** @brief Receives VLAN mode from NCSI specification "Enable VLAN" command. */
    RegAPENcsiChannel0Vlan_t NcsiChannel0Vlan;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_18720[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegAPENcsiChannel0AltHostMacHigh_t NcsiChannel0AltHostMacHigh;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegAPENcsiChannel0AltHostMacMid_t NcsiChannel0AltHostMacMid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegAPENcsiChannel0AltHostMacLow_t NcsiChannel0AltHostMacLow;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_18736[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegAPENcsiChannel0Mac0High_t NcsiChannel0Mac0High;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegAPENcsiChannel0Mac0Mid_t NcsiChannel0Mac0Mid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegAPENcsiChannel0Mac0Low_t NcsiChannel0Mac0Low;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_18752[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegAPENcsiChannel0Mac1High_t NcsiChannel0Mac1High;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegAPENcsiChannel0Mac1Mid_t NcsiChannel0Mac1Mid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegAPENcsiChannel0Mac1Low_t NcsiChannel0Mac1Low;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_18768[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegAPENcsiChannel0Mac2High_t NcsiChannel0Mac2High;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegAPENcsiChannel0Mac2Mid_t NcsiChannel0Mac2Mid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegAPENcsiChannel0Mac2Low_t NcsiChannel0Mac2Low;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_18784[1];

    /** @brief Lower 16 bits of this word contains upper 16 bits of the MAC. */
    RegAPENcsiChannel0Mac3High_t NcsiChannel0Mac3High;

    /** @brief Lower 16 bits of this word contains mid 16 bits of the MAC. */
    RegAPENcsiChannel0Mac3Mid_t NcsiChannel0Mac3Mid;

    /** @brief Lower 16 bits of this word contains low 16 bits of the MAC. */
    RegAPENcsiChannel0Mac3Low_t NcsiChannel0Mac3Low;

    /** @brief Nonzero indicates VLAN field is valid */
    RegAPENcsiChannel0Mac0VlanValid_t NcsiChannel0Mac0VlanValid;

    /** @brief  */
    RegAPENcsiChannel0Mac0Vlan_t NcsiChannel0Mac0Vlan;

    /** @brief Nonzero indicates VLAN field is valid */
    RegAPENcsiChannel0Mac1VlanValid_t NcsiChannel0Mac1VlanValid;

    /** @brief  */
    RegAPENcsiChannel0Mac1Vlan_t NcsiChannel0Mac1Vlan;

    /** @brief  */
    RegAPENcsiChannel0Status_t NcsiChannel0Status;

    /** @brief  */
    RegAPENcsiChannel0ResetCount_t NcsiChannel0ResetCount;

    /** @brief  */
    RegAPENcsiChannel0Pxe_t NcsiChannel0Pxe;

    /** @brief  */
    RegAPENcsiChannel0Dropfil_t NcsiChannel0Dropfil;

    /** @brief  */
    RegAPENcsiChannel0Slink_t NcsiChannel0Slink;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_18836[3];

    /** @brief  */
    RegAPENcsiChannel0Dbg_t NcsiChannel0Dbg;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_18852[3];

    /** @brief  */
    RegAPENcsiChannel0CtrlstatRx_t NcsiChannel0CtrlstatRx;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_APE_H_uint32_t reserved_18868[3731];

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
