#include <stdio.h>

int main() {
    int N, i;

    // 1: Print "MySirG" N times
    printf("1: Enter the value of N for printing MySirG: ");
    scanf("%d", &N);
    printf("MySirG printed %d times:\n", N);
    for (i = 0; i < N; i++) {
        printf("MySirG ");
    }
    printf("\n\n");

    // 2: Print the first N natural numbers
    printf("2: Enter the value of N for printing natural numbers: ");
    scanf("%d", &N);
    printf("First %d natural numbers:\n", N);
    for (i = 1; i <= N; i++) {
        printf("%d ", i);
    }
    printf("\n\n");

    // 3: Print the first N natural numbers in reverse order
    printf("3: Enter the value of N for printing natural numbers in reverse order: ");
    scanf("%d", &N);
    printf("First %d natural numbers in reverse order:\n", N);
    for (i = N; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n\n");

    // 4: Print the first N odd natural numbers
    printf("4: Enter the value of N for printing odd natural numbers: ");
    scanf("%d", &N);
    printf("First %d odd natural numbers:\n", N);
    for (i = 1; i <= 2 * N - 1; i += 2) {
        printf("%d ", i);
    }
    printf("\n\n");

    // 5: Print the first N odd natural numbers in reverse order
    printf("5: Enter the value of N for printing odd natural numbers in reverse order: ");
    scanf("%d", &N);
    printf("First %d odd natural numbers in reverse order:\n", N);
    for (i = 2 * N - 1; i >= 1; i -= 2) {
        printf("%d ", i);
    }
    printf("\n\n");

    // 6: Print the first N even natural numbers
    printf("6: Enter the value of N for printing even natural numbers: ");
    scanf("%d", &N);
    printf("First %d even natural numbers:\n", N);
    for (i = 2; i <= 2 * N; i += 2) {
        printf("%d ", i);
    }
    printf("\n\n");

    // 7: Print the first N even natural numbers in reverse order
    printf("7: Enter the value of N for printing even natural numbers in reverse order: ");
    scanf("%d", &N);
    printf("First %d even natural numbers in reverse order:\n", N);
    for (i = 2 * N; i >= 2; i -= 2) {
        printf("%d ", i);
    }
    printf("\n\n");

    // 8: Print squares of the first N natural numbers
    printf("8: Enter the value of N for printing squares: ");
    scanf("%d", &N);
    printf("Squares of the first %d natural numbers:\n", N);
    for (i = 1; i <= N; i++) {
        printf("%d ", i * i);
    }
    printf("\n\n");

    // 9: Print cubes of the first N natural numbers
    printf("9: Enter the value of N for printing cubes: ");
    scanf("%d", &N);
    printf("Cubes of the first %d natural numbers:\n", N);
    for (i = 1; i <= N; i++) {
        printf("%d ", i * i * i);
    }
    printf("\n\n");

    // 10: Print a table of N
    printf("10: Enter the value of N for printing a table: ");
    scanf("%d", &N);
    printf("Table of %d:\n", N);
    for (i = 1; i <= 10; i++) {
        printf("%d x %d = %d\n", N, i, N * i);
    }

    return 0;
}
