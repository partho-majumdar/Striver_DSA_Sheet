#include <bits/stdc++.h>
using namespace std;

void sort_even_increase(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 2 - i; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void sort_odd_decrease(int arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 2 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

int main()
{
    int arr[] = {3, 1, 2, 4, 5, 9, 13, 14, 12};
    int n = sizeof(arr) / sizeof(arr[0]);

    int oddArr[n];
    int oddI = 0;

    int evenArr[n];
    int evenI = 0;

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0)
        {
            evenArr[evenI++] = arr[i];
        }

        else if (i % 2 != 0)
        {
            oddArr[oddI++] = arr[i];
        }
    }

    sort_even_increase(evenArr, evenI);
    sort_odd_decrease(oddArr, oddI);

    for (int i = 0; i < evenI; i++)
    {
        cout << evenArr[i] << " ";
    }

    for (int i = 0; i < oddI; i++)
    {
        cout << oddArr[i] << " ";
    }
    return 0;
}

/*

https://www.geeksforgeeks.org/sort-even-placed-elements-increasing-odd-placed-decreasing-order/
We are given an array of n distinct numbers. The task is to sort all even-placed numbers in increasing and odd-placed numbers in decreasing order. The modified array should contain all sorted even-placed numbers followed by reverse sorted odd-placed numbers.

Note that the first element is considered as even placed because of its index 0.

Examples:

Input:  arr[] = {0, 1, 2, 3, 4, 5, 6, 7}
Output: arr[] = {0, 2, 4, 6, 7, 5, 3, 1}
Even-place elements : 0, 2, 4, 6
Odd-place elements : 1, 3, 5, 7
Even-place elements in increasing order :
0, 2, 4, 6
Odd-Place elements in decreasing order :
7, 5, 3, 1

Input: arr[] = {3, 1, 2, 4, 5, 9, 13, 14, 12}
Output: {2, 3, 5, 12, 13, 14, 9, 4, 1}
Even-place elements : 3, 2, 5, 13, 12
Odd-place elements : 1, 4, 9, 14
Even-place elements in increasing order :
2, 3, 5, 12, 13
Odd-Place elements in decreasing order :
14, 9, 4, 1

*/