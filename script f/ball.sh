echo "Enter the factorial"
read n
f=1
i=1
while [ $i -le $n ];
do
	f=$(echo "$f * $i"  | bc )
	i=$(echo $i + 1  | bc )
done
echo $f

