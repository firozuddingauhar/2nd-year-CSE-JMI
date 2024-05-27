for file in "$@"; do
    sed -i '/sorry/d' "$file"
done
