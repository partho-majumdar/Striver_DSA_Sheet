#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int minSwaps(string s)
    {
        int size = 0; // Keeps track of unbalanced '[' characters
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            char ch = s[i];

            if (ch == '[')
            {
                size++; // If it's an opening bracket, increment size
            }
            else if (size > 0)
            {
                size--; // If it's a closing bracket and size > 0, decrement size (i.e., a matching opening bracket exists)
            }
        }

        // The number of swaps is (size + 1) / 2, which is the number of unbalanced pairs
        return (size + 1) / 2;
    }
};

int main()
{
    Solution solution;
    string s;

    // Input prompt
    cout << "Enter the bracket sequence: ";
    cin >> s;

    // Get the minimum number of swaps
    int result = solution.minSwaps(s);

    // Output the result
    cout << "Minimum number of swaps to balance: " << result << endl;

    return 0;
}
