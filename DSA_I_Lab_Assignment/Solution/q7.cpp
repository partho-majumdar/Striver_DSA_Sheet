#include <bits/stdc++.h>
using namespace std;

void find_occurrence(int n)
{
    queue<int> que;

    int i = 0;
    while (i < n)
    {
        que.push(rand() % 100 + 1);
        i++;
    }

    map<int, int> occurrence;

    while (!que.empty())
    {
        occurrence[que.front()]++;
        que.pop();
    }

    int max = INT_MIN;

    for (auto i : occurrence)
    {
        if (i.second > max)
        {
            max = i.second;
        }
    }

    for (auto i : occurrence)
    {
        if (i.second == max)
        {
            cout << i.first << ", ";
        }
    }

    cout << "Occurred " << max << " times" << endl;
}

int main()
{
    int n;
    cout << "How many numbers do you want to generate: ";
    cin >> n;
    find_occurrence(n);
    return 0;
}
