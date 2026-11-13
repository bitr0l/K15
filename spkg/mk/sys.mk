#
# Kernel build variables.
# Copyright (c) 2026, Apollo Telephone Laboratories, et al.
# Provided under the BSD-3 clause.
#

COMMON_CFLAGS =							\
	-target x86_64-unknown 				\
	-ffreestanding						\
	-nostdlib							\
	-nostdinc							\
	-MMD								\
	-I$(GLOBAL_ROOT)/sdk/inc/crt

ifeq ($(CONFIG_ARCH),amd64)
	COMMON_CFLAGS +=					\
		-mno-red-zone					\
		-mgeneral-regs-only				\
		-mno-sse						\
		-mno-sse2						\
		-mno-avx						\
		-mno-avx2						\
		-mno-3dnow
endif

COMMON_LINK_FLAGS =	\
	-nostdlib
