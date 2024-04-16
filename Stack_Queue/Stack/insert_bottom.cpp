#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int x)
{
    stack<int> temp;
    while (!st.empty())
    {
        temp.push(st.top());
        st.pop();
    }
    st.push(x);
    while (!temp.empty())
    {
        st.push(temp.top());
        temp.pop();
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
    insertAtBottom(st, 105);
    insertAtBottom(st, 109);

    while (!st.empty())
    {
        int top = st.top();
        cout << top << endl;
        st.pop();
    }

    return 0;
}