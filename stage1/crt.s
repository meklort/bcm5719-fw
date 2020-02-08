

.section .init
.global __start
.align 4
__start:
    la      $sp, _estack
    j       main
.size __start, . - __start
