#include <stdio.h>
#include <math.h>
#define EPSILON 0.00001
double bisection(double a, double b)
{
    double c;
    while ((b - a) >= EPSILON)
    {
        c = (a + b) / 2;
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}
double regulaFalsi(double a, double b)
{
    double c;
    while ((b - a) >= EPSILON)
    {
        c = (a * f(b) - b * f(a)) / (f(b) - f(a));
        if (f(c) == 0.0)
            break;
        else if (f(c) * f(a) < 0)
            b = c;
        else
            a = c;
    }
    return c;
}
double f(double x) { return 2 * x - 5; }
int main()
{
    double a, b;
    printf("Enter interval [a, b]: ");
    scanf("%lf %lf", &a, &b);
    if (f(a) * f(b) >= 0)
    {
        printf("The function does not have opposite signs at interval endpoints.\n");
        return 1;
    }
    printf("Root of the equation by bisection: %lf\n", bisection(a, b));
    printf("Root of the equation by regula falsi: %lf\n", regulaFalsi(a, b));
}
