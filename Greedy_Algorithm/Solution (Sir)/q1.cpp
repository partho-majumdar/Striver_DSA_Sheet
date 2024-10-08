// #include <bits/stdc++.h>
// using namespace std;

// struct Item
// {
//     int weight;
//     int value;
//     int index;
// };

// bool compare(Item a, Item b)
// {
//     double r1 = (double)a.value / (double)a.weight;
//     double r2 = (double)b.value / (double)b.weight;
//     return r1 > r2;
// }

// void fractionalKnapsack(int W, vector<Item> &items)
// {
//     sort(items.begin(), items.end(), compare);

//     double totalProfit = 0.0;
//     vector<pair<int, double>> selectedItems;

//     for (auto &item : items)
//     {
//         if (W == 0)
//             break;

//         if (item.weight <= W)
//         {
//             W -= item.weight;
//             totalProfit += item.value;
//             selectedItems.push_back({item.index, (double)item.weight});
//         }
//         else
//         {
//             double fraction = (double)W / item.weight;
//             totalProfit += item.value * fraction;
//             selectedItems.push_back({item.index, W});
//             W = 0;
//         }
//     }

//     cout << "Selected items:\n";
//     for (auto &item : selectedItems)
//     {
//         cout << "Item " << item.first + 1 << ": " << item.second << " kg\n";
//     }
//     cout << "Total profit: " << totalProfit << " taka\n";
// }

// int main()
// {
//     int n, W;
//     cout << "Enter the number of items: ";
//     cin >> n;

//     vector<Item> items(n);

//     cout << "Enter weight and value of each item:\n";
//     for (int i = 0; i < n; i++)
//     {
//         cin >> items[i].weight >> items[i].value;
//         items[i].index = i;
//     }

//     cout << "Enter the capacity of the knapsack: ";
//     cin >> W;

//     fractionalKnapsack(W, items);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int weight;
    int value;
    int index;
};

bool compare(Item a, Item b)
{
    return (double)a.value / a.weight > (double)b.value / b.weight;
}

void fractionalKnapsack(int capacity, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare);

    double totalProfit = 0.0;
    vector<pair<int, double>> selectedItems;

    for (const auto &item : items)
    {
        if (capacity <= 0)
            break;

        if (item.weight <= capacity)
        {
            capacity -= item.weight;
            totalProfit += item.value;
            selectedItems.push_back({item.index, (double)item.weight});
        }
        else
        {
            double fraction = (double)capacity / item.weight;
            totalProfit += item.value * fraction;
            selectedItems.push_back({item.index, capacity});
            capacity = 0;
        }
    }

    cout << "Selected items:\n";
    for (const auto &item : selectedItems)
    {
        cout << "Item " << item.first + 1 << ": " << item.second << " kg\n";
    }
    cout << "Total profit: " << totalProfit << " taka\n";
}

int main()
{
    int itemCount, knapsackCapacity;

    cout << "Enter the number of items: ";
    cin >> itemCount;

    vector<Item> items(itemCount);

    cout << "Enter weight and value of each item:\n";
    for (int i = 0; i < itemCount; i++)
    {
        cin >> items[i].weight >> items[i].value;
        items[i].index = i;
    }

    cout << "Enter the capacity of the knapsack: ";
    cin >> knapsackCapacity;

    fractionalKnapsack(knapsackCapacity, items);

    return 0;
}
