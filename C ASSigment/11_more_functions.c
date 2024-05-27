#include <stdio.h>

// Function to calculate the LCM of two numbers
int calculateLCM(int a, int b) {
    int max = (a > b) ? a : b;
    while (1) {
        if (max % a == 0 && max % b == 0) {
            return max;
        }
        max++;
    }
}

// Function to calculate the HCF of two numbers
int calculateHCF(int a, int b) {
    int temp;
    while (b != 0) {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to check whether a given number is prime or not
int isPrime(int num) {
    if (num <= 1) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

// Function to find the next prime number after a given number
int findNextPrime(int num) {
    while (1) {
        num++;
        if (isPrime(num)) {
            return num;
        }
    }
}

// Function to print the first N prime numbers
void printNPrimes(int N) {
    int num = 2;
    int count = 0;
    while (count < N) {
        if (isPrime(num)) {
            printf("%d ", num);
            count++;
        }
        num++;
    }
    printf("\n\n");
}

// Function to print all prime numbers between two given numbers
void printPrimesInRange(int start, int end) {
    for (int num = start; num <= end; num++) {
        if (isPrime(num)) {
            printf("%d ", num);
        }
    }
    printf("\n\n");
}

// Function to print the first N terms of the Fibonacci series
void printNFibonacci(int N) {
    int a = 0, b = 1;
    printf("First %d terms of the Fibonacci series: ", N);
    for (int i = 0; i < N; i++) {
        printf("%d ", a);
        int temp = a + b;
        a = b;
        b = temp;
    }
    printf("\n\n");
}

// Function to calculate the square of a number
int calculateSquare(int num) {
    return num * num;
}

// Function to find the sum of the series 1!/1 + 2!/2 + 3!/3 + 4!/4 + 5!/5
double calculateSeriesSum(int N) {
    double sum = 0;
    for (int i = 1; i <= N; i++) {
        double term = 1.0;
        for (int j = 1; j <= i; j++) {
            term *= (double)j;
        }
        sum += term / (double)i;
    }
    return sum;
}

int main() {
    int num1, num2, num, N, startRange, endRange;

    printf("Enter two numbers to calculate their LCM: ");
    scanf("%d %d", &num1, &num2);
    printf("LCM of %d and %d: %d\n\n", num1, num2, calculateLCM(num1, num2));

    printf("Enter two numbers to calculate their HCF: ");
    scanf("%d %d", &num1, &num2);
    printf("HCF of %d and %d: %d\n\n", num1, num2, calculateHCF(num1, num2));

    printf("Enter a number to check if it's prime: ");
    scanf("%d", &num);
    if (isPrime(num)) {
        printf("%d is a prime number.\n\n", num);
    } else {
        printf("%d is not a prime number.\n\n", num);
    }

    printf("Enter a number to find the next prime number after it: ");
    scanf("%d", &num);
    printf("Next prime number after %d: %d\n\n", num, findNextPrime(num));

    printf("Enter N to print the first N prime numbers: ");
    scanf("%d", &N);
    printNPrimes(N);

    printf("Enter the start and end range to print prime numbers in between: ");
    scanf("%d %d", &startRange, &endRange);
    printPrimesInRange(startRange, endRange);

    printf("Enter N to print the first N terms of the Fibonacci series: ");
    scanf("%d", &N);
    printNFibonacci(N);

    printf("Enter a number to calculate its square: ");
    scanf("%d", &num);
    printf("Square of %d: %d\n\n", num, calculateSquare(num));

    printf("Enter N to calculate the sum of the series: ");
    scanf("%d", &N);
    printf("Sum of the series: %.2lf\n", calculateSeriesSum(N));

    return 0;
}
