/*
 * EFI device path protocol definitions.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#ifndef _EFIDEVP_H
#define _EFIDEVP_H

#define EFI_DEVICE_PATH_PROTOCOL_GUID { 0x09576e91, 0x6d3f, 0x11d2, { 0x8e, 0x39, 0x00, 0xa0, 0xc9, 0x69, 0x72, 0x3b } }

//
// Device path node.
//

typedef struct {
    UINT8 Type;
    UINT8 SubType;

    //
    // Usage determined by Type and SubType.
    //

    UINT8 Length[2];
} EFI_DEVICE_PATH, EFI_DEVICE_PATH_PROTOCOL;

//
// Device path types.
//

#define HARDWARE_DEVICE_PATH  0x01
#define ACPI_DEVICE_PATH      0x02
#define MESSAGING_DEVICE_PATH 0x03
#define MEDIA_DEVICE_PATH     0x04
#define BBS_DEVICE_PATH       0x05
#define END_DEVICE_PATH_TYPE  0x7f

#define EFI_DP_TYPE_MASK     0x7f
#define EFI_DP_TYPE_UNPACKED 0x80

//
// End device path subtypes.
//

#define END_INSTANCE_DEVICE_PATH_SUBTYPE 0x01
#define END_ENTIRE_DEVICE_PATH_SUBTYPE   0xff

//
// End device path length.
//

#define END_DEVICE_PATH_LENGTH (sizeof(EFI_DEVICE_PATH_PROTOCOL))

//
// Device path helpers.
//

FORCEINLINE
UINT8
DevicePathType (
    IN CONST VOID *Node
    )

/*++

Routine Description:

    Gets the type of a device path node.

Arguments:

    Node - The node to get the type of.

Return Value:

    The type of the node.

--*/

{
    return ((EFI_DEVICE_PATH *) (Node))->Type & EFI_DP_TYPE_MASK;
}

FORCEINLINE
UINT8
DevicePathSubType (
    IN CONST VOID *Node
    )

/*++

Routine Description:

    Gets the subtype of a device path node.

Arguments:

    Node - The node to get the subtype of.

Return Value:

    The subtype of the node.

--*/

{
    return ((EFI_DEVICE_PATH *) (Node))->SubType;
}

FORCEINLINE
UINTN
DevicePathNodeLength (
    IN CONST VOID *Node
    )

/*++

Routine Description:

    Gets the length of a device path node.

Arguments:

    Node - The node to get the length of.

Return Value:

    The length of the node.

--*/

{
    return *((UINT16 *) &((EFI_DEVICE_PATH *) (Node))->Length[0]);
}

FORCEINLINE
EFI_DEVICE_PATH *
NextDevicePathNode (
    IN CONST VOID *Node
    )

/*++

Routine Description:

    Finds the next node in a device path.

Arguments:

    Node - The current node to find the next node from.

Return Value:

    A pointer to the next node.

--*/

{
    return (EFI_DEVICE_PATH *) ((UINT8 *) (Node) + DevicePathNodeLength(Node));
}

FORCEINLINE
BOOLEAN
IsDevicePathEndType (
    IN CONST VOID *Node
    )

/*++

Routine Description:

    Checks if a device path node is an end node.

Arguments:

    Node - The node to check.

Return Value:

    TRUE if the node is an end node.

    FALSE if the node is not an end node.

--*/

{
    return (BOOLEAN) (DevicePathType(Node) == END_DEVICE_PATH_TYPE);
}

#endif // _EFIDEVP_H
