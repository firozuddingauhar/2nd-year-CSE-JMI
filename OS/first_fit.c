 #include <stdio.h>

// Function to allocate memory to 
// blocks as per First fit algorithm 
void firstFit(int blockSize[], int m, int processSize[], int n) {
    int i, j;
    // Stores block id of the 
    // block allocated to a process
    int allocation[n];
    // Initially no block is assigned to any process
    for(i = 0; i < n; i++) {
        allocation[i] = -1;
    }
    // pick each process and find suitable blocks 
    // according to its size and assign to it
    for (i = 0; i < n; i++) { // here, n -> number of processes
        for (j = 0; j < m; j++) { // here, m -> number of blocks
            if (blockSize[j] >= processSize[i]) {
                // allocating block j to the ith process
                allocation[i] = j;
                // Reduce available memory in this block.
                // Check for internal fragmentation
                if (blockSize[j] > processSize[i]) {
                    int internal_fragmentation = blockSize[j] - processSize[i];
                    printf("Internal Fragmentation in Block %d: %d\n", j + 1, internal_fragmentation);
                }
                blockSize[j] -= processSize[i];
                break; // go to the next process in the queue
            }
        }
        if (allocation[i] == -1) {
            printf("Process %d not allocated.\n",i+1);
            printf("External Fragmentation is %d:\n",processSize[i]);
        }
    }
    printf("\nProcess No.\tProcess Size\tBlock no.\n"); 
    for (int i = 0; i < n; i++) 
    { 
        printf(" %i\t\t\t", i+1); 
        printf("%i\t\t\t\t", processSize[i]); 
        if (allocation[i] != -1) 
            printf("%i", allocation[i] + 1); 
        else
            printf("Not Allocated"); 
        printf("\n"); 
    }
    // Calculate total external fragmentation
    int totalFragmentation = 0;
    for (i = 0; i < m; i++) {
        if (blockSize[i] > 0) {
            totalFragmentation += blockSize[i];
        }
    }
    printf("Total Fragmentation: %d\n", totalFragmentation);
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

    firstFit(blockSize, m, processSize, n);

    return 0;
}
