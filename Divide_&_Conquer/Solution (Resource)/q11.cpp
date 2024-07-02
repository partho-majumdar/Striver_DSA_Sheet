#include <bits/stdc++.h>
using namespace std;

string commonPrefix(string &s1, string &s2)
{
    int minLen = min(s1.length(), s2.length());
    for (int i = 0; i < minLen; i++)
    {
        if (s1[i] != s2[i])
        {
            return s1.substr(0, i);
        }
    }
    return s1.substr(0, minLen);
}

string longestCommonPrefix(string arr[], int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }

    int mid = low + (high - low) / 2;

    string leftPrefix = longestCommonPrefix(arr, low, mid);
    string rightPrefix = longestCommonPrefix(arr, mid + 1, high);

    return commonPrefix(leftPrefix, rightPrefix);
}

int main()
{
    string arr[] = {"Algolab", "Algorithms", "Algeria"};
    int n = sizeof(arr) / sizeof(arr[0]);
    string result = longestCommonPrefix(arr, 0, n - 1);
    cout << "The longest common prefix is: " << result << endl;
    return 0;
}