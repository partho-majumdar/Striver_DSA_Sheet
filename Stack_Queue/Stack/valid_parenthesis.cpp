#include <bits/stdc++.h>
using namespace std;

void validParenthesis(string s)
{
    vector<char> stk;

    for (auto i : s)
    {
        // cout << i << " ";
        if (i == '(' || i == '{' || i == '[')
        {
            stk.push_back(i);
        }
        else
        {
            if (stk.empty())
            {
                cout << "Invalid";
                return;
            }

            char top = stk.back();
            if (top == '[' && i == ']')
            {
                stk.pop_back();
            }
            else if (top == '{' && i == '}')
            {
                stk.pop_back();
            }
            else if (top == '(' && i == ')')
            {
                stk.pop_back();
            }
            else
            {
                cout << "Invalid";
                return;
            }
        }
    }
    if (stk.empty())
    {
        cout << "valid";
    }
}

int main()
{
    // string bracket = "{([)])}";
    string bracket = "]";
    validParenthesis(bracket);
    return 0;
}