#include <bits/stdc++.h>
using namespace std;

int countPath(int r, int c)
{
    if (r == 1 || c == 1)
    {
        return 1;
    }

    int left = countPath(r - 1, c);
    int right = countPath(r, c - 1);

    return left + right;
}

int main()
{
    int row = 3;
    int col = 3;
    int ans = countPath(row, col);
    cout << ans;

    return 0;
}

/*

3*3 matrix er (3, 3) --> (1, 1) a path count = ? only right and down allow

*/