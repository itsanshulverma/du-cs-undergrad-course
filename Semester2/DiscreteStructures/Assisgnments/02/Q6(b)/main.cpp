#include <iostream>
using namespace std;
#define N 25

int main()
{
    int **matrix, *deg;
    int v, sum = 0, count = 0;
    char ch;

    cout << "\nEnter the number of vertices : ";
    cin >> v;

    matrix = new int *[v];
    deg = new int[v];
    for (int i = 0; i < v; i++)
    {
        cout << endl;
        matrix[i] = new int[v];
        for (int j = 0; j < v; j++)
        {
            cout << "=> Is there a edge between " << i + 1 << " and " << j + 1 << " ? (y/n) : ";
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                matrix[i][j] = 1;
            }
            else
                matrix[i][j] = 0;
        }
    }

    cout << "\n--> Given Adjacency Matrix : \n";
    for (int i = 0; i < v; i++)
    {
        cout << "\n\t";
        for (int j = 0; j < v; j++)
        {
            cout << matrix[i][j] << " ";
        }
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
    cout << endl;
    for (int i = 0; i < v; i++)
    {
        cout << "\n--> Degree of Vertex " << i + 1 << " : " << deg[i];
    }
    for (int i = 0; i < v; i++)
    {
        if ((deg[i] % 2) != 0)
        {
            count++;
        }
    }
    if (count == 2 || count == 0)
        cout << "\n\n--> Hence, it has an euler path.";
    else
        cout << "\n\n--> Hence, it has no euler path.";
    cout << endl;

    return 0;
}