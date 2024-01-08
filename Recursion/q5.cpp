#include <bits/stdc++.h>
using namespace std;

int func(int n)
{
    if (n == 0)
    {
        return 0;
    }
    return (n + func(n - 1));
}

int main()
{
    int n = 3;
    int ans = func(n);
    cout << ans;
    return 0;
}

// functional way sum of 1 to N