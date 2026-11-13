/*
 * Root EFI header.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#ifndef _EFI_H
#define _EFI_H

#ifdef _M_X64
    #include "x64/efibind.h"
#else
    #error Unsupported processor architecture!
#endif

#include "efidef.h"
#include "efidevp.h"
#include "efiprot.h"
#include "eficon.h"
#include "efiapi.h"
#include "efierr.h"

#endif // _EFI_H
