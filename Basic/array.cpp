#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 1d array
    int arr[5];
    cout << "Enter 5 number: ";
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3] >> arr[4];
    arr[3] += 10; // modify
    cout << "Ans: ";
    cout << arr[3];

    // 2d array
    int arr1[2][3];
    arr1[1][2] = 12;
    cout << arr1[1][1]; // give some random garbage value
    return 0;
}