#include <bits/stdc++.h>
using namespace std;

int minCoins(vector<int> &coins, int M)
{
    vector<int> dp(M + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= M; i++)
    {
        for (int coin : coins)
        {
            if (i >= coin && dp[i - coin] != INT_MAX)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return (dp[M] == INT_MAX) ? -1 : dp[M];
}

void printCoins(vector<int> &coins, int M)
{
    vector<int> dp(M + 1, INT_MAX);
    vector<int> coinUsed(M + 1, -1);
    dp[0] = 0;
    for (int i = 1; i <= M; i++)
    {
        for (int coin : coins)
        {
            if (i >= coin && dp[i - coin] != INT_MAX)
            {
                if (dp[i] > dp[i - coin] + 1)
                {
                    dp[i] = dp[i - coin] + 1;
                    coinUsed[i] = coin;
                }
            }
        }
    }

    if (dp[M] == INT_MAX)
    {
        cout << "Not possible to make change for " << M << " cents." << endl;
        return;
    }

    cout << "Coins used to make " << M << " cents: ";
    int current = M;
    while (current > 0)
    {
        cout << coinUsed[current] << " ";
        current -= coinUsed[current];
    }
    cout << endl;
}

int main()
{
    vector<int> coins = {1, 3, 4};
    int M = 6;

    int result = minCoins(coins, M);

    if (result != -1)
        cout << "The minimum number of coins required to make change for " << M << " cents is " << result << endl;
    else
        cout << "Not possible to make change for " << M << " cents." << endl;

    printCoins(coins, M);

    return 0;
}
