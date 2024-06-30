#include <bits/stdc++.h>
using namespace std;

void findMaxMin(double arr[], int low, int high, double &max_value, double &min_value)
{
    if (low == high)
    {
        max_value = min_value = arr[low];
        return;
    }

    else if (low + 1 == high)
    {
        if (arr[low] < arr[high])
        {
            max_value = arr[high];
            min_value = arr[low];
        }
    }

    int mid = (low + high) / 2;
    double left_min, left_max, right_min, right_max;

    findMaxMin(arr, low, mid, left_max, left_min);
    findMaxMin(arr, mid + 1, high, right_max, right_min);

    max_value = max(left_max, right_max);
    min_value = min(left_min, right_min);
}

int main()
{
    double arr[] = {34, -1.5, 5, 6, -50.1, -6};
    int n = sizeof(arr) / sizeof(arr[0]);
    double max_value = INT_MIN;
    double min_value = INT_MAX;

    findMaxMin(arr, 0, n - 1, max_value, min_value);
    cout << "Max: " << max_value << endl;
    cout << "Min: " << min_value << endl;
    return 0;
}