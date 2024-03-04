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

Node *deleteKthElement(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
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
    Node *front = temp->next;

    if (prev == NULL && front == NULL)
    {
        return NULL;
    }

    else if (prev == NULL)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        Node *prev = head;
        head = head->next;
        head->back = nullptr;
        prev->next = nullptr;
        delete prev;
        return head;
    }

    else if (front == NULL)
    {
        if (head == NULL || head->next == NULL)
        {
            return NULL;
        }

        Node *tail = head;
        while (tail->next != NULL)
        {
            tail = tail->next;
        }

        Node *prev = tail->back;
        tail->back = nullptr;
        prev->next = nullptr;
        delete tail;

        return head;
    }

    else
    {
        prev->next = front;
        front->back = prev;
        temp->next = NULL;
        temp->back = NULL;
        free(temp);
    }
    return head;
}

int main()
{
    int arr[] = {8, 1, 3, 9, 2, 7};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = arrToDLL(arr, n);
    printDLL(head);

    cout << endl;

    Node *ans = deleteKthElement(head, 7);
    printDLL(ans);

    return 0;
}