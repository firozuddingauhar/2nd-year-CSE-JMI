#include <stdio.h>
int main(void) {
    float x[10], y[10];
    int n, q = 0, i = 0, j = 0, k;
    printf("Enter number of data points : ");
    scanf("%d", &n);
    printf("Enter data points x[i], y[i]\n");
    for (i = 0; i < n; i++) {
        scanf("%f %f", &x[i], &y[i]);
    }
    float sum_x = 0, sum_y = 0, sum_xy = 0, sum_x2 = 0, sum_x3 = 0, sum_x4 = 0, sum_x2y = 0;
    for (i = 0; i < n; i++) {
        sum_x += x[i];
        sum_y += y[i];
        sum_xy += x[i] * y[i];
        sum_x2 += x[i] * x[i];
        sum_x3 += x[i] * x[i] * x[i];
        sum_x4 += x[i] * x[i] * x[i] * x[i];
        sum_x2y += x[i] * x[i] * y[i];
    }
    float a[3][4] = {{n     , sum_x , sum_x2, sum_y  },
                     {sum_x , sum_x2, sum_x3, sum_xy },
                     {sum_x2, sum_x3, sum_x4, sum_x2y}};

    for (i = 0; i < 2; i++) {  
        for (k = i + 1; k < 3; k++) {
            double t = a[k][i] / a[i][i];
            for (j = 0; j <= 3; j++) {
                a[k][j] = a[k][j] - t * a[i][j];  
            }
        }
    }
    for (i = 2; i >= 0; i--) {
        x[i] = a[i][3];  
        for (j = i + 1; j < 3; j++) {
            if (j != i) {  
                x[i] = x[i] - a[i][j] * x[j];
            }
        }
        x[i] = x[i] / a[i][i];
    }
    printf("\nThe values of the variables are as follows:\n");
    for (i = 0; i < 3; i++) {
        printf("%f\n", x[i]); 
    }
    printf("Fitted parabola: y = %fx^2 + %fx + %f\n", x[0], x[1], x[2]);
    return 0;
}
