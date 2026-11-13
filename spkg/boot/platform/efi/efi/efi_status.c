/*
 * EFI status code translation.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <efilib.h>

status_t
efi_to_os_status (
    __in EFI_STATUS status
    )
{
    switch (status) {
    case EFI_SUCCESS:
        return STATUS_SUCCESS;
    case EFI_INVALID_PARAMETER:
        return STATUS_INVALID_PARAM;
    case EFI_OUT_OF_RESOURCES:
        return STATUS_OUT_OF_RESOURCES;
    case EFI_UNSUPPORTED:
        return STATUS_NOT_SUPPORTED;
    default:
        return STATUS_FAILURE;
    }
}
