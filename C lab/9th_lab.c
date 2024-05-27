#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int daysInMonth(int month, int year) {
    int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (month == 2 && ((year % 4 == 0 && year % 100 != 0)||(year % 400 == 0))) { return 29; }
    return days[month];
}
int daysBetweenDates(int day1, int month1, int year1, int day2, int month2, int year2) {
    int days = 0;
    while (day1 != day2 || month1 != month2 || year1 != year2) {
        days++;
        day1++;
        if (day1 > daysInMonth(month1, year1)) {
            day1 = 1;
            month1++;
        }
        if (month1 > 12) {
            month1 = 1;
            year1++;
        }
    }
    return days;
}
int main() {
    char input[25];
    int day1, month1, year1, day2, month2, year2;
    printf("Enter two dates in the format 'DD MM YYYY, DD MM YYYY': ");
    gets(input);
    puts(input);
    if (sscanf(input, "%d %d %d, %d %d %d", &day1, &month1, &year1, &day2, &month2, &year2) != 6) {
        printf("\nInvalid input format. Please use 'DD MM YYYY, DD MM YYYY' format.\n");
        return 1;
    }
    int days = daysBetweenDates(day1, month1, year1, day2, month2, year2);
    printf("\nThe number of days between the two dates is: %d\n", days);
    return 0;
}