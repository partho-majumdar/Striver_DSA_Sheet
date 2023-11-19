#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= 2 * n; i++)
    {
        // start
        int condition1 = i > n ? i - n : n - i + 1;
        for (int j = 1; j <= condition1; j++)
        {
            cout << "*";
        }

        // space
        int k = 1;
        int condition2 = i > n ?: 2 * (i - 1);
        for (int j = 1; j <= condition2; j++)
        {
            cout << " ";
        }

        // start
        int condition3 = i > n ? i - n : n - i + 1;
        for (int j = 1; j <= condition3; j++)
        {
            cout << "*";
        }
        cout << endl;
    }
    return 0;
}