/*
 * EFI initialization.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <efilib.h>

EFI_HANDLE gImageHandle;
EFI_SYSTEM_TABLE *gST;
EFI_BOOT_SERVICES *gBS;
EFI_SIMPLE_TEXT_OUTPUT_PROTOCOL *gCons;

status_t
efi_firmware_init (
    __in EFI_HANDLE image_handle,
    __in EFI_SYSTEM_TABLE *systab
    )
{
    if (image_handle == NULL || systab == NULL) {
        return STATUS_INVALID_PARAM;
    }

    gImageHandle = image_handle;
    gST = systab;
    gBS = systab->BootServices;
    gCons = systab->ConOut;
    return STATUS_SUCCESS;
}
