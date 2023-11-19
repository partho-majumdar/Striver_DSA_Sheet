#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= (2 * n) - 1; i++)
    {
        // star
        int condition1 = i > n ? (2 * n) - i : i;
        for (int j = 1; j <= condition1; j++)
        {
            cout << "*";
        }

        // space
        int condition2 = i > n ? (i - n) * 2 : 2 * (n - i);
        for (int j = 1; j <= condition2; j++)
        {
            cout << " ";
        }

        // star
        int condition3 = i > n ? (2 * n) - i : i;
        for (int j = 1; j <= condition3; j++)
        {
            cout << "*";
        }

        cout << endl;
    }
    return 0;
}