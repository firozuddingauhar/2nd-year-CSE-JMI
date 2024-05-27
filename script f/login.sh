echo "Enter the username "
read name
i=1
while [ $i -le 5 ]
do
	i=`expr $i + 1`
	who | grep $name
if [ $? -eq 0 ]
then
	echo "Logged in "
	exit
else
	echo "Not logged in"
	sleep 5
fi
done
