#!/bin/bash
:<< INTRUDUCE
AUTHOR:Yuanjie Huang
FUNCTION:copy and change file name.
INTRUDUCE
FILES=`ls *.sh`
for sh  in $FILES 
do 
    txt=`echo $sh | sed "s/.sh/.txt/"` 
    cp   $sh  $txt
    echo $sh
    echo $txt
done
  
