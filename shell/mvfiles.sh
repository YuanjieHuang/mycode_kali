#!/bin/bash
#:>>!
#function arr("01" "02" "03" )
CUR_DIR=$(cd `dirname $0` ;pwd)
path=$CUR_DIR/..
echo $path
i={01..21}
echo $i
:<<!
if false;then
for j in {01..21}
do
    echo $j
    rm -rf $path/$j
done
fi
!
:<<!
do
    echo $j
    mv $path/$j/* $path
done
!

