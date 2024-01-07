#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10400;

    int sum = 0;
    while (n != 0)
    {
        int last_digit = n % 10;
        sum = (sum * 10) + last_digit;
        n /= 10;
    }
    cout << "Rev number: " sum;

    return 0;
}