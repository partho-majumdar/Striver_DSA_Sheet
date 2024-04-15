#include <bits/stdc++.h>
using namespace std;

int main()
{
    deque<int> dq;
    dq.push_back(1);
    dq.push_back(2);
    dq.push_back(3);
    dq.push_front(9);
    dq.push_front(8);
    dq.push_front(7);
    dq.push_front(6);

    for (auto i : dq)
    {
        cout << i << " ";
    }

    cout << endl
         << dq.front();
    cout << endl
         << dq.back();

    return 1;
}