#include <bits/stdc++.h>
using namespace std;

stack<int> st1;
stack<int> st2;

void my_push(int x)
{
    st1.push(x);
    while (!st1.empty())
    {
        st2.push(st1.top());
        st1.pop();
    }
}

void my_pop()
{
    int top = st2.top();
    st2.pop();
    cout << top << endl;
}

int main()
{
    my_push(4);
    my_push(3);
    my_push(2);
    my_push(1);

    my_pop();
    my_pop();
    return 0;
}