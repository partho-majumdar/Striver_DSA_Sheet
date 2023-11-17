#include <bits/stdc++.h>
using namespace std;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        cout << "Hey " << i + 1 << endl;
    }

    int j;
    for (j = 11; j <= 15; j++)
    {
        if (j % 2 == 0)
        {
            cout << "Even " << j << endl;
        }
    }
    cout << j; // 16
    return 0;
}