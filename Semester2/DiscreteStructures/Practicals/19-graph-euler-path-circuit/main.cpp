#include <iostream>
using namespace std;

int main()
{
    int **matrix, *deg, *vertices;
    int v, n, sum = 0, flag = 1, count = 0;
    cout << "\nEnter the dimension of matrix : ";
    cin >> v;

    matrix = new int *[v];
    deg = new int[v];

    for (int i = 0; i < v; i++)
    {
        matrix[i] = new int[v];
        cout << "Enter the elements in row " << i + 1 << " : ";
        for (int j = 0; j < v; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "\n--> Adjacency Matrix \n ";
    for (int m = 0; m < v; m++)
    {
        cout << "\n    ";
        for (int n = 0; n < v; n++)
            cout << matrix[m][n] << " ";
    }

    for (int i = 0; i < v; i++)
    {
        sum = 0;
        for (int j = 0; j < v; j++)
        {
            sum += matrix[i][j];
        }
        deg[i] = sum;
    }

    cout << "\n\nEnter the no of vertices followed by the vertices to be checked : ";
    cin >> n;
    vertices = new int[n];

    for (int i = 0; i < n; i++)
    {
        cin >> vertices[i];
    }

    for (int i = 0; i < n; i++)
    {
        cout << "\n--> Degree of Vertex " << vertices[i] << " : " << deg[vertices[i] - 1];
    }

    for (int i = 0; i < n; i++)
    {
        if ((deg[vertices[i] - 1] % 2) != 0)
        {
            flag = 0;
            count++;
        }
    }
    if (flag == 1)
        cout << "\n\n--> There is an euler circuit.";
    else
        cout << "\n\n--> There is no euler circuit.";
    if (count == 2 || flag == 1)
        cout << "\n\n--> There is an euler path.";
    else
        cout << "\n\n--> There is no euler path.";
    cout << endl;
    return 0;
}