#include <stdio.h>

int main()
{
    int i, j, rows;

    // Pattern 1
    printf("\nPattern 1:\n");
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 2
    printf("\nPattern 2:\n");
    rows = 5;
    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= rows - i; j++)
        {
            printf(" ");
        }
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 3
    printf("\nPattern 3:\n");
    for (i = 5; i >= 1; i--)
    {
        for (j = 1; j <= i; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 4
    printf("\nPattern 4:\n");
    for (i = 1; i <= 5; i++)
    {
        for (j = 1; j < i; j++)
        {
            printf(" ");
        }
        for (j = 5; j >= i; j--)
        {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 5
    printf("\nPattern 5:\n");
    rows = 5;
    for (i = 1; i <= rows; i++)
    {
        for (j = 1; j <= rows - i; j++)
        {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 6
    printf("\nPattern 6:\n");
    rows = 5;
    for (i = rows; i >= 1; i--)
    {
        for (j = 1; j <= rows - i; j++)
        {
            printf(" ");
        }
        for (j = 1; j <= 2 * i - 1; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    // Pattern 7
    printf("\nPattern 7:\n");
    rows = 5;

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < rows - i; j++)
        {
            printf("*");
        }
        for (int k = 0; k < 2 * i; k++)
        {
            printf(" ");
        }
        for (int l = 0; l < rows - i; l++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
