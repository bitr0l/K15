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
# Prepare the build environment.
#
build_prepare() {
    pushd spkg/
        source env/build.env
    popd

    check_deps      \
        clang       \
        rsync       \
        make        \
        lld-link
}

build_prepare
