#include <stdio.h>
void dividedDifference(double x[], double y[], double diffTable[][10], int n) {
    for (int i = 0; i < n; i++) {
        diffTable[i][0] = y[i];
    }
    for (int j = 1; j < n; j++) {
        for (int i = 0; i < n - j; i++) {
            diffTable[i][j] = (diffTable[i + 1][j - 1] - diffTable[i][j - 1]) / (x[i + j] - x[i]);
        }
    }
}
double newtonInterpolation(double xi, double x[], double diffTable[][10], int n) {
    double result = 0, term = 1;
    for (int i = 0; i < n; i++) {
        result += term * diffTable[0][i];
        term *= (xi - x[i]);
    }
    return result;
}
int main() {
    double x[] = {4.0, 5.0, 7.0, 10.0, 11.0, 13.0};
    double y[] = {18.0, 100.0, 294.0, 900.0, 1210.0, 2028.0};
    int n = sizeof(x) / sizeof(x[0]);
    double xi = 8.0,  diffTable[10][10];

    dividedDifference(x, y, diffTable, n);
    for (int i = 0; i < n; i++) {
        printf("\n");
        for (int j = 0; j <= i; j++) {
            printf("%.1f\t", diffTable[i][j]);
        }
    }
    printf("\nInterpolated value at x=%.1f is %.4f\n", xi, newtonInterpolation(xi, x, diffTable, n));
}