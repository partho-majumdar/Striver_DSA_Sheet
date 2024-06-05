#include <bits/stdc++.h>
using namespace std;

int count_number(int n)
{
    if (n / 10 == 0)
    {
        return 1;
    }

    return (1 + count_number(n / 10));
}

int main()
{
    int ans = count_number(517923);
    cout << ans;
    return 0;
}