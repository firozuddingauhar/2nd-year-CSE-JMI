#!/bin/bash

if [ $# -eq 0 ]; then
    read -p "Enter a year (or press Enter to use the current year): " year
    if [ -z "$year" ]; then
        year=$(date +"%Y")
    fi
else
    year=$1
fi

# Check if the year is a leap year
if (( ($year % 4 == 0 && $year % 100 != 0) || ($year % 400 == 0) )); then
    echo "$year is a leap year."
else
    echo "$year is not a leap year."
fi

