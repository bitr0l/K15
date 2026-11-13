/*
 * Boot manager entry.
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
    struct memory_map memory_map;

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

     /*
      * Obtain the platform memory map.
      *
      * XXX: This must remain the last thing done.
      */

     status = get_memory_map(&memory_map);
     if (!OS_SUCCESS(status)) {
         cons_printf(L"fatal: unable to obtain memory map\r\n");
         return;
     }
}
