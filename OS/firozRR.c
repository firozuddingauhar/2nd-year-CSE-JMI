#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

struct proces {
    int ind;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int rbt;
};

void display(int n, struct proces arr[]) {
    printf("PROC\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\tRT\n");
    for (int i = 0; i < n; i++) {
        printf("P%d\t\t%d\t\t%d\t\t", i + 1, arr[i].at, arr[i].bt);
        if (arr[i].ct != INT_MAX) {
            printf("%d\t\t%d\t\t%d\t\t%d", arr[i].ct, arr[i].tat, arr[i].wt, arr[i].rt);
        }
        printf("\n");
    }
}

void avg(int n, struct proces arr[]) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i].tat;
    }
    printf("\nTotal TurnAround Time is : %d\n", sum);
    printf("Average TurnAround Time is : %d/%d = %f\n", sum, n, (float)sum / n);
    sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i].wt;
    }
    printf("\nTotal Waiting Time is : %d\n", sum);
    printf("Average Waiting Time is : %d/%d = %f\n", sum, n, (float)sum / n);
}

bool check(int n, struct proces arr[]) {
    bool flag = true;
    for (int i = 0; i < n; i++) {
        if (arr[i].rbt != INT_MAX)
            flag = false;
    }
    return flag;
}

void roro(int n, struct proces arr[], int tq) {
    struct proces *qt[1000]; // Assuming a maximum of 1000 processes in the queue
    int front = 0, rear = 0;
    int atime = 0;
    while (1) {
        if (front != rear) {
            struct proces *temp = qt[front++];
            if (temp->rt == INT_MAX)
                temp->rt = atime - temp->at;
            if (temp->rbt > tq) {
                temp->rbt -= tq;
                for (int i = atime + 1; i <= atime + tq; i++) {
                    for (int j = 0; j < n; j++) {
                        if (arr[j].at == i)
                            qt[rear++] = &arr[j];
                    }
                }
                atime += tq;
                printf("P%d | %d |", temp->ind, atime);
                qt[rear++] = temp;
            } else {
                temp->ct = atime + temp->rbt;
                for (int i = atime + 1; i <= atime + temp->rbt; i++) {
                    for (int j = 0; j < n; j++) {
                        if (arr[j].at == i)
                            qt[rear++] = &arr[j];
                    }
                }
                atime += temp->rbt;
                printf("P%d | %d |", temp->ind, atime);
                temp->rbt = INT_MAX;
            }
        } else {
            if (check(n, arr)) {
                for (int i = 0; i < n; i++) {
                    arr[i].tat = arr[i].ct - arr[i].at;
                    arr[i].wt = arr[i].tat - arr[i].bt;
                }
                printf("\n");
                display(n, arr);
                return;
            }
            for (int i = 0; i < n; i++) {
                if (arr[i].at == atime)
                    qt[rear++] = &arr[i];
            }
            if (front == rear)
                atime++;
        }
    }
}

int main() {
    printf("Name : Md Masleuddin\nRoll : 21BCS028\n\n");
    int n, tq;
    printf("Enter the no of Proces :\n");
    scanf("%d", &n);
    printf("Enter the time quantum :\n");
    scanf("%d", &tq);
    struct proces arr[n];
    for (int i = 0; i < n; i++) {
        printf("Enter the Arrival Time and Burst Time of %d process :\n", i + 1);
        scanf("%d %d", &arr[i].at, &arr[i].bt);
        arr[i].ind = i + 1;
        arr[i].rbt = arr[i].bt;
        arr[i].ct = INT_MAX;
        arr[i].tat = INT_MAX;
        arr[i].wt = INT_MAX;
        arr[i].rt = INT_MAX;
    }
    printf("\n");
    roro(n, arr, tq);
    avg(n, arr);
}