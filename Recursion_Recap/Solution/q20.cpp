#include <bits/stdc++.h>
using namespace std;

void toh(int n, char source, char destination, char helper)
{
    if (n == 1)
    {
        cout << "Move disk " << n << " from " << source << " to " << destination << endl;
        return;
    }

    toh(n - 1, source, helper, destination);
    cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    toh(n - 1, helper, destination, source);
}

int main()
{
    int n = 4;
    toh(n, 'A', 'C', 'B');
    return 0;
}