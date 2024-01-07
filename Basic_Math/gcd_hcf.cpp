#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n1 = 11;
    int n2 = 13;

    for (int i = min(n1, n2); i >= 1; i--)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            cout << "GCD: " << i;
            break;
        }
    }

    return 0;
}

/*
     gcd / hcf --> highest common factor
     9 --> 1, 3, 9
     12 --> 1, 2, 3, 4, 6, 12

     common --> 1, 3
     gcd --> 3

*/