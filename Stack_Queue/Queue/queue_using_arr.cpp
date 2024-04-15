#include <bits/stdc++.h>
using namespace std;

int n = 5;
int arr[5] = {0};
int cnt = 0;
int front = 0;
int rare = 0;

void EnQueue_push(int x)
{
    if (cnt == n)
    {
        return;
    }
    arr[rare % n] = x;
    rare++;
    cnt++;
}

void DeQueue_pop()
{
    if (cnt == 0)
    {
        return;
    }
    arr[front % n] = 0;
    front++;
    cnt--;
}

void printQueue()
{
    for (int i = 0; i < n; i++)
    {
        cout << endl;
        cout << arr[i];
    }
}

void printTop()
{
    int ans = arr[front];
    cout << endl;
    cout << "Top: " << ans;
}

int main()
{
    EnQueue_push(10);
    EnQueue_push(14);
    EnQueue_push(19);

    DeQueue_pop();

    EnQueue_push(21);
    EnQueue_push(22);
    EnQueue_push(28);

    printQueue();

    printTop();
    return 0;
}
