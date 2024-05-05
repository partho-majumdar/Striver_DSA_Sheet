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

int find_floor(Node *root, int key)
{
    int floor = -1;
    while (root)
    {
        if (root->data == key)
        {
            floor = root->data;
            return floor;
        }

        else if (key > root->data)
        {
            root = root->right;
            floor = root->data;
        }

        else if (key < root->data)
        {
            root = root->left;
        }
    }
    return floor;
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

    int ans = find_floor(root, 15);
    cout << ans;

    return 0;
}
