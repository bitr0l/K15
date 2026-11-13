/*
 * Processor entry point and low level commons.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

    .section .ipl
    .globl _start
_start:
1:  cli
    hlt
    jmp 1b
