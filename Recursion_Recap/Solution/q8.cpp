#include <bits/stdc++.h>
using namespace std;

int arr_max(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    return max(arr[n - 1], arr_max(arr, n - 1));
}

int main()
{
    int arr[] = {7, 1, 2, 9, 5, 3, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = arr_max(arr, n);
    cout << ans;
    return 0;
}