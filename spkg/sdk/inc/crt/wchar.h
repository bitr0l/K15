/*
 * C runtime widechar support.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#ifndef __WCHAR_H
#define __WCHAR_H

#ifdef __cplusplus
extern "C" {
#endif

#if !defined(__STDC_WANT_LIB_EXT1__) && defined(_WIN32)
    #define __STDC_WANT_LIB_EXT1__ 1
#endif

#define __need_size_t
#define __need_wchar_t
#define __need_wint_t
#define __need_NULL
#if defined(__STDC_WANT_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__ >= 1
    #define __need_rsize_t
#endif
#include <stddef.h>

#define __need_va_list
#include <stdarg.h>

//
// Memory services.
//

wchar_t *wmemset(wchar_t *wcs, wchar_t wc, size_t n);
wchar_t *wmemcpy(wchar_t *dest, const wchar_t *src, size_t n);
wchar_t *wmemmove(wchar_t *dest, const wchar_t *src, size_t n);
int wmemcmp(const wchar_t *s1, const wchar_t *s2, size_t n);

//
// String services.
//

size_t wcslen(const wchar_t *s);
size_t wcsnlen(const wchar_t *s, size_t maxlen);

//
// Extensions.
//

#if defined(__STDC_WANT_LIB_EXT1__) && __STDC_WANT_LIB_EXT1__ >= 1

size_t wcsnlen_s(const wchar_t *str, size_t strsz);

int vswprintf_s(wchar_t *buf, size_t bufsz, const wchar_t *format, va_list args);

#endif

#ifdef __cplusplus
}
#endif

#endif // __WCHAR_H
