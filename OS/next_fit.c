#include <stdio.h>

// Function to allocate memory to blocks as per Next Fit algorithm
void nextFit(int blockSize[], int m, int processSize[], int n) {
    int allocation[n]; // Stores block id of the block allocated to a process
    int i, j;
    int lastAllocated = 0; // Index of the last allocated block

    // Initially no block is assigned to any process
    for(i = 0; i < n; i++) {
        allocation[i] = -1;
    }

    int internalFragmentation = 0;
    int externalFragmentation = 0;

    // pick each process and find suitable blocks according to its size and assign to it
    for (i = 0; i < n; i++) { // here, n -> number of processes
        // Start searching for a block from the last allocated block
        for (j = lastAllocated; j < m; j++) { // here, m -> number of blocks
            if (blockSize[j] >= processSize[i]) {
                // allocating block j to the ith process
                allocation[i] = j;
                // Reduce available memory in this block
                blockSize[j] -= processSize[i];
                // Calculate internal fragmentation for the allocated block
                internalFragmentation += blockSize[j];
                // Update the index of the last allocated block
                lastAllocated = j + 1;
                break; // Go to the next process in the queue
            }
        }
        // If a block is not found till the end, start searching from the beginning
        if (allocation[i] == -1) {
            for (j = 0; j < lastAllocated; j++) {
                if (blockSize[j] >= processSize[i]) {
                    // allocating block j to the ith process
                    allocation[i] = j;
                    // Reduce available memory in this block
                    blockSize[j] -= processSize[i];
                    // Calculate internal fragmentation for the allocated block
                    internalFragmentation += blockSize[j];
                    // Update the index of the last allocated block
                    lastAllocated = j + 1;
                    break; // Go to the next process in the queue
                }
            }
        }
        // If no block is found, it's external fragmentation
        if (allocation[i] == -1) {
            externalFragmentation += processSize[i];
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

    printf("Internal Fragmentation: %d\n", internalFragmentation);
    printf("External Fragmentation: %d\n", externalFragmentation);
}

// Driver code
int main() {
    int m; // number of blocks in the memory
    int n; // number of processes in the input queue

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

    nextFit(blockSize, m, processSize, n);

    return 0;
}
