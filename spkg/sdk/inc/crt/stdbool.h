/*
 * C runtime bool support.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#ifndef __STDBOOL_H
#define __STDBOOL_H

#define __bool_true_false_are_defined 1

#ifdef __cplusplus
    //
    // Define GNU extensions.
    //

    #if defined(__GNUC__) && !defined(__STRICT_ANSI__)
        #define _Bool bool
        #if __cplusplus < 201103L
            #define bool  bool
            #define true  true
            #define false false
        #endif
    #endif
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 202311L
    //
    // Bool, true, and false are keywords.
    //
#elif defined(__STDC_VERSION__) && __STDC_VERSION__ >= 199901L
    #define bool  _Bool
    #define true  1
    #define false 0
#else
    #define bool  char
    #define true  1
    #define false 0
#endif

#endif // __STDBOOL_H
