#include <bits/stdc++.h>
using namespace std;

bool isPrime(int val)
{
    if (val <= 1)
    {
        return false;
    }

    else if (val == 2)
    {
        return true;
    }

    else if (val % 2 == 0)
    {
        return false;
    }

    else
    {
        for (int i = 3; i <= sqrt(val); i += 2)
        {
            if (val % i == 0)
            {
                return false;
            }
        }
    }
    return true;
}

int countPrime(vector<vector<int>> &arr, int row, int col)
{
    if (row >= arr.size())
    {
        return 0;
    }

    else if (col >= arr[row].size())
    {
        return countPrime(arr, row + 1, 0);
    }

    int count = 0;
    if (isPrime(arr[row][col]))
    {
        count = 1;
    }

    return count + countPrime(arr, row, col + 1);
}

int main()
{
    vector<vector<int>> arr = {
        {2, 3, 4},
        {5, 6, 7, 23},
        {8, 9, 10}};

    int ans = countPrime(arr, 0, 0);
    cout << ans;
    return 0;
}