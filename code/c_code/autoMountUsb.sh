#!/bin/bash
#autousb
echo "welcome to use AUTOUSB"
echo "do you want load usb(y/n)?"
read  ANSWER

if  [ $ANSWER = "Y" -o $ANSWER = "y" ]
   then mount -t vfat /dev/sda1 /mnt/usb
   echo   "do you want copy files to  /root(y/n)?"
   read  ANSWER
   while [  $ANSWER  =  "y"  -o  $ANSWER =  "Y" ]
   do
     ls -a /mnt/usb
     echo "type the filename you want to copy"
     read  FILE
     cp /mnt/usb/"$FILE"  /root
        if [  $? -qe 0 ];then
           echob  " copy finished"
        else
           echob  " copy errored "
        fi
     echo  "any other files(y/n)?"
     read  ANSWER
   done
fi

echo    "do you want to copy files to usb(y/n)?"
read  ANSWER
while  [  $ANSWER  =  "y"  -o  $ANSWER  =  "Y"  ]
do
  ls -a  /root
  echo  "type the filename you want to copy to usb"
  read  FILE
  cp "/root/$FILE"  /mnt/usb
    if [  $? -qe 0 ];then
         echob  " copy file finished"
        else
         echob  " copy file errored "
    fi
  echo  "any other files(y/n)?"
  read  ANSWER
done

echo  "do you want to umount usb(y/n)?"
read  ANSWER
if  [ $ANSWER  =  " y"  -o   $ANSWER  =  " Y" ] ;then
  umount /mnt/usb
  else
echo "Haven't umount!"
fi
echo "GoodBye!"

