#include <stdio.h>
void matrixMultiplication(int mat1[][3], int mat2[][3], int res[][3], int rows1, int cols1, int cols2) {
    for (int i = 0; i < rows1; i++) {
        for (int j = 0; j < cols2; j++) {
            res[i][j] = 0;
            for (int k = 0; k < cols1; k++) {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
}
void displayMatrix(int mat[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", mat[i][j]);
        }
        printf("\n");
    }
}
int main() {
    int mat1[3][3] = {{1, 2, 3},
                     {4, 5, 6},
                     {7, 8, 9}};
    int mat2[3][3] = {{9, 8, 7},
                     {6, 5, 4},
                     {3, 2, 1}};
    int res[3][3];
    int rows1 = 3, cols1 = 3, rows2 = 3, cols2 = 3;

    matrixMultiplication(mat1, mat2, res, rows1, cols1, cols2);

    printf("Resultant matrix after multiplication:\n");
    displayMatrix(res, rows1, cols2);

    return 0;
}
