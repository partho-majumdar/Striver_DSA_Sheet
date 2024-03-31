#include <bits/stdc++.h>
using namespace std;

void func(stack<int> &st, stack<int> &result)
{
    if (st.empty())
    {
        return;
    }
    int top = st.top();
    st.pop();
    func(st, result);
    result.push(top);
}

int main()
{
    stack<int> st; // 4 3 2 1
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    stack<int> result;

    func(st, result);

    while (!result.empty())
    {
        int top = result.top();
        cout << top << " ";
        result.pop();
    }
    return 0;
}