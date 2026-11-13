/*
 * OS status codes.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#ifndef _SYS_STATUS_H
#define _SYS_STATUS_H 1

#include <stdint.h>

#define STATUS_SUCCESS          0x00000000UL   /* Operation successful */
#define STATUS_INVALID_PARAM    0x00000001UL   /* Invalid parameter */
#define STATUS_OUT_OF_RESOURCES 0x00000002UL   /* System out of resources */
#define STATUS_NOT_SUPPORTED    0x00000003UL   /* Operation not supported */
#define STATUS_NOT_EXEC         0x00000004UL   /* Not executable */

/*
 * All routines returning status codes must be of the
 * following type...
 */
typedef uint32_t status_t;

/*
 * Macro used to quickly check if a status code is marked as
 * successful.
 */
#define OS_SUCCESS(STATUS)  \
    ((STATUS) == STATUS_SUCCESS)

#endif /* _SYS_STATUS_H */
