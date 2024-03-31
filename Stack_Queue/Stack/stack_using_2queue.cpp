#include <bits/stdc++.h>
using namespace std;

queue<int> q1;
queue<int> q2;

void push_element(int x)
{
    q2.push(x);
    while (!q1.empty())
    {
        q2.push(q1.front());
        q1.pop();
    }

    while (!q2.empty())
    {
        q1.push(q2.front());
        q2.pop();
    }
}

int pop_element()
{
    int top = q1.front();
    q1.pop();
    return top;
}

int main()
{
    push_element(4);
    push_element(3);
    push_element(2);
    push_element(1);

    pop_element();

    while (!q1.empty())
    {
        cout << q1.front() << " ";
        q1.pop();
    }
    return 0;
}