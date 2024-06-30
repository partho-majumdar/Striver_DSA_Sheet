#include <bits/stdc++.h>
using namespace std;

int calc_sum(int arr[], int low, int high)
{
    if (low > high)
    {
        return 0;
    }

    if (low == high)
    {
        return arr[low];
    }

    int mid = (low + high) / 2;
    int left_sum = calc_sum(arr, low, mid);
    int right_sum = calc_sum(arr, mid + 1, high);

    return left_sum + right_sum;
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = calc_sum(arr, 0, n - 1);
    cout << ans;
    return 0;
}