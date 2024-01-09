#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cout << "Enter of element: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // pre-store
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int value = arr[i];
        mpp[value]++;
        // mpp[arr[i]]++; shortcut
    }

    // print map value
    for (auto i : mpp)
    {
        cout << i.first << "-->" << i.second << endl;
    }

    // fetch
    int q;
    cout << "Enter number of query: ";
    cin >> q;
    while (q--)
    {
        int num;
        cout << "Enter number to see its occurrence: ";
        cin >> num;

        cout << mpp[num] << endl;
    }

    return 0;
}

// if value 10^7+ then use map