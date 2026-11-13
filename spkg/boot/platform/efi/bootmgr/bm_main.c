/*
 * Boot manager entry.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <sys/cdef.h>
#include <bootlib.h>
#include <efilib.h>

void
bm_entry (
    void
    )
{
   EFI_FILE_HANDLE boot_volume;
   EFI_STATUS efi_status;
   EFI_PHYSICAL_ADDRESS kernel_image;
   uint64_t kimage_size;
   status_t status;
   struct memory_map memory_map;
   struct file_handle kernel;

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
    * Open the kernel binary.
    */

   status = open_file_path(
      boot_volume,
      KERNEL_PATH,
      &kernel
   );

   if (!OS_SUCCESS(status)) {
      cons_printf(L"fatal: could not locate %s\r\n", KERNEL_PATH);
      return;
   }

   /*
    * Allocate memory for the kernel image and fill it.
    */

   kimage_size = ALIGN_UP(kernel.size_bytes, EFI_PAGE_SIZE);
   efi_status = gBS->AllocatePages(
      AllocateAnyPages,
      EfiLoaderData,
      kimage_size,
      &kernel_image
   );

   if (efi_status != EFI_SUCCESS) {
      cons_printf(L"fatal: failed to allocate kernel image %x\r\n", kernel.size_bytes);
      return;
   }

   status = read_file(
      &kernel,
      &kimage_size,
      (void *)kernel_image
   );

   if (!OS_SUCCESS(status)) {
      cons_printf(L"fatal: failed to read kernel binary\r\n");
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

   /*
    * Now, we leave boot services...
    */

   efi_status = gBS->ExitBootServices(
      gImageHandle,
      memory_map.key
   );

   if (efi_status != EFI_SUCCESS) {
      cons_printf(L"fatal: failed to exit boot services\r\n");
      return;
   }

   ((void(*)(void))kernel_image)();
}
