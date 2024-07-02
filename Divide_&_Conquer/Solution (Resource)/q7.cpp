#include <bits/stdc++.h>
using namespace std;

void mergeSort(int arr[], int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;

    while (left <= mid && right <= high)
    {
        if (arr[left] >= arr[right])
        {
            temp.push_back(arr[left++]);
        }

        else if (arr[left] <= arr[right])
        {
            temp.push_back(arr[right++]);
        }
    }

    while (left <= mid)
    {
        temp.push_back(arr[left++]);
    }

    while (right <= high)
    {
        temp.push_back(arr[right++]);
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void divideMS(int arr[], int low, int high)
{
    if (low >= high)
    {
        return;
    }

    int mid = (low + high) / 2;
    divideMS(arr, low, mid);
    divideMS(arr, mid + 1, high);
    mergeSort(arr, low, mid, high);
}

int main()
{
    int arr[] = {3, 7, 5, 5, 5, -1};
    int n = sizeof(arr) / sizeof(arr[0]);
    divideMS(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}