#include <stdio.h>
double function(double x){
    return 1 / (1 + (x * x));
}
double trapezoidalRule(double a, double b, int n, double h){
    double sum = function(a) + function(b);
    for (int i = 1; i < n; i++){
        sum += 2 * function(a + i * h);
    }
    return (h / 2) * sum;
}
double simpsonsOneThirdRule(double a, double b, int n, double h){
    double sum = function(a) + function(b);
    for (int i = 1; i < n; i++){
        double x = a + i * h;
        if (i % 2 == 0)
            sum += 2 * function(x);
        else
            sum += 4 * function(x);
    }
    return (h / 3) * sum;
}
double simpsonsThreeEighthRule(double a, double b, int n, double h){
    double sum = function(a) + function(b);
    for (int i = 1; i < n; i++){
        double x = a + i * h;
        if (i % 3 == 0)
            sum += 2 * function(x);
        else
            sum += 3 * function(x);
    }
    return (3 * h / 8) * sum;
}
double boolesRule(double a, double b, int n, double h){
    double sum = 7 * (function(a) + function(b));
    for (int i = 1; i <= n - 1; i++){
        if (i % 4 == 0)
            sum += 14 * function(a + i * h);
        else if (i % 2 == 0)
            sum += 12 * function(a + i * h);
        else
            sum += 32 * function(a + i * h);
    }
    return (2 * h / 45) * sum;
}
double weddlesRule(double a, double b, int n, double h){
    double sum = function(a) + function(b);
    for (int i = 1; i <= n - 1; i++){
        if (i % 6 == 0)
            sum += 2 * function(a + i * h);
        else if (i % 6 == 3)
            sum += 6 * function(a + i * h);
        else if (i % 2 == 0)
            sum += function(a + i * h);
        else
            sum += 5 * function(a + i * h);
    }
    return (3 * h / 10) * sum;
}
int main(){
    double a, b;
    int n = 0;
    printf("Enter the lower and upper limit of integration (a  b) : ");
    scanf("%lf %lf", &a, &b);
    printf("Enter the number of intervals (n): ");
    scanf("%d", &n);
    double h = (b - a) / n;
    printf("Trapezoidal rule result: %lf\n", trapezoidalRule(a, b, n, h));
    printf("Simpson's 1/3 rule result: %lf\n", simpsonsOneThirdRule(a, b, n, h));
    printf("Simpson's 3/8 rule result: %lf\n", simpsonsThreeEighthRule(a, b, n, h));
    printf("Boole's rule result: %lf\n", boolesRule(a, b, n, h));
    printf("Weddle's rule result: %lf\n", weddlesRule(a, b, n, h));
}