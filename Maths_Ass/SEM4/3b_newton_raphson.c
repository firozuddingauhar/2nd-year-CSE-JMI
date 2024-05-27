#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001
double f(double x) {
    return exp(x) - 3 * x;
}
double df(double x) {
    return exp(x) - 3;
}
double newtonRaphson(double x) {
    while (fabs(f(x) / df(x)) > EPSILON) {
        x = x - f(x) / df(x);
    }
    return x;
}
int main() {
    double x0;
    printf("Enter initial guess: ");
    scanf("%lf", &x0);
    printf("Root of the equation: %lf\n", newtonRaphson(x0));
}

// #include <stdio.h>
// #include <math.h>

// int main() {
//     int x = 1;
//     while (fabs((exp(x) - 3 * x) / (exp(x) - 3)) > 0.0001) {
//         x -= (exp(x) - 3 * x) / (exp(x) - 3);
//     }
//     printf("%d", x);
//     return 0;
// }

