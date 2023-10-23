#!/bin/sh

coc_file=$1
c_file=$(basename -s .coc $coc_file).c
cp $coc_file $c_file

sed -e "1s/^/#include \"coc.h\"\n\n/"    -i $c_file
sed -e "/^ \+or/ s/\bor\b/else if/g"     -i $c_file
sed -e "/^ \+esac/ s/\besac\b/default/g" -i $c_file
sed -e "/^ \+fi/ s/\bfi\b/else/g"        -i $c_file
sed -e "/^ \+def/ s/\bdef\b/typedef/g"   -i $c_file
