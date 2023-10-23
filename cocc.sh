#!/bin/sh

coc_file=$1
c_file=$(basename -s .coc $coc_file).c
cp $coc_file $c_file

sed -e "1s/^/#include \"coc.h\"\n\n/"                -i $c_file
sed -e "/^\s\+main/ s/\main\b/void main/g"           -i $c_file
sed -e "/^\s\+or\(\s\|$\)/ s/\bor\b/else if/g"       -i $c_file
sed -e "/^\s\+fi\(\s\|$\)/ s/\bfi\b/else/g"          -i $c_file
sed -e "/^\s\+esac/ s/\besac\b/default/g"            -i $c_file
sed -e "/^\s\+record/ s/\brecord\b/typedef struct/g" -i $c_file
