#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

public:
    Node(int d1)
    {
        data = d1;
        next = prev = NULL;
    }
};

Node *front = NULL;
Node *rear = NULL;

void push_front(int x)
{
    Node *newNode = new Node(x);

    if (front == NULL)
    {
        front = rear = newNode;
        return;
    }
    else
    {
        newNode->next = front;
        front->prev = newNode;
        front = newNode;
        return;
    }
}

void push_back(int x)
{
    Node *newNode = new Node(x);

    if (front == NULL)
    {
        front = rear = newNode;
        return;
    }
    else
    {
        rear->next = newNode;
        newNode->prev = rear;
        rear = newNode;
        return;
    }
}

void pop_front()
{
    if (front == NULL)
    {
        return;
    }
    else
    {
        Node *temp = front;
        front = front->next;
        delete temp;
        if (front)
        {
            front->prev = NULL;
        }
        else
        {
            rear = NULL;
        }
    }
}

void pop_back()
{
    if (front == NULL)
    {
        return;
    }
    else
    {
        Node *temp = rear;
        rear = rear->prev;
        delete temp;

        if (rear)
        {
            rear->next = NULL;
        }
        else
        {
            front = NULL;
        }
    }
}

void printQueue()
{
    Node *temp = front;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int main()
{
    push_front(1);
    push_front(2);
    push_front(3);

    push_back(4);

    pop_front();
    pop_back();

    printQueue();
    return 0;
}