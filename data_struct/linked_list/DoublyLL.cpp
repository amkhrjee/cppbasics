// Doubly Linked List!
// most methods are same as in LL with tails so I'm not implementing them as of now
#include <iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node *prev;
        Node(int data) : data(data), next(NULL), prev(NULL) {}
    };
    Node *head, *tail;

public:
    LinkedList()
    {
        head = tail = NULL;
    }

    // helpers
    friend bool isEmpty(LinkedList &);
    friend int len(LinkedList &);
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
    void printRev();
};

// helpers

bool isEmpty(LinkedList &ll)
{
    if (ll.head == NULL)
        return true;
    return false;
}

int len(LinkedList &ll)
{
    if (!isEmpty(ll))
    {
        int counter = 0;
        while (ll.head != NULL)
        {
            ll.head = ll.head->next;
            counter++;
            cout << counter << endl;
        }
        return counter;
    }
    else
        return 0;
}

// insertion

void LinkedList::insertAtEnd(int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void LinkedList::insertAtBeg(int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = tail = newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void LinkedList::insertAt(int index, int data)
{
    if (index > len(*this) - 1 || index < 0)
    {
        cout << "Index out of bound" << endl;
        exit(1);
    }
    else if (index == 0)
        insertAtBeg(data);
    else if (index == len(*this) - 1)
        insertAtEnd(data);
    int flag = 0;
    Node *curr = head;
    Node *newNode = new Node(data);
    while (curr != NULL)
    {
        if (flag = index - 1)
        {
            newNode->next = curr->next;
            curr->next->prev = newNode;
            curr->next = newNode;
            newNode->prev = curr;
        }
    }
}

// display

void LinkedList::print()
{
    if (!isEmpty(*this))
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " <-> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
        return;
    }
    cout << "Empty List" << endl;
}

void LinkedList::printRev()
{
    if (!isEmpty(*this))
    {
        Node *curr = tail;
        while (curr != NULL)
        {
            cout << curr->data << " <-> ";
            curr = curr->prev;
        }
        cout << "NULL" << endl;
        return;
    }
    cout << "Empty List" << endl;
}

int main()
{
    LinkedList ll;
    ll.insertAtEnd(10);
    ll.insertAtEnd(60);
    ll.insertAtEnd(50);
    ll.insertAtEnd(40);
    ll.insertAtEnd(30);
    ll.print();
    ll.printRev();
}