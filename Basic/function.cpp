#include <bits/stdc++.h>
using namespace std;

void printName(string nam)
{
    cout << "Hi I am " << nam << endl;
}

int sum(int a, int b)
{
    return a + b;
}

// pass by value
void doSomething(int num)
{
    cout << num << endl;
    num += 5;
    cout << num << endl;
    num += 5;
    cout << num << endl;
}

// pass by reference
void strPrint(string &s)
{
    cout << s << endl;
    s[0] = 't';
    cout << s << endl;
}

// array always pass by reference
void forArray(int arr[], int n)
{
    arr[0] += 101;
    cout << "Outside main: " << arr[0] << endl;
}

int main()
{
    string nam;
    cout << "Enter name: ";
    cin >> nam;
    printName(nam);

    int x = sum(4, 5);
    cout << x << endl
         << endl;

    int num = 10;
    doSomething(num);
    cout << "In main: " << num << endl
         << endl; // it should print 25 but it print 10 cause here in doSomething() function as a parameter i pass the value(copy of that number not original one) not pass the reference

    string str = "raj";
    strPrint(str);
    cout << "In main: " << str << endl
         << endl;

    int n = 4;
    int arr[4];

    for (int i = 0; i <= n - 1; i++)
    {
        cin >> arr[i];
    }

    forArray(arr, n);
    cout << "Inside main: " << arr[0] << endl;

    return 0;
}
