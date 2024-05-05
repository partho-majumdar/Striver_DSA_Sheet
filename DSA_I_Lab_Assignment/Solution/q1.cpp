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

Node *head = NULL;

void insertAtMid(int value)
{
    Node *newNode = new Node(value);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    int count = 0;
    Node *current = head;
    while (current)
    {
        count++;
        current = current->next;
    }

    int mid = (count + 1) / 2;

    Node *temp = head;
    int cnt = 0;

    while (temp->next != NULL)
    {
        cnt++;
        if (cnt == mid)
        {
            break;
        }
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

void arr_at_the_end(int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node *temp = head;
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode;
}

void delete_kth_element(int k)
{

    if (head->next == NULL || k <= 1)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }

    Node *temp = head;
    int cnt = 0;
    while (temp)
    {
        cnt++;
        if (cnt + 1 == k)
        {
            break;
        }
        temp = temp->next;
    }
    Node *deleteItem = temp->next;
    temp->next = deleteItem->next;
    delete deleteItem;
}

void replace_last_by_sum()
{
    Node *temp = head;
    int sum = 0;

    Node *prev = NULL;

    while (temp)
    {
        sum += temp->data;
        prev = temp;
        temp = temp->next;
    }

    if (prev != NULL)
    {
        prev->data = sum;
    }
}

vector<int> even_number()
{
    vector<int> arr;
    Node *temp = head;
    while (temp)
    {
        if (temp->data % 2 == 0)
        {
            arr.push_back(temp->data);
        }
        temp = temp->next;
    }
    return arr;
}

void printLL()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int main()
{
    insertAtMid(1);
    insertAtMid(2);
    insertAtMid(3);
    insertAtMid(4);
    insertAtMid(5);

    vector<int> arr = {9, 2, 5, 1, 7, 8, 6};

    for (int i = 0; i < arr.size(); i++)
    {
        arr_at_the_end(arr[i]);
    }

    delete_kth_element(6);

    printLL();
    cout << endl;
    replace_last_by_sum();
    printLL();

    cout << endl;
    cout << "Even number: ";

    vector<int> ans = even_number();
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << ", ";
    }
    return 0;
}
