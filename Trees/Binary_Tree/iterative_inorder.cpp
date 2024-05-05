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

vector<int> iterative_inorder_usingStack(Node *root)
{
    vector<int> ans;
    stack<Node *> st;
    Node *temp = root;

    while (true)
    {
        if (temp != NULL)
        {
            st.push(temp);
            temp = temp->left;
        }
        else
        {
            if (st.empty())
            {
                break;
            }
            temp = st.top();
            st.pop();
            ans.push_back(temp->data);
            temp = temp->right;
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

    vector<int> result = iterative_inorder_usingStack(root);

    for (auto i : result)
    {
        cout << i << " ";
    }

    return 0;
}

/*

Inorder -> Left, Root, Right

*/