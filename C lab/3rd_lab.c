#include <stdio.h>

int incert(int array[], int size, int element, int position)
{
        int i;
        for (i = size; i >= position; i--)
        {
                array[i + 1] = array[i];
        }
        array[position] = element;
}

int delete_(int array[], int size, int position)
{
        int i;
        for (i = position; i <= size - 1; i++)
        {
                array[i] = array[i + 1];
        }
}

int print_array(int array[], int size)
{
        int i;
        for (i = 0; i < size; i++)
        {
                printf("%d ", array[i]);
        }
}

int main()
{
        int size, array[69], i, choice, element, position;
        printf("enter size of array");
        scanf("%d", &size);
        printf("enter elements of array");
        for (i = 0; i < size; i++)
        {
                scanf("%d", &array[i]);
        }

        printf("\nenter choice\n");
        printf("1) incert element at begining\n");
        printf("2) incert element at end\n");
        printf("3) incert element at given position\n");
        printf("4) delete element at begining\n");
        printf("5) delete element at end\n");
        printf("6) delete element at given position\n");
        printf("7) Exict\n");
        while (1)
        {
                scanf("%d", &choice);

                if (choice == 1)
                {
                        printf("enter element you want to incert\n");
                        scanf("%d", &element);

                        incert(array, size, element, 0);
                        size++;
                        print_array(array, size);
                }
                if (choice == 2)
                {
                        printf("enter element you want to incert\n");
                        scanf("%d", &element);

                        incert(array, size, element, size);
                        size++;
                        print_array(array, size);
                }
                if (choice == 3)
                {
                        printf("enter element you want to incert\n");
                        scanf("%d", &element);
                        printf("enter position where you want to incert the element\n");
                        scanf("%d", &position);

                        incert(array, size, element, position);
                        size++;
                        print_array(array, size);
                }
                if (choice == 4)
                {
                        printf("deleting element at begining\n");

                        delete_(array, size, 0);
                        size--;
                        print_array(array, size);
                }
                if (choice == 5)
                {
                        printf("deleting element at end\n");

                        delete_(array, size, size);
                        size--;
                        print_array(array, size);
                }
                if (choice == 6)
                {
                        printf("enter position you want to delete");
                        scanf("%d", &position);
                        printf("deleting element at end\n");

                        delete_(array, size, position);
                        size--;
                        print_array(array, size);
                }
                if (choice == 7)
                {
                        break;
                }
                printf("\n");
        }
}