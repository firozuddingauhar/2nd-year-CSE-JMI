#include <stdio.h>
#include <limits.h>

struct process
{
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
    int rt;
    int rbt;
};

void display(int n, struct process arr[])
{
    printf("PROC\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\tRT\n");
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d", i + 1, arr[i].at, arr[i].bt,arr[i].ct, arr[i].tat, arr[i].wt,arr[i].rt);
     
        printf("\n");
    }
}

void avg(int n, struct process arr[])
{
    int sum_tat = 0;
    int sum_wt = 0;
    for (int i = 0; i < n; i++)
    {
        sum_tat += arr[i].tat;
        sum_wt += arr[i].wt;
    }
    printf("\nTotal TurnAround Time is : %d\n", sum_tat);
    printf("Average TurnAround Time is : %d/%d = %.2f\n", sum_tat, n, (float)sum_tat / (float)n);
    printf("\nTotal Waiting Time is : %d\n", sum_wt);
    printf("Average Waiting Time is : %d/%d = %.2f\n", sum_wt, n, (float)sum_wt / (float)n);
}

int check(int n, struct process arr[])
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i].rbt != INT_MAX)
            return 0;
    }
    return 1;
}

void srtf(int n, struct process *arr)
{
    int atime = 0;
    while (1)
    {
        int minindex = -1, minvalue = INT_MAX;
        for (int i = 0; i < n; i++)
        { 
            if (arr[i].at <= atime)
            {
                if (arr[i].rbt < minvalue)
                {
                    minvalue = arr[i].rbt;
                    minindex = i;
                }
            }
        }
        if (minindex != -1)
        {
            printf("P%d | %d | ", minindex + 1, atime + 1);
            if (arr[minindex].rt == INT_MAX){
                arr[minindex].rt = atime - arr[minindex].at;}
            atime++;
            arr[minindex].rbt--;
                // atime++;
            if (arr[minindex].rbt == 0)
            {
                arr[minindex].ct = atime;
                arr[minindex].rbt = INT_MAX;
            }
        }
        else
            atime++;
        if (check(n, arr))
        {
            for (int i = 0; i < n; i++)
            {
                arr[i].tat = arr[i].ct - arr[i].at;
                arr[i].wt = arr[i].tat - arr[i].bt;
            }
            printf("\n");
            display(n, arr);
            return;
        }
    }
}

int main()
{
    int n;
    printf("Enter the no of Processes:\n");
    scanf("%d", &n);
    struct process arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the Arrival Time and Burst Time of Process %d:\n", i + 1);
        scanf("%d", &arr[i].at);
        scanf("%d", &arr[i].bt);
        arr[i].rbt = arr[i].bt;
        arr[i].rt = INT_MAX;
    }
    srtf(n, arr);
    avg(n, arr);
    return 0;
}
