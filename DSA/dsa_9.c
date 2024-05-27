#include <stdio.h>
#include <math.h>

int main()
{
    int size, i, j, k = 0, l;
    printf("Name: Firoz Uddin Gauhar\n");
    printf("Roll no: 22BCS041\n\n");;
    printf("Enter size of tree\n");
    scanf("%d", &size);
    int height = log2(size);
    int tree[512];

    for (i = 0; i < size; i++){
        printf("Enter element %d:", i + 1);
        scanf("%d", &tree[i]);
    }

    printf("The Complete Binary Tree is :\n");
    for (i = 0; i <= height; i++){
        for (j = 0; j < pow(2, height - i) - 1; j++){
            printf(" ");
        }
        for (j = 0; j < pow(2, i); j++){
            if (k >= size){
                break;
            }
            else{
                printf("%d", tree[k]);
                if (i >= 1){
                    for (l = 0; l < pow(2, height - i); l++){

                        printf(" ");
                    }
                }
                k++;
            }
        }
        printf("\n");
    }
}