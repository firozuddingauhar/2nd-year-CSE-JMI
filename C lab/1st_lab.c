#include <stdio.h>

void displayFibonacci(int n) {
    int first = 0, second = 1, next;

    printf("Fibonacci Sequence up to %d terms:\n", n);
    for (int i = 0; i < n; i++) {
        printf("%d, ", first);
        next = first + second;
        first = second;
        second = next;
    }
}

void printHalfPyramid(int rows) {
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= i; j++) {
            printf("* ");
        }
        printf("\n");
    }
}

int factorial(int n) {
    int fact = 1;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int findMax(int arr[], int size) {
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}

int main() {
    int terms;
    printf("Enter the number of terms for Fibonacci sequence: ");
    scanf("%d", &terms);
    displayFibonacci(terms);

    int rows;
    printf("\nEnter the number of rows for the half pyramid: ");
    scanf("%d", &rows);
    printHalfPyramid(rows);

    int number;
    printf("\nEnter a number to find its factorial: ");
    scanf("%d", &number);
    printf("Factorial of %d = %d\n", number, factorial(number));

    int arr[] = {3, 5, 12, 7, 2, 9};
    int size = sizeof(arr) / sizeof(arr[0]);
    printf("\nMaximum element in the array: %d\n\n", findMax(arr, size));

    return 0;
}