#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    string name;
    int id;
    float w_hr;
    Employee *next;

public:
    Employee(string nam, int i_d, float hr)
    {
        name = nam;
        id = i_d;
        w_hr = hr;
        next = NULL;
    }

    void display()
    {
        cout << "Name: " << name << ", ID: " << id << ", Work Hour: " << w_hr << endl;
    }
};

class MinStack
{
private:
    Employee *head;

public:
    MinStack() : head(NULL) {}

    void push(Employee emp)
    {

        Employee *newNode = new Employee(emp);
        if (head == NULL)
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void pop()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return;
        }

        Employee *temp = head;
        head = head->next;
        delete temp;
    }

    Employee top()
    {
        if (head == NULL)
        {
            cout << "Stack empty";
            return Employee("", -1, -1);
        }
        cout << "Top employee-> ";
        head->display();
        return *head;
    }

    void displaySt()
    {
        Employee *temp = head;
        while (temp)
        {
            temp->display();
            temp = temp->next;
        }
    }

    Employee getMin()
    {
        if (head == NULL)
        {
            cout << "Stack is empty" << endl;
            return Employee("", -1, -1);
        }

        Employee *temp = head;
        Employee minEmp = *temp;

        while (temp)
        {
            if (temp->w_hr < minEmp.w_hr)
            {
                minEmp = *temp;
            }
            temp = temp->next;
        }

        cout << "Employee with minimum work-hour:";
        minEmp.display();
        return minEmp;
    }
};

int main()
{
    MinStack minStack;

    Employee e1("a", 14, 45);
    Employee e2("s", 23, 55);
    Employee e3("d", 33, 12);
    Employee e4("e", 13, 17);

    minStack.push(e1);
    minStack.push(e2);
    minStack.push(e3);
    minStack.push(e4);

    minStack.pop();

    minStack.top();
    minStack.displaySt();
    minStack.getMin();

    return 0;
}
