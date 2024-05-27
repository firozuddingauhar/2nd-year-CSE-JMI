#include <stdio.h>

int main() {
    int n;
    printf("Enter a positive integer N: ");
    scanf("%d", &n);

    // Calculate sum of first N natural numbers
    int sumNaturals = 0;
    for (int i = 1; i <= n; i++) {
        sumNaturals += i;
    }
    printf("Sum of first %d natural numbers: %d\n\n", n, sumNaturals);

    // Calculate sum of first N even natural numbers
    int sumEvenNaturals = 0;
    for (int i = 2; i <= 2 * n; i += 2) {
        sumEvenNaturals += i;
    }
    printf("Sum of first %d even natural numbers: %d\n\n", n, sumEvenNaturals);

    // Calculate sum of first N odd natural numbers
    int sumOddNaturals = 0;
    for (int i = 1; i <= 2 * n; i += 2) {
        sumOddNaturals += i;
    }
    printf("Sum of first %d odd natural numbers: %d\n\n", n, sumOddNaturals);

    // Calculate sum of squares of first N natural numbers
    int sumSquares = 0;
    for (int i = 1; i <= n; i++) {
        sumSquares += i * i;
    }
    printf("Sum of squares of first %d natural numbers: %d\n\n", n, sumSquares);

    // Calculate sum of cubes of first N natural numbers
    int sumCubes = 0;
    for (int i = 1; i <= n; i++) {
        sumCubes += i * i * i;
    }
    printf("Sum of cubes of first %d natural numbers: %d\n\n", n, sumCubes);

    // Calculate factorial of a number
    int factorialNum = 1;
    for (int i = 1; i <= n; i++) {
        factorialNum *= i;
    }
    printf("Factorial of %d: %d\n\n", n, factorialNum);

    // Count digits in a given number
    int num;
    printf("Enter a number to count its digits: ");
    scanf("%d", &num);
    int digitCount = 0;
    while (num != 0) {
        num /= 10;
        digitCount++;
    }
    printf("Number of digits is: %d\n\n", digitCount);

    // Check whether a given number is a Prime number or not
    printf("Enter a number to check if it is prime: ");
    scanf("%d", &num);
    int isPrime = 1;
    if (num <= 1) {
        isPrime = 0; 
    } else {
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                isPrime = 0; 
                break;
            }
        }
    }
    if (isPrime) {
        printf("%d is a prime number.\n\n", num);
    } else {
        printf("%d is not a prime number.\n\n", num);
    }

    // Calculate LCM of two numbers
    int a, b;
    printf("Enter two numbers to find their LCM: ");
    scanf("%d %d", &a, &b);
    int max = (a > b) ? a : b;
    while (1) {
        if (max % a == 0 && max % b == 0) {
            printf("LCM of %d and %d: %d\n\n", a, b, max);
            break;
        }
        max++;
    }

    // Reverse a given number
    printf("Enter a number to reverse: ");
    scanf("%d", &num);
    int reversed = 0;
    while (num != 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    printf("Reverse of %d: %d\n\n", num, reversed);

    return 0;
}
