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

Node *remove_kth(Node *head, int k)
{
    if (head == NULL)
    {
        return NULL;
    }

    if (k == 1)
    {
        Node *temp = head;
        head = temp->next;
        free(temp);
        return head;
    }

    Node *temp = head;
    Node *previous = NULL;
    int count = 0;

    while (temp != NULL)
    {
        count++;
        if (count == k)
        {
            previous->next = previous->next->next;
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
    vector<int> arr = {7, 1, 9, 3, 2};
    Node *head = arr2LL(arr);
    printValue(head);
    cout << endl;

    head = remove_kth(head, 3);
    printValue(head);

    return 0;
}