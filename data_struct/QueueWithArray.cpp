// A simple circular queue implementation
#include <iostream>
using namespace std;

class Queue
{
    int *arr;
    int size;
    int front, rear;

public:
    Queue(int size) : size(size)
    {
        arr = new int[size];
        front = rear = -1;
    }
    void push(int n)
    {
        if (rear + 1 != front)
        {
            if (front = -1)
            {
                front = 0;
            }
            rear = (rear + 1) % size;
            arr[rear] = n;
        }
        else
            cout << "Index out of bound" << endl;
    }

    void pop()
    {
        if (front >= 0)
        {
            front += 1;
        }
    }

    int peek()
    {
        if (front >= 0)
        {
            cout << arr[front] << endl;
        }
    }
};

int main()
{
    Queue q(10);
    for (int i = 1; i < 10; i++)
        q.push(i);
    q.peek();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.peek();
}