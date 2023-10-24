#!/bin/sh

co_file=$1
c_file=$(basename -s .co $co_file).c
cp $co_file $c_file

sed -i -e "1s/^/#include \"coc.h\"\n\n/"      $c_file
sed -i -e "/^\s\+main/ s/\main\b/void main/g" $c_file
