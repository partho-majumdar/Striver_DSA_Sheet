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

Node *insertBeforeKthElement(Node *head, int val, int k)
{
    if (k == 1)
    {
        Node *newNode = new Node(val, head, nullptr);
        head->back = newNode;

        return newNode;
    }
    Node *temp = head;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *prev = temp->back;
    Node *newNode = new Node(val, temp, prev);
    prev->next = newNode;
    temp->back = newNode;

    return head;
}

int main()
{
    int arr[] = {8, 1, 3, 9, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = arrToDLL(arr, n);
    printDLL(head);

    cout << endl;

    Node *ans = insertBeforeKthElement(head, 202, 7);
    printDLL(ans);

    return 0;
}