echo "Enter name(File path)"
read name
if [ -d $name ]
then
echo "......................"
echo "name is directory"
ls $name
else
echo "......................"
echo "name is file"
res = `stat -c %s $name`
echo $res
fi
