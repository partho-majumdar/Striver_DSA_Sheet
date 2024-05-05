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

vector<int> bfs_levelOrder(Node *root)
{
    vector<int> ans;
    queue<Node *> q;
    q.push(root);
    Node *temp;

    while (!q.empty())
    {
        temp = q.front();
        q.pop();
        ans.push_back(temp->data);
        if (temp->left)
        {
            q.push(temp->left);
        }
        if (temp->right)
        {
            q.push(temp->right);
        }
    }
    return ans;
}

int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    vector<int> result = bfs_levelOrder(root);

    for (auto i : result)
    {
        cout << i << " ";
    }
    return 0;
}