#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Item
{
    string name;
    double value;
    double weight;
    double ratio;
};

bool compareRatio(Item a, Item b)
{
    return a.ratio > b.ratio;
}

int main()
{
    int n;
    cin >> n;

    vector<Item> items(n);
    for (int i = 0; i < n; i++)
    {
        cin >> items[i].name >> items[i].value >> items[i].weight;
        items[i].ratio = items[i].value / items[i].weight;
    }

    int k;
    cin >> k;
    vector<double> capacity(k);
    for (int i = 0; i < k; i++)
    {
        cin >> capacity[i];
    }

    vector<Item> remaining = items;
    int thieves_needed = 0;

    cout << fixed << setprecision(1);

    for (int t = 0; t < k; t++)
    {
        if (remaining.empty())
            break;

        sort(remaining.begin(), remaining.end(), compareRatio);

        double current_capacity = capacity[t];
        double profit = 0;
        bool took_something = false;

        vector<pair<string, pair<double, double>>> thief_items;

        for (int i = 0; i < remaining.size() && current_capacity > 0; i++)
        {
            double can_take = min(remaining[i].weight, current_capacity);
            if (can_take > 0)
            {
                took_something = true;
                double proportion = can_take / remaining[i].weight;
                double value_taken = remaining[i].value * (can_take / remaining[i].weight);
                profit += value_taken;

                string name_without_dust = remaining[i].name;
                if (name_without_dust.length() > 5 && name_without_dust.substr(name_without_dust.length() - 5) == "-dust")
                {
                    name_without_dust = name_without_dust.substr(0, name_without_dust.length() - 5);
                }

                thief_items.push_back({name_without_dust, {can_take, value_taken}});

                remaining[i].weight -= can_take;
                remaining[i].value -= value_taken;
                current_capacity -= can_take;
            }
        }

        if (took_something)
        {
            thieves_needed++;
            for (const auto &item : thief_items)
            {
                cout << "Taking " << item.first << ": "
                     << item.second.first << " kg "
                     << item.second.second << " taka\n";
            }
            cout << "Thief " << t + 1 << " profit: " << profit << " taka\n";
        }

        remaining.erase(
            remove_if(remaining.begin(), remaining.end(),
                      [](Item &i)
                      { return i.weight <= 0.001; }),
            remaining.end());
    }

    cout << "Total " << thieves_needed << " thieves stole from the warehouse.\n";

    return 0;
}