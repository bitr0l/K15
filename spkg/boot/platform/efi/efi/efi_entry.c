/*
 * EFI platform entry point.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <sys/comdef.h>
#include <efi/efi.h>
#include <efilib.h>

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
    __in EFI_HANDLE image_handle,
    __in EFI_SYSTEM_TABLE *systab
    )
{
    status_t status;

    /*
     * Initialize the EFI global state.
     */

    status = efi_firmware_init(image_handle, systab);
    if (!OS_SUCCESS(status)) {
        return EFI_INVALID_PARAMETER;
    }

    return EFI_ABORTED;
}
