#include <bits/stdc++.h>
using namespace std;

bool balanced_parentheses(string str, int index, int balance)
{
    if (index == str.length())
    {
        return balance = 0;
    }

    if (balance < 0)
    {
        return false;
    }

    if (str[index] == '(')
    {
        return balanced_parentheses(str, index + 1, balance + 1);
    }

    else if (str[index] == ')')
    {
        return balanced_parentheses(str, index + 1, balance + 1);
    }

    else
    {
        return balanced_parentheses(str, index + 1, balance);
    }
}

int main()
{
    string str = "(((()))))";
    bool ans = balanced_parentheses(str, 0, 0);

    if (ans)
    {
        cout << "Balanced";
    }
    else
    {
        cout << "Not balanced";
    }

    return 0;
}