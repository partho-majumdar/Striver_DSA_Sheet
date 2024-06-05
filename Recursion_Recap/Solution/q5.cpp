#include <bits/stdc++.h>
using namespace std;

int digit_sum(int n)
{
    if (n / 10 == 0)
    {
        return n % 10;
    }

    return ((n % 10) + digit_sum(n / 10));
}

int main()
{
    int ans = digit_sum(51923);
    cout << ans;
    return 0;
}