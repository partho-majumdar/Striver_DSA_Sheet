#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

public:
    Node(int d)
    {
        data = d;
        left = right = NULL;
    }
};

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->right = new Node(4);

    cout << root->left->data << endl;
    cout << root->right->data << endl;
    cout << root->left->right->data << endl;
    return 0;
}