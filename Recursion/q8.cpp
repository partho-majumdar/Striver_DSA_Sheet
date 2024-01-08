#include <bits/stdc++.h>
using namespace std;

int revArr(int arr[], int i, int n)
{
    if (i >= n / 2)
    {
        return 0;
    }
    swap(arr[i], arr[n - i - 1]); // in built function
    return revArr(arr, i + 1, n);
}

int main()
{

    int n;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    revArr(arr, 0, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// reverse array using 1 pointer