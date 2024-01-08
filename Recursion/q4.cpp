#include <bits/stdc++.h>
using namespace std;

int addNum(int i, int sum)
{
    if (i < 1)
    {
        cout << sum;
        return sum;
    }
    return addNum(i - 1, sum + i);
}

int main()
{
    int n = 3;
    addNum(n, 0);
    return 0;
}

// sum of 1 to N --> 3 = 1 + 2 + 3 = 6 (parameterized way)