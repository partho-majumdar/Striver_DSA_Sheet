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
        next = NULL;
    }
};

// convert array to linked list
Node *arrToLL(int arr[], int n)
{
    Node *head = new Node(arr[0]);
    Node *mover = head;

    for (int i = 1; i < n; i++)
    {
        Node *temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

// print linked list
void printLL(Node *head)
{
    Node *temp = head;

    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

// delete first element
Node *deleteHead(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *temp = head;
    head = head->next;
    free(temp);
    return head;
}

// delete last element
Node *deleteTail(Node *head)
{
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }

    Node *temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}

// delete kth element
Node *deleteKthElement(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (k == 1)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node *temp = head;
    int count = 0;
    Node *previous = NULL;

    while (temp->next != NULL)
    {
        count++;
        if (count == k)
        {
            previous->next = temp->next;
            free(temp);
            break;
        }
        previous = temp;
        temp = temp->next;
    }
    return head;
}

// delete a particular value
Node *deleteValue(Node *head, int val)
{
    if (head->next == NULL)
    {
        return NULL;
    }

    if (head->data == val)
    {
        Node *temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    Node *previous = NULL;
    Node *temp = head;

    while (temp->next != NULL)
    {
        if (temp->data == val)
        {
            previous->next = temp->next;
            free(temp);
            break;
        }
        previous = temp;
        temp = temp->next;
    }

    return head;
}

int main()
{
    int arr[] = {7, 1, 9, 3, 2, 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    Node *head = arrToLL(arr, n);
    printLL(head);

    cout << endl;

    // head = deleteHead(head);
    // printLL(head);

    // Node *ans1 = deleteTail(head);
    // printLL(ans1);

    // Node *ans2 = deleteKthElement(head, 1);
    // printLL(ans2);

    Node *ans3 = deleteValue(head, 9);
    printLL(ans3);
}
