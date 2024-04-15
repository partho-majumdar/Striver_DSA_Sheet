#include <bits/stdc++.h>
using namespace std;

void rev_k_element(int n)
{
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(3);
    q.push(5);

    stack<int> st;

    while (n)
    {
        st.push(q.front());
        q.pop();
        n--;
    }

    int m = q.size();
    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    while (m)
    {
        q.push(q.front());
        q.pop();
        m--;
    }

    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
}

int main()
{
    rev_k_element(2);
    return 0;
}