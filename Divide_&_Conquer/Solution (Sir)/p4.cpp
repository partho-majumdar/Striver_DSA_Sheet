#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int low, int high, int target)
{
    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (arr[mid] == target)
    {
        return mid;
    }

    if (target < arr[mid])
    {
        return binary_search(arr, low, mid, target);
    }

    return binary_search(arr, mid + 1, high, target);
}

int main()
{
    int arr[] = {2, 3, 4, 5, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 14;
    int ans = binary_search(arr, 0, n - 1, target);
    cout << ans;
    return 0;
}