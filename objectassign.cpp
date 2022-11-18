#include <iostream>
using namespace std;

class Simple
{
public:
	int x;
};

class Stack
{
public:
	Simple simple;
};

class Heap
{
public:
	Simple *simple;
	Heap(int set_x)
	{
		simple = new Simple;
		simple->x = set_x;
	}
};

int main()
{
	Stack stackA;
	stackA.simple.x = 4;
	Stack stackB;
	stackB.simple.x = 10;

	stackA = stackB;
	cout << stackA.simple.x << endl;

	Heap heapA(40);
	Heap heapB(50);

	cout << "heapA.simple->x: " << heapA.simple->x << endl;
	cout << "heapB.simple->x: " << heapB.simple->x << endl;

	heapA = heapB;

	cout << "heapA.simple->x: " << heapA.simple->x << endl;
	cout << "heapB.simple->x: " << heapB.simple->x << endl;

	heapA.simple->x = 69;

	cout << "heapA.simple->x: " << heapA.simple->x << endl;
	cout << "heapB.simple->x: " << heapB.simple->x << endl;

	heapB.simple->x = 56;

	cout << "heapA.simple->x: " << heapA.simple->x << endl;
	cout << "heapB.simple->x: " << heapB.simple->x << endl;
}
