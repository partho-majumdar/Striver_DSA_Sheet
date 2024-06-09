#include <bits/stdc++.h>
using namespace std;

int find_matrix_max(vector<vector<int>> &arr, int row, int col)
{
    if (row >= arr.size())
    {
        return INT_MIN;
    }

    if (col >= arr[row].size())
    {
        return find_matrix_max(arr, row + 1, 0);
    }

    int current = arr[row][col];
    int maxInRest = find_matrix_max(arr, row, col + 1);

    return max(current, maxInRest);
}

int main()
{
    vector<vector<int>> arr = {
        {3, 8, 2},
        {4, 70, 6, 1},
        {5, 9, 1}};

    if (arr.empty())
    {
        cout << "The array is empty." << endl;
    }

    int maxVal = find_matrix_max(arr, 0, 0);
    cout << "Maximum value: " << maxVal << endl;

    return 0;
}
