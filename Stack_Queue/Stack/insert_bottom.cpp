#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int x)
{
    stack<int> temp;
    while (!st.empty())
    {
        int top = st.top();
        st.pop();
        temp.push(top);
    }
    st.push(x);
    while (!temp.empty())
    {
        int top = temp.top();
        temp.pop();
        st.push(top);
    }
}

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    insertAtBottom(st, 101);

    while (!st.empty())
    {
        int top = st.top();
        cout << top << endl;
        st.pop();
    }

    return 0;
}