################################################################################
###
### @file       APE_sym.s
###
### @project    ape
###
### @brief      APE_sym.s
###
### @classification  Confidential
###
################################################################################
###
################################################################################
###
### @copyright Copyright (c) 2018, Evan Lojewski
### @cond
###
### All rights reserved.
###
### Redistribution and use in source and binary forms, with or without
### modification, are permitted provided that the following conditions are met:
### 1. Redistributions of source code must retain the above copyright notice,
### this list of conditions and the following disclaimer.
### 2. Redistributions in binary form must reproduce the above copyright notice,
### this list of conditions and the following disclaimer in the documentation
### and/or other materials provided with the distribution.
### 3. Neither the name of the <organization> nor the
### names of its contributors may be used to endorse or promote products
### derived from this software without specific prior written permission.
###
################################################################################
###
### THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
### AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
### IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
### ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
### LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
### CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
### SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
### INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
### CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
### ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
### POSSIBILITY OF SUCH DAMAGE.
### @endcond
################################################################################

.global DEVICE
.equ    DEVICE, 0xa0040000
.size   DEVICE, 0x7c08

.global DEVICE1
.equ    DEVICE1, 0xa0050000
.size   DEVICE1, 0x7c08

.global DEVICE2
.equ    DEVICE2, 0xa0060000
.size   DEVICE2, 0x7c08

.global DEVICE3
.equ    DEVICE3, 0xa0070000
.size   DEVICE3, 0x7c08

.global NVIC
.equ    NVIC, 0xe000e000
.size   NVIC, 0xf04

.global NVM
.equ    NVM, 0x60240000
.size   NVM, 0x3c

.global SHM
.equ    SHM, 0x60220000
.size   SHM, 0x9b4

.global SHM1
.equ    SHM1, 0x60221000
.size   SHM1, 0x0

.global SHM2
.equ    SHM2, 0x60222000
.size   SHM2, 0x0

.global SHM3
.equ    SHM3, 0x60223000
.size   SHM3, 0x0


