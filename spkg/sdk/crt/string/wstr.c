/*
 * Wide-character string services.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <wchar.h>

size_t
wcslen (
    const wchar_t *s
    )

{
    const wchar_t *ptr;

    ptr = s;
    while (*ptr != L'\0') {
        ptr++;
    }

    return ptr - s;
}

size_t
wcsnlen (
    const wchar_t *s,
    size_t        maxlen
    )

{
    const wchar_t *ptr;

    ptr = s;
    while (maxlen-- && *ptr != L'\0') {
        ptr++;
    }

    return ptr - s;
}

size_t
wcsnlen_s (
    const wchar_t *str,
    size_t        strsz
    )

{
    const wchar_t *ptr;
    size_t maxlen;

    if (str == NULL) {
        return 0;
    }

    ptr = str;
    maxlen = strsz;
    while (strsz--) {
        if (*ptr == '\0') {
            return ptr - str;
        }

        ptr++;
    }

    return maxlen;
}
