#include <bits/stdc++.h>
using namespace std;

void sorting(int arr[], int n)
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
    int n = 10;
    int arr[n] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8};

    // sorting(arr, n);

    map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]]++;
    }

    for (auto it : mp)
    {
        cout << it.first << " --> " << it.second << endl;
    }

    // for (int i = 0; i <= n - 1; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    return 0;
}

/*

https://www.geeksforgeeks.org/sort-elements-by-frequency/

Print the elements of an array in the decreasing frequency if 2 numbers have the same frequency then print the one which came first

Examples:

Input:  arr[] = {2, 5, 2, 8, 5, 6, 8, 8}
Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6}

Input: arr[] = {2, 5, 2, 6, -1, 9999999, 5, 8, 8, 8}
Output: arr[] = {8, 8, 8, 2, 2, 5, 5, 6, -1, 9999999}

2 -> 2
5 -> 2
6 -> 1
-1 -> 1
9999999 -> 1
8 -> 3

*/