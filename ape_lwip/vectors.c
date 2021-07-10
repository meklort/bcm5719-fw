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

#include <APE_SHM.h>
#include <APE_SHM1.h>
#include <APE_SHM2.h>
#include <APE_SHM3.h>

void handleCommand(volatile SHM_t *shm);

extern uint32_t _estack; // Defined by linker
extern vector_t __start; // Defined by crt1.s

typedef struct __attribute__((packed)) ContextStateFrame {
  uint32_t r0; //lint !e754
  uint32_t r1; //lint !e754
  uint32_t r2; //lint !e754
  uint32_t r3; //lint !e754
  uint32_t r12; //lint -e754
  uint32_t lr; //lint !e754
  uint32_t return_address; //lint !e754
  uint32_t xpsr; //lint !e754
} sContextStateFrame;


//lint -e714
void __attribute__((interrupt)) IRQ_Default(void)
{
    __asm volatile(
      "tst lr, #4 \n"
      "ite eq \n"
      "mrseq r0, msp \n"
      "mrsne r0, psp \n"
      "b my_fault_handler_c \n"
                                                 );
}

// Disable optimizations for this function so "frame" argument
// does not get optimized away
void my_fault_handler_c(sContextStateFrame *frame) {
    (void)frame;

    uint32_t vector = NVIC.InterruptControlState.bits.VECTACTIVE;
    printf("HALTING due to ISR: %u\n\n", vector);
    printf("\tUsageFaultStatus:        0x%X\n", NVIC.FaultStatus.bits.UsageFaultStatus);
    printf("\tBusFaultStatus:          0x%X\n", NVIC.FaultStatus.bits.BusFaultStatus);
    printf("\tMemoryManageFaultStatus: 0x%X\n", NVIC.FaultStatus.bits.MemoryManageFaultStatus);
    printf("\tReturn Address:          0x%X\n", frame->return_address);
    printf("\tlr:                      0x%X\n", frame->lr);

    for (;;)
    {
        handleCommand(&SHM);
        handleCommand(&SHM1);
        handleCommand(&SHM2);
        handleCommand(&SHM3);
    }
}

// Alias all IRQ routines ot the default handler.
void __attribute__((interrupt)) IRQ_NMI(void) __attribute__((weak, alias("IRQ_Default")));                  //lint !e762
void __attribute__((interrupt)) IRQ_HardFault(void) __attribute__((weak, alias("IRQ_Default")));            //lint !e762
void __attribute__((interrupt)) IRQ_MemoryManagmentFault(void) __attribute__((weak, alias("IRQ_Default"))); //lint !e762
void __attribute__((interrupt)) IRQ_BusFault(void) __attribute__((weak, alias("IRQ_Default")));             //lint !e762
void __attribute__((interrupt)) IRQ_UsageFault(void) __attribute__((weak, alias("IRQ_Default")));           //lint !e762
void __attribute__((interrupt)) IRQ_SVCall(void) __attribute__((weak, alias("IRQ_Default")));               //lint !e762
void __attribute__((interrupt)) IRQ_Debug(void) __attribute__((weak, alias("IRQ_Default")));                //lint !e762
void __attribute__((interrupt)) IRQ_PendSV(void) __attribute__((weak, alias("IRQ_Default")));               //lint !e762
void __attribute__((interrupt)) IRQ_Systick(void) __attribute__((weak, alias("IRQ_Default")));              //lint !e762

void __attribute__((interrupt)) IRQ_RxPacketEven(void) __attribute__((weak, alias("IRQ_Default")));       //lint !e762
void __attribute__((interrupt)) IRQ_RxPacketOdd(void) __attribute__((weak, alias("IRQ_Default")));        //lint !e762
void __attribute__((interrupt)) IRQ_RMU(void) __attribute__((weak, alias("IRQ_Default")));                //lint !e762
void __attribute__((interrupt)) IRQ_VoltageSource(void) __attribute__((weak, alias("IRQ_Default")));      //lint !e762
void __attribute__((interrupt)) IRQ_PowerStatusChanged(void) __attribute__((weak, alias("IRQ_Default"))); //lint !e762

//lint -esym(714, gVectors) // Referenced by linker script
vector_table_t gVectors __attribute__((section(".init"))) = {
    .sp = &_estack,
    .__start = &__start,
    .vectors = {
        [0x0] = IRQ_NMI,
        [0x1] = IRQ_HardFault,
        [0x2] = IRQ_MemoryManagmentFault,
        [0x3] = IRQ_BusFault,
        [0x4] = IRQ_UsageFault,
        [0x5] = IRQ_Default, /* Reserved */
        [0x6] = IRQ_Default, /* Reserved */
        [0x7] = IRQ_Default, /* Reserved */
        [0x8] = IRQ_Default, /* Reserved */
        [0x9] = IRQ_SVCall,
        [0xA] = IRQ_Debug,
        [0xB] = IRQ_Default, /* Reserved */
        [0xC] = IRQ_PendSV,
        [0xD] = IRQ_Systick,
        [0xE] = IRQ_Default, /* Reserved */
        [0xF] = IRQ_Default, /* Reserved */

        /* External Interrupts */
        [0x10] = IRQ_Default,               /* Handle Event */
        [0x11] = IRQ_Default,               /* -- */
        [0x12] = IRQ_Default,               /* -- */
        [0x13] = IRQ_Default,               /* -- */
        [0x14] = IRQ_Default,               /* -- */
        [0x15] = IRQ_Default,               /* -- */
        [0x16] = IRQ_Default,               /* Host to BMC */
        [0x17] = IRQ_Default,               /* -- */
        [0x18] = IRQ_Default,               /* TX Error */
        [0x19] = IRQ_RxPacketEven,          /* RX Packet - Even ports */
        [0x1A] = IRQ_Default,               /* -- */
        [0x1B] = IRQ_Default,               /* -- */
        [0x1C] = IRQ_Default,               /* SMBUS 0 */
        [0x1D] = IRQ_Default,               /* -- */
        [0x1E] = IRQ_Default,               /* SMBUS 1 */
        [0x1F] = IRQ_RMU,                   /* RMU Egress */
        [0x20] = IRQ_Default,               /* -- */
        [0x21] = IRQ_Default,               /* -- */
        [0x22] = IRQ_PowerStatusChanged,    /* Gen Status Changed */
        [0x23] = IRQ_Default,               /* seems to be always pending, but always masked. no handler (i.e., uses exception handler) */
        [0x24] = IRQ_Default,               /* -- */
        [0x25] = IRQ_Default,               /* -- */
        [0x26] = IRQ_VoltageSource,         /* Voltage Source Changed */
        [0x27] = IRQ_Default,               /* Link Status Changed (Even Ports) */
        [0x28] = IRQ_Default,               /* Link Status Changed (Odd Ports) */
        [0x29] = IRQ_RxPacketOdd,           /* RX Packet (Odd ports) */
        [0x2A] = IRQ_Default,               /* -- */
        [0x2B] = IRQ_Default,               /* -- */
        [0x2C] = IRQ_Default,               /* -- */
        [0x2D] = IRQ_Default,               /* -- */
    },
};
