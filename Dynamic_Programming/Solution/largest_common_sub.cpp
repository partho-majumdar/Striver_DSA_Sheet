#include <bits/stdc++.h>
using namespace std;

string lcs(string x, string y)
{
    int m = x.length();
    int n = y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (x[i - 1] == y[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // Reconstruct the LCS (optional)
    string lcs_str = "";
    int i = m, j = n;
    while (i > 0 && j > 0)
    {
        if (x[i - 1] == y[j - 1])
        {
            lcs_str = x[i - 1] + lcs_str;
            i--;
            j--;
        }
        else if (dp[i][j] == dp[i - 1][j])
        {
            i--;
        }
        else
        {
            j--;
        }
    }

    return lcs_str;
}

int main()
{
    string x = "ABBACQ";
    string y = "XAYZMBNNALQCTRQ";
    string lcs_str = lcs(x, y);
    cout << "Longest Common Subsequence: " << lcs_str << endl;
    cout << "Length: " << lcs_str.length() << endl;
    return 0;
}

// #include <bits/stdc++.h>
// using namespace std;

// // Function to find the length of the Longest Common Subsequence (LCS)
// int lcsUtil(string &s1, string &s2, int ind1, int ind2, vector<vector<int>> &dp)
// {
//     // Base case: If either string reaches the end, return 0
//     if (ind1 < 0 || ind2 < 0)
//         return 0;

//     // If the result for this pair of indices is already calculated, return it
//     if (dp[ind1][ind2] != -1)
//         return dp[ind1][ind2];

//     // If the characters at the current indices match, increment the LCS length
//     if (s1[ind1] == s2[ind2])
//         return dp[ind1][ind2] = 1 + lcsUtil(s1, s2, ind1 - 1, ind2 - 1, dp);
//     else
//         // If the characters don't match, consider two options: moving either left or up in the strings
//         return dp[ind1][ind2] = max(lcsUtil(s1, s2, ind1, ind2 - 1, dp), lcsUtil(s1, s2, ind1 - 1, ind2, dp));
// }

// // Function to calculate the length of the Longest Common Subsequence
// int lcs(string s1, string s2)
// {
//     int n = s1.size();
//     int m = s2.size();

//     vector<vector<int>> dp(n, vector<int>(m, -1)); // Create a DP table
//     return lcsUtil(s1, s2, n - 1, m - 1, dp);
// }

// int main()
// {
//     string s1 = "ABBACQ";
//     string s2 = "XAYZMBNNALQCTRQ";

//     // Call the function to find and output the length of the Longest Common Subsequence
//     cout << "The Length of Longest Common Subsequence is " << lcs(s1, s2) << endl;

//     return 0; // Return 0 to indicate successful program execution
// }

// #include <bits/stdc++.h>
// using namespace std;

// // Function to find the length of the Longest Common Subsequence (LCS)
// int lcs(string s1, string s2)
// {
//     int n = s1.size();
//     int m = s2.size();

//     vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1)); // Create a DP table

//     // Initialize the base cases
//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = 0;
//     }
//     for (int i = 0; i <= m; i++)
//     {
//         dp[0][i] = 0;
//     }

//     // Fill in the DP table to calculate the length of LCS
//     for (int ind1 = 1; ind1 <= n; ind1++)
//     {
//         for (int ind2 = 1; ind2 <= m; ind2++)
//         {
//             if (s1[ind1 - 1] == s2[ind2 - 1])
//                 dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1]; // Characters match, increment LCS length
//             else
//                 dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]); // Characters don't match, consider the maximum from left or above
//         }
//     }

//     return dp[n][m]; // Return the length of the Longest Common Subsequence
// }

// int main()
// {
//     string s1 = "ABBACQ";
//     string s2 = "XAYZMBNNALQCTRQ";

//     // Call the function to find and output the length of the Longest Common Subsequence
//     cout << "The Length of Longest Common Subsequence is " << lcs(s1, s2) << endl;

//     return 0; // Return 0 to indicate successful program execution
// }
