/*
 * String definitions.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#ifndef __STRING_H
#define __STRING_H

#ifdef __cplusplus
extern "C" {
#endif

#define __need_size_t
#define __need_NULL
#include <stddef.h>

//
// Memory services.
//

void *memset(void *s, int c, size_t n);
void *memcpy(void *dest, const void *src, size_t n);
void *memmove(void *dest, const void *src, size_t n);
int memcmp(const void *s1, const void *s2, size_t n);

//
// String services.
//

size_t strlen(const char *s);
size_t strnlen(const char *s, size_t maxlen);

#ifdef __cplusplus
}
#endif

#endif // __STRING_H
