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
        next = NULL;
    }
};

// conver array to linked list
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

// insert at head
Node *insertHead(Node *head, int val)
{
    Node *temp = new Node(val, head);
    return temp;
}

// insert at last
Node *insertTail(Node *head, int val)
{
    if (head == NULL)
    {
        return new Node(val);
    }

    Node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    Node *newNode = new Node(val);
    temp->next = newNode;
    return head;
}

// insert kth element
Node *insertKthElement(Node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            Node *newNode = new Node(val, head);
            return newNode;
        }

        else
        {
            return NULL;
        }
    }

    if (k == 1)
    {
        Node *newNode1 = new Node(val, head);
        return newNode1;
    }

    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        if (count == k - 1)
        {
            Node *newNode2 = new Node(val);
            newNode2->next = temp->next;
            temp->next = newNode2;
            break;
        }
        temp = temp->next;
    }
    return head;
}

// insert a value(val) before a particlular value(x)
Node *insertBeforeValue(Node *head, int val, int x)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (head->data == x)
    {
        Node *newNode = new Node(val, head);
        return newNode;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->next->data == x)
        {
            Node *newNode1 = new Node(val, temp->next);
            temp->next = newNode1;
            break;
        }
        temp = temp->next;
    }
    return head;
}

int main()
{
    int arr[] = {5, 1, 8, 2, 4};
    int n = sizeof(arr) / sizeof(arr[0]);

    Node *head = arrToLL(arr, n);
    printLL(head);

    cout << endl;

    // head = insertHead(head, 101);
    // printLL(head);

    // Node *ans = insertTail(head, 101);
    // printLL(ans);

    // Node *ans1 = insertKthElement(head, 101, 7);
    // printLL(ans1);

    Node *ans2 = insertBeforeValue(head, 202, 2);
    printLL(ans2);

    return 0;
}
