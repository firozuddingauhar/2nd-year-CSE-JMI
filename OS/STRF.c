#include <stdio.h>

#define MAX_PROCESSES 10
#define INT_MAX 2147483647

typedef struct {
    int pid;            
    int arrival_time;   
    int burst_time;     
    int remaining_time; 
    int completion_time;
    int waiting_time;   
    int turnaround_time;
} Process;

int findShortestRemainingTime(Process processes[], int n, int current_time) {
    int shortest_job_index = -1;
    int shortest_remaining_time = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (processes[i].arrival_time <= current_time && processes[i].remaining_time < shortest_remaining_time && processes[i].remaining_time > 0) {
            shortest_job_index = i;
            shortest_remaining_time = processes[i].remaining_time;
        }
    }

    return shortest_job_index;
}

void calculateTimes(Process processes[], int n) {
    int current_time = 0;
    int completed_processes = 0;

    while (completed_processes < n) {
        int shortest_job_index = findShortestRemainingTime(processes, n, current_time);
        if (shortest_job_index == -1) {
            current_time++; 
            continue;
        }

        Process *current_process = &processes[shortest_job_index];
        current_process->remaining_time--;
        current_time++;

        if (current_process->remaining_time == 0) {
            current_process->completion_time = current_time;
            completed_processes++;
        }
    }
    for (int i = 0; i < n; i++) {
        processes[i].turnaround_time = processes[i].completion_time - processes[i].arrival_time;
        processes[i].waiting_time = processes[i].turnaround_time - processes[i].burst_time;
    }
}


int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    Process processes[MAX_PROCESSES];

    for (int i = 0; i < n; i++) {
        printf("Enter arrival time and burst time for process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].pid = i + 1;
        processes[i].remaining_time = processes[i].burst_time;
        processes[i].completion_time = 0;
        processes[i].waiting_time = 0;
        processes[i].turnaround_time = 0;
    }

    calculateTimes(processes, n);

    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].pid, processes[i].arrival_time, processes[i].burst_time, processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time);
    }

    return 0;
}
