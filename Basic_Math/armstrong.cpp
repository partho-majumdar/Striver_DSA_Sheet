#include <bits/stdc++.h>
using namespace std;

int digitCount(int n)
{
    int count = 0;
    while (n != 0)
    {
        int last_digit = n % 10;
        count++;
        n /= 10;
    }
    return count;
}

int main()
{
    int n = 1634;
    int temp = n;
    int sum = 0;
    int power = digitCount(temp);

    while (n != 0)
    {
        int last_digit = n % 10;
        sum += pow(last_digit, power);
        n /= 10;
    }

    if (temp == sum)
    {
        cout << "Armstrong";
    }
    else
    {
        cout << "Not armstrong";
    }
    return 0;
}

// 1634 is an Armstrong number, as 1^4 + 6^4 + 3^4 + 4^4 = 1634