#factorial
#!bin/bash


echo "Enter no"
read no
i=$no

while [ $i -gt 1 ]
do


i=`expr $i - 1`
no=`expr $no \* $i`


done
echo factorial = $no








