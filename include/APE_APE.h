////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_APE.h
///
/// @project    ape
///
/// @brief      APE_APE
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

/** @defgroup APE_APE_H    APE_APE */
/** @addtogroup APE_APE_H
 * @{
 */
#ifndef APE_APE_H
#define APE_APE_H

#include <stdint.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_APE_sim(void* base);
void init_APE_APE(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_APE_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_APE_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_APE_H_uint32_t;
#define APE_APE_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_APE_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_APE_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_APE_H_uint8_t;
typedef uint16_t APE_APE_H_uint16_t;
typedef uint32_t APE_APE_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_APE_BASE ((volatile void*)0x60200000) /* Device APE Registers */
#define REG_APE_SIZE (sizeof(APE_t))

#define REG_APE_MODE ((volatile APE_APE_H_uint32_t*)0x60200000) /* More of these bits can be found in diagnostic utilities, but they don't seem too interesting. */
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
#define     APE_MODE_SWAP_ATB_DWORD_SHIFT 9u
#define     APE_MODE_SWAP_ATB_DWORD_MASK  0x200u
#define GET_APE_MODE_SWAP_ATB_DWORD(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_APE_MODE_SWAP_ATB_DWORD(__val__)  (((__val__) << 9u) & 0x200u)
#define     APE_MODE_SWAP_ARB_DWORD_SHIFT 11u
#define     APE_MODE_SWAP_ARB_DWORD_MASK  0x800u
#define GET_APE_MODE_SWAP_ARB_DWORD(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_APE_MODE_SWAP_ARB_DWORD(__val__)  (((__val__) << 11u) & 0x800u)
#define     APE_MODE_MEMORY_ECC_SHIFT 18u
#define     APE_MODE_MEMORY_ECC_MASK  0x40000u
#define GET_APE_MODE_MEMORY_ECC(__reg__)  (((__reg__) & 0x40000) >> 18u)
#define SET_APE_MODE_MEMORY_ECC(__val__)  (((__val__) << 18u) & 0x40000u)
#define     APE_MODE_ICODE_PIP_RD_DISABLE_SHIFT 19u
#define     APE_MODE_ICODE_PIP_RD_DISABLE_MASK  0x80000u
#define GET_APE_MODE_ICODE_PIP_RD_DISABLE(__reg__)  (((__reg__) & 0x80000) >> 19u)
#define SET_APE_MODE_ICODE_PIP_RD_DISABLE(__val__)  (((__val__) << 19u) & 0x80000u)

/** @brief Register definition for @ref APE_t.Mode. */
typedef register_container RegAPEMode_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Used to reset the APE block. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 0, 1)
        /** @brief APE is halted if set. Setting then unsetting this bit resets the APE to its reset vector, etc. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 1, 1)
        /** @brief Can be used to boot from RAM instead of NVM. Takes a full APE image with section headers, etc. so you still need to form a proper image. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FastBoot, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HostDiag, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_4_4, 4, 1)
        /** @brief Used to signal the APE that an event from the host is ready for processing in SHM. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Event1, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Event2, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, GRCint, 7, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_8_8, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, SwapATBdword, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_10_10, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, SwapARBdword, 11, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_17_12, 12, 6)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, MemoryECC, 18, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ICodePIPRdDisable, 19, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_20, 20, 12)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_20, 20, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ICodePIPRdDisable, 19, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, MemoryECC, 18, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_17_12, 12, 6)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, SwapARBdword, 11, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_10_10, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, SwapATBdword, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_8_8, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, GRCint, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Event2, 6, 1)
        /** @brief Used to signal the APE that an event from the host is ready for processing in SHM. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Event1, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_4_4, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HostDiag, 3, 1)
        /** @brief Can be used to boot from RAM instead of NVM. Takes a full APE image with section headers, etc. so you still need to form a proper image. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FastBoot, 2, 1)
        /** @brief APE is halted if set. Setting then unsetting this bit resets the APE to its reset vector, etc. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 1, 1)
        /** @brief Used to reset the APE block. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
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
        bits.SwapATBdword.setBaseRegister(&r32);
        bits.SwapATBdword.setName("SwapATBdword");
        bits.SwapARBdword.setBaseRegister(&r32);
        bits.SwapARBdword.setName("SwapARBdword");
        bits.MemoryECC.setBaseRegister(&r32);
        bits.MemoryECC.setName("MemoryECC");
        bits.ICodePIPRdDisable.setBaseRegister(&r32);
        bits.ICodePIPRdDisable.setName("ICodePIPRdDisable");
    }
    RegAPEMode_t& operator=(const RegAPEMode_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEMode_t;

#define REG_APE_STATUS ((volatile APE_APE_H_uint32_t*)0x60200004) /*  */
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
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PCIeReset, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_2_1, 1, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, NVRAMControlReset, 3, 1)
        /** @brief Indicates port is in D3 if set, otherwise the port is in D0-D2. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, LAN0Dstate, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, BootMode, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_8_6, 6, 3)
        /** @brief Indicates port is in D3 if set, otherwise the port is in D0-D2. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, LAN1Dstate, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_23_10, 10, 14)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, BootStatusB, 24, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, BootStatusA, 28, 4)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, BootStatusA, 28, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, BootStatusB, 24, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_23_10, 10, 14)
        /** @brief Indicates port is in D3 if set, otherwise the port is in D0-D2. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, LAN1Dstate, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_8_6, 6, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, BootMode, 5, 1)
        /** @brief Indicates port is in D3 if set, otherwise the port is in D0-D2. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, LAN0Dstate, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, NVRAMControlReset, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_2_1, 1, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PCIeReset, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
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

#define REG_APE_GPIO_MESSAGE ((volatile APE_APE_H_uint32_t*)0x60200008) /* Related to APE fastboot. In that case the value of it is an APE memory address in the code region. If Fast Boot is set, and the low two bits of this are not 0b10, ROM hangs (you have to OR 0x2 into the address). Otherwise, they are masked off and the resulting value is used as the reset vector. The resulting value is also stored in this register (i.e., the low two bits are cleared).  */
/** @brief Register definition for @ref APE_t.GpioMessage. */
typedef register_container RegAPEGpioMessage_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "GpioMessage"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEGpioMessage_t()
    {
        /** @brief constructor for @ref APE_t.GpioMessage. */
        r32.setName("GpioMessage");
    }
    RegAPEGpioMessage_t& operator=(const RegAPEGpioMessage_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEGpioMessage_t;

#define REG_APE_EVENT ((volatile APE_APE_H_uint32_t*)0x6020000c) /*  */
#define     APE_EVENT_1_SHIFT 0u
#define     APE_EVENT_1_MASK  0x1u
#define GET_APE_EVENT_1(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_EVENT_1(__val__)  (((__val__) << 0u) & 0x1u)

/** @brief Register definition for @ref APE_t.Event. */
typedef register_container RegAPEEvent_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Event 1 */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, _1, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_1, 1, 31)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_1, 1, 31)
        /** @brief Event 1 */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, _1, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
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

#define REG_APE_RXBUFOFFSET_FUNC0 ((volatile APE_APE_H_uint32_t*)0x60200014) /* This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. The fields are block numbers (block size 128 bytes). */
#define     APE_RXBUFOFFSET_FUNC0_TAIL_SHIFT 0u
#define     APE_RXBUFOFFSET_FUNC0_TAIL_MASK  0xfffu
#define GET_APE_RXBUFOFFSET_FUNC0_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_RXBUFOFFSET_FUNC0_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_RXBUFOFFSET_FUNC0_HEAD_SHIFT 12u
#define     APE_RXBUFOFFSET_FUNC0_HEAD_MASK  0xfff000u
#define GET_APE_RXBUFOFFSET_FUNC0_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_RXBUFOFFSET_FUNC0_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_RXBUFOFFSET_FUNC0_TO_HOST_SHIFT 24u
#define     APE_RXBUFOFFSET_FUNC0_TO_HOST_MASK  0x1000000u
#define GET_APE_RXBUFOFFSET_FUNC0_TO_HOST(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_APE_RXBUFOFFSET_FUNC0_TO_HOST(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     APE_RXBUFOFFSET_FUNC0_IP_FRAG_SHIFT 25u
#define     APE_RXBUFOFFSET_FUNC0_IP_FRAG_MASK  0x2000000u
#define GET_APE_RXBUFOFFSET_FUNC0_IP_FRAG(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_APE_RXBUFOFFSET_FUNC0_IP_FRAG(__val__)  (((__val__) << 25u) & 0x2000000u)
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
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ToHost, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, IPFrag, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 26, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Valid, 30, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Valid, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 26, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, IPFrag, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ToHost, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
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
        bits.ToHost.setBaseRegister(&r32);
        bits.ToHost.setName("ToHost");
        bits.IPFrag.setBaseRegister(&r32);
        bits.IPFrag.setName("IPFrag");
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

#define REG_APE_RXBUFOFFSET_FUNC1 ((volatile APE_APE_H_uint32_t*)0x60200018) /* This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
#define     APE_RXBUFOFFSET_FUNC1_TAIL_SHIFT 0u
#define     APE_RXBUFOFFSET_FUNC1_TAIL_MASK  0xfffu
#define GET_APE_RXBUFOFFSET_FUNC1_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_RXBUFOFFSET_FUNC1_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_RXBUFOFFSET_FUNC1_HEAD_SHIFT 12u
#define     APE_RXBUFOFFSET_FUNC1_HEAD_MASK  0xfff000u
#define GET_APE_RXBUFOFFSET_FUNC1_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_RXBUFOFFSET_FUNC1_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_RXBUFOFFSET_FUNC1_TO_HOST_SHIFT 24u
#define     APE_RXBUFOFFSET_FUNC1_TO_HOST_MASK  0x1000000u
#define GET_APE_RXBUFOFFSET_FUNC1_TO_HOST(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_APE_RXBUFOFFSET_FUNC1_TO_HOST(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     APE_RXBUFOFFSET_FUNC1_IP_FRAG_SHIFT 25u
#define     APE_RXBUFOFFSET_FUNC1_IP_FRAG_MASK  0x2000000u
#define GET_APE_RXBUFOFFSET_FUNC1_IP_FRAG(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_APE_RXBUFOFFSET_FUNC1_IP_FRAG(__val__)  (((__val__) << 25u) & 0x2000000u)
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
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ToHost, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, IPFrag, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 26, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Valid, 30, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Valid, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 26, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, IPFrag, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ToHost, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
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
        bits.ToHost.setBaseRegister(&r32);
        bits.ToHost.setName("ToHost");
        bits.IPFrag.setBaseRegister(&r32);
        bits.IPFrag.setName("IPFrag");
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

#define REG_APE_TX_TO_NET_DOORBELL_FUNC0 ((volatile APE_APE_H_uint32_t*)0x6020001c) /* Written on APE TX to network after filling 0xA002 buffer with packet. */
#define     APE_TX_TO_NET_DOORBELL_FUNC0_TAIL_SHIFT 0u
#define     APE_TX_TO_NET_DOORBELL_FUNC0_TAIL_MASK  0xfffu
#define GET_APE_TX_TO_NET_DOORBELL_FUNC0_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC0_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_TX_TO_NET_DOORBELL_FUNC0_HEAD_SHIFT 12u
#define     APE_TX_TO_NET_DOORBELL_FUNC0_HEAD_MASK  0xfff000u
#define GET_APE_TX_TO_NET_DOORBELL_FUNC0_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC0_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_TX_TO_NET_DOORBELL_FUNC0_LENGTH_SHIFT 24u
#define     APE_TX_TO_NET_DOORBELL_FUNC0_LENGTH_MASK  0xff000000u
#define GET_APE_TX_TO_NET_DOORBELL_FUNC0_LENGTH(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC0_LENGTH(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref APE_t.TxToNetDoorbellFunc0. */
typedef register_container RegAPETxToNetDoorbellFunc0_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Length, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Length, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetDoorbellFunc0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetDoorbellFunc0_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetDoorbellFunc0. */
        r32.setName("TxToNetDoorbellFunc0");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.Length.setBaseRegister(&r32);
        bits.Length.setName("Length");
    }
    RegAPETxToNetDoorbellFunc0_t& operator=(const RegAPETxToNetDoorbellFunc0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetDoorbellFunc0_t;

#define REG_APE_TX_STATE0 ((volatile APE_APE_H_uint32_t*)0x60200020) /* APE TX Status. */
#define     APE_TX_STATE0_TAIL_SHIFT 0u
#define     APE_TX_STATE0_TAIL_MASK  0xfffu
#define GET_APE_TX_STATE0_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_TX_STATE0_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_TX_STATE0_HEAD_SHIFT 12u
#define     APE_TX_STATE0_HEAD_MASK  0xfff000u
#define GET_APE_TX_STATE0_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_TX_STATE0_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_TX_STATE0_TXERROR_SHIFT 24u
#define     APE_TX_STATE0_TXERROR_MASK  0x1000000u
#define GET_APE_TX_STATE0_TXERROR(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_APE_TX_STATE0_TXERROR(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     APE_TX_STATE0_ERROR_CODE_SHIFT 25u
#define     APE_TX_STATE0_ERROR_CODE_MASK  0xe000000u
#define GET_APE_TX_STATE0_ERROR_CODE(__reg__)  (((__reg__) & 0xe000000) >> 25u)
#define SET_APE_TX_STATE0_ERROR_CODE(__val__)  (((__val__) << 25u) & 0xe000000u)

/** @brief Register definition for @ref APE_t.TxState0. */
typedef register_container RegAPETxState0_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, TXError, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ErrorCode, 25, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_28, 28, 4)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_28, 28, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ErrorCode, 25, 3)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, TXError, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxState0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxState0_t()
    {
        /** @brief constructor for @ref APE_t.TxState0. */
        r32.setName("TxState0");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.TXError.setBaseRegister(&r32);
        bits.TXError.setName("TXError");
        bits.ErrorCode.setBaseRegister(&r32);
        bits.ErrorCode.setName("ErrorCode");
    }
    RegAPETxState0_t& operator=(const RegAPETxState0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxState0_t;

#define REG_APE_MODE_2 ((volatile APE_APE_H_uint32_t*)0x6020002c) /* Expansion for MODE */
/** @brief Register definition for @ref APE_t.Mode2. */
typedef register_container RegAPEMode2_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Mode2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEMode2_t()
    {
        /** @brief constructor for @ref APE_t.Mode2. */
        r32.setName("Mode2");
    }
    RegAPEMode2_t& operator=(const RegAPEMode2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEMode2_t;

#define REG_APE_STATUS_2 ((volatile APE_APE_H_uint32_t*)0x60200030) /*  */
/** @brief Register definition for @ref APE_t.Status2. */
typedef register_container RegAPEStatus2_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Status2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEStatus2_t()
    {
        /** @brief constructor for @ref APE_t.Status2. */
        r32.setName("Status2");
    }
    RegAPEStatus2_t& operator=(const RegAPEStatus2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEStatus2_t;

#define REG_APE_LOCK_GRANT__OBSOLETE_ ((volatile APE_APE_H_uint32_t*)0x6020004c) /* See  */
/** @brief Register definition for @ref APE_t.LockGrantObsolete. */
typedef register_container RegAPELockGrantObsolete_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "LockGrantObsolete"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPELockGrantObsolete_t()
    {
        /** @brief constructor for @ref APE_t.LockGrantObsolete. */
        r32.setName("LockGrantObsolete");
    }
    RegAPELockGrantObsolete_t& operator=(const RegAPELockGrantObsolete_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPELockGrantObsolete_t;

#define REG_APE_RX_POOL_MODE_STATUS_0 ((volatile APE_APE_H_uint32_t*)0x60200078) /*  */
#define     APE_RX_POOL_MODE_STATUS_0_HALT_SHIFT 0u
#define     APE_RX_POOL_MODE_STATUS_0_HALT_MASK  0x1u
#define GET_APE_RX_POOL_MODE_STATUS_0_HALT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_RX_POOL_MODE_STATUS_0_HALT(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_RX_POOL_MODE_STATUS_0_HALT_DONE_SHIFT 1u
#define     APE_RX_POOL_MODE_STATUS_0_HALT_DONE_MASK  0x2u
#define GET_APE_RX_POOL_MODE_STATUS_0_HALT_DONE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_RX_POOL_MODE_STATUS_0_HALT_DONE(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_RX_POOL_MODE_STATUS_0_ENABLE_SHIFT 2u
#define     APE_RX_POOL_MODE_STATUS_0_ENABLE_MASK  0x4u
#define GET_APE_RX_POOL_MODE_STATUS_0_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_RX_POOL_MODE_STATUS_0_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_RX_POOL_MODE_STATUS_0_EMPTY_SHIFT 4u
#define     APE_RX_POOL_MODE_STATUS_0_EMPTY_MASK  0x10u
#define GET_APE_RX_POOL_MODE_STATUS_0_EMPTY(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_RX_POOL_MODE_STATUS_0_EMPTY(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_RX_POOL_MODE_STATUS_0_ERROR_SHIFT 5u
#define     APE_RX_POOL_MODE_STATUS_0_ERROR_MASK  0x20u
#define GET_APE_RX_POOL_MODE_STATUS_0_ERROR(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_RX_POOL_MODE_STATUS_0_ERROR(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_RX_POOL_MODE_STATUS_0_RESET_SHIFT 6u
#define     APE_RX_POOL_MODE_STATUS_0_RESET_MASK  0x40u
#define GET_APE_RX_POOL_MODE_STATUS_0_RESET(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_RX_POOL_MODE_STATUS_0_RESET(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_RX_POOL_MODE_STATUS_0_FULL_COUNT_SHIFT 8u
#define     APE_RX_POOL_MODE_STATUS_0_FULL_COUNT_MASK  0xffff00u
#define GET_APE_RX_POOL_MODE_STATUS_0_FULL_COUNT(__reg__)  (((__reg__) & 0xffff00) >> 8u)
#define SET_APE_RX_POOL_MODE_STATUS_0_FULL_COUNT(__val__)  (((__val__) << 8u) & 0xffff00u)

/** @brief Register definition for @ref APE_t.RxPoolModeStatus0. */
typedef register_container RegAPERxPoolModeStatus0_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxPoolModeStatus0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxPoolModeStatus0_t()
    {
        /** @brief constructor for @ref APE_t.RxPoolModeStatus0. */
        r32.setName("RxPoolModeStatus0");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.HaltDone.setBaseRegister(&r32);
        bits.HaltDone.setName("HaltDone");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
        bits.Empty.setBaseRegister(&r32);
        bits.Empty.setName("Empty");
        bits.Error.setBaseRegister(&r32);
        bits.Error.setName("Error");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.FullCount.setBaseRegister(&r32);
        bits.FullCount.setName("FullCount");
    }
    RegAPERxPoolModeStatus0_t& operator=(const RegAPERxPoolModeStatus0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxPoolModeStatus0_t;

#define REG_APE_RX_POOL_MODE_STATUS_1 ((volatile APE_APE_H_uint32_t*)0x6020007c) /*  */
#define     APE_RX_POOL_MODE_STATUS_1_HALT_SHIFT 0u
#define     APE_RX_POOL_MODE_STATUS_1_HALT_MASK  0x1u
#define GET_APE_RX_POOL_MODE_STATUS_1_HALT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_RX_POOL_MODE_STATUS_1_HALT(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_RX_POOL_MODE_STATUS_1_HALT_DONE_SHIFT 1u
#define     APE_RX_POOL_MODE_STATUS_1_HALT_DONE_MASK  0x2u
#define GET_APE_RX_POOL_MODE_STATUS_1_HALT_DONE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_RX_POOL_MODE_STATUS_1_HALT_DONE(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_RX_POOL_MODE_STATUS_1_ENABLE_SHIFT 2u
#define     APE_RX_POOL_MODE_STATUS_1_ENABLE_MASK  0x4u
#define GET_APE_RX_POOL_MODE_STATUS_1_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_RX_POOL_MODE_STATUS_1_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_RX_POOL_MODE_STATUS_1_EMPTY_SHIFT 4u
#define     APE_RX_POOL_MODE_STATUS_1_EMPTY_MASK  0x10u
#define GET_APE_RX_POOL_MODE_STATUS_1_EMPTY(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_RX_POOL_MODE_STATUS_1_EMPTY(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_RX_POOL_MODE_STATUS_1_ERROR_SHIFT 5u
#define     APE_RX_POOL_MODE_STATUS_1_ERROR_MASK  0x20u
#define GET_APE_RX_POOL_MODE_STATUS_1_ERROR(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_RX_POOL_MODE_STATUS_1_ERROR(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_RX_POOL_MODE_STATUS_1_RESET_SHIFT 6u
#define     APE_RX_POOL_MODE_STATUS_1_RESET_MASK  0x40u
#define GET_APE_RX_POOL_MODE_STATUS_1_RESET(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_RX_POOL_MODE_STATUS_1_RESET(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_RX_POOL_MODE_STATUS_1_FULL_COUNT_SHIFT 8u
#define     APE_RX_POOL_MODE_STATUS_1_FULL_COUNT_MASK  0xffff00u
#define GET_APE_RX_POOL_MODE_STATUS_1_FULL_COUNT(__reg__)  (((__reg__) & 0xffff00) >> 8u)
#define SET_APE_RX_POOL_MODE_STATUS_1_FULL_COUNT(__val__)  (((__val__) << 8u) & 0xffff00u)

/** @brief Register definition for @ref APE_t.RxPoolModeStatus1. */
typedef register_container RegAPERxPoolModeStatus1_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxPoolModeStatus1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxPoolModeStatus1_t()
    {
        /** @brief constructor for @ref APE_t.RxPoolModeStatus1. */
        r32.setName("RxPoolModeStatus1");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.HaltDone.setBaseRegister(&r32);
        bits.HaltDone.setName("HaltDone");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
        bits.Empty.setBaseRegister(&r32);
        bits.Empty.setName("Empty");
        bits.Error.setBaseRegister(&r32);
        bits.Error.setName("Error");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.FullCount.setBaseRegister(&r32);
        bits.FullCount.setName("FullCount");
    }
    RegAPERxPoolModeStatus1_t& operator=(const RegAPERxPoolModeStatus1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxPoolModeStatus1_t;

#define REG_APE_RX_POOL_RETIRE_0 ((volatile APE_APE_H_uint32_t*)0x60200080) /* Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
#define     APE_RX_POOL_RETIRE_0_TAIL_SHIFT 0u
#define     APE_RX_POOL_RETIRE_0_TAIL_MASK  0xfffu
#define GET_APE_RX_POOL_RETIRE_0_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_RX_POOL_RETIRE_0_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_RX_POOL_RETIRE_0_HEAD_SHIFT 12u
#define     APE_RX_POOL_RETIRE_0_HEAD_MASK  0xfff000u
#define GET_APE_RX_POOL_RETIRE_0_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_RX_POOL_RETIRE_0_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_RX_POOL_RETIRE_0_STATE_SHIFT 25u
#define     APE_RX_POOL_RETIRE_0_STATE_MASK  0x6000000u
#define GET_APE_RX_POOL_RETIRE_0_STATE(__reg__)  (((__reg__) & 0x6000000) >> 25u)
#define SET_APE_RX_POOL_RETIRE_0_STATE(__val__)  (((__val__) << 25u) & 0x6000000u)
#define     APE_RX_POOL_RETIRE_0_STATE_PROCESSING 0x0u
#define     APE_RX_POOL_RETIRE_0_STATE_RETIRED_OK 0x1u
#define     APE_RX_POOL_RETIRE_0_STATE_ERROR__FULL 0x2u
#define     APE_RX_POOL_RETIRE_0_STATE_ERROR__IN_HALT 0x3u

#define     APE_RX_POOL_RETIRE_0_COUNT_SHIFT 27u
#define     APE_RX_POOL_RETIRE_0_COUNT_MASK  0x78000000u
#define GET_APE_RX_POOL_RETIRE_0_COUNT(__reg__)  (((__reg__) & 0x78000000) >> 27u)
#define SET_APE_RX_POOL_RETIRE_0_COUNT(__val__)  (((__val__) << 27u) & 0x78000000u)

/** @brief Register definition for @ref APE_t.RxPoolRetire0. */
typedef register_container RegAPERxPoolRetire0_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_24_24, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 25, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 27, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 27, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 25, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_24_24, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxPoolRetire0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxPoolRetire0_t()
    {
        /** @brief constructor for @ref APE_t.RxPoolRetire0. */
        r32.setName("RxPoolRetire0");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.State.setBaseRegister(&r32);
        bits.State.setName("State");
        bits.Count.setBaseRegister(&r32);
        bits.Count.setName("Count");
    }
    RegAPERxPoolRetire0_t& operator=(const RegAPERxPoolRetire0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxPoolRetire0_t;

#define REG_APE_RX_POOL_RETIRE_1 ((volatile APE_APE_H_uint32_t*)0x60200088) /* Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
#define     APE_RX_POOL_RETIRE_1_TAIL_SHIFT 0u
#define     APE_RX_POOL_RETIRE_1_TAIL_MASK  0xfffu
#define GET_APE_RX_POOL_RETIRE_1_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_RX_POOL_RETIRE_1_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_RX_POOL_RETIRE_1_HEAD_SHIFT 12u
#define     APE_RX_POOL_RETIRE_1_HEAD_MASK  0xfff000u
#define GET_APE_RX_POOL_RETIRE_1_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_RX_POOL_RETIRE_1_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_RX_POOL_RETIRE_1_STATE_SHIFT 25u
#define     APE_RX_POOL_RETIRE_1_STATE_MASK  0x6000000u
#define GET_APE_RX_POOL_RETIRE_1_STATE(__reg__)  (((__reg__) & 0x6000000) >> 25u)
#define SET_APE_RX_POOL_RETIRE_1_STATE(__val__)  (((__val__) << 25u) & 0x6000000u)
#define     APE_RX_POOL_RETIRE_1_STATE_PROCESSING 0x0u
#define     APE_RX_POOL_RETIRE_1_STATE_RETIRED_OK 0x1u
#define     APE_RX_POOL_RETIRE_1_STATE_ERROR__FULL 0x2u
#define     APE_RX_POOL_RETIRE_1_STATE_ERROR__IN_HALT 0x3u

#define     APE_RX_POOL_RETIRE_1_COUNT_SHIFT 27u
#define     APE_RX_POOL_RETIRE_1_COUNT_MASK  0x78000000u
#define GET_APE_RX_POOL_RETIRE_1_COUNT(__reg__)  (((__reg__) & 0x78000000) >> 27u)
#define SET_APE_RX_POOL_RETIRE_1_COUNT(__val__)  (((__val__) << 27u) & 0x78000000u)

/** @brief Register definition for @ref APE_t.RxPoolRetire1. */
typedef register_container RegAPERxPoolRetire1_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_24_24, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 25, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 27, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 27, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 25, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_24_24, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxPoolRetire1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxPoolRetire1_t()
    {
        /** @brief constructor for @ref APE_t.RxPoolRetire1. */
        r32.setName("RxPoolRetire1");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.State.setBaseRegister(&r32);
        bits.State.setName("State");
        bits.Count.setBaseRegister(&r32);
        bits.Count.setName("Count");
    }
    RegAPERxPoolRetire1_t& operator=(const RegAPERxPoolRetire1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxPoolRetire1_t;

#define REG_APE_TX_TO_NET_POOL_MODE_STATUS_0 ((volatile APE_APE_H_uint32_t*)0x6020008c) /*  */
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT_SHIFT 0u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT_MASK  0x1u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT_DONE_SHIFT 1u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT_DONE_MASK  0x2u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT_DONE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_HALT_DONE(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_ENABLE_SHIFT 2u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_ENABLE_MASK  0x4u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_EMPTY_SHIFT 4u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_EMPTY_MASK  0x10u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_EMPTY(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_EMPTY(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_ERROR_SHIFT 5u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_ERROR_MASK  0x20u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_ERROR(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_ERROR(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_RESET_SHIFT 6u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_RESET_MASK  0x40u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_RESET(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_RESET(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_FULL_COUNT_SHIFT 8u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_0_FULL_COUNT_MASK  0xffff00u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_0_FULL_COUNT(__reg__)  (((__reg__) & 0xffff00) >> 8u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_0_FULL_COUNT(__val__)  (((__val__) << 8u) & 0xffff00u)

/** @brief Register definition for @ref APE_t.TxToNetPoolModeStatus0. */
typedef register_container RegAPETxToNetPoolModeStatus0_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief Must set Enable before the APE TX To Net Buffer Allocator will work. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief Must set Enable before the APE TX To Net Buffer Allocator will work. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetPoolModeStatus0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetPoolModeStatus0_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetPoolModeStatus0. */
        r32.setName("TxToNetPoolModeStatus0");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.HaltDone.setBaseRegister(&r32);
        bits.HaltDone.setName("HaltDone");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
        bits.Empty.setBaseRegister(&r32);
        bits.Empty.setName("Empty");
        bits.Error.setBaseRegister(&r32);
        bits.Error.setName("Error");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.FullCount.setBaseRegister(&r32);
        bits.FullCount.setName("FullCount");
    }
    RegAPETxToNetPoolModeStatus0_t& operator=(const RegAPETxToNetPoolModeStatus0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetPoolModeStatus0_t;

#define REG_APE_TX_TO_NET_BUFFER_ALLOCATOR_0 ((volatile APE_APE_H_uint32_t*)0x60200090) /*  */
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_INDEX_SHIFT 0u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_INDEX_MASK  0xfffu
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_0_INDEX(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_0_INDEX(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_INDEX_BLOCK_SIZE 0x80u

#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_REQUEST_ALLOCATION_SHIFT 12u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_REQUEST_ALLOCATION_MASK  0x1000u
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_0_REQUEST_ALLOCATION(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_0_REQUEST_ALLOCATION(__val__)  (((__val__) << 12u) & 0x1000u)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE_SHIFT 13u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE_MASK  0x6000u
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE(__reg__)  (((__reg__) & 0x6000) >> 13u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE(__val__)  (((__val__) << 13u) & 0x6000u)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE_PROCESSING 0x0u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE_ALLOCATION_OK 0x1u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE_ERROR__EMPTY 0x2u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_0_STATE_ERROR__IN_HALT 0x3u


/** @brief Register definition for @ref APE_t.TxToNetBufferAllocator0. */
typedef register_container RegAPETxToNetBufferAllocator0_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Index, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, RequestAllocation, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 13, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_15, 15, 17)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_15, 15, 17)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 13, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, RequestAllocation, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Index, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetBufferAllocator0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetBufferAllocator0_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetBufferAllocator0. */
        r32.setName("TxToNetBufferAllocator0");
        bits.Index.setBaseRegister(&r32);
        bits.Index.setName("Index");
        bits.RequestAllocation.setBaseRegister(&r32);
        bits.RequestAllocation.setName("RequestAllocation");
        bits.State.setBaseRegister(&r32);
        bits.State.setName("State");
    }
    RegAPETxToNetBufferAllocator0_t& operator=(const RegAPETxToNetBufferAllocator0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetBufferAllocator0_t;

#define REG_APE_TICK_1MHZ ((volatile APE_APE_H_uint32_t*)0x602000a8) /* Unknown, monotonically increasing value. Increases at a rate of 1MHz. */
/** @brief Register definition for @ref APE_t.Tick1mhz. */
typedef register_container RegAPETick1mhz_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Tick1mhz"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETick1mhz_t()
    {
        /** @brief constructor for @ref APE_t.Tick1mhz. */
        r32.setName("Tick1mhz");
    }
    RegAPETick1mhz_t& operator=(const RegAPETick1mhz_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETick1mhz_t;

#define REG_APE_TICK_1KHZ ((volatile APE_APE_H_uint32_t*)0x602000ac) /* Unknown, monotonically increasing value. Increases at a rate of 1KHz. */
/** @brief Register definition for @ref APE_t.Tick1khz. */
typedef register_container RegAPETick1khz_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Tick1khz"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETick1khz_t()
    {
        /** @brief constructor for @ref APE_t.Tick1khz. */
        r32.setName("Tick1khz");
    }
    RegAPETick1khz_t& operator=(const RegAPETick1khz_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETick1khz_t;

#define REG_APE_TICK_10HZ ((volatile APE_APE_H_uint32_t*)0x602000b0) /* Unknown, monotonically increasing value. Increases at a rate of 10Hz. */
/** @brief Register definition for @ref APE_t.Tick10hz. */
typedef register_container RegAPETick10hz_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Tick10hz"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETick10hz_t()
    {
        /** @brief constructor for @ref APE_t.Tick10hz. */
        r32.setName("Tick10hz");
    }
    RegAPETick10hz_t& operator=(const RegAPETick10hz_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETick10hz_t;

#define REG_APE_GPIO ((volatile APE_APE_H_uint32_t*)0x602000b8) /*  */
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
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN0Unknown, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN1Unknown, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN2Unknown, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN3Unknown, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_4, 4, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN0UnknownOut, 8, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN1UnknownOut, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN2UnknownOut, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN3UnknownOut, 11, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_15_12, 12, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN0ModeOutput, 16, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN1ModeOutput, 17, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN2ModeOutput, 18, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN3ModeOutput, 19, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_20, 20, 12)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_20, 20, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN3ModeOutput, 19, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN2ModeOutput, 18, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN1ModeOutput, 17, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN0ModeOutput, 16, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_15_12, 12, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN3UnknownOut, 11, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN2UnknownOut, 10, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN1UnknownOut, 9, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN0UnknownOut, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_4, 4, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN3Unknown, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN2Unknown, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN1Unknown, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, PIN0Unknown, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
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

#define REG_APE_GINT ((volatile APE_APE_H_uint32_t*)0x602000bc) /* TODO: See diag for field info. */
/** @brief Register definition for @ref APE_t.Gint. */
typedef register_container RegAPEGint_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Gint"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEGint_t()
    {
        /** @brief constructor for @ref APE_t.Gint. */
        r32.setName("Gint");
    }
    RegAPEGint_t& operator=(const RegAPEGint_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEGint_t;

#define REG_APE_OTP_CONTROL ((volatile APE_APE_H_uint32_t*)0x602000e8) /*  */
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
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Start, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_20_1, 1, 20)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ProgEnable, 21, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_22, 22, 10)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_22, 22, 10)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ProgEnable, 21, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_20_1, 1, 20)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Start, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
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

#define REG_APE_OTP_STATUS ((volatile APE_APE_H_uint32_t*)0x602000ec) /*  */
#define     APE_OTP_STATUS_COMMAND_DONE_SHIFT 0u
#define     APE_OTP_STATUS_COMMAND_DONE_MASK  0x1u
#define GET_APE_OTP_STATUS_COMMAND_DONE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_OTP_STATUS_COMMAND_DONE(__val__)  (((__val__) << 0u) & 0x1u)

/** @brief Register definition for @ref APE_t.OtpStatus. */
typedef register_container RegAPEOtpStatus_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, CommandDone, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_1, 1, 31)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_1, 1, 31)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, CommandDone, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
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

#define REG_APE_OTP_ADDR ((volatile APE_APE_H_uint32_t*)0x602000f0) /*  */
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
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Address, 0, 31)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, CPUEnable, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, CPUEnable, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Address, 0, 31)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
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

#define REG_APE_OTP_READ_DATA ((volatile APE_APE_H_uint32_t*)0x602000f8) /*  */
/** @brief Register definition for @ref APE_t.OtpReadData. */
typedef register_container RegAPEOtpReadData_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "OtpReadData"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPEOtpReadData_t()
    {
        /** @brief constructor for @ref APE_t.OtpReadData. */
        r32.setName("OtpReadData");
    }
    RegAPEOtpReadData_t& operator=(const RegAPEOtpReadData_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPEOtpReadData_t;

#define REG_APE_CPU_STATUS ((volatile APE_APE_H_uint32_t*)0x60200108) /* Seems CPU control related. */
#define     APE_CPU_STATUS_STATUS_SHIFT 0u
#define     APE_CPU_STATUS_STATUS_MASK  0xfu
#define GET_APE_CPU_STATUS_STATUS(__reg__)  (((__reg__) & 0xf) >> 0u)
#define SET_APE_CPU_STATUS_STATUS(__val__)  (((__val__) << 0u) & 0xfu)
#define     APE_CPU_STATUS_STATUS_RUNNING 0x0u
#define     APE_CPU_STATUS_STATUS_HALTED 0x1u
#define     APE_CPU_STATUS_STATUS_LOCKED_OUT 0x2u
#define     APE_CPU_STATUS_STATUS_SLEEPING 0x3u
#define     APE_CPU_STATUS_STATUS_DEEP_SLEEP 0x4u
#define     APE_CPU_STATUS_STATUS_INTERRUPT_PENDING 0x8u
#define     APE_CPU_STATUS_STATUS_INTERRUPT_ENTRY 0x9u
#define     APE_CPU_STATUS_STATUS_INTERRUPT_EXIT 0xau
#define     APE_CPU_STATUS_STATUS_INTERRUPT_RETURN 0xbu

#define     APE_CPU_STATUS_ACTIVE_INTERRUPT_SHIFT 24u
#define     APE_CPU_STATUS_ACTIVE_INTERRUPT_MASK  0xff000000u
#define GET_APE_CPU_STATUS_ACTIVE_INTERRUPT(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_APE_CPU_STATUS_ACTIVE_INTERRUPT(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref APE_t.CpuStatus. */
typedef register_container RegAPECpuStatus_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Status, 0, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_23_4, 4, 20)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ActiveInterrupt, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ActiveInterrupt, 24, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_23_4, 4, 20)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Status, 0, 4)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "CpuStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPECpuStatus_t()
    {
        /** @brief constructor for @ref APE_t.CpuStatus. */
        r32.setName("CpuStatus");
        bits.Status.setBaseRegister(&r32);
        bits.Status.setName("Status");
        bits.ActiveInterrupt.setBaseRegister(&r32);
        bits.ActiveInterrupt.setName("ActiveInterrupt");
    }
    RegAPECpuStatus_t& operator=(const RegAPECpuStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPECpuStatus_t;

#define REG_APE_TX_TO_NET_POOL_MODE_STATUS_1 ((volatile APE_APE_H_uint32_t*)0x60200110) /*  */
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_HALT_SHIFT 0u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_HALT_MASK  0x1u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_1_HALT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_1_HALT(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_HALT_DONE_SHIFT 1u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_HALT_DONE_MASK  0x2u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_1_HALT_DONE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_1_HALT_DONE(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_ENABLE_SHIFT 2u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_ENABLE_MASK  0x4u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_1_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_1_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_EMPTY_SHIFT 4u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_EMPTY_MASK  0x10u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_1_EMPTY(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_1_EMPTY(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_ERROR_SHIFT 5u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_ERROR_MASK  0x20u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_1_ERROR(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_1_ERROR(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_RESET_SHIFT 6u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_RESET_MASK  0x40u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_1_RESET(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_1_RESET(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_FULL_COUNT_SHIFT 8u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_1_FULL_COUNT_MASK  0xffff00u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_1_FULL_COUNT(__reg__)  (((__reg__) & 0xffff00) >> 8u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_1_FULL_COUNT(__val__)  (((__val__) << 8u) & 0xffff00u)

/** @brief Register definition for @ref APE_t.TxToNetPoolModeStatus1. */
typedef register_container RegAPETxToNetPoolModeStatus1_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief Must set Enable before the APE TX To Net Buffer Allocator will work. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief Must set Enable before the APE TX To Net Buffer Allocator will work. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetPoolModeStatus1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetPoolModeStatus1_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetPoolModeStatus1. */
        r32.setName("TxToNetPoolModeStatus1");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.HaltDone.setBaseRegister(&r32);
        bits.HaltDone.setName("HaltDone");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
        bits.Empty.setBaseRegister(&r32);
        bits.Empty.setName("Empty");
        bits.Error.setBaseRegister(&r32);
        bits.Error.setName("Error");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.FullCount.setBaseRegister(&r32);
        bits.FullCount.setName("FullCount");
    }
    RegAPETxToNetPoolModeStatus1_t& operator=(const RegAPETxToNetPoolModeStatus1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetPoolModeStatus1_t;

#define REG_APE_TX_TO_NET_BUFFER_ALLOCATOR_1 ((volatile APE_APE_H_uint32_t*)0x60200114) /*  */
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_1_INDEX_SHIFT 0u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_1_INDEX_MASK  0xfffu
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_1_INDEX(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_1_INDEX(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_1_INDEX_BLOCK_SIZE 0x80u

#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_1_REQUEST_ALLOCATION_SHIFT 12u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_1_REQUEST_ALLOCATION_MASK  0x1000u
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_1_REQUEST_ALLOCATION(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_1_REQUEST_ALLOCATION(__val__)  (((__val__) << 12u) & 0x1000u)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_1_STATE_SHIFT 13u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_1_STATE_MASK  0x6000u
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_1_STATE(__reg__)  (((__reg__) & 0x6000) >> 13u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_1_STATE(__val__)  (((__val__) << 13u) & 0x6000u)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_1_STATE_PROCESSING 0x0u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_1_STATE_ALLOCATION_OK 0x1u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_1_STATE_ERROR__EMPTY 0x2u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_1_STATE_ERROR__IN_HALT 0x3u


/** @brief Register definition for @ref APE_t.TxToNetBufferAllocator1. */
typedef register_container RegAPETxToNetBufferAllocator1_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Index, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, RequestAllocation, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 13, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_15, 15, 17)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_15, 15, 17)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 13, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, RequestAllocation, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Index, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetBufferAllocator1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetBufferAllocator1_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetBufferAllocator1. */
        r32.setName("TxToNetBufferAllocator1");
        bits.Index.setBaseRegister(&r32);
        bits.Index.setName("Index");
        bits.RequestAllocation.setBaseRegister(&r32);
        bits.RequestAllocation.setName("RequestAllocation");
        bits.State.setBaseRegister(&r32);
        bits.State.setName("State");
    }
    RegAPETxToNetBufferAllocator1_t& operator=(const RegAPETxToNetBufferAllocator1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetBufferAllocator1_t;

#define REG_APE_TX_TO_NET_DOORBELL_FUNC1 ((volatile APE_APE_H_uint32_t*)0x60200120) /* Written on APE TX to network after filling 0xA002 buffer with packet. */
#define     APE_TX_TO_NET_DOORBELL_FUNC1_TAIL_SHIFT 0u
#define     APE_TX_TO_NET_DOORBELL_FUNC1_TAIL_MASK  0xfffu
#define GET_APE_TX_TO_NET_DOORBELL_FUNC1_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC1_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_TX_TO_NET_DOORBELL_FUNC1_HEAD_SHIFT 12u
#define     APE_TX_TO_NET_DOORBELL_FUNC1_HEAD_MASK  0xfff000u
#define GET_APE_TX_TO_NET_DOORBELL_FUNC1_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC1_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_TX_TO_NET_DOORBELL_FUNC1_LENGTH_SHIFT 24u
#define     APE_TX_TO_NET_DOORBELL_FUNC1_LENGTH_MASK  0xff000000u
#define GET_APE_TX_TO_NET_DOORBELL_FUNC1_LENGTH(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC1_LENGTH(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref APE_t.TxToNetDoorbellFunc1. */
typedef register_container RegAPETxToNetDoorbellFunc1_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Length, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Length, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetDoorbellFunc1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetDoorbellFunc1_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetDoorbellFunc1. */
        r32.setName("TxToNetDoorbellFunc1");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.Length.setBaseRegister(&r32);
        bits.Length.setName("Length");
    }
    RegAPETxToNetDoorbellFunc1_t& operator=(const RegAPETxToNetDoorbellFunc1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetDoorbellFunc1_t;

#define REG_APE_RXBUFOFFSET_FUNC2 ((volatile APE_APE_H_uint32_t*)0x60200200) /* This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
#define     APE_RXBUFOFFSET_FUNC2_TAIL_SHIFT 0u
#define     APE_RXBUFOFFSET_FUNC2_TAIL_MASK  0xfffu
#define GET_APE_RXBUFOFFSET_FUNC2_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_RXBUFOFFSET_FUNC2_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_RXBUFOFFSET_FUNC2_HEAD_SHIFT 12u
#define     APE_RXBUFOFFSET_FUNC2_HEAD_MASK  0xfff000u
#define GET_APE_RXBUFOFFSET_FUNC2_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_RXBUFOFFSET_FUNC2_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_RXBUFOFFSET_FUNC2_TO_HOST_SHIFT 24u
#define     APE_RXBUFOFFSET_FUNC2_TO_HOST_MASK  0x1000000u
#define GET_APE_RXBUFOFFSET_FUNC2_TO_HOST(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_APE_RXBUFOFFSET_FUNC2_TO_HOST(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     APE_RXBUFOFFSET_FUNC2_IP_FRAG_SHIFT 25u
#define     APE_RXBUFOFFSET_FUNC2_IP_FRAG_MASK  0x2000000u
#define GET_APE_RXBUFOFFSET_FUNC2_IP_FRAG(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_APE_RXBUFOFFSET_FUNC2_IP_FRAG(__val__)  (((__val__) << 25u) & 0x2000000u)
#define     APE_RXBUFOFFSET_FUNC2_COUNT_SHIFT 26u
#define     APE_RXBUFOFFSET_FUNC2_COUNT_MASK  0x3c000000u
#define GET_APE_RXBUFOFFSET_FUNC2_COUNT(__reg__)  (((__reg__) & 0x3c000000) >> 26u)
#define SET_APE_RXBUFOFFSET_FUNC2_COUNT(__val__)  (((__val__) << 26u) & 0x3c000000u)
#define     APE_RXBUFOFFSET_FUNC2_VALID_SHIFT 30u
#define     APE_RXBUFOFFSET_FUNC2_VALID_MASK  0x40000000u
#define GET_APE_RXBUFOFFSET_FUNC2_VALID(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_APE_RXBUFOFFSET_FUNC2_VALID(__val__)  (((__val__) << 30u) & 0x40000000u)

/** @brief Register definition for @ref APE_t.RxbufoffsetFunc2. */
typedef register_container RegAPERxbufoffsetFunc2_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ToHost, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, IPFrag, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 26, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Valid, 30, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Valid, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 26, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, IPFrag, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ToHost, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxbufoffsetFunc2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxbufoffsetFunc2_t()
    {
        /** @brief constructor for @ref APE_t.RxbufoffsetFunc2. */
        r32.setName("RxbufoffsetFunc2");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.ToHost.setBaseRegister(&r32);
        bits.ToHost.setName("ToHost");
        bits.IPFrag.setBaseRegister(&r32);
        bits.IPFrag.setName("IPFrag");
        bits.Count.setBaseRegister(&r32);
        bits.Count.setName("Count");
        bits.Valid.setBaseRegister(&r32);
        bits.Valid.setName("Valid");
    }
    RegAPERxbufoffsetFunc2_t& operator=(const RegAPERxbufoffsetFunc2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxbufoffsetFunc2_t;

#define REG_APE_TX_TO_NET_DOORBELL_FUNC2 ((volatile APE_APE_H_uint32_t*)0x60200204) /* Written on APE TX to network after filling 0xA002 buffer with packet. */
#define     APE_TX_TO_NET_DOORBELL_FUNC2_TAIL_SHIFT 0u
#define     APE_TX_TO_NET_DOORBELL_FUNC2_TAIL_MASK  0xfffu
#define GET_APE_TX_TO_NET_DOORBELL_FUNC2_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC2_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_TX_TO_NET_DOORBELL_FUNC2_HEAD_SHIFT 12u
#define     APE_TX_TO_NET_DOORBELL_FUNC2_HEAD_MASK  0xfff000u
#define GET_APE_TX_TO_NET_DOORBELL_FUNC2_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC2_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_TX_TO_NET_DOORBELL_FUNC2_LENGTH_SHIFT 24u
#define     APE_TX_TO_NET_DOORBELL_FUNC2_LENGTH_MASK  0xff000000u
#define GET_APE_TX_TO_NET_DOORBELL_FUNC2_LENGTH(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC2_LENGTH(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref APE_t.TxToNetDoorbellFunc2. */
typedef register_container RegAPETxToNetDoorbellFunc2_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Length, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Length, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetDoorbellFunc2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetDoorbellFunc2_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetDoorbellFunc2. */
        r32.setName("TxToNetDoorbellFunc2");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.Length.setBaseRegister(&r32);
        bits.Length.setName("Length");
    }
    RegAPETxToNetDoorbellFunc2_t& operator=(const RegAPETxToNetDoorbellFunc2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetDoorbellFunc2_t;

#define REG_APE_RX_POOL_MODE_STATUS_2 ((volatile APE_APE_H_uint32_t*)0x60200214) /*  */
#define     APE_RX_POOL_MODE_STATUS_2_HALT_SHIFT 0u
#define     APE_RX_POOL_MODE_STATUS_2_HALT_MASK  0x1u
#define GET_APE_RX_POOL_MODE_STATUS_2_HALT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_RX_POOL_MODE_STATUS_2_HALT(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_RX_POOL_MODE_STATUS_2_HALT_DONE_SHIFT 1u
#define     APE_RX_POOL_MODE_STATUS_2_HALT_DONE_MASK  0x2u
#define GET_APE_RX_POOL_MODE_STATUS_2_HALT_DONE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_RX_POOL_MODE_STATUS_2_HALT_DONE(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_RX_POOL_MODE_STATUS_2_ENABLE_SHIFT 2u
#define     APE_RX_POOL_MODE_STATUS_2_ENABLE_MASK  0x4u
#define GET_APE_RX_POOL_MODE_STATUS_2_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_RX_POOL_MODE_STATUS_2_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_RX_POOL_MODE_STATUS_2_EMPTY_SHIFT 4u
#define     APE_RX_POOL_MODE_STATUS_2_EMPTY_MASK  0x10u
#define GET_APE_RX_POOL_MODE_STATUS_2_EMPTY(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_RX_POOL_MODE_STATUS_2_EMPTY(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_RX_POOL_MODE_STATUS_2_ERROR_SHIFT 5u
#define     APE_RX_POOL_MODE_STATUS_2_ERROR_MASK  0x20u
#define GET_APE_RX_POOL_MODE_STATUS_2_ERROR(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_RX_POOL_MODE_STATUS_2_ERROR(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_RX_POOL_MODE_STATUS_2_RESET_SHIFT 6u
#define     APE_RX_POOL_MODE_STATUS_2_RESET_MASK  0x40u
#define GET_APE_RX_POOL_MODE_STATUS_2_RESET(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_RX_POOL_MODE_STATUS_2_RESET(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_RX_POOL_MODE_STATUS_2_FULL_COUNT_SHIFT 8u
#define     APE_RX_POOL_MODE_STATUS_2_FULL_COUNT_MASK  0xffff00u
#define GET_APE_RX_POOL_MODE_STATUS_2_FULL_COUNT(__reg__)  (((__reg__) & 0xffff00) >> 8u)
#define SET_APE_RX_POOL_MODE_STATUS_2_FULL_COUNT(__val__)  (((__val__) << 8u) & 0xffff00u)

/** @brief Register definition for @ref APE_t.RxPoolModeStatus2. */
typedef register_container RegAPERxPoolModeStatus2_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxPoolModeStatus2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxPoolModeStatus2_t()
    {
        /** @brief constructor for @ref APE_t.RxPoolModeStatus2. */
        r32.setName("RxPoolModeStatus2");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.HaltDone.setBaseRegister(&r32);
        bits.HaltDone.setName("HaltDone");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
        bits.Empty.setBaseRegister(&r32);
        bits.Empty.setName("Empty");
        bits.Error.setBaseRegister(&r32);
        bits.Error.setName("Error");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.FullCount.setBaseRegister(&r32);
        bits.FullCount.setName("FullCount");
    }
    RegAPERxPoolModeStatus2_t& operator=(const RegAPERxPoolModeStatus2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxPoolModeStatus2_t;

#define REG_APE_RX_POOL_RETIRE_2 ((volatile APE_APE_H_uint32_t*)0x60200218) /* Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
#define     APE_RX_POOL_RETIRE_2_TAIL_SHIFT 0u
#define     APE_RX_POOL_RETIRE_2_TAIL_MASK  0xfffu
#define GET_APE_RX_POOL_RETIRE_2_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_RX_POOL_RETIRE_2_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_RX_POOL_RETIRE_2_HEAD_SHIFT 12u
#define     APE_RX_POOL_RETIRE_2_HEAD_MASK  0xfff000u
#define GET_APE_RX_POOL_RETIRE_2_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_RX_POOL_RETIRE_2_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_RX_POOL_RETIRE_2_STATE_SHIFT 25u
#define     APE_RX_POOL_RETIRE_2_STATE_MASK  0x6000000u
#define GET_APE_RX_POOL_RETIRE_2_STATE(__reg__)  (((__reg__) & 0x6000000) >> 25u)
#define SET_APE_RX_POOL_RETIRE_2_STATE(__val__)  (((__val__) << 25u) & 0x6000000u)
#define     APE_RX_POOL_RETIRE_2_STATE_PROCESSING 0x0u
#define     APE_RX_POOL_RETIRE_2_STATE_RETIRED_OK 0x1u
#define     APE_RX_POOL_RETIRE_2_STATE_ERROR__FULL 0x2u
#define     APE_RX_POOL_RETIRE_2_STATE_ERROR__IN_HALT 0x3u

#define     APE_RX_POOL_RETIRE_2_COUNT_SHIFT 27u
#define     APE_RX_POOL_RETIRE_2_COUNT_MASK  0x78000000u
#define GET_APE_RX_POOL_RETIRE_2_COUNT(__reg__)  (((__reg__) & 0x78000000) >> 27u)
#define SET_APE_RX_POOL_RETIRE_2_COUNT(__val__)  (((__val__) << 27u) & 0x78000000u)

/** @brief Register definition for @ref APE_t.RxPoolRetire2. */
typedef register_container RegAPERxPoolRetire2_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_24_24, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 25, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 27, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 27, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 25, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_24_24, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxPoolRetire2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxPoolRetire2_t()
    {
        /** @brief constructor for @ref APE_t.RxPoolRetire2. */
        r32.setName("RxPoolRetire2");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.State.setBaseRegister(&r32);
        bits.State.setName("State");
        bits.Count.setBaseRegister(&r32);
        bits.Count.setName("Count");
    }
    RegAPERxPoolRetire2_t& operator=(const RegAPERxPoolRetire2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxPoolRetire2_t;

#define REG_APE_TX_TO_NET_POOL_MODE_STATUS_2 ((volatile APE_APE_H_uint32_t*)0x60200220) /*  */
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_HALT_SHIFT 0u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_HALT_MASK  0x1u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_2_HALT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_2_HALT(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_HALT_DONE_SHIFT 1u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_HALT_DONE_MASK  0x2u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_2_HALT_DONE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_2_HALT_DONE(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_ENABLE_SHIFT 2u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_ENABLE_MASK  0x4u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_2_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_2_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_EMPTY_SHIFT 4u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_EMPTY_MASK  0x10u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_2_EMPTY(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_2_EMPTY(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_ERROR_SHIFT 5u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_ERROR_MASK  0x20u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_2_ERROR(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_2_ERROR(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_RESET_SHIFT 6u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_RESET_MASK  0x40u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_2_RESET(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_2_RESET(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_FULL_COUNT_SHIFT 8u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_2_FULL_COUNT_MASK  0xffff00u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_2_FULL_COUNT(__reg__)  (((__reg__) & 0xffff00) >> 8u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_2_FULL_COUNT(__val__)  (((__val__) << 8u) & 0xffff00u)

/** @brief Register definition for @ref APE_t.TxToNetPoolModeStatus2. */
typedef register_container RegAPETxToNetPoolModeStatus2_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief Must set Enable before the APE TX To Net Buffer Allocator will work. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief Must set Enable before the APE TX To Net Buffer Allocator will work. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetPoolModeStatus2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetPoolModeStatus2_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetPoolModeStatus2. */
        r32.setName("TxToNetPoolModeStatus2");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.HaltDone.setBaseRegister(&r32);
        bits.HaltDone.setName("HaltDone");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
        bits.Empty.setBaseRegister(&r32);
        bits.Empty.setName("Empty");
        bits.Error.setBaseRegister(&r32);
        bits.Error.setName("Error");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.FullCount.setBaseRegister(&r32);
        bits.FullCount.setName("FullCount");
    }
    RegAPETxToNetPoolModeStatus2_t& operator=(const RegAPETxToNetPoolModeStatus2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetPoolModeStatus2_t;

#define REG_APE_TX_TO_NET_BUFFER_ALLOCATOR_2 ((volatile APE_APE_H_uint32_t*)0x60200224) /*  */
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_2_INDEX_SHIFT 0u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_2_INDEX_MASK  0xfffu
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_2_INDEX(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_2_INDEX(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_2_INDEX_BLOCK_SIZE 0x80u

#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_2_REQUEST_ALLOCATION_SHIFT 12u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_2_REQUEST_ALLOCATION_MASK  0x1000u
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_2_REQUEST_ALLOCATION(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_2_REQUEST_ALLOCATION(__val__)  (((__val__) << 12u) & 0x1000u)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_2_STATE_SHIFT 13u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_2_STATE_MASK  0x6000u
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_2_STATE(__reg__)  (((__reg__) & 0x6000) >> 13u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_2_STATE(__val__)  (((__val__) << 13u) & 0x6000u)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_2_STATE_PROCESSING 0x0u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_2_STATE_ALLOCATION_OK 0x1u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_2_STATE_ERROR__EMPTY 0x2u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_2_STATE_ERROR__IN_HALT 0x3u


/** @brief Register definition for @ref APE_t.TxToNetBufferAllocator2. */
typedef register_container RegAPETxToNetBufferAllocator2_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Index, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, RequestAllocation, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 13, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_15, 15, 17)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_15, 15, 17)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 13, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, RequestAllocation, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Index, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetBufferAllocator2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetBufferAllocator2_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetBufferAllocator2. */
        r32.setName("TxToNetBufferAllocator2");
        bits.Index.setBaseRegister(&r32);
        bits.Index.setName("Index");
        bits.RequestAllocation.setBaseRegister(&r32);
        bits.RequestAllocation.setName("RequestAllocation");
        bits.State.setBaseRegister(&r32);
        bits.State.setName("State");
    }
    RegAPETxToNetBufferAllocator2_t& operator=(const RegAPETxToNetBufferAllocator2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetBufferAllocator2_t;

#define REG_APE_RXBUFOFFSET_FUNC3 ((volatile APE_APE_H_uint32_t*)0x60200300) /* This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
#define     APE_RXBUFOFFSET_FUNC3_TAIL_SHIFT 0u
#define     APE_RXBUFOFFSET_FUNC3_TAIL_MASK  0xfffu
#define GET_APE_RXBUFOFFSET_FUNC3_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_RXBUFOFFSET_FUNC3_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_RXBUFOFFSET_FUNC3_HEAD_SHIFT 12u
#define     APE_RXBUFOFFSET_FUNC3_HEAD_MASK  0xfff000u
#define GET_APE_RXBUFOFFSET_FUNC3_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_RXBUFOFFSET_FUNC3_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_RXBUFOFFSET_FUNC3_TO_HOST_SHIFT 24u
#define     APE_RXBUFOFFSET_FUNC3_TO_HOST_MASK  0x1000000u
#define GET_APE_RXBUFOFFSET_FUNC3_TO_HOST(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_APE_RXBUFOFFSET_FUNC3_TO_HOST(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     APE_RXBUFOFFSET_FUNC3_IP_FRAG_SHIFT 25u
#define     APE_RXBUFOFFSET_FUNC3_IP_FRAG_MASK  0x2000000u
#define GET_APE_RXBUFOFFSET_FUNC3_IP_FRAG(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_APE_RXBUFOFFSET_FUNC3_IP_FRAG(__val__)  (((__val__) << 25u) & 0x2000000u)
#define     APE_RXBUFOFFSET_FUNC3_COUNT_SHIFT 26u
#define     APE_RXBUFOFFSET_FUNC3_COUNT_MASK  0x3c000000u
#define GET_APE_RXBUFOFFSET_FUNC3_COUNT(__reg__)  (((__reg__) & 0x3c000000) >> 26u)
#define SET_APE_RXBUFOFFSET_FUNC3_COUNT(__val__)  (((__val__) << 26u) & 0x3c000000u)
#define     APE_RXBUFOFFSET_FUNC3_VALID_SHIFT 30u
#define     APE_RXBUFOFFSET_FUNC3_VALID_MASK  0x40000000u
#define GET_APE_RXBUFOFFSET_FUNC3_VALID(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_APE_RXBUFOFFSET_FUNC3_VALID(__val__)  (((__val__) << 30u) & 0x40000000u)

/** @brief Register definition for @ref APE_t.RxbufoffsetFunc3. */
typedef register_container RegAPERxbufoffsetFunc3_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ToHost, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, IPFrag, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 26, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Valid, 30, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Valid, 30, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 26, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, IPFrag, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, ToHost, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxbufoffsetFunc3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxbufoffsetFunc3_t()
    {
        /** @brief constructor for @ref APE_t.RxbufoffsetFunc3. */
        r32.setName("RxbufoffsetFunc3");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.ToHost.setBaseRegister(&r32);
        bits.ToHost.setName("ToHost");
        bits.IPFrag.setBaseRegister(&r32);
        bits.IPFrag.setName("IPFrag");
        bits.Count.setBaseRegister(&r32);
        bits.Count.setName("Count");
        bits.Valid.setBaseRegister(&r32);
        bits.Valid.setName("Valid");
    }
    RegAPERxbufoffsetFunc3_t& operator=(const RegAPERxbufoffsetFunc3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxbufoffsetFunc3_t;

#define REG_APE_TX_TO_NET_DOORBELL_FUNC3 ((volatile APE_APE_H_uint32_t*)0x60200304) /* Written on APE TX to network after filling 0xA002 buffer with packet. */
#define     APE_TX_TO_NET_DOORBELL_FUNC3_TAIL_SHIFT 0u
#define     APE_TX_TO_NET_DOORBELL_FUNC3_TAIL_MASK  0xfffu
#define GET_APE_TX_TO_NET_DOORBELL_FUNC3_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC3_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_TX_TO_NET_DOORBELL_FUNC3_HEAD_SHIFT 12u
#define     APE_TX_TO_NET_DOORBELL_FUNC3_HEAD_MASK  0xfff000u
#define GET_APE_TX_TO_NET_DOORBELL_FUNC3_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC3_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_TX_TO_NET_DOORBELL_FUNC3_LENGTH_SHIFT 24u
#define     APE_TX_TO_NET_DOORBELL_FUNC3_LENGTH_MASK  0xff000000u
#define GET_APE_TX_TO_NET_DOORBELL_FUNC3_LENGTH(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_APE_TX_TO_NET_DOORBELL_FUNC3_LENGTH(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref APE_t.TxToNetDoorbellFunc3. */
typedef register_container RegAPETxToNetDoorbellFunc3_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Length, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Length, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetDoorbellFunc3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetDoorbellFunc3_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetDoorbellFunc3. */
        r32.setName("TxToNetDoorbellFunc3");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.Length.setBaseRegister(&r32);
        bits.Length.setName("Length");
    }
    RegAPETxToNetDoorbellFunc3_t& operator=(const RegAPETxToNetDoorbellFunc3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetDoorbellFunc3_t;

#define REG_APE_RX_POOL_MODE_STATUS_3 ((volatile APE_APE_H_uint32_t*)0x60200314) /*  */
#define     APE_RX_POOL_MODE_STATUS_3_HALT_SHIFT 0u
#define     APE_RX_POOL_MODE_STATUS_3_HALT_MASK  0x1u
#define GET_APE_RX_POOL_MODE_STATUS_3_HALT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_RX_POOL_MODE_STATUS_3_HALT(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_RX_POOL_MODE_STATUS_3_HALT_DONE_SHIFT 1u
#define     APE_RX_POOL_MODE_STATUS_3_HALT_DONE_MASK  0x2u
#define GET_APE_RX_POOL_MODE_STATUS_3_HALT_DONE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_RX_POOL_MODE_STATUS_3_HALT_DONE(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_RX_POOL_MODE_STATUS_3_ENABLE_SHIFT 2u
#define     APE_RX_POOL_MODE_STATUS_3_ENABLE_MASK  0x4u
#define GET_APE_RX_POOL_MODE_STATUS_3_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_RX_POOL_MODE_STATUS_3_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_RX_POOL_MODE_STATUS_3_EMPTY_SHIFT 4u
#define     APE_RX_POOL_MODE_STATUS_3_EMPTY_MASK  0x10u
#define GET_APE_RX_POOL_MODE_STATUS_3_EMPTY(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_RX_POOL_MODE_STATUS_3_EMPTY(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_RX_POOL_MODE_STATUS_3_ERROR_SHIFT 5u
#define     APE_RX_POOL_MODE_STATUS_3_ERROR_MASK  0x20u
#define GET_APE_RX_POOL_MODE_STATUS_3_ERROR(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_RX_POOL_MODE_STATUS_3_ERROR(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_RX_POOL_MODE_STATUS_3_RESET_SHIFT 6u
#define     APE_RX_POOL_MODE_STATUS_3_RESET_MASK  0x40u
#define GET_APE_RX_POOL_MODE_STATUS_3_RESET(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_RX_POOL_MODE_STATUS_3_RESET(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_RX_POOL_MODE_STATUS_3_FULL_COUNT_SHIFT 8u
#define     APE_RX_POOL_MODE_STATUS_3_FULL_COUNT_MASK  0xffff00u
#define GET_APE_RX_POOL_MODE_STATUS_3_FULL_COUNT(__reg__)  (((__reg__) & 0xffff00) >> 8u)
#define SET_APE_RX_POOL_MODE_STATUS_3_FULL_COUNT(__val__)  (((__val__) << 8u) & 0xffff00u)

/** @brief Register definition for @ref APE_t.RxPoolModeStatus3. */
typedef register_container RegAPERxPoolModeStatus3_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxPoolModeStatus3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxPoolModeStatus3_t()
    {
        /** @brief constructor for @ref APE_t.RxPoolModeStatus3. */
        r32.setName("RxPoolModeStatus3");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.HaltDone.setBaseRegister(&r32);
        bits.HaltDone.setName("HaltDone");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
        bits.Empty.setBaseRegister(&r32);
        bits.Empty.setName("Empty");
        bits.Error.setBaseRegister(&r32);
        bits.Error.setName("Error");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.FullCount.setBaseRegister(&r32);
        bits.FullCount.setName("FullCount");
    }
    RegAPERxPoolModeStatus3_t& operator=(const RegAPERxPoolModeStatus3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxPoolModeStatus3_t;

#define REG_APE_RX_POOL_RETIRE_3 ((volatile APE_APE_H_uint32_t*)0x60200318) /* Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
#define     APE_RX_POOL_RETIRE_3_TAIL_SHIFT 0u
#define     APE_RX_POOL_RETIRE_3_TAIL_MASK  0xfffu
#define GET_APE_RX_POOL_RETIRE_3_TAIL(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_RX_POOL_RETIRE_3_TAIL(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_RX_POOL_RETIRE_3_HEAD_SHIFT 12u
#define     APE_RX_POOL_RETIRE_3_HEAD_MASK  0xfff000u
#define GET_APE_RX_POOL_RETIRE_3_HEAD(__reg__)  (((__reg__) & 0xfff000) >> 12u)
#define SET_APE_RX_POOL_RETIRE_3_HEAD(__val__)  (((__val__) << 12u) & 0xfff000u)
#define     APE_RX_POOL_RETIRE_3_STATE_SHIFT 25u
#define     APE_RX_POOL_RETIRE_3_STATE_MASK  0x6000000u
#define GET_APE_RX_POOL_RETIRE_3_STATE(__reg__)  (((__reg__) & 0x6000000) >> 25u)
#define SET_APE_RX_POOL_RETIRE_3_STATE(__val__)  (((__val__) << 25u) & 0x6000000u)
#define     APE_RX_POOL_RETIRE_3_STATE_PROCESSING 0x0u
#define     APE_RX_POOL_RETIRE_3_STATE_RETIRED_OK 0x1u
#define     APE_RX_POOL_RETIRE_3_STATE_ERROR__FULL 0x2u
#define     APE_RX_POOL_RETIRE_3_STATE_ERROR__IN_HALT 0x3u

#define     APE_RX_POOL_RETIRE_3_COUNT_SHIFT 27u
#define     APE_RX_POOL_RETIRE_3_COUNT_MASK  0x78000000u
#define GET_APE_RX_POOL_RETIRE_3_COUNT(__reg__)  (((__reg__) & 0x78000000) >> 27u)
#define SET_APE_RX_POOL_RETIRE_3_COUNT(__val__)  (((__val__) << 27u) & 0x78000000u)

/** @brief Register definition for @ref APE_t.RxPoolRetire3. */
typedef register_container RegAPERxPoolRetire3_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_24_24, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 25, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 27, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Count, 27, 4)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 25, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_24_24, 24, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Head, 12, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Tail, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "RxPoolRetire3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPERxPoolRetire3_t()
    {
        /** @brief constructor for @ref APE_t.RxPoolRetire3. */
        r32.setName("RxPoolRetire3");
        bits.Tail.setBaseRegister(&r32);
        bits.Tail.setName("Tail");
        bits.Head.setBaseRegister(&r32);
        bits.Head.setName("Head");
        bits.State.setBaseRegister(&r32);
        bits.State.setName("State");
        bits.Count.setBaseRegister(&r32);
        bits.Count.setName("Count");
    }
    RegAPERxPoolRetire3_t& operator=(const RegAPERxPoolRetire3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPERxPoolRetire3_t;

#define REG_APE_TX_TO_NET_POOL_MODE_STATUS_3 ((volatile APE_APE_H_uint32_t*)0x60200320) /*  */
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_HALT_SHIFT 0u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_HALT_MASK  0x1u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_3_HALT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_3_HALT(__val__)  (((__val__) << 0u) & 0x1u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_HALT_DONE_SHIFT 1u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_HALT_DONE_MASK  0x2u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_3_HALT_DONE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_3_HALT_DONE(__val__)  (((__val__) << 1u) & 0x2u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_ENABLE_SHIFT 2u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_ENABLE_MASK  0x4u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_3_ENABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_3_ENABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_EMPTY_SHIFT 4u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_EMPTY_MASK  0x10u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_3_EMPTY(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_3_EMPTY(__val__)  (((__val__) << 4u) & 0x10u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_ERROR_SHIFT 5u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_ERROR_MASK  0x20u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_3_ERROR(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_3_ERROR(__val__)  (((__val__) << 5u) & 0x20u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_RESET_SHIFT 6u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_RESET_MASK  0x40u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_3_RESET(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_3_RESET(__val__)  (((__val__) << 6u) & 0x40u)
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_FULL_COUNT_SHIFT 8u
#define     APE_TX_TO_NET_POOL_MODE_STATUS_3_FULL_COUNT_MASK  0xffff00u
#define GET_APE_TX_TO_NET_POOL_MODE_STATUS_3_FULL_COUNT(__reg__)  (((__reg__) & 0xffff00) >> 8u)
#define SET_APE_TX_TO_NET_POOL_MODE_STATUS_3_FULL_COUNT(__val__)  (((__val__) << 8u) & 0xffff00u)

/** @brief Register definition for @ref APE_t.TxToNetPoolModeStatus3. */
typedef register_container RegAPETxToNetPoolModeStatus3_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief Must set Enable before the APE TX To Net Buffer Allocator will work. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_24, 24, 8)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, FullCount, 8, 16)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_7_7, 7, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Reset, 6, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Error, 5, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Empty, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief Must set Enable before the APE TX To Net Buffer Allocator will work. */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Enable, 2, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, HaltDone, 1, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Halt, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetPoolModeStatus3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetPoolModeStatus3_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetPoolModeStatus3. */
        r32.setName("TxToNetPoolModeStatus3");
        bits.Halt.setBaseRegister(&r32);
        bits.Halt.setName("Halt");
        bits.HaltDone.setBaseRegister(&r32);
        bits.HaltDone.setName("HaltDone");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
        bits.Empty.setBaseRegister(&r32);
        bits.Empty.setName("Empty");
        bits.Error.setBaseRegister(&r32);
        bits.Error.setName("Error");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.FullCount.setBaseRegister(&r32);
        bits.FullCount.setName("FullCount");
    }
    RegAPETxToNetPoolModeStatus3_t& operator=(const RegAPETxToNetPoolModeStatus3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetPoolModeStatus3_t;

#define REG_APE_TX_TO_NET_BUFFER_ALLOCATOR_3 ((volatile APE_APE_H_uint32_t*)0x60200324) /*  */
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_3_INDEX_SHIFT 0u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_3_INDEX_MASK  0xfffu
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_3_INDEX(__reg__)  (((__reg__) & 0xfff) >> 0u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_3_INDEX(__val__)  (((__val__) << 0u) & 0xfffu)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_3_INDEX_BLOCK_SIZE 0x80u

#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_3_REQUEST_ALLOCATION_SHIFT 12u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_3_REQUEST_ALLOCATION_MASK  0x1000u
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_3_REQUEST_ALLOCATION(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_3_REQUEST_ALLOCATION(__val__)  (((__val__) << 12u) & 0x1000u)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_3_STATE_SHIFT 13u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_3_STATE_MASK  0x6000u
#define GET_APE_TX_TO_NET_BUFFER_ALLOCATOR_3_STATE(__reg__)  (((__reg__) & 0x6000) >> 13u)
#define SET_APE_TX_TO_NET_BUFFER_ALLOCATOR_3_STATE(__val__)  (((__val__) << 13u) & 0x6000u)
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_3_STATE_PROCESSING 0x0u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_3_STATE_ALLOCATION_OK 0x1u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_3_STATE_ERROR__EMPTY 0x2u
#define     APE_TX_TO_NET_BUFFER_ALLOCATOR_3_STATE_ERROR__IN_HALT 0x3u


/** @brief Register definition for @ref APE_t.TxToNetBufferAllocator3. */
typedef register_container RegAPETxToNetBufferAllocator3_t {
    /** @brief 32bit direct register access. */
    APE_APE_H_uint32_t r32;

    BITFIELD_BEGIN(APE_APE_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Index, 0, 12)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, RequestAllocation, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 13, 2)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_15, 15, 17)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, reserved_31_15, 15, 17)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, State, 13, 2)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, RequestAllocation, 12, 1)
        /** @brief  */
        BITFIELD_MEMBER(APE_APE_H_uint32_t, Index, 0, 12)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_APE_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "TxToNetBufferAllocator3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegAPETxToNetBufferAllocator3_t()
    {
        /** @brief constructor for @ref APE_t.TxToNetBufferAllocator3. */
        r32.setName("TxToNetBufferAllocator3");
        bits.Index.setBaseRegister(&r32);
        bits.Index.setName("Index");
        bits.RequestAllocation.setBaseRegister(&r32);
        bits.RequestAllocation.setName("RequestAllocation");
        bits.State.setBaseRegister(&r32);
        bits.State.setName("State");
    }
    RegAPETxToNetBufferAllocator3_t& operator=(const RegAPETxToNetBufferAllocator3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegAPETxToNetBufferAllocator3_t;

/** @brief Component definition for @ref APE. */
typedef struct APE_t {
    /** @brief More of these bits can be found in diagnostic utilities, but they don't seem too interesting. */
    RegAPEMode_t Mode;

    /** @brief  */
    RegAPEStatus_t Status;

    /** @brief Related to APE fastboot. In that case the value of it is an APE memory address in the code region. If Fast Boot is set, and the low two bits of this are not 0b10, ROM hangs (you have to OR 0x2 into the address). Otherwise, they are masked off and the resulting value is used as the reset vector. The resulting value is also stored in this register (i.e., the low two bits are cleared).  */
    RegAPEGpioMessage_t GpioMessage;

    /** @brief  */
    RegAPEEvent_t Event;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_16[1];

    /** @brief This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. The fields are block numbers (block size 128 bytes). */
    RegAPERxbufoffsetFunc0_t RxbufoffsetFunc0;

    /** @brief This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
    RegAPERxbufoffsetFunc1_t RxbufoffsetFunc1;

    /** @brief Written on APE TX to network after filling 0xA002 buffer with packet. */
    RegAPETxToNetDoorbellFunc0_t TxToNetDoorbellFunc0;

    /** @brief APE TX Status. */
    RegAPETxState0_t TxState0;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_36[2];

    /** @brief Expansion for MODE */
    RegAPEMode2_t Mode2;

    /** @brief  */
    RegAPEStatus2_t Status2;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_52[6];

    /** @brief See  */
    RegAPELockGrantObsolete_t LockGrantObsolete;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_80[10];

    /** @brief  */
    RegAPERxPoolModeStatus0_t RxPoolModeStatus0;

    /** @brief  */
    RegAPERxPoolModeStatus1_t RxPoolModeStatus1;

    /** @brief Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
    RegAPERxPoolRetire0_t RxPoolRetire0;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_132[1];

    /** @brief Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
    RegAPERxPoolRetire1_t RxPoolRetire1;

    /** @brief  */
    RegAPETxToNetPoolModeStatus0_t TxToNetPoolModeStatus0;

    /** @brief  */
    RegAPETxToNetBufferAllocator0_t TxToNetBufferAllocator0;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_148[5];

    /** @brief Unknown, monotonically increasing value. Increases at a rate of 1MHz. */
    RegAPETick1mhz_t Tick1mhz;

    /** @brief Unknown, monotonically increasing value. Increases at a rate of 1KHz. */
    RegAPETick1khz_t Tick1khz;

    /** @brief Unknown, monotonically increasing value. Increases at a rate of 10Hz. */
    RegAPETick10hz_t Tick10hz;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_180[1];

    /** @brief  */
    RegAPEGpio_t Gpio;

    /** @brief TODO: See diag for field info. */
    RegAPEGint_t Gint;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_192[10];

    /** @brief  */
    RegAPEOtpControl_t OtpControl;

    /** @brief  */
    RegAPEOtpStatus_t OtpStatus;

    /** @brief  */
    RegAPEOtpAddr_t OtpAddr;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_244[1];

    /** @brief  */
    RegAPEOtpReadData_t OtpReadData;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_252[3];

    /** @brief Seems CPU control related. */
    RegAPECpuStatus_t CpuStatus;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_268[1];

    /** @brief  */
    RegAPETxToNetPoolModeStatus1_t TxToNetPoolModeStatus1;

    /** @brief  */
    RegAPETxToNetBufferAllocator1_t TxToNetBufferAllocator1;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_280[2];

    /** @brief Written on APE TX to network after filling 0xA002 buffer with packet. */
    RegAPETxToNetDoorbellFunc1_t TxToNetDoorbellFunc1;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_292[55];

    /** @brief This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
    RegAPERxbufoffsetFunc2_t RxbufoffsetFunc2;

    /** @brief Written on APE TX to network after filling 0xA002 buffer with packet. */
    RegAPETxToNetDoorbellFunc2_t TxToNetDoorbellFunc2;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_520[3];

    /** @brief  */
    RegAPERxPoolModeStatus2_t RxPoolModeStatus2;

    /** @brief Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
    RegAPERxPoolRetire2_t RxPoolRetire2;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_540[1];

    /** @brief  */
    RegAPETxToNetPoolModeStatus2_t TxToNetPoolModeStatus2;

    /** @brief  */
    RegAPETxToNetBufferAllocator2_t TxToNetBufferAllocator2;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_552[54];

    /** @brief This is examined on the APE Packet RX interrupt, and indicates the offset of an incoming (from-network) frame within the APE memory space, which provides access to the from-network RX buffer. */
    RegAPERxbufoffsetFunc3_t RxbufoffsetFunc3;

    /** @brief Written on APE TX to network after filling 0xA002 buffer with packet. */
    RegAPETxToNetDoorbellFunc3_t TxToNetDoorbellFunc3;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_776[3];

    /** @brief  */
    RegAPERxPoolModeStatus3_t RxPoolModeStatus3;

    /** @brief Used to indicate when the APE is done with a region of the 0xA000_0000 RX pool buffer so that it can be used to receive another frame. */
    RegAPERxPoolRetire3_t RxPoolRetire3;

    /** @brief Reserved bytes to pad out data structure. */
    APE_APE_H_uint32_t reserved_796[1];

    /** @brief  */
    RegAPETxToNetPoolModeStatus3_t TxToNetPoolModeStatus3;

    /** @brief  */
    RegAPETxToNetBufferAllocator3_t TxToNetBufferAllocator3;

#ifdef CXX_SIMULATOR
    APE_t()
    {
        Mode.r32.setComponentOffset(0x0);
        Status.r32.setComponentOffset(0x4);
        GpioMessage.r32.setComponentOffset(0x8);
        Event.r32.setComponentOffset(0xc);
        RxbufoffsetFunc0.r32.setComponentOffset(0x14);
        RxbufoffsetFunc1.r32.setComponentOffset(0x18);
        TxToNetDoorbellFunc0.r32.setComponentOffset(0x1c);
        TxState0.r32.setComponentOffset(0x20);
        Mode2.r32.setComponentOffset(0x2c);
        Status2.r32.setComponentOffset(0x30);
        LockGrantObsolete.r32.setComponentOffset(0x4c);
        RxPoolModeStatus0.r32.setComponentOffset(0x78);
        RxPoolModeStatus1.r32.setComponentOffset(0x7c);
        RxPoolRetire0.r32.setComponentOffset(0x80);
        RxPoolRetire1.r32.setComponentOffset(0x88);
        TxToNetPoolModeStatus0.r32.setComponentOffset(0x8c);
        TxToNetBufferAllocator0.r32.setComponentOffset(0x90);
        Tick1mhz.r32.setComponentOffset(0xa8);
        Tick1khz.r32.setComponentOffset(0xac);
        Tick10hz.r32.setComponentOffset(0xb0);
        Gpio.r32.setComponentOffset(0xb8);
        Gint.r32.setComponentOffset(0xbc);
        OtpControl.r32.setComponentOffset(0xe8);
        OtpStatus.r32.setComponentOffset(0xec);
        OtpAddr.r32.setComponentOffset(0xf0);
        OtpReadData.r32.setComponentOffset(0xf8);
        CpuStatus.r32.setComponentOffset(0x108);
        TxToNetPoolModeStatus1.r32.setComponentOffset(0x110);
        TxToNetBufferAllocator1.r32.setComponentOffset(0x114);
        TxToNetDoorbellFunc1.r32.setComponentOffset(0x120);
        RxbufoffsetFunc2.r32.setComponentOffset(0x200);
        TxToNetDoorbellFunc2.r32.setComponentOffset(0x204);
        RxPoolModeStatus2.r32.setComponentOffset(0x214);
        RxPoolRetire2.r32.setComponentOffset(0x218);
        TxToNetPoolModeStatus2.r32.setComponentOffset(0x220);
        TxToNetBufferAllocator2.r32.setComponentOffset(0x224);
        RxbufoffsetFunc3.r32.setComponentOffset(0x300);
        TxToNetDoorbellFunc3.r32.setComponentOffset(0x304);
        RxPoolModeStatus3.r32.setComponentOffset(0x314);
        RxPoolRetire3.r32.setComponentOffset(0x318);
        TxToNetPoolModeStatus3.r32.setComponentOffset(0x320);
        TxToNetBufferAllocator3.r32.setComponentOffset(0x324);
    }
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

#endif /* !APE_APE_H */

/** @} */
