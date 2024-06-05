#include <bits/stdc++.h>
using namespace std;

int nth_fibo(int n)
{
    if (n == 0)
    {
        return 0;
    }

    else if (n == 1 || n == 2)
    {
        return 1;
    }
    return (nth_fibo(n - 1) + nth_fibo(n - 2));
}

int main()
{
    int ans = nth_fibo(4);
    cout << ans;
    return 0;
}

// 0, 1, 1, 2, 3, 5, 8, 13..........