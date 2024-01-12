#include <bits/stdc++.h>
using namespace std;

void printPath(string s, int r, int c)
{
    if (r == 1 && c == 1)
    {
        cout << s << endl;
        return;
    }

    if (r > 1)
    {
        printPath(s + "D", r - 1, c);
    }

    if (c > 1)
    {
        printPath(s + "R", r, c - 1);
    }
}

int main()
{
    int row = 3;
    int col = 3;
    printPath("", row, col);

    return 0;
}

// print path only right and down