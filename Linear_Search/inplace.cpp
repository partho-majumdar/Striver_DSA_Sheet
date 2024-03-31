#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[] = {8, 1, 5, 2, 2, 3, 2, 7, 8, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int arr2[10] = {0};

    for (int i = 0; i < n; i++)
    {
        arr2[arr[i]]++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
}