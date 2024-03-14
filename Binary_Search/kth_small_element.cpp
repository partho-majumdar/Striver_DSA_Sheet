#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[][4] = {
        {10, 20, 30, 40},
        {15, 25, 35, 45},
        {24, 29, 37, 48},
        {32, 33, 39, 50}};

    int row = sizeof(arr) / sizeof(arr[0]);
    int col = 
    cout << row;
}

/*

Kth smallest element in a row-wise and column-wise sorted 2D array
Given an n x n matrix, where every row and column is sorted in non-decreasing order. Find the kth smallest element in the given 2D array.

Example,

Input:k = 3 and array =
        10, 20, 30, 40
        15, 25, 35, 45
        24, 29, 37, 48
        32, 33, 39, 50
Output: 20
Explanation: The 3rd smallest element is 20
Input:k = 7 and array =
        10, 20, 30, 40
        15, 25, 35, 45
        24, 29, 37, 48
        32, 33, 39, 50
Output: 30
Explanation: The 7th smallest element is 30

*/