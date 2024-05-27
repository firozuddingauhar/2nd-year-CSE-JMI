file1=$1
file2=$2
if cmp -s "$file1" "$file2"; then
    echo "Files have the same contents. Deleting $file2."
    rm "$file2"
else
    echo "Files have different contents."
fi
