#include <bits/stdc++.h>
using namespace std;

int question1(int start, int n)
{
    if (start > n)
    {
        return 0;
    }

    return start + question1(start + 1, n);
}

int question2(int start, int n)
{
    if (start > n)
    {
        return 0;
    }

    return pow(start, 2) + question2(start + 1, n);
}

int question3(int start, int n)
{
    if (start > n)
    {
        return 0;
    }

    int oddNum = (2 * start) + 1;
    return (start * oddNum) + question3(start + 1, n);
}

int question4(int start, int factor, int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int term = start * factor;
    return term + question4(start * 2, factor + 2, n - 1);
}

int question5(int start, int factor1, int n)
{
    if (n <= 0)
    {
        return 0;
    }

    int term1 = start * factor1 * n;
    return term1 + question5(start * 2, factor1 + 2, n - 1);
}

int main()
{
    int n1 = 3;
    int ans1 = question1(1, n1);
    cout << ans1 << endl;

    int n2 = 3;
    int ans2 = question2(1, n2);
    cout << ans2 << endl;

    int n3 = 4;
    int ans3 = question3(1, n3);
    cout << ans3 << endl;

    int n4 = 4;
    int ans4 = question4(2, 3, n4);
    cout << ans4 << endl;

    int n5 = 4;
    int ans5 = question5(2, 3, n5);
    cout << ans5 << endl;

    return 0;
}