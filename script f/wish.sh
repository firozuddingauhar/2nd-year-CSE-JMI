t=$(date +%H)

if [ "$t" -ge 12 -a "$t" -lt 16 ]; then
    echo "Good Afternoon"
elif [ "$t" -lt 12 ]; then
    echo "Good morning"
elif [ "$t" -ge 16 -a "$t" -lt 21 ]; then
    echo "Good night"
fi

