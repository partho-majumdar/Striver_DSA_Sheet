// #include <bits/stdc++.h>
// using namespace std;

// int minSwapsToBalance(string s)
// {
//     int open = 0, close = 0, imbalance = 0, swaps = 0;

//     for (int i = 0; i < s.length(); i++)
//     {
//         if (s[i] == '[')
//         {
//             open++;
//             if (imbalance > 0)
//             {
//                 swaps += imbalance;
//                 imbalance--;
//             }
//         }
//         else
//         {
//             close++;
//             imbalance = close - open;
//         }
//     }

//     return swaps;
// }

// int main()
// {
//     string s;

//     cout << "Enter the bracket string: ";
//     cin >> s;

//     cout << "Minimum swaps required: " << minSwapsToBalance(s) << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int swapCount(string s)
{
    int ans = 0;

    int count = 0;

    int n = s.size();

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '[')
        {
            count++;
        }
        else
        {
            count--;
        }
        if (count < 0)
        {
            int j = i + 1;
            while (j < n)
            {
                if (s[j] == '[')
                {
                    break;
                }
                j++;
            }
            ans += j - i;

            count = 1;

            char ch = s[j];
            for (int k = j; k > i; k--)
            {
                s[k] = s[k - 1];
            }
            s[i] = ch;
        }
    }
    return ans;
}

int main()
{
    string s = "[]][][";
    cout << swapCount(s) << "\n";

    return 0;
}