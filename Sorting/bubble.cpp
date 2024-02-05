#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;
    int arr[n] = {13, 46, 24, 52, 20, 9};

    for (int i = 0; i <= n - 1; i++)
    {
        int didSwap = 0;
        for (int j = 0; j <= n - 2 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                didSwap = 1;
            }
        }

        if (didSwap == 0)
        {
            break;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

/*

put maximum value in last by adjacent swap worst/avg T.C --> O(N^2) and best T.C --> O(N)
outer for loop run: 0 to n-1
inner for loop run: 0 to n-2

*/ 