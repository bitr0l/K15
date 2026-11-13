/*
 * EFI console helpers.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <bootlib.h>
#include <stdint.h>

static wchar_t scratch_buffer[EFI_PAGE_SIZE];

void
cons_printf (
    __in const wchar_t *fmt,
    ...
    )
{
    va_list va;
    int buffer_used;

    /*
     * Handle format and arguments.
     */

    va_start(va, fmt);
    buffer_used = vswprintf_s(
        scratch_buffer,
        (sizeof(scratch_buffer) / sizeof(CHAR16)) - 1,
        fmt,
        va
    );
    va_end(va);

    /*
     * Print formatted buffer.
     */

     if (buffer_used >= 1) {
        gCons->OutputString(gCons, scratch_buffer);
     }
}
