// #include <bits/stdc++.h>
// using namespace std;

// // Function to solve the rod cutting problem using memoization
// int solve(int index, int target, vector<int> &nums, vector<vector<int>> &dp) {
//     if (index == 0) {
//         return target * nums[0]; // When there's only one length, we take all of it.
//     }

//     if (dp[index][target] != -1) {
//         return dp[index][target]; // Return cached value if already computed
//     }

//     int not_take = solve(index - 1, target, nums, dp); // Option to not take the current length

//     int take = 0;
//     if (target >= index + 1) { // Only take if we have enough length
//         take = nums[index] + solve(index, target - (index + 1), nums, dp); // Option to take the current length
//     }

//     // Store the maximum profit in the DP table
//     return dp[index][target] = max(take, not_take);
// }

// // Main function to initialize DP and start the recursive solving
// int cutRod(vector<int> &price, int n) {
//     vector<vector<int>> dp(n, vector<int>(n + 1, -1)); // DP table
//     return solve(n - 1, n, price, dp); // Start the recursive solving from the last index
// }

// int main() {
//     // Example Input: 2 test cases
//     int n1 = 5;
//     vector<int> price1 = {2, 5, 7, 8, 10};

//     int maxProfit1 = cutRod(price1, n1);
//     cout << "Maximum profit for the first rod: " << maxProfit1 << endl;

//     int n2 = 8;
//     vector<int> price2 = {3, 5, 8, 9, 10, 17, 17, 20};

//     int maxProfit2 = cutRod(price2, n2);
//     cout << "Maximum profit for the second rod: " << maxProfit2 << endl;

//     return 0; // Return 0 to indicate successful program execution
// }

#include <bits/stdc++.h>
using namespace std;

// Function to solve the rod cutting problem using bottom-up DP
int cutRod(vector<int> &price, int n)
{
    // Create a DP table
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));

    // Initialize the first row: when we only have the first piece
    for (int i = 0; i <= n; i++)
    {
        dp[0][i] = i * price[0]; // Maximum profit when cutting rod of length i with the first price
    }

    // Fill the DP table
    for (int i = 1; i < n; i++)
    { // Iterate over the pieces
        for (int target = 0; target <= n; target++)
        {                                     // Iterate over lengths of the rod
            int not_take = dp[i - 1][target]; // Not taking the current piece

            int take = 0;
            if (target >= (i + 1))
            {                                              // Check if we can take the current piece
                take = price[i] + dp[i][target - (i + 1)]; // Taking the current piece
            }

            // Store the maximum profit in the DP table
            dp[i][target] = max(take, not_take);
        }
    }

    return dp[n - 1][n]; // Return the maximum profit
}

int main()
{
    // Example Input: 2 test cases
    int n1 = 5;                            // Length of the first rod
    vector<int> price1 = {2, 5, 7, 8, 10}; // Prices for lengths 1 to 5

    int maxProfit1 = cutRod(price1, n1); // Calculate max profit for the first rod
    cout << "Maximum profit for the first rod: " << maxProfit1 << endl;

    int n2 = 8;                                        // Length of the second rod
    vector<int> price2 = {3, 5, 8, 9, 10, 17, 17, 20}; // Prices for lengths 1 to 8

    int maxProfit2 = cutRod(price2, n2); // Calculate max profit for the second rod
    cout << "Maximum profit for the second rod: " << maxProfit2 << endl;

    return 0; // Return 0 to indicate successful program execution
}
