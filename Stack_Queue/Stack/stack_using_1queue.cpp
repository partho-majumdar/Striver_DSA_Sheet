#include <bits/stdc++.h>
using namespace std;

queue<int> q1;

void my_push(int x)
{
    q1.push(x);
    for (int i = 0; i < q1.size() - 1; i++)
    {
        q1.push(q1.front());
        q1.pop();
    }
}

void my_pop()
{
    q1.pop();
}

int main()
{
    my_push(4);
    my_push(3);
    my_push(2);
    my_push(1);

    my_pop();

    while (!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
    return 0;
}