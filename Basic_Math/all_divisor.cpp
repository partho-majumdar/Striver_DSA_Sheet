#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 36;

    // for (int i = 1; i <= n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         cout << i << " ";
    //     }
    // }

    vector<int> ls;

    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ls.push_back(i);
            if ((n / i) != i)
            {
                ls.push_back(n / i);
            }
        }
    }

    sort(ls.begin(), ls.end());

    for (auto i = ls.begin(); i != ls.end(); i++)
    {
        cout << *i << " ";
    }

    return 0;
}

// The divisors of 10 are 1,2,5,10.