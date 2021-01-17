////////////////////////////////////////////////////////////////////////////////
///
/// @file       vectors.c
///
/// @project
///
/// @brief      APE vector table
///
////////////////////////////////////////////////////////////////////////////////
///
////////////////////////////////////////////////////////////////////////////////
///
/// @copyright Copyright (c) 2019, Evan Lojewski
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

#include <APE_NVIC.h>
#include <ape_main.h>
#include <printf.h>

extern uint32_t _estack; // Defined by linker
extern vector_t __start; // Defined by crt1.s

void __attribute__((interrupt)) Vector_Default(void)
{
    uint32_t vector = NVIC.InterruptControlState.bits.VECTACTIVE;
    printf("ISR: %d\n", vector);
}

void __attribute__((interrupt)) Vector_NMI(void) __attribute__((weak, alias("Vector_Default")));
void __attribute__((interrupt)) Vector_HardFault(void) __attribute__((weak, alias("Vector_Default")));
void __attribute__((interrupt)) Vector_MemoryManagmentFault(void) __attribute__((weak, alias("Vector_Default")));
void __attribute__((interrupt)) Vector_BusFault(void) __attribute__((weak, alias("Vector_Default")));
void __attribute__((interrupt)) Vector_UsageFault(void) __attribute__((weak, alias("Vector_Default")));
void __attribute__((interrupt)) Vector_SVCall(void) __attribute__((weak, alias("Vector_Default")));
void __attribute__((interrupt)) Vector_Debug(void) __attribute__((weak, alias("Vector_Default")));
void __attribute__((interrupt)) Vector_PendSV(void) __attribute__((weak, alias("Vector_Default")));
void __attribute__((interrupt)) Vector_Systick(void) __attribute__((weak, alias("Vector_Default")));

//lint -esym(714, gVectors) // Referenced by linker script
vector_table_t gVectors __attribute__((section(".init"))) = {
    .sp = &_estack,
    .__start = &__start,
    .vectors = {
        [0x0] = Vector_NMI,
        [0x1] = Vector_HardFault,
        [0x2] = Vector_MemoryManagmentFault,
        [0x3] = Vector_BusFault,
        [0x4] = Vector_UsageFault,
        [0x5] = Vector_Default, /* Reserved */
        [0x6] = Vector_Default, /* Reserved */
        [0x7] = Vector_Default, /* Reserved */
        [0x8] = Vector_Default, /* Reserved */
        [0x9] = Vector_SVCall,
        [0xA] = Vector_Debug,
        [0xB] = Vector_Default, /* Reserved */
        [0xC] = Vector_PendSV,
        [0xD] = Vector_Systick,
        [0xE] = Vector_Default, /* Reserved */
        [0xF] = Vector_Default, /* Reserved */

        /* External Interrupts */
        [0x10] = Vector_Default,    /* Handle Event */
        [0x11] = Vector_Default,    /* -- */
        [0x12] = Vector_Default,    /* -- */
        [0x13] = Vector_Default,    /* -- */
        [0x14] = Vector_Default,    /* -- */
        [0x15] = Vector_Default,    /* -- */
        [0x16] = Vector_Default,    /* Host to BMC */
        [0x17] = Vector_Default,    /* -- */
        [0x18] = Vector_Default,    /* TX Error */
        [0x19] = Vector_Default,    /* RX Packet - Even ports */
        [0x1A] = Vector_Default,    /* -- */
        [0x1B] = Vector_Default,    /* -- */
        [0x1C] = Vector_Default,    /* SMBUS 0 */
        [0x1D] = Vector_Default,    /* -- */
        [0x1E] = Vector_Default,    /* SMBUS 1 */
        [0x1F] = Vector_Default,    /* RMU Egress */
        [0x20] = Vector_Default,    /* -- */
        [0x21] = Vector_Default,    /* -- */
        [0x22] = Vector_Default,    /* Gen Status Changed */
        [0x23] = Vector_Default,    /* seems to be always pending, but always masked. no handler (i.e., uses exception handler) */
        [0x24] = Vector_Default,    /* -- */
        [0x25] = Vector_Default,    /* -- */
        [0x26] = Vector_Default,    /* Voltage Source Changed */
        [0x27] = Vector_Default,    /* Link Status Changed (Even Ports) */
        [0x28] = Vector_Default,    /* Link Status Changed (Odd Ports) */
        [0x29] = Vector_Default,    /* RX Packet (Odd ports) */
        [0x2A] = Vector_Default,    /* -- */
        [0x2B] = Vector_Default,    /* -- */
        [0x2C] = Vector_Default,    /* -- */
        [0x2D] = Vector_Default,    /* -- */
    },
};
