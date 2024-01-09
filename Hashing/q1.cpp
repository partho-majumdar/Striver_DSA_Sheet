#include <bits/stdc++.h>
using namespace std;

int main()
{
    int arr[6] = {1, 2, 3, 2, 4, 2};
    int num = 2;
    int count = 0;

    for (int i = 0; i < sizeof(arr) / sizeof(int); i++)
    {
        if (arr[i] == num)
        {
            count++;
        }
    }
    cout << count;
    return 0;
}

// find a number how many time it occurs