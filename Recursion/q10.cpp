#include <bits/stdc++.h>
using namespace std;

int nthFibo(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return nthFibo(n - 1) + nthFibo(n - 2);
}

int main()
{
    int f1 = 0;
    int f2 = 1;
    int ans = nthFibo(6);
    cout << ans;
    return 0;
}