#include <bits/stdc++.h>
using namespace std;

void print_odd(vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return;
    }

    if (start == end)
    {
        if (arr[start] % 2 != 0)
        {
            cout << arr[start] << " ";
        }
        return;
    }

    int mid = (start + end) / 2;

    print_odd(arr, start, mid);
    print_odd(arr, mid + 1, end);
}

int main()
{
    vector<int> arr = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    cout << "Odd numbers in the array: ";
    print_odd(arr, 0, arr.size() - 1);

    return 0;
}
