#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= 5; i++)
    {
        for (char ch = 'E' - i + 1; ch <= 'E'; ch++)
        {
            cout << ch;
        }
        cout << endl;
    }
    return 0;
}