#include <bits/stdc++.h>
using namespace std;

int main()
{
    int num;
    cout << "Enter any number: ";
    cin >> num;
    int count = 0;

    while (num != 0)
    {
        cout << "Number " << num << endl;
        int last_digit = num % 10;
        count++;
        cout << "Last digit " << last_digit << endl;
        num /= 10;
    }

    cout << "Total number: " << count;
    return 0;
}