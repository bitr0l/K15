/*
 * Processor entry point and low level commons.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

    .section .ipl, "ax", @progbits
    .globl _start
    .extern __bss_start
    .extern __bss_end
_start:
    /* Setup our own stack */
    xor %rbp, %rbp
    lea stack_top(%rip), %rsp

    /* Compute length of .bss into RCX */
    lea __bss_start(%rip), %rdi
    lea __bss_end(%rip), %rsi
    sub %rdi, %rsi
    mov %rsi, %rcx

    /* Zero .bss */
    xor %al, %al
    lea __bss_start(%rip), %rdi
    cld
    rep stosb

1:  cli
    hlt
    jmp 1b

    .align 16
    .section .bss
stack_base:
    .skip 4096
stack_top:
