#!/bin/bash
#4.9.sh
FILES=`ls *.sh`
for sh  in $FILES 
 do 
txt=`echo $sh | sed "s/.sh/.txt/"` 
cp   $sh  $txt
#echo $sh
echo $txt

done
  
