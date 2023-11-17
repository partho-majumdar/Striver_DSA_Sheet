#include <bits/stdc++.h>
using namespace std;

int main()
{
    int age;
    cout << "Enter your age: ";
    cin >> age;

    if (age >= 18 && age <= 30)
    {
        cout << "University student";
    }
    else if (age < 18)
    {
        cout << "High school student";
    }
    else
    {
        cout << "Job holder";
    }
    return 0;
}