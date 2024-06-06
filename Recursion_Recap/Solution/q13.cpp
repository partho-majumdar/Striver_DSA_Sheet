#include <bits/stdc++.h>
using namespace std;

void even_range(int start, int end)
{
    if (start > end)
    {
        return;
    }

    if (start % 2 == 0)
    {
        cout << start << " ";
    }

    even_range(start + 1, end);
}

int main()
{
    int start = 3;
    int end = 10;
    even_range(start, end);
    cout << endl;
    return 0;
}
