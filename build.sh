#!/bin/bash
#
# Central build driver.
# Copyright (c) 2026, Apollo Telephone Laboratories, et al.
# Provided under the BSD-3 clause.
#

MAKE=make

#
# Check if a list of deps are installed on the host system
#
# $@: Dep list to check
#
check_deps() {
    for dep in $@
    do
        printf "Checking if $dep is installed... "
        which $dep &>/dev/null
        if [ $? -ne 0 ]
        then
            echo "no"
            echo "fatal: Please install '$dep'!"
            exit 1
        fi
        echo "yes"
    done
}

#
# Make the disk to be booted from
#
make_disk() {
    mkdir -p disk/EFI/BOOT/

    mv out/BOOTX64.EFI disk/EFI/BOOT
    cp out/k15.sys disk/k15.sys

    rm -f out/k15.img
    truncate -s 4M out/k15.img
    mkfs.fat -F 12 out/k15.img 4096
    mcopy -s -i out/k15.img disk/* ::/
}

#
# Prepare the build environment.
#
build_prepare() {
    mkdir -p out
    pushd spkg/
        source env/build.env
    popd

    check_deps      \
        clang       \
        rsync       \
        make        \
        lld-link    \
        mtools      \
        mkfs.fat    \
        truncate
}

#
# Build a directory with MAKE.
#
# $1: Directory to build
#
build_make() {
    pushd $1/
        $MAKE
    popd
}

#
# Begin the actual build process.
#
build() {
    build_make      \
        spkg/boot

    build_make      \
        spkg/sys

    make_disk
}

build_prepare
build
