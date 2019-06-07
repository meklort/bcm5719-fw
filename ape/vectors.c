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

#include <types.h>

// Function pointer for vectors
typedef void (*vector_t)(void) __attribute__((interrupt));

// Vector table
typedef struct
{
    uint32_t *sp;
    vector_t *__start;
    vector_t *vectors[46];
} vector_table_t;

extern uint32_t _estack;

extern vector_t __start;

#pragma weak Vector_NMI
#pragma weak Vector_HardFault
#pragma weak Vector_MemoryManagmentFault
#pragma weak Vector_BusFault
#pragma weak Vector_UsageFault
#pragma weak Vector_SVCall
#pragma weak Vector_Debug
#pragma weak Vector_PendSV
#pragma weak Vector_Systick

extern vector_t Vector_NMI;
extern vector_t Vector_HardFault;
extern vector_t Vector_MemoryManagmentFault;
extern vector_t Vector_BusFault;
extern vector_t Vector_UsageFault;
extern vector_t Vector_SVCall;
extern vector_t Vector_Debug;
extern vector_t Vector_PendSV;
extern vector_t Vector_Systick;

vector_table_t gVectors __attribute__((section(".init"))) = {
    .sp = &_estack,
    .__start = &__start,
    .vectors = {
        [0] = &Vector_NMI,
        [1] = &Vector_HardFault,
        [2] = &Vector_MemoryManagmentFault,
        [3] = &Vector_BusFault,
        [4] = &Vector_UsageFault,

        [9] = &Vector_SVCall,
        [10] = &Vector_Debug,

        [12] = &Vector_PendSV,
        [13] = &Vector_Systick,
    },
};
