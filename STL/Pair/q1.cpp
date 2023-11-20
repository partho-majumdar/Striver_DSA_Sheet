#include <bits/stdc++.h>
using namespace std;

int main()
{
    pair<int, int> p = {1, 2};
    cout << p.first << endl;
    cout << p.second << endl;

    pair<int, pair<int, int>> p1 = {1, {3, 4}};

    cout << p1.first << endl;
    cout << p1.second.first << endl;  // 3
    cout << p1.second.second << endl; // 4

    pair<int, int> arr[] = {{10, 11}, {20, 21}, {30, 31}};

    cout << arr[0].second << endl;
    cout << arr[2].first << endl;

    return 0;
}