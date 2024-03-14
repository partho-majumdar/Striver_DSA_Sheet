#include <bits/stdc++.h>
using namespace std;

bool rotatedArrDuplicate(int arr[], int low, int high, int target)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target)
        {
            return true;
        }

        if (arr[low] == arr[mid] && arr[mid] == arr[high])
        {
            low++;
            high--;
            continue;
        }

        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= target && target <= arr[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }

        else if (arr[mid] <= arr[high])
        {
            if (arr[mid] << target && target <= arr[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return false;
}

int main()
{
    int arr[] = {7, 8, 9, 1, 2, 3, 3, 3, 4, 5, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    bool ans = rotatedArrDuplicate(arr, 0, n - 1, 3);
    cout << ans;
}
