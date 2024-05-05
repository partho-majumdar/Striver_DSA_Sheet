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

void push(int val)
{
    Node *newNode = new Node(val);

    if (head == NULL)
    {
        head = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

int isEmpty()
{
    if (head == NULL)
    {
        return 1;
    }
    return 0;
}

int pop()
{
    if (isEmpty())
    {
        cout << "Stack Underflow" << endl;
    }

    Node *temp = head;
    int value = temp->data;
    head = head->next;
    delete temp;
    return value;
}

int peek()
{
    if (isEmpty())
    {
        cout << "Stack is empty" << endl;
    }
    return head->data;
}

void display()
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}

void sort()
{
    stack<int> st;

    while (!isEmpty())
    {
        int val = pop();

        while (!st.empty() && st.top() < val)
        {
            push(st.top());
            st.pop();
        }
        st.push(val);
    }

    while (!st.empty())
    {
        push(st.top());
        st.pop();
    }
}

int main()
{
    push(4);
    push(121);
    push(12);
    push(16);
    push(3);
    push(18);

    sort();

    cout << "Delete item: " << pop() << endl;
    cout << "Peek item: " << peek() << endl;

    display();
    return 0;
}