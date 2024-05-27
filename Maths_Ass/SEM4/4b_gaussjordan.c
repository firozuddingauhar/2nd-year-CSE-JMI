#include <stdio.h>
#define N 4
void gaussJordan(float matrix[N][N+1]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i != j) {
                float ratio = matrix[j][i] / matrix[i][i];
                for (int k = 0; k <= N; k++) {
                    matrix[j][k] -= ratio * matrix[i][k];
                }
            }
        }
    }
    printf("Solution:\n");
    for (int i = 0; i < N; i++) {
        printf("x%d = %.2f\n", i+1, matrix[i][N] / matrix[i][i]);
    }
}
int main() {
    float matrix[N][N+1] = {{10, -2, -1, -1, 3},
                       {-2, 10, -1, -1, 15},
                       {-1, -1, 10, -2, 27},
                       {-1, -1, -2, 10, -9}};
    gaussJordan(matrix);
}
