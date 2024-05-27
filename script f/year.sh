read -p "Enter year :" year
if [ -z "$year" ];
then
	year=$(date +%Y)
else
	year=$year
fi

if (( ( year % 4 == 0 && year % 400 != 0 ) || ( year % 100 == 0 ) ))
then
	echo "$year" is a leap year
else
	echo "$year" ia not a leap year
fi


