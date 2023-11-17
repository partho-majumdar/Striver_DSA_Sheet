#include <bits/stdc++.h>
using namespace std;

int main()
{
    int j = 11;
    while (j <= 15)
    {
        if (j % 2 == 0)
        {
            cout << "Even " << j << endl;
        }
        j++;
    }
    cout << j << endl; // 16

    // if i want loop must run minumum 1 time then use do-while loop
    int i = 11;
    do
    {
        if (i % 2 == 0)
        {
            cout << "Even " << i << endl;
        }
        i++;
    } while (i <= 15);
    return 0;
}