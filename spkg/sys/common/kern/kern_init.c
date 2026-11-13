/*
 * Kernel entry point.
 * Copyright (c) 2026, Apollo Telephone Laboratories, et al.
 * Provided under the BSD-3 clause.
 */

#include <pexpert/serial.h>

void
kmain (
    void
    )
{
    /* Initialize the serial driver */
    px_serial_init();
}
