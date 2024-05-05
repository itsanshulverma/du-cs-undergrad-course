/*
    Implementation of Dijkstra algorithm in routing using Adjacency Matrix
    Author: Anshul Verma, 19/78065
*/

#include <iostream>
#include <string>
using namespace std;

int extractMinVertex(int *dist, bool *visited, int n)
{
    int minIndex = -1;
    for (int i = 0; i < n; i++)
        if(!visited[i] && (minIndex == -1 || dist[minIndex] > dist[i]))
            minIndex = i;
    return minIndex;
}

// Dijkstra Algorithm
void dijkstra(int **adj, int n, int source, int dest)
{
    int *dist = new int[n];
    bool *visited = new bool[n];
    string *path = new string[n];

    // Inintialising each element of distance(with INF)
    // visited(with false)
    // path with ""
    for (int i = 0; i < n; i++)
    {
        dist[i] = INT16_MAX;
        visited[i] = false;
        path[i] = "";
    }

    // Source -> Source: 0
    dist[source] = 0;

    // Main Algorithm
    for (int i = 0; i < n-1; i++)
    {
        int minVertex = extractMinVertex(dist, visited, n);
        visited[minVertex] = true;
        for (int j = 0; j < n; j++)
        {
            if(!visited[j] && adj[minVertex][j] != 0)
            {
              int dist_1 = dist[minVertex] + adj[minVertex][j];
                string temp = path[minVertex] + " -> " + to_string(minVertex + 1);
                if(dist_1 < dist[j])
                {
                    dist[j] = dist_1;
                    path[j] = temp;
                }
            }
        }
    }
    
    // Printing result
    cout << "\nShortest path: " << path[dest] << " -> " << dest + 1;
    cout << "\nShortest path length: " << dist[dest];
}

// to print adjacency matrix
void printAdjMatrix(int **adj, int n)
{
    cout << "\n     ";
    for (int i = 0; i < n; i++)
    {
        cout << i+1 << "  ";    
    }
    cout << "\n  ------------------";
    for(int i = 0; i < n; ++i)
    {
        cout << "\n" << i+1 << " |  ";
        for (int j = 0; j < n; ++j)
        {
            cout << adj[i][j] << "  ";
        }
    }
    cout << endl;
}

int main(){
    // Input as a Graph
    int **adj, n;
    cout << "\nEnter the total no of routers in the network: ";
    cin >> n;
    adj = new int* [n];
    for (int i = 0; i < n; i++)
    {
        adj[i] = new int[n];
        for (int j = 0; j < n; ++j)
        {
            adj[i][j] = 0;
        }
    }
    for (int i = 0; i < n; ++i)
    {
        int v;
        cout << "\nEnter the no of routers adjacent to Router " << i+1 << ": ";
        cin >> v;
        for (int j = 0; j < v; ++j)
        {
            int a, e;
            cout << "Enter an adjacent router # and edge weight b/w them: ";
            cin >> a;
            cin >> e;
            adj[i][a-1] = e;
            adj[a-1][i] = e;
        }
    }

    // Printing adjacenecy matrix for the graph
    printAdjMatrix(adj, n);

    // Input source and destination
    int source, dest;
    cout << "\nEnter source router: ";
    cin >> source;
    cout << "Enter destination router: ";
    cin >> dest;

    // Applying Dijkstra Algorithm
    dijkstra(adj, n, source-1, dest-1);

    cout << "\n\n";
    return 0;
}