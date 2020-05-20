#include <iostream>
using namespace std;
#define N 25

int main()
{
    int matrix[N][N], deg[N][2] = {0};
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
                matrix[i][j] = 1;
                ++deg[j][0];
                ++deg[i][1];
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

    cout << "\n\n--> Vertex | In-degree | Out-degree";
    for (int i = 0; i < v; i++)
    {
        cout << "\n-->   " << i + 1 << "    |     " << deg[i][0] << "     |     " << deg[i][1];
    }
    cout << endl;

    return 0;
}