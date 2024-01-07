#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;
    q.back() += 5;

    cout << q.back();

    return 0;
}

// FIFO --> First in first out