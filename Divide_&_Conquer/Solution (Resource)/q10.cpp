#include <bits/stdc++.h>
using namespace std;

int Max_Subarray_Sum(int arr[], int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }

    int mid = (low + high) / 2;

    int left_MSS = Max_Subarray_Sum(arr, low, mid);
    int right_MSS = Max_Subarray_Sum(arr, mid + 1, high);

    int left_sum = INT_MIN, right_sum = INT_MIN, sum = 0;

    for (int i = mid; i >= low; i--)
    {
        sum += arr[i];
        left_sum = max(left_sum, sum);
    }

    sum = 0;

    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        right_sum = max(right_sum, sum);
    }

    int ans = max(left_MSS, right_MSS);
    return max(ans, left_sum + right_sum);
}

int main()
{
    int arr[] = {4, -10, 6, -1, 2, -3};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << Max_Subarray_Sum(arr, 0, n - 1);
    return 0;
}