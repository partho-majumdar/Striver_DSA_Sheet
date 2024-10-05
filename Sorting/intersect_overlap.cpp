#include <bits/stdc++.h>
using namespace std;

struct Interval
{
    int start;
    int end;
};

// Function to print the sorted array of intervals
void printSortedArray(Interval arr[], int n)
{
    cout << "Sorted Array of Intervals:" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << "[" << arr[i].start << ", " << arr[i].end << "]" << endl;
    }
}

bool isIntersect(Interval arr[], int n)
{
    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 2 - i; j++)
        {
            if ((arr[j].start != arr[j + 1].start) && (arr[j].start > arr[j + 1].start))
            {
                Interval temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
            else if ((arr[j].start == arr[j + 1].start) && (arr[j].end > arr[j + 1].end))
            {
                Interval temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    printSortedArray(arr, n);

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1].end > arr[i].start)
        {
            return true;
        }
    }

    return false;
}

int main()
{
    Interval arr1[] = {{1, 3}, {4, 9}, {4, 6}, {10, 13}};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);

    bool ans = isIntersect(arr1, n1);

    if (ans == 1)
    {
        cout << "Yes Overlap";
    }
    else
    {
        cout << "No overlap";
    }
    return 0;
}

/*

https://www.geeksforgeeks.org/check-if-any-two-intervals-overlap-among-a-given-set-of-intervals/

An interval is represented as a combination of start time and end time. Given a set of intervals, check if any two intervals intersect.

Examples:

Input:  arr[] = {{1, 3}, {5, 7}, {2, 4}, {6, 8}}
Output: true
The intervals {1, 3} and {2, 4} overlap


Input:  arr[] = {{1, 3}, {7, 9}, {4, 6}, {10, 13}}
Output: false
No pair of intervals overlap.

*/