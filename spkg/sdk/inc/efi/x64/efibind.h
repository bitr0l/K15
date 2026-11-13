/*
 * AMD64 processor bindings.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#ifndef _EFIBIND_H
#define _EFIBIND_H

//
// EFI requires structure alignment.
//

#pragma pack()

//
// EFI service calling convention.
//

#ifndef EFIAPI
    #define EFIAPI __cdecl
#endif

//
// Fixed-width integer types.
//

typedef __int8           INT8;
typedef __int16          INT16;
typedef __int32          INT32;
typedef __int64          INT64;

typedef unsigned __int8  UINT8;
typedef unsigned __int16 UINT16;
typedef unsigned __int32 UINT32;
typedef unsigned __int64 UINT64;

//
// Native-width integer types.
//

typedef INT64  INTN;
typedef UINT64 UINTN;

#define MIN_INTN  (((INTN) -9223372036854775807L) - 1)
#define MAX_INTN  ((INTN)  0x7fffffffffffffff)
#define MAX_UINTN ((UINTN) 0xffffffffffffffff)

//
// EFI_STATUS error masks.
//

#define EFI_ERROR_MASK     0x8000000000000000
#define EFI_ERROR_MASK_OEM 0xc000000000000000

#endif // _EFIBIND_H
