#include <iostream>
using namespace std;

#define N 10

// Function to multiply two matrices
void multiply(int a[][N], int b[][N], int res[][N], int v)
{
    int mul[N][N];
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            mul[i][j] = 0;
            for (int k = 0; k < v; k++)
                mul[i][j] += a[i][k] * b[k][j];
        }
    }

    // Storing the multiplication result in res[][]
    for (int i = 0; i < v; i++)
        for (int j = 0; j < v; j++)
            res[i][j] = mul[i][j];
}

// Function to compute G raised to the power n
void power(int G[N][N], int res[N][N], int n, int v)
{

    // Base condition
    if (n == 1)
    {
        for (int i = 0; i < v; i++)
            for (int j = 0; j < v; j++)
                res[i][j] = G[i][j];
        return;
    }

    // Recursion call for first half
    power(G, res, n / 2, v);

    // Multiply two halves
    multiply(G, G, res, v);

    // If n is odd
    if (n % 2 != 0)
        multiply(res, G, res, v);
}

int main()
{
    int n, source, dest, res[N][N];
    int G[N][N];
    int v;
    char ch;

    cout << "\nEnter the number of vertices : ";
    cin >> v;
    for (int i = 0; i < v; i++)
    {
        cout << endl;
        for (int j = 0; j < v; j++)
        {
            cout << "=> Is there a edge " << i + 1 << "--> " << j + 1 << " ? (y/n) : ";
            cin >> ch;
            if (ch == 'Y' || ch == 'y')
            {
                G[i][j] = 1;
            }
            else
                G[i][j] = 0;
        }
    }

    cout << "\n--> Given Adjacency Matrix : \n";
    for (int i = 0; i < v; i++)
    {
        cout << "\n\t";
        for (int j = 0; j < v; j++)
        {
            cout << G[i][j] << " ";
        }
    }

    cout << "\n\nEnter the path length : ";
    cin >> n;
    cout << "Enter the source : ";
    cin >> source;
    cout << "Enter the destination : ";
    cin >> dest;

    power(G, res, n, v);

    cout << "\n--> Number of paths of length " << n
         << " from <" << source << "> to <" << dest << "> : "
         << res[source - 1][dest - 1] << "\n";

    return 0;
}