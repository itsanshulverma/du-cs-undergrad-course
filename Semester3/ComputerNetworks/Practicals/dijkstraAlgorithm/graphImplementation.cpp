#include <iostream>
using namespace std;

class Vertex
{
    public:
    int vertex;
    int adjVLength;
    Vertex *adjVertices;
    Vertex() {}
    Vertex(int vertex) { this->vertex = vertex; }
    Vertex(int vertex, int n) { 
        this->vertex = vertex;
        this->adjVLength = n;
        this->adjVertices = new Vertex[n];
    }
    void addEdge(int i, Vertex V)
    {
        adjVertices[i] = V;
    }
};

class Graph
{
    public:
    Vertex *adjList;
    int size;
    Graph(int noOfVertices){
        this->size = noOfVertices;
        this->adjList = new Vertex[noOfVertices];
    }

    void printAdjList()
    {
        for(int i = 0; i < size; ++i)
        {
            cout << "\n" << i << " -> [ ";
            for (int j; j < adjList[i].adjVLength; ++j)
            {
                cout << adjList[i].adjVertices[j].vertex << " ";
            }
            cout << "]";
        }
        cout << endl;
    }
};

Graph inputGraph()
{
    int n;
    cout << "\nEnter the total no of vertices: ";
    cin >> n;
    Graph g = Graph(n);
    for (int i = 0; i < n; ++i)
    {
        int v;
        cout << "Enter the no of adjacent vertices to V[" << i << "]: ";
        cin >> v;
        Vertex V = Vertex(i,v);
        cout << "Enter the vertices adjacent to V[" << i << "]: ";
        for (int j = 0; j < v; ++j)
        {
            int e;
            cin >> e;
            cout << " " << e << " ";
            Vertex V1 = Vertex(e);
            V.addEdge(j, V1);
        }
        g.adjList[i] = V;
    }
    return g;
}

int main(){

    Graph g = inputGraph();
    g.printAdjList();
    return  0;
}