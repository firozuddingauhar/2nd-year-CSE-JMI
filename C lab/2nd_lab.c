#include <stdio.h>

void printHelicalH(){
    // int arr[4][4];
     int arr[4][4] = {{1, 2, 3, 4},
                      {5, 6, 7, 8},
                      {9, 1, 2, 3},
                      {4, 5, 6, 7}};
    // printf("Enter elements in the matrix of arder 4*4\n");
    // for(int i=0;i<4;i++){
    //     for(int j=0;j<4;j++){
    //         scanf("%d",&arr[i][j]);
    //     }
    // }
    printf("\n");
    printf("\n");
    int count=0,minrow=0,mincol=0,maxrow=3,maxcol=3;
    while(minrow<=maxrow){
        for(int j=mincol;j<=maxrow;j++){
            printf("%d ",arr[minrow][j]);
        }
        minrow++;
        
        printf("\n");
        for(int j=maxcol;j>=mincol;j--){
            printf("%d ",arr[minrow][j]);
        }
        printf("\n");
        minrow++;
    }

}

void countFrequency(int arr[], int size) {
    printf("Frequency of each element in the array:\n");
    for (int i = 0; i < size; i++) {
        if (arr[i] != -1) {
            int count = 1;
            for (int j = i + 1; j < size; j++) {
                if (arr[i] == arr[j]) {
                    count++;
                    arr[j] = -1; 
                }
            }
            printf("%d occurs %d times\n", arr[i], count);
        }
    }
}

void countDuplicatesAndPrintUnique(int arr[], int size) {
    int countDuplicates = 0;

    printf("Unique elements in the array:\n");
    for (int i = 0; i < size; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                break;
            }
        }
        if (i == j) {
            printf("%d ", arr[i]);
        } else {
            countDuplicates++;
        }
    }
    printf("\nTotal number of duplicates: %d\n", countDuplicates);
}

void mergeArrays(int arr1[], int arr2[], int size) {
    int merged[size * 2];
    int k = 0;

    for (int i = 0; i < size; i++) {
        merged[k++] = arr1[i];
        merged[k++] = arr2[i];
    }

    for (int i = 0; i < size * 2 - 1; i++) {
        for (int j = i + 1; j < size * 2; j++) {
            if (merged[i] < merged[j]) {
                int temp = merged[i];
                merged[i] = merged[j];
                merged[j] = temp;
            }
        }
    }

    printf("Merged array in descending order:\n");
    for (int i = 0; i < size * 2; i++) {
        printf("%d ", merged[i]);
    }
}

int main() {

    printHelicalH();

    int arr[] = {3, 5, 2, 7, 5, 8, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    countFrequency(arr, size);

    int arr1[] = {3, 5, 2, 7, 5};
    int arr2[] = {8, 2, 3, 4, 6};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    countDuplicatesAndPrintUnique(arr1, size);
    mergeArrays(arr1, arr2, size1);

    return 0;
}
