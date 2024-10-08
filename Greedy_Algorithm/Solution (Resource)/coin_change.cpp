#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void makeChange(int N, const vector<int> &denominations)
{
    vector<int> coinCount(denominations.size(), 0);
    int totalCoins = 0;

    for (size_t i = 0; i < denominations.size(); i++)
    {
        if (N <= 0)
        {
            break;
        }
        coinCount[i] = N / denominations[i];
        N %= denominations[i];
        totalCoins += coinCount[i];
    }

    // Output results
    for (size_t i = 0; i < denominations.size(); i++)
    {
        if (coinCount[i] > 0)
        {
            cout << denominations[i] << " cents --- " << coinCount[i] << endl;
        }
    }
    cout << "Total " << totalCoins << " coins" << endl;
}

int main()
{
    int N;
    cout << "Enter the amount in cents (N): ";
    cin >> N;

    vector<int> denominations = {25, 10, 5, 1};

    makeChange(N, denominations);

    return 0;
}
