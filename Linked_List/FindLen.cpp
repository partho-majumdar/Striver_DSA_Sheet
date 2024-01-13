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

Node *arrayToLL(vector<int> &arr)
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

int length_of_ll(Node *head)
{
    Node *temp = head;
    int count = 0;

    while (temp)
    {
        temp = temp->next;
        count++;
    }

    return count;
}

int main()
{
    vector<int> arr = {8, 3, 7, 1, 6};
    Node *head = arrayToLL(arr);

    int len = length_of_ll(head);
    cout << len;
    return 0;
}

// Given a Linked list means --> given the head of the linked list