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

Node *head = NULL; // initially node is empty

void insertHead(int value)
{
    Node *newNode = new Node(value, NULL);

    if (head == NULL)
    {
        head = newNode;
        return;
    }
    newNode->next = head;
    head = newNode;
}

void insertTail(int value)
{
    if (head == NULL)
    {
        insertHead(value);
        return;
    }

    Node *newNode = new Node(value, NULL);
    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = newNode;
}

void insertAtKth(int value, int k)
{
    if (head == NULL || k <= 1)
    {
        insertHead(value);
        return;
    }

    Node *newNode = new Node(value, NULL);

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
    newNode->next = temp->next;
    temp->next = newNode;
}

void deleteHead()
{
    if (head == NULL || head->next == NULL)
    {
        head = NULL;
        return;
    }
    Node *temp = head;
    head = head->next;
    free(temp);
}

void deleteTail()
{
    if (head == NULL || head->next == NULL)
    {
        head = NULL;
        return;
    }

    Node *temp = head;
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

void deleteKth(int k)
{
    if (head->next == NULL || k <= 1)
    {
        deleteHead();
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
    Node *deleteItem = temp->next;
    temp->next = deleteItem->next;
    delete deleteItem;
}

void printLL()
{
    if (head == NULL)
    {
        cout << "Empty Linked list";
        return;
    }

    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int main()
{
    insertHead(5);
    insertHead(15);
    insertHead(3);

    insertTail(11);
    insertTail(17);

    insertAtKth(345, -2);
    insertAtKth(101, 2);
    insertAtKth(181, 10);

    // deleteHead();
    // deleteHead();
    // deleteHead();
    // deleteHead();
    // deleteHead();
    // deleteTail();
    deleteKth(1);

    printLL();
    return 0;
}