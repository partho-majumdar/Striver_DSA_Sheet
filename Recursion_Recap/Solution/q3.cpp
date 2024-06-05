#include <bits/stdc++.h>
using namespace std;

int find_power(int x, int y)
{
    int ans = 1;
    if (y == 0)
    {
        return ans;
    }
    ans = x * find_power(x, y - 1);
    return ans;
}

int main()
{
    int ans = find_power(2, 4);
    cout << ans;
    return 0;
}