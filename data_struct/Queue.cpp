// Queue using Linked List
#include "LinkedList.h"
using namespace std;

class Queue : private LinkedList
{
public:
    using LinkedList::LinkedList;
    // operations
    void enqueue(int data)
    {
        insertAtEnd(data);
    }
    void dequeue()
    {
        deleteAtBeg();
    }
    void print()
    {
        for (int i = 0; i < len(); i++)
        {
            cout << getAt(i) << endl;
        }
    }
};

int main()
{
    Queue q;
    q.enqueue(45);
    q.enqueue(55);
    q.enqueue(785);
    q.print();
    q.dequeue();
    q.print();
}