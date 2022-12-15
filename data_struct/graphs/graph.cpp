#include <iostream>
using namespace std;

class AdjMatrix
{
	TwoDMatrix graph;

public:
	AdjMatrix();
	AdjMatrix(int size);
	void AddEdge(unsigned, unsigned, int);
	void removeEdge(unsigned startVert, unsigned endVert);
	~AdjMatrix();
};

class TwoDMatrix
{
	int **data;
	int size;

public:
	TwoDMatrix()
		: data(nullptr),
		  size(0) {}
	TwoDMatrix(int size)
		: size(size)
	{
		int data[size][size];
	}
	void makeEdge(unsigned start, unsigned end, int weight)
	{
		data[start][end] = weight;
	}
	int getSize() { return size; }
	~TwoDMatrix()
	{
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				data[i][j] = 0;
			}
		}
		delete data;
	}
};

AdjMatrix::AdjMatrix(){};
AdjMatrix::AdjMatrix(int size) : graph(size){};
void AdjMatrix::AddEdge(unsigned start, unsigned end, int weight = 1)
{
	if (start < 0 || start > graph.getSize() || end < 0 || end > graph.getSize())
		exit(0);
	graph.makeEdge(start, end, weight);
}
void AdjMatrix::removeEdge(unsigned start, unsigned end)
{
	if (start < 0 || start > graph.getSize() || end < 0 || end > graph.getSize())
		exit(0);
	graph.makeEdge(start, end, 0);
}
AdjMatrix::~AdjMatrix()
{
	graph.~TwoDMatrix();
}