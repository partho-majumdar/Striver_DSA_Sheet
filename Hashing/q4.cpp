#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;

    // pre-store
    int hashArr[256] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hashArr[s[i]]++;
    }

    int q;
    cout << "Enter number of query: ";
    cin >> q;

    // fetching
    while (q--)
    {
        char ch;
        cout << "Enter the character: ";
        cin >> ch;

        cout << hashArr[ch] << endl;
    }

    return 0;
}

// character occurrence for all 256 latter
