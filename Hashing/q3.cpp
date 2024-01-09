#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cout << "Enter string: ";
    cin >> s;

    // pre-store
    int hashArr[26] = {0};
    for (int i = 0; i < s.size(); i++)
    {
        hashArr[s[i] - 'a']++;
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

        cout << hashArr[ch - 'a'] << endl;
    }

    return 0;
}

// character occurrence