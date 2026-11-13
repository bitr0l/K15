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
 * Convert an EFI status type to our native status types.
 *
 * @status: EFI status to translate
 */
status_t
efi_to_os_status (
    __in EFI_STATUS status
    );

#endif  /* !_EFILIB_H */
