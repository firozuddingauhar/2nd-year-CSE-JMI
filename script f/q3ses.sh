touch temp_file
if [ $2 -eq 1 ]
then
	tr '[:upper:]' '[:lower:]' < $1 > temp_file && mv temp_file $1
else
	tr '[:lower:]' '[:upper:]'  < $1 > temp_file && mv temp_file $1
fi

