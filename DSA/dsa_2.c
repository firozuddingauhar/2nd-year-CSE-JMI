#include <stdio.h>

void readMatrix(int matrix[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Element at Row %d and Column %d: ", i + 1, j + 1);
            scanf("%d", &matrix[i][j]);
        }
    }
}

void displayMatrix(int matrix[][3], int rows, int cols) {
    printf("Matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void addMatrices(int matrixA[][3], int matrixB[][3], int result[][3], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}

void multiplyMatrices(int matrixA[][3], int rowsA, int colsA,
                      int matrixB[][3], int rowsB, int colsB, int result[][3]) {
    if (colsA != rowsB) {
        printf("Matrix multiplication not possible. Columns of the first matrix must be equal to rows of the second matrix.\n");
        return;
    }

    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0;
            for (int k = 0; k < colsA; k++) {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}

int main() {
    printf("\nNAME: Firoz Uddin Gauhar\nROLL_NO: 22BCS041\n\n");

    int n, m, p, q;
    n = m = p = q = 3;//size

    int matrixA[3][3], matrixB[3][3], resultAddition[3][3], resultMultiplication[3][3];

    printf("Enter values in matrix A:\n");
    readMatrix(matrixA, n, m);

    printf("Enter values in matrix B:\n");
    readMatrix(matrixB, p, q);

    int choice;
    while (1) {
        printf("\nEnter 1 for matrix Addition\nEnter 2 for matrix Multiplication\nEnter 3 to exit\n");
        scanf("%d", &choice);

        if (choice == 1) {
            addMatrices(matrixA, matrixB, resultAddition, n, m);
            printf("The Resultant matrix after addition is:\n");
            displayMatrix(resultAddition, n, m);
        } else if (choice == 2) {
            multiplyMatrices(matrixA, n, m, matrixB, p, q, resultMultiplication);
            printf("Matrix after Multiplication is:\n");
            displayMatrix(resultMultiplication, n, q);
        } else if (choice == 3) {
            break;
        } else {
            printf("Invalid choice. Please enter a valid option.\n");
        }
    }
    return 0;
}
