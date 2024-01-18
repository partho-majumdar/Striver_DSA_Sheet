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

Node *insert_value_in_kth(Node *head, int val, int k)
{
    if (head == NULL)
    {
        if (k == 1)
        {
            Node *newNode = new Node(val);
        }
        else
        {
            return head;
        }
    }

    if (k == 1)
    {
        Node *newNode = new Node(val, head);
        return newNode;
    }

    int cnt = 0;
    Node *temp = head;

    while (temp)
    {
        cnt++;
        if (cnt == k - 1)
        {
            Node *newNode = new Node(val, temp->next);
            temp->next = newNode;
        }
        temp = temp->next;
    }
    return head;
};

int main()
{
    vector<int> arr = {9, 3, 1, 7, 8};
    Node *head = arr2LL(arr);
    printValue(head);
    cout << endl;
    Node *ans = insert_value_in_kth(head, 101, 6);
    printValue(ans);
    return 0;
}