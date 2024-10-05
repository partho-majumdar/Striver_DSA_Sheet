#include <bits/stdc++.h>
using namespace std;

bool compare_end_time(pair<int, int> &a, pair<int, int> &b)
{
    return a.second <= b.second;
}

void compatible_activity(vector<pair<int, int>> &events)
{
    sort(events.begin(), events.end(), compare_end_time);

    int last_finish_time = -1;

    for (size_t i = 0; i < events.size(); i++)
    {
        if (events[i].first >= last_finish_time)
        {
            cout << "(" << events[i].first << ", " << events[i].second << ") ";
            last_finish_time = events[i].second;
        }
    }
}

int main()
{
    vector<pair<int, int>> events = {{5, 9}, {1, 2}, {3, 4}, {0, 6}, {5, 7}, {8, 9}, {1, 7}, {3, 7}};
    compatible_activity(events);
    return 0;
}