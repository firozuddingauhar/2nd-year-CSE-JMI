#include <stdio.h>

int main() {
    int i;

    // 1: Print "MySirG" 5 times
    printf("1:\n");
    for (i = 0; i < 5; i++) {
        printf("MySirG ");
    }
    printf("\n");

    // 2: Print the first 10 natural numbers
    printf("2:\n");
    for (i = 1; i <= 10; i++) {
        printf("%d ", i);
    }
    printf("\n");

    // 3: Print the first 10 natural numbers in reverse order
    printf("3:\n");
    for (i = 10; i >= 1; i--) {
        printf("%d ", i);
    }
    printf("\n");

    // 4: Print the first 10 odd natural numbers
    printf("4:\n");
    for (i = 1; i <= 19; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    // 5: Print the first 10 odd natural numbers in reverse order
    printf("5:\n");
    for (i = 19; i >= 1; i -= 2) {
        printf("%d ", i);
    }
    printf("\n");

    // 6: Print the first 10 even natural numbers
    printf("6:\n");
    for (i = 2; i <= 20; i += 2) {
        printf("%d ", i);
    }
    printf("\n");

    // 7: Print the first 10 even natural numbers in reverse order
    printf("7:\n");
    for (i = 20; i >= 2; i -= 2) {
        printf("%d ", i);
    }
    printf("\n");

    // 8: Print squares of the first 10 natural numbers
    printf("8:\n");
    for (i = 1; i <= 10; i++) {
        printf("%d ", i * i);
    }
    printf("\n");

    // 9: Print cubes of the first 10 natural numbers
    printf("9:\n");
    for (i = 1; i <= 10; i++) {
        printf("%d ", i * i * i);
    }
    printf("\n");

    // 10: Print a table of 5
    printf("10: Table of 5\n");
    for (i = 1; i <= 10; i++) {
        printf("5 x %d = %d\n", i, 5 * i);
    }

    return 0;
}
