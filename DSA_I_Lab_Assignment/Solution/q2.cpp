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
    }
};

Node *head = NULL;

void push(int val)
{
    Node *newNode = new Node(val);

    newNode->next = head;
    head = newNode;
}

int isEmpty()
{
    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        temp = temp->next;
    }

    if (cnt >= 1)
    {
        return 0;
    }
    return 1;
}

int pop()
{
    Node *temp = head;
    int value = temp->data;
    head = head->next;
    delete temp;
    return value;
}

int peak()
{
    return head->data;
}

void display()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

void sort()
{
    Node *sorted = NULL;
    while (head != NULL)
    {
        int val = pop();
        if (sorted == NULL || val > sorted->data)
        {
            Node *newNode = new Node(val);
            newNode->next = sorted;
            sorted = newNode;
        }
        else
        {
            Node *temp = sorted;
            while (temp->next != NULL && temp->next->data > val)
            {
                temp = temp->next;
            }
            Node *newNode = new Node(val);
            newNode->next = temp->next;
            temp->next = newNode;
        }
    }
    head = sorted;
}

int main()
{
    push(12);
    push(4);
    push(16);
    push(3);
    push(18);

    sort();
    // cout << "Delete item: " << pop() << endl;
    cout << "Peak item: " << peak() << endl;

    display();
    return 0;
}