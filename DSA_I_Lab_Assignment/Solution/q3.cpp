#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int d1)
    {
        data = d1;
        next = NULL;
    }
};

Node *head = NULL;

void put(int val)
{
    Node *newNode = new Node(val);

    if (head == NULL || newNode->data <= head->data)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    else
    {
        Node *cur = head;
        while (cur->next != NULL && cur->next->data < val)
        {
            cur = cur->next;
        }
        newNode->next = cur->next;
        cur->next = newNode;
    }
}

int pop()
{
    Node *temp = head;
    int pop_value = temp->data;
    head = head->next;
    delete temp;

    return pop_value;
}

void display()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    put(5);
    put(55);
    put(10);
    put(45);
    put(2);
    put(12);
    put(8);

    cout << "Delete item: " << pop() << endl;
    cout << "Delete item: " << pop() << endl;

    display();
    return 0;
}
