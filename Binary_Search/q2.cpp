#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int low, int high, int target)
{

    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;
    if (arr[mid] == target)
    {
        return mid;
    }

    else if (arr[mid] < target)
    {
        return binarySearch(arr, mid + 1, high, target);
    }
    return binarySearch(arr, low, mid - 1, target);
}

int main()
{
    vector<int> arr = {3, 4, 6, 7, 9, 12, 16, 17};
    int low = 0;
    int high = arr.size() - 1;
    int ans = binarySearch(arr, low, high, 13);
    cout << "Index: " << ans;
}

// Binary search using recursion