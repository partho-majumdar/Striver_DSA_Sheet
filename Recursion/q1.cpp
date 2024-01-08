#include <bits/stdc++.h>
using namespace std;

int count = 0;
void func()
{
    cout << ::count << endl;
    ::count++;
    func();
}

int main()
{
    func();
    return 0;
}