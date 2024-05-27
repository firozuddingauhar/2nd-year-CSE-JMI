#include <stdio.h>
int main() {
    float a[10][10] = {{1.2, 2.1, 4.2},
                       {5.3, 6.1, 4.7},
                       {9.2, 8.3, 1}};
    float b[10] = {9.9, 21.6, 15.2}, x[10] = {0, 0, 0}, y[10];
    int n = 3, q = 10;
    while (q > 0) {
        for (int i = 0; i < n; i++) {
            y[i] = (b[i] / a[i][i]);
            for (int j = 0; j < n; j++) {
                if (j != i){
                y[i] -= ((a[i][j] / a[i][i]) * x[j]);
                x[i] = y[i];
                }
            }
            printf("\nx[%d] = %f ", i + 1, y[i]);
        }
        printf("\n");
        q--;
    }
}
