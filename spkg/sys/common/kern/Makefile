#
# Kernel MI build script.
# Copyright (c) 2026, Apollo Telephone Laboratories, et al.
# Provided under the BSD-3 clause.
#

include ../../../mk/common.mk
include ../../../mk/sys.mk

CFILES = $(shell find . -name "*.c")
OFILES = $(CFILES:.c=.o)
DFILES = $(CFILES:.c=.d)

CFLAGS =		\
	$(COMMON_CFLAGS)

.PHONY: all
all: $(OFILES)

-include $(DFILES)
%.o: %.c
	$(PROMPT) "CC" $<
	$(CC) -c $(CFLAGS) $< -o $@
