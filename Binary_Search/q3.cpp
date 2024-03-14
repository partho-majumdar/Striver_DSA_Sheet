#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 10;
    int arr[n] = {1, 2, 3, 3, 5, 8, 8, 10, 10, 11};
    int low = 0;
    int high = n - 1;
    int ans = n;
    int target = 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= target)
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

// lower bound(lowest index such that) --> arr[i] >= value