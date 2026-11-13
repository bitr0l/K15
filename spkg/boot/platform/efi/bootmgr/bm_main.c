/*
 * Boot library and definitions.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <bootlib.h>

void
bm_entry (
    void
    )
{
    status_t status;

    /*
     * Disable the watchdog timer so that it cannot fire, most platforms
     * have it set to 5 minutes which will most certainly not pass before
     * we exit boot services. However, it is good practice to disable it
     * anyways as we'll find no use in it.
     */

     status = set_watchdog_timer(
        0,
        0,
        0,
        NULL
     );

     if (!OS_SUCCESS(status)) {
        cons_printf(L"error: could not disable watchdog timer, continuing...\r\n");
     }
}
