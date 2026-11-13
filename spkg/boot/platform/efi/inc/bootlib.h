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
 * Configure the watchdog timer, wraps boot service's
 * SetWatchdogTimer().
 *
 * @timeout:    Number of seconds to set watchdog timer to
 * @code:       Numeric code to log upon event
 * @data_size:  Size of optional watchdog data
 * @wd_data:    Watchdog data
 *
 * Return value:
 *      Returns STATUS_SUCCESS if successful.
 *      Returns error code on failure.
 */
status_t
set_watchdog_timer (
    __in uint64_t timeout,
    __in uint64_t code,
    __in uint64_t data_size,
    __in wchar_t *wd_data
    );

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
