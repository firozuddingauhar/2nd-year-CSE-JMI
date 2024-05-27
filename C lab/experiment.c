#include <stdio.h>
void swap(int *p, int *q)
{
    int temp = *p;
    *p = *q;
    *q = temp;
}
void sort(int arr[], int n, int opt)
{
    int min = arr[0];
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (opt == 1 && arr[i] < arr[j])
            {
                swap(&arr[i], &arr[j]);
                printf("sorted array in descending order is.\n");
            }
            if (opt == 2 && arr[i] > arr[j])
            {
                swap(&arr[i], &arr[j]);
                printf("sorted array in ascending order is.\n");
            }
        }
    }
    for (int i = 0; i < n; i++)
    {

        printf("%d ", arr[i]);
    }
    printf("\n");
}
void display(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    int n, opt;
    printf("Enter the size of array: ");
    scanf("%d", &n);
    int arr[100];
    printf("Enter the element of array: \n ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    while (1)
    {
        printf("select any one option \nEnter 1 for assending order \nEnter 2for descending order \nEnter 3 for Display\nEnter 4 for exit \n");

        scanf("%d", &opt);
        if (opt == 1)
        {
            sort(arr, n, opt);
        }
        else if (opt == 2)
        {
            sort(arr, n, opt);
        }
        else if (opt == 3)
        {
            display(arr, n);
        }
        else if (opt == 4)
            return 0;
    }
}