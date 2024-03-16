#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *back;

public:
    Node(int d1, Node *n1, Node *b1)
    {
        data = d1;
        next = n1;
        back = b1;
    }

public:
    Node(int d1)
    {
        data = d1;
        next = NULL;
        back = NULL;
    }
};

Node *head = NULL;

void insertHead(int value)
{
    Node *newNode = new Node(value, NULL, NULL);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    head->back = newNode;
    newNode->next = head;
    head = newNode;
}

void insertTail(int value)
{
    if (head == NULL)
    {
        insertHead(value);
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    Node *newNode = new Node(value, NULL, NULL);
    temp->next = newNode;
    newNode->back = temp;
}

void insertKth(int x, int k)
{
    if (head == NULL || k <= 1)
    {
        insertHead(x);
        return;
    }
    Node *temp = head;
    int cnt = 0;

    while (temp->next != NULL)
    {
        cnt++;
        if (cnt + 1 == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp;
    Node *n1 = new Node(x, NULL, NULL);
    n1->next = prev->next;
    n1->back = prev;
    prev->next = n1;
    prev->next->back = n1;
}

void deleteHead()
{
    if (head->next == NULL)
    {
        head = NULL;
        return;
    }
    Node *temp = head;
    head = head->next;
    head->back = NULL;
    temp->next = NULL;
    delete temp;
}

void deleteTail()
{
    if (head->next == NULL)
    {
        deleteHead();
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    Node *deleteNode = temp->next;
    temp->next = NULL;
    deleteNode->back = NULL;
    deleteNode->next = NULL;

    delete (deleteNode);
}

void deleteKth(int k)
{
    if (head->next == NULL || k == 1)
    {
        deleteHead();
        return;
    }

    Node *temp = head;
    int cnt = 0;
    while (temp->next != NULL)
    {
        cnt++;
        if (cnt == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *deleteNode = temp;
    temp = temp->back;
    temp->next = deleteNode->next;
    deleteNode->next->back = temp;
    delete deleteNode;
}

void printLL()
{
    if (head == NULL)
    {
        cout << "Empty Linked list";
    }

    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int main()
{
    insertHead(4);
    insertHead(9);
    insertHead(1);

    insertTail(13);
    insertTail(18);

    insertKth(101, 8);

    // deleteHead();
    // deleteTail();
    deleteKth(1);

    printLL();
    return 0;
}
