#include <bits/stdc++.h>
using namespace std;

int countOnes(int arr[], int low, int high)
{
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if ((mid == high || arr[mid + 1] == 0) && (arr[mid] == 1))
        {
            return mid + 1;
        }

        if (arr[mid] == 1)
        {
            return countOnes(arr, mid + 1, high);
        }

        return countOnes(arr, low, mid - 1);
    }
    return -1;
}

int main()
{
    int arr[] = {1, 1, 1, 1, 1, 1, 0, 0, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int ans = countOnes(arr, 0, n - 1);
    cout << ans;
}

/*

https://www.geeksforgeeks.org/count-1s-sorted-binary-array/
Count 1’s in a sorted binary array
Given a binary array arr[] of size N, which is sorted in non-increasing order, count the number of 1’s in it.

Examples:

Input: arr[] = {1, 1, 0, 0, 0, 0, 0}
Output: 2

Input: arr[] = {1, 1, 1, 1, 1, 1, 1}
Output: 7

Input: arr[] = {0, 0, 0, 0, 0, 0, 0}
Output: 0

*/