#
# EFI platform build script.
# Copyright (c) 2026, Apollo Telephone Laboratories, et al.
# Provided under the BSD-3 clause.
#

include ../../../mk/common.mk
include ../../../mk/ldr.mk

CFILES = $(shell find . -name "*.c")
CFILES += $(shell find $(GLOBAL_ROOT)/sdk/crt/ -name "*.c")
OFILES = $(CFILES:.c=.o)
DFILES = $(CFILES:.c=.d)

REAL_ROOT = $(GLOBAL_ROOT)/..
LDFLAGS =                               \
        $(LDR_COMMON_LDFLAGS)           \
        -Wl,-subsystem:efi_application  \
        -Wl,-entry:efi_main

CFLAGS =                                 \
        $(LDR_COMMON_CFLAGS)             \
		-I$(GLOBAL_ROOT)/sdk/inc		 \
		-I$(GLOBAL_ROOT)/sdk/inc/crt	\
        -O2                              \
		-MMD                             \
		-Iinc							 \
		-fms-extensions

.PHONY: all
all: $(OFILES) $(REAL_ROOT)/out/BOOTX64.EFI postbuild

-include $(DFILES)
%.o: %.c
	$(PROMPT) "CC" $<
	$(CC) -c $(CFLAGS) $< -o $@

.PHONY: BOOTX64.EFI
$(REAL_ROOT)/out/BOOTX64.EFI:
	$(CC) $(LDFLAGS) $(OFILES) -o $@

.PHONY: postbuild
postbuild:
	rm -f $(GLOBAL_ROOT)/sdk/crt/**/{*.o,*.d}
