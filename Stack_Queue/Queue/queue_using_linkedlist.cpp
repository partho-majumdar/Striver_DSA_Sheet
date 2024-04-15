#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int d1, Node *n1)
    {
        data = d1;
        next = n1;
    }

public:
    Node(int d1)
    {
        data = d1;
        next = nullptr;
    }
};

Node *head = nullptr;

void EnQueue_push(int val)
{
    if (head == nullptr)
    {
        head = new Node(val);
        return;
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(val);
    temp->next = newNode;
}

void DeQueue_pop()
{
    Node *temp = head;
    head = head->next;
    free(temp);
}

void printQueue()
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

int main()
{
    EnQueue_push(12);
    EnQueue_push(18);
    EnQueue_push(14);

    DeQueue_pop();

    EnQueue_push(21);

    DeQueue_pop();

    printQueue();
    return 0;
}