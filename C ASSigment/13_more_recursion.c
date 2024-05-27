#include <stdio.h>

// Recursive function to calculate the sum of the first N natural numbers
int sumOfNaturals(int N) {
    if (N == 1) {
        return 1;
    } else {
        return N + sumOfNaturals(N - 1);
    }
}

// Recursive function to calculate the sum of the first N odd natural numbers
int sumOfOddNaturals(int N) {
    if (N == 1) {
        return 1;
    } else {
        return (2 * N - 1) + sumOfOddNaturals(N - 1);
    }
}

// Recursive function to calculate the sum of the first N even natural numbers
int sumOfEvenNaturals(int N) {
    if (N == 1) {
        return 2;
    } else {
        return (2 * N) + sumOfEvenNaturals(N - 1);
    }
}

// Recursive function to calculate the sum of squares of the first N natural numbers
int sumOfSquares(int N) {
    if (N == 1) {
        return 1;
    } else {
        return N * N + sumOfSquares(N - 1);
    }
}

// Recursive function to calculate the sum of digits of a given number
int sumOfDigits(int number) {
    if (number == 0) {
        return 0;
    } else {
        return (number % 10) + sumOfDigits(number / 10);
    }
}

// Recursive function to calculate the factorial of a given number
int factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    } else {
        return num * factorial(num - 1);
    }
}

// Recursive function to calculate the HCF of two numbers
int hcf(int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return hcf(b, a % b);
    }
}

// Recursive function to calculate the power of a number
int power(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    } else {
        return base * power(base, exponent - 1);
    }
}

// Recursive function to print the first N terms of the Fibonacci series
void fibonacci(int N, int a, int b, int count) {
    if (count < N) {
        printf("%d ", a);
        fibonacci(N, b, a + b, count + 1);
    }
}

// Recursive function to count the digits of a given number
int countDigits(int number) {
    if (number == 0) {
        return 0;
    } else {
        return 1 + countDigits(number / 10);
    }
}

int main() {
    int N, num1, num2, number, base, exponent;

    printf("Enter N for sum of natural numbers: ");
    scanf("%d", &N);
    printf("Sum of first %d natural numbers: %d\n\n", N, sumOfNaturals(N));

    printf("Enter N for sum of odd natural numbers: ");
    scanf("%d", &N);
    printf("Sum of first %d odd natural numbers: %d\n\n", N, sumOfOddNaturals(N));

    printf("Enter N for sum of even natural numbers: ");
    scanf("%d", &N);
    printf("Sum of first %d even natural numbers: %d\n\n", N, sumOfEvenNaturals(N));

    printf("Enter N for sum of squares of natural numbers: ");
    scanf("%d", &N);
    printf("Sum of squares of first %d natural numbers: %d\n\n", N, sumOfSquares(N));

    printf("Enter a number to calculate the sum of its digits: ");
    scanf("%d", &number);
    printf("Sum of digits of %d: %d\n\n", number, sumOfDigits(number));

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &num1);
    printf("Factorial of %d: %d\n\n", num1, factorial(num1));

    printf("Enter two numbers to calculate their HCF: ");
    scanf("%d %d", &num1, &num2);
    printf("HCF of %d and %d: %d\n\n", num1, num2, hcf(num1, num2));

    printf("Enter N to print the first N terms of the Fibonacci series: ");
    scanf("%d", &N);
    printf("Fibonacci series: ");
    fibonacci(N, 0, 1, 0);
    printf("\n\n");

    printf("Enter a number to count its digits: ");
    scanf("%d", &number);
    printf("Number of digits in %d: %d\n\n", number, countDigits(number));

    printf("Enter a base number: ");
    scanf("%d", &base);
    printf("Enter an exponent: ");
    scanf("%d", &exponent);
    printf("%d^%d: %d\n\n", base, exponent, power(base, exponent));

    return 0;
}
