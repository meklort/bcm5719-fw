////////////////////////////////////////////////////////////////////////////////
///
/// @file       APE_NVIC.h
///
/// @project    ape
///
/// @brief      APE_NVIC
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

/** @defgroup APE_NVIC_H    APE_NVIC */
/** @addtogroup APE_NVIC_H
 * @{
 */
#ifndef APE_NVIC_H
#define APE_NVIC_H

#include <stdint.h>

#ifdef CXX_SIMULATOR /* Compiling c++ simulator code - uses register wrappers */
void init_APE_NVIC_mmap(void* base);
void init_APE_NVIC(void);

#include <CXXRegister.h>
typedef CXXRegister<uint8_t,  0,  8> APE_NVIC_H_uint8_t;
typedef CXXRegister<uint16_t, 0, 16> APE_NVIC_H_uint16_t;
typedef CXXRegister<uint32_t, 0, 32> APE_NVIC_H_uint32_t;
#define APE_NVIC_H_uint8_t_bitfield(__pos__, __width__)  CXXRegister<uint8_t,  __pos__, __width__>
#define APE_NVIC_H_uint16_t_bitfield(__pos__, __width__) CXXRegister<uint16_t, __pos__, __width__>
#define APE_NVIC_H_uint32_t_bitfield(__pos__, __width__) CXXRegister<uint32_t, __pos__, __width__>
#define register_container struct
#define volatile
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__##_bitfield(__offset__, __bits__) __name__;
#define BITFIELD_END(__type__, __name__) } __name__;

#else /* Firmware Data types */
typedef uint8_t  APE_NVIC_H_uint8_t;
typedef uint16_t APE_NVIC_H_uint16_t;
typedef uint32_t APE_NVIC_H_uint32_t;
#define register_container union
#define BITFIELD_BEGIN(__type__, __name__) struct {
#define BITFIELD_MEMBER(__type__, __name__, __offset__, __bits__) __type__ __name__:__bits__;
#define BITFIELD_END(__type__, __name__) } __name__;
#endif /* !CXX_SIMULATOR */

#define REG_NVIC_BASE ((volatile void*)0x380038000) /* Nested Vectored Interrupt Controller */
#define REG_NVIC_SIZE (sizeof(NVIC_t))

#define REG_NVIC_INTERRUPT_CONTROL_TYPE ((volatile APE_NVIC_H_uint32_t*)0xe000e004) /* Read the Interrupt Controller Type Register to see the number of interrupt lines that the NVIC supports. */
#define     NVIC_INTERRUPT_CONTROL_TYPE_INTLINESNUM_SHIFT 0u
#define     NVIC_INTERRUPT_CONTROL_TYPE_INTLINESNUM_MASK  0xfu
#define GET_NVIC_INTERRUPT_CONTROL_TYPE_INTLINESNUM(__reg__)  (((__reg__) & 0xf) >> 0u)
#define SET_NVIC_INTERRUPT_CONTROL_TYPE_INTLINESNUM(__val__)  (((__val__) << 0u) & 0xfu)
#define     NVIC_INTERRUPT_CONTROL_TYPE_INTLINESNUM_0_TO_32 0x0u
#define     NVIC_INTERRUPT_CONTROL_TYPE_INTLINESNUM_33_TO_64 0x1u
#define     NVIC_INTERRUPT_CONTROL_TYPE_INTLINESNUM_65_TO_96 0x2u


/** @brief Register definition for @ref NVIC_t.InterruptControlType. */
typedef register_container RegNVICInterruptControlType_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief  */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, INTLINESNUM, 0, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_4, 4, 28)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_4, 4, 28)
        /** @brief  */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, INTLINESNUM, 0, 4)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "InterruptControlType"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICInterruptControlType_t()
    {
        /** @brief constructor for @ref NVIC_t.InterruptControlType. */
        r32.setName("InterruptControlType");
        bits.INTLINESNUM.setBaseRegister(&r32);
        bits.INTLINESNUM.setName("INTLINESNUM");
    }
    RegNVICInterruptControlType_t& operator=(const RegNVICInterruptControlType_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICInterruptControlType_t;

#define REG_NVIC_SYSTICK_CONTROL_AND_STATUS ((volatile APE_NVIC_H_uint32_t*)0xe000e010) /* Use the SysTick Control and Status Register to enable the SysTick features. */
#define     NVIC_SYSTICK_CONTROL_AND_STATUS_ENABLE_SHIFT 0u
#define     NVIC_SYSTICK_CONTROL_AND_STATUS_ENABLE_MASK  0x1u
#define GET_NVIC_SYSTICK_CONTROL_AND_STATUS_ENABLE(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_NVIC_SYSTICK_CONTROL_AND_STATUS_ENABLE(__val__)  (((__val__) << 0u) & 0x1u)
#define     NVIC_SYSTICK_CONTROL_AND_STATUS_TICKINT_SHIFT 1u
#define     NVIC_SYSTICK_CONTROL_AND_STATUS_TICKINT_MASK  0x2u
#define GET_NVIC_SYSTICK_CONTROL_AND_STATUS_TICKINT(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVIC_SYSTICK_CONTROL_AND_STATUS_TICKINT(__val__)  (((__val__) << 1u) & 0x2u)
#define     NVIC_SYSTICK_CONTROL_AND_STATUS_CLKSOURCE_SHIFT 2u
#define     NVIC_SYSTICK_CONTROL_AND_STATUS_CLKSOURCE_MASK  0x4u
#define GET_NVIC_SYSTICK_CONTROL_AND_STATUS_CLKSOURCE(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_NVIC_SYSTICK_CONTROL_AND_STATUS_CLKSOURCE(__val__)  (((__val__) << 2u) & 0x4u)
#define     NVIC_SYSTICK_CONTROL_AND_STATUS_COUNTFLAG_SHIFT 16u
#define     NVIC_SYSTICK_CONTROL_AND_STATUS_COUNTFLAG_MASK  0x10000u
#define GET_NVIC_SYSTICK_CONTROL_AND_STATUS_COUNTFLAG(__reg__)  (((__reg__) & 0x10000) >> 16u)
#define SET_NVIC_SYSTICK_CONTROL_AND_STATUS_COUNTFLAG(__val__)  (((__val__) << 16u) & 0x10000u)

/** @brief Register definition for @ref NVIC_t.SystickControlAndStatus. */
typedef register_container RegNVICSystickControlAndStatus_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief It set, counter loads with the Reload value and then begins counting down. On reaching 0, it sets the COUNTFLAG to 1 and optionally pends the SysTick handler, based on TICKINT. It then loads the Reload value again, and begins counting. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ENABLE, 0, 1)
        /** @brief If set, counting down to 0 pends the SysTick handler. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, TICKINT, 1, 1)
        /** @brief If no reference clock is provided, it is held at 1 and so gives the same time as the core clock. The core clock must be at least 2.5 times faster than the reference clock. If it is not, the count values are Unpredictable. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, CLKSOURCE, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_15_3, 3, 13)
        /** @brief Returns 1 if timer counted to 0 since last time this was read. Clears on read by application of any part of the SysTick Control and Status Register. If read by the debugger using the DAP, this bit is cleared on read-only if the MasterType bit in the AHB-AP Control Register is set to 0. Otherwise, the COUNTFLAG bit is not changed by the debugger read. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, COUNTFLAG, 16, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_17, 17, 15)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_17, 17, 15)
        /** @brief Returns 1 if timer counted to 0 since last time this was read. Clears on read by application of any part of the SysTick Control and Status Register. If read by the debugger using the DAP, this bit is cleared on read-only if the MasterType bit in the AHB-AP Control Register is set to 0. Otherwise, the COUNTFLAG bit is not changed by the debugger read. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, COUNTFLAG, 16, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_15_3, 3, 13)
        /** @brief If no reference clock is provided, it is held at 1 and so gives the same time as the core clock. The core clock must be at least 2.5 times faster than the reference clock. If it is not, the count values are Unpredictable. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, CLKSOURCE, 2, 1)
        /** @brief If set, counting down to 0 pends the SysTick handler. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, TICKINT, 1, 1)
        /** @brief It set, counter loads with the Reload value and then begins counting down. On reaching 0, it sets the COUNTFLAG to 1 and optionally pends the SysTick handler, based on TICKINT. It then loads the Reload value again, and begins counting. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ENABLE, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SystickControlAndStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICSystickControlAndStatus_t()
    {
        /** @brief constructor for @ref NVIC_t.SystickControlAndStatus. */
        r32.setName("SystickControlAndStatus");
        bits.ENABLE.setBaseRegister(&r32);
        bits.ENABLE.setName("ENABLE");
        bits.TICKINT.setBaseRegister(&r32);
        bits.TICKINT.setName("TICKINT");
        bits.CLKSOURCE.setBaseRegister(&r32);
        bits.CLKSOURCE.setName("CLKSOURCE");
        bits.COUNTFLAG.setBaseRegister(&r32);
        bits.COUNTFLAG.setName("COUNTFLAG");
    }
    RegNVICSystickControlAndStatus_t& operator=(const RegNVICSystickControlAndStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICSystickControlAndStatus_t;

#define REG_NVIC_SYSTICK_RELOAD_VALUE ((volatile APE_NVIC_H_uint32_t*)0xe000e014) /* Use the SysTick Reload Value Register to specify the start value to load into the current value register when the counter reaches 0. It can be any value between 1 and 0x00FFFFFF. A start value of 0 is possible, but has no effect because the SysTick interrupt and COUNTFLAG are activated when counting from 1 to 0. */
#define     NVIC_SYSTICK_RELOAD_VALUE_RELOAD_SHIFT 0u
#define     NVIC_SYSTICK_RELOAD_VALUE_RELOAD_MASK  0xffffffu
#define GET_NVIC_SYSTICK_RELOAD_VALUE_RELOAD(__reg__)  (((__reg__) & 0xffffff) >> 0u)
#define SET_NVIC_SYSTICK_RELOAD_VALUE_RELOAD(__val__)  (((__val__) << 0u) & 0xffffffu)

/** @brief Register definition for @ref NVIC_t.SystickReloadValue. */
typedef register_container RegNVICSystickReloadValue_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Value to load into the SysTick Current Value Register when the counter reaches 0. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, RELOAD, 0, 24)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_24, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_24, 24, 8)
        /** @brief Value to load into the SysTick Current Value Register when the counter reaches 0. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, RELOAD, 0, 24)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SystickReloadValue"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICSystickReloadValue_t()
    {
        /** @brief constructor for @ref NVIC_t.SystickReloadValue. */
        r32.setName("SystickReloadValue");
        bits.RELOAD.setBaseRegister(&r32);
        bits.RELOAD.setName("RELOAD");
    }
    RegNVICSystickReloadValue_t& operator=(const RegNVICSystickReloadValue_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICSystickReloadValue_t;

#define REG_NVIC_SYSTICK_CURRENT_VALUE ((volatile APE_NVIC_H_uint32_t*)0xe000e018) /* Use the SysTick Current Value Register to find the current value in the register. */
#define     NVIC_SYSTICK_CURRENT_VALUE_CURRENT_SHIFT 0u
#define     NVIC_SYSTICK_CURRENT_VALUE_CURRENT_MASK  0xffffffu
#define GET_NVIC_SYSTICK_CURRENT_VALUE_CURRENT(__reg__)  (((__reg__) & 0xffffff) >> 0u)
#define SET_NVIC_SYSTICK_CURRENT_VALUE_CURRENT(__val__)  (((__val__) << 0u) & 0xffffffu)

/** @brief Register definition for @ref NVIC_t.SystickCurrentValue. */
typedef register_container RegNVICSystickCurrentValue_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Current value at the time the register is accessed. No read-modify-write protection is provided, so change with care. This register is write-clear. Writing to it with any value clears the register to 0. Clearing this register also clears the COUNTFLAG bit of the SysTick Control and Status Register. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, CURRENT, 0, 24)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_24, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_24, 24, 8)
        /** @brief Current value at the time the register is accessed. No read-modify-write protection is provided, so change with care. This register is write-clear. Writing to it with any value clears the register to 0. Clearing this register also clears the COUNTFLAG bit of the SysTick Control and Status Register. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, CURRENT, 0, 24)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SystickCurrentValue"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICSystickCurrentValue_t()
    {
        /** @brief constructor for @ref NVIC_t.SystickCurrentValue. */
        r32.setName("SystickCurrentValue");
        bits.CURRENT.setBaseRegister(&r32);
        bits.CURRENT.setName("CURRENT");
    }
    RegNVICSystickCurrentValue_t& operator=(const RegNVICSystickCurrentValue_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICSystickCurrentValue_t;

#define REG_NVIC_SYSTICK_CALIBRATION_VALUE ((volatile APE_NVIC_H_uint32_t*)0xe000e01c) /* Use the SysTick Calibration Value Register to enable software to scale to any required speed using divide and multiply. */
#define     NVIC_SYSTICK_CALIBRATION_VALUE_TENMS_SHIFT 0u
#define     NVIC_SYSTICK_CALIBRATION_VALUE_TENMS_MASK  0xffffffu
#define GET_NVIC_SYSTICK_CALIBRATION_VALUE_TENMS(__reg__)  (((__reg__) & 0xffffff) >> 0u)
#define SET_NVIC_SYSTICK_CALIBRATION_VALUE_TENMS(__val__)  (((__val__) << 0u) & 0xffffffu)
#define     NVIC_SYSTICK_CALIBRATION_VALUE_SKEW_SHIFT 30u
#define     NVIC_SYSTICK_CALIBRATION_VALUE_SKEW_MASK  0x40000000u
#define GET_NVIC_SYSTICK_CALIBRATION_VALUE_SKEW(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_NVIC_SYSTICK_CALIBRATION_VALUE_SKEW(__val__)  (((__val__) << 30u) & 0x40000000u)
#define     NVIC_SYSTICK_CALIBRATION_VALUE_NOREF_SHIFT 31u
#define     NVIC_SYSTICK_CALIBRATION_VALUE_NOREF_MASK  0x80000000u
#define GET_NVIC_SYSTICK_CALIBRATION_VALUE_NOREF(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_NVIC_SYSTICK_CALIBRATION_VALUE_NOREF(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref NVIC_t.SystickCalibrationValue. */
typedef register_container RegNVICSystickCalibrationValue_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief This value is the Reload value to use for 10ms timing. Depending on the value of SKEW, this might be exactly 10ms or might be the closest value. If this reads as 0, then the calibration value is not known. This is probably because the reference clock is an unknown input from the system or scalable dynamically. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, TENMS, 0, 24)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_29_24, 24, 6)
        /** @brief 1 = the calibration value is not exactly 10ms because of clock frequency. This could affect its suitability as a software real time clock. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SKEW, 30, 1)
        /** @brief 1 = the reference clock is not provided. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, NOREF, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief 1 = the reference clock is not provided. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, NOREF, 31, 1)
        /** @brief 1 = the calibration value is not exactly 10ms because of clock frequency. This could affect its suitability as a software real time clock. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SKEW, 30, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_29_24, 24, 6)
        /** @brief This value is the Reload value to use for 10ms timing. Depending on the value of SKEW, this might be exactly 10ms or might be the closest value. If this reads as 0, then the calibration value is not known. This is probably because the reference clock is an unknown input from the system or scalable dynamically. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, TENMS, 0, 24)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SystickCalibrationValue"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICSystickCalibrationValue_t()
    {
        /** @brief constructor for @ref NVIC_t.SystickCalibrationValue. */
        r32.setName("SystickCalibrationValue");
        bits.TENMS.setBaseRegister(&r32);
        bits.TENMS.setName("TENMS");
        bits.SKEW.setBaseRegister(&r32);
        bits.SKEW.setName("SKEW");
        bits.NOREF.setBaseRegister(&r32);
        bits.NOREF.setName("NOREF");
    }
    RegNVICSystickCalibrationValue_t& operator=(const RegNVICSystickCalibrationValue_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICSystickCalibrationValue_t;

#define REG_NVIC_INTERRUPT_SET_ENABLE ((volatile APE_NVIC_H_uint32_t*)0xe000e100) /* Each bit in the register corresponds to one of 32 interrupts. Setting a bit in the Interrupt Set-Enable Register enables the corresponding interrupt. When the enable bit of a pending interrupt is set, the processor activates the interrupt based on its priority. When the enable bit is clear, asserting its interrupt signal pends the interrupt, but it is not possible to activate the interrupt, regardless of its priority. Therefore, a disabled interrupt can serve as a latched general-purpose I/O bit. You can read it and clear it without invoking an interrupt. */
#define     NVIC_INTERRUPT_SET_ENABLE_SETENA_SHIFT 0u
#define     NVIC_INTERRUPT_SET_ENABLE_SETENA_MASK  0xffffffffu
#define GET_NVIC_INTERRUPT_SET_ENABLE_SETENA(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_NVIC_INTERRUPT_SET_ENABLE_SETENA(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref NVIC_t.InterruptSetEnable. */
typedef register_container RegNVICInterruptSetEnable_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Writing 0 to a SETENA bit has no effect. Reading the bit returns its current enable state. Reset clears the SETENA fields. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SETENA, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Writing 0 to a SETENA bit has no effect. Reading the bit returns its current enable state. Reset clears the SETENA fields. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SETENA, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "InterruptSetEnable"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICInterruptSetEnable_t()
    {
        /** @brief constructor for @ref NVIC_t.InterruptSetEnable. */
        r32.setName("InterruptSetEnable");
        bits.SETENA.setBaseRegister(&r32);
        bits.SETENA.setName("SETENA");
    }
    RegNVICInterruptSetEnable_t& operator=(const RegNVICInterruptSetEnable_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICInterruptSetEnable_t;

#define REG_NVIC_INTERRUPT_CLEAR_ENABLE ((volatile APE_NVIC_H_uint32_t*)0xe000e180) /* Each bit in the register corresponds to one of the 32 interrupts. Setting an Interrupt Clear-Enable Register bit disables the corresponding interrupt. */
#define     NVIC_INTERRUPT_CLEAR_ENABLE_CLRENA_SHIFT 0u
#define     NVIC_INTERRUPT_CLEAR_ENABLE_CLRENA_MASK  0xffffffffu
#define GET_NVIC_INTERRUPT_CLEAR_ENABLE_CLRENA(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_NVIC_INTERRUPT_CLEAR_ENABLE_CLRENA(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref NVIC_t.InterruptClearEnable. */
typedef register_container RegNVICInterruptClearEnable_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Writing 0 to a CLRENA bit has no effect. Reading the bit returns its current enable state. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, CLRENA, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Writing 0 to a CLRENA bit has no effect. Reading the bit returns its current enable state. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, CLRENA, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "InterruptClearEnable"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICInterruptClearEnable_t()
    {
        /** @brief constructor for @ref NVIC_t.InterruptClearEnable. */
        r32.setName("InterruptClearEnable");
        bits.CLRENA.setBaseRegister(&r32);
        bits.CLRENA.setName("CLRENA");
    }
    RegNVICInterruptClearEnable_t& operator=(const RegNVICInterruptClearEnable_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICInterruptClearEnable_t;

#define REG_NVIC_INTERRUPT_SET_PENDING ((volatile APE_NVIC_H_uint32_t*)0xe000e200) /* Each bit in the register corresponds to one of the 32 interrupts. Setting an Interrupt Set-Pending Register bit pends the corresponding interrupt. */
#define     NVIC_INTERRUPT_SET_PENDING_SETPEND_SHIFT 0u
#define     NVIC_INTERRUPT_SET_PENDING_SETPEND_MASK  0xffffffffu
#define GET_NVIC_INTERRUPT_SET_PENDING_SETPEND(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_NVIC_INTERRUPT_SET_PENDING_SETPEND(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref NVIC_t.InterruptSetPending. */
typedef register_container RegNVICInterruptSetPending_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Writing 0 to a SETPEND bit has no effect. Reading the bit returns its current state. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SETPEND, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Writing 0 to a SETPEND bit has no effect. Reading the bit returns its current state. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SETPEND, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "InterruptSetPending"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICInterruptSetPending_t()
    {
        /** @brief constructor for @ref NVIC_t.InterruptSetPending. */
        r32.setName("InterruptSetPending");
        bits.SETPEND.setBaseRegister(&r32);
        bits.SETPEND.setName("SETPEND");
    }
    RegNVICInterruptSetPending_t& operator=(const RegNVICInterruptSetPending_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICInterruptSetPending_t;

#define REG_NVIC_INTERRUPT_CLEAR_PENDING ((volatile APE_NVIC_H_uint32_t*)0xe000e280) /* Each bit in the register corresponds to one of the 32 interrupts. Setting an Interrupt Clear-Pending Register bit puts the corresponding pending interrupt in the inactive state. */
#define     NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_SHIFT 0u
#define     NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND_MASK  0xffffffffu
#define GET_NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_NVIC_INTERRUPT_CLEAR_PENDING_CLRPEND(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref NVIC_t.InterruptClearPending. */
typedef register_container RegNVICInterruptClearPending_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Writing 0 to a CLRPEND bit has no effect. Reading the bit returns its current state. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, CLRPEND, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Writing 0 to a CLRPEND bit has no effect. Reading the bit returns its current state. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, CLRPEND, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "InterruptClearPending"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICInterruptClearPending_t()
    {
        /** @brief constructor for @ref NVIC_t.InterruptClearPending. */
        r32.setName("InterruptClearPending");
        bits.CLRPEND.setBaseRegister(&r32);
        bits.CLRPEND.setName("CLRPEND");
    }
    RegNVICInterruptClearPending_t& operator=(const RegNVICInterruptClearPending_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICInterruptClearPending_t;

#define REG_NVIC_ACTIVE_BIT ((volatile APE_NVIC_H_uint32_t*)0xe000e300) /* Read the Active Bit Register to determine which interrupts are active. Each flag in the register corresponds to one of the 32 interrupts. */
#define     NVIC_ACTIVE_BIT_ACTIVE_SHIFT 0u
#define     NVIC_ACTIVE_BIT_ACTIVE_MASK  0xffffffffu
#define GET_NVIC_ACTIVE_BIT_ACTIVE(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_NVIC_ACTIVE_BIT_ACTIVE(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref NVIC_t.ActiveBit. */
typedef register_container RegNVICActiveBit_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Interrupt active flags. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ACTIVE, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Interrupt active flags. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ACTIVE, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ActiveBit"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICActiveBit_t()
    {
        /** @brief constructor for @ref NVIC_t.ActiveBit. */
        r32.setName("ActiveBit");
        bits.ACTIVE.setBaseRegister(&r32);
        bits.ACTIVE.setName("ACTIVE");
    }
    RegNVICActiveBit_t& operator=(const RegNVICActiveBit_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICActiveBit_t;

#define REG_NVIC_INTERRUPT_PRIORITY_0 ((volatile APE_NVIC_H_uint32_t*)0xe000e400) /* Use the Interrupt Priority Registers to assign a priority from 0 to 255 to each of the available interrupts. 0 is the highest priority, and 255 is the lowest. */
#define     NVIC_INTERRUPT_PRIORITY_0_PRI_0_SHIFT 0u
#define     NVIC_INTERRUPT_PRIORITY_0_PRI_0_MASK  0xffu
#define GET_NVIC_INTERRUPT_PRIORITY_0_PRI_0(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_NVIC_INTERRUPT_PRIORITY_0_PRI_0(__val__)  (((__val__) << 0u) & 0xffu)
#define     NVIC_INTERRUPT_PRIORITY_0_PRI_1_SHIFT 8u
#define     NVIC_INTERRUPT_PRIORITY_0_PRI_1_MASK  0xff00u
#define GET_NVIC_INTERRUPT_PRIORITY_0_PRI_1(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_NVIC_INTERRUPT_PRIORITY_0_PRI_1(__val__)  (((__val__) << 8u) & 0xff00u)
#define     NVIC_INTERRUPT_PRIORITY_0_PRI_2_SHIFT 16u
#define     NVIC_INTERRUPT_PRIORITY_0_PRI_2_MASK  0xff0000u
#define GET_NVIC_INTERRUPT_PRIORITY_0_PRI_2(__reg__)  (((__reg__) & 0xff0000) >> 16u)
#define SET_NVIC_INTERRUPT_PRIORITY_0_PRI_2(__val__)  (((__val__) << 16u) & 0xff0000u)
#define     NVIC_INTERRUPT_PRIORITY_0_PRI_3_SHIFT 24u
#define     NVIC_INTERRUPT_PRIORITY_0_PRI_3_MASK  0xff000000u
#define GET_NVIC_INTERRUPT_PRIORITY_0_PRI_3(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_NVIC_INTERRUPT_PRIORITY_0_PRI_3(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref NVIC_t.InterruptPriority0. */
typedef register_container RegNVICInterruptPriority0_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Priority of Interrupt 0. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_0, 0, 8)
        /** @brief Priority of Interrupt 1. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_1, 8, 8)
        /** @brief Priority of Interrupt 2. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_2, 16, 8)
        /** @brief Priority of Interrupt 3. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_3, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Priority of Interrupt 3. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_3, 24, 8)
        /** @brief Priority of Interrupt 2. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_2, 16, 8)
        /** @brief Priority of Interrupt 1. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_1, 8, 8)
        /** @brief Priority of Interrupt 0. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_0, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "InterruptPriority0"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICInterruptPriority0_t()
    {
        /** @brief constructor for @ref NVIC_t.InterruptPriority0. */
        r32.setName("InterruptPriority0");
        bits.PRI_0.setBaseRegister(&r32);
        bits.PRI_0.setName("PRI_0");
        bits.PRI_1.setBaseRegister(&r32);
        bits.PRI_1.setName("PRI_1");
        bits.PRI_2.setBaseRegister(&r32);
        bits.PRI_2.setName("PRI_2");
        bits.PRI_3.setBaseRegister(&r32);
        bits.PRI_3.setName("PRI_3");
    }
    RegNVICInterruptPriority0_t& operator=(const RegNVICInterruptPriority0_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICInterruptPriority0_t;

#define REG_NVIC_INTERRUPT_PRIORITY_1 ((volatile APE_NVIC_H_uint32_t*)0xe000e404) /* Use the Interrupt Priority Registers to assign a priority from 0 to 255 to each of the available interrupts. 0 is the highest priority, and 255 is the lowest. */
#define     NVIC_INTERRUPT_PRIORITY_1_PRI_4_SHIFT 0u
#define     NVIC_INTERRUPT_PRIORITY_1_PRI_4_MASK  0xffu
#define GET_NVIC_INTERRUPT_PRIORITY_1_PRI_4(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_NVIC_INTERRUPT_PRIORITY_1_PRI_4(__val__)  (((__val__) << 0u) & 0xffu)
#define     NVIC_INTERRUPT_PRIORITY_1_PRI_5_SHIFT 8u
#define     NVIC_INTERRUPT_PRIORITY_1_PRI_5_MASK  0xff00u
#define GET_NVIC_INTERRUPT_PRIORITY_1_PRI_5(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_NVIC_INTERRUPT_PRIORITY_1_PRI_5(__val__)  (((__val__) << 8u) & 0xff00u)
#define     NVIC_INTERRUPT_PRIORITY_1_PRI_6_SHIFT 16u
#define     NVIC_INTERRUPT_PRIORITY_1_PRI_6_MASK  0xff0000u
#define GET_NVIC_INTERRUPT_PRIORITY_1_PRI_6(__reg__)  (((__reg__) & 0xff0000) >> 16u)
#define SET_NVIC_INTERRUPT_PRIORITY_1_PRI_6(__val__)  (((__val__) << 16u) & 0xff0000u)
#define     NVIC_INTERRUPT_PRIORITY_1_PRI_7_SHIFT 24u
#define     NVIC_INTERRUPT_PRIORITY_1_PRI_7_MASK  0xff000000u
#define GET_NVIC_INTERRUPT_PRIORITY_1_PRI_7(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_NVIC_INTERRUPT_PRIORITY_1_PRI_7(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref NVIC_t.InterruptPriority1. */
typedef register_container RegNVICInterruptPriority1_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Priority of Interrupt 4. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_4, 0, 8)
        /** @brief Priority of Interrupt 5. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_5, 8, 8)
        /** @brief Priority of Interrupt 6. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_6, 16, 8)
        /** @brief Priority of Interrupt 7. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_7, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Priority of Interrupt 7. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_7, 24, 8)
        /** @brief Priority of Interrupt 6. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_6, 16, 8)
        /** @brief Priority of Interrupt 5. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_5, 8, 8)
        /** @brief Priority of Interrupt 4. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_4, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "InterruptPriority1"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICInterruptPriority1_t()
    {
        /** @brief constructor for @ref NVIC_t.InterruptPriority1. */
        r32.setName("InterruptPriority1");
        bits.PRI_4.setBaseRegister(&r32);
        bits.PRI_4.setName("PRI_4");
        bits.PRI_5.setBaseRegister(&r32);
        bits.PRI_5.setName("PRI_5");
        bits.PRI_6.setBaseRegister(&r32);
        bits.PRI_6.setName("PRI_6");
        bits.PRI_7.setBaseRegister(&r32);
        bits.PRI_7.setName("PRI_7");
    }
    RegNVICInterruptPriority1_t& operator=(const RegNVICInterruptPriority1_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICInterruptPriority1_t;

#define REG_NVIC_CPU_ID ((volatile APE_NVIC_H_uint32_t*)0xe000ed00) /* Read the CPU ID Base Register to determine: the ID number of the processor core, the version number of the processor core, the implementation details of the processor core. */
#define     NVIC_CPU_ID_REVISION_SHIFT 0u
#define     NVIC_CPU_ID_REVISION_MASK  0xfu
#define GET_NVIC_CPU_ID_REVISION(__reg__)  (((__reg__) & 0xf) >> 0u)
#define SET_NVIC_CPU_ID_REVISION(__val__)  (((__val__) << 0u) & 0xfu)
#define     NVIC_CPU_ID_PARTNO_SHIFT 4u
#define     NVIC_CPU_ID_PARTNO_MASK  0xfff0u
#define GET_NVIC_CPU_ID_PARTNO(__reg__)  (((__reg__) & 0xfff0) >> 4u)
#define SET_NVIC_CPU_ID_PARTNO(__val__)  (((__val__) << 4u) & 0xfff0u)
#define     NVIC_CPU_ID_CONSTANT_SHIFT 16u
#define     NVIC_CPU_ID_CONSTANT_MASK  0xf0000u
#define GET_NVIC_CPU_ID_CONSTANT(__reg__)  (((__reg__) & 0xf0000) >> 16u)
#define SET_NVIC_CPU_ID_CONSTANT(__val__)  (((__val__) << 16u) & 0xf0000u)
#define     NVIC_CPU_ID_VARIANT_SHIFT 20u
#define     NVIC_CPU_ID_VARIANT_MASK  0xf00000u
#define GET_NVIC_CPU_ID_VARIANT(__reg__)  (((__reg__) & 0xf00000) >> 20u)
#define SET_NVIC_CPU_ID_VARIANT(__val__)  (((__val__) << 20u) & 0xf00000u)
#define     NVIC_CPU_ID_IMPLEMENTER_SHIFT 24u
#define     NVIC_CPU_ID_IMPLEMENTER_MASK  0xf000000u
#define GET_NVIC_CPU_ID_IMPLEMENTER(__reg__)  (((__reg__) & 0xf000000) >> 24u)
#define SET_NVIC_CPU_ID_IMPLEMENTER(__val__)  (((__val__) << 24u) & 0xf000000u)

/** @brief Register definition for @ref NVIC_t.CpuId. */
typedef register_container RegNVICCpuId_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Implementation defined revision number. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, REVISION, 0, 4)
        /** @brief Reads as 0xF */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PARTNO, 4, 12)
        /** @brief Priority of Interrupt 6. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, Constant, 16, 4)
        /** @brief Implementation defined variant number. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VARIANT, 20, 4)
        /** @brief Implementer code. ARM is 0x41. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, IMPLEMENTER, 24, 4)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_28, 28, 4)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_28, 28, 4)
        /** @brief Implementer code. ARM is 0x41. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, IMPLEMENTER, 24, 4)
        /** @brief Implementation defined variant number. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VARIANT, 20, 4)
        /** @brief Priority of Interrupt 6. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, Constant, 16, 4)
        /** @brief Reads as 0xF */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PARTNO, 4, 12)
        /** @brief Implementation defined revision number. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, REVISION, 0, 4)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "CpuId"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICCpuId_t()
    {
        /** @brief constructor for @ref NVIC_t.CpuId. */
        r32.setName("CpuId");
        bits.REVISION.setBaseRegister(&r32);
        bits.REVISION.setName("REVISION");
        bits.PARTNO.setBaseRegister(&r32);
        bits.PARTNO.setName("PARTNO");
        bits.Constant.setBaseRegister(&r32);
        bits.Constant.setName("Constant");
        bits.VARIANT.setBaseRegister(&r32);
        bits.VARIANT.setName("VARIANT");
        bits.IMPLEMENTER.setBaseRegister(&r32);
        bits.IMPLEMENTER.setName("IMPLEMENTER");
    }
    RegNVICCpuId_t& operator=(const RegNVICCpuId_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICCpuId_t;

#define REG_NVIC_INTERRUPT_CONTROL_STATE ((volatile APE_NVIC_H_uint32_t*)0xe000ed04) /* Use the Interrupt Control State Register to: set a pending Non-Maskable Interrupt (NMI), set or clear a pending SVC, set or clear a pending SysTick, check for pending exceptions, check the vector number of the highest priority pended exception, check the vector number of the active exception. */
#define     NVIC_INTERRUPT_CONTROL_STATE_VECTACTIVE_SHIFT 0u
#define     NVIC_INTERRUPT_CONTROL_STATE_VECTACTIVE_MASK  0x1ffu
#define GET_NVIC_INTERRUPT_CONTROL_STATE_VECTACTIVE(__reg__)  (((__reg__) & 0x1ff) >> 0u)
#define SET_NVIC_INTERRUPT_CONTROL_STATE_VECTACTIVE(__val__)  (((__val__) << 0u) & 0x1ffu)
#define     NVIC_INTERRUPT_CONTROL_STATE_RETTOBASE_SHIFT 11u
#define     NVIC_INTERRUPT_CONTROL_STATE_RETTOBASE_MASK  0x800u
#define GET_NVIC_INTERRUPT_CONTROL_STATE_RETTOBASE(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_NVIC_INTERRUPT_CONTROL_STATE_RETTOBASE(__val__)  (((__val__) << 11u) & 0x800u)
#define     NVIC_INTERRUPT_CONTROL_STATE_VECTPENDING_SHIFT 12u
#define     NVIC_INTERRUPT_CONTROL_STATE_VECTPENDING_MASK  0x3ff000u
#define GET_NVIC_INTERRUPT_CONTROL_STATE_VECTPENDING(__reg__)  (((__reg__) & 0x3ff000) >> 12u)
#define SET_NVIC_INTERRUPT_CONTROL_STATE_VECTPENDING(__val__)  (((__val__) << 12u) & 0x3ff000u)
#define     NVIC_INTERRUPT_CONTROL_STATE_ISRPENDING_SHIFT 22u
#define     NVIC_INTERRUPT_CONTROL_STATE_ISRPENDING_MASK  0x400000u
#define GET_NVIC_INTERRUPT_CONTROL_STATE_ISRPENDING(__reg__)  (((__reg__) & 0x400000) >> 22u)
#define SET_NVIC_INTERRUPT_CONTROL_STATE_ISRPENDING(__val__)  (((__val__) << 22u) & 0x400000u)
#define     NVIC_INTERRUPT_CONTROL_STATE_ISRPREEMPT_SHIFT 23u
#define     NVIC_INTERRUPT_CONTROL_STATE_ISRPREEMPT_MASK  0x800000u
#define GET_NVIC_INTERRUPT_CONTROL_STATE_ISRPREEMPT(__reg__)  (((__reg__) & 0x800000) >> 23u)
#define SET_NVIC_INTERRUPT_CONTROL_STATE_ISRPREEMPT(__val__)  (((__val__) << 23u) & 0x800000u)
#define     NVIC_INTERRUPT_CONTROL_STATE_PENDSTCLR_SHIFT 25u
#define     NVIC_INTERRUPT_CONTROL_STATE_PENDSTCLR_MASK  0x2000000u
#define GET_NVIC_INTERRUPT_CONTROL_STATE_PENDSTCLR(__reg__)  (((__reg__) & 0x2000000) >> 25u)
#define SET_NVIC_INTERRUPT_CONTROL_STATE_PENDSTCLR(__val__)  (((__val__) << 25u) & 0x2000000u)
#define     NVIC_INTERRUPT_CONTROL_STATE_PENDSTSET_SHIFT 26u
#define     NVIC_INTERRUPT_CONTROL_STATE_PENDSTSET_MASK  0x4000000u
#define GET_NVIC_INTERRUPT_CONTROL_STATE_PENDSTSET(__reg__)  (((__reg__) & 0x4000000) >> 26u)
#define SET_NVIC_INTERRUPT_CONTROL_STATE_PENDSTSET(__val__)  (((__val__) << 26u) & 0x4000000u)
#define     NVIC_INTERRUPT_CONTROL_STATE_PENDSVCLR_SHIFT 27u
#define     NVIC_INTERRUPT_CONTROL_STATE_PENDSVCLR_MASK  0x8000000u
#define GET_NVIC_INTERRUPT_CONTROL_STATE_PENDSVCLR(__reg__)  (((__reg__) & 0x8000000) >> 27u)
#define SET_NVIC_INTERRUPT_CONTROL_STATE_PENDSVCLR(__val__)  (((__val__) << 27u) & 0x8000000u)
#define     NVIC_INTERRUPT_CONTROL_STATE_PENDSVSET_SHIFT 28u
#define     NVIC_INTERRUPT_CONTROL_STATE_PENDSVSET_MASK  0x10000000u
#define GET_NVIC_INTERRUPT_CONTROL_STATE_PENDSVSET(__reg__)  (((__reg__) & 0x10000000) >> 28u)
#define SET_NVIC_INTERRUPT_CONTROL_STATE_PENDSVSET(__val__)  (((__val__) << 28u) & 0x10000000u)
#define     NVIC_INTERRUPT_CONTROL_STATE_NMIPENDSET_SHIFT 31u
#define     NVIC_INTERRUPT_CONTROL_STATE_NMIPENDSET_MASK  0x80000000u
#define GET_NVIC_INTERRUPT_CONTROL_STATE_NMIPENDSET(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_NVIC_INTERRUPT_CONTROL_STATE_NMIPENDSET(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref NVIC_t.InterruptControlState. */
typedef register_container RegNVICInterruptControlState_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Active ISR number field. VECTACTIVE contains the interrupt number of the currently running ISR, including NMI and Hard Fault. A shared handler can use VECTACTIVE to determine which interrupt invoked it. You can subtract 16 from the VECTACTIVE field to index into the Interrupt Clear/Set Enable, Interrupt Clear Pending/SetPending and Interrupt Priority Registers. INTISR[0] has vector number 16. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VECTACTIVE, 0, 9)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_10_9, 9, 2)
        /** @brief This bit is 1 when the set of all active exceptions minus the IPSR_current_exception yields the empty set. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, RETTOBASE, 11, 1)
        /** @brief Pending ISR number field. VECTPENDING contains the interrupt number of the highest priority pending ISR. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VECTPENDING, 12, 10)
        /** @brief Interrupt pending flag. Excludes NMI and Faults. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ISRPENDING, 22, 1)
        /** @brief You must only use this at debug time. It indicates that a pending interrupt becomes active in the next running cycle. If C_MASKINTS is clear in the Debug Halting Control and Status Register, the interrupt is serviced. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ISRPREEMPT, 23, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_24_24, 24, 1)
        /** @brief Clear pending SysTick bit. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PENDSTCLR, 25, 1)
        /** @brief Set a pending SysTick bit. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PENDSTSET, 26, 1)
        /** @brief Clear pending pendSV bit. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PENDSVCLR, 27, 1)
        /** @brief Set pending pendSV bit. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PENDSVSET, 28, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_30_29, 29, 2)
        /** @brief NMIPENDSET pends and activates an NMI. Because NMI is the highest-priority interrupt, it takes effect as soon as it registers. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, NMIPENDSET, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief NMIPENDSET pends and activates an NMI. Because NMI is the highest-priority interrupt, it takes effect as soon as it registers. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, NMIPENDSET, 31, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_30_29, 29, 2)
        /** @brief Set pending pendSV bit. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PENDSVSET, 28, 1)
        /** @brief Clear pending pendSV bit. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PENDSVCLR, 27, 1)
        /** @brief Set a pending SysTick bit. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PENDSTSET, 26, 1)
        /** @brief Clear pending SysTick bit. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PENDSTCLR, 25, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_24_24, 24, 1)
        /** @brief You must only use this at debug time. It indicates that a pending interrupt becomes active in the next running cycle. If C_MASKINTS is clear in the Debug Halting Control and Status Register, the interrupt is serviced. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ISRPREEMPT, 23, 1)
        /** @brief Interrupt pending flag. Excludes NMI and Faults. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ISRPENDING, 22, 1)
        /** @brief Pending ISR number field. VECTPENDING contains the interrupt number of the highest priority pending ISR. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VECTPENDING, 12, 10)
        /** @brief This bit is 1 when the set of all active exceptions minus the IPSR_current_exception yields the empty set. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, RETTOBASE, 11, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_10_9, 9, 2)
        /** @brief Active ISR number field. VECTACTIVE contains the interrupt number of the currently running ISR, including NMI and Hard Fault. A shared handler can use VECTACTIVE to determine which interrupt invoked it. You can subtract 16 from the VECTACTIVE field to index into the Interrupt Clear/Set Enable, Interrupt Clear Pending/SetPending and Interrupt Priority Registers. INTISR[0] has vector number 16. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VECTACTIVE, 0, 9)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "InterruptControlState"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICInterruptControlState_t()
    {
        /** @brief constructor for @ref NVIC_t.InterruptControlState. */
        r32.setName("InterruptControlState");
        bits.VECTACTIVE.setBaseRegister(&r32);
        bits.VECTACTIVE.setName("VECTACTIVE");
        bits.RETTOBASE.setBaseRegister(&r32);
        bits.RETTOBASE.setName("RETTOBASE");
        bits.VECTPENDING.setBaseRegister(&r32);
        bits.VECTPENDING.setName("VECTPENDING");
        bits.ISRPENDING.setBaseRegister(&r32);
        bits.ISRPENDING.setName("ISRPENDING");
        bits.ISRPREEMPT.setBaseRegister(&r32);
        bits.ISRPREEMPT.setName("ISRPREEMPT");
        bits.PENDSTCLR.setBaseRegister(&r32);
        bits.PENDSTCLR.setName("PENDSTCLR");
        bits.PENDSTSET.setBaseRegister(&r32);
        bits.PENDSTSET.setName("PENDSTSET");
        bits.PENDSVCLR.setBaseRegister(&r32);
        bits.PENDSVCLR.setName("PENDSVCLR");
        bits.PENDSVSET.setBaseRegister(&r32);
        bits.PENDSVSET.setName("PENDSVSET");
        bits.NMIPENDSET.setBaseRegister(&r32);
        bits.NMIPENDSET.setName("NMIPENDSET");
    }
    RegNVICInterruptControlState_t& operator=(const RegNVICInterruptControlState_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICInterruptControlState_t;

#define REG_NVIC_VECTOR_TABLE_OFFSET ((volatile APE_NVIC_H_uint32_t*)0xe000ed08) /* Use the Vector Table Offset Register to determine: if the vector table is in RAM or code memory, the vector table offset. */
#define     NVIC_VECTOR_TABLE_OFFSET_TBLOFF_SHIFT 7u
#define     NVIC_VECTOR_TABLE_OFFSET_TBLOFF_MASK  0x1fffff80u
#define GET_NVIC_VECTOR_TABLE_OFFSET_TBLOFF(__reg__)  (((__reg__) & 0x1fffff80) >> 7u)
#define SET_NVIC_VECTOR_TABLE_OFFSET_TBLOFF(__val__)  (((__val__) << 7u) & 0x1fffff80u)
#define     NVIC_VECTOR_TABLE_OFFSET_TBLBASE_SHIFT 29u
#define     NVIC_VECTOR_TABLE_OFFSET_TBLBASE_MASK  0x20000000u
#define GET_NVIC_VECTOR_TABLE_OFFSET_TBLBASE(__reg__)  (((__reg__) & 0x20000000) >> 29u)
#define SET_NVIC_VECTOR_TABLE_OFFSET_TBLBASE(__val__)  (((__val__) << 29u) & 0x20000000u)

/** @brief Register definition for @ref NVIC_t.VectorTableOffset. */
typedef register_container RegNVICVectorTableOffset_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_6_0, 0, 7)
        /** @brief Vector table base offset field. Contains the offset of the table base from the bottom of the SRAM or CODE space. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, TBLOFF, 7, 22)
        /** @brief Table base is in Code (0) or RAM (1). */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, TBLBASE, 29, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_30, 30, 2)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_30, 30, 2)
        /** @brief Table base is in Code (0) or RAM (1). */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, TBLBASE, 29, 1)
        /** @brief Vector table base offset field. Contains the offset of the table base from the bottom of the SRAM or CODE space. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, TBLOFF, 7, 22)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_6_0, 0, 7)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "VectorTableOffset"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICVectorTableOffset_t()
    {
        /** @brief constructor for @ref NVIC_t.VectorTableOffset. */
        r32.setName("VectorTableOffset");
        bits.TBLOFF.setBaseRegister(&r32);
        bits.TBLOFF.setName("TBLOFF");
        bits.TBLBASE.setBaseRegister(&r32);
        bits.TBLBASE.setName("TBLBASE");
    }
    RegNVICVectorTableOffset_t& operator=(const RegNVICVectorTableOffset_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICVectorTableOffset_t;

#define REG_NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL ((volatile APE_NVIC_H_uint32_t*)0xe000ed0c) /* the Application Interrupt and Reset Control Register to: determine data endianness, clear all active state information for debug or to recover from a hard failure, execute a system reset, alter the priority grouping position (binary point). */
#define     NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_VECTRESET_SHIFT 0u
#define     NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_VECTRESET_MASK  0x1u
#define GET_NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_VECTRESET(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_VECTRESET(__val__)  (((__val__) << 0u) & 0x1u)
#define     NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_VECTCLRACTIVE_SHIFT 1u
#define     NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_VECTCLRACTIVE_MASK  0x2u
#define GET_NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_VECTCLRACTIVE(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_VECTCLRACTIVE(__val__)  (((__val__) << 1u) & 0x2u)
#define     NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_SYSRESETREQ_SHIFT 2u
#define     NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_SYSRESETREQ_MASK  0x4u
#define GET_NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_SYSRESETREQ(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_SYSRESETREQ(__val__)  (((__val__) << 2u) & 0x4u)
#define     NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_PRIGROUP_SHIFT 8u
#define     NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_PRIGROUP_MASK  0x700u
#define GET_NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_PRIGROUP(__reg__)  (((__reg__) & 0x700) >> 8u)
#define SET_NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_PRIGROUP(__val__)  (((__val__) << 8u) & 0x700u)
#define     NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_ENDIANESS_SHIFT 15u
#define     NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_ENDIANESS_MASK  0x8000u
#define GET_NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_ENDIANESS(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_ENDIANESS(__val__)  (((__val__) << 15u) & 0x8000u)
#define     NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_VECTKEY_SHIFT 16u
#define     NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_VECTKEY_MASK  0xffff0000u
#define GET_NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_VECTKEY(__reg__)  (((__reg__) & 0xffff0000) >> 16u)
#define SET_NVIC_APPLICATION_INTERRUPT_AND_RESET_CONTROL_VECTKEY(__val__)  (((__val__) << 16u) & 0xffff0000u)

/** @brief Register definition for @ref NVIC_t.ApplicationInterruptAndResetControl. */
typedef register_container RegNVICApplicationInterruptAndResetControl_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief System Reset bit. Resets the system, with the exception of debug components. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VECTRESET, 0, 1)
        /** @brief Clear active vector bit. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VECTCLRACTIVE, 1, 1)
        /** @brief Causes a signal to be asserted to the outer system that indicates a reset is requested. Intended to force a large system reset of all major components except for debug. Setting this bit does not prevent Halting Debug from running. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SYSRESETREQ, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_7_3, 3, 5)
        /** @brief PRIGROUP field is a binary point position indicator for creating subpriorities for exceptions that share the same pre-emption level. It divides the PRI_n field in the Interrupt Priority Register into a pre-emption level and a subpriority level. The binary point is a left-of value. This means that the PRIGROUP value represents a point starting at the left of the Least Significant Bit (LSB). This is bit [0] of 7:0. The lowest value might not be 0 depending on the number of bits allocated for priorities, and implementation choices. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRIGROUP, 8, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_14_11, 11, 4)
        /** @brief Data endianness bit: 1 = big endian. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ENDIANESS, 15, 1)
        /** @brief Register key. Writing to this register requires 0x5FA in the VECTKEY field. Otherwise the write value is ignored. Reads as 0xFA05. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VECTKEY, 16, 16)
#elif defined(__BIG_ENDIAN__)
        /** @brief Register key. Writing to this register requires 0x5FA in the VECTKEY field. Otherwise the write value is ignored. Reads as 0xFA05. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VECTKEY, 16, 16)
        /** @brief Data endianness bit: 1 = big endian. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ENDIANESS, 15, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_14_11, 11, 4)
        /** @brief PRIGROUP field is a binary point position indicator for creating subpriorities for exceptions that share the same pre-emption level. It divides the PRI_n field in the Interrupt Priority Register into a pre-emption level and a subpriority level. The binary point is a left-of value. This means that the PRIGROUP value represents a point starting at the left of the Least Significant Bit (LSB). This is bit [0] of 7:0. The lowest value might not be 0 depending on the number of bits allocated for priorities, and implementation choices. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRIGROUP, 8, 3)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_7_3, 3, 5)
        /** @brief Causes a signal to be asserted to the outer system that indicates a reset is requested. Intended to force a large system reset of all major components except for debug. Setting this bit does not prevent Halting Debug from running. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SYSRESETREQ, 2, 1)
        /** @brief Clear active vector bit. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VECTCLRACTIVE, 1, 1)
        /** @brief System Reset bit. Resets the system, with the exception of debug components. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VECTRESET, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ApplicationInterruptAndResetControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICApplicationInterruptAndResetControl_t()
    {
        /** @brief constructor for @ref NVIC_t.ApplicationInterruptAndResetControl. */
        r32.setName("ApplicationInterruptAndResetControl");
        bits.VECTRESET.setBaseRegister(&r32);
        bits.VECTRESET.setName("VECTRESET");
        bits.VECTCLRACTIVE.setBaseRegister(&r32);
        bits.VECTCLRACTIVE.setName("VECTCLRACTIVE");
        bits.SYSRESETREQ.setBaseRegister(&r32);
        bits.SYSRESETREQ.setName("SYSRESETREQ");
        bits.PRIGROUP.setBaseRegister(&r32);
        bits.PRIGROUP.setName("PRIGROUP");
        bits.ENDIANESS.setBaseRegister(&r32);
        bits.ENDIANESS.setName("ENDIANESS");
        bits.VECTKEY.setBaseRegister(&r32);
        bits.VECTKEY.setName("VECTKEY");
    }
    RegNVICApplicationInterruptAndResetControl_t& operator=(const RegNVICApplicationInterruptAndResetControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICApplicationInterruptAndResetControl_t;

#define REG_NVIC_SYSTEM_CONTROL ((volatile APE_NVIC_H_uint32_t*)0xe000ed10) /* Use the System Control Register for power-management functions: signal to the system when the processor can enter a low power state, control how the processor enters and exits low power states. */
#define     NVIC_SYSTEM_CONTROL_SLEEPONEXIT_SHIFT 1u
#define     NVIC_SYSTEM_CONTROL_SLEEPONEXIT_MASK  0x2u
#define GET_NVIC_SYSTEM_CONTROL_SLEEPONEXIT(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVIC_SYSTEM_CONTROL_SLEEPONEXIT(__val__)  (((__val__) << 1u) & 0x2u)
#define     NVIC_SYSTEM_CONTROL_SLEEPDEEP_SHIFT 2u
#define     NVIC_SYSTEM_CONTROL_SLEEPDEEP_MASK  0x4u
#define GET_NVIC_SYSTEM_CONTROL_SLEEPDEEP(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_NVIC_SYSTEM_CONTROL_SLEEPDEEP(__val__)  (((__val__) << 2u) & 0x4u)
#define     NVIC_SYSTEM_CONTROL_SEVONPEND_SHIFT 4u
#define     NVIC_SYSTEM_CONTROL_SEVONPEND_MASK  0x10u
#define GET_NVIC_SYSTEM_CONTROL_SEVONPEND(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_NVIC_SYSTEM_CONTROL_SEVONPEND(__val__)  (((__val__) << 4u) & 0x10u)

/** @brief Register definition for @ref NVIC_t.SystemControl. */
typedef register_container RegNVICSystemControl_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_0_0, 0, 1)
        /** @brief Sleep on exit when returning from Handler mode to Thread mode: 1 = sleep on ISR exit. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SLEEPONEXIT, 1, 1)
        /** @brief 1 = indicates to the system that Cortex-M3 clock can be stopped. Setting this bit causes the SLEEPDEEP port to be asserted when the processor can be stopped. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SLEEPDEEP, 2, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief When enabled, this causes WFE to wake up when an interrupt moves from inactive to pended. Otherwise, WFE only wakes up from an event signal, external and SEV instruction generated. The event input, RXEV, is registered even when not waiting for an event, and so effects the next WFE. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SEVONPEND, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_5, 5, 27)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_5, 5, 27)
        /** @brief When enabled, this causes WFE to wake up when an interrupt moves from inactive to pended. Otherwise, WFE only wakes up from an event signal, external and SEV instruction generated. The event input, RXEV, is registered even when not waiting for an event, and so effects the next WFE. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SEVONPEND, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_3_3, 3, 1)
        /** @brief 1 = indicates to the system that Cortex-M3 clock can be stopped. Setting this bit causes the SLEEPDEEP port to be asserted when the processor can be stopped. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SLEEPDEEP, 2, 1)
        /** @brief Sleep on exit when returning from Handler mode to Thread mode: 1 = sleep on ISR exit. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SLEEPONEXIT, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_0_0, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SystemControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICSystemControl_t()
    {
        /** @brief constructor for @ref NVIC_t.SystemControl. */
        r32.setName("SystemControl");
        bits.SLEEPONEXIT.setBaseRegister(&r32);
        bits.SLEEPONEXIT.setName("SLEEPONEXIT");
        bits.SLEEPDEEP.setBaseRegister(&r32);
        bits.SLEEPDEEP.setName("SLEEPDEEP");
        bits.SEVONPEND.setBaseRegister(&r32);
        bits.SEVONPEND.setName("SEVONPEND");
    }
    RegNVICSystemControl_t& operator=(const RegNVICSystemControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICSystemControl_t;

#define REG_NVIC_CONFIGURATION_CONTROL ((volatile APE_NVIC_H_uint32_t*)0xe000ed14) /* Use the Configuration Control Register to: enable NMI, Hard Fault and FAULTMASK to ignore bus fault, trap divide by zero, and unaligned accesses, enable user access to the Software Trigger Exception Register, control entry to Thread Mode. */
#define     NVIC_CONFIGURATION_CONTROL_NONEBASETHRDENA_SHIFT 0u
#define     NVIC_CONFIGURATION_CONTROL_NONEBASETHRDENA_MASK  0x1u
#define GET_NVIC_CONFIGURATION_CONTROL_NONEBASETHRDENA(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_NVIC_CONFIGURATION_CONTROL_NONEBASETHRDENA(__val__)  (((__val__) << 0u) & 0x1u)
#define     NVIC_CONFIGURATION_CONTROL_USERSETMPEND_SHIFT 1u
#define     NVIC_CONFIGURATION_CONTROL_USERSETMPEND_MASK  0x2u
#define GET_NVIC_CONFIGURATION_CONTROL_USERSETMPEND(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVIC_CONFIGURATION_CONTROL_USERSETMPEND(__val__)  (((__val__) << 1u) & 0x2u)
#define     NVIC_CONFIGURATION_CONTROL_UNALIGN_TRP_SHIFT 3u
#define     NVIC_CONFIGURATION_CONTROL_UNALIGN_TRP_MASK  0x8u
#define GET_NVIC_CONFIGURATION_CONTROL_UNALIGN_TRP(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_NVIC_CONFIGURATION_CONTROL_UNALIGN_TRP(__val__)  (((__val__) << 3u) & 0x8u)
#define     NVIC_CONFIGURATION_CONTROL_DIV_0_TRP_SHIFT 4u
#define     NVIC_CONFIGURATION_CONTROL_DIV_0_TRP_MASK  0x10u
#define GET_NVIC_CONFIGURATION_CONTROL_DIV_0_TRP(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_NVIC_CONFIGURATION_CONTROL_DIV_0_TRP(__val__)  (((__val__) << 4u) & 0x10u)
#define     NVIC_CONFIGURATION_CONTROL_BFHFNMIGN_SHIFT 8u
#define     NVIC_CONFIGURATION_CONTROL_BFHFNMIGN_MASK  0x100u
#define GET_NVIC_CONFIGURATION_CONTROL_BFHFNMIGN(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_NVIC_CONFIGURATION_CONTROL_BFHFNMIGN(__val__)  (((__val__) << 8u) & 0x100u)
#define     NVIC_CONFIGURATION_CONTROL_STKALIGN_SHIFT 9u
#define     NVIC_CONFIGURATION_CONTROL_STKALIGN_MASK  0x200u
#define GET_NVIC_CONFIGURATION_CONTROL_STKALIGN(__reg__)  (((__reg__) & 0x200) >> 9u)
#define SET_NVIC_CONFIGURATION_CONTROL_STKALIGN(__val__)  (((__val__) << 9u) & 0x200u)

/** @brief Register definition for @ref NVIC_t.ConfigurationControl. */
typedef register_container RegNVICConfigurationControl_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief When 0, default, It is only possible to enter Thread mode when returning from the last exception. When set to 1, Thread mode can be entered from any level in Handler mode by controlled return value. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, NONEBASETHRDENA, 0, 1)
        /** @brief If written as 1, enables user code to write the Software Trigger Interrupt register to trigger (pend) a Main exception, which is one associated with the Main stack pointer. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, USERSETMPEND, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_2_2, 2, 1)
        /** @brief Trap for unaligned access. This enables faulting/halting on any unaligned half or full word access. Unaligned load-store multiples always fault. The relevant Usage Fault Status Register bit is UNALIGNED, see Usage Fault Status Register. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, UNALIGN_TRP, 3, 1)
        /** @brief Trap on Divide by 0. This enables faulting/halting when an attempt is made to divide by 0. The relevant Usage Fault Status Register bit is DIVBYZERO, see Usage Fault Status Register. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, DIV_0_TRP, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief When enabled, this causes handlers running at priority -1 and -2 (Hard Fault, NMI, and FAULTMASK escalated handlers) to ignore Data Bus faults caused by load and store instructions. When disabled, these bus faults cause a lock-up. You must only use this enable with extreme caution. All data bus faults are ignored – you must only use it when the handler and its data are in absolutely safe memory. Its normal use is to probe system devices and bridges to detect control path problems and fix them. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, BFHFNMIGN, 8, 1)
        /** @brief 1 = on exception entry, the SP used prior to the exception is adjusted to be 8-byte aligned and the context to restore it is saved. The SP is restored on the associated exception return. 0 = only 4-byte alignment is guaranteed for the SP used prior to the exception on exception entry. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, STKALIGN, 9, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_10, 10, 22)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_10, 10, 22)
        /** @brief 1 = on exception entry, the SP used prior to the exception is adjusted to be 8-byte aligned and the context to restore it is saved. The SP is restored on the associated exception return. 0 = only 4-byte alignment is guaranteed for the SP used prior to the exception on exception entry. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, STKALIGN, 9, 1)
        /** @brief When enabled, this causes handlers running at priority -1 and -2 (Hard Fault, NMI, and FAULTMASK escalated handlers) to ignore Data Bus faults caused by load and store instructions. When disabled, these bus faults cause a lock-up. You must only use this enable with extreme caution. All data bus faults are ignored – you must only use it when the handler and its data are in absolutely safe memory. Its normal use is to probe system devices and bridges to detect control path problems and fix them. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, BFHFNMIGN, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_7_5, 5, 3)
        /** @brief Trap on Divide by 0. This enables faulting/halting when an attempt is made to divide by 0. The relevant Usage Fault Status Register bit is DIVBYZERO, see Usage Fault Status Register. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, DIV_0_TRP, 4, 1)
        /** @brief Trap for unaligned access. This enables faulting/halting on any unaligned half or full word access. Unaligned load-store multiples always fault. The relevant Usage Fault Status Register bit is UNALIGNED, see Usage Fault Status Register. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, UNALIGN_TRP, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_2_2, 2, 1)
        /** @brief If written as 1, enables user code to write the Software Trigger Interrupt register to trigger (pend) a Main exception, which is one associated with the Main stack pointer. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, USERSETMPEND, 1, 1)
        /** @brief When 0, default, It is only possible to enter Thread mode when returning from the last exception. When set to 1, Thread mode can be entered from any level in Handler mode by controlled return value. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, NONEBASETHRDENA, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "ConfigurationControl"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICConfigurationControl_t()
    {
        /** @brief constructor for @ref NVIC_t.ConfigurationControl. */
        r32.setName("ConfigurationControl");
        bits.NONEBASETHRDENA.setBaseRegister(&r32);
        bits.NONEBASETHRDENA.setName("NONEBASETHRDENA");
        bits.USERSETMPEND.setBaseRegister(&r32);
        bits.USERSETMPEND.setName("USERSETMPEND");
        bits.UNALIGN_TRP.setBaseRegister(&r32);
        bits.UNALIGN_TRP.setName("UNALIGN_TRP");
        bits.DIV_0_TRP.setBaseRegister(&r32);
        bits.DIV_0_TRP.setName("DIV_0_TRP");
        bits.BFHFNMIGN.setBaseRegister(&r32);
        bits.BFHFNMIGN.setName("BFHFNMIGN");
        bits.STKALIGN.setBaseRegister(&r32);
        bits.STKALIGN.setName("STKALIGN");
    }
    RegNVICConfigurationControl_t& operator=(const RegNVICConfigurationControl_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICConfigurationControl_t;

#define REG_NVIC_SYSTEM_HANDLER_PRIORITY_4 ((volatile APE_NVIC_H_uint32_t*)0xe000ed18) /* System handlers are a special class of exception handler that can have their priority set to any of the priority levels. Most can be masked on (enabled) or off (disabled). When disabled, the fault is always treated as a Hard Fault. */
#define     NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_4_SHIFT 0u
#define     NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_4_MASK  0xffu
#define GET_NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_4(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_4(__val__)  (((__val__) << 0u) & 0xffu)
#define     NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_5_SHIFT 8u
#define     NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_5_MASK  0xff00u
#define GET_NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_5(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_5(__val__)  (((__val__) << 8u) & 0xff00u)
#define     NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_6_SHIFT 16u
#define     NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_6_MASK  0xff0000u
#define GET_NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_6(__reg__)  (((__reg__) & 0xff0000) >> 16u)
#define SET_NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_6(__val__)  (((__val__) << 16u) & 0xff0000u)
#define     NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_7_SHIFT 24u
#define     NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_7_MASK  0xff000000u
#define GET_NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_7(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_NVIC_SYSTEM_HANDLER_PRIORITY_4_PRI_7(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref NVIC_t.SystemHandlerPriority4. */
typedef register_container RegNVICSystemHandlerPriority4_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Priority of Mem Manage. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_4, 0, 8)
        /** @brief Priority of Bus Fault. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_5, 8, 8)
        /** @brief Priority of Usage Fault. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_6, 16, 8)
        /** @brief Reserved. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_7, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Reserved. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_7, 24, 8)
        /** @brief Priority of Usage Fault. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_6, 16, 8)
        /** @brief Priority of Bus Fault. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_5, 8, 8)
        /** @brief Priority of Mem Manage. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_4, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SystemHandlerPriority4"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICSystemHandlerPriority4_t()
    {
        /** @brief constructor for @ref NVIC_t.SystemHandlerPriority4. */
        r32.setName("SystemHandlerPriority4");
        bits.PRI_4.setBaseRegister(&r32);
        bits.PRI_4.setName("PRI_4");
        bits.PRI_5.setBaseRegister(&r32);
        bits.PRI_5.setName("PRI_5");
        bits.PRI_6.setBaseRegister(&r32);
        bits.PRI_6.setName("PRI_6");
        bits.PRI_7.setBaseRegister(&r32);
        bits.PRI_7.setName("PRI_7");
    }
    RegNVICSystemHandlerPriority4_t& operator=(const RegNVICSystemHandlerPriority4_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICSystemHandlerPriority4_t;

#define REG_NVIC_SYSTEM_HANDLER_PRIORITY_8 ((volatile APE_NVIC_H_uint32_t*)0xe000ed1c) /* System handlers are a special class of exception handler that can have their priority set to any of the priority levels. Most can be masked on (enabled) or off (disabled). When disabled, the fault is always treated as a Hard Fault. */
#define     NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_8_SHIFT 0u
#define     NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_8_MASK  0xffu
#define GET_NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_8(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_8(__val__)  (((__val__) << 0u) & 0xffu)
#define     NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_9_SHIFT 8u
#define     NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_9_MASK  0xff00u
#define GET_NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_9(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_9(__val__)  (((__val__) << 8u) & 0xff00u)
#define     NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_10_SHIFT 16u
#define     NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_10_MASK  0xff0000u
#define GET_NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_10(__reg__)  (((__reg__) & 0xff0000) >> 16u)
#define SET_NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_10(__val__)  (((__val__) << 16u) & 0xff0000u)
#define     NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_11_SHIFT 24u
#define     NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_11_MASK  0xff000000u
#define GET_NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_11(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_NVIC_SYSTEM_HANDLER_PRIORITY_8_PRI_11(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref NVIC_t.SystemHandlerPriority8. */
typedef register_container RegNVICSystemHandlerPriority8_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Reserved. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_8, 0, 8)
        /** @brief Reserved. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_9, 8, 8)
        /** @brief Reserved. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_10, 16, 8)
        /** @brief Priority of SVCall. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_11, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Priority of SVCall. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_11, 24, 8)
        /** @brief Reserved. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_10, 16, 8)
        /** @brief Reserved. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_9, 8, 8)
        /** @brief Reserved. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_8, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SystemHandlerPriority8"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICSystemHandlerPriority8_t()
    {
        /** @brief constructor for @ref NVIC_t.SystemHandlerPriority8. */
        r32.setName("SystemHandlerPriority8");
        bits.PRI_8.setBaseRegister(&r32);
        bits.PRI_8.setName("PRI_8");
        bits.PRI_9.setBaseRegister(&r32);
        bits.PRI_9.setName("PRI_9");
        bits.PRI_10.setBaseRegister(&r32);
        bits.PRI_10.setName("PRI_10");
        bits.PRI_11.setBaseRegister(&r32);
        bits.PRI_11.setName("PRI_11");
    }
    RegNVICSystemHandlerPriority8_t& operator=(const RegNVICSystemHandlerPriority8_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICSystemHandlerPriority8_t;

#define REG_NVIC_SYSTEM_HANDLER_PRIORITY_12 ((volatile APE_NVIC_H_uint32_t*)0xe000ed20) /* System handlers are a special class of exception handler that can have their priority set to any of the priority levels. Most can be masked on (enabled) or off (disabled). When disabled, the fault is always treated as a Hard Fault. */
#define     NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_12_SHIFT 0u
#define     NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_12_MASK  0xffu
#define GET_NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_12(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_12(__val__)  (((__val__) << 0u) & 0xffu)
#define     NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_13_SHIFT 8u
#define     NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_13_MASK  0xff00u
#define GET_NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_13(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_13(__val__)  (((__val__) << 8u) & 0xff00u)
#define     NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_14_SHIFT 16u
#define     NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_14_MASK  0xff0000u
#define GET_NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_14(__reg__)  (((__reg__) & 0xff0000) >> 16u)
#define SET_NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_14(__val__)  (((__val__) << 16u) & 0xff0000u)
#define     NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_15_SHIFT 24u
#define     NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_15_MASK  0xff000000u
#define GET_NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_15(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_NVIC_SYSTEM_HANDLER_PRIORITY_12_PRI_15(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref NVIC_t.SystemHandlerPriority12. */
typedef register_container RegNVICSystemHandlerPriority12_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Priority of Debug Monitor. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_12, 0, 8)
        /** @brief Reserved. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_13, 8, 8)
        /** @brief Priority of PendSV. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_14, 16, 8)
        /** @brief Priority of SysTick. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_15, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Priority of SysTick. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_15, 24, 8)
        /** @brief Priority of PendSV. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_14, 16, 8)
        /** @brief Reserved. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_13, 8, 8)
        /** @brief Priority of Debug Monitor. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PRI_12, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SystemHandlerPriority12"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICSystemHandlerPriority12_t()
    {
        /** @brief constructor for @ref NVIC_t.SystemHandlerPriority12. */
        r32.setName("SystemHandlerPriority12");
        bits.PRI_12.setBaseRegister(&r32);
        bits.PRI_12.setName("PRI_12");
        bits.PRI_13.setBaseRegister(&r32);
        bits.PRI_13.setName("PRI_13");
        bits.PRI_14.setBaseRegister(&r32);
        bits.PRI_14.setName("PRI_14");
        bits.PRI_15.setBaseRegister(&r32);
        bits.PRI_15.setName("PRI_15");
    }
    RegNVICSystemHandlerPriority12_t& operator=(const RegNVICSystemHandlerPriority12_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICSystemHandlerPriority12_t;

#define REG_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE ((volatile APE_NVIC_H_uint32_t*)0xe000ed24) /* Use the System Handler Control and State Register to: enable or disable the system handlers, determine the pending status of bus fault, mem manage fault, and SVC, determine the active status of the system handlers. */
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MEMFAULTACT_SHIFT 0u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MEMFAULTACT_MASK  0x1u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MEMFAULTACT(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MEMFAULTACT(__val__)  (((__val__) << 0u) & 0x1u)
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_BUSFAULTACT_SHIFT 1u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_BUSFAULTACT_MASK  0x2u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_BUSFAULTACT(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_BUSFAULTACT(__val__)  (((__val__) << 1u) & 0x2u)
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_USGFAULTACT_SHIFT 3u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_USGFAULTACT_MASK  0x8u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_USGFAULTACT(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_USGFAULTACT(__val__)  (((__val__) << 3u) & 0x8u)
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_SVCALLACT_SHIFT 7u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_SVCALLACT_MASK  0x80u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_SVCALLACT(__reg__)  (((__reg__) & 0x80) >> 7u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_SVCALLACT(__val__)  (((__val__) << 7u) & 0x80u)
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MONITORACT_SHIFT 8u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MONITORACT_MASK  0x100u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MONITORACT(__reg__)  (((__reg__) & 0x100) >> 8u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MONITORACT(__val__)  (((__val__) << 8u) & 0x100u)
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_PENDSVACT_SHIFT 10u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_PENDSVACT_MASK  0x400u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_PENDSVACT(__reg__)  (((__reg__) & 0x400) >> 10u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_PENDSVACT(__val__)  (((__val__) << 10u) & 0x400u)
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_SYSTICKACT_SHIFT 11u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_SYSTICKACT_MASK  0x800u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_SYSTICKACT(__reg__)  (((__reg__) & 0x800) >> 11u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_SYSTICKACT(__val__)  (((__val__) << 11u) & 0x800u)
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_USGFAULTPENDED_SHIFT 12u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_USGFAULTPENDED_MASK  0x1000u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_USGFAULTPENDED(__reg__)  (((__reg__) & 0x1000) >> 12u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_USGFAULTPENDED(__val__)  (((__val__) << 12u) & 0x1000u)
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MEMFAULTPENDED_SHIFT 13u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MEMFAULTPENDED_MASK  0x2000u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MEMFAULTPENDED(__reg__)  (((__reg__) & 0x2000) >> 13u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MEMFAULTPENDED(__val__)  (((__val__) << 13u) & 0x2000u)
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_BUSFAULTPENDED_SHIFT 14u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_BUSFAULTPENDED_MASK  0x4000u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_BUSFAULTPENDED(__reg__)  (((__reg__) & 0x4000) >> 14u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_BUSFAULTPENDED(__val__)  (((__val__) << 14u) & 0x4000u)
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_SVCALLPENDED_SHIFT 15u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_SVCALLPENDED_MASK  0x8000u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_SVCALLPENDED(__reg__)  (((__reg__) & 0x8000) >> 15u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_SVCALLPENDED(__val__)  (((__val__) << 15u) & 0x8000u)
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MEMFAULTENA_SHIFT 16u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MEMFAULTENA_MASK  0x10000u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MEMFAULTENA(__reg__)  (((__reg__) & 0x10000) >> 16u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_MEMFAULTENA(__val__)  (((__val__) << 16u) & 0x10000u)
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_BUSFAULTENA_SHIFT 17u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_BUSFAULTENA_MASK  0x20000u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_BUSFAULTENA(__reg__)  (((__reg__) & 0x20000) >> 17u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_BUSFAULTENA(__val__)  (((__val__) << 17u) & 0x20000u)
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_USGFAULTENA_SHIFT 18u
#define     NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_USGFAULTENA_MASK  0x40000u
#define GET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_USGFAULTENA(__reg__)  (((__reg__) & 0x40000) >> 18u)
#define SET_NVIC_SYSTEM_HANDLER_CONTROL_AND_STATE_USGFAULTENA(__val__)  (((__val__) << 18u) & 0x40000u)

/** @brief Register definition for @ref NVIC_t.SystemHandlerControlAndState. */
typedef register_container RegNVICSystemHandlerControlAndState_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Reads as 1 if MemManage is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, MEMFAULTACT, 0, 1)
        /** @brief Reads as 1 if BusFault is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, BUSFAULTACT, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_2_2, 2, 1)
        /** @brief Reads as 1 if UsageFault is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, USGFAULTACT, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_6_4, 4, 3)
        /** @brief Reads as 1 if SVCall is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SVCALLACT, 7, 1)
        /** @brief Reads as 1 if the Monitor is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, MONITORACT, 8, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_9_9, 9, 1)
        /** @brief Reads as 1 if PendSV is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PENDSVACT, 10, 1)
        /** @brief Reads as 1 if SysTick is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SYSTICKACT, 11, 1)
        /** @brief Read as 1 if usage fault is pended. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, USGFAULTPENDED, 12, 1)
        /** @brief Reads as 1 if MemManage is pended. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, MEMFAULTPENDED, 13, 1)
        /** @brief Reads as 1 if BusFault is pended. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, BUSFAULTPENDED, 14, 1)
        /** @brief Reads as 1 if SVCall is pended. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SVCALLPENDED, 15, 1)
        /** @brief Set to 0 to disable, else 1 for enabled. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, MEMFAULTENA, 16, 1)
        /** @brief Set to 0 to disable, else 1 for enabled. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, BUSFAULTENA, 17, 1)
        /** @brief Set to 0 to disable, else 1 for enabled. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, USGFAULTENA, 18, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_19, 19, 13)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_19, 19, 13)
        /** @brief Set to 0 to disable, else 1 for enabled. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, USGFAULTENA, 18, 1)
        /** @brief Set to 0 to disable, else 1 for enabled. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, BUSFAULTENA, 17, 1)
        /** @brief Set to 0 to disable, else 1 for enabled. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, MEMFAULTENA, 16, 1)
        /** @brief Reads as 1 if SVCall is pended. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SVCALLPENDED, 15, 1)
        /** @brief Reads as 1 if BusFault is pended. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, BUSFAULTPENDED, 14, 1)
        /** @brief Reads as 1 if MemManage is pended. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, MEMFAULTPENDED, 13, 1)
        /** @brief Read as 1 if usage fault is pended. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, USGFAULTPENDED, 12, 1)
        /** @brief Reads as 1 if SysTick is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SYSTICKACT, 11, 1)
        /** @brief Reads as 1 if PendSV is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, PENDSVACT, 10, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_9_9, 9, 1)
        /** @brief Reads as 1 if the Monitor is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, MONITORACT, 8, 1)
        /** @brief Reads as 1 if SVCall is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, SVCALLACT, 7, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_6_4, 4, 3)
        /** @brief Reads as 1 if UsageFault is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, USGFAULTACT, 3, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_2_2, 2, 1)
        /** @brief Reads as 1 if BusFault is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, BUSFAULTACT, 1, 1)
        /** @brief Reads as 1 if MemManage is active. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, MEMFAULTACT, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SystemHandlerControlAndState"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICSystemHandlerControlAndState_t()
    {
        /** @brief constructor for @ref NVIC_t.SystemHandlerControlAndState. */
        r32.setName("SystemHandlerControlAndState");
        bits.MEMFAULTACT.setBaseRegister(&r32);
        bits.MEMFAULTACT.setName("MEMFAULTACT");
        bits.BUSFAULTACT.setBaseRegister(&r32);
        bits.BUSFAULTACT.setName("BUSFAULTACT");
        bits.USGFAULTACT.setBaseRegister(&r32);
        bits.USGFAULTACT.setName("USGFAULTACT");
        bits.SVCALLACT.setBaseRegister(&r32);
        bits.SVCALLACT.setName("SVCALLACT");
        bits.MONITORACT.setBaseRegister(&r32);
        bits.MONITORACT.setName("MONITORACT");
        bits.PENDSVACT.setBaseRegister(&r32);
        bits.PENDSVACT.setName("PENDSVACT");
        bits.SYSTICKACT.setBaseRegister(&r32);
        bits.SYSTICKACT.setName("SYSTICKACT");
        bits.USGFAULTPENDED.setBaseRegister(&r32);
        bits.USGFAULTPENDED.setName("USGFAULTPENDED");
        bits.MEMFAULTPENDED.setBaseRegister(&r32);
        bits.MEMFAULTPENDED.setName("MEMFAULTPENDED");
        bits.BUSFAULTPENDED.setBaseRegister(&r32);
        bits.BUSFAULTPENDED.setName("BUSFAULTPENDED");
        bits.SVCALLPENDED.setBaseRegister(&r32);
        bits.SVCALLPENDED.setName("SVCALLPENDED");
        bits.MEMFAULTENA.setBaseRegister(&r32);
        bits.MEMFAULTENA.setName("MEMFAULTENA");
        bits.BUSFAULTENA.setBaseRegister(&r32);
        bits.BUSFAULTENA.setName("BUSFAULTENA");
        bits.USGFAULTENA.setBaseRegister(&r32);
        bits.USGFAULTENA.setName("USGFAULTENA");
    }
    RegNVICSystemHandlerControlAndState_t& operator=(const RegNVICSystemHandlerControlAndState_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICSystemHandlerControlAndState_t;

#define REG_NVIC_FAULT_STATUS ((volatile APE_NVIC_H_uint32_t*)0xe000ed28) /* The flags in these registers indicate the causes of local faults. Multiple flags can be set if more than one fault occurs. These register are read/write-clear. This means that they can be read normally, but writing a 1 to any bit clears that bit. */
#define     NVIC_FAULT_STATUS_MEMORY_MANAGE_FAULT_STATUS_SHIFT 0u
#define     NVIC_FAULT_STATUS_MEMORY_MANAGE_FAULT_STATUS_MASK  0xffu
#define GET_NVIC_FAULT_STATUS_MEMORY_MANAGE_FAULT_STATUS(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_NVIC_FAULT_STATUS_MEMORY_MANAGE_FAULT_STATUS(__val__)  (((__val__) << 0u) & 0xffu)
#define     NVIC_FAULT_STATUS_BUS_FAULT_STATUS_SHIFT 8u
#define     NVIC_FAULT_STATUS_BUS_FAULT_STATUS_MASK  0xff00u
#define GET_NVIC_FAULT_STATUS_BUS_FAULT_STATUS(__reg__)  (((__reg__) & 0xff00) >> 8u)
#define SET_NVIC_FAULT_STATUS_BUS_FAULT_STATUS(__val__)  (((__val__) << 8u) & 0xff00u)
#define     NVIC_FAULT_STATUS_USAGE_FAULT_STATUS_SHIFT 16u
#define     NVIC_FAULT_STATUS_USAGE_FAULT_STATUS_MASK  0xff0000u
#define GET_NVIC_FAULT_STATUS_USAGE_FAULT_STATUS(__reg__)  (((__reg__) & 0xff0000) >> 16u)
#define SET_NVIC_FAULT_STATUS_USAGE_FAULT_STATUS(__val__)  (((__val__) << 16u) & 0xff0000u)
#define     NVIC_FAULT_STATUS_RESERVED_SHIFT 24u
#define     NVIC_FAULT_STATUS_RESERVED_MASK  0xff000000u
#define GET_NVIC_FAULT_STATUS_RESERVED(__reg__)  (((__reg__) & 0xff000000) >> 24u)
#define SET_NVIC_FAULT_STATUS_RESERVED(__val__)  (((__val__) << 24u) & 0xff000000u)

/** @brief Register definition for @ref NVIC_t.FaultStatus. */
typedef register_container RegNVICFaultStatus_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief The flags in the Memory Manage Fault Status Register indicate the cause of memory access faults. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, MemoryManageFaultStatus, 0, 8)
        /** @brief The flags in the Bus Fault Status Register indicate the cause of bus access faults. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, BusFaultStatus, 8, 8)
        /** @brief The flags in the Bus Fault Status Register indicate the cause of usage faults. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, UsageFaultStatus, 16, 8)
        /** @brief Reserved. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, Reserved, 24, 8)
#elif defined(__BIG_ENDIAN__)
        /** @brief Reserved. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, Reserved, 24, 8)
        /** @brief The flags in the Bus Fault Status Register indicate the cause of usage faults. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, UsageFaultStatus, 16, 8)
        /** @brief The flags in the Bus Fault Status Register indicate the cause of bus access faults. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, BusFaultStatus, 8, 8)
        /** @brief The flags in the Memory Manage Fault Status Register indicate the cause of memory access faults. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, MemoryManageFaultStatus, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "FaultStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICFaultStatus_t()
    {
        /** @brief constructor for @ref NVIC_t.FaultStatus. */
        r32.setName("FaultStatus");
        bits.MemoryManageFaultStatus.setBaseRegister(&r32);
        bits.MemoryManageFaultStatus.setName("MemoryManageFaultStatus");
        bits.BusFaultStatus.setBaseRegister(&r32);
        bits.BusFaultStatus.setName("BusFaultStatus");
        bits.UsageFaultStatus.setBaseRegister(&r32);
        bits.UsageFaultStatus.setName("UsageFaultStatus");
        bits.Reserved.setBaseRegister(&r32);
        bits.Reserved.setName("Reserved");
    }
    RegNVICFaultStatus_t& operator=(const RegNVICFaultStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICFaultStatus_t;

#define REG_NVIC_HARD_FAULT_STATUS ((volatile APE_NVIC_H_uint32_t*)0xe000ed2c) /* Use the Hard Fault Status Register (HFSR) to obtain information about events that activate the Hard Fault handler. */
#define     NVIC_HARD_FAULT_STATUS_VECTTBL_SHIFT 1u
#define     NVIC_HARD_FAULT_STATUS_VECTTBL_MASK  0x2u
#define GET_NVIC_HARD_FAULT_STATUS_VECTTBL(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVIC_HARD_FAULT_STATUS_VECTTBL(__val__)  (((__val__) << 1u) & 0x2u)
#define     NVIC_HARD_FAULT_STATUS_FORCED_SHIFT 30u
#define     NVIC_HARD_FAULT_STATUS_FORCED_MASK  0x40000000u
#define GET_NVIC_HARD_FAULT_STATUS_FORCED(__reg__)  (((__reg__) & 0x40000000) >> 30u)
#define SET_NVIC_HARD_FAULT_STATUS_FORCED(__val__)  (((__val__) << 30u) & 0x40000000u)
#define     NVIC_HARD_FAULT_STATUS_DEBUGEVT_SHIFT 31u
#define     NVIC_HARD_FAULT_STATUS_DEBUGEVT_MASK  0x80000000u
#define GET_NVIC_HARD_FAULT_STATUS_DEBUGEVT(__reg__)  (((__reg__) & 0x80000000) >> 31u)
#define SET_NVIC_HARD_FAULT_STATUS_DEBUGEVT(__val__)  (((__val__) << 31u) & 0x80000000u)

/** @brief Register definition for @ref NVIC_t.HardFaultStatus. */
typedef register_container RegNVICHardFaultStatus_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_0_0, 0, 1)
        /** @brief This bit is set if there is a fault because of vector table read on exception processing (Bus Fault). This case is always a Hard Fault. The return PC points to the pre-empted instruction. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VECTTBL, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_29_2, 2, 28)
        /** @brief Hard Fault activated because a Configurable Fault was received and cannot activate because of priority or because the Configurable Fault is disabled. The Hard Fault handler then has to read the other fault status registers to determine cause. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, FORCED, 30, 1)
        /** @brief This bit is set if there is a fault related to debug. This is only possible when halting debug is not enabled. For monitor enabled debug, it only happens for BKPT when the current priority is higher than the monitor. When both halting and monitor debug are disabled, it only happens for debug events that are not ignored (minimally, BKPT). The Debug Fault Status Register is updated. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, DEBUGEVT, 31, 1)
#elif defined(__BIG_ENDIAN__)
        /** @brief This bit is set if there is a fault related to debug. This is only possible when halting debug is not enabled. For monitor enabled debug, it only happens for BKPT when the current priority is higher than the monitor. When both halting and monitor debug are disabled, it only happens for debug events that are not ignored (minimally, BKPT). The Debug Fault Status Register is updated. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, DEBUGEVT, 31, 1)
        /** @brief Hard Fault activated because a Configurable Fault was received and cannot activate because of priority or because the Configurable Fault is disabled. The Hard Fault handler then has to read the other fault status registers to determine cause. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, FORCED, 30, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_29_2, 2, 28)
        /** @brief This bit is set if there is a fault because of vector table read on exception processing (Bus Fault). This case is always a Hard Fault. The return PC points to the pre-empted instruction. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VECTTBL, 1, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_0_0, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "HardFaultStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICHardFaultStatus_t()
    {
        /** @brief constructor for @ref NVIC_t.HardFaultStatus. */
        r32.setName("HardFaultStatus");
        bits.VECTTBL.setBaseRegister(&r32);
        bits.VECTTBL.setName("VECTTBL");
        bits.FORCED.setBaseRegister(&r32);
        bits.FORCED.setName("FORCED");
        bits.DEBUGEVT.setBaseRegister(&r32);
        bits.DEBUGEVT.setName("DEBUGEVT");
    }
    RegNVICHardFaultStatus_t& operator=(const RegNVICHardFaultStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICHardFaultStatus_t;

#define REG_NVIC_DEBUG_FAULT_STATUS ((volatile APE_NVIC_H_uint32_t*)0xe000ed30) /* Use the Debug Fault Status Register to monitor: external debug requests, vector catches, data watchpoint match, BKPT instruction execution, halt requests. */
#define     NVIC_DEBUG_FAULT_STATUS_HALTED_SHIFT 0u
#define     NVIC_DEBUG_FAULT_STATUS_HALTED_MASK  0x1u
#define GET_NVIC_DEBUG_FAULT_STATUS_HALTED(__reg__)  (((__reg__) & 0x1) >> 0u)
#define SET_NVIC_DEBUG_FAULT_STATUS_HALTED(__val__)  (((__val__) << 0u) & 0x1u)
#define     NVIC_DEBUG_FAULT_STATUS_BKPT_SHIFT 1u
#define     NVIC_DEBUG_FAULT_STATUS_BKPT_MASK  0x2u
#define GET_NVIC_DEBUG_FAULT_STATUS_BKPT(__reg__)  (((__reg__) & 0x2) >> 1u)
#define SET_NVIC_DEBUG_FAULT_STATUS_BKPT(__val__)  (((__val__) << 1u) & 0x2u)
#define     NVIC_DEBUG_FAULT_STATUS_DWTTRAP_SHIFT 2u
#define     NVIC_DEBUG_FAULT_STATUS_DWTTRAP_MASK  0x4u
#define GET_NVIC_DEBUG_FAULT_STATUS_DWTTRAP(__reg__)  (((__reg__) & 0x4) >> 2u)
#define SET_NVIC_DEBUG_FAULT_STATUS_DWTTRAP(__val__)  (((__val__) << 2u) & 0x4u)
#define     NVIC_DEBUG_FAULT_STATUS_VCATCH_SHIFT 3u
#define     NVIC_DEBUG_FAULT_STATUS_VCATCH_MASK  0x8u
#define GET_NVIC_DEBUG_FAULT_STATUS_VCATCH(__reg__)  (((__reg__) & 0x8) >> 3u)
#define SET_NVIC_DEBUG_FAULT_STATUS_VCATCH(__val__)  (((__val__) << 3u) & 0x8u)
#define     NVIC_DEBUG_FAULT_STATUS_EXTERNAL_SHIFT 4u
#define     NVIC_DEBUG_FAULT_STATUS_EXTERNAL_MASK  0x10u
#define GET_NVIC_DEBUG_FAULT_STATUS_EXTERNAL(__reg__)  (((__reg__) & 0x10) >> 4u)
#define SET_NVIC_DEBUG_FAULT_STATUS_EXTERNAL(__val__)  (((__val__) << 4u) & 0x10u)

/** @brief Register definition for @ref NVIC_t.DebugFaultStatus. */
typedef register_container RegNVICDebugFaultStatus_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief 1 = halt requested by NVIC, including step. The processor is halted on the next instruction. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, HALTED, 0, 1)
        /** @brief The BKPT flag is set by a BKPT instruction in flash patch code, and also by normal code. Return PC points to breakpoint containing instruction. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, BKPT, 1, 1)
        /** @brief Data Watchpoint and Trace (DWT) flag. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, DWTTRAP, 2, 1)
        /** @brief Vector catch flag. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VCATCH, 3, 1)
        /** @brief External debug request flag. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, EXTERNAL, 4, 1)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_5, 5, 27)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_5, 5, 27)
        /** @brief External debug request flag. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, EXTERNAL, 4, 1)
        /** @brief Vector catch flag. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, VCATCH, 3, 1)
        /** @brief Data Watchpoint and Trace (DWT) flag. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, DWTTRAP, 2, 1)
        /** @brief The BKPT flag is set by a BKPT instruction in flash patch code, and also by normal code. Return PC points to breakpoint containing instruction. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, BKPT, 1, 1)
        /** @brief 1 = halt requested by NVIC, including step. The processor is halted on the next instruction. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, HALTED, 0, 1)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "DebugFaultStatus"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICDebugFaultStatus_t()
    {
        /** @brief constructor for @ref NVIC_t.DebugFaultStatus. */
        r32.setName("DebugFaultStatus");
        bits.HALTED.setBaseRegister(&r32);
        bits.HALTED.setName("HALTED");
        bits.BKPT.setBaseRegister(&r32);
        bits.BKPT.setName("BKPT");
        bits.DWTTRAP.setBaseRegister(&r32);
        bits.DWTTRAP.setName("DWTTRAP");
        bits.VCATCH.setBaseRegister(&r32);
        bits.VCATCH.setName("VCATCH");
        bits.EXTERNAL.setBaseRegister(&r32);
        bits.EXTERNAL.setName("EXTERNAL");
    }
    RegNVICDebugFaultStatus_t& operator=(const RegNVICDebugFaultStatus_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICDebugFaultStatus_t;

#define REG_NVIC_MEMORY_MANAGE_FAULT_ADDRESS ((volatile APE_NVIC_H_uint32_t*)0xe000ed34) /* Use the Memory Manage Fault Address Register to read the address of the location that caused a Memory Manage Fault. */
#define     NVIC_MEMORY_MANAGE_FAULT_ADDRESS_ADDRESS_SHIFT 0u
#define     NVIC_MEMORY_MANAGE_FAULT_ADDRESS_ADDRESS_MASK  0xffffffffu
#define GET_NVIC_MEMORY_MANAGE_FAULT_ADDRESS_ADDRESS(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_NVIC_MEMORY_MANAGE_FAULT_ADDRESS_ADDRESS(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref NVIC_t.MemoryManageFaultAddress. */
typedef register_container RegNVICMemoryManageFaultAddress_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Mem Manage fault address field. ADDRESS is the data address of a faulted load or store attempt. When an unaligned access faults, the address is the actual address that faulted. Because an access can be split into multiple parts, each aligned, this address can be any offset in the range of the requested size. Flags in the Memory Manage Fault Status Register indicate the cause of the fault. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ADDRESS, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Mem Manage fault address field. ADDRESS is the data address of a faulted load or store attempt. When an unaligned access faults, the address is the actual address that faulted. Because an access can be split into multiple parts, each aligned, this address can be any offset in the range of the requested size. Flags in the Memory Manage Fault Status Register indicate the cause of the fault. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ADDRESS, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "MemoryManageFaultAddress"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICMemoryManageFaultAddress_t()
    {
        /** @brief constructor for @ref NVIC_t.MemoryManageFaultAddress. */
        r32.setName("MemoryManageFaultAddress");
        bits.ADDRESS.setBaseRegister(&r32);
        bits.ADDRESS.setName("ADDRESS");
    }
    RegNVICMemoryManageFaultAddress_t& operator=(const RegNVICMemoryManageFaultAddress_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICMemoryManageFaultAddress_t;

#define REG_NVIC_BUS_FAULT_ADDRESS ((volatile APE_NVIC_H_uint32_t*)0xe000ed38) /* Use the Bus Fault Address Register to read the address of the location that generated a Bus Fault. */
#define     NVIC_BUS_FAULT_ADDRESS_ADDRESS_SHIFT 0u
#define     NVIC_BUS_FAULT_ADDRESS_ADDRESS_MASK  0xffffffffu
#define GET_NVIC_BUS_FAULT_ADDRESS_ADDRESS(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_NVIC_BUS_FAULT_ADDRESS_ADDRESS(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref NVIC_t.BusFaultAddress. */
typedef register_container RegNVICBusFaultAddress_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Bus fault address field. ADDRESS is the data address of a faulted load or store attempt. When an unaligned access faults, the address is the address requested by the instruction, even if that is not the address that faulted. Flags in the Bus Fault Status Register indicate the cause of the fault. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ADDRESS, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Bus fault address field. ADDRESS is the data address of a faulted load or store attempt. When an unaligned access faults, the address is the address requested by the instruction, even if that is not the address that faulted. Flags in the Bus Fault Status Register indicate the cause of the fault. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, ADDRESS, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "BusFaultAddress"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICBusFaultAddress_t()
    {
        /** @brief constructor for @ref NVIC_t.BusFaultAddress. */
        r32.setName("BusFaultAddress");
        bits.ADDRESS.setBaseRegister(&r32);
        bits.ADDRESS.setName("ADDRESS");
    }
    RegNVICBusFaultAddress_t& operator=(const RegNVICBusFaultAddress_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICBusFaultAddress_t;

#define REG_NVIC_AUXILIARY_FAULT_ADDRESS ((volatile APE_NVIC_H_uint32_t*)0xe000ed3c) /* Use the Auxiliary Fault Status Register (AFSR) to determine additional system fault information to software. The AFSR flags map directly onto the AUXFAULT inputs of the processor, and a single-cycle high level on an external pin causes the corresponding AFSR bit to become latched as one. The bit can only be cleared by writing a one to the corresponding AFSR bit. When an AFSR bit is written or latched as one, an exception does not occur. If you require an exception, you must use an interrupt. */
#define     NVIC_AUXILIARY_FAULT_ADDRESS_IMPDEF_SHIFT 0u
#define     NVIC_AUXILIARY_FAULT_ADDRESS_IMPDEF_MASK  0xffffffffu
#define GET_NVIC_AUXILIARY_FAULT_ADDRESS_IMPDEF(__reg__)  (((__reg__) & 0xffffffff) >> 0u)
#define SET_NVIC_AUXILIARY_FAULT_ADDRESS_IMPDEF(__val__)  (((__val__) << 0u) & 0xffffffffu)

/** @brief Register definition for @ref NVIC_t.AuxiliaryFaultAddress. */
typedef register_container RegNVICAuxiliaryFaultAddress_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Implementation defined. The bits map directly onto the signal assignment to the AUXFAULT inputs. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, IMPDEF, 0, 32)
#elif defined(__BIG_ENDIAN__)
        /** @brief Implementation defined. The bits map directly onto the signal assignment to the AUXFAULT inputs. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, IMPDEF, 0, 32)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "AuxiliaryFaultAddress"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICAuxiliaryFaultAddress_t()
    {
        /** @brief constructor for @ref NVIC_t.AuxiliaryFaultAddress. */
        r32.setName("AuxiliaryFaultAddress");
        bits.IMPDEF.setBaseRegister(&r32);
        bits.IMPDEF.setName("IMPDEF");
    }
    RegNVICAuxiliaryFaultAddress_t& operator=(const RegNVICAuxiliaryFaultAddress_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICAuxiliaryFaultAddress_t;

#define REG_NVIC_SOFTWARE_TRIGGER_INTERRUPT ((volatile APE_NVIC_H_uint32_t*)0xe000ef00) /* Use the Software Trigger Interrupt Register to pend an interrupt to trigger. */
#define     NVIC_SOFTWARE_TRIGGER_INTERRUPT_INTID_SHIFT 0u
#define     NVIC_SOFTWARE_TRIGGER_INTERRUPT_INTID_MASK  0xffu
#define GET_NVIC_SOFTWARE_TRIGGER_INTERRUPT_INTID(__reg__)  (((__reg__) & 0xff) >> 0u)
#define SET_NVIC_SOFTWARE_TRIGGER_INTERRUPT_INTID(__val__)  (((__val__) << 0u) & 0xffu)

/** @brief Register definition for @ref NVIC_t.SoftwareTriggerInterrupt. */
typedef register_container RegNVICSoftwareTriggerInterrupt_t {
    /** @brief 32bit direct register access. */
    APE_NVIC_H_uint32_t r32;

    BITFIELD_BEGIN(APE_NVIC_H_uint32_t, bits)
#if defined(__LITTLE_ENDIAN__)
        /** @brief Interrupt ID field. Writing a value to the INTID field is the same as manually pending an interrupt by setting the corresponding interrupt bit in an Interrupt Set Pending Register. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, INTID, 0, 8)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_8, 8, 24)
#elif defined(__BIG_ENDIAN__)
        /** @brief Padding */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, reserved_31_8, 8, 24)
        /** @brief Interrupt ID field. Writing a value to the INTID field is the same as manually pending an interrupt by setting the corresponding interrupt bit in an Interrupt Set Pending Register. */
        BITFIELD_MEMBER(APE_NVIC_H_uint32_t, INTID, 0, 8)
#else
#error Unknown Endian
#endif
    BITFIELD_END(APE_NVIC_H_uint32_t, bits)
#ifdef CXX_SIMULATOR
    /** @brief Register name for use with the simulator. */
    const char* getName(void) { return "SoftwareTriggerInterrupt"; }

    /** @brief Print register value. */
    void print(void) { r32.print(); }

    RegNVICSoftwareTriggerInterrupt_t()
    {
        /** @brief constructor for @ref NVIC_t.SoftwareTriggerInterrupt. */
        r32.setName("SoftwareTriggerInterrupt");
        bits.INTID.setBaseRegister(&r32);
        bits.INTID.setName("INTID");
    }
    RegNVICSoftwareTriggerInterrupt_t& operator=(const RegNVICSoftwareTriggerInterrupt_t& other)
    {
        r32 = other.r32;
        return *this;
    }
#endif /* CXX_SIMULATOR */
} RegNVICSoftwareTriggerInterrupt_t;

/** @brief Component definition for @ref NVIC. */
typedef struct {
    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint32_t reserved_0[1];

    /** @brief Read the Interrupt Controller Type Register to see the number of interrupt lines that the NVIC supports. */
    RegNVICInterruptControlType_t InterruptControlType;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_5[11];

    /** @brief Use the SysTick Control and Status Register to enable the SysTick features. */
    RegNVICSystickControlAndStatus_t SystickControlAndStatus;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_17[3];

    /** @brief Use the SysTick Reload Value Register to specify the start value to load into the current value register when the counter reaches 0. It can be any value between 1 and 0x00FFFFFF. A start value of 0 is possible, but has no effect because the SysTick interrupt and COUNTFLAG are activated when counting from 1 to 0. */
    RegNVICSystickReloadValue_t SystickReloadValue;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_21[3];

    /** @brief Use the SysTick Current Value Register to find the current value in the register. */
    RegNVICSystickCurrentValue_t SystickCurrentValue;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_25[3];

    /** @brief Use the SysTick Calibration Value Register to enable software to scale to any required speed using divide and multiply. */
    RegNVICSystickCalibrationValue_t SystickCalibrationValue;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_29[227];

    /** @brief Each bit in the register corresponds to one of 32 interrupts. Setting a bit in the Interrupt Set-Enable Register enables the corresponding interrupt. When the enable bit of a pending interrupt is set, the processor activates the interrupt based on its priority. When the enable bit is clear, asserting its interrupt signal pends the interrupt, but it is not possible to activate the interrupt, regardless of its priority. Therefore, a disabled interrupt can serve as a latched general-purpose I/O bit. You can read it and clear it without invoking an interrupt. */
    RegNVICInterruptSetEnable_t InterruptSetEnable;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_257[127];

    /** @brief Each bit in the register corresponds to one of the 32 interrupts. Setting an Interrupt Clear-Enable Register bit disables the corresponding interrupt. */
    RegNVICInterruptClearEnable_t InterruptClearEnable;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_385[127];

    /** @brief Each bit in the register corresponds to one of the 32 interrupts. Setting an Interrupt Set-Pending Register bit pends the corresponding interrupt. */
    RegNVICInterruptSetPending_t InterruptSetPending;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_513[127];

    /** @brief Each bit in the register corresponds to one of the 32 interrupts. Setting an Interrupt Clear-Pending Register bit puts the corresponding pending interrupt in the inactive state. */
    RegNVICInterruptClearPending_t InterruptClearPending;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_641[127];

    /** @brief Read the Active Bit Register to determine which interrupts are active. Each flag in the register corresponds to one of the 32 interrupts. */
    RegNVICActiveBit_t ActiveBit;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_769[255];

    /** @brief Use the Interrupt Priority Registers to assign a priority from 0 to 255 to each of the available interrupts. 0 is the highest priority, and 255 is the lowest. */
    RegNVICInterruptPriority0_t InterruptPriority0;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_1025[3];

    /** @brief Use the Interrupt Priority Registers to assign a priority from 0 to 255 to each of the available interrupts. 0 is the highest priority, and 255 is the lowest. */
    RegNVICInterruptPriority1_t InterruptPriority1;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_1029[2299];

    /** @brief Read the CPU ID Base Register to determine: the ID number of the processor core, the version number of the processor core, the implementation details of the processor core. */
    RegNVICCpuId_t CpuId;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3329[3];

    /** @brief Use the Interrupt Control State Register to: set a pending Non-Maskable Interrupt (NMI), set or clear a pending SVC, set or clear a pending SysTick, check for pending exceptions, check the vector number of the highest priority pended exception, check the vector number of the active exception. */
    RegNVICInterruptControlState_t InterruptControlState;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3333[3];

    /** @brief Use the Vector Table Offset Register to determine: if the vector table is in RAM or code memory, the vector table offset. */
    RegNVICVectorTableOffset_t VectorTableOffset;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3337[3];

    /** @brief the Application Interrupt and Reset Control Register to: determine data endianness, clear all active state information for debug or to recover from a hard failure, execute a system reset, alter the priority grouping position (binary point). */
    RegNVICApplicationInterruptAndResetControl_t ApplicationInterruptAndResetControl;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3341[3];

    /** @brief Use the System Control Register for power-management functions: signal to the system when the processor can enter a low power state, control how the processor enters and exits low power states. */
    RegNVICSystemControl_t SystemControl;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3345[3];

    /** @brief Use the Configuration Control Register to: enable NMI, Hard Fault and FAULTMASK to ignore bus fault, trap divide by zero, and unaligned accesses, enable user access to the Software Trigger Exception Register, control entry to Thread Mode. */
    RegNVICConfigurationControl_t ConfigurationControl;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3349[3];

    /** @brief System handlers are a special class of exception handler that can have their priority set to any of the priority levels. Most can be masked on (enabled) or off (disabled). When disabled, the fault is always treated as a Hard Fault. */
    RegNVICSystemHandlerPriority4_t SystemHandlerPriority4;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3353[3];

    /** @brief System handlers are a special class of exception handler that can have their priority set to any of the priority levels. Most can be masked on (enabled) or off (disabled). When disabled, the fault is always treated as a Hard Fault. */
    RegNVICSystemHandlerPriority8_t SystemHandlerPriority8;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3357[3];

    /** @brief System handlers are a special class of exception handler that can have their priority set to any of the priority levels. Most can be masked on (enabled) or off (disabled). When disabled, the fault is always treated as a Hard Fault. */
    RegNVICSystemHandlerPriority12_t SystemHandlerPriority12;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3361[3];

    /** @brief Use the System Handler Control and State Register to: enable or disable the system handlers, determine the pending status of bus fault, mem manage fault, and SVC, determine the active status of the system handlers. */
    RegNVICSystemHandlerControlAndState_t SystemHandlerControlAndState;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3365[3];

    /** @brief The flags in these registers indicate the causes of local faults. Multiple flags can be set if more than one fault occurs. These register are read/write-clear. This means that they can be read normally, but writing a 1 to any bit clears that bit. */
    RegNVICFaultStatus_t FaultStatus;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3369[3];

    /** @brief Use the Hard Fault Status Register (HFSR) to obtain information about events that activate the Hard Fault handler. */
    RegNVICHardFaultStatus_t HardFaultStatus;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3373[3];

    /** @brief Use the Debug Fault Status Register to monitor: external debug requests, vector catches, data watchpoint match, BKPT instruction execution, halt requests. */
    RegNVICDebugFaultStatus_t DebugFaultStatus;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3377[3];

    /** @brief Use the Memory Manage Fault Address Register to read the address of the location that caused a Memory Manage Fault. */
    RegNVICMemoryManageFaultAddress_t MemoryManageFaultAddress;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3381[3];

    /** @brief Use the Bus Fault Address Register to read the address of the location that generated a Bus Fault. */
    RegNVICBusFaultAddress_t BusFaultAddress;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3385[3];

    /** @brief Use the Auxiliary Fault Status Register (AFSR) to determine additional system fault information to software. The AFSR flags map directly onto the AUXFAULT inputs of the processor, and a single-cycle high level on an external pin causes the corresponding AFSR bit to become latched as one. The bit can only be cleared by writing a one to the corresponding AFSR bit. When an AFSR bit is written or latched as one, an exception does not occur. If you require an exception, you must use an interrupt. */
    RegNVICAuxiliaryFaultAddress_t AuxiliaryFaultAddress;

    /** @brief Reserved bytes to pad out data structure. */
    APE_NVIC_H_uint8_t reserved_3389[451];

    /** @brief Use the Software Trigger Interrupt Register to pend an interrupt to trigger. */
    RegNVICSoftwareTriggerInterrupt_t SoftwareTriggerInterrupt;

#ifdef CXX_SIMULATOR
    typedef uint32_t (*read_callback_t)(uint32_t, void*);
    read_callback_t mIndexReadCallback;
    void* mIndexReadCallbackArgs;

    typedef void (*write_callback_t)(uint32_t, uint32_t value, void*);
    write_callback_t mIndexWriteCallback;
    void* mIndexWriteCallbackArgs;

    uint32_t read(int index) { return mIndexReadCallback(index, mIndexReadCallbackArgs); }
    void write(int index, uint32_t value) { mIndexWriteCallback(index, value, mIndexWriteCallbackArgs); }
#endif /* CXX_SIMULATOR */
} NVIC_t;

/** @brief Nested Vectored Interrupt Controller */
extern volatile NVIC_t NVIC;



#ifdef CXX_SIMULATOR /* Compiling c++ code - uses register wrappers */
#undef volatile
#endif /* CXX_SIMULATOR */

#undef register_container
#undef BITFIELD_BEGIN
#undef BITFIELD_MEMBER
#undef BITFIELD_END

#endif /* !APE_NVIC_H */

/** @} */
