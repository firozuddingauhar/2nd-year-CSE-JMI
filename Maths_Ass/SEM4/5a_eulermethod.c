#include <stdio.h>
double f(double x, double y) {
    return x + y; // Example: y' = x + y
}
void modifiedEuler(double x0, double y0, double h, double xn) {
    double y = y0, x = x0;
    printf("x\t\ty\n");
    printf("%.2f\t%.6f\n", x, y);
    while (x < xn) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h, y + k1);
        y += (k1 + k2) / 2.0;
        x += h;
        printf("%.2f\t%.6f\n", x, y);
    }
}
int main() {
    double x0 = 0.0;  // Initial value of x
    double y0 = 1.0;  // Initial value of y
    double h = 0.1;   // Step size
    double xn = 1.0;  // Final value of x

    modifiedEuler(x0, y0, h, xn);

    return 0;
}
