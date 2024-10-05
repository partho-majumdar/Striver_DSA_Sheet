#include <bits/stdc++.h>
using namespace std;

void sortArr(int startArr[], int endArr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (endArr[j] > endArr[j + 1])
            {
                swap(endArr[j], endArr[j + 1]);
                swap(startArr[j], startArr[j + 1]);
            }
        }
    }
}

void maxSubset(int startArr[], int endArr[], int n)
{
    sortArr(startArr, endArr, n);

    int previousEnd = endArr[0];
    cout << "Start " << startArr[0] << " End " << endArr[0] << endl;

    for (int i = 1; i < n; i++)
    {
        if (startArr[i] >= previousEnd)
        {
            cout << "Start " << startArr[i] << " End " << endArr[i] << endl;
            previousEnd = endArr[i];
        }
    }
}

int main()
{
    int startArr[] = {6, 5, 8, 1, 2, 4};
    int endArr[] = {8, 7, 9, 3, 5, 6};
    int n = sizeof(startArr) / sizeof(startArr[0]);
    maxSubset(startArr, endArr, n);
    return 0;
}
