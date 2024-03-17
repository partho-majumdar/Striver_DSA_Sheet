#include <bits/stdc++.h>
using namespace std;

int find_ceil(int arr[], int low, int high, int value)
{
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= value)
        {
            ans = arr[mid];
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int find_floor(int arr[], int low, int high, int value)
{
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] <= value)
        {
            ans = arr[mid];
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{
    int n = 5;
    int arr[n] = {10, 20, 30, 40, 50};
    int low = 0;
    int high = n - 1;
    int value = 25;
    int floor_ans = find_floor(arr, low, high, value);
    int ceil_ans = find_ceil(arr, low, high, value);
    cout << "Floor: " << floor_ans << endl;
    cout << "Ceil: " << ceil_ans << endl;
    return 0;
}

// find floor and ceil