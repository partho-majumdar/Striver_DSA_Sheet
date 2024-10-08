#include <bits/stdc++.h>
using namespace std;

int minCostToFormRope(int M, vector<int> &ropes, int X)
{
    vector<int> dp(M + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= M; i++)
    {
        for (int rope : ropes)
        {
            if (i >= rope)
            {
                dp[i] = min(dp[i], dp[i - rope] + X);
            }
        }
    }

    return (dp[M] == INT_MAX) ? -1 : dp[M];
}

int main()
{
    vector<int> ropes = {1, 3, 4};
    int M = 10;
    int X = 2;
    int result = minCostToFormRope(M, ropes, X);

    if (result != -1)
    {
        cout << "The minimum cost to form a rope of length " << M << " meters is: " << result << " dollars." << endl;
    }
    else
    {
        cout << "It is not possible to form a rope of length " << M << " meters with the given ropes." << endl;
    }

    return 0;
}
