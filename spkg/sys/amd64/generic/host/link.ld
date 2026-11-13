/*
 * Kernel linker script.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

OUTPUT_FORMAT(binary)

SECTIONS
{
    . = 0x00;

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
        *(COMMON)
        *(.bss .bss.*)
    }
}
