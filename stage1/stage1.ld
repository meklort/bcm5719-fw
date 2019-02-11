OUTPUT_FORMAT(binary)
ENTRY(__start)

SECTIONS
{
    .init 0x08003800 : ALIGN(4) SUBALIGN(4)
    {
        *(.init)
    }

    .text . : ALIGN(4) SUBALIGN(4)
    {
        *(.text)
    }


    .data . : ALIGN(4) SUBALIGN(4)
    {
        *(.data)
        *(.bss)
        *(.rodata)
        *(.rodata.*)
    }


    .stack . : ALIGN(4) SUBALIGN(4)
    {
        _fstack = .;
        _estack = 0x08007000;
    }


    /DISCARD/ :
    {
        *(.comment)
        *(.note.GNU-stack)
        *(.eh_frame)
        *(.got)
        *(.MIPS.abiflags)
        *(.reginfo)
        *(.mdebug.abi32)
        *(.pdr)
    }
}

