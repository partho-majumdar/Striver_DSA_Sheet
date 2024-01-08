#include <bits/stdc++.h>
using namespace std;

bool revStr(string s, int i)
{
    if (i >= s.size() / 2)
    {
        return true;
    }
    if (s[i] != s[s.size() - i - 1])
    {
        return false;
    }
    return revStr(s, i + 1);
}

int main()
{
    string s = "madam";
    bool ans = revStr(s, 0);
    cout << ans;
    return 0;
}

// string palindrome --> MADAM