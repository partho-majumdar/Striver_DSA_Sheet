#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution
{
public:
    string longestCommonPrefix(vector<string> &v)
    {
        string ans = "";

        // Sort the vector of strings
        sort(v.begin(), v.end());

        // Get the size of the vector
        int n = v.size();

        // Get the first and the last string after sorting
        string first = v[0], last = v[n - 1];

        // Compare the characters of the first and last strings
        for (int i = 0; i < min(first.size(), last.size()); i++)
        {
            if (first[i] != last[i])
            {
                return ans;
            }
            ans += first[i];
        }

        return ans;
    }
};

int main()
{
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;

    vector<string> words(n);
    cout << "Enter " << n << " strings:" << endl;
    cin.ignore(); // Clear the newline character left in the buffer

    for (int i = 0; i < n; i++)
    {
        getline(cin, words[i]); // Take input for each string
    }

    // Create an instance of the Solution class
    Solution solution;

    // Call the longestCommonPrefix function and print the result
    string result = solution.longestCommonPrefix(words);

    cout << "Longest common prefix: " << result << endl;

    return 0;
}
