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
 * Memory region types.
 */
#define MEMORY_RESERVED  0x00000000UL       /* Reserved memory */
#define MEMORY_USABLE    0x00000001UL       /* Usable memory */
#define MEMORY_BAD       0x00000002UL       /* Unusable memory */

/* Memory region kind type */
typedef uint32_t memkind_t;

/*
 * Our own internal representation of a memory descriptor.
 *
 * @kind:       Memory region kind.
 * @pbase:      Physical base of memory region.
 * @length:     Length of region in bytes.
 */
struct memory_descrip {
    memkind_t kind;
    uintptr_t pbase;
    uint64_t length;
};

/*
 * Represents our own internal representation of a memory map.
 *
 * @map:                Our memory map.
 * @nr_entries:         Number of entries in our memory map.
 * @key:                EFI map key.
 * @descriptor_ver:     EFI descriptor version.
 */
struct memory_map {
    struct memory_descrip *map;
    uint64_t nr_entries;
    UINTN key;
    UINTN descriptor_ver;
};

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
