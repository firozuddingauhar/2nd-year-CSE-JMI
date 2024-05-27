#include <stdio.h>

// Function to allocate memory to blocks as per Best Fit algorithm
void bestFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n];
    int internalFragmentation;
    int i, j;
    for(i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    for (i = 0; i < n; i++) { 
        int bestFitIdx = -1;
        for (j = 0; j < m; j++) { 
            if (blockSize[j] >= processSize[i]) {
                if (bestFitIdx == -1 || blockSize[j] < blockSize[bestFitIdx]) {
                    bestFitIdx = j;
                }
            }
        }
        if (bestFitIdx != -1) {
            allocation[i] = bestFitIdx;
            blockSize[bestFitIdx] -= processSize[i];
            internalFragmentation += blockSize[j];
        }
    }

    printf("\nProcess No.\tProcess Size\tBlock no.\n");
    for (i = 0; i < n; i++) {
        printf(" %d\t\t\t", i + 1);
        printf("%d\t\t\t\t", processSize[i]);
        if (allocation[i] != -1) {
            printf("%d", allocation[i] + 1);
        } else {
            printf("Not Allocated");
        }
        printf("\n");
    }
    // if (allocation[i] == -1) {
    //         printf("Process %d not allocated.\n",i+1);
    //         printf("External Fragmentation is %d:\n",processSize[i]);
    //     }
    int ExternalFragmentation = 0;
    for (i = 0; i < m; i++) {
        if (blockSize[i] > 0 && blockSize[i] == -1) {
            ExternalFragmentation += blockSize[i];
        }
    }
    printf("External Fragmentation: %d\n", ExternalFragmentation);
}

int main() {
    int m; 
    int n;
    printf("Enter the number of blocks in memory: ");
    scanf("%d", &m);
    int blockSize[m];
    printf("Enter the size of each block: ");
    for(int i = 0; i < m; i++) {
        scanf("%d", &blockSize[i]);
    }
    printf("Enter the number of processes: ");
    scanf("%d", &n);
    int processSize[n];
    printf("Enter the size of each process: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
    }
    bestFit(blockSize, m, processSize, n);
    return 0;
}
