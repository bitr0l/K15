/*
 * EFI library and definitions.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#ifndef _EFILIB_H
#define _EFILIB_H 1

#include <sys/comdef.h>
#include <sys/status.h>
#include <efi/efi.h>

/*
 * Global EFI state.
 */
extern EFI_HANDLE gImageHandle;
extern EFI_SYSTEM_TABLE *gST;
extern EFI_BOOT_SERVICES *gBS;

/*
 * Convert an EFI status type to our native status types.
 *
 * @status: EFI status to translate
 */
status_t
efi_to_os_status (
    __in EFI_STATUS status
    );

/*
 * Initialize firmware global state.
 *
 * @image_handle: Image handle passed to us by firmware
 * @systab:       System table passed to us by firmware
 *
 * Return value:
 *     Returns STATUS_SUCCESS on success.
 *     Returns error code on failure.
 */
status_t
efi_firmware_init (
    __in EFI_HANDLE image_handle,
    __in EFI_SYSTEM_TABLE *systab
    );

#endif  /* !_EFILIB_H */
