#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    int arr[n] = {2, 3, 6, 7, 8, 8, 11, 11, 11, 12};
    int low = 0;
    int high = n - 1;
    int target = 11;
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