#include <bits/stdc++.h>
using namespace std;

int find_gcd(int x, int y)
{
    if (y == 0)
    {
        return x;
    }

    return find_gcd(y, x % y);
}

int main()
{
    int x = 24;
    int y = 30;

    int ans = find_gcd(x, y);
    cout << ans;
    return 0;
}