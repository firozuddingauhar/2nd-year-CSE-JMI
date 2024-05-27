#include <stdio.h>
#define MAXN 10
double lagrangeInterpolation(double x[], double y[], int n, double point){
    double result = 0;
    for (int i = 0; i < n; i++){
        double term = y[i];
        for (int j = 0; j < n; j++){
            if (j != i){
                term = term * (point - x[j]) / (x[i] - x[j]);
            }
        }
        result += term;
    }
    return result;
}
int main(){
    int n;
    printf("Enter the number of data points: ");
    scanf("%d", &n);
    double x[MAXN], y[MAXN], point, value;
    printf("Enter the data points in the format (x y):\n");
    for (int i = 0; i < n; i++){
        scanf("%lf %lf", &x[i], &y[i]);
    }
    printf("Enter the point at which you want to interpolate: ");
    scanf("%lf", &point);
    printf("Interpolated value at %lf is: %lf\n", point, lagrangeInterpolation(x, y, n, point));
    // printf("Enter the value at which you want to find the inverse interpolation: ");
    // scanf("%lf", &value);
    // printf("Interpolated value at %lf is: %lf\n", value, lagrangeInterpolation(y, x, n, value));
}
