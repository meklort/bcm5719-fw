/////////////////////////////////////////////////////////////////////////////////
///
/// @file       ape.h
///
/// @project
///
/// @brief      Functions provided by ape.
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
/// 3. Neither the name of the copyright holder nor the
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

#ifndef APE_MAIN_H
#define APE_MAIN_H

#include <types.h>

////////////////////////////////////////////////////////////////////////////////
// RMU
////////////////////////////////////////////////////////////////////////////////
void RMU_init(void);

void RMU_resetBadPacket(void);

////////////////////////////////////////////////////////////////////////////////
// ISR
////////////////////////////////////////////////////////////////////////////////
typedef void (*vector_t)(void) __attribute__((interrupt));

/**
 *  Vector table format
 */
typedef struct
{
    uint32_t *sp;         /**< The stack pointer */
    vector_t *__start;    /**< The reset vector */
    vector_t vectors[46]; /**< Exception and interrupt vectors */
} vector_table_t;

/**
 *  Default vector table
 */
extern vector_table_t gVectors;

void __attribute__((interrupt)) IRQ_NMI(void);
void __attribute__((interrupt)) IRQ_HardFault(void);
void __attribute__((interrupt)) IRQ_MemoryManagmentFault(void);
void __attribute__((interrupt)) IRQ_BusFault(void);
void __attribute__((interrupt)) IRQ_UsageFault(void);
void __attribute__((interrupt)) IRQ_SVCall(void);
void __attribute__((interrupt)) IRQ_Debug(void);
void __attribute__((interrupt)) IRQ_PendSV(void);
void __attribute__((interrupt)) IRQ_Systick(void);

void __attribute__((interrupt)) IRQ_RxPacketEven(void);
void __attribute__((interrupt)) IRQ_RxPacketOdd(void);
void __attribute__((interrupt)) IRQ_RMU(void);
void __attribute__((interrupt)) IRQ_VoltageSource(void);
void __attribute__((interrupt)) IRQ_PowerStatusChanged(void);

#endif /* APE_MAIN_H */
