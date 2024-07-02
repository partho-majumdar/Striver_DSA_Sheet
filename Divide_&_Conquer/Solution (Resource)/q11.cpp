#include <iostream>
#include <string>
using namespace std;

string commonPrefix(const string &s1, const string &s2)
{
    int minLength = min(s1.length(), s2.length());
    for (int i = 0; i < minLength; i++)
    {
        if (s1[i] != s2[i])
        {
            return s1.substr(0, i);
        }
    }
    return s1.substr(0, minLength);
}

string longestCommonPrefix(string arr[], int low, int high)
{
    if (low == high)
    {
        return arr[low];
    }

    if (high > low)
    {
        int mid = low + (high - low) / 2;

        string s1 = longestCommonPrefix(arr, low, mid);

        string s2 = longestCommonPrefix(arr, mid + 1, high);

        return commonPrefix(s1, s2);
    }
    return "";
}

int main()
{
    string arr[] = {
        "Algolab",
        "Algorithms",
        "Algeria"};
    int n = sizeof(arr) / sizeof(arr[0]);
    string result = longestCommonPrefix(arr, 0, n - 1);
    cout << "The longest common prefix is: " << result << endl;
    return 0;
}