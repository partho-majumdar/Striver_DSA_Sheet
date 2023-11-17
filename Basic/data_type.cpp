#include <bits/stdc++.h>
using namespace std;

int main()
{
    int x = 1;
    float y = 11.11;
    double a = 12321;
    long l = 2345677;
    long long ll = 98765623;
    string s = "Hey striver";
    char ch = 'P';

    string str1, str2;
    cout << "Enter anything: ";
    cin >> str1;
    cout << str1;

    fflush(stdin); // clear input buffer

    cout << endl << "Enter name: ";
    getline(cin, str2);
    cout << str2;
    return 0;
}