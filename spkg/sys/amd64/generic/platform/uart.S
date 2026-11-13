/*
 * AMD64 UART driver.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

    .text
    .globl px_serial_init
px_serial_init:
    /*
     * This is mostly used on emulators as most PCs nowadays don't include
     * a serial port...
     */
    retq

    .globl px_serial_write
px_serial_write:
    pushfq
    cld
    mov %rdx, %rcx
    mov $0x3F8, %dx
    rep outsb
    popfq
    retq
