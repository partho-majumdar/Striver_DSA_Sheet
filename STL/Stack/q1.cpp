#include <bits/stdc++.h>
using namespace std;

int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    return 0;
}

// LIFO --> Last in first out