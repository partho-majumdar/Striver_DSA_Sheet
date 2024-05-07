#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node *parent;

    Node(int data)
    {
        this->data = data;
        this->left = this->right = this->parent = nullptr;
    }
};

// Function to find the parent of a node
Node *findParent(Node *root, Node *node)
{
    if (root == nullptr || root == node)
    {
        return nullptr;
    }

    if (root->left == node || root->right == node)
    {
        return root;
    }

    Node *leftParent = findParent(root->left, node);
    if (leftParent != nullptr)
    {
        return leftParent;
    }

    return findParent(root->right, node);
}

// Function to find the child nodes of a node
void findChildren(Node *node, Node *&child1, Node *&child2)
{
    if (node == nullptr)
    {
        child1 = nullptr;
        child2 = nullptr;
    }
    else
    {
        child1 = node->left;
        child2 = node->right;
    }
}

// Function to find the grandparent of a node
Node *findGrandparent(Node *node)
{
    if (node == nullptr || node->parent == nullptr || node->parent->parent == nullptr)
    {
        return nullptr;
    }

    return node->parent->parent;
}

// Function to find the ancestor of a node
Node *findAncestor(Node *root, Node *node)
{
    if (root == nullptr || root == node)
    {
        return nullptr;
    }

    if (root->left == node || root->right == node)
    {
        return root;
    }

    Node *leftAncestor = findAncestor(root->left, node);
    if (leftAncestor != nullptr)
    {
        return leftAncestor;
    }

    return findAncestor(root->right, node);
}

// Function to find the successor of a node
Node *findSuccessor(Node *node)
{
    if (node == nullptr)
    {
        return nullptr;
    }

    if (node->right != nullptr)
    {
        Node *successor = node->right;
        while (successor->left != nullptr)
        {
            successor = successor->left;
        }
        return successor;
    }

    Node *parent = node->parent;
    while (parent != nullptr && parent->right == node)
    {
        node = parent;
        parent = parent->parent;
    }

    return parent;
}

// Function to find the height of a node
int findHeight(Node *node)
{
    if (node == nullptr)
    {
        return -1;
    }

    int leftHeight = findHeight(node->left);
    int rightHeight = findHeight(node->right);

    return max(leftHeight, rightHeight) + 1;
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

    Node *node = root->left->left; // node = 4

    Node *parent = findParent(root, node);
    Node *child1, *child2;
    findChildren(node, child1, child2);
    Node *grandparent = findGrandparent(node);
    Node *ancestor = findAncestor(root, node);
    Node *successor = findSuccessor(node);
    int height = findHeight(node);

    cout << "Parent of " << node->data << " is: " << (parent ? to_string(parent->data) : "nullptr") << endl;
    cout << "Child1 of " << node->data << " is: " << (child1 ? to_string(child1->data) : "nullptr") << endl;
    cout << "Child2 of " << node->data << " is: " << (child2 ? to_string(child2->data) : "nullptr") << endl;
    cout << "Grandparent of " << node->data << " is: " << (grandparent ? to_string(grandparent->data) : "nullptr") << endl;
    cout << "Ancestor of " << node->data << " is: " << (ancestor ? to_string(ancestor->data) : "nullptr") << endl;
    cout << "Successor of " << node->data << " is: " << (successor ? to_string(successor->data) : "nullptr") << endl;
    cout << "Height of node " << node->data << " is: " << height << endl;

    return 0;
}
