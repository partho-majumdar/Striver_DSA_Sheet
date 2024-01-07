#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 121;
    int rev = 0;
    int temp = n;

    while (n != 0)
    {
        int last_digit = n % 10;
        rev = (rev * 10) + last_digit;
        n /= 10;
    }

    if (rev == temp)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }

    return 0;
}