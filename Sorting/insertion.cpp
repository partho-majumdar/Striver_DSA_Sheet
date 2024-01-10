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

*/