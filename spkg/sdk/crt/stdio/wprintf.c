/*
 * Wide-character formatted printing services.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <stdarg.h>
#include <stdbool.h>
#include <stdint.h>
#include <wchar.h>

static
size_t
print_hex (
    wchar_t  *dest,
    size_t   destsz,
    uint32_t num
    )

{
    size_t n;
    uint8_t digit;

    n = 0;
    for (int8_t s = 28; n < destsz && s >= 0; s -= 4) {
        digit = (num >> s) & 0xf;
        if (digit >= 0xa) {
            *dest = L'a' + (digit - 0xa);
        } else {
            *dest = L'0' + digit;
        }

        dest++;
        n++;
    }

    return n;
}

static
size_t
print_dec (
    wchar_t  *dest,
    size_t   destsz,
    uint32_t num
    )

{
    size_t n;
    bool pad;
    uint8_t digit;

    n = 0;
    pad = true;
    for (uint32_t d = 1000000000; n < destsz && d > 0; d /= 10) {
        digit = num / d;
        num %= d;

        if (digit != 0) {
            pad = false;
        }

        if (!pad || d == 1) {
            *dest++ = L'0' + digit;
            n++;
        }
    }

    return n;
}

static
size_t
print_str (
    wchar_t       *dest,
    size_t        destsz,
    const wchar_t *str
    )

{
    size_t len;

    len = wcsnlen_s(str, destsz);
    if (len == 0 || len == destsz) {
        return 0;
    }

    wmemcpy(dest, str, len);

    return len;
}

int
vswprintf_s (
    wchar_t       *buf,
    size_t        bufsz,
    const wchar_t *format,
    va_list       args
    )

{
    wchar_t *dest;
    size_t total, len;

    if (buf == NULL || bufsz == 0 || format == NULL) {
        return -1;
    }

    //
    // Reserve space for terminator.
    //

    bufsz--;

    dest = buf;
    total = 0;
    while (total < bufsz && *format != L'\0') {
        if (*format != L'%') {
            *dest++ = *format++;
            total++;
            continue;
        }

        format++;
        switch (*format) {
        case L'x':
            len = print_hex(dest, bufsz - total, va_arg(args, uint32_t));
            dest += len;
            total += len;
            format++;
            break;
        case L'd':
            len = print_dec(dest, bufsz - total, va_arg(args, uint32_t));
            dest += len;
            total += len;
            format++;
            break;
        case L's':
            len = print_str(dest, bufsz - total, va_arg(args, const wchar_t *));
            dest += len;
            total += len;
            format++;
            break;
        case L'\0':
            break;
        case L'%':
        default:
            *dest++ = *format++;
            total++;
            break;
        }
    }

    buf[total] = L'\0';

    return (int) total;
}
