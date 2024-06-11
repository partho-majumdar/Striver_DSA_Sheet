#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int d1)
    {
        data = d1;
        left = right = NULL;
    }
};

bool find_path(Node *current, Node *target)
{
    if (current == NULL)
    {
        return false;
    }

    if (current->data == target->data)
    {
        cout << current->data << " ";
        return true;
    }

    if (find_path(current->left, target))
    {
        cout << current->data << " ";
        return true;
    }

    if (find_path(current->right, target))
    {
        cout << current->data << " ";
        return true;
    }

    return false;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Node *target = new Node(5);
    if (!find_path(root, target))
    {
        cout << "not found";
    }
}
