#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<int> v; // {} create empty container vector size dynamic but array size fixed

    v.push_back(1);
    v.emplace_back(2);
    cout << v[1] << endl;

    // pair in vector
    vector<pair<int, int>> vec;
    vec.push_back({1, 2});
    // vec.emplace_back((1, 2));

    vector<int> v1(5, 100); // {100, 100, 100, 100, 100}
    vector<int> v11(5);     // {0, 0, 0, 0, 0}

    vector<int> v2(5, 20); // {20, 20, 20, 20, 20}
    vector<int> v3(v2);    // copy v2 in v3

    vector<int> v4(3, 10); // {10, 10, 10}
    v4.push_back(11);      // {10, 10, 10, 11}
    cout << v4[3] << endl; // 11

    // iterate vector
    vector<int> vec1{10, 18, 46, 23, 27, 32};
    vector<int>::iterator it = vec1.begin();
    it++;
    cout << *(it) << endl; // 18

    vector<int> v5{10, 20, 30, 40};
    cout << v5.back() << endl; // 40
    vector<int>::iterator it1 = v5.end();
    it1--;
    cout << *(it1) << endl;

    // iterate vector using for loop
    vector<int> vec13{10, 20, 30, 40};
    for (vector<int>::iterator it = vec13.begin(); it != vec13.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << endl;

    // auto assignation
    vector<int> vec14{11, 22, 33, 44};
    for (auto it = vec14.begin(); it != vec14.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << endl;

    // erase
    vector<int> e1{10, 11, 12, 13, 14, 15, 16, 17};
    // e1.erase(e1.begin()); // erase only one elements
    e1.erase(e1.begin() + 2, e1.begin() + 4);

    for (auto it = e1.begin(); it != e1.end(); it++)
    {
        cout << *(it) << " ";
    }

    cout << endl;

    // insert element in vector
    vector<int> v6(2, 100);
    v6.insert(v6.begin(), 300);
    // v6.insert(v.begin() + 1, 2, 10, 10);

    for (auto i = v6.begin(); i != v6.end(); i++)
    {
        cout << *(i) << " ";
    }

    cout << endl;

    return 0;
}
