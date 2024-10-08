// // Top - Down

// #include <bits/stdc++.h>
// using namespace std;

// vector<int> F;

// int Fib(int n)
// {
//     if (n == 0 || n == 1)
//     {
//         return n;
//     }

//     if (F[n] != -1)
//     {
//         return F[n];
//     }

//     F[n] = Fib(n - 1) + Fib(n - 2);
//     return F[n];
// }

// int main()
// {
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;

//     F.resize(n + 1, -1);
//     F[0] = 0;
//     F[1] = 1;

//     cout << "Fibonacci of " << n << " is: " << Fib(n) << endl;

//     return 0;
// }

// Bottom - Up

// #include <iostream>
// #include <vector>

// using namespace std;

// int Fib(int n)
// {
//     if (n == 0)
//     {
//         return 0;
//     }
//     if (n == 1)
//     {
//         return 1;
//     }

//     vector<int> F(n + 1);
//     F[0] = 0;
//     F[1] = 1;

//     for (int i = 2; i <= n; i++)
//     {
//         F[i] = F[i - 1] + F[i - 2];
//     }

//     return F[n];
// }

// int main()
// {
//     int n;
//     cout << "Enter a number: ";
//     cin >> n;

//     cout << "Fibonacci of " << n << " is: " << Fib(n) << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int Fib(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    int prev2 = 0;
    int prev1 = 1;

    int curr;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return curr;
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Fibonacci of " << n << " is: " << Fib(n) << endl;

    return 0;
}
