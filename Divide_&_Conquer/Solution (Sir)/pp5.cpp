// #include <bits/stdc++.h>
// using namespace std;

// string commonPrefixUtil(string str1, string str2)
// {
//     string result;
//     int n1 = str1.length(), n2 = str2.length();

//     for (int i = 0, j = 0; i <= n1 - 1 && j <= n2 - 1; i++, j++)
//     {
//         if (str1[i] != str2[j])
//             break;
//         result.push_back(str1[i]);
//     }
//     return result;
// }

// string commonPrefix(string arr[], int low, int high)
// {
//     if (low == high)
//         return (arr[low]);

//     if (high > low)
//     {
//         int mid = low + (high - low) / 2;

//         string str1 = commonPrefix(arr, low, mid);
//         string str2 = commonPrefix(arr, mid + 1, high);

//         return (commonPrefixUtil(str1, str2));
//     }
//     return "";
// }

// int main()
// {
//     string arr[] = {"Algolab", "Algorithms",
//                     "Algeria"};
//     int n = sizeof(arr) / sizeof(arr[0]);

//     string ans = commonPrefix(arr, 0, n - 1);

//     if (ans.length())
//         cout << "The longest common prefix is "
//              << ans;
//     else
//         cout << "There is no common prefix";
//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int min(int a, int b)
{
    return (a < b) ? a : b;
}

int min(int a, int b, int c)
{
    return min(min(a, b), c);
}

int minCrossingSum(vector<int> &arr, int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MAX;
    for (int i = m; i >= l; i--)
    {
        sum += arr[i];
        left_sum = min(left_sum, sum);
    }

    sum = 0;
    int right_sum = INT_MAX;
    for (int i = m + 1; i <= h; i++)
    {
        sum += arr[i];
        right_sum = min(right_sum, sum);
    }

    return left_sum + right_sum;
}

int minSubArraySum(vector<int> &arr, int l, int h)
{
    if (l == h)
        return arr[l];

    int m = (l + h) / 2;
    return min(minSubArraySum(arr, l, m),
               minSubArraySum(arr, m + 1, h),
               minCrossingSum(arr, l, m, h));
}

int main()
{
    vector<int> arr = {2, 3, 4, -5, 7};
    int n = arr.size();
    int min_sum = minSubArraySum(arr, 0, n - 1);
    cout << "Minimum contiguous sum is " << min_sum << endl;
    return 0;
}
