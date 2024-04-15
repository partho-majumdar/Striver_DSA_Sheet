#include <bits/stdc++.h>
using namespace std;
#define SIZE 5

int arr[SIZE];
int front = -1;
int rear = -1;

bool isFull()
{
    if ((rear + 1) % SIZE == front)
    {
        return true;
    }
    return false;
}

bool isEmpty()
{
    if (front == -1 && rear == -1)
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
        rear = (rear + 1) % SIZE;
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
        // arr[front] = 0;
        front = (front + 1) % SIZE;
    }
    return x;
}

void printQueue()
{
    for (int i = 0; i < SIZE; i++)
    {
        cout << arr[i] << endl;
    }
}

int main()
{
    enqueue(8);
    enqueue(1);
    enqueue(9);
    enqueue(3);
    enqueue(5);

    cout << "pop: " << dequeue() << endl;
    cout << "pop: " << dequeue() << endl;

    enqueue(201);

    printQueue();
    return 0;
}