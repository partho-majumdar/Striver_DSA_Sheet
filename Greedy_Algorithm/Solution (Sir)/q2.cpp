// #include <bits/stdc++.h>
// using namespace std;

// struct Activity
// {
//     int start;
//     int finish;
// };

// bool compare(Activity a, Activity b)
// {
//     return a.finish < b.finish;
// }

// void activitySelection(vector<Activity> &activities)
// {
//     sort(activities.begin(), activities.end(), compare);

//     cout << "Selected activities:\n";

//     int lastFinishTime = activities[0].finish;
//     cout << "Activity (start: " << activities[0].start << ", finish: " << activities[0].finish << ")\n";

//     for (int i = 1; i < activities.size(); i++)
//     {
//         if (activities[i].start >= lastFinishTime)
//         {
//             cout << "Activity (start: " << activities[i].start << ", finish: " << activities[i].finish << ")\n";
//             lastFinishTime = activities[i].finish;
//         }
//     }
// }

// int main()
// {
//     int n;
//     cout << "Enter the number of activities: ";
//     cin >> n;

//     vector<Activity> activities(n);

//     cout << "Enter the start and finish times of the activities:\n";
//     for (int i = 0; i < n; i++)
//     {
//         cout << "Activity " << i + 1 << " start and finish time: ";
//         cin >> activities[i].start >> activities[i].finish;
//     }

//     activitySelection(activities);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct Activity
{
    int start, finish;
};

bool compare(const Activity &a, const Activity &b)
{
    return a.finish < b.finish;
}

void activitySelection(vector<Activity> &activities)
{
    sort(activities.begin(), activities.end(), compare);
    cout << "Selected activities:\n";

    int lastFinishTime = activities[0].finish;
    cout << "Activity (start: " << activities[0].start << ", finish: " << activities[0].finish << ")\n";

    for (size_t i = 1; i < activities.size(); i++)
    {
        if (activities[i].start >= lastFinishTime)
        {
            cout << "Activity (start: " << activities[i].start << ", finish: " << activities[i].finish << ")\n";
            lastFinishTime = activities[i].finish;
        }
    }
}

int main()
{
    int n;
    cout << "Enter the number of activities: ";
    cin >> n;

    vector<Activity> activities(n);
    for (int i = 0; i < n; i++)
    {
        cin >> activities[i].start >> activities[i].finish;
    }

    activitySelection(activities);
    return 0;
}
