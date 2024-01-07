#include <bits/stdc++.h>
using namespace std;

int main()
{
    priority_queue<int> pq;
    pq.push(1);
    pq.push(12);
    pq.push(3);
    pq.push(4);

    pq.pop();
    cout << pq.top() << endl;

    return 0;
}

// max item always stay in top