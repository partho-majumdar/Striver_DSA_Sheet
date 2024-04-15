#include <bits/stdc++.h>
using namespace std;

void time_to_buy_ticket(int arr[], int n, int k)
{
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        q.push(i);
    }

    int time = 0;
    while (arr[k] != 0)
    {
        arr[q.front()]--;
        if (arr[q.front()])
        {
            q.push(q.front());
        }
        q.pop();
        time++;
    }

    cout << time;
}

int main()
{
    int arr[] = {5, 1, 1, 1};
    int k = 0;
    int n = sizeof(arr) / sizeof(arr[0]);
    time_to_buy_ticket(arr, n, k);
    return 0;
}

/*

https://leetcode.com/problems/time-needed-to-buy-tickets

*/