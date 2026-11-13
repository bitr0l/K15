#
# Kernel build driver.
# Copyright (c) 2026, Apollo Telephone Laboratories, et al.
# Provided under the BSD-3 clause.
#

.PHONY: all
all: machine

.PHONY: machine
machine:
	cd $(CONFIG_ARCH)/$(CONFIG_CHIP); $(MAKE)
