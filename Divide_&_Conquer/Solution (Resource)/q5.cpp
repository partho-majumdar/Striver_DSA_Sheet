#include <bits/stdc++.h>
using namespace std;

pair<double, double> RMaxMin(vector<double> arr, int low, int high)
{
    if (low == high)
    {
        return {arr[low], arr[low]};
    }

    int mid = (low + high) / 2;
    auto left = RMaxMin(arr, low, mid);
    auto right = RMaxMin(arr, mid + 1, high);

    double maxValue = max(left.first, right.first);
    double minValue = min(left.second, right.second);

    return {maxValue, minValue};
}

int main()
{
    vector<double> arr = {34, -1.5, 5, 6, -50.1, -6};
    int n = arr.size();
    auto ans = RMaxMin(arr, 0, n - 1);
    cout << "Max: " << ans.first << endl;
    cout << "Min: " << ans.second;
    return 0;
}