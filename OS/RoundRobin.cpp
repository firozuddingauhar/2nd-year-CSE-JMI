#include <bits/stdc++.h>
using namespace std;
struct proces
{
    int ind;
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
void roro(int n, struct proces arr[], int tq)
{
    queue<struct proces *> qt;
    int atime = 0, tos = 0;
    while (1)
    {
        if (!qt.empty())
        {
            struct proces *temp = qt.front();
            qt.pop();
            if (temp->rt == INT_MAX)
                temp->rt = atime - temp->at;
            if (temp->rbt > tq)
            {
                temp->rbt = temp->rbt - tq;
                for (int i = atime + 1; i <= atime + tq; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (arr[j].at == i)
                            qt.push(&arr[j]);
                    }
                }
                atime = atime + tq;
                cout << "P" << temp->ind << " | " << atime << " |";
                qt.push(temp);
            }
            else if (temp->rbt == tq)
            {
                temp->ct = atime + tq;
                for (int i = atime + 1; i <= atime + tq; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (arr[j].at == i)
                            qt.push(&arr[j]);
                    }
                }
                atime = atime + tq;
                cout << "P" << temp->ind << " | " << atime << " |";
                temp->rbt = INT_MAX;
            }
            else
            {
                temp->ct = atime + temp->rbt;
                for (int i = atime + 1; i <= atime + temp->rbt; i++)
                {
                    for (int j = 0; j < n; j++)
                    {
                        if (arr[j].at == i)
                            qt.push(&arr[j]);
                    }
                }
                atime = atime + temp->rbt;
                cout << "P" << temp->ind << " | " << atime << " |";
                temp->rbt = INT_MAX;
            }
        }
        else
        {
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
            for (int i = 0; i < n; i++)
            {
                if (arr[i].at == atime)
                    qt.push(&arr[i]);
            }
            if (qt.empty())
                atime++;
        }
    }
}
int main()
{
    cout << "Name : Md Masleuddin\nRoll : 21BCS028\n\n";
    int n, tq;
    cout << "Enter the no of Proces :" << endl;
    cin >> n;
    cout << "Enter the time quantum :" << endl;
    cin >> tq;
    struct proces arr[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the Arrival Time and Burst Time of " << i + 1 << " process :" << endl;
        cin >> arr[i].at >> arr[i].bt;
        arr[i].ind = i + 1;
        arr[i].rbt = arr[i].bt;
    }
    cout << endl;
    roro(n, arr, tq);
    avg(n, arr);
}