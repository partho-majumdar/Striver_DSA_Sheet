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

vector<int> iterative_preorder_usingStack(Node *root)
{
    vector<int> ans;
    stack<Node *> st;

    if (root == NULL)
    {
        return ans;
    }

    st.push(root);

    while (!st.empty())
    {
        root = st.top();
        st.pop();

        ans.push_back(root->data);
        if (root->right)
        {
            st.push(root->right);
        }
        if (root->left)
        {
            st.push(root->left);
        }
    }
    return ans;
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

    vector<int> result = iterative_preorder_usingStack(root);

    for (auto i : result)
    {
        cout << i << " ";
    }

    return 0;
}

/*

stack -> last in first out
preorder -> Root, Left, Right but here after print put Right, Left in stack

*/