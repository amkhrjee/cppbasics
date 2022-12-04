// Singly Linked List without tail pointer
// The member functions have been impleneted inside the class
// definition for the sake of simplicity

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
    bool isEmpty = false;
    // error handling
    inline int errorOut()
    {
        cout << "List is empty!" << endl;
        return 0;
    }

public:
    LinkedList()
    {
        // initially points to nothing
        head = NULL;
    }
    int len()
    {
        int count = 0;
        if (head == NULL)
        {
            return 0;
        }
        else
        {
            Node *curr = head;
            while (curr != NULL)
            {
                curr = curr->next;
                count++;
            }
            return count;
        }
    }
    bool is_empty()
    {
        if (head == NULL)
        {
            isEmpty = true;
            return true;
        }
        else
            return false;
    }
    // insertion
    void insertAtEnd(int data)
    {
        // we create a new node with the data
        Node *newNode = new Node(data);
        // first we check whether the LL already has other nodes or not
        if (head == NULL)
        {
            // if it doesn't, we simply point the head to the newNode
            head = newNode;
        }
        else // otherwise we traverse through the list till we hit
             // a node that points to NULL (the end of the list)
        {
            // here curr is our iterator, we set to the beginning first
            // if it is not NULL, then we simply change to the next node
            Node *curr = head;
            while (curr->next != NULL)
                curr = curr->next;
            curr->next = newNode;
        }
    }
    void insertAtBeg(int data)
    {
        Node *newNode = new Node(data);
        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            Node *curr = head;
            // we point the next pointer of the
            // new node to whatever head was pointing to
            // and then we set head to point to the new node
            newNode->next = head;
            head = newNode;
        }
    }
    void insertAt(int data, int index)
    {
        if (len() - 1 < index)
        {
            cout << "Index out of bound" << endl;
        }
        else
        {
            Node *newNode = new Node(data);
            int flag = 0;
            Node *curr = head;
            while (curr != NULL)
            {
                if (flag == index - 1)
                {
                    newNode->next = curr->next;
                    curr->next = newNode;
                }
                curr = curr->next;
                flag++;
            }
        }
    }
    // deletion
    void deleteEnd()
    {
        if (!isEmpty)
        {
            Node *curr = head;
            while (curr->next->next != NULL)
            {
                curr = curr->next;
            }
            delete (curr->next);
            curr->next = NULL;
        }
        else
            errorOut();
    }
    void deleteBeg()
    {
        if (!isEmpty)
        {
            Node *curr = head;
            head = curr->next;
            delete (curr);
        }
        else
            errorOut();
    }
    void deleteAt(int index)
    {
        if (!isEmpty)
        {
            if (len() - 1 < index)
            {
                cout << "Index out of bound" << endl;
                return;
            }
            else
            {
                int flag = 0;
                Node *curr = head;
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
            errorOut();
    }
    // getters
    int getLast()
    {
        // a tail pointer would have been nice!
        if (!isEmpty)
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            return curr->data;
        }
        else
            errorOut();
    }
    int getFirst()
    {
        if (!isEmpty)
        {
            return head->data;
        }
        else
            errorOut();
    }
    // setters
    void setLast(int data)
    {
        if (!isEmpty)
        {
            Node *curr = head;
            while (curr->next != NULL)
            {
                curr = curr->next;
            }
            curr->data = data;
        }
        else
            errorOut();
    }
    void setFirst(int data)
    {
        if (!isEmpty)
        {
            head->data = data;
        }
        else
            errorOut();
    }
    void setAt(int data, int index)
    {
        if (!isEmpty)
        {
            int flag = 0;
            Node *curr = head;
            while (curr->next != NULL)
            {
                if (flag == index)
                {
                    curr->data = data;
                }
                curr = curr->next;
                flag++;
            }
        }
        else
            errorOut();
    }
    // maxmin
    int findMax()
    {
        int max = 0;
        if (!isEmpty)
        {
            Node *curr = head;
            while (curr != NULL)
            {
                if (max < curr->data)
                {
                    max = curr->data;
                }
                curr = curr->next;
            }
            return max;
        }
        else
        {
            errorOut();
        }
    }
    int findMin()
    {
        int min = INT16_MAX;
        if (!isEmpty)
        {
            Node *curr = head;
            while (curr != NULL)
            {
                if (min > curr->data)
                {
                    min = curr->data;
                }
                curr = curr->next;
            }
            return min;
        }
        else
            errorOut();
    }
    // searching
    void find(int data)
    {
        int index = 0;
        if (!isEmpty)
        {
            Node *curr = head;
            while (curr != NULL)
            {
                if (curr->data == data)
                {
                    cout << "Found at index: " << index << endl;
                    return;
                }
                curr = curr->next;
                index++;
            }
            cout << "Not Found!" << endl;
            return;
        }
        else
            errorOut();
    }
    //  display
    void print()
    {
        if (head == NULL)
        {
            cout << "Linked List is empty!" << endl;
            return;
        }
        else
        {
            Node *curr = head;
            while (curr != NULL)
            {
                cout << curr->data << "-> ";
                curr = curr->next;
            }
            cout << "NULL" << endl;
        }
    }
};

int main()
{
    LinkedList ll = LinkedList();
    ll.insertAtEnd(90);
    ll.insertAtEnd(80);
    ll.insertAtEnd(70);
    ll.insertAtEnd(60);
    ll.insertAtEnd(50);
    ll.insertAtEnd(40);
    ll.insertAtEnd(30);
    ll.print();
    ll.insertAtEnd(20);
    ll.deleteAt(3);
    ll.print();
    ll.find(30);
}