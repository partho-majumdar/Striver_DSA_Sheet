#include <bits/stdc++.h>
using namespace std;

int print_count_even(int arr[], int n)
{
    if (n == 0)
    {
        return 0;
    }

    int count = print_count_even(arr, n - 1);

    if (arr[n - 1] % 2 == 0)
    {
        cout << arr[n - 1] << " ";
        count++;
    }

    return count;
}

int main()
{
    int arr[] = {3, 5, 7, 8, 9, 11, 14};
    int n = sizeof(arr) / sizeof(arr[0]);

    int count = print_count_even(arr, n);
    cout << "\nNumber of even numbers: " << count << endl;

    return 0;
}
