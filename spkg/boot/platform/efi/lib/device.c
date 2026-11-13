/*
 * Boot device interface.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <bootlib.h>
#include <efilib.h>

status_t
set_watchdog_timer (
    __in uint64_t timeout,
    __in uint64_t code,
    __in uint64_t data_size,
    __in wchar_t *wd_data
    )
{
    EFI_STATUS efi_status;

    efi_status = gBS->SetWatchdogTimer(
        timeout,
        code,
        data_size,
        wd_data
    );

    return efi_to_os_status(efi_status);
}
