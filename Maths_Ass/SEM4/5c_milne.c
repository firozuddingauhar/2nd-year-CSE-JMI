#include <stdio.h>
double f(double x, double y) {
    return x - y; // Example ODE: y' = x - y
}
void milne(double x0, double y0, double xn, double h) {
    double x = x0, y = y0, k1, k2, k3, k4;
    printf("x\t\t y (Milne's Method)\n");
    printf("%0.5lf\t %0.5lf\n", x, y);
    while (x < xn) {
        k1 = h * f(x, y);
        k2 = h * f(x + h/2, y + k1/2);
        k3 = h * f(x + h/2, y + k2/2);
        k4 = h * f(x + h, y + k3);
        y += (k1 + 4 * k2 + k3) / 6; // Predictor
        y += (k2 + 4 * k3 + k4) / 6; // Corrector
        x += h;
        printf("%0.5lf\t %0.5lf\n", x, y);
    }
}
int main() {
    double x0 = 0.0, y0 = 1.0, h = 0.1, xn = 1.0; 

    milne(x0, y0, xn, h);

    return 0;
}
