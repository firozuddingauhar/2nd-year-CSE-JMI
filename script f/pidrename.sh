for file in *.$$; do
    mv "$file" "$(echo "$file" | sed "s/$$//")"
done
