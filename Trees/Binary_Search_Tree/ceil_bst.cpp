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

int find_ceil(Node *root, int key)
{
    int ceil = -1;
    while (root)
    {
        if (root->data == key)
        {
            ceil = root->data;
            return ceil;
        }

        else if (key > root->data)
        {
            root = root->right;
        }

        else if (key < root->data)
        {
            ceil = root->data;
            root = root->left;
        }
    }
    return ceil;
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

    int ans = find_ceil(root, 15);
    cout << ans;

    return 0;
}
