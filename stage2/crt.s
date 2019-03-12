

.section .init
.global __start
.align 4
__start:
    j       _main
    .word   gVersion
.size __start, . - __start


_main:
    la      $sp, _estack
    move    $fp, $sp
    j       main
.size __main, . - __main


.section .data
.global gVersion
gVersion:
.string "bcm5719 stage2."
.size gVersion, . - gVersion
