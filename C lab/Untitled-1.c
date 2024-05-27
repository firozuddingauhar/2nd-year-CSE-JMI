#include <stdio.h>

void print_array(int array[])
{
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", array[i]);
    }
}

void add_array(int array[])
{
    int sum = 0, i;
    int *ptr1 = array;
    int *ptr2 = &sum;

    for (i = 0; i < 10; i++)
    {
        *ptr2 = *ptr1 + *ptr2;
        ptr1++;
        printf("\n%d", *ptr2);
    }
    printf("\nfinal sum is %d", *ptr2);
}

void bubble_sort(int array[])
{
    int i, j, temp;

    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < i; j++)
        {
            if (array[j] > array[j + 1])
            {
                temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
        print_array(array);
        printf("\n");
    }
    printf("sorted arrray is \n");
    print_array(array);
}

int main()
{
    int array[10] = {0, 1, 4, 7, 2, 5, 8, 3, 6, 9};

    bubble_sort(array);

    add_array(array);
}