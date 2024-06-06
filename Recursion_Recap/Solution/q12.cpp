#include <bits/stdc++.h>
using namespace std;

void reverse_arr(int arr[], int n)
{
    if (n == 0)
    {
        return;
    }
    cout << arr[n - 1] << " ";
    reverse_arr(arr, n - 1);
}

int main()
{
    int arr[] = {3, 5, 7, 8, 9, 11};
    int n = sizeof(arr) / sizeof(arr[0]);
    reverse_arr(arr, n);
    return 0;
}