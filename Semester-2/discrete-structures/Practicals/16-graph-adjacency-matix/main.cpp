#include <iostream>
using namespace std;

//Adjacency Matrix
int adjMatrix[10][10] = {0};

void displayMatrix(int v)
{
    for (int i = 0; i < v; i++)
    {
        cout << endl
             << "\t";
        for (int j = 0; j < v; j++)
        {
            cout << adjMatrix[i][j] << " ";
        }
    }
}

int main()
{
    int v, e, x; //v= no of vertices , e= no of adjacent vertices, x= adjacent vertex
    int count = 0;
    cout << "Enter the total number of vertices : ";
    cin >> v;

    for (int i = 1; i <= v; i++)
    {
        cout << "Enter the no. of vertices adjacent to " << i << " : ";
        cin >> e;
        cout << "Enter the adjacent vertices : ";
        for (int j = 1; j <= e; j++)
        {
            cin >> x;
            adjMatrix[i - 1][x - 1] = 1;
            count++;
        }
    }

    displayMatrix(v);

    if (count == ((v * v) - v))
    {

        cout << endl
             << endl
             << "-> This is a Complete Graph" << endl;
    }
    else
    {
        cout << endl
             << endl
             << "-> This is not a Complete Graph" << endl;
    }

    return 0;
}