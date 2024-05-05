#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int d1)
    {
        data = d1;
        left = NULL;
        right = NULL;
    }
};

Node *search_bst(Node *root, int val)
{
    if (root == NULL || root->data == val)
    {
        return root;
    }
    if (val < root->data)
    {
        return search_bst(root->left, val);
    }
    else
    {
        return search_bst(root->right, val);
    }
}

int main()
{
    Node *root = new Node(8);
    root->left = new Node(3);
    root->right = new Node(10);
    root->right->right = new Node(14);
    root->right->right->left = new Node(13);
    root->left->left = new Node(1);
    root->left->right = new Node(6);
    root->left->right->left = new Node(4);
    root->left->right->right = new Node(7);

    int val;
    cout << "Enter search value: ";
    cin >> val;

    Node *result = search_bst(root, val);
    if (result != NULL)
    {
        cout << "Found " << val << " in the BST." << endl;
    }
    else
    {
        cout << val << " not found in the BST." << endl;
    }

    return 0;
}
