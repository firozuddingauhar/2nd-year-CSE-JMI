#include <stdio.h>
#define MAX_SIZE 15
void generateMagicSquare(int n) {
    int magicSquare[MAX_SIZE][MAX_SIZE];

    // Initialize all cells with 0
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            magicSquare[i][j] = 0;
        }
    }

    // Initialize position for 1
    int row = 0, col = n / 2, num = 1;

    // One by one put all values in the magic square
    while (num <= n * n) {
        if (magicSquare[row][col] == 0) {
            magicSquare[row][col] = num;
            num++;
        }
        row--;
        col++;
        if (row == -1)
            row = n - 1;
        if (col == n)
            col = 0;

        if (magicSquare[row][col] != 0) {
            row++;
            col--;
            if (row == -1)
                row = n - 1;
            if (col == n)
                col = 0;
            row++;
        }
    }

    // Print the magic square
    printf("The Magic Square for n=%d:\nSum of each row or column %d:\n\n", n, n * (n * n + 1) / 2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%3d ", magicSquare[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    printf("Enter the size of magic square (odd number): ");
    scanf("%d", &n);
    if (n % 2 == 0 || n > MAX_SIZE || n < 1) {
        printf("Please enter a valid odd number less than or equal to %d.\n", MAX_SIZE);
        return 1;
    }

    generateMagicSquare(n);

    return 0;
}
