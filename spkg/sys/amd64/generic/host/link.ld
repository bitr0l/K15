/*
 * Kernel linker script.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

SECTIONS
{
    . = 1M;

    .text : ALIGN(4K) {
        *(.ipl)
        *(.text .text.*)
    }

    .data : ALIGN(4K) {
        *(.data .data.*)
    }

    .rodata : ALIGN(4K) {
        *(.rodata .rodata.*)
    }

    .bss : ALIGN(4K) {
        __bss_start = .;
        *(COMMON)
        *(.bss .bss.*)
        __bss_end = .;
    }
}
