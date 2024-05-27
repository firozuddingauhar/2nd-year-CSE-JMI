echo "Enter the text in uppercase:"
read name
lowercase=$(echo "$name" | tr '[:upper:]' '[:lower:]')
echo "Text in lowercase is $lowercase"
