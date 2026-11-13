#!/bin/bash
#
# Central build driver.
# Copyright (c) 2026, Apollo Telephone Laboratories, et al.
# Provided under the BSD-3 clause.
#

qemu-system-x86_64                          \
    -bios OVMF.fd                         \
    -hda fat:rw:disk                        \
    -serial stdio
