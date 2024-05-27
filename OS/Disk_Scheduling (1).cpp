#include <bits/stdc++.h>
using namespace std;
void fcfs(vector<int> arr, int head, int range)
{
    int sum = 0;
    cout << "Disc will be called in order of" << endl;
    for (int i = 0; i < arr.size(); i++)
    {
        sum = sum + abs(head - arr[i]);
        head = arr[i];
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "Total head movement is :" << sum << endl;
}
void scan(vector<int> arr, int head, int range)
{
    int opt;
    cout << "Enter 1 for Right Movement" << endl
         << "Enter 2 for Left Movement" << endl;
    cin >> opt;
    if (opt == 1)
    {
        int temp = 0, sum = 0;
        sort(arr.begin(), arr.end());
        while (head > arr[temp])
            temp++;
        for (int i = temp; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << range << " ";
        for (int i = temp - 1; 0 <= i; i--)
        {
            cout << arr[i] << " ";
        }
        sum = abs(range - head) + (range - arr[0]);
        cout << endl
             << "Total Head Movement is :" << sum << endl;
    }
    else if (opt == 2)
    {

        int temp = 0, sum = 0;
        sort(arr.begin(), arr.end());
        while (head > arr[temp])
            temp++;
        for (int i = temp - 1; 0 <= i; i--)
        {
            cout << arr[i] << " ";
        }
        cout << "0 ";
        for (int i = temp; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        sum = head + arr[arr.size() - 1];
        cout << endl
             << "Total Head Movement is :" << sum << endl;
    }
    else
    {
        cout << "You Entered Wrong Key" << endl;
    }
}

void look(vector<int> arr, int head, int range)
{
    int opt;
    cout << "Enter 1 for Right Movement" << endl
         << "Enter 2 for Left Movement" << endl;
    cin >> opt;
    if (opt == 1)
    {
        int temp = 0, sum = 0;
        sort(arr.begin(), arr.end());
        while (head > arr[temp])
            temp++;
        for (int i = temp; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        for (int i = temp - 1; 0 <= i; i--)
        {
            cout << arr[i] << " ";
        }
        sum = abs(head - arr[arr.size() - 1]) + (arr[arr.size() - 1] - arr[0]);

        cout << endl
             << "Total Head Movement is :" << sum << endl;
    }
    else if (opt == 2)
    {
        int temp = 0, sum = 0;
        sort(arr.begin(), arr.end());
        while (head > arr[temp])
            temp++;
        for (int i = temp - 1; 0 <= i; i--)
        {
            cout << arr[i] << " ";
        }
        for (int i = temp; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        sum = (head - arr[0]) + (arr[arr.size() - 1] - arr[0]);

        cout << endl
             << "Total Head Movement is :" << sum << endl;
    }
    else
    {
        cout << "You Entered Wrong Key" << endl;
    }
}

void cscan(vector<int> arr, int head, int range)
{
    int opt;
    cout << "Enter 1 for Right Movement" << endl
         << "Enter 2 for Left Movement" << endl;
    cin >> opt;
    if (opt == 1)
    {
        int temp = 0, sum = 0;
        sort(arr.begin(), arr.end());
        while (head > arr[temp])
            temp++;
        for (int i = temp; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        cout << range << " 0 ";
        for (int i = 0; i < temp; i++)
        {
            cout << arr[i] << " ";
        }
        sum = abs(range - head) + arr[temp - 1] + range;
        cout << endl
             << "Total Head Movement is :" << sum << endl;
    }
    else if (opt == 2)
    {

        int temp = 0, sum = 0;
        sort(arr.begin(), arr.end());
        while (head > arr[temp])
            temp++;
        for (int i = temp - 1; 0 <= i; i--)
        {
            cout << arr[i] << " ";
        }
        cout << "0 " << range << " ";
        for (int i = arr.size() - 1; temp <= i; i--)
        {
            cout << arr[i] << " ";
        }
        sum = head + range + abs(range - arr[temp]);
        cout << endl
             << "Total Head Movement is :" << sum << endl;
    }
    else
    {
        cout << "You Entered Wrong Key" << endl;
    }
}
void clook(vector<int> arr, int head, int range)
{
    int opt;
    cout << "Enter 1 for Right Movement" << endl
         << "Enter 2 for Left Movement" << endl;
    cin >> opt;
    if (opt == 1)
    {
        int temp = 0, sum = 0;
        sort(arr.begin(), arr.end());
        while (head > arr[temp])
            temp++;
        for (int i = temp; i < arr.size(); i++)
        {
            cout << arr[i] << " ";
        }
        for (int i = 0; i <= temp; i++)
        {
            cout << arr[i] << " ";
        }
        sum = abs(head - arr[arr.size() - 1]) + (arr[arr.size() - 1] - arr[0]) + abs(arr[0] - arr[temp - 1]);
        cout << endl
             << "Total Head Movement is :" << sum << endl;
    }
    else if (opt == 2)
    {
        int temp = 0, sum = 0;
        sort(arr.begin(), arr.end());
        while (head > arr[temp])
            temp++;
        for (int i = temp - 1; 0 <= i; i--)
        {
            cout << arr[i] << " ";
        }
        for (int i = arr.size() - 1; temp <= i; i--)
        {
            cout << arr[i] << " ";
        }
        sum = (head - arr[0]) + abs(arr[arr.size() - 1] - arr[0]) + abs(arr[arr.size() - 1] - arr[temp]);

        cout << endl
             << "Total Head Movement is :" << sum << endl;
    }
    else
    {
        cout << "You Entered Wrong Key" << endl;
    }
}
void sstf(vector<int> arr, int head, int range)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        int min = INT_MAX, k = 0, temp = 0;
        for (int j = 0; j < arr.size(); j++)
        {
            temp = abs(head - arr[j]);
            if (temp < min)
            {
                min = temp;
                k = j;
            }
        }
        cout << arr[k] << " ";
        sum = sum + min;
        head = arr[k];
        arr[k] = INT_MAX;
    }
    cout << endl
         << "Total Head Movement is :" << sum << endl;
}
int main()
{
    vector<int> arr;
    int n, head, range;
    cout << "Name : Md Masleuddin\nRoll : 21BCS028\n\n";
    cout << "Enter the no of request" << endl;
    cin >> n;
    cout << "Enter the position of head" << endl;
    cin >> head;
    cout << "Enter the no of Track" << endl;
    cin >> range;
    range--;
    cout << "Enter the request" << endl;
    for (int i = 0; i < n; i++)
    {
        int temp = 0;
        cin >> temp;
        arr.push_back(temp);
    }
    while (1)
    {
        int opt;
        cout << "\nselect any one option\nEnter 1 for FCFS\nEnter 2 for SCAN\nEnter 3 for C-SCAN\nEnter 4 for LOOK\nEnter 5 for C-LOOK\nEnter 6 for SSTF" << endl;
        cin >> opt;
        if (opt == 1)
        {
            fcfs(arr, head, range);
        }
        else if (opt == 2)
        {
            scan(arr, head, range);
        }
        else if (opt == 3)
        {
            cscan(arr, head, range);
        }
        else if (opt == 4)
        {
            look(arr, head, range);
        }
        else if (opt == 5)
        {
            clook(arr, head, range);
        }
        else if (opt == 6)
        {
            sstf(arr, head, range);
        }
    }
}