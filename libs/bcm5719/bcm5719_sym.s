################################################################################
###
### @file       bcm5719_sym.s
###
### @project    bcm5719
###
### @brief      bcm5719_sym.s
###
################################################################################
###
################################################################################
###
### @copyright Copyright (c) 2020, Evan Lojewski
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

.global APE
.equ    APE, 0xc0010000
.size   APE, 0x330

.global APE_PERI
.equ    APE_PERI, 0xc0018000
.size   APE_PERI, 0x440

.global SHM
.equ    SHM, 0xc0014000
.size   SHM, 0x900

.global SHM_CHANNEL0
.equ    SHM_CHANNEL0, 0xc0014900
.size   SHM_CHANNEL0, 0xcc

.global SHM_CHANNEL1
.equ    SHM_CHANNEL1, 0xc0014a00
.size   SHM_CHANNEL1, 0xcc

.global SHM_CHANNEL2
.equ    SHM_CHANNEL2, 0xc0014b00
.size   SHM_CHANNEL2, 0xcc

.global SHM_CHANNEL3
.equ    SHM_CHANNEL3, 0xc0014c00
.size   SHM_CHANNEL3, 0xcc

.global DEVICE
.equ    DEVICE, 0xc0000000
.size   DEVICE, 0x7c08

.global NVM
.equ    NVM, 0xc0007000
.size   NVM, 0x3c

.global GEN
.equ    GEN, 0xb50
.size   GEN, 0x368

.global RXMBUF
.equ    RXMBUF, 0x10000
.size   RXMBUF, 0xc800

.global SDBCACHE
.equ    SDBCACHE, 0x20000
.size   SDBCACHE, 0xc800

.global TXMBUF
.equ    TXMBUF, 0x2c800
.size   TXMBUF, 0x7400

.global BOOTCODE
.equ    BOOTCODE, 0x8000000
.size   BOOTCODE, 0x7000

.global MII
.equ    MII, 0x0
.size   MII, 0x71a


