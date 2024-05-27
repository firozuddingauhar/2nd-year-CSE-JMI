#include <stdio.h>
#include <math.h>
double sineSeries(double x, int n) {
    double sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += (pow(-1, i) * pow(x, 2 * i + 1)) / tgamma(2 * i + 2);
    }
    return sum;
}
double cosineSeries(double x, int n) {
    double sum = 0;
    int i;
    for (i = 0; i < n; i++) {
        sum += (pow(-1, i) * pow(x, 2 * i)) / tgamma(2 * i + 1);
    }
    return sum;
}
int main() {
    double angle;
    int terms;

    printf("Enter the angle in degrees: ");
    scanf("%lf", &angle);
    printf("Enter the number of terms: ");
    scanf("%d", &terms);

    double radians = angle * 3.141592653589793 / 180.0;

    double sin_result = sineSeries(radians, terms);

    printf("Sine of %.2lf degrees using %d terms is: %.6lf\n", angle, terms, sin_result);

    double cos_result = cosineSeries(radians, terms);

    printf("Cosine of %.2lf degrees using %d terms is: %.6lf\n", angle, terms, cos_result);

    return 0;
}