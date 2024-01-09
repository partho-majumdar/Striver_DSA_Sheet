#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "aAqbAxoqzAax";

    map<char, int> mpp;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        mpp[ch]++;
    }

    for (auto i : mpp)
    {
        cout << i.first << "-->" << i.second << endl;
    }

    return 0;
}

// character occurrence using map