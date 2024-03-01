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

Node *deleteTail(Node *head)
{
    Node *temp = head;
    if (temp == NULL || temp->next == NULL)
    {
        return NULL;
    }
    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = nullptr;

    return head;
}

int main()
{
    vector<int> arr = {9, 1, 2, 8, 5, 4};
    Node *head = arr2LL(arr);
    printValue(head);
    cout << endl;
    Node *ans = deleteTail(head);
    printValue(ans);
    return 0;
}
