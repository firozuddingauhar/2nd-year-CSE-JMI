#!/bin/bash

# Function to calculate Fibonacci sequence

echo "Enter the Range "
read n
a=0
b=1
i=2
echo "The fibonacci series :"
echo -n "$a "
echo -n "$b "
while [ $i -le $n ]
do
	c=$( echo $a + $b | bc)
	echo -n "$c "
	a=$b
	b=$c
	i=$( echo $i + 1 | bc)
done


