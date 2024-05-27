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

void priority_non_preemptive(int n, struct Process arr[]) {
    int current_time = 0;
    int completed_processes = 0;
    
    while (completed_processes < n) {
        int lowest_priority_index = -1;
        int lowest_priority = INT_MAX;
        
        for (int i = 0; i < n; i++) {
            if (arr[i].at <= current_time && arr[i].rbt != INT_MAX) {
                if (arr[i].priority < lowest_priority) {
                    lowest_priority = arr[i].priority;
                    lowest_priority_index = i;
                }
            }
        }
        
        if (lowest_priority_index != -1) {
            current_time += arr[lowest_priority_index].bt;
            arr[lowest_priority_index].ct = current_time;
            arr[lowest_priority_index].rbt = INT_MAX;
            arr[lowest_priority_index].tat = arr[lowest_priority_index].ct - arr[lowest_priority_index].at;
            arr[lowest_priority_index].wt = arr[lowest_priority_index].tat - arr[lowest_priority_index].bt;
            completed_processes++;
            
            printf("P%d | %d |", arr[lowest_priority_index].ind, current_time);
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

    priority_non_preemptive(n, arr);
    display_processes(n, arr);
    calculate_averages(n, arr);

    return 0;
}
