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
        left = right = nullptr;
    }
};

vector<int> preOrder(Node *root, vector<int> &arr)
{
    if (root == nullptr)
    {
        return arr;
    }

    arr.push_back(root->data);
    preOrder(root->left, arr);
    preOrder(root->right, arr);

    return arr;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> arr;
    vector<int> ans = preOrder(root, arr);

    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}