#include <bits/stdc++.h>
using namespace std;

void find_next_greater(int arr[], int n)
{

    int nge[n];
    stack<int> st;

    for (int i = ((2 * n) - 1); i >= 0; i--)
    {
        while (!st.empty() && st.top() <= arr[i % n])
        {
            st.pop();
        }
        if (i < n)
        {
            if (!st.empty())
            {
                nge[i] = st.top();
            }
            else
            {
                nge[i] = -1;
            }
        }
        st.push(arr[i % n]);
    }

    for (int i = 0; i < n; i++)
    {
        cout << nge[i] << " ";
    }
}

int main()
{
    int arr[] = {4, 12, 5, 3, 1, 2, 5, 3, 1, 2, 4, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    find_next_greater(arr, n);
    return 0;
}