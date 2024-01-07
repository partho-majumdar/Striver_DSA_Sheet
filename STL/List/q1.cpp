#include <bits/stdc++.h>
using namespace std;

int main()
{
    list<int> ls = {1, 2, 3, 4, 5, 6, 7};
    // ls.push_back(1);
    // ls.push_back(2);
    // ls.push_back(3);
    // ls.push_back(4);

    ls.erase(next(ls.begin(), 1), next(ls.begin(), 3));
    // ls.insert((ls.begin(), 10));

    cout << ls.back() << endl;

    for (auto i = ls.begin(); i != ls.end(); i++)
    {
        cout << *i << " ";
    }

    cout << endl;

    return 0;
}