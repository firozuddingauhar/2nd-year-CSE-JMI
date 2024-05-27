echo Enter the name of the user
read name
who>list
if grep $name list
then
echo "User: $name is logged in."
else
echo "User: $name not logged in."
fi

