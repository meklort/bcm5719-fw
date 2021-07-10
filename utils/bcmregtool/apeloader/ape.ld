################################################################################
###
### @file       ape.ld
###
### @project    bcm5719
###
### @brief      APE linker script
###
################################################################################
###
################################################################################
###
### @copyright Copyright (c) 2018-2020, Evan Lojewski
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
### 3. Neither the name of the copyright holder nor the
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

ENTRY(__start)

MEMORY
{
    SCRATCH (rwx) : ORIGIN = 0x00100000, LENGTH = 3K
    STACK   (rw)  : ORIGIN = 0x00116000, LENGTH = 8K
}

SECTIONS
{
    .text : ALIGN(4) SUBALIGN(4)
    {
        KEEP(*(.init*))
        *(.text*)
    } > SCRATCH


    .data : ALIGN(4) SUBALIGN(4)
    {
        *(.data*)
        *(.rodata*)
    } > SCRATCH

    _fbss = .;
    .bss : ALIGN(4) SUBALIGN(4)
    {
        *(.bss*)
    } > SCRATCH
    _ebss = .;


    .stack (NOLOAD) : ALIGN(4) SUBALIGN(4)
    {
        _fstack = .;
        _estack = 0x00118000;
    } > STACK


    /DISCARD/ :
    {
        *(.comment)
        *(.note.GNU-stack)
        *(.eh_frame)
        *(.got)
        *(.ARM.exidx*)
        *(.reginfo)
        *(.mdebug.abi32)
        *(.pdr)
    }
}

