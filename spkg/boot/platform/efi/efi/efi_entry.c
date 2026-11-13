/*
 * EFI platform entry point.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <efi/efi.h>

/*
 * The firmware passes control to us at this entry point.
 *
 * @ImageHandle: The handle to the loaded image passed to us
 * @SystemTable: EFI system table pointer passed to us
 *
 * Return value:
 *      Doesn't return on success.
 *      Any status code on failure or abort.
 */
EFIAPI
EFI_STATUS
efi_main (
    IN EFI_HANDLE ImageHandle,
    IN EFI_SYSTEM_TABLE *SystemTable
    )
{
    return EFI_SUCCESS;
}
