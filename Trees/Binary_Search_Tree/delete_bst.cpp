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

void delete_node(Node *root, int val)
{
    
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

    return 0;
}
