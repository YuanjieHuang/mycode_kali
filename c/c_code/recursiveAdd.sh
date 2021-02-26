#!/bin/bash
#4.11.sh
sum=0
i=1
until [ $i -gt 100  ]
do
echo $i
sum=$[$sum+$i]
i=$[$i+1]
done 
echo $sum 
