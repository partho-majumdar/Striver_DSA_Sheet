#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;
    int arr[n] = {6, 5, 4, 3, 2, 1};
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}

/*

select an element and put it in correct index
sort till index 0
                1
                2
                3
                4

Worst and avg T.C --> O(N^2)
Best T.C --> O(N)

#include <bits/stdc++.h>
using namespace std;

void insertionSort(int arr[], int n)
{
    for (int i = 0; i <= n - 2; i++)
    {
        for (int j = i + 1; j > 0; j--)
        {
            if (arr[j] < arr[j - 1])
            {
                swap(arr[j], arr[j - 1]);
            }
            else
            {
                break;
            }
        }
    }
}

int main()
{
    int n = 5;
    int arr[n] = {5, 4, 3, 2, 1};

    insertionSort(arr, n);

    for (int i = 0; i <= n - 1; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

*/
