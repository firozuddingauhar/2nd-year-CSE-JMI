#include <bits/stdc++.h>
using namespace std;
void firstfit(vector<pair<int, int>> vect, int memory[], int m)
{
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int j = 0;
        while (j < vect.size())
        {
            if (memory[i] <= vect[j].first)
            {
                cout << "P" << i + 1 << "----->"
                     << "Block" << j + 1 << endl;
                sum = sum + (vect[j].first - memory[i]);
                vect[j].first = 0;
                break;
            }
            j++;
        }
    }
    cout << "Total Internal Fragmentation is " << sum << endl;
    sum = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        sum = sum + vect[i].first;
    }
    cout << "Total External Fragmentation is " << sum << endl;
}

void nextfit(vector<pair<int, int>> vect, int memory[], int m)
{
    int sum = 0;
    int j = 0;
    for (int i = 0; i < m; i++)
    {
        while (j < vect.size())
        {
            if (memory[i] <= vect[j].first)
            {
                cout << "P" << i + 1 << "----->"
                     << "Block" << j + 1 << endl;
                sum = sum + (vect[j].first - memory[i]);
                vect[j].first = 0;
                break;
            }
            j++;
        }
    }
    cout << "Total Internal Fragmentation is " << sum << endl;
    sum = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        sum = sum + vect[i].first;
    }
    cout << "Total External Fragmentation is " << sum << endl;
}
void bestfit(vector<pair<int, int>> vect, int memory[], int m)
{
    sort(vect.begin(), vect.end());
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int j = 0;
        while (j < vect.size())
        {
            if (memory[i] <= vect[j].first)
            {
                cout << "P" << i + 1 << "----->"
                     << "Block" << vect[j].second << endl;
                sum = sum + (vect[j].first - memory[i]);
                vect[j].first = 0;
                break;
            }
            j++;
        }
    }
    cout << "Total Internal Fragmentation is " << sum << endl;
    sum = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        sum = sum + vect[i].first;
    }
    cout << "Total External Fragmentation is " << sum << endl;
}
void worstfit(vector<pair<int, int>> vect, int memory[], int m)
{
    sort(vect.begin(), vect.end());
    int sum = 0;
    for (int i = 0; i < m; i++)
    {
        int j = vect.size() - 1;
        while (0 <= j)
        {
            if (memory[i] <= vect[j].first)
            {
                cout << "P" << i + 1 << "----->"
                     << "Block" << vect[j].second << endl;
                sum = sum + (vect[j].first - memory[i]);
                vect[j].first = 0;
                break;
            }
            j--;
        }
    }
    cout << "Total Internal Fragmentation is " << sum << endl;
    sum = 0;
    for (int i = 0; i < vect.size(); i++)
    {
        sum = sum + vect[i].first;
    }
    cout << "Total External Fragmentation is " << sum << endl;
}
int main()
{
    int n, m;
    cout << "Name : Md Masleuddin\nRoll : 21BCS028\n\n";
    cout << "Enter the no of Blocks" << endl;
    cin >> n;
    cout << "Enter the number of procces" << endl;
    cin >> m;
    vector<pair<int, int>> block;
    int memory[m];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the size of Block " << i + 1 << ": ";
        int temp;
        cin >> temp;
        block.push_back(make_pair(temp, i + 1));
    }
    cout << endl;
    for (int i = 0; i < m; i++)
    {
        cout << "Enter the size of Memory " << i + 1 << ": ";
        cin >> memory[i];
    }
    while (1)
    {
        int opt;
        cout << "\n\nSelect any one Option\nEnter 1 for Best fit\nEnter 2 for Worst fit\nEnter 3 for First fit\nEnter 4 for Next fit\n"
             << endl;
        cin >> opt;
        if (opt == 1)
        {
            bestfit(block, memory, m);
        }
        else if (opt == 2)
        {
            worstfit(block, memory, m);
        }
        else if (opt == 3)
        {
            firstfit(block, memory, m);
        }
        else if (opt == 4)
        {
            nextfit(block, memory, m);
        }
        else
        {
            cout << "You Entered Wrong Key";
            return 0;
        }
    }
}