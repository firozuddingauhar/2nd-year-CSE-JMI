for a in $*
do
	if [ -f $a ]
	then
		lines=$(wc -l < $a)
		echo "$a is a file and $a has $lines no of lines "
	else
		echo $a is a directory
	fi
done
