#include <bits/stdc++.h>
using namespace std;
#define SIZE 5

int arr[SIZE];
int front = -1; // delete
int rear = -1;  // add

bool isEmpty()
{
    if (front == -1 && rear == -1)
    {
        return true;
    }
    return false;
}

bool isFull()
{
    if (rear + 1 == SIZE)
    {
        return true;
    }
    return false;
}

void enqueue(int x)
{
    if (isFull())
    {
        cout << "Queue overflow";
        return;
    }
    else if (isEmpty())
    {
        front = rear = 0;
    }
    else
    {
        rear++;
    }
    arr[rear] = x;
}

int dequeue()
{
    if (isEmpty())
    {
        cout << "Queue underflow";
        return -1;
    }
    int x = arr[front];
    if (front == rear)
    {
        front = rear = -1;
    }
    else
    {
        arr[front] = 0;
        front++;
    }
    return x;
}

void printQueue()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << endl
             << arr[i];
    }
}

int main()
{
    enqueue(5);
    enqueue(9);
    enqueue(2);
    enqueue(7);
    enqueue(1);

    cout << "pop: " << dequeue() << endl;
    // cout << "pop: " << dequeue() << endl;
    // cout << "pop: " << dequeue() << endl;

    enqueue(101);

    printQueue();
    return 0;
}