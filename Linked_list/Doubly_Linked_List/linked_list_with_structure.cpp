#include <bits/stdc++.h>
using namespace std;

class Student
{
public:
    string name;
    float cgpa;

    Student(string s1, float cg)
    {
        name = s1;
        cgpa = cg;
    }

    Student() {}
};

class Node
{
public:
    Student s;
    Node *next;

    Node(Student s1, Node *n1)
    {
        s = s1;
        next = n1;
    }
};

Node *head = NULL;

void insertStudent(Student s1)
{
    Node *newNode = new Node(s1, NULL);

    if (head == NULL || s1.cgpa < head->s.cgpa)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL && temp->next->s.cgpa < s1.cgpa)
    {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

int main()
{
    insertStudent(Student("A", 3.5));
    insertStudent(Student("B", 3.2));
    insertStudent(Student("C", 3.3));
    insertStudent(Student("D", 2.8));
    insertStudent(Student("E", 3.8));

    Node *temp = head;
    while (temp != NULL)
    {
        cout << "Name: " << temp->s.name << ", CGPA: " << temp->s.cgpa << endl;
        temp = temp->next;
    }

    return 0;
}
