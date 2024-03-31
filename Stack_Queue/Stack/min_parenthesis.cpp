#include <bits/stdc++.h>
using namespace std;

int minAddToMakeValid(string s)
{
    vector<char> stk;
    int cnt = 0;

    for (auto i : s)
    {
        if (i == '(')
        {
            stk.push_back(i);
        }
        else
        {
            if (stk.empty())
            {
                cnt++;
            }
            else
            {
                stk.pop_back();
            }
        }
    }
    return cnt + stk.size();
}

int main()
{
    string s = "(())))";
    int ans = minAddToMakeValid(s);
    cout << ans;
    return 0;
}

// https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/?source=submission-ac
/*

    (()) )) -> ans 2 cause need 2 bracket for valid

*/