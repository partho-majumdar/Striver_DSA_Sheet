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

Node *BinaryTree()
{
    int x;
    cin >> x;

    if (x == -1)
    {
        return NULL;
    }
    Node *temp = new Node(x);

    cout << "Enter left child value of " << x << ": ";
    temp->left = BinaryTree();

    cout << "Enter left child value of " << x << ": ";
    temp->right = BinaryTree();

    return temp;
}

int main()
{
    cout << "Enter root node: ";
    Node *root = BinaryTree();
    return 0;
}