/*
 * Processor entry point and low level commons.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

    .section .ipl
    .globl _start
_start:
    /* Setup our own stack */
    xor %rbp, %rbp
    lea stack_top(%rip), %rsp

1:  cli
    hlt
    jmp 1b

    .align 16
    .section .bss
stack_base:
    .skip 4096
stack_top:
