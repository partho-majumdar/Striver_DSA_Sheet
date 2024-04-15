#include <bits/stdc++.h>
using namespace std;

void rev_queue()
{
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(3);
    q.push(5);

    stack<int> st;

    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    rev_queue();
    return 0;
}