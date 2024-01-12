#include <bits/stdc++.h>
using namespace std;

// struct Node
class Node
{
public:
    int data;
    Node *next;

public:
    Node(int d1, Node *n1)
    {
        data = d1;
        next = n1;
    }
};

int main()
{
    vector<int> arr = {2, 5, 8, 7};
    Node x = Node(arr[0], nullptr);

    // shortcut
    // Node *y = new Node (arr[0], nullptr);
    Node *y = &x;

    cout << y << endl; // give me memory address
    cout << y->data << " " << y->next;
    return 0;
}