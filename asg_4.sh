echo enter num
read num
i=2
flag=0
while [ $i -lt $num ]
do 
    if [ `expr $num % $i` -eq 0 ]
        then
            flag=1
            break;
    fi
    i=`expr $i + 1`
done
if [ $flag -eq 0 ]
 then
    echo prime no
else
    echo not a prime no
fi
