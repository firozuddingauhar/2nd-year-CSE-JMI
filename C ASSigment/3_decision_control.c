#include <stdio.h>
#include <math.h>
#include <ctype.h>

int main() {
    int num, num1, num2, num3,year, month, days, marks[5];
    double a, b, c;
    float cost_price, selling_price;
    char ch;

    // 1: Check if a number is positive or non-positive
    printf("\n1: Enter a number: ");
    scanf("%d", &num);
    if (num > 0) {
        printf("Positive number\n");
    } else if (num < 0) {
        printf("Non-positive number\n");
    } else {
        printf("Zero\n");
    }

    // 2: Check if a number is divisible by 5
    printf("\n2: Enter a number: ");
    scanf("%d", &num);
    if (num % 5 == 0) {
        printf("Divisible by 5\n");
    } else {
        printf("Not divisible by 5\n");
    }

    // 3: Check if a number is even or odd
    printf("\n3: Enter a number: ");
    scanf("%d", &num);
    if (num % 2 == 0) {
        printf("Even number\n");
    } else {
        printf("Odd number\n");
    }

    // 4: Check if a number is even or odd without using %
    printf("\n4: Enter a number: ");
    scanf("%d", &num);
    if ((num & 1) == 0) {
        printf("Even number\n");
    } else {
        printf("Odd number\n");
    }

    // 5: Check if a number is a three-digit number
    printf("\n5: Enter a number: ");
    scanf("%d", &num);
    if (num >= 100 && num <= 999) {
        printf("Three-digit number\n");
    } else {
        printf("Not a three-digit number\n");
    }

    // 6: Print the greater of two numbers
    printf("\n6: Enter two numbers: ");
    scanf("%d %d", &num1, &num2);
    if (num1 > num2) {
        printf("Greater number: %d\n", num1);
    } else if (num2 > num1) {
        printf("Greater number: %d\n", num2);
    } else {
        printf("Both numbers are the same: %d\n", num1);
    }

    // 7: Check the roots of a quadratic equation
    printf("\n7: Enter coefficients (a, b, c) of the quadratic equation: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    double discriminant = b * b - 4 * a * c;
    if (discriminant > 0) {
        printf("Real and distinct roots\n");
    } else if (discriminant == 0) {
        printf("Real and equal roots\n");
    } else {
        printf("Imaginary roots\n");
    }

    // 8: Check if a year is a leap year
    printf("\n8: Enter a year: ");
    scanf("%d", &year);
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        printf("Leap year\n");
    } else {
        printf("Not a leap year\n");
    }

    // 9: Find the greatest among three numbers
    printf("\n9: Enter three numbers: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    if (num1 == num2 && num2 == num3) {
        printf("All three numbers are equal: %d\n", num1);
    } else if (num1 >= num2 && num1 >= num3) {
        printf("Greatest number: %d\n", num1);
    } else if (num2 >= num1 && num2 >= num3) {
        printf("Greatest number: %d\n", num2);
    } else {
        printf("Greatest number: %d\n", num3);
    }

    // 10: Calculate profit or loss percentage
    printf("\n10: Enter cost price and selling price: ");
    scanf("%f %f", &cost_price, &selling_price);
    if (selling_price > cost_price) {
        float profit = selling_price - cost_price;
        float profit_percentage = (profit / cost_price) * 100;
        printf("Profit percentage: %.2f%%\n", profit_percentage);
    } else if (cost_price > selling_price) {
        float loss = cost_price - selling_price;
        float loss_percentage = (loss / cost_price) * 100;
        printf("Loss percentage: %.2f%%\n", loss_percentage);
    } else {
        printf("No profit, no loss\n");
    }

    // 11: Check if a candidate passed or failed based on marks in 5 subjects
    printf("\n11: Enter marks for 5 subjects (out of 100): ");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &marks[i]);
    }
    int total_marks = 0;
    for (int i = 0; i < 5; i++) {
        total_marks += marks[i];
    }
    if (total_marks / 5 >= 33) {
        printf("Candidate passed\n");
    } else {
        printf("Candidate failed\n");
    }

    // 12: Check if a character is uppercase, lowercase, digit, or special character
    printf("\n12: Enter a character: ");
    scanf(" %c", &ch);
    if (isupper(ch)) {
        printf("Uppercase alphabet\n");
    } else if (islower(ch)) {
        printf("Lowercase alphabet\n");
    } else if (isdigit(ch)) {
        printf("Digit\n");
    } else {
        printf("Special character\n");
    }

    // 13: Check if a number is divisible by 3 and 2
    printf("\n13: Enter a number: ");
    scanf("%d", &num);
    if (num % 3 == 0 && (num & 1) == 0) {
        printf("Divisible by 3 and even\n");
    } else {
        printf("Not divisible by 3 and even\n");
    }

    // 14: Check if a number is divisible by 7 or 3
    printf("\n14: Enter a number: ");
    scanf("%d", &num);
    if (num % 7 == 0 || num % 3 == 0) {
        printf("Divisible by 7 or 3\n");
    } else {
        printf("Not divisible by 7 or 3\n");
    }

    // 15: Check if a number is positive, negative, or zero
    printf("\n15: Enter a number: ");
    scanf("%d", &num);
    if (num > 0) {
        printf("Positive number\n");
    } else if (num < 0) {
        printf("Negative number\n");
    } else {
        printf("Zero\n");
    }

    // 16: Check if a character is an alphabet (uppercase, lowercase), digit, or special character
    printf("\n16: Enter a character: ");
    scanf(" %c", &ch);
    if (isalpha(ch)) {
        if (isupper(ch)) {
            printf("Uppercase alphabet\n");
        } else {
            printf("Lowercase alphabet\n");
        }
    } else if (isdigit(ch)) {
        printf("Digit\n");
    } else {
        printf("Special character\n");
    }

    // 17: Check if a triangle with given sides is valid
    printf("\n17: Enter the lengths of the sides of a triangle: ");
    scanf("%d %d %d", &num1, &num2, &num3);
    if (num1 + num2 > num3 && num1 + num3 > num2 && num2 + num3 > num1) {
        printf("Valid triangle\n");
    } else {
        printf("Invalid triangle\n");
    }

    // 18: Display the number of days in a given month
    printf("\n18: Enter a month number: ");
    scanf("%d", &month);
    switch (month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            days = 31;
            break;
        case 4: case 6: case 9: case 11:
            days = 30;
            break;
        case 2:
            days = 28;
            break;
        default:
            printf("Invalid month\n");
            return 1;
    }
    printf("Number of days in the month: %d\n", days);

    return 0;
}
