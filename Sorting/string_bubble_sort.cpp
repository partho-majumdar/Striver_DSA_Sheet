#include <bits/stdc++.h>
using namespace std;
#define MAX 100

void sortStrings(char arr[][MAX], int n)
{
    char temp[MAX];

    for (int i = 0; i <= n - 1; i++)
    {
        for (int j = 0; j <= n - 2 - i; j++)
        {
            if (strcmp(arr[j], arr[j + 1]) > 0)
            {
                strcpy(temp, arr[j]);
                strcpy(arr[j], arr[j + 1]);
                strcpy(arr[j + 1], temp);
            }
        }
    }
}

int main()
{
    char arr[][MAX] = {"Geeks", "for", "Geeks", "Quiz", "Practice",
                       "Blogs", "Coding"};

    int n = sizeof(arr) / sizeof(arr[0]);

    sortStrings(arr, n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

/*

https://www.geeksforgeeks.org/sorting-strings-using-bubble-sort-2/

*/