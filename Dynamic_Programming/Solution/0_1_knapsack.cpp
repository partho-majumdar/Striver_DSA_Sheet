// #include <iostream>
// #include <vector>

// using namespace std;

// int knapsack(int n, int W, vector<int> &weights, vector<int> &values)
// {
//     int dp[n + 1][W + 1];

//     for (int i = 0; i <= n; i++)
//     {
//         for (int j = 0; j <= W; j++)
//         {
//             if (i == 0 || j == 0)
//             {
//                 dp[i][j] = 0;
//             }
//         }
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= W; j++)
//         {
//             if (weights[i - 1] <= j)
//             {
//                 dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + values[i - 1]);
//             }
//             else
//             {
//                 dp[i][j] = dp[i - 1][j];
//             }
//         }
//     }

//     int i = n, j = W;
//     vector<int> includedItems;
//     while (i > 0 && j > 0)
//     {
//         if (dp[i][j] != dp[i - 1][j])
//         {
//             includedItems.push_back(i);
//             j -= weights[i - 1];
//         }
//         i--;
//     }

//     cout << "Included items: ";
//     for (int item : includedItems)
//     {
//         cout << item << " ";
//     }
//     cout << endl;
//     cout << "Maximum profit: " << dp[n][W] << endl;

//     return dp[n][W];
// }

// int main()
// {
//     int n, W;
//     cin >> n;

//     vector<int> weights(n);
//     vector<int> values(n);
//     for (int i = 0; i < n; i++)
//     {
//         cin >> weights[i] >> values[i];
//     }

//     cin >> W;

//     int maxProfit = knapsack(n, W, weights, values);

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

// Function to solve the 0/1 Knapsack problem using memoization
int knapsackUtil(vector<int> &wt, vector<int> &val, int ind, int W, vector<vector<int>> &dp)
{
    // Base case: If there are no items left or the knapsack has no capacity, return 0
    if (ind == 0)
    {
        // If the only item can fit in the knapsack, return its value, otherwise return 0
        if (wt[0] <= W)
            return val[0];
        else
            return 0;
    }

    // If the result for this state is already calculated, return it
    if (dp[ind][W] != -1)
    {
        return dp[ind][W];
    }

    // Calculate the maximum value by either excluding the current item or including it
    int notTaken = knapsackUtil(wt, val, ind - 1, W, dp);
    int taken = 0;

    // Check if the current item can be included without exceeding the knapsack's capacity
    if (wt[ind] <= W)
    {
        taken = val[ind] + knapsackUtil(wt, val, ind - 1, W - wt[ind], dp);
    }

    // Store the result in the DP table and return
    return dp[ind][W] = max(notTaken, taken);
}

// Function to solve the 0/1 Knapsack problem
int knapsack(vector<int> &wt, vector<int> &val, int n, int W)
{
    vector<vector<int>> dp(n, vector<int>(W + 1, -1));
    return knapsackUtil(wt, val, n - 1, W, dp);
}

int main()
{
    vector<int> wt = {4, 3, 2, 1};
    vector<int> val = {20, 9, 12, 7};
    int W = 5;
    int n = wt.size();

    cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, n, W);

    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// // Function to solve the 0/1 Knapsack problem using dynamic programming
// int knapsack(vector<int> &wt, vector<int> &val, int n, int W)
// {
//     // Create a 2D DP table with dimensions n x W+1 and initialize it with zeros
//     vector<vector<int>> dp(n, vector<int>(W + 1, 0));

//     // Base condition: Fill in the first row for the weight of the first item
//     for (int i = wt[0]; i <= W; i++)
//     {
//         dp[0][i] = val[0];
//     }

//     // Fill in the DP table using a bottom-up approach
//     for (int ind = 1; ind < n; ind++)
//     {
//         for (int cap = 0; cap <= W; cap++)
//         {
//             // Calculate the maximum value by either excluding the current item or including it
//             int notTaken = dp[ind - 1][cap];
//             int taken = INT_MIN;

//             // Check if the current item can be included without exceeding the knapsack's capacity
//             if (wt[ind] <= cap)
//             {
//                 taken = val[ind] + dp[ind - 1][cap - wt[ind]];
//             }

//             // Update the DP table
//             dp[ind][cap] = max(notTaken, taken);
//         }
//     }

//     // The final result is in the last cell of the DP table
//     return dp[n - 1][W];
// }

// int main()
// {
//     vector<int> wt = {4, 3, 2, 1};
//     vector<int> val = {20, 9, 12, 7};
//     int W = 5;
//     int n = wt.size();

//     cout << "The Maximum value of items the thief can steal is " << knapsack(wt, val, n, W);

//     return 0;
// }
