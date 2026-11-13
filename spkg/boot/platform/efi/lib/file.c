/*
 * File I/O interfaces.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <bootlib.h>
#include <efilib.h>

status_t
get_root_volume (
    __out EFI_FILE_HANDLE *volume
    )
{
    EFI_GUID lip_guid = EFI_LOADED_IMAGE_PROTOCOL_GUID;
    EFI_GUID fs_guid = EFI_SIMPLE_FILE_SYSTEM_PROTOCOL_GUID;
    EFI_LOADED_IMAGE *lip = NULL;
    EFI_SIMPLE_FILE_SYSTEM_PROTOCOL *io_volume;
    EFI_STATUS efi_status;

    if (volume == NULL) {
        return STATUS_INVALID_PARAM;
    }

    /*
     * Obtain the loaded image protocol interface.
     */

     efi_status = gBS->HandleProtocol(
        gImageHandle,
        &lip_guid,
        (void **)&lip
     );

     if (efi_status != EFI_SUCCESS) {
        return efi_to_os_status(efi_status);
     }

     /*
      * Obtain the root volume handle.
      */

    efi_status = gBS->HandleProtocol(
        lip->DeviceHandle,
        &fs_guid,
        (void *)&io_volume
    );

    if (efi_status != EFI_SUCCESS) {
        return efi_to_os_status(efi_status);
    }

    efi_status = io_volume->OpenVolume(
        io_volume,
        (EFI_FILE_PROTOCOL **)volume
    );

    return efi_to_os_status(efi_status);
}

status_t
open_file_path (
    __in EFI_FILE_HANDLE volume,
    __in wchar_t *file_path,
    __out struct file_handle *handle
    )
{
    EFI_STATUS efi_status;

    if (volume == NULL || file_path == NULL) {
        return STATUS_INVALID_PARAM;
    }

    if (handle == NULL) {
        return STATUS_INVALID_PARAM;
    }

    efi_status = volume->Open(
        volume,
        &handle->handle,
        file_path,
        EFI_FILE_MODE_READ,
        EFI_FILE_READ_ONLY | EFI_FILE_HIDDEN | EFI_FILE_SYSTEM
    );

    if (efi_status != EFI_SUCCESS) {
        return efi_to_os_status(efi_status);
    }

    /*
     * Obtain the file size.
     */

    efi_status = handle->handle->SetPosition(
        handle->handle,
        0xFFFFFFFFFFFFFFFF
    );

    if (efi_status != EFI_SUCCESS) {
        return efi_to_os_status(efi_status);
    }

    efi_status = handle->handle->GetPosition(
        handle->handle,
        &handle->size_bytes
    );

    if (efi_status != EFI_SUCCESS) {
        handle->handle->SetPosition(handle->handle, 0);
        return efi_to_os_status(efi_status);
    }

    efi_status = handle->handle->SetPosition(
        handle->handle,
        0
    );

    return efi_to_os_status(efi_status);
}
