#include <bits/stdc++.h>
using namespace std;

void print_odd(int arr[], int low, int high)
{
    if (low > high)
    {
        return;
    }

    else if (low == high)
    {
        if (arr[low] % 2 != 0)
        {
            cout << arr[low] << " ";
        }
        return;
    }

    int mid = (low + high) / 2;

    print_odd(arr, low, mid);
    print_odd(arr, mid + 1, high);
}

int main()
{
    int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    print_odd(arr, 0, n - 1);
    return 0;
}
