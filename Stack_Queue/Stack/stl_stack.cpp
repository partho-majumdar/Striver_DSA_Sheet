#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> stk;
    stk.push_back(1);
    stk.push_back(2);
    stk.push_back(3);
    stk.push_back(4);

    int top = stk.back();

    stk.pop_back();

    for (auto i : stk)
    {
        cout << i << " ";
    }
    return 0;
}