#include <bits/stdc++.h>
using namespace std;

int gcd(int n1, int n2)
{
    for (int i = min(n1, n2); i >= 1; i--)
    {
        if ((n1 % i == 0) && (n2 % i == 0))
        {
            return i;
            break;
        }
    }
    return 0;
}

int main()
{
    int n1 = 24;
    int n2 = 36;

    int lcm = (n1 * n2) / gcd(n1, n2);
    cout << "LCM: " << lcm;

    return 0;
}
