#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter number of element in array: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // pre-store
    int hashArr[12] = {0};
    for (int i = 0; i < n; i++)
    {
        hashArr[arr[i]]++;
    }

    // fetch
    int q;
    cout << "Enter number of query: ";
    cin >> q;
    while (q > 0)
    {
        int num;
        cout << "Enter number to see its occurrences: ";
        cin >> num;
        cout << "Ans: " << hashArr[num] << endl;
        q--;
    }

    return 0;
}

// how many times a number occur using hashing technique