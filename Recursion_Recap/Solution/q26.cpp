#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int d1)
    {
        data = d1;
        left = right = NULL;
    }
};

void pre_Order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " -> ";
    pre_Order(root->left);
    pre_Order(root->right);
}

void in_Order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    in_Order(root->left);
    cout << root->data << " -> ";
    in_Order(root->right);
}

void post_Order(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    post_Order(root->left);
    post_Order(root->right);
    cout << root->data << " -> ";
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

    cout << "Preorder: ";
    pre_Order(root);
    cout << "NULL" << endl;

    cout << "Inorder: ";
    in_Order(root);
    cout << "NULL" << endl;

    cout << "Postorder: ";
    post_Order(root);
    cout << "NULL" << endl;

    return 0;
}
