#include <iostream>
#include <unordered_map>
#include <list>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;
    void addEdge(int u, int v, bool dir)
    {
        adj[u].push_back(v);
        if (!dir)
            adj[v].push_back(u);
    }

    void printBFS()
    {
        // we need to maintain a queue
    }

    void printAdjList()
    {
        for (auto i : adj)
        {
            cout << i.first << " - > ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    Graph graph;
    graph.addEdge(3, 4, 0);
    graph.addEdge(6, 7, 0);
    graph.addEdge(5, 6, 0);
    graph.printAdjList();
}