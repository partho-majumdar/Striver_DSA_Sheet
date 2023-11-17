#include <bits/stdc++.h>
using namespace std;

int main()
{
    string str = "Hey there";
    int len = str.size();
    int len1 = str.length();

    str[len1 - 1] = 'E';

    cout << len << " " << len1 << " " << str[len - 1];
    return 0;
}