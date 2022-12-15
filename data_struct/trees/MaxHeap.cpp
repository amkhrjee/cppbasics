// A minimal implementation of max heap
#include <iostream>
using namespace std;

void swap(int &, int &);

class MaxHeap
{
    int *harr;
    int capacity;
    int heap_size;

public:
    MaxHeap(int);
    void MaxHeapify(int);
    void insertKey(int);
    int extractMax();
    int left(int);
    int right(int);
    int parent(int);
    void print();
};

// implementations

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

MaxHeap::MaxHeap(int cap) : capacity(cap), heap_size(0)
{
    harr = new int[cap];
}

int MaxHeap::left(int i) { return (2 * i + 1); }
int MaxHeap::right(int i) { return (2 * i + 2); }
int MaxHeap::parent(int i) { return ((i - 1) / 2); }

void MaxHeap::insertKey(int key)
{
    if (heap_size == capacity)
    {
        cout << "Heap overflow" << endl;
        exit(1);
    }
    heap_size++;
    int i = heap_size - 1;
    harr[i] = key;
    while (i != 0 && harr[i] > harr[parent(i)])
    {
        swap(harr[i], harr[parent(i)]);
        i = parent(i);
    }
}

void MaxHeap::MaxHeapify(int i)
{
    if (i < 0 || i > heap_size - 1)
        exit(1);
    int max = i;
    int l = left(i);
    int r = right(i);
    if (i < heap_size && harr[max] < harr[l])
        max = l;
    if (i < heap_size && harr[max] < harr[r])
        max = r;
    if (max != i)
    {
        swap(harr[i], harr[max]);
        MaxHeapify(max);
    }
}

int MaxHeap::extractMax()
{
    if (heap_size == 0)
        exit(1);
    int root = harr[0];
    harr[0] = harr[heap_size - 1];
    heap_size--;
    MaxHeapify(0);
    cout << "Extracted!" << endl;
    return root;
}
void MaxHeap::print()
{
    for (int i = 0; i < heap_size; i++)
        cout << harr[i] << " ";
    cout << endl;
}
int main()
{
    MaxHeap mh(10);
    mh.insertKey(50);
    mh.insertKey(20);
    mh.insertKey(40);
    mh.insertKey(20);
    mh.insertKey(100);
    mh.print();
    cout << "Max: " << mh.extractMax() << endl;
}
