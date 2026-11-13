/*
 * Boot library and definitions.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#ifndef _BOOTLIB_H
#define _BOOTLIB_H 1

#include <sys/comdef.h>
#include <efilib.h>
#include <stdint.h>
#include <stdarg.h>
#include <wchar.h>

/*
 * Write a formatted string to the console.
 *
 * @fmt:    Format specifier
 * @<...>:  Variadic arguments
 */
void
cons_printf (
    __in const wchar_t *fmt,
    ...
    );

/*
 * Begin the actual boot process by starting the EFI
 * boot manager.
 */
void
bm_entry (
    void
    );

#endif  /* !_BOOTLIB_H */
