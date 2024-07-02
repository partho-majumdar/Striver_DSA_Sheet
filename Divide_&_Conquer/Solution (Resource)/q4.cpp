#include <bits/stdc++.h>
using namespace std;

int power(int X, int Y)
{
    if (Y == 0)
    {
        return 1;
    }

    if (Y == 1)
    {
        return X;
    }

    return (power(X, Y / 2) * power(X, Y - Y / 2));
}

int main()
{
    int X, Y;
    cout << "Enter X and Y: ";
    cin >> X >> Y;

    int result = power(X, Y);

    cout << result;

    return 0;
}
