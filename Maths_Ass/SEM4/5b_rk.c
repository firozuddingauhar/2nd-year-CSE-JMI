#include <stdio.h>
double f(double x, double y, double z) { return x + z; }
double g(double x, double y, double z) { return x - y * y; }
double rungeKutta(double x0, double y0, double z0, double h, double xn) {
    double k1, k2, k3, k4, l1, l2, l3, l4, y = y0, z = z0;
    while (x0 < xn) {
        k1 = h * f(x0, y, z0);
        l1 = h * g(x0, y, z0);
        k2 = h * f(x0 + 0.5 * h, y + 0.5 * k1, z0 + 0.5*l1);
        l2 = h * g(x0 + 0.5 * h, y + 0.5 * k1, z0 + 0.5*l1);
        k3 = h * f(x0 + 0.5 * h, y + 0.5 * k2, z0 + 0.5*l2);
        l3 = h * g(x0 + 0.5 * h, y + 0.5 * k2, z0 + 0.5*l2);
        k4 = h * f(x0 + h, y + k3, z0 + l3);
        l4 = h * g(x0 + h, y + k3, z0 + l3);
        y = y + (1.0 / 6.0) * (k1 + 2 * k2 + 2 * k3 + k4);
        z = z + (1.0 / 6.0) * (l1 + 2 * l2 + 2 * l3 + l4);
        x0 = x0 + h;
    }printf("y = %lf, z = %lf",y ,z);
}
int main() {
    double x0 = 0, y0 = 2, z0 = 1, xn =0.1, h = 0.1;
    rungeKutta(x0, y0, z0, h, xn);
}
