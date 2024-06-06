#include <bits/stdc++.h>
using namespace std;

int isPalindrome(string str, int start, int end)
{
    if (start >= end)
    {
        return 1;
    }

    else if (str[start] != str[end])
    {
        return 0;
    }

    return isPalindrome(str, start + 1, end - 1);
}

int main()
{
    string str = "madam";
    int n = str.length();
    int ans = isPalindrome(str, 0, n - 1);

    if (ans)
    {
        cout << "Palindrome";
    }
    else
    {
        cout << "Not Palindrome";
    }
    return 0;
}