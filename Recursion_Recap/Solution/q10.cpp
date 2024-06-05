#include <bits/stdc++.h>
using namespace std;

int arr_sum(int arr[], int n)
{
    if (n == 1)
    {
        return arr[0];
    }
    return (arr[n - 1] + arr_sum(arr, n - 1));
}

int arr_avg(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }
    int sum_ans = arr_sum(arr, n);
    return sum_ans / n;
}

int main()
{
    int arr[] = {7, 1, 2, 9, 5, 3, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = arr_avg(arr, n);
    cout << ans;
    return 0;
}