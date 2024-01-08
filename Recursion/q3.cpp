#include <bits/stdc++.h>
using namespace std;

void func(int i, int n)
{
    if (i > n)
    {
        return;
    }
    else
    {
        func(i + 1, n);
        cout << "Partho " << i << endl;
    }
}

int main()
{
    int n;
    cin >> n;
    func(1, n);
    return 0;
}

// Print name from N to 1 times