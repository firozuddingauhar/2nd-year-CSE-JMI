#include <stdio.h>
#include <limits.h>

#define MAX_PROCESSES 100

struct Process {
    int ind;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rbt;
    int rt;
    int priority; // New priority field
};

void display_processes(int n, struct Process arr[]) {
    printf("PROC\t\tPT\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",
               arr[i].ind,arr[i].priority, arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt);
    }
}

void calculate_averages(int n, struct Process arr[]) {
    int sum_tat = 0, sum_wt = 0;
    for (int i = 0; i < n; i++) {
        sum_tat += arr[i].tat;
        sum_wt += arr[i].wt;
    }
    printf("\nTotal Turnaround Time: %d\n", sum_tat);
    printf("Average Turnaround Time: %.2f\n", (float)sum_tat / n);
    printf("\nTotal Waiting Time: %d\n", sum_wt);
    printf("Average Waiting Time: %.2f\n", (float)sum_wt / n);
}

void priority_preemptive(int n, struct Process arr[]) {
    int current_time = 0;
    int completed_processes = 0;
    
    while (completed_processes < n) {
        int highest_priority_index = -1;
        int highest_priority = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (arr[i].at <= current_time && arr[i].rbt > 0) {
                if (arr[i].priority < highest_priority) {
                    highest_priority = arr[i].priority;
                    highest_priority_index = i;
                }
            }
        }
        
        if (highest_priority_index != -1) {
            current_time++;
            arr[highest_priority_index].rbt--;
            if (arr[highest_priority_index].rbt == 0) {
                arr[highest_priority_index].ct = current_time;
                arr[highest_priority_index].tat = arr[highest_priority_index].ct - arr[highest_priority_index].at;
                arr[highest_priority_index].wt = arr[highest_priority_index].tat - arr[highest_priority_index].bt;
                completed_processes++;
            }
            
            printf("P%d|%d|", arr[highest_priority_index].ind, current_time);
        } else {
            current_time++;
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter the number of Processes:\n");
    scanf("%d", &n);
    struct Process arr[MAX_PROCESSES];
    
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time, Burst Time, and Priority of Process %d:\n", i + 1);
        scanf("%d %d %d", &arr[i].at, &arr[i].bt, &arr[i].priority);
        arr[i].ind = i + 1;
        arr[i].rbt = arr[i].bt;
        arr[i].rt = INT_MAX;
    }

    priority_preemptive(n, arr);
    display_processes(n, arr);
    calculate_averages(n, arr);

    return 0;
}
