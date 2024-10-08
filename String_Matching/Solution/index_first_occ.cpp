#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int strStr(string m, string n)
    {
        // If the size of the n string is greater than the m string, return -1
        if (m.size() < n.size())
            return -1;

        // Traverse through the m string and check for the substring match
        for (int i = 0; i <= m.size() - n.size(); i++)
        {
            if (m.substr(i, n.size()) == n)
                return i; // Return the starting index of the match
        }
        return -1; // If no match found, return -1
    }
};

int main()
{
    string m, n;

    // Input for the strings
    cout << "Enter the larger string: ";
    getline(cin, m); // Input the larger string

    cout << "Enter the smaller string: ";
    getline(cin, n); // Input the smaller string to search for

    Solution solution;
    int result = solution.strStr(m, n);

    // Output the result
    if (result != -1)
        cout << "The smaller string is found at index: " << result << endl;
    else
        cout << "The smaller string is not found in the larger string." << endl;

    return 0;
}
