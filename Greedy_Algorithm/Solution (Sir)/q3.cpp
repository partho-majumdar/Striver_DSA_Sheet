// #include <bits/stdc++.h>
// using namespace std;

// void findMinCoins(int V)
// {
//     vector<int> denominations = {1000, 500, 100, 50, 20, 10, 5, 2, 1};

//     vector<int> result;

//     for (int i = 0; i < denominations.size(); i++)
//     {
//         while (V >= denominations[i])
//         {
//             V -= denominations[i];
//             result.push_back(denominations[i]);
//         }
//     }

//     cout << "Minimum coins required: " << result.size() << endl;
//     cout << "Coins used: ";
//     for (int coin : result)
//     {
//         cout << coin << " ";
//     }
//     cout << endl;
// }

// int main()
// {
//     int V;
//     cout << "Enter the value in Rs: ";
//     cin >> V;

//     findMinCoins(V);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

void findMinCoins(int value)
{
    vector<int> denominations = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
    vector<int> result;

    for (int coin : denominations)
    {
        while (value >= coin)
        {
            value -= coin;
            result.push_back(coin);
        }
    }

    cout << "Minimum coins required: " << result.size() << endl;
    cout << "Coins used: ";
    for (int coin : result)
    {
        cout << coin << " ";
    }
    cout << endl;
}

int main()
{
    int value;
    cout << "Enter the value in Rs: ";
    cin >> value;

    findMinCoins(value);
    return 0;
}
