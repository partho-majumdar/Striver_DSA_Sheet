#include <bits/stdc++.h>
using namespace std;

void pathWithRestriction(string s, bool maze[3][3], int r, int c, int rLength, int cLength)
{
    if ((r == rLength - 1) && (c == cLength - 1))
    {
        cout << s << endl;
    }

    if (maze[r][c] == false)
    {
        return;
    }

    if (r < rLength - 1)
    {
        pathWithRestriction(s + "D", maze, r + 1, c, rLength, cLength);
    }

    if (c < cLength - 1)
    {
        pathWithRestriction(s + "R", maze, r, c + 1, rLength, cLength);
    }
}

int main()
{
    bool board[3][3] = {
        {true, true, true},
        {true, false, true},
        {true, true, true}

    };

    int rowLength = sizeof(board) / sizeof(board[0]);
    int colLength = sizeof(board[0]) / sizeof(board[0][0]);

    pathWithRestriction(" ", board, 0, 0, rowLength, colLength);
    return 0;
}