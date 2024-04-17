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

void my_put(int val)
{
    Node *newNode = new Node(val);

    if (head == NULL || newNode->data > head->data)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    
    else
    {
        Node *current = head;
        while (current->next != NULL && current->next->data > val)
        {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

void print()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
}

int my_pop()
{
    Node *temp = head;
    int pop_value = temp->data;
    head = head->next;
    delete temp;

    return pop_value;
}

int main()
{
    my_put(5);
    my_put(55);
    my_put(65);
    my_put(1);
    my_put(10);
    my_put(45);
    my_put(2);

    cout << "Delete item: " << my_pop() << endl;
    cout << "Delete item: " << my_pop() << endl;
    cout << "Delete item: " << my_pop() << endl;

    my_put(12);
    my_put(8);

    print();
    return 0;
}
