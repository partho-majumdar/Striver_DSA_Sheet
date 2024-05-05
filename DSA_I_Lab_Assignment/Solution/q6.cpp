#include <bits/stdc++.h>
using namespace std;

class Employee
{
public:
    string name;
    int id;
    string position;
};

class Node
{
public:
    Employee emp;
    Node *next;

public:
    Node(Employee e)
    {
        emp = e;
        next = NULL;
    }
};

Node *head = NULL;

void insertNode(Employee e)
{
    Node *newNode = new Node(e);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void display()
{
    if (head == NULL)
    {
        cout << "There are no employees" << endl;
        return;
    }
    Node *temp = head;
    while (temp)
    {
        cout << "Name: " << temp->emp.name << ", ID: " << temp->emp.id << ", Position: " << temp->emp.position << endl;
        temp = temp->next;
    }
}

void consecutive_count()
{
    Node *temp = head;
    int cnt = 0;

    while (temp != NULL && temp->next != NULL)
    {
        if (temp->emp.name != "" && temp->next->emp.name != "")
        {
            cnt++;
        }
        temp = temp->next;
    }
    cout << "Number of connected employees: " << cnt << endl;
}

int main()
{
    insertNode({"Rana", 11023, "Software-Tester"});
    insertNode({"Salman", 12045, "Designer"});
    insertNode({"Jacob", 21055, "FrontEnd-Developer"});
    insertNode({"Rasel", 22134, "BackEnd-Developer"});
    insertNode({"Patrick", 31022, "Administrator"});

    display();

    consecutive_count();

    return 0;
}
