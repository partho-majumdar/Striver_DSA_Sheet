#include <bits/stdc++.h>
using namespace std;

int calc_sum(vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return 0;
    }

    if (start == end)
    {
        if (arr[start] % 2 == 0)
        {
            return arr[start];
        }
        return 0;
    }

    int mid = (start + end) / 2;

    int leftSum = calc_sum(arr, start, mid);
    int rightSum = calc_sum(arr, mid + 1, end);

    return leftSum + rightSum;
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    int sum_even = calc_sum(arr, 0, arr.size() - 1);
    cout << "Sum of even numbers in the array: " << sum_even << endl;

    return 0;
}
