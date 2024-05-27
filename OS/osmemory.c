#include <stdio.h>
#define MAXBLOCKS 69

void sort(int arr[], int n) {  
    int i, j;  
    for (i = 0; i < n - 1; i++) {  
        for (j = 0; j < n - i - 1; j++) {  
            if (arr[j] > arr[j + 1]) {  
            int temp = arr[j];  
            arr[j] = arr[j + 1];  
            arr[j + 1] = temp;  
            }  
        }  
    }  
} 

void firstFit(int blockSize[], int m, int processSize[], int n){
    int sum = 0;
    for (int i = 0; i < m; i++){
        int j = 0;
        while (j < n){
            if (processSize[i] <= blockSize[j]){
                printf("P %d ----> Block %d \n", i+1, j+1);
                sum += blockSize[j] - processSize[i];
                blockSize[j] = 0;
                break;
            }
            j++;
        }
    }
    printf("Total internal fragmentation = %d\n", sum);
    sum = 0;
    for (int i = 0; i < m; i++){
        sum += blockSize[i];
    }
    printf("Total external fragmentation = %d", sum);
}

void nexttFit(int blockSize[], int m, int processSize[], int n){
    int sum = 0;
    int j = 0;
    for (int i = 0; i < m; i++){
        while (j < n){
            if (processSize[i] <= blockSize[j]){
                printf("P %d ----> Block %d \n", i+1, j+1);
                sum += blockSize[j] - processSize[i];
                blockSize[j] = 0;
                break;
            }
            j++;
        }  
    }
    printf("Total internal fragmentation = %d\n", sum);
    sum = 0;
    for (int i = 0; i < m; i++){
        sum += blockSize[i];
    }
    printf("Total external fragmentation = %d", sum);
}

void bestFit(int blockSize[], int m, int processSize[], int n){
    sort(blockSize, m);
    int sum = 0;
    for (int i = 0; i < m; i++){
        int j = 0;
        while (j < n){
            if (processSize[i] <= blockSize[j]){
                printf("P %d ----> Block %d \n", i+1, j+1);
                sum += blockSize[j] - processSize[i];
                blockSize[j] = 0;
                break;
            }
            j++;
        }
    }
    printf("Total internal fragmentation = %d\n", sum);
    sum = 0;
    for (int i = 0; i < m; i++){
        sum += blockSize[i];
    }
    printf("Total external fragmentation = %d", sum);
}

void bestFit(int blockSize[], int m, int processSize[], int n){
    sort(blockSize, m);
    int sum = 0;
    for (int i = 0; i < m; i++){
        int j = m - 1;
        while (0 <= j){
            if (processSize[i] <= blockSize[j]){
                printf("P %d ----> Block %d \n", i+1, j+1);
                sum += blockSize[j] - processSize[i];
                blockSize[j] = 0;
                break;
            }
            j--;
        }
    }
    printf("Total internal fragmentation = %d\n", sum);
    sum = 0;
    for (int i = 0; i < m; i++){
        sum += blockSize[i];
    }
    printf("Total external fragmentation = %d", sum);
}

int main() {
    int m; // number of blocks in the memory
    int n; // number of processes in the input queue

    printf("Enter the number of blocks in memory: ");
    scanf("%d", &m);

    int blockSize[MAXBLOCKS];
    printf("Enter the size of each block: ");
    for(int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int processSize[MAXBLOCKS];
    printf("Enter the size of each process: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }

    firstFit(blockSize, m, processSize, n);

    nexttFit(blockSize, m, processSize, n);

    bestFit(blockSize, m, processSize, n);

    return 0;
}