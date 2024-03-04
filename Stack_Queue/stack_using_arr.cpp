#include <bits/stdc++.h>
using namespace std;

int myStack[5] = {0};
int top = -1;

void myPush(int x)
{
    myStack[++top] = x;
}

void myPop()
{
    myStack[--top];
    myStack[top + 1] = 0;
}

void myTop()
{
    int ans = myStack[top];
    cout << endl;
    cout << "Top: " << ans;
}

void stackSize()
{
    cout << endl;
    cout << "Size: " << top + 1;
}

void printStack()
{
    for (int i = 4; i >= 0; i--)
    {
        cout << myStack[i] << endl;
    }
}

int main()
{
    myPush(18);
    myPush(11);
    myPush(19);

    myPop();

    myPush(22);

    printStack();

    myTop();

    stackSize();

    return 0;
}
