#include <bits/stdc++.h>
using namespace std;

void print_without_pop()
{
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(3);
    q.push(5);

    vector<int> ans;

    while (!q.empty())
    {
        cout << q.front() << " ";
        ans.push_back(q.front());
        q.pop();
    }

    for (auto i : ans)
    {
        q.push(i);
    }
}

void print_with_constant_time()
{
    queue<int> q;
    q.push(2);
    q.push(4);
    q.push(6);
    q.push(3);
    q.push(5);

    int n = q.size();
    while (n)
    {
        cout << q.front() << " ";
        q.push(q.front());
        q.pop();
        n--;
    }
}

int main()
{
    // queue<int> q;
    // q.push(1);
    // q.push(2);
    // q.push(3);

    // while (!q.empty())
    // {
    //     cout << q.front() << " ";
    //     q.pop();
    // }

    // print_without_pop();
    print_with_constant_time();

    return 0;
}