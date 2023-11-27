#!bi/bash
ch=3

while [ $ch -ne 0 ]
do
echo "Enter your choice"
echo -e "1. Date\n 2. Cal,\n 3. Ls,\n 4. Pwd,\n 5. Exit\n"
read ch

case $ch in
    1)date
        ;;
    2)cal
        ;;
    3)ls
        ;;
    4)pwd
        ;;
    5)
        break;
esac
done