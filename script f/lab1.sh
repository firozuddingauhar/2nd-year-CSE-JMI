echo "Enter two numbers"
read a b
c=$((echo $a + $b ) | bc )
echo "The sum of $a and $b is $c"

#Area and Perimeter

echo "Enter the radius of circle"
read r
per=$( echo "2*3.14*$r" | bc)
area=$( echo "3.14*$r*$r" | bc)

echo "The area is $area and the perimeter is $per"
