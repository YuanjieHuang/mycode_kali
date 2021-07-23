#!/bin/bash
# cur_dir=$(cd `dirname $0`;pwd)
mkdir new;
file=`ls *.cpp`
for i in $file
do
str_del=`echo $i | cut -nb 1-12`;
# echo $str_del;
rename -v "s/$str_del//" $i;
# echo $i;
# sed -i '/^\s*$/d' $i;
# sed -i '/^\s*$/d' $i;
# sed -i '1d' $i;
done
# 程序清单1-1.cpp

