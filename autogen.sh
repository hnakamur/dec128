#!/bin/sh

autogen_init() {
    touch_if_not_found COPYING INSTALL NEWS README AUTHORS ChangeLog
    aclocal
    autoheader
    automake -a
    autoconf
}

touch_if_not_found() {
    for f in $*; do
        if [ ! -f $f ]; then
            touch $f
        fi
    done
}

autogen_clean() {
    if [ -f Makefile ]; then
        make clean
    fi
    rm -rf .deps aclocal.m4 autom4te.cache config.h \
        config.h.in config.h.in~ config.log config.status configure \
        depcomp install-sh Makefile Makefile.in missing \
        stamp-h1 temp.txt
    rm_if_empty COPYING INSTALL NEWS README AUTHORS ChangeLog
}

rm_if_empty() {
    for f in $*; do
        if [ -f $f -a ! -s $f ]; then
            rm $f
        fi
    done
}

case $1 in
init)
    autogen_init
    ;;
clean)
    autogen_clean
    ;;
*)
    echo "Usage: $0 [init|clean]"
    ;;
esac
