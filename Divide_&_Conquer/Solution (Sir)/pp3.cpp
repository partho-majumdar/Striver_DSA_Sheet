#include <bits/stdc++.h>
using namespace std;

int mergeBoth(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    int cnt = 0;

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }

        else if (arr[left] >= arr[right])
        {
            temp.push_back(arr[right]);
            cnt += (mid - left + 1);
            right++;
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }

    return cnt;
}

int divideMS(int arr[], int low, int high)
{
    int cnt = 0;
    if (low >= high)
    {
        return cnt;
    }

    int mid = (low + high) / 2;
    cnt += divideMS(arr, low, mid);
    cnt += divideMS(arr, mid + 1, high);
    cnt += mergeBoth(arr, low, mid, high);
    return cnt;
}

int main()
{
    int arr[] = {8, 4, -1, 2, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = divideMS(arr, 0, n - 1);
    cout << result;
    return 0;
}
