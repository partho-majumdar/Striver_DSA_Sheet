#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[n] = {1, 2, 4, 7};
    int n = sizeof(arr) / sizeof(arr[0]);
    int value = 6;
    int ans = n;
    int low = 0;
    int high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= value)
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

/*

https://www.codingninjas.com/studio/problems/algorithm-to-find-best-insert-position-in-sorted-array_839813?interviewProblemRedirection=true
If the value is present in the array, return its index.
If the value is absent, determine the index where it would be inserted in the array while maintaining the sorted order.

Input:  arr = [1, 2, 4, 7],  m = 6

Output: 3

If the given array 'arr' is: [1, 2, 4, 7] and m = 6. We insert m = 6 in the array and get 'arr' as: [1, 2, 4, 6, 7]. The position of 6 is 3 (according to 0-based indexing)

*/