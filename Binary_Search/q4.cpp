#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {2, 3, 6, 8, 8, 11, 11, 11, 12};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0;
    int high = n - 1;
    int target = 8;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > target)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans;
    return 0;
}

// upper bound(lowest index such that) --> arr[i] > value