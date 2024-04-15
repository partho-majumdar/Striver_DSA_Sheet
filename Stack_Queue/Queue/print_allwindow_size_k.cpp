#include <bits/stdc++.h>
using namespace std;

void display(queue<int> q)
{
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    int arr[] = {2, 3, 1, 5, 6, 7, 8};
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
        cout << endl;
    }

    display(q);
    return 0;
}