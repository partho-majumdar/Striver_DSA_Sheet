#include <bits/stdc++.h>
using namespace std;

bool primeHelper(int val, int i)
{
    if (i > sqrt(val))
    {
        return true;
    }

    else if (val % i == 0)
    {
        return false;
    }

    else
    {
        return primeHelper(val, i + 2);
    }
}

bool isPrime(int val)
{
    if (val <= 1)
    {
        return false;
    }

    else if (val == 2)
    {
        return true;
    }

    else if (val % 2 == 0)
    {
        return false;
    }

    else
    {
        return primeHelper(val, 3);
    }
}

int main()
{
    int ans = isPrime(6);
    if (ans)
    {
        cout << "Prime";
    }
    else
    {
        cout << "Not Prime";
    }
    return 0;
}