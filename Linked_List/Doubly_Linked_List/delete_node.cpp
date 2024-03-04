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
        next = nullptr;
        back = nullptr;
    }
};

Node *arrToDLL(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *prev = head;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i], nullptr, prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void printDLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

void deleteNode(Node *head)
{
    Node *temp = head;
    Node *front = temp->next;
    Node *prev = temp->back;

    if (front == NULL)
    {
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back = prev;

    temp->next = temp->back = nullptr;
    free(temp);
}

int main()
{
    int arr[] = {8, 1, 3, 9, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = arrToDLL(arr, n);
    printDLL(head);

    cout << endl;

    deleteNode(head->next->next);
    printDLL(head);

    return 0;
}