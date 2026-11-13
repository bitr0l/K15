/*
 * String services.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <string.h>

size_t
strlen (
    const char *s
    )

{
    const char *ptr;

    ptr = s;
    while (*ptr != '\0') {
        ptr++;
    }

    return ptr - s;
}

size_t
strnlen (
    const char *s,
    size_t     maxlen
    )

{
    const char *ptr;

    ptr = s;
    while (maxlen-- && *ptr != '\0') {
        ptr++;
    }

    return ptr - s;
}
