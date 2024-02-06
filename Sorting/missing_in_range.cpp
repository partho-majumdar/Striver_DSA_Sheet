#include <bits/stdc++.h>
using namespace std;

void missing_sort_in_range(int arr[], int n, int low, int high)
{
    for (int i = low; i <= high; i++)
    {
        int flag = 0;
        for (int j = 0; j <= n - 1; j++)
        {
            if (arr[j] == i)
            {
                flag = 1;
            }
        }
        if (flag == 0)
        {
            cout << i << " ";
        }
    }
}

int main()
{
    int n = 4;
    int arr[n] = {10, 12, 11, 15};

    int low = 10;
    int high = 15;

    missing_sort_in_range(arr, n, low, high);

    return 0;
}

/*

https://www.geeksforgeeks.org/find-missing-elements-of-a-range/

Given an array, arr[0..n-1] of distinct elements and a range [low, high], find all numbers that are in a range, but not the array. The missing elements should be printed in sorted order.

Examples:

Input: arr[] = {10, 12, 11, 15},
       low = 10, high = 15
Output: 13, 14
Input: arr[] = {1, 14, 11, 51, 15},
       low = 50, high = 55
Output: 50, 52, 53, 54, 55

*/