#
# Bootloader build variables.
# Copyright (c) 2026, Apollo Telephone Laboratories, et al.
# Provided under the BSD-3 clause.
#

LDR_COMMON_CFLAGS =						\
	-target x86_64-unknown-windows		\
	-ffreestanding						\
	-fshort-wchar

ifeq ($(CONFIG_ARCH),amd64)
	LDR_COMMON_CFLAGS +=				\
		-mno-red-zone					\
		-mgeneral-regs-only				\
		-mno-sse						\
		-mno-sse2						\
		-mno-avx						\
		-mno-avx2						\
		-mno-3dnow
endif

LDR_COMMON_LDFLAGS =				\
	-target x86_64-unknown-windows  \
	-fuse-ld=lld					\
	-nostdlib
