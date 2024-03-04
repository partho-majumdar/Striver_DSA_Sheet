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

Node *arr2LL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

void printValue(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *insertInTail(Node *head, int value)
{
    if (head == NULL)
    {
        return new Node(value);
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(value);
    temp->next = newNode;
    return head;
}

int main()
{
    vector<int> arr = {8, 2, 7, 4, 3};
    Node *head = arr2LL(arr);
    printValue(head);
    cout << endl;
    Node *ans = insertInTail(head, 100);
    printValue(ans);
    return 0;
}