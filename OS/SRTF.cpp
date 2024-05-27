#include <bits/stdc++.h>

using namespace std;
struct proces
{
    int at;
    int bt;
    int ct = INT_MAX;
    int tat = INT_MAX;
    int wt = INT_MAX;
    int rt = INT_MAX;
    int rbt;
};
void display(int n, struct proces arr[])
{
    cout << "PROC\t\tAT\t\tBT\t\tCT\t\tTAT\t\tWT\t\tRT" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "P" << i + 1 << "\t\t" << arr[i].at << "\t\t" << arr[i].bt << "\t\t";
        if (arr[i].ct != INT_MAX)
        {
            cout << arr[i].ct << "\t\t" << arr[i].tat << "\t\t" << arr[i].wt << "\t\t" << arr[i].rt;
        }
        cout << endl;
    }
}
void avg(int n, struct proces arr[])
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i].tat;
    }
    cout << "\nTotal TurnAround Time is : " << sum << endl;
    cout << "Average TurnAround Time is : " << sum << "/" << n << " = " << (float)sum / (float)n << endl;
    sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum = sum + arr[i].wt;
    }
    cout << "\nTotal Waiting Time is : " << sum << endl;
    cout << "Average Waiting Time is : " << sum << "/" << n << " = " << (float)sum / (float)n << endl;
}
bool check(int n, struct proces arr[])
{
    bool flag = true;
    for (int i = 0; i < n; i++)
    {
        if (arr[i].rbt != INT_MAX)
            flag = false;
    }
    return flag;
}
void srtf(int n, struct proces *arr)
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
            cout << "P" << minindex + 1 << " | " ;//<< atime + 1 << " | ";
            atime++;
            arr[minindex].rbt--;
            if (arr[minindex].rt == INT_MAX)
                arr[minindex].rt = atime - arr[minindex].at - 1;
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
            cout << endl;
            display(n, arr);
            return;
        }
    }
}
int main()
{
    cout << "Name:Firoz Uddin\nRoll: 22BCS041\n\n";
    int n;
    cout << "Enter the no of Proces :" << endl;
    cin >> n;
    struct proces arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Arrival Time and Burst Time of " << i + 1 << " process :" << endl;
        cin >> arr[i].at >> arr[i].bt;
        arr[i].rbt = arr[i].bt;
    }
    srtf(n, arr);
    avg(n, arr);
}