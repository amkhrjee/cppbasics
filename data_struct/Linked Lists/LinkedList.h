#include <iostream>
class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node(int data) : data(data), next(NULL) {}
    };

protected:
    Node *head;
    Node *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }
    // helpers
    bool isEmpty();
    int len();
    // insertion
    void insertAtEnd(int);
    void insertAtBeg(int);
    void insertAt(int, int);
    // deletion
    void deleteAtEnd();
    void deleteAtBeg();
    void deleteAt(int);
    // setters
    void setLast(int);
    void setFirst(int);
    void setAt(int, int);
    // getters
    int getLast();
    int getFirst();
    int getAt(int);
    // minmax
    friend int findMin(LinkedList &);
    friend int findMax(LinkedList &);
    // search
    friend void search(LinkedList &, int);
    // display
    void print();
    // destructor
    ~LinkedList();
};
