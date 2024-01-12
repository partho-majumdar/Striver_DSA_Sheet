#include <bits/stdc++.h>
using namespace std;

void printAllPath(string s, int r, int c)
{
    if (r == 1 && c == 1)
    {
        cout << s << endl;
        return;
    }

    // horizontal
    if (c > 1)
    {
        printAllPath(s + "H", r, c - 1);
    }

    // vertical
    if (r > 1)
    {
        printAllPath(s + "V", r - 1, c);
    }

    // Diagonal
    if (r > 1 && c > 1)
    {
        printAllPath(s + "D", r - 1, c - 1);tg
    }
}

int main()
{
    int row = 3;
    int col = 3;
    printAllPath(" ", row, col);
    return 0;
}

// Print path horizontal, vertical and diagonal