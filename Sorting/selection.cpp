#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n = 6;
    int arr[n] = {13, 46, 24, 52, 20, 9};

    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;
        for (int j = i; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// get the minimum and swap it (put minimum value in front) best/worst/avg T.C --> O(N^2)