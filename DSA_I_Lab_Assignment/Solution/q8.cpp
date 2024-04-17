#include <iostream>
#include <stack>
#include <string>

using namespace std;

class Emp
{
public:
    string name;
    int id;
    float work_hour;

public:
    Emp(string nam, int i_d, float w_hr)
    {
        name = nam;
        id = i_d;
        work_hour = w_hr;
    }

    void display()
    {
        cout << "Name: " << name << ", ID: " << id << ", Work Hour: " << work_hour << endl;
    }
};

stack<Emp> empStack;

void push(Emp employee)
{
    empStack.push(employee);
}

void pop()
{
    if (!empStack.empty())
    {
        empStack.pop();
    }
    else
    {
        cout << "Stack is empty" << endl;
    }
}

Emp my_top()
{
    if (empStack.empty())
    {
        cout << "Stack empty";
    }

    return empStack.top();
}

void getMin()
{
    int min = INT_MAX;

    while (!empStack.empty())
    {
        if (empStack.top().work_hour < min)
        {
            min = empStack.top().work_hour;
        }
        empStack.pop();
    }

    cout << "Minimum work hour: " << min << endl;
}

void display()
{
    while (!empStack.empty())
    {
        empStack.top().display();
        empStack.pop();
    }
}

int main()
{
    Emp e1("Rasel", 14, 45);
    Emp e2("Yaseer", 23, 55);
    Emp e3("Naheed", 33, 12);
    Emp e4("Joy", 13, 17);

    empStack.push(e1);
    empStack.push(e2);
    empStack.push(e3);
    empStack.push(e4);

    pop();

    Emp topEmployee = my_top();

    if (!topEmployee.name.empty())
    {
        cout << "Top -> ";
        topEmployee.display();
    }

    display();
    getMin();

    return 0;
}
