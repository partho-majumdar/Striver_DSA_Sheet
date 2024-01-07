#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 36;

    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
        {
            cout << i << " ";
        }
    }

    return 0;
}

// The divisors of 10 are 1,2,5,10.