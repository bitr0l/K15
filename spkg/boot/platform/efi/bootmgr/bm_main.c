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
   EFI_FILE_HANDLE boot_volume;
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
    * Obtain the root volume that we are booted on.
    */

   status = get_root_volume(&boot_volume);
   if (!OS_SUCCESS(status)) {
      cons_printf(L"fatal: could not obtain boot volume\r\n");
      return;
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
