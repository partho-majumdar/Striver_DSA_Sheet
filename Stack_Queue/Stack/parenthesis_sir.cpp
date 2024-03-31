#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<char> stk;
    string brackets = "]";
    // cin >> brackets;

    for (char c : brackets)
    {
        if (c == '(' || c == '{' || c == '[')
        {
            stk.push_back(c);
        }
        else
        {
            if (c == ')' || c == '}' || c == ']')
            {
                cout << "Invalid";
                // break;
            }
            char t = stk.back();
            if (c == ')' && t == '(')
            {
                stk.pop_back();
            }
            else if (c == '}' && t == '{')
            {
                stk.pop_back();
            }
            else if (c == ']' && t == '[')
            {
                stk.pop_back();
            }
            else
            {
                cout << "Invalid Sequence" << endl;
                return 0;
            }
        }
    }
    if (stk.empty())
    {
        cout << "Valid Sequence" << endl;
    }
}
