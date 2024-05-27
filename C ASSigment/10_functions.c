#include <stdio.h>

// Function to calculate the area of a circle
double CircleArea(double radius) {
    return 3.14159265359 * radius * radius;
}

// Function to calculate simple interest
double SimpleInterest(double principal, double rate, double time) {
    return (principal * rate * time) / 100;
}

// Function to check whether a given number is even or odd
int isEven(int num) {
    return (num % 2 == 0) ? 1 : 0;
}

// Function to print first N natural numbers
void NaturalNumbers(int N) {
    for (int i = 1; i <= N; i++) {
        printf("%d ", i);
    }
    printf("\n\n");
}

// Function to print first N odd natural numbers
void OddNumbers(int N) {
    for (int i = 1; i <= N; i++) {
        printf("%d ", 2 * i - 1);
    }
    printf("\n\n");
}

// Function to calculate the factorial of a number
int Factorial(int num) {
    if (num == 0 || num == 1) {
        return 1;
    }
    int factorial = 1;
    for (int i = 2; i <= num; i++) {
        factorial *= i;
    }
    return factorial;
}

// Function to calculate the number of combinations (n choose 1)
int Combinations(int n, int r) {
    int numerator = Factorial(n);
    int denominator = Factorial(r) * Factorial(n - r);
    return numerator / denominator;
}

// Function to calculate the number of arrangements (n permute r)
int Arrangements(int n, int r) {
    return Factorial(n) / Factorial(n - r);
}

// Function to check whether a given number contains a given digit or not
int containsDigit(int number, int digit) {
    while (number > 0) {
        if (number % 10 == digit) {
            return 1;
        }
        number /= 10;
    }
    return 0;
}

// Function to print all prime factors of a given number
void PrimeFactors(int number) {
    int divisor = 2;
    while (number > 1) {
        if (number % divisor == 0) {
            printf("%d ", divisor);
            number /= divisor;
        } else {
            divisor++;
        }
    }
    printf("\n");
}

int main() {
    double circleRadius, principalAmount, interestRate, timePeriod;
    int N, num, factNum, combinationsN, arrangementsN, combinationsR, arrangementsR, containsDigitNumber, digitToCheck, primeFactorNumber;

    printf("Enter the radius of the circle: ");
    scanf("%lf", &circleRadius);
    printf("Area of a circle with radius %.2lf: %.2lf\n\n", circleRadius, CircleArea(circleRadius));

    printf("Enter the principal amount: ");
    scanf("%lf", &principalAmount);
    printf("Enter the interest rate (in percentage): ");
    scanf("%lf", &interestRate);
    printf("Enter the time period (in years): ");
    scanf("%lf", &timePeriod);
    printf("Simple interest with principal %.2lf, rate %.2lf%%, and time %.2lf years: %.2lf\n\n"
    , principalAmount, interestRate, timePeriod, SimpleInterest(principalAmount, interestRate, timePeriod));

    printf("Enter N for natural numbers: ");
    scanf("%d", &N);
    printf("First %d natural numbers: ", N);
    NaturalNumbers(N);

    printf("First %d odd natural numbers: ", N);
    OddNumbers(N);

    printf("Enter a number to check if it's even or odd: ");
    scanf("%d", &num);
    printf("Is %d even? %s\n\n", num, isEven(num) ? "Yes" : "No");

    printf("Enter a number to calculate its factorial: ");
    scanf("%d", &factNum);
    printf("Factorial of %d: %d\n\n", factNum, Factorial(factNum));

    printf("Enter n and r for combinations (n choose r): ");
    scanf("%d", &combinationsN);
    scanf("%d", &combinationsR);
    printf("Number of combinations of %d items chosen 1 at a time: %d\n\n", combinationsN, Combinations(combinationsN, combinationsR));

    printf("Enter n and r for arrangements (n permute r): ");
    scanf("%d", &arrangementsN);
    scanf("%d", &arrangementsR);
    printf("Number of arrangements of %d items chosen %d at a time: %d\n\n", arrangementsN, arrangementsN, Arrangements(arrangementsN, arrangementsR));

    printf("Enter a number to check for a specific digit: ");
    scanf("%d", &containsDigitNumber);
    printf("Enter a digit to check in the number: ");
    scanf("%d", &digitToCheck);
    printf("Does %d contain the digit %d? %s\n\n", containsDigitNumber, digitToCheck, containsDigit(containsDigitNumber, digitToCheck) ? "Yes" : "No");


    printf("Enter a number to find its prime factors: ");
    scanf("%d", &primeFactorNumber);
    printf("Prime factors of %d: ", primeFactorNumber);
    PrimeFactors(primeFactorNumber);

    return 0;
}
