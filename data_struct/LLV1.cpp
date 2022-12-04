// This is a Linked List implementation with tail pointer
// + a few improvements + horrendous error handling :)
#include <iostream>
using namespace std;

class LinkedList
{
    struct Node
    {
        int data;
        Node *next;
        Node(int data) : data(data), next(NULL) {}
    };
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
};

// helpers
bool LinkedList::isEmpty()
{
    if (head == NULL)
    {
        return true;
    }
    else
        return false;
}

int LinkedList::len()
{
    if (!isEmpty())
    {
        int count = 0;
        Node *curr = head;
        while (curr != NULL)
        {
            curr = curr->next;
            count++;
        }
        return count;
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
    }
    else
    {
        Node *curr = tail;
        tail = newNode;
        curr->next = newNode;
    }
}

void LinkedList::insertAtBeg(int data)
{
    Node *newNode = new Node(data);
    if (head == NULL)
    {
        head = tail = newNode;
    }
    else
    {
        newNode->next = head;
        head = newNode;
    }
}

void LinkedList::insertAt(int index, int data)
{
    if (!isEmpty())
    {
        if (index > len() - 1)
        {
            cout << "Index out of bound" << endl;
            return;
        }
        int flag = 0;
        Node *curr = head;
        Node *newNode = new Node(data);
        while (curr != NULL)
        {
            if (index == 0)
            {
                newNode->next = head;
                head = newNode;
                return;
            }
            else if (flag == index - 1)
            {
                newNode->next = curr->next;
                curr->next = newNode;
            }
            curr = curr->next;
            flag++;
        }
    }
    else
    {
        cout << "Empty List" << endl;
    }
}

// deletion

void LinkedList::deleteAtEnd()
{
    if (!isEmpty())
    {
        Node *curr = head;
        while (curr->next->next != NULL)
        {
            curr = curr->next;
        }
        delete (curr->next);
        curr->next = NULL;
        tail = curr;
        return;
    }
    else
        return;
}

void LinkedList::deleteAtBeg()
{
    if (!isEmpty())
    {
        Node *first = head;
        head = first->next;
        delete (first);
        return;
    }
    else
        return;
}

void LinkedList::deleteAt(int index)
{
    if (!isEmpty())
    {
        if (index > len() - 1 || index < 0)
        {
            cout << "Index out of bound" << endl;
            return;
        }
        int flag = 0;
        Node *curr = head;
        if (index == 0)
        {
            deleteAtBeg();
        }
        else if (index == len() - 1)
        {
            deleteAtEnd();
        }
        else
        {
            while (curr != NULL)
            {
                if (flag == index - 1)
                {
                    Node *del = curr->next;
                    curr->next = curr->next->next;
                    delete (del);
                    return;
                }
                curr = curr->next;
                flag++;
            }
        }
    }
    else
        return;
}

// getters

int LinkedList::getFirst()
{
    if (!isEmpty())
        return head->data;
    else
        exit(1);
}

int LinkedList::getLast()
{
    if (!isEmpty())
        return tail->data;
    else
        exit(1);
}

int LinkedList::getAt(int index)
{
    if (!isEmpty())
    {
        if (index > len() - 1 || index < 0)
        {
            cout << "index out of bound" << endl;
            exit(1);
        }
        Node *curr = head;
        int flag = 0;
        while (curr != NULL)
        {
            if (flag == index)
                return curr->data;
            curr = curr->next;
            flag++;
        }
    }

    cout << "Empty list" << endl;
    exit(1);
}

// setters

void LinkedList::setLast(int data)
{
    if (!isEmpty())
    {
        tail->data = data;
    }
}

void LinkedList::setFirst(int data)
{
    if (!isEmpty())
    {
        head->data = data;
    }
}

void LinkedList::setAt(int index, int data)
{
    if (!isEmpty())
    {
        if (index > len() - 1 || index < 0)
        {
            cout << "Index out of bound" << endl;
            return;
        }
        else if (index == 0)
            setFirst(data);
        else if (index == len() - 1)
            setLast(data);
        else
        {
            int flag = 0;
            Node *curr = head;
            while (curr != NULL)
            {
                if (flag == index)
                {
                    curr->data = data;
                    return;
                }
                curr = curr->next;
                flag++;
            }
        }
    }
}

// minmax

int findMin(LinkedList &ll)
{
    int min = INT16_MAX;
    if (!ll.isEmpty())
    {
        for (int i = 0; i < ll.len(); i++)
        {
            if (min > ll.getAt(i))
                min = ll.getAt(i);
        }
        return min;
    }
    else
        exit(1);
}

int findMax(LinkedList &ll)
{
    int max = INT16_MIN;
    if (!ll.isEmpty())
    {
        for (int i = 0; i < ll.len(); i++)
        {
            if (max < ll.getAt(i))
                max = ll.getAt(i);
        }
        return max;
    }
    else
        exit(1);
}

// search

void search(LinkedList &ll, int data)
{
    for (int i = 0; i < ll.len(); i++)
    {
        if (data == ll.getAt(i))
        {
            cout << "Found at index: " << i << endl;
            return;
        }
    }

    cout << "Not found" << endl;
    return;
}

// display

void LinkedList::print()
{
    if (head == NULL)
    {
        cout << "Empty List!" << endl;
    }
    else
    {
        Node *curr = head;
        while (curr != NULL)
        {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL" << endl;
    }
}

int main()
{
    LinkedList ll;
    ll.insertAtEnd(12);
    ll.insertAtEnd(17);
    ll.insertAtEnd(560);
    ll.insertAtEnd(40);
    ll.insertAtEnd(30);
    ll.insertAtBeg(20);
    ll.insertAt(2, 76);
    ll.insertAt(1, 6);
    ll.insertAt(0, 456);
    ll.deleteAtEnd();
    ll.deleteAtBeg();
    ll.deleteAt(3);
    cout << "Last: " << ll.getLast() << endl
         << "First: " << ll.getFirst() << endl
         << "At 3: " << ll.getAt(3) << endl;
    ll.setFirst(69);
    ll.setLast(2000);
    ll.setAt(3, 420);
    cout << "Max: " << findMax(ll) << endl
         << "Min: " << findMin(ll) << endl;
    ll.print();
    search(ll, 420);
}