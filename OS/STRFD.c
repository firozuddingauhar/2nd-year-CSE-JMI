#include <stdio.h>
#include <limits.h>
#define MAX_PROCESSES 10
struct Process {
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
    int response_time;
    int remaining_burst_time;
};
void display(int n, struct Process processes[]) {
    printf("\nProcess\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\tResponse Time\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t%d\t\t%d\t\t", i + 1, processes[i].arrival_time, processes[i].burst_time);
        // if (processes[i].completion_time != INT_MAX) {
            printf("%d\t\t%d\t\t%d\t\t%d\n", processes[i].completion_time, processes[i].turnaround_time, processes[i].waiting_time, processes[i].response_time);
        // } else {
        //     printf("NA\t\tNA\t\tNA\t\tNA\n");
        // }
    }
}
void calculate_averages(int n, struct Process processes[]) {
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int total_response_time = 0;
    for (int i = 0; i < n; i++) {
        total_turnaround_time += processes[i].turnaround_time;
        total_waiting_time += processes[i].waiting_time;
        total_response_time += processes[i].response_time;
    }
    // printf("\nTotal Turnaround Time: %d\n", total_turnaround_time);
    printf("Average Turnaround Time: %.2f\n", (float)total_turnaround_time / n);
    // printf("Total Waiting Time: %d\n", total_waiting_time);
    printf("Average Waiting Time: %.2f\n", (float)total_waiting_time / n);
    // printf("Total Response Time: %d\n", total_response_time);
    printf("Average Response Time: %.2f\n", (float)total_response_time / n);
}

void srtf(int n, struct Process processes[]) {
    int current_time = 0;
    int remaining_processes = n;
    printf("Gantt Chart:\n");
    while (remaining_processes > 0) {
        int min_index = -1, min_value = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (processes[i].arrival_time <= current_time && processes[i].remaining_burst_time < min_value && processes[i].remaining_burst_time > 0) {
                min_value = processes[i].remaining_burst_time;
                min_index = i;
            }
        }
        if (min_index != -1) {
            printf("P%d |",min_index + 1);
            if (processes[min_index].response_time == INT_MAX) {
                processes[min_index].response_time = current_time - processes[min_index].arrival_time;
            }
            current_time++;
            processes[min_index].remaining_burst_time--;
            if (processes[min_index].remaining_burst_time == 0) {
                processes[min_index].completion_time = current_time;
                processes[min_index].turnaround_time = processes[min_index].completion_time - processes[min_index].arrival_time;
                processes[min_index].waiting_time = processes[min_index].turnaround_time - processes[min_index].burst_time;
                remaining_processes--;
            }
        } else {
            current_time++;
        }
    }
    display(n, processes);
}

int main() {
    printf("Name:Firoz Uddin\nRoll: 22BCS041\n\n");

    int num_processes;
    printf("Enter the number of Processes: ");
    scanf("%d", &num_processes);

    struct Process processes[MAX_PROCESSES];
    for (int i = 0; i < num_processes; i++) {
        printf("Enter Arrival Time and Burst Time for Process %d: ", i + 1);
        scanf("%d %d", &processes[i].arrival_time, &processes[i].burst_time);
        processes[i].remaining_burst_time = processes[i].burst_time;
        processes[i].response_time = INT_MAX;
    }

    srtf(num_processes, processes);
    calculate_averages(num_processes, processes);

    return 0;
}
