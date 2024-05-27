#include <stdio.h>

int main() {
    int num, num2, num3, a, b, temp, digit;
    char ch;
    float f;
    double d;
    
    // 1. Print unit digit of a given number
    printf("Enter a number: ");
    scanf("%d", &num);
    int unit_digit = num % 10;
    printf("Unit digit: %d\n", unit_digit);

    // 2. Print a given number without its last digit
    num2 = num / 10;
    printf("\nNumber without the last digit: %d\n\n", num2);

    // 3. Swap values of two int variables
    printf("Enter two integers to swap: ");
    scanf("%d %d", &a, &b);
    temp = a;
    a = b;
    b = temp;
    printf("Swapped values: a = %d, b = %d\n\n", a, b);

    // 4. Swap values of two int variables without using a third variable
    printf("Enter two integers to swap without a third variable: ");
    scanf("%d %d", &a, &b);
    a = a + b;
    b = a - b;
    a = a - b;
    printf("Swapped values without a third variable: a = %d, b = %d\n\n", a, b);

    // 5. Input a three-digit number and display the sum of the digits
    printf("Enter a three-digit number: ");
    scanf("%d", &num3);
    int sum_of_digits = (num3 % 10) + ((num3 / 10) % 10) + (num3 / 100);
    printf("Sum of the digits: %d\n\n", sum_of_digits);

    // 6. Take a character as input and display its ASCII code
    printf("Enter a character: ");
    scanf(" %c", &ch);
    printf("ASCII code of '%c' is %d\n\n", ch, ch);

    // 7. Find the position of the first 1 in LSB
    printf("Enter a number: ");
    scanf("%d", &num);
    int position = 0;
    while (!(num & 1)) {
        num >>= 1;
        position++;
    }
    printf("Position of the first 1 in LSB: %d\n\n", position);

    // 8. Check whether the given number is even or odd using bitwise operator
    printf("Enter a number: ");
    scanf("%d", &num);
    if (num & 1) {
        printf("%d is odd\n\n", num);
    } else {
        printf("%d is even\n\n", num);
    }

    // 9. Print the size of int, float, char, and double variables
    printf("Size of int: %lu bytes\n", sizeof(int));
    printf("Size of float: %lu bytes\n", sizeof(float));
    printf("Size of char: %lu bytes\n", sizeof(char));
    printf("Size of double: %lu bytes\n\n", sizeof(double));

    // 10. Make the last digit of a number stored in a variable as zero
    printf("Enter a number: ");
    scanf("%d", &num);
    num = (num / 10) * 10;
    printf("Number with last digit as zero: %d\n\n", num);

    // 11. Input a number and a digit, append the digit to the number
    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter a digit to append: ");
    scanf("%d", &digit);
    num = (num * 10) + digit;
    printf("Resulting number: %d\n\n", num);

    // 12. Convert INR to USD
    float inr, usd;
    printf("Enter an amount in INR: ");
    scanf("%f", &inr);
    usd = inr / 76.23;
    printf("Equivalent amount in USD: %.2f\n\n", usd);

    // 13. Rotate the digits of a three-digit number to the right
    printf("Enter a three-digit number: ");
    scanf("%d", &num);
    int last_digit = num % 10;
    num = num / 10 + (last_digit * 100);
    printf("Rotated number: %d\n", num);

    return 0;
}
