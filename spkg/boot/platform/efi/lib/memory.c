/*
 * Platform memory interfaces.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <sys/cdef.h>
#include <bootlib.h>
#include <efilib.h>

/*
 * Converts EFI memory type to our internal representation.
 *
 * @type:  Type to convert
 *
 * Return value:
 *      Any MEMORY_* define
 */
static uint32_t
conv_efi_memkind (
    IN EFI_MEMORY_TYPE type
    )
{
    switch (type) {
    case EfiConventionalMemory:
        return MEMORY_USABLE;
    case EfiUnusableMemory:
        return MEMORY_BAD;
    default:
        return MEMORY_RESERVED;
    }
}

status_t
get_memory_map (
    __out struct memory_map *map
    )
{
    struct memory_descrip *descrip;
    EFI_MEMORY_DESCRIPTOR *efi_desc_list;
    EFI_MEMORY_DESCRIPTOR *efi_desc_cur;
    EFI_STATUS efi_status;
    UINTN efi_map_size;
    UINTN efi_desc_size;
    UINTN boot_map_size;
    UINTN index;

    if (map == NULL) {
        return STATUS_INVALID_PARAM;
    }

    /*
     * Zero initialize the map.
     */

    map->map = NULL;
    map->nr_entries = 0;
    map->key = 0;
    map->descriptor_ver = 0;

    /*
     * Obtain the size of the memory map.
     */

    efi_map_size = 0;
    efi_desc_list = NULL;

    efi_status = gBS->GetMemoryMap(
        &efi_map_size,
        efi_desc_list,
        &map->key,
        &efi_desc_size,
        &map->descriptor_ver
    );

    if (efi_status != EFI_BUFFER_TOO_SMALL) {
        return STATUS_FAILURE;
    }

    /*
     * Allocate memory for us to store the firmware memory map
     * within...
     */

    efi_status = gBS->AllocatePool(
        EfiLoaderData,
        efi_map_size,
        (void **)&efi_desc_list
    );

    if (efi_status != EFI_SUCCESS) {
        return STATUS_OUT_OF_RESOURCES;
    }

    /*
     * Now request again to actually obtain the firmware memory map. Note
     * that we have to do it twice due to us allocating memory beforehand
     * which may alter the map in ways that a single call would fail.
     */

     for (index = 0; index < 2; ++index) {
        efi_status = gBS->GetMemoryMap(
            &efi_map_size,
            efi_desc_list,
            &map->key,
            &efi_desc_size,
            &map->descriptor_ver
        );

        if (efi_status == EFI_SUCCESS) {
            break;
        }
     }

     if (efi_status != STATUS_SUCCESS) {
        gBS->FreePool(efi_desc_list);
        return efi_to_os_status(efi_status);
     }

    /*
     * Allocate memory for our own internal representation.
     */

    map->nr_entries = efi_map_size / efi_desc_size;
    boot_map_size = map->nr_entries * sizeof(struct memory_descrip);

    efi_status = gBS->AllocatePool(
        EfiLoaderData,
        boot_map_size,
        (void **)&map->map
    );

    if (efi_status != EFI_SUCCESS) {
        gBS->FreePool(efi_desc_list);
        return efi_to_os_status(efi_status);
    }

    /*
     * Populate our memory map.
     */

    efi_desc_cur = efi_desc_list;
    for (index = 0; index < map->nr_entries; ++index) {
        descrip = &map->map[index];
        descrip->kind = conv_efi_memkind(efi_desc_cur->Type);
        descrip->pbase = efi_desc_cur->PhysicalStart;
        descrip->length = efi_desc_cur->NumberOfPages * EFI_PAGE_SIZE;
        efi_desc_cur = PTR_OFFSET(efi_desc_cur, efi_desc_size);
    }

    gBS->FreePool(efi_desc_list);
    return STATUS_SUCCESS;
}
