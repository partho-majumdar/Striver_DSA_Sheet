#include <bits/stdc++.h>
using namespace std;

int my_partition(int arr[], int start, int end)
{
    int pos = start;
    for (int i = start; i <= end; i++)
    {
        if (arr[i] <= arr[end])
        {
            swap(arr[i], arr[pos]);
            pos++;
        }
    }
    return pos - 1;
}

void quick_sort(int arr[], int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int pivot = my_partition(arr, start, end);
    quick_sort(arr, start, pivot - 1);
    quick_sort(arr, pivot + 1, end);
}

int main()
{
    int arr[] = {5, 9, 8, 1, 2, 7, 4, 6, 3, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

/*

#include <bits/stdc++.h>
using namespace std;

void quick_sort(int arr[], int low, int high)
{
    int start = low;
    int end = high;
    int mid = start + (end - start) / 2;
    int pivot = arr[mid];

    if (low >= high)
    {
        return;
    }

    while (start <= end)
    {
        while (arr[start] < pivot)
        {
            start++;
        }

        while (arr[end] > pivot)
        {
            end--;
        }

        if (start <= end)
        {
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            start++;
            end--;
        }
    }
    quick_sort(arr, low, end);
    quick_sort(arr, start, high);
}

int main()
{
    int arr[] = {5, 9, 8, 1, 2, 7, 4, 6, 3, 10};
    int n = sizeof(arr) / sizeof(arr[0]);

    quick_sort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

*/