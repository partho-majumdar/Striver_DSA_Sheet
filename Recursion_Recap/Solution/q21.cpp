#include <bits/stdc++.h>
using namespace std;

int binary_search(int arr[], int start, int end, int target)
{
    if (start > end)
    {
        return -1;
    }

    int mid = (start + end) / 2;
    if (target == arr[mid])
    {
        return mid;
    }

    else if (target > arr[mid])
    {
        return binary_search(arr, mid + 1, end, target);
    }

    else
    {
        return binary_search(arr, start, mid - 1, target);
    }
}

int main()
{
    int arr[] = {2, 5, 7, 9, 11, 13};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 17;
    int ans = binary_search(arr, 0, n - 1, target);
    cout << "Target found at index: " << ans;
    return 0;
}