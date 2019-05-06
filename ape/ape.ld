OUTPUT_FORMAT(binary)
ENTRY(__start)

SECTIONS
{
    .text 0x00100000 : ALIGN(4) SUBALIGN(4)
    {
        KEEP(*(.init))
        *(.text)
    }


    .data . : ALIGN(4) SUBALIGN(4)
    {
        *(.data*)
        *(.rodata*)
    }

    _fbss = .;
    .bss . : ALIGN(4) SUBALIGN(4)
    {
        *(.bss*)
    }
    _ebss = .;


    .stack . (NOLOAD) : ALIGN(4) SUBALIGN(4)
    {
        _fstack = .;
        _estack = 0x00118000;
    }


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

