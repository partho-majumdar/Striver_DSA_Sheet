#include <bits/stdc++.h>
using namespace std;

int find_power(int x, int y)
{
    if (y == 0)
    {
        return 1;
    }

    else if (y == 1)
    {
        return x;
    }

    return (find_power(x, y / 2) * find_power(x, y - y / 2));
}

int main()
{
    int x = 3, y = 7;
    int ans = find_power(x, y);
    cout << ans;
    return 0;
}