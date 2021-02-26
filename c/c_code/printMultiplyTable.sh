#!/bin/bash
#4.10.sh
FILES=`ls *.sh`
for i in 1 2 3 4 5 6 7 8 9 
 do
for j in 1 2 3 4 5 6 7 8 9 
do
if [ $j -le $i  ]
then 
echo -e "$j\c"
echo -e "*\c"
echo -e "$i\c"
echo -e "=\c"
echo -e  "$[ $i*$j  ]  \c"
fi
done
echo  ""
done
  
