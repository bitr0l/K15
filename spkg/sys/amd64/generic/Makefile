#
# Kernel AMD64 build script.
# Copyright (c) 2026, Apollo Telephone Laboratories, et al.
# Provided under the BSD-3 clause.
#

include ../../../mk/common.mk
include ../../../mk/sys.mk

ASMFILES = $(shell find . -name "*.S")
ASMOFILES = $(ASMFILES:.S=.S.o)
MISC_OFILES = $(shell find $(GLOBAL_ROOT)/sys/ -name "*.o")

REAL_ROOT = $(GLOBAL_ROOT)/..
KERNEL_OUT = $(REAL_ROOT)/out/k15.sys

CFLAGS =				\
	$(COMMON_CFLAGS)

.PHONY: all
all: $(ASMOFILES)
	$(CC) -Thost/link.ld $(COMMON_LINK_FLAGS) $(MISC_OFILES) -o $(KERNEL_OUT)

%.S.o: %.S
	$(CC) -c $(CFLAGS) $< -o $@
