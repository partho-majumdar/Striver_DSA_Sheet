#include <bits/stdc++.h>
using namespace std;

void swapNum(int arr[], int index1, int index2)
{
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}

void revArr(int arr[], int i, int j)
{
    if (i < j)
    {
        swapNum(arr, i, j);
        revArr(arr, i + 1, j - 1);
    }
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

    revArr(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

// reverse an array using 2 pointer