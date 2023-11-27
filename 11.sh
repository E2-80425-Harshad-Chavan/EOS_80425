
echo "enter your salary"
read n
da=`echo "$n * 0.40" |bc`
hra=`echo "$n * 0.20" |bc`
f=`echo "$n+$da+$hra" |bc`
echo gross salary : $f