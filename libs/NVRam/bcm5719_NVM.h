////////////////////////////////////////////////////////////////////////////////
///
/// @file       bcm5719_NVM.h
///
/// @project    bcm5719
///
/// @brief      bcm5719_NVM
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

/** @defgroup BCM5719_NVM_H    bcm5719_NVM */
/** @addtogroup BCM5719_NVM_H
 * @{
 */
#ifndef BCM5719_NVM_H
#define BCM5719_NVM_H

#include <types.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_bcm5719_NVM_sim(void* base);
void init_bcm5719_NVM(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> BCM5719_NVM_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> BCM5719_NVM_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> BCM5719_NVM_H_uint32_t;
#define BCM5719_NVM_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define BCM5719_NVM_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define BCM5719_NVM_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  BCM5719_NVM_H_uint8_t;
typedef uint16_t BCM5719_NVM_H_uint16_t;
typedef uint32_t BCM5719_NVM_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_NVM_BASE ((volatile void*)0xc0007000) /* Non-Volatile Memory Registers */
#define REG_NVM_SIZE (sizeof(NVM_t))

#define REG_NVM_COMMAND ((volatile BCM5719_NVM_H_uint32_t*)0xc0007000) /*  */
#define     NVM_COMMAND_RESET_SHIFT 1u
#define     NVM_COMMAND_RESET_MASK  0x2u
#define GET_NVM_COMMAND_RESET(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVM_COMMAND_RESET(__val__)  (((__val__) << 1u) & 0x2u)
#define     NVM_COMMAND_DONE_SHIFT 3u
#define     NVM_COMMAND_DONE_MASK  0x8u
#define GET_NVM_COMMAND_DONE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_NVM_COMMAND_DONE(__val__)  (((__val__) << 3u) & 0x8u)
#define     NVM_COMMAND_DOIT_SHIFT 4u
#define     NVM_COMMAND_DOIT_MASK  0x10u
#define GET_NVM_COMMAND_DOIT(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_NVM_COMMAND_DOIT(__val__)  (((__val__) << 4u) & 0x10u)
#define     NVM_COMMAND_WR_SHIFT 5u
#define     NVM_COMMAND_WR_MASK  0x20u
#define GET_NVM_COMMAND_WR(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_NVM_COMMAND_WR(__val__)  (((__val__) << 5u) & 0x20u)
#define     NVM_COMMAND_ERASE_SHIFT 6u
#define     NVM_COMMAND_ERASE_MASK  0x40u
#define GET_NVM_COMMAND_ERASE(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_NVM_COMMAND_ERASE(__val__)  (((__val__) << 6u) & 0x40u)
#define     NVM_COMMAND_FIRST_SHIFT 7u
#define     NVM_COMMAND_FIRST_MASK  0x80u
#define GET_NVM_COMMAND_FIRST(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_NVM_COMMAND_FIRST(__val__)  (((__val__) << 7u) & 0x80u)
#define     NVM_COMMAND_LAST_SHIFT 8u
#define     NVM_COMMAND_LAST_MASK  0x100u
#define GET_NVM_COMMAND_LAST(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_NVM_COMMAND_LAST(__val__)  (((__val__) << 8u) & 0x100u)
#define     NVM_COMMAND_WRITE_ENABLE_COMMAND_SHIFT 16u
#define     NVM_COMMAND_WRITE_ENABLE_COMMAND_MASK  0x10000u
#define GET_NVM_COMMAND_WRITE_ENABLE_COMMAND(__reg__)  (((__reg__) & 0x10000) >> 16u)
#define SET_NVM_COMMAND_WRITE_ENABLE_COMMAND(__val__)  (((__val__) << 16u) & 0x10000u)
#define     NVM_COMMAND_WRITE_DISABLE_COMMAND_SHIFT 17u
#define     NVM_COMMAND_WRITE_DISABLE_COMMAND_MASK  0x20000u
#define GET_NVM_COMMAND_WRITE_DISABLE_COMMAND(__reg__)  (((__reg__) & 0x20000) >> 17u)
#define SET_NVM_COMMAND_WRITE_DISABLE_COMMAND(__val__)  (((__val__) << 17u) & 0x20000u)

/** @brief Register definition for @ref NVM_t.Command. */
typedef register_container RegNVMCommand_t {
    /** @brief 32bit direct register access. */
    BCM5719_NVM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_NVM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_0_0, 0, 1)
        /** @brief When set, the entire NVM state machine is reset. This bit is self- clearing. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Reset, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_2_2, 2, 1)
        /** @brief Sequence completion bit that is asserted when the command requested by assertion of the doit bit has completed. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Done, 3, 1)
        /** @brief Command from software to start the defined command. The done bit must be clear before setting this bit. This bit is self clearing and will remain set while the command is active. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Doit, 4, 1)
        /** @brief The write/not read command bit. Set to execute write or erase. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Wr, 5, 1)
        /** @brief The erase command bit. Set high to execute an erase. This bit is ignored if the wr is clear. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Erase, 6, 1)
        /** @brief This bit is passed to the SEE_FSM or SPI_FSM if the pass_mode bit is set */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, First, 7, 1)
        /** @brief When this bit is set, the next command sequence is interpreted as the last one of a burst and any cleanup work is done. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Last, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_15_9, 9, 7)
        /** @brief The write enable command bit. Set '1' will make the flash interface state machine generate a write enable command cycle to the flash device to set the write enable bit in the device status register. This command is used for devices with a write protection function. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, WriteEnableCommand, 16, 1)
        /** @brief The write disable command bit. Set '1' will make the flash interface state machine generate a write disable command cycle to the flash device to clear the write enable bit in the device status register. This command is used for devices with a write protection function. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, WriteDisableCommand, 17, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_18, 18, 14)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_18, 18, 14)
        /** @brief The write disable command bit. Set '1' will make the flash interface state machine generate a write disable command cycle to the flash device to clear the write enable bit in the device status register. This command is used for devices with a write protection function. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, WriteDisableCommand, 17, 1)
        /** @brief The write enable command bit. Set '1' will make the flash interface state machine generate a write enable command cycle to the flash device to set the write enable bit in the device status register. This command is used for devices with a write protection function. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, WriteEnableCommand, 16, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_15_9, 9, 7)
        /** @brief When this bit is set, the next command sequence is interpreted as the last one of a burst and any cleanup work is done. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Last, 8, 1)
        /** @brief This bit is passed to the SEE_FSM or SPI_FSM if the pass_mode bit is set */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, First, 7, 1)
        /** @brief The erase command bit. Set high to execute an erase. This bit is ignored if the wr is clear. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Erase, 6, 1)
        /** @brief The write/not read command bit. Set to execute write or erase. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Wr, 5, 1)
        /** @brief Command from software to start the defined command. The done bit must be clear before setting this bit. This bit is self clearing and will remain set while the command is active. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Doit, 4, 1)
        /** @brief Sequence completion bit that is asserted when the command requested by assertion of the doit bit has completed. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Done, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_2_2, 2, 1)
        /** @brief When set, the entire NVM state machine is reset. This bit is self- clearing. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Reset, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_0_0, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_NVM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Command"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVMCommand_t()
    {
        /** @brief constructor for @ref NVM_t.Command. */
        r32.setName("Command");
        bits.Reset.setBaseRegister(&r32);
        bits.Reset.setName("Reset");
        bits.Done.setBaseRegister(&r32);
        bits.Done.setName("Done");
        bits.Doit.setBaseRegister(&r32);
        bits.Doit.setName("Doit");
        bits.Wr.setBaseRegister(&r32);
        bits.Wr.setName("Wr");
        bits.Erase.setBaseRegister(&r32);
        bits.Erase.setName("Erase");
        bits.First.setBaseRegister(&r32);
        bits.First.setName("First");
        bits.Last.setBaseRegister(&r32);
        bits.Last.setName("Last");
        bits.WriteEnableCommand.setBaseRegister(&r32);
        bits.WriteEnableCommand.setName("WriteEnableCommand");
        bits.WriteDisableCommand.setBaseRegister(&r32);
        bits.WriteDisableCommand.setName("WriteDisableCommand");
    }
    RegNVMCommand_t& operator=(const RegNVMCommand_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVMCommand_t;

#define REG_NVM_WRITE ((volatile BCM5719_NVM_H_uint32_t*)0xc0007008) /* 32bits of write data are used when write commands are executed. */
#define     NVM_WRITE_SCLK_OUTPUT_VALUE_SHIFT 2u
#define     NVM_WRITE_SCLK_OUTPUT_VALUE_MASK  0x4u
#define GET_NVM_WRITE_SCLK_OUTPUT_VALUE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_NVM_WRITE_SCLK_OUTPUT_VALUE(__val__)  (((__val__) << 2u) & 0x4u)
#define     NVM_WRITE_CSB_OUTPUT_VALUE_SHIFT 3u
#define     NVM_WRITE_CSB_OUTPUT_VALUE_MASK  0x8u
#define GET_NVM_WRITE_CSB_OUTPUT_VALUE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_NVM_WRITE_CSB_OUTPUT_VALUE(__val__)  (((__val__) << 3u) & 0x8u)
#define     NVM_WRITE_SI_OUTPUT_VALUE_SHIFT 4u
#define     NVM_WRITE_SI_OUTPUT_VALUE_MASK  0x10u
#define GET_NVM_WRITE_SI_OUTPUT_VALUE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_NVM_WRITE_SI_OUTPUT_VALUE(__val__)  (((__val__) << 4u) & 0x10u)
#define     NVM_WRITE_SO_OUTPUT_VALUE_SHIFT 5u
#define     NVM_WRITE_SO_OUTPUT_VALUE_MASK  0x20u
#define GET_NVM_WRITE_SO_OUTPUT_VALUE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_NVM_WRITE_SO_OUTPUT_VALUE(__val__)  (((__val__) << 5u) & 0x20u)

/** @brief Register definition for @ref NVM_t.Write. */
typedef register_container RegNVMWrite_t {
    /** @brief 32bit direct register access. */
    BCM5719_NVM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_NVM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_1_0, 0, 2)
        /** @brief When in bit-bang mode, this bit controls the SCLK output value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SCLKOutputValue, 2, 1)
        /** @brief When in bit-bang mode, this bit controls the CSb output value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, CSbOutputValue, 3, 1)
        /** @brief When in bit-bang mode, this bit controls the SI output value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SIOutputValue, 4, 1)
        /** @brief When in bit-bang mode, this bit controls the SO output value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SOOutputValue, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_6, 6, 26)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_6, 6, 26)
        /** @brief When in bit-bang mode, this bit controls the SO output value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SOOutputValue, 5, 1)
        /** @brief When in bit-bang mode, this bit controls the SI output value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SIOutputValue, 4, 1)
        /** @brief When in bit-bang mode, this bit controls the CSb output value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, CSbOutputValue, 3, 1)
        /** @brief When in bit-bang mode, this bit controls the SCLK output value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SCLKOutputValue, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_1_0, 0, 2)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_NVM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Write"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVMWrite_t()
    {
        /** @brief constructor for @ref NVM_t.Write. */
        r32.setName("Write");
        bits.SCLKOutputValue.setBaseRegister(&r32);
        bits.SCLKOutputValue.setName("SCLKOutputValue");
        bits.CSbOutputValue.setBaseRegister(&r32);
        bits.CSbOutputValue.setName("CSbOutputValue");
        bits.SIOutputValue.setBaseRegister(&r32);
        bits.SIOutputValue.setName("SIOutputValue");
        bits.SOOutputValue.setBaseRegister(&r32);
        bits.SOOutputValue.setName("SOOutputValue");
    }
    RegNVMWrite_t& operator=(const RegNVMWrite_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVMWrite_t;

#define REG_NVM_ADDR ((volatile BCM5719_NVM_H_uint32_t*)0xc000700c) /* The 24 bit address for a read or write operation (must be 4 byte aligned). */
#define     NVM_ADDR_SCLK_OUTPUT_DISABLE_SHIFT 2u
#define     NVM_ADDR_SCLK_OUTPUT_DISABLE_MASK  0x4u
#define GET_NVM_ADDR_SCLK_OUTPUT_DISABLE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_NVM_ADDR_SCLK_OUTPUT_DISABLE(__val__)  (((__val__) << 2u) & 0x4u)
#define     NVM_ADDR_CSB_OUTPUT_DISABLE_SHIFT 3u
#define     NVM_ADDR_CSB_OUTPUT_DISABLE_MASK  0x8u
#define GET_NVM_ADDR_CSB_OUTPUT_DISABLE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_NVM_ADDR_CSB_OUTPUT_DISABLE(__val__)  (((__val__) << 3u) & 0x8u)
#define     NVM_ADDR_SI_OUTPUT_DISABLE_SHIFT 4u
#define     NVM_ADDR_SI_OUTPUT_DISABLE_MASK  0x10u
#define GET_NVM_ADDR_SI_OUTPUT_DISABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_NVM_ADDR_SI_OUTPUT_DISABLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     NVM_ADDR_SO_OUTPUT_DISABLE_SHIFT 5u
#define     NVM_ADDR_SO_OUTPUT_DISABLE_MASK  0x20u
#define GET_NVM_ADDR_SO_OUTPUT_DISABLE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_NVM_ADDR_SO_OUTPUT_DISABLE(__val__)  (((__val__) << 5u) & 0x20u)

/** @brief Register definition for @ref NVM_t.Addr. */
typedef register_container RegNVMAddr_t {
    /** @brief 32bit direct register access. */
    BCM5719_NVM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_NVM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_1_0, 0, 2)
        /** @brief When in bit-bang mode, this bit controls the SCLK output enable. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SCLKOutputDisable, 2, 1)
        /** @brief When in bit-bang mode, this bit controls the CSb output enable. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, CSbOutputDisable, 3, 1)
        /** @brief When in bit-bang mode, this bit controls the SI output enable. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SIOutputDisable, 4, 1)
        /** @brief When in bit-bang mode, this bit controls the SO output enable. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SOOutputDisable, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_6, 6, 26)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_6, 6, 26)
        /** @brief When in bit-bang mode, this bit controls the SO output enable. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SOOutputDisable, 5, 1)
        /** @brief When in bit-bang mode, this bit controls the SI output enable. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SIOutputDisable, 4, 1)
        /** @brief When in bit-bang mode, this bit controls the CSb output enable. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, CSbOutputDisable, 3, 1)
        /** @brief When in bit-bang mode, this bit controls the SCLK output enable. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SCLKOutputDisable, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_1_0, 0, 2)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_NVM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Addr"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVMAddr_t()
    {
        /** @brief constructor for @ref NVM_t.Addr. */
        r32.setName("Addr");
        bits.SCLKOutputDisable.setBaseRegister(&r32);
        bits.SCLKOutputDisable.setName("SCLKOutputDisable");
        bits.CSbOutputDisable.setBaseRegister(&r32);
        bits.CSbOutputDisable.setName("CSbOutputDisable");
        bits.SIOutputDisable.setBaseRegister(&r32);
        bits.SIOutputDisable.setName("SIOutputDisable");
        bits.SOOutputDisable.setBaseRegister(&r32);
        bits.SOOutputDisable.setName("SOOutputDisable");
    }
    RegNVMAddr_t& operator=(const RegNVMAddr_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVMAddr_t;

#define REG_NVM_READ ((volatile BCM5719_NVM_H_uint32_t*)0xc0007010) /* 32bits of read data are used when read commands are executed. */
#define     NVM_READ_SCLK_INPUT_VALUE_SHIFT 2u
#define     NVM_READ_SCLK_INPUT_VALUE_MASK  0x4u
#define GET_NVM_READ_SCLK_INPUT_VALUE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_NVM_READ_SCLK_INPUT_VALUE(__val__)  (((__val__) << 2u) & 0x4u)
#define     NVM_READ_CSB_INPUT_VALUE_SHIFT 3u
#define     NVM_READ_CSB_INPUT_VALUE_MASK  0x8u
#define GET_NVM_READ_CSB_INPUT_VALUE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_NVM_READ_CSB_INPUT_VALUE(__val__)  (((__val__) << 3u) & 0x8u)
#define     NVM_READ_SI_INPUT_VALUE_SHIFT 4u
#define     NVM_READ_SI_INPUT_VALUE_MASK  0x10u
#define GET_NVM_READ_SI_INPUT_VALUE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_NVM_READ_SI_INPUT_VALUE(__val__)  (((__val__) << 4u) & 0x10u)
#define     NVM_READ_SO_INPUT_VALUE_SHIFT 5u
#define     NVM_READ_SO_INPUT_VALUE_MASK  0x20u
#define GET_NVM_READ_SO_INPUT_VALUE(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_NVM_READ_SO_INPUT_VALUE(__val__)  (((__val__) << 5u) & 0x20u)

/** @brief Register definition for @ref NVM_t.Read. */
typedef register_container RegNVMRead_t {
    /** @brief 32bit direct register access. */
    BCM5719_NVM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_NVM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_1_0, 0, 2)
        /** @brief When in bit-bang mode, this bit reads the current SCLK input value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SCLKInputValue, 2, 1)
        /** @brief When in bit-bang mode, this bit reads the current CSb input value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, CSbInputValue, 3, 1)
        /** @brief When in bit-bang mode, this bit reads the current SI input value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SIInputValue, 4, 1)
        /** @brief When in bit-bang mode, this bit reads the current SO input value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SOInputValue, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_6, 6, 26)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_6, 6, 26)
        /** @brief When in bit-bang mode, this bit reads the current SO input value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SOInputValue, 5, 1)
        /** @brief When in bit-bang mode, this bit reads the current SI input value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SIInputValue, 4, 1)
        /** @brief When in bit-bang mode, this bit reads the current CSb input value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, CSbInputValue, 3, 1)
        /** @brief When in bit-bang mode, this bit reads the current SCLK input value. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SCLKInputValue, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_1_0, 0, 2)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_NVM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Read"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVMRead_t()
    {
        /** @brief constructor for @ref NVM_t.Read. */
        r32.setName("Read");
        bits.SCLKInputValue.setBaseRegister(&r32);
        bits.SCLKInputValue.setName("SCLKInputValue");
        bits.CSbInputValue.setBaseRegister(&r32);
        bits.CSbInputValue.setName("CSbInputValue");
        bits.SIInputValue.setBaseRegister(&r32);
        bits.SIInputValue.setName("SIInputValue");
        bits.SOInputValue.setBaseRegister(&r32);
        bits.SOInputValue.setName("SOInputValue");
    }
    RegNVMRead_t& operator=(const RegNVMRead_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVMRead_t;

#define REG_NVM_NVM_CFG_1 ((volatile BCM5719_NVM_H_uint32_t*)0xc0007014) /*  */
#define     NVM_NVM_CFG_1_FLASH_MODE_SHIFT 0u
#define     NVM_NVM_CFG_1_FLASH_MODE_MASK  0x1u
#define GET_NVM_NVM_CFG_1_FLASH_MODE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_NVM_NVM_CFG_1_FLASH_MODE(__val__)  (((__val__) << 0u) & 0x1u)
#define     NVM_NVM_CFG_1_BUFFER_MODE_SHIFT 1u
#define     NVM_NVM_CFG_1_BUFFER_MODE_MASK  0x2u
#define GET_NVM_NVM_CFG_1_BUFFER_MODE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVM_NVM_CFG_1_BUFFER_MODE(__val__)  (((__val__) << 1u) & 0x2u)
#define     NVM_NVM_CFG_1_PASS_MODE_SHIFT 2u
#define     NVM_NVM_CFG_1_PASS_MODE_MASK  0x4u
#define GET_NVM_NVM_CFG_1_PASS_MODE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_NVM_NVM_CFG_1_PASS_MODE(__val__)  (((__val__) << 2u) & 0x4u)
#define     NVM_NVM_CFG_1_BITBANG_MODE_SHIFT 3u
#define     NVM_NVM_CFG_1_BITBANG_MODE_MASK  0x8u
#define GET_NVM_NVM_CFG_1_BITBANG_MODE(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_NVM_NVM_CFG_1_BITBANG_MODE(__val__)  (((__val__) << 3u) & 0x8u)
#define     NVM_NVM_CFG_1_STATUS_BIT_SHIFT 4u
#define     NVM_NVM_CFG_1_STATUS_BIT_MASK  0x70u
#define GET_NVM_NVM_CFG_1_STATUS_BIT(__reg__)  (((__reg__) & 0x70) >> 4u)
#define SET_NVM_NVM_CFG_1_STATUS_BIT(__val__)  (((__val__) << 4u) & 0x70u)
#define     NVM_NVM_CFG_1_SPI_CLK_DIV_SHIFT 7u
#define     NVM_NVM_CFG_1_SPI_CLK_DIV_MASK  0x780u
#define GET_NVM_NVM_CFG_1_SPI_CLK_DIV(__reg__)  (((__reg__) & 0x780) >> 7u)
#define SET_NVM_NVM_CFG_1_SPI_CLK_DIV(__val__)  (((__val__) << 7u) & 0x780u)
#define     NVM_NVM_CFG_1_PROTECT_MODE_SHIFT 24u
#define     NVM_NVM_CFG_1_PROTECT_MODE_MASK  0x1000000u
#define GET_NVM_NVM_CFG_1_PROTECT_MODE(__reg__)  (((__reg__) & 0x1000000) >> 24u)
#define SET_NVM_NVM_CFG_1_PROTECT_MODE(__val__)  (((__val__) << 24u) & 0x1000000u)
#define     NVM_NVM_CFG_1_FLASH_SIZE_SHIFT 25u
#define     NVM_NVM_CFG_1_FLASH_SIZE_MASK  0x2000000u
#define GET_NVM_NVM_CFG_1_FLASH_SIZE(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_NVM_NVM_CFG_1_FLASH_SIZE(__val__)  (((__val__) << 25u) & 0x2000000u)
#define     NVM_NVM_CFG_1_PAGE_SIZE_SHIFT 28u
#define     NVM_NVM_CFG_1_PAGE_SIZE_MASK  0x70000000u
#define GET_NVM_NVM_CFG_1_PAGE_SIZE(__reg__)  (((__reg__) & 0x70000000) >> 28u)
#define SET_NVM_NVM_CFG_1_PAGE_SIZE(__val__)  (((__val__) << 28u) & 0x70000000u)
#define     NVM_NVM_CFG_1_PAGE_SIZE_256_BYTES 0x0u
#define     NVM_NVM_CFG_1_PAGE_SIZE_512_BYTES 0x1u
#define     NVM_NVM_CFG_1_PAGE_SIZE_1024_BYTES 0x2u
#define     NVM_NVM_CFG_1_PAGE_SIZE_2048_BYTES 0x3u
#define     NVM_NVM_CFG_1_PAGE_SIZE_4096_BYTES 0x4u
#define     NVM_NVM_CFG_1_PAGE_SIZE_264_BYTES 0x5u


/** @brief Register definition for @ref NVM_t.NvmCfg1. */
typedef register_container RegNVMNvmCfg1_t {
    /** @brief 32bit direct register access. */
    BCM5719_NVM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_NVM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Enable Flash Interface mode. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, FlashMode, 0, 1)
        /** @brief Enable SSRAM Buffered Interface mode. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, BufferMode, 1, 1)
        /** @brief Enable pass-thorough mode to the byte level SPI and SEE state machines. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, PassMode, 2, 1)
        /** @brief Enable bit-bang mode to control pins. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, BitbangMode, 3, 1)
        /** @brief Bit Offset in status command response to interpret as the ready flag. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, StatusBit, 4, 3)
        /** @brief The equation to calculate the clock freq. for SCK is: CORE_CLK / ((SPI_CLK_DIV + 1) * 2) */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SPICLKDIV, 7, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_23_11, 11, 13)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ProtectMode, 24, 1)
        /** @brief Enables 1-Mbit devices as opposed to 512 Kbit. At CORE reset, this pin is set to the value of the SO pin. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, FlashSize, 25, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_27_26, 26, 2)
        /** @brief These bits indicate the page size of the attached flash device. They are set automatically depending on the chosen flash as indicated by the strapping option pins. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, PageSize, 28, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_31, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_31, 31, 1)
        /** @brief These bits indicate the page size of the attached flash device. They are set automatically depending on the chosen flash as indicated by the strapping option pins. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, PageSize, 28, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_27_26, 26, 2)
        /** @brief Enables 1-Mbit devices as opposed to 512 Kbit. At CORE reset, this pin is set to the value of the SO pin. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, FlashSize, 25, 1)
        /** @brief  */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ProtectMode, 24, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_23_11, 11, 13)
        /** @brief The equation to calculate the clock freq. for SCK is: CORE_CLK / ((SPI_CLK_DIV + 1) * 2) */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, SPICLKDIV, 7, 4)
        /** @brief Bit Offset in status command response to interpret as the ready flag. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, StatusBit, 4, 3)
        /** @brief Enable bit-bang mode to control pins. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, BitbangMode, 3, 1)
        /** @brief Enable pass-thorough mode to the byte level SPI and SEE state machines. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, PassMode, 2, 1)
        /** @brief Enable SSRAM Buffered Interface mode. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, BufferMode, 1, 1)
        /** @brief Enable Flash Interface mode. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, FlashMode, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_NVM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NvmCfg1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVMNvmCfg1_t()
    {
        /** @brief constructor for @ref NVM_t.NvmCfg1. */
        r32.setName("NvmCfg1");
        bits.FlashMode.setBaseRegister(&r32);
        bits.FlashMode.setName("FlashMode");
        bits.BufferMode.setBaseRegister(&r32);
        bits.BufferMode.setName("BufferMode");
        bits.PassMode.setBaseRegister(&r32);
        bits.PassMode.setName("PassMode");
        bits.BitbangMode.setBaseRegister(&r32);
        bits.BitbangMode.setName("BitbangMode");
        bits.StatusBit.setBaseRegister(&r32);
        bits.StatusBit.setName("StatusBit");
        bits.SPICLKDIV.setBaseRegister(&r32);
        bits.SPICLKDIV.setName("SPICLKDIV");
        bits.ProtectMode.setBaseRegister(&r32);
        bits.ProtectMode.setName("ProtectMode");
        bits.FlashSize.setBaseRegister(&r32);
        bits.FlashSize.setName("FlashSize");
        bits.PageSize.setBaseRegister(&r32);
        bits.PageSize.setName("PageSize");
        bits.PageSize.addEnum("256 bytes", 0x0);
        bits.PageSize.addEnum("512 bytes", 0x1);
        bits.PageSize.addEnum("1024 bytes", 0x2);
        bits.PageSize.addEnum("2048 bytes", 0x3);
        bits.PageSize.addEnum("4096 bytes", 0x4);
        bits.PageSize.addEnum("264 bytes", 0x5);

    }
    RegNVMNvmCfg1_t& operator=(const RegNVMNvmCfg1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVMNvmCfg1_t;

#define REG_NVM_NVM_CFG_2 ((volatile BCM5719_NVM_H_uint32_t*)0xc0007018) /*  */
#define     NVM_NVM_CFG_2_ERASE_COMMAND_SHIFT 0u
#define     NVM_NVM_CFG_2_ERASE_COMMAND_MASK  0xffu
#define GET_NVM_NVM_CFG_2_ERASE_COMMAND(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_NVM_NVM_CFG_2_ERASE_COMMAND(__val__)  (((__val__) << 0u) & 0xffu)
#define     NVM_NVM_CFG_2_STATUS_COMMAND_SHIFT 16u
#define     NVM_NVM_CFG_2_STATUS_COMMAND_MASK  0xff0000u
#define GET_NVM_NVM_CFG_2_STATUS_COMMAND(__reg__)  (((__reg__) & 0xff0000) >> 16u)
#define SET_NVM_NVM_CFG_2_STATUS_COMMAND(__val__)  (((__val__) << 16u) & 0xff0000u)

/** @brief Register definition for @ref NVM_t.NvmCfg2. */
typedef register_container RegNVMNvmCfg2_t {
    /** @brief 32bit direct register access. */
    BCM5719_NVM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_NVM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief This is the Flash page erase command. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, EraseCommand, 0, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_15_8, 8, 8)
        /** @brief This is the Flash status register read command. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, StatusCommand, 16, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_24, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_24, 24, 8)
        /** @brief This is the Flash status register read command. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, StatusCommand, 16, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_15_8, 8, 8)
        /** @brief This is the Flash page erase command. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, EraseCommand, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_NVM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NvmCfg2"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVMNvmCfg2_t()
    {
        /** @brief constructor for @ref NVM_t.NvmCfg2. */
        r32.setName("NvmCfg2");
        bits.EraseCommand.setBaseRegister(&r32);
        bits.EraseCommand.setName("EraseCommand");
        bits.StatusCommand.setBaseRegister(&r32);
        bits.StatusCommand.setName("StatusCommand");
    }
    RegNVMNvmCfg2_t& operator=(const RegNVMNvmCfg2_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVMNvmCfg2_t;

#define REG_NVM_NVM_CFG_3 ((volatile BCM5719_NVM_H_uint32_t*)0xc000701c) /*  */
#define     NVM_NVM_CFG_3_WRITE_COMMAND_SHIFT 8u
#define     NVM_NVM_CFG_3_WRITE_COMMAND_MASK  0xff00u
#define GET_NVM_NVM_CFG_3_WRITE_COMMAND(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_NVM_NVM_CFG_3_WRITE_COMMAND(__val__)  (((__val__) << 8u) & 0xff00u)
#define     NVM_NVM_CFG_3_READ_COMMAND_SHIFT 24u
#define     NVM_NVM_CFG_3_READ_COMMAND_MASK  0xff000000u
#define GET_NVM_NVM_CFG_3_READ_COMMAND(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_NVM_NVM_CFG_3_READ_COMMAND(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref NVM_t.NvmCfg3. */
typedef register_container RegNVMNvmCfg3_t {
    /** @brief 32bit direct register access. */
    BCM5719_NVM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_NVM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_7_0, 0, 8)
        /** @brief Command to write a series of bytes into a selected page in the Flash device. Note: this write command wraps around to the beginning of the page after the internal address counter in the Flash device reaches the end of the page. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, WriteCommand, 8, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_23_16, 16, 8)
        /** @brief This is the Flash/SEEPROM read command. Following this command, any number of bytes may be read up to the end of the flash memory. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReadCommand, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief This is the Flash/SEEPROM read command. Following this command, any number of bytes may be read up to the end of the flash memory. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReadCommand, 24, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_23_16, 16, 8)
        /** @brief Command to write a series of bytes into a selected page in the Flash device. Note: this write command wraps around to the beginning of the page after the internal address counter in the Flash device reaches the end of the page. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, WriteCommand, 8, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_7_0, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_NVM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NvmCfg3"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVMNvmCfg3_t()
    {
        /** @brief constructor for @ref NVM_t.NvmCfg3. */
        r32.setName("NvmCfg3");
        bits.WriteCommand.setBaseRegister(&r32);
        bits.WriteCommand.setName("WriteCommand");
        bits.ReadCommand.setBaseRegister(&r32);
        bits.ReadCommand.setName("ReadCommand");
    }
    RegNVMNvmCfg3_t& operator=(const RegNVMNvmCfg3_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVMNvmCfg3_t;

#define REG_NVM_SOFTWARE_ARBITRATION ((volatile BCM5719_NVM_H_uint32_t*)0xc0007020) /*  */
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET0_SHIFT 0u
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET0_MASK  0x1u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_SET0(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_SET0(__val__)  (((__val__) << 0u) & 0x1u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET1_SHIFT 1u
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET1_MASK  0x2u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_SET1(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_SET1(__val__)  (((__val__) << 1u) & 0x2u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET2_SHIFT 2u
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET2_MASK  0x4u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_SET2(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_SET2(__val__)  (((__val__) << 2u) & 0x4u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET3_SHIFT 3u
#define     NVM_SOFTWARE_ARBITRATION_REQ_SET3_MASK  0x8u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_SET3(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_SET3(__val__)  (((__val__) << 3u) & 0x8u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR0_SHIFT 4u
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR0_MASK  0x10u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_CLR0(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_CLR0(__val__)  (((__val__) << 4u) & 0x10u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR1_SHIFT 5u
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR1_MASK  0x20u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_CLR1(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_CLR1(__val__)  (((__val__) << 5u) & 0x20u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR2_SHIFT 6u
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR2_MASK  0x40u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_CLR2(__reg__)  (((__reg__) & 0x40) >> 6u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_CLR2(__val__)  (((__val__) << 6u) & 0x40u)
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR3_SHIFT 7u
#define     NVM_SOFTWARE_ARBITRATION_REQ_CLR3_MASK  0x80u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ_CLR3(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ_CLR3(__val__)  (((__val__) << 7u) & 0x80u)
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON0_SHIFT 8u
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON0_MASK  0x100u
#define GET_NVM_SOFTWARE_ARBITRATION_ARB_WON0(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_NVM_SOFTWARE_ARBITRATION_ARB_WON0(__val__)  (((__val__) << 8u) & 0x100u)
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON1_SHIFT 9u
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON1_MASK  0x200u
#define GET_NVM_SOFTWARE_ARBITRATION_ARB_WON1(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_NVM_SOFTWARE_ARBITRATION_ARB_WON1(__val__)  (((__val__) << 9u) & 0x200u)
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON2_SHIFT 10u
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON2_MASK  0x400u
#define GET_NVM_SOFTWARE_ARBITRATION_ARB_WON2(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_NVM_SOFTWARE_ARBITRATION_ARB_WON2(__val__)  (((__val__) << 10u) & 0x400u)
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON3_SHIFT 11u
#define     NVM_SOFTWARE_ARBITRATION_ARB_WON3_MASK  0x800u
#define GET_NVM_SOFTWARE_ARBITRATION_ARB_WON3(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_NVM_SOFTWARE_ARBITRATION_ARB_WON3(__val__)  (((__val__) << 11u) & 0x800u)
#define     NVM_SOFTWARE_ARBITRATION_REQ0_SHIFT 12u
#define     NVM_SOFTWARE_ARBITRATION_REQ0_MASK  0x1000u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ0(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ0(__val__)  (((__val__) << 12u) & 0x1000u)
#define     NVM_SOFTWARE_ARBITRATION_REQ1_SHIFT 13u
#define     NVM_SOFTWARE_ARBITRATION_REQ1_MASK  0x2000u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ1(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ1(__val__)  (((__val__) << 13u) & 0x2000u)
#define     NVM_SOFTWARE_ARBITRATION_REQ2_SHIFT 14u
#define     NVM_SOFTWARE_ARBITRATION_REQ2_MASK  0x4000u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ2(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ2(__val__)  (((__val__) << 14u) & 0x4000u)
#define     NVM_SOFTWARE_ARBITRATION_REQ3_SHIFT 15u
#define     NVM_SOFTWARE_ARBITRATION_REQ3_MASK  0x8000u
#define GET_NVM_SOFTWARE_ARBITRATION_REQ3(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_NVM_SOFTWARE_ARBITRATION_REQ3(__val__)  (((__val__) << 15u) & 0x8000u)

/** @brief Register definition for @ref NVM_t.SoftwareArbitration. */
typedef register_container RegNVMSoftwareArbitration_t {
    /** @brief 32bit direct register access. */
    BCM5719_NVM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_NVM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Set Software Arbitration request Bit 0. This bit is set by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqSet0, 0, 1)
        /** @brief Set Software Arbitration request Bit 1. This bit is set by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqSet1, 1, 1)
        /** @brief Set Software Arbitration request Bit 2. This bit is set by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqSet2, 2, 1)
        /** @brief Set Software Arbitration request Bit 3. This bit is set by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqSet3, 3, 1)
        /** @brief Clear Software Arbitration request Bit 0. This bit is cleared by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqClr0, 4, 1)
        /** @brief Clear Software Arbitration request Bit 1. This bit is cleared by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqClr1, 5, 1)
        /** @brief Clear Software Arbitration request Bit 2. This bit is cleared by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqClr2, 6, 1)
        /** @brief Clear Software Arbitration request Bit 3. This bit is cleared by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqClr3, 7, 1)
        /** @brief When arbitration is won, this bit will be read as 1, when an operation is complete, then the Req Clr0 must be written to clear this bit. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ArbWon0, 8, 1)
        /** @brief When arbitration is won, this bit will be read as 1, when an operation is complete, then the Req Clr1 must be written to clear this bit. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ArbWon1, 9, 1)
        /** @brief When arbitration is won, this bit will be read as 1, when an operation is complete, then the Req Clr2 must be written to clear this bit. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ArbWon2, 10, 1)
        /** @brief When arbitration is won, this bit will be read as 1, when an operation is complete, then the Req Clr3 must be written to clear this bit. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ArbWon3, 11, 1)
        /** @brief This is the status of requester 0. When this bit is one, it means that Req Set0 has been set since Req Clr0. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Req0, 12, 1)
        /** @brief This is the status of requester 1. When this bit is one, it means that Req Set1 has been set since Req Clr1. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Req1, 13, 1)
        /** @brief This is the status of requester 2. When this bit is one, it means that Req Set2 has been set since Req Clr2. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Req2, 14, 1)
        /** @brief This is the status of requester 3. When this bit is one, it means that Req Set3 has been set since Req Clr3. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Req3, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_16, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_16, 16, 16)
        /** @brief This is the status of requester 3. When this bit is one, it means that Req Set3 has been set since Req Clr3. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Req3, 15, 1)
        /** @brief This is the status of requester 2. When this bit is one, it means that Req Set2 has been set since Req Clr2. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Req2, 14, 1)
        /** @brief This is the status of requester 1. When this bit is one, it means that Req Set1 has been set since Req Clr1. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Req1, 13, 1)
        /** @brief This is the status of requester 0. When this bit is one, it means that Req Set0 has been set since Req Clr0. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Req0, 12, 1)
        /** @brief When arbitration is won, this bit will be read as 1, when an operation is complete, then the Req Clr3 must be written to clear this bit. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ArbWon3, 11, 1)
        /** @brief When arbitration is won, this bit will be read as 1, when an operation is complete, then the Req Clr2 must be written to clear this bit. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ArbWon2, 10, 1)
        /** @brief When arbitration is won, this bit will be read as 1, when an operation is complete, then the Req Clr1 must be written to clear this bit. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ArbWon1, 9, 1)
        /** @brief When arbitration is won, this bit will be read as 1, when an operation is complete, then the Req Clr0 must be written to clear this bit. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ArbWon0, 8, 1)
        /** @brief Clear Software Arbitration request Bit 3. This bit is cleared by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqClr3, 7, 1)
        /** @brief Clear Software Arbitration request Bit 2. This bit is cleared by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqClr2, 6, 1)
        /** @brief Clear Software Arbitration request Bit 1. This bit is cleared by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqClr1, 5, 1)
        /** @brief Clear Software Arbitration request Bit 0. This bit is cleared by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqClr0, 4, 1)
        /** @brief Set Software Arbitration request Bit 3. This bit is set by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqSet3, 3, 1)
        /** @brief Set Software Arbitration request Bit 2. This bit is set by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqSet2, 2, 1)
        /** @brief Set Software Arbitration request Bit 1. This bit is set by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqSet1, 1, 1)
        /** @brief Set Software Arbitration request Bit 0. This bit is set by writing a 1 to this bit position. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, ReqSet0, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_NVM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SoftwareArbitration"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVMSoftwareArbitration_t()
    {
        /** @brief constructor for @ref NVM_t.SoftwareArbitration. */
        r32.setName("SoftwareArbitration");
        bits.ReqSet0.setBaseRegister(&r32);
        bits.ReqSet0.setName("ReqSet0");
        bits.ReqSet1.setBaseRegister(&r32);
        bits.ReqSet1.setName("ReqSet1");
        bits.ReqSet2.setBaseRegister(&r32);
        bits.ReqSet2.setName("ReqSet2");
        bits.ReqSet3.setBaseRegister(&r32);
        bits.ReqSet3.setName("ReqSet3");
        bits.ReqClr0.setBaseRegister(&r32);
        bits.ReqClr0.setName("ReqClr0");
        bits.ReqClr1.setBaseRegister(&r32);
        bits.ReqClr1.setName("ReqClr1");
        bits.ReqClr2.setBaseRegister(&r32);
        bits.ReqClr2.setName("ReqClr2");
        bits.ReqClr3.setBaseRegister(&r32);
        bits.ReqClr3.setName("ReqClr3");
        bits.ArbWon0.setBaseRegister(&r32);
        bits.ArbWon0.setName("ArbWon0");
        bits.ArbWon1.setBaseRegister(&r32);
        bits.ArbWon1.setName("ArbWon1");
        bits.ArbWon2.setBaseRegister(&r32);
        bits.ArbWon2.setName("ArbWon2");
        bits.ArbWon3.setBaseRegister(&r32);
        bits.ArbWon3.setName("ArbWon3");
        bits.Req0.setBaseRegister(&r32);
        bits.Req0.setName("Req0");
        bits.Req1.setBaseRegister(&r32);
        bits.Req1.setName("Req1");
        bits.Req2.setBaseRegister(&r32);
        bits.Req2.setName("Req2");
        bits.Req3.setBaseRegister(&r32);
        bits.Req3.setName("Req3");
    }
    RegNVMSoftwareArbitration_t& operator=(const RegNVMSoftwareArbitration_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVMSoftwareArbitration_t;

#define REG_NVM_ACCESS ((volatile BCM5719_NVM_H_uint32_t*)0xc0007024) /*  */
#define     NVM_ACCESS_ENABLE_SHIFT 0u
#define     NVM_ACCESS_ENABLE_MASK  0x1u
#define GET_NVM_ACCESS_ENABLE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_NVM_ACCESS_ENABLE(__val__)  (((__val__) << 0u) & 0x1u)
#define     NVM_ACCESS_WRITE_ENABLE_SHIFT 1u
#define     NVM_ACCESS_WRITE_ENABLE_MASK  0x2u
#define GET_NVM_ACCESS_WRITE_ENABLE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVM_ACCESS_WRITE_ENABLE(__val__)  (((__val__) << 1u) & 0x2u)

/** @brief Register definition for @ref NVM_t.Access. */
typedef register_container RegNVMAccess_t {
    /** @brief 32bit direct register access. */
    BCM5719_NVM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_NVM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief When 1, allows the NVRAM write command to be issued even if the NVRAM write enable bit 21 of the mode control register 0x6800. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Enable, 0, 1)
        /** @brief When 0, prevents write access to all other NVRAM registers, except for the Software arbitration register. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, WriteEnable, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_2, 2, 30)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_2, 2, 30)
        /** @brief When 0, prevents write access to all other NVRAM registers, except for the Software arbitration register. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, WriteEnable, 1, 1)
        /** @brief When 1, allows the NVRAM write command to be issued even if the NVRAM write enable bit 21 of the mode control register 0x6800. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, Enable, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_NVM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "Access"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVMAccess_t()
    {
        /** @brief constructor for @ref NVM_t.Access. */
        r32.setName("Access");
        bits.Enable.setBaseRegister(&r32);
        bits.Enable.setName("Enable");
        bits.WriteEnable.setBaseRegister(&r32);
        bits.WriteEnable.setName("WriteEnable");
    }
    RegNVMAccess_t& operator=(const RegNVMAccess_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVMAccess_t;

#define REG_NVM_NVM_WRITE_1 ((volatile BCM5719_NVM_H_uint32_t*)0xc0007028) /*  */
#define     NVM_NVM_WRITE_1_WRITE_ENABLE_COMMAND_SHIFT 0u
#define     NVM_NVM_WRITE_1_WRITE_ENABLE_COMMAND_MASK  0xffu
#define GET_NVM_NVM_WRITE_1_WRITE_ENABLE_COMMAND(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_NVM_NVM_WRITE_1_WRITE_ENABLE_COMMAND(__val__)  (((__val__) << 0u) & 0xffu)
#define     NVM_NVM_WRITE_1_WRITE_DISABLE_COMMAND_SHIFT 8u
#define     NVM_NVM_WRITE_1_WRITE_DISABLE_COMMAND_MASK  0xff00u
#define GET_NVM_NVM_WRITE_1_WRITE_DISABLE_COMMAND(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_NVM_NVM_WRITE_1_WRITE_DISABLE_COMMAND(__val__)  (((__val__) << 8u) & 0xff00u)

/** @brief Register definition for @ref NVM_t.NvmWrite1. */
typedef register_container RegNVMNvmWrite1_t {
    /** @brief 32bit direct register access. */
    BCM5719_NVM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_NVM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Flash write enable command when device with protection function is used. This command will be issued by the flash interface state machine through SPI interface. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, WriteEnableCommand, 0, 8)
        /** @brief Flash write disable command when device with protection function is used. This command will be issued by the flash interface state machine through SPI interface. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, WriteDisableCommand, 8, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_16, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_16, 16, 16)
        /** @brief Flash write disable command when device with protection function is used. This command will be issued by the flash interface state machine through SPI interface. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, WriteDisableCommand, 8, 8)
        /** @brief Flash write enable command when device with protection function is used. This command will be issued by the flash interface state machine through SPI interface. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, WriteEnableCommand, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_NVM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "NvmWrite1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVMNvmWrite1_t()
    {
        /** @brief constructor for @ref NVM_t.NvmWrite1. */
        r32.setName("NvmWrite1");
        bits.WriteEnableCommand.setBaseRegister(&r32);
        bits.WriteEnableCommand.setName("WriteEnableCommand");
        bits.WriteDisableCommand.setBaseRegister(&r32);
        bits.WriteDisableCommand.setName("WriteDisableCommand");
    }
    RegNVMNvmWrite1_t& operator=(const RegNVMNvmWrite1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVMNvmWrite1_t;

#define REG_NVM_ARBITRATION_WATCHDOG ((volatile BCM5719_NVM_H_uint32_t*)0xc000702c) /*  */
#define     NVM_ARBITRATION_WATCHDOG_RESERVED_SHIFT 0u
#define     NVM_ARBITRATION_WATCHDOG_RESERVED_MASK  0xffffffffu
#define GET_NVM_ARBITRATION_WATCHDOG_RESERVED(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_NVM_ARBITRATION_WATCHDOG_RESERVED(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref NVM_t.ArbitrationWatchdog. */
typedef register_container RegNVMArbitrationWatchdog_t {
    /** @brief 32bit direct register access. */
    BCM5719_NVM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_NVM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Reserved */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Reserved */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_NVM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ArbitrationWatchdog"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVMArbitrationWatchdog_t()
    {
        /** @brief constructor for @ref NVM_t.ArbitrationWatchdog. */
        r32.setName("ArbitrationWatchdog");
        bits.reserved.setBaseRegister(&r32);
        bits.reserved.setName("reserved");
    }
    RegNVMArbitrationWatchdog_t& operator=(const RegNVMArbitrationWatchdog_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVMArbitrationWatchdog_t;

#define REG_NVM_AUTO_SENSE_STATUS ((volatile BCM5719_NVM_H_uint32_t*)0xc0007038) /*  */
#define     NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_BUSY_SHIFT 0u
#define     NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_BUSY_MASK  0x1u
#define GET_NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_BUSY(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_BUSY(__val__)  (((__val__) << 0u) & 0x1u)
#define     NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_ENABLE_SHIFT 4u
#define     NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_ENABLE_MASK  0x10u
#define GET_NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_ENABLE(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_ENABLE(__val__)  (((__val__) << 4u) & 0x10u)
#define     NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_SUCCESSFUL_SHIFT 5u
#define     NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_SUCCESSFUL_MASK  0x20u
#define GET_NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_SUCCESSFUL(__reg__)  (((__reg__) & 0x20) >> 5u)
#define SET_NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_SUCCESSFUL(__val__)  (((__val__) << 5u) & 0x20u)
#define     NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_STATE_SHIFT 8u
#define     NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_STATE_MASK  0x1f00u
#define GET_NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_STATE(__reg__)  (((__reg__) & 0x1f00) >> 8u)
#define SET_NVM_AUTO_SENSE_STATUS_AUTO_CONFIG_STATE(__val__)  (((__val__) << 8u) & 0x1f00u)
#define     NVM_AUTO_SENSE_STATUS_AUTO_DETECTED_DEVICE_ID_SHIFT 16u
#define     NVM_AUTO_SENSE_STATUS_AUTO_DETECTED_DEVICE_ID_MASK  0x1f0000u
#define GET_NVM_AUTO_SENSE_STATUS_AUTO_DETECTED_DEVICE_ID(__reg__)  (((__reg__) & 0x1f0000) >> 16u)
#define SET_NVM_AUTO_SENSE_STATUS_AUTO_DETECTED_DEVICE_ID(__val__)  (((__val__) << 16u) & 0x1f0000u)
#define     NVM_AUTO_SENSE_STATUS_AUTO_DETECTED_DEVICE_ID_AT45DB041D 0x0u
#define     NVM_AUTO_SENSE_STATUS_AUTO_DETECTED_DEVICE_ID_AT45DB021D 0x3u
#define     NVM_AUTO_SENSE_STATUS_AUTO_DETECTED_DEVICE_ID_AT45DB011D 0x4u
#define     NVM_AUTO_SENSE_STATUS_AUTO_DETECTED_DEVICE_ID_STM25PE40 0x8u
#define     NVM_AUTO_SENSE_STATUS_AUTO_DETECTED_DEVICE_ID_STM25PE20 0xau
#define     NVM_AUTO_SENSE_STATUS_AUTO_DETECTED_DEVICE_ID_STM25PE10 0xbu
#define     NVM_AUTO_SENSE_STATUS_AUTO_DETECTED_DEVICE_ID_STM45PE10 0xcu
#define     NVM_AUTO_SENSE_STATUS_AUTO_DETECTED_DEVICE_ID_STM45PE20 0xdu
#define     NVM_AUTO_SENSE_STATUS_AUTO_DETECTED_DEVICE_ID_STM45PE40 0xeu


/** @brief Register definition for @ref NVM_t.AutoSenseStatus. */
typedef register_container RegNVMAutoSenseStatus_t {
    /** @brief 32bit direct register access. */
    BCM5719_NVM_H_uint32_t r32;

    BITFIELD_BEGIN(BCM5719_NVM_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Auto Configuration Busy */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, AutoConfigBusy, 0, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_3_1, 1, 3)
        /** @brief Auto config feature is enabled through pin strap. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, AutoConfigEnable, 4, 1)
        /** @brief Auto config is successful. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, AutoConfigSuccessful, 5, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_7_6, 6, 2)
        /** @brief Auto Config FSM state. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, AutoConfigState, 8, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_15_13, 13, 3)
        /** @brief Auto detected device ID. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, AutoDetectedDeviceID, 16, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_21, 21, 11)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_31_21, 21, 11)
        /** @brief Auto detected device ID. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, AutoDetectedDeviceID, 16, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_15_13, 13, 3)
        /** @brief Auto Config FSM state. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, AutoConfigState, 8, 5)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_7_6, 6, 2)
        /** @brief Auto config is successful. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, AutoConfigSuccessful, 5, 1)
        /** @brief Auto config feature is enabled through pin strap. */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, AutoConfigEnable, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, reserved_3_1, 1, 3)
        /** @brief Auto Configuration Busy */
        BITFIELD_MEMBER(BCM5719_NVM_H_uint32_t, AutoConfigBusy, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(BCM5719_NVM_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "AutoSenseStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVMAutoSenseStatus_t()
    {
        /** @brief constructor for @ref NVM_t.AutoSenseStatus. */
        r32.setName("AutoSenseStatus");
        bits.AutoConfigBusy.setBaseRegister(&r32);
        bits.AutoConfigBusy.setName("AutoConfigBusy");
        bits.AutoConfigEnable.setBaseRegister(&r32);
        bits.AutoConfigEnable.setName("AutoConfigEnable");
        bits.AutoConfigSuccessful.setBaseRegister(&r32);
        bits.AutoConfigSuccessful.setName("AutoConfigSuccessful");
        bits.AutoConfigState.setBaseRegister(&r32);
        bits.AutoConfigState.setName("AutoConfigState");
        bits.AutoDetectedDeviceID.setBaseRegister(&r32);
        bits.AutoDetectedDeviceID.setName("AutoDetectedDeviceID");
        bits.AutoDetectedDeviceID.addEnum("AT45DB041D", 0x0);
        bits.AutoDetectedDeviceID.addEnum("AT45DB021D", 0x3);
        bits.AutoDetectedDeviceID.addEnum("AT45DB011D", 0x4);
        bits.AutoDetectedDeviceID.addEnum("STM25PE40", 0x8);
        bits.AutoDetectedDeviceID.addEnum("STM25PE20", 0xa);
        bits.AutoDetectedDeviceID.addEnum("STM25PE10", 0xb);
        bits.AutoDetectedDeviceID.addEnum("STM45PE10", 0xc);
        bits.AutoDetectedDeviceID.addEnum("STM45PE20", 0xd);
        bits.AutoDetectedDeviceID.addEnum("STM45PE40", 0xe);

    }
    RegNVMAutoSenseStatus_t& operator=(const RegNVMAutoSenseStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVMAutoSenseStatus_t;

/** @brief Component definition for @ref NVM. */
typedef struct NVM_t {
    /** @brief  */
    RegNVMCommand_t Command;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_NVM_H_uint32_t reserved_4[1];

    /** @brief 32bits of write data are used when write commands are executed. */
    RegNVMWrite_t Write;

    /** @brief The 24 bit address for a read or write operation (must be 4 byte aligned). */
    RegNVMAddr_t Addr;

    /** @brief 32bits of read data are used when read commands are executed. */
    RegNVMRead_t Read;

    /** @brief  */
    RegNVMNvmCfg1_t NvmCfg1;

    /** @brief  */
    RegNVMNvmCfg2_t NvmCfg2;

    /** @brief  */
    RegNVMNvmCfg3_t NvmCfg3;

    /** @brief  */
    RegNVMSoftwareArbitration_t SoftwareArbitration;

    /** @brief  */
    RegNVMAccess_t Access;

    /** @brief  */
    RegNVMNvmWrite1_t NvmWrite1;

    /** @brief  */
    RegNVMArbitrationWatchdog_t ArbitrationWatchdog;

    /** @brief Reserved bytes to pad out data structure. */
    BCM5719_NVM_H_uint32_t reserved_48[2];

    /** @brief  */
    RegNVMAutoSenseStatus_t AutoSenseStatus;

#ifdef CXX_SIMULATOR
    NVM_t()
    {
        Command.r32.setComponentOffset(0x0);
        for(int i = 0; i < 1; i++)
        {
            reserved_4[i].setComponentOffset(0x4 + (i * 4));
        }
        Write.r32.setComponentOffset(0x8);
        Addr.r32.setComponentOffset(0xc);
        Read.r32.setComponentOffset(0x10);
        NvmCfg1.r32.setComponentOffset(0x14);
        NvmCfg2.r32.setComponentOffset(0x18);
        NvmCfg3.r32.setComponentOffset(0x1c);
        SoftwareArbitration.r32.setComponentOffset(0x20);
        Access.r32.setComponentOffset(0x24);
        NvmWrite1.r32.setComponentOffset(0x28);
        ArbitrationWatchdog.r32.setComponentOffset(0x2c);
        for(int i = 0; i < 2; i++)
        {
            reserved_48[i].setComponentOffset(0x30 + (i * 4));
        }
        AutoSenseStatus.r32.setComponentOffset(0x38);
    }
    void print()
    {
        Command.print();
        for(int i = 0; i < 1; i++)
        {
            reserved_4[i].print();
        }
        Write.print();
        Addr.print();
        Read.print();
        NvmCfg1.print();
        NvmCfg2.print();
        NvmCfg3.print();
        SoftwareArbitration.print();
        Access.print();
        NvmWrite1.print();
        ArbitrationWatchdog.print();
        for(int i = 0; i < 2; i++)
        {
            reserved_48[i].print();
        }
        AutoSenseStatus.print();
    }
    typedef uint32_t (*callback_t)(uint32_t, uint32_t, void*);
    callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    uint32_t read(int offset) { return mIndexReadCallback(0, offset, mIndexReadCallbackArgs); }
    void write(int offset, uint32_t value) { (void)mIndexWriteCallback(value, offset, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
} NVM_t;

/** @brief Non-Volatile Memory Registers */
extern volatile NVM_t NVM;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !BCM5719_NVM_H */

/** @} */
