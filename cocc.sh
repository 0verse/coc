#!/bin/sh

coc_file=$1
c_file=$(basename -s .co $coc_file).c
cp $coc_file $c_file

sed -e "1s/^/#include \"coc.h\"\n\n/" \
    -e "/^\s\+main/ s/\main\b/void main/g" \
    -e "/^\s\+or\(\s\|$\)/ s/\bor\b/else if/g" \
    -e "/^\s\+fi\(\s\|$\)/ s/\bfi\b/else/g" \
    -e "/^\s\+esac/ s/\besac\b/default/g" \
    -e "/^\s\+record/ s/\brecord\b/typedef struct/g" \
    -i $c_file
