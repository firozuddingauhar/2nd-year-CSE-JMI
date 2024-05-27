// C program for FIFO page replacement algorithm
#include<stdio.h> 
typedef enum { false, true } bool;
# define MAX_FRAMES 10
int main() {
    int incomingStream[] = {1, 2, 3, 4, 5, 2,3, 4, 1, 6, 7, 8, 7, 8, 9, 7, 8, 9, 5, 4, 5, 4, 2};
    int no_of_frames = 4;
    int i, j, s, pageFaults = 0, pages = sizeof(incomingStream)/sizeof(incomingStream[0]);
    bool hit;
    
    // printf("Enter number of pages: ");
    // scanf("%d", &pages);
    // printf("\nEnter reference string one by one: ");
    // for (i = 0; i < pages; i++){
    //     scanf("%d", &incomingStream[i]);
    // }
    // printf("\nEnter number of no_of_frames: ");
    // scanf("%d", &no_of_frames);
    
    printf("Incoming \t Frame 1 \t Frame 2 \t Frame 3 \t Frame 4");
    int frames[MAX_FRAMES];
    for(i = 0; i < no_of_frames; i++){
        frames[i] = -1;
    }
    for(i = 0; i < pages; i++){
        hit = false;
        for(j = 0; j < no_of_frames; j++){
            if(incomingStream[i] == frames[j]){
                hit = true;
                pageFaults--;
            }
        }
        pageFaults++;
        if((pageFaults <= no_of_frames) && (hit == false)){
            frames[i] = incomingStream[i];
        }
        else if(hit == false){
            frames[(pageFaults - 1) % no_of_frames] = incomingStream[i];
        }
        printf("\n%d\t\t",incomingStream[i]);
        for(j = 0; j < no_of_frames; j++){
            if(frames[j] != -1) printf(" %d\t\t", frames[j]);
            else printf(" - \t\t");
        }
    }
    printf("\n\nTotal Page Faults:\t%d\n", pageFaults);
}