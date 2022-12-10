// Stack implementation using Linked List
#include "LinkedList.h"
using namespace std;

class Stack : public LinkedList
{
public:
    using LinkedList::LinkedList;

    // basic operations
    void push(int data)
    {
        insertAtBeg(data);
    }
    void pop()
    {
        deleteAtBeg();
    }
    int peek()
    {
        getFirst();
    }
    void print()
    {
        for (int i = 0; i < this->len(); i++)
        {
            cout << this->getAt(i) << endl;
        }
    }
};

int main()
{
    Stack s;
    s.push(45);
    s.push(35);
    s.push(55);
    s.push(65);
    s.push(425);
    s.print();
    for (int i = 0; i < 10; i++)
    {
        cout << "-";
    }
    cout << endl;
    s.pop();
    s.pop();
    s.pop();
    s.print();
    cout << "Peek: " << s.peek() << endl;
}