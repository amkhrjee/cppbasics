// a minimal implementation of a binary min heap
#include <iostream>
using namespace std;

// helper swap
void swap(int &, int &);

class MinHeap
{
    int *harr;
    int heap_size;
    int capacity;

public:
    MinHeap(int);
    int left(int);
    int right(int);
    int parent(int);
    void insertKey(int);
    void deleteKeyAt(int);
    int extractMin();
    void MinHeapify(int);
    void setKeyAt(int, int);
    void print();
};

// implementations
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

MinHeap::MinHeap(int cap) : capacity(cap), heap_size(0)
{
    harr = new int[cap];
}

int MinHeap::parent(int i) { return (i - 1) / 2; }
int MinHeap::left(int i) { return (2 * i + 1); }
int MinHeap::right(int i) { return (2 * i + 2); }

void MinHeap::insertKey(int key)
{
    if (heap_size == capacity)
    {
        cout << "Overflow" << endl;
        exit(1);
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = key;
    while (i != 0 && harr[i] < harr[parent(i)])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MinHeap::setKeyAt(int index, int key)
{
    if (index > heap_size - 1 || index < 0)
    {
        cout << "Index out of bound" << endl;
        exit(1);
    }
    harr[index] = key;
    while (index != 0 && harr[index] < harr[parent(index)])
    {
        swap(harr[index], harr[parent(index)]);
        index = parent(index);
    }
}

void MinHeap::MinHeapify(int index)
{
    if (index > heap_size - 1 || index < 0)
    {
        cout << "Index out of bound" << endl;
        exit(1);
    }

    int smallest = index;
    int l = left(index);
    int r = right(index);
    if (l < heap_size && harr[l] < harr[smallest])
        smallest = l;
    if (r < heap_size && harr[r] < harr[smallest])
        smallest = r;
    if (smallest != index)
    {
        swap(harr[smallest], harr[index]);
        cout << "smallest: " << smallest << endl;
        MinHeapify(smallest);
    }
}

int MinHeap::extractMin()
{
    if (heap_size <= 0)
        exit(1);
    else if (heap_size == 1)
    {
        heap_size--;
        cout << "Extracted!";
        return harr[0];
    }
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MinHeapify(0);
    // cout << "Extracted!";
    return root;
}

void MinHeap::deleteKeyAt(int index)
{
    setKeyAt(index, INT16_MIN);
    extractMin();
}

void MinHeap::print()
{
    for (int i = 0; i < heap_size; i++)
        cout << harr[i] << " ";
    cout << endl;
}

int main()
{
    MinHeap mh(10);
    mh.insertKey(34);
    mh.insertKey(12);
    mh.insertKey(324);
    mh.insertKey(0);
    mh.insertKey(323);
    mh.insertKey(-34);
    mh.print();
    for (int i = 0; i < 10; i++)
        cout << "-";
    cout << endl;
    cout << "Min: " << mh.extractMin() << endl;
    mh.deleteKeyAt(3);
    mh.print();
}