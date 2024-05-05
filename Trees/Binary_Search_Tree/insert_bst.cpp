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

Node *insertNode(Node *root, int val)
{
    if (root == NULL)
    {
        return new Node(val);
    }

    Node *curr = root;
    while (curr)
    {
        if (val >= curr->data)
        {
            if (curr->right != NULL)
            {
                curr = curr->right;
            }
            else
            {
                curr->right = new Node(val);
                break;
            }
        }
        else if (val < curr->data)
        {
            if (curr->left != NULL)
            {
                curr = curr->left;
            }
            else
            {
                curr->left = new Node(val);
                break;
            }
        }
    }
    return root;
}

void printInOrder(Node *root)
{
    if (root == NULL)
    {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
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

    root = insertNode(root, val);

    cout << "In-order traversal after insertion: ";
    printInOrder(root);
    cout << endl;

    return 0;
}
