
// #include <iostream>
// #include <vector>
// using namespace std;

// bool isSubsetSum(vector<int> &A, int N)
// {
//     int n = A.size();

//     vector<vector<bool>> dp(n + 1, vector<bool>(N + 1, false));

//     for (int i = 0; i <= n; i++)
//     {
//         dp[i][0] = true;
//     }

//     for (int i = 1; i <= n; i++)
//     {
//         for (int j = 1; j <= N; j++)
//         {
//             dp[i][j] = dp[i - 1][j];

//             if (j >= A[i - 1])
//             {
//                 dp[i][j] = dp[i][j] || dp[i - 1][j - A[i - 1]];
//             }
//         }
//     }

//     return dp[n][N];
// }

// int main()
// {
//     vector<int> A = {2, 4, 5, 6, 8};
//     int N = 15;

//     if (isSubsetSum(A, N))
//     {
//         cout << "True" << endl;
//     }
//     else
//     {
//         cout << "False" << endl;
//     }

//     return 0;
// }

#include <iostream>
#include <vector>
using namespace std;

bool isSubsetSum(vector<int> &A, int N)
{
    int n = A.size();

    vector<vector<bool>> dp(n + 1, vector<bool>(N + 1, false));

    for (int i = 0; i <= n; i++)
    {
        dp[i][0] = true;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            dp[i][j] = dp[i - 1][j];

            if (j >= A[i - 1])
            {
                dp[i][j] = dp[i][j] || dp[i - 1][j - A[i - 1]];
            }
        }
    }

    if (!dp[n][N])
    {
        return false;
    }

    vector<int> subset;

    int i = n, j = N;
    while (i > 0 && j > 0)
    {
        if (dp[i][j] && !dp[i - 1][j])
        {
            subset.push_back(A[i - 1]);
            j -= A[i - 1];
        }
        i--;
    }

    cout << "Subset that sums up to " << N << ": ";
    for (int num : subset)
    {
        cout << num << " ";
    }
    cout << endl;

    return true;
}

int main()
{
    vector<int> A = {2, 4, 5, 6, 8};
    int N = 15;

    if (isSubsetSum(A, N))
    {
        cout << "True" << endl;
    }
    else
    {
        cout << "False" << endl;
    }

    return 0;
}
