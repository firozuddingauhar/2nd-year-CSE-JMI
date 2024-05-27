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
};

void display_processes(int n, struct Process arr[]) {
    printf("PROC\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("\nP%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n",
               arr[i].ind, arr[i].at, arr[i].bt, arr[i].ct, arr[i].tat, arr[i].wt,arr[i].rt);
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

int all_processes_completed(int n, struct Process arr[]) {
    for (int i = 0; i < n; i++) {
        if (arr[i].rbt != 0)
            return 0;
    }
    return 1;
}

void round_robin(int n, struct Process arr[], int tq) {
    int current_time = 0;
    while (!all_processes_completed(n, arr)) {
        for (int i = 0; i < n; i++) {
            if (arr[i].at <= current_time && arr[i].rbt > 0) {
                if (arr[i].rbt > tq) {
                    if (arr[i].rt == INT_MAX){
                    arr[i].rt = current_time - arr[i].at;}
                    current_time += tq;
                    arr[i].rbt -= tq;
                     printf("P%d | %d |", arr[i].ind, current_time);
                } else {
                    current_time += arr[i].rbt;
                    arr[i].rbt = 0;
                    arr[i].ct = current_time;
                     printf("P%d | %d |", arr[i].ind, current_time);
                    arr[i].tat = arr[i].ct - arr[i].at;
                    arr[i].wt = arr[i].tat - arr[i].bt;
                }
            }
        }
    }
        printf("\n");
}

int main() {
    int n, tq;
    printf("Enter the number of Processes:\n");
    scanf("%d", &n);
    printf("Enter the time quantum:\n");
    scanf("%d", &tq);
    struct Process arr[MAX_PROCESSES];
    for (int i = 0; i < n; i++) {
        printf("Enter Arrival Time and Burst Time of Process %d:\n", i + 1);
        scanf("%d %d", &arr[i].at, &arr[i].bt);
        arr[i].ind = i + 1;
        arr[i].rbt = arr[i].bt;
        arr[i].rt = INT_MAX;
    }

    round_robin(n, arr, tq);
    display_processes(n, arr);
    calculate_averages(n, arr);

    return 0;
}
