#include <bits/stdc++.h>
using namespace std;

void display(queue<int> q)
{
    while (!q.empty())
    {
        if (q.front() < 0)
        {
            cout << q.front() << " ";
            break;
        }
        q.pop();
    }
}

int main()
{
    int arr[] = {2, -3, -4, -2, 7, 8, 9, -10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 3;

    queue<int> q;

    for (int i = 0; i < k; i++)
    {
        q.push(arr[i]);
    }

    for (int i = k; i < n; i++)
    {
        display(q);
        q.pop();
        q.push(arr[i]);
        // cout << endl;
    }
    return 0;
}

// first negative integer in every window of size k