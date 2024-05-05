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
        left = NULL;
        right = NULL;
    }
};

int max_height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    return (1 + max(max_height(root->left), max_height(root->right)));
}

int main()
{
    Node *root = new Node(9);
    root->left = new Node(8);
    root->right = new Node(7);
    root->left->left = new Node(5);
    root->left->left->right = new Node(6);

    int ans = max_height(root);
    cout << ans;
    return 0;
}