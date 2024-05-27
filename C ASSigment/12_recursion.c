#include <stdio.h>

// Recursive function to print first N natural numbers
void printNaturalNumbers(int N, int current) {
    if (current <= N) {
        printf("%d ", current);
        printNaturalNumbers(N, current + 1);
    }
}

// Recursive function to print first N natural numbers in reverse order
void printNaturalNumbersReverse(int N) {
    if (N > 0) {
        printf("%d ", N);
        printNaturalNumbersReverse(N - 1);
    }
}

// Recursive function to print first N odd natural numbers
void printOddNaturalNumbers(int N, int current) {
    if (current <= N) {
        printf("%d ", 2 * current - 1);
        printOddNaturalNumbers(N, current + 1);
    }
}

// Recursive function to print first N odd natural numbers in reverse order
void printOddNaturalNumbersReverse(int N) {
    if (N > 0) {
        printf("%d ", 2 * N - 1);
        printOddNaturalNumbersReverse(N - 1);
    }
}

// Recursive function to print first N even natural numbers
void printEvenNaturalNumbers(int N, int current) {
    if (current <= N) {
        printf("%d ", 2 * current);
        printEvenNaturalNumbers(N, current + 1);
    }
}

// Recursive function to print first N even natural numbers in reverse order
void printEvenNaturalNumbersReverse(int N) {
    if (N > 0) {
        printf("%d ", 2 * N);
        printEvenNaturalNumbersReverse(N - 1);
    }
}

// Recursive function to print squares of first N natural numbers
void printSquares(int N, int current) {
    if (current <= N) {
        printf("%d ", current * current);
        printSquares(N, current + 1);
    }
}

// Recursive function to print binary of a given decimal number
void printBinary(int decimal) {
    if (decimal > 0) {
        printBinary(decimal / 2);
        printf("%d", decimal % 2);
    }
}

// Recursive function to print octal of a given decimal number
void printOctal(int decimal) {
    if (decimal > 0) {
        printOctal(decimal / 8);
        printf("%d", decimal % 8);
    }
}

// Recursive function to print the reverse of a given number
void printReverse(int number) {
    if (number == 0) {
        return;
    }
    printf("%d", number % 10);
    printReverse(number / 10);
}

int main() {
    int N, decimalNumber;

    printf("Enter N for natural numbers: ");
    scanf("%d", &N);
    printf("First %d natural numbers: ", N);
    printNaturalNumbers(N, 1);
    printf("\n\n");

    printf("Enter N for natural numbers in reverse order: ");
    scanf("%d", &N);
    printf("First %d natural numbers in reverse order: ", N);
    printNaturalNumbersReverse(N);
    printf("\n\n");

    printf("Enter N for odd natural numbers: ");
    scanf("%d", &N);
    printf("First %d odd natural numbers: ", N);
    printOddNaturalNumbers(N, 1);
    printf("\n\n");

    printf("Enter N for odd natural numbers in reverse order: ");
    scanf("%d", &N);
    printf("First %d odd natural numbers in reverse order: ", N);
    printOddNaturalNumbersReverse(N);
    printf("\n\n");

    printf("Enter N for even natural numbers: ");
    scanf("%d", &N);
    printf("First %d even natural numbers: ", N);
    printEvenNaturalNumbers(N, 1);
    printf("\n\n");

    printf("Enter N for even natural numbers in reverse order: ");
    scanf("%d", &N);
    printf("First %d even natural numbers in reverse order: ", N);
    printEvenNaturalNumbersReverse(N);
    printf("\n\n");

    printf("Enter N for squares of natural numbers: ");
    scanf("%d", &N);
    printf("Squares of first %d natural numbers: ", N);
    printSquares(N, 1);
    printf("\n\n");

    printf("Enter a decimal number to convert to binary: ");
    scanf("%d", &decimalNumber);
    printf("Binary representation: ");
    printBinary(decimalNumber);
    printf("\n\n");

    printf("Enter a decimal number to convert to octal: ");
    scanf("%d", &decimalNumber);
    printf("Octal representation: ");
    printOctal(decimalNumber);
    printf("\n\n");

    printf("Enter a number to print its reverse: ");
    scanf("%d", &decimalNumber);
    printf("Reverse of the number: ");
    printReverse(decimalNumber);
    printf("\n\n");

    return 0;
}
