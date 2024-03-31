#include <bits/stdc++.h>
using namespace std;

int linear_search(int arr[], int n, int value)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == value)
        {
            return i;
        }
    }
    return 0;
}

int main()
{
    int n;
    cout << "Enter number of element: ";
    cin >> n;
    int arr[n];

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }

    int val;
    cin >> val;
    int found = linear_search(arr, n, val);
    cout << found;
    // if (found)
    // {
    //     cout << "Found it";
    // }
    // else
    // {
    //     cout << "Not found";
    // }
    return 0;
}
