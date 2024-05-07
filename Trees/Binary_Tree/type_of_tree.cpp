#include <iostream>
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

int height(Node *root)
{
    if (root == NULL)
    {
        return 0;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if (rh == -1 || rh == -1)
    {
        return -1;
    }

    if (abs(lh - rh) > 1)
    {
        return -1;
    }

    return 1 + max(lh, rh);
}

bool isBalanced(Node *root)
{
    if (root == NULL)
    {
        return true;
    }

    int lh = height(root->left);
    int rh = height(root->right);

    if (lh == -1 || rh == -1 || abs(lh - rh) > 1)
    {
        return false;
    }

    return isBalanced(root->left) && isBalanced(root->right);
}

bool isComplete(Node *root, int index, int size)
{
    if (root == NULL)
    {
        return true;
    }

    if (index >= size)
    {
        return false;
    }

    return isComplete(root->left, 2 * index + 1, size) && isComplete(root->right, 2 * index + 2, size);
}

bool isPerfect(Node *root, int index, int size)
{
    if (root == NULL)
    {
        return true;
    }

    if (index >= size || (root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL))
    {
        return false;
    }

    return isPerfect(root->left, 2 * index + 1, size) && isPerfect(root->right, 2 * index + 2, size);
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

    if (isBalanced(root))
    {
        cout << "Balanced" << endl;
    }
    else
    {
        cout << "Not balanced" << endl;
    }

    int size = pow(2, (int)log2(8) + 1) - 1;

    if (isComplete(root, 0, size))
    {
        cout << "Complete" << endl;
    }
    else
    {
        cout << "Not complete" << endl;
    }

    if (isPerfect(root, 0, size))
    {
        cout << "Perfect" << endl;
    }
    else
    {
        cout << "Not perfect" << endl;
    }

    return 0;
}