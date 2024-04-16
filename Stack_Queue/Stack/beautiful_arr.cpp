#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 3, 5, -4, 6, -2, -8, 9};
    int n = sizeof(arr) / sizeof(arr[0]);

    stack<int> stk;

    for (auto i : arr)
    {
        if (stk.empty())
        {
            stk.push(i);
        }
        else if (i >= 0)
        {
            if (stk.top() >= 0)
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
            }
        }
        else
        {
            if (stk.top() < 0)
            {
                stk.push(i);
            }
            else
            {
                stk.pop();
            }
        }
    }

    while (!stk.empty())
    {
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}

// https://www.geeksforgeeks.org/problems/make-the-array-beautiful--170647/1
