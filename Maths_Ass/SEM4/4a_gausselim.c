#include <stdio.h>
#define N 4
void gaussElimination(float A[N][N+1]) {
    int i, j, k;
    for (i = 0; i < N; i++) {
        for (j = i + 1; j < N; j++) {
            float ratio = A[j][i] / A[i][i];
            for (k = 0; k <= N; k++) {
                A[j][k] -= ratio * A[i][k];
            }
        }
    }
    float x[N];
    for (i = N - 1; i >= 0; i--) {
        x[i] = A[i][N];
        for (j = i + 1; j < N; j++) {
            x[i] -= A[i][j] * x[j];
        }
        x[i] /= A[i][i];
    }
    printf("Solution:\n");
    for (i = 0; i < N; i++) {
        printf("x[%d] = %f\n", i, x[i]);
    }
}
int main() {
    float A[N][N+1] = {{10, -2, -1, -1, 3},
                       {-2, 10, -1, -1, 15},
                       {-1, -1, 10, -2, 27},
                       {-1, -1, -2, 10, -9}};

    gaussElimination(A);
}
