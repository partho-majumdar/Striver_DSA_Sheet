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

vector<int> iterative_postorder_usingStack(Node *root)
{
    
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(3);
    root->left->right = new Node(4);
    root->left->right->left = new Node(5);
    root->left->right->right = new Node(6);

    vector<int> result = iterative_postorder_usingStack(root);

    for (auto i : result)
    {
        cout << i << " ";
    }

    return 0;
}
