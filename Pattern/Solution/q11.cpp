#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int printStart = i % 2 == 0 ? 0 : 1;

        for (int j = 1; j <= i; j++)
        {
            cout << printStart;
            printStart = 1 - printStart;
        }
        cout << endl;
    }
    return 0;
}