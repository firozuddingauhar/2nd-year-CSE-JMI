#include <stdio.h>
double newtonForwardInterpolation(double x[], double y[], int n, double value) {
    double result = 0, table[10][10];
    for (int i = 0; i < n; ++i) {
        table[i][0] = y[i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < n - i; ++j) {
            table[j][i] = table[j + 1][i - 1] - table[j][i - 1];
        }
    }
    printf("\nThe forward difference table is:\n");
    for (int i = 0; i < n; i++) { 
        printf("\n");
        for (int j = 0; j < n - i; j++) {
            printf("%.4f\t", table[i][j]);
        }
    }
    double u = (value - x[0]) / (x[1] - x[0]);
    double term = 1;
    result = table[0][0];
    for (int i = 1; i < n; ++i) {
        term *= (u - i + 1) / i;
        result += term * table[0][i];
    }
    return result;
}
double newtonBackwardInterpolation(double x[], double y[], int n, double value) {
    double result = 0, table[10][10];
    for (int i = 0; i < n; ++i) {
        table[i][0] = y[i];
    }
    for (int i = 1; i < n; ++i) {
        for (int j = n - 1; j >= i; --j) {
            table[j][i] = table[j][i - 1] - table[j - 1][i - 1];
        }
    }
    double u = (value - x[n - 1]) / (x[1] - x[0]), term = 1;
    result = table[n - 1][0];
    for (int i = 1; i < n; ++i) {
        term *= (u + i - 1) / i;
        result += term * table[n - 1][i];
    }
    return result;
}
int main() {
    int n;
    printf("Enter no of data points");
    scanf("%d",&n);
    // double x[10], y[10];
    // printf("Enter the data points in the format (x y):\n");
    // for (int i = 0; i < n; i++){
    //     scanf("%lf %lf", &x[i], &y[i]);
    // }
    double x[] = { 0,0.1,0.2,0.3,0.4,0.5,0.6 };
    double y[] = { 30.13,31.62,32.87,33.64,33.45,33.81,33.24 };
    double value;
    printf("Enter the point at which you want to interpolate: ");
    scanf("%lf", &value);

    printf("\nNewton's Forward Interpolation at x = %.1f: %.3f\n", value, newtonForwardInterpolation(x, y, n, value));

    printf("\nNewton's Backward Interpolation at x = %.1f: %.2f\n", value, newtonBackwardInterpolation(x, y, n, value));

    return 0;
}
