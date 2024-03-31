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

void myPush(int val)
{
    Node *temp = new Node(val, head);
    head = temp;
}

void myPop()
{
    if (head == NULL)
    {
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}

void printLL()
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
    myPush(17);
    myPush(12);
    myPush(13);
    myPush(14);

    myPop();

    myPush(22);

    printLL();
    return 0;
}