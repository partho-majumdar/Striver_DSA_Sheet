#include <iostream>
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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if (rh == -1 || rh == -1)
    {
        return -1;
    }

    if (abs(lh - rh) > 1)
    {
        return -1;
    }

    return 1 + max(lh, rh);
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    // root->left->left = new Node(4);
    // root->left->left->left = new Node(6);
    // root->left->left->right = new Node(7);
    // root->right->left = new Node(5);

    int ans = height(root);

    if (ans == -1)
    {
        cout << "Not balanced";
    }
    else
    {
        cout << "Balanced";
    }
    return 0;
}
