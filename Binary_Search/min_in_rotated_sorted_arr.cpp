#include <bits/stdc++.h>
using namespace std;

int minRotArr(int arr[], int n)
{
    int low = 0;
    int high = n - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            ans = min(ans, arr[mid]);
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int arr[] = {5, 6, 1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = minRotArr(arr, n);
    cout << ans;
    return 0;
}

/*

https://www.geeksforgeeks.org/find-minimum-element-in-a-sorted-and-rotated-array/
Find the Minimum element in a Sorted and Rotated Array

Given a sorted array arr[] (may be distinct or may contain duplicates) of size N that is rotated at some unknown point, the task is to find the minimum element in it.

Examples:

Input: arr[] = {5, 6, 1, 2, 3, 4}
Output: 1
Explanation: 1 is the minimum element present in the array.

Input: arr[] = {1, 2, 3, 4}
Output: 1

Input: arr[] = {2, 1}
Output: 1

*/