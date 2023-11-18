#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        char ch = 'A';

        // space
        for (int j = 1; j <= n - i; j++)
        {
            cout << " ";
        }

        // value
        for (int j = 1; j <= (2 * i) - 1; j++)
        {
            cout << ch;

            if (j <= i)
            {
                ch++;
            }
            else
            {
                ch--;
            }
        }
        cout << endl;
    }
    return 0;
}