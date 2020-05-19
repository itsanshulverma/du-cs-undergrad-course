#include <iostream>
using namespace std;
int main()
{
    int v, i, j, p = 0, sum = 0, flag = 0, c = 0;
    cout << "\nEnter number of vertices in the graph : ";
    cin >> v;
    int arr[v][v], arr1[v];
    for (i = 0; i < v; i++)
    {
        for (j = 0; j < v; j++)
        {
            cout << "--> How many edge from " << (char)(97 + i) << " to " << (char)(97 + j) << " : ";
            cin >> arr[i][j];
        }
    }
    cout << "\n--> Adjacency Matrix \n ";
    for (int m = 0; m < v; m++)
    {
        cout << endl
             << "    ";
        for (int n = 0; n < v; n++)
            cout << arr[m][n] << " ";
    }
    for (i = 0; i < v; i++)
    {
        sum = 0;
        for (j = 0; j < v; j++)
        {
            sum += arr[i][j];
        }
        arr1[i] = sum;
    }
    cout << endl;
    for (i = 0; i < v; i++)
    {
        cout << "\n--> Degree of " << (char)(97 + i) << " -- " << arr1[i];
    }
    for (i = 0; i < v; i++)
    {
        if ((arr1[i] % 2) != 0)
        {
            cout << "\n\n--> There is no euler circuit";
            flag = 1;
            c++;
        }
    }
    if (flag == 0)
        cout << "\n\n--> There is euler circuit";
    if (c == 2)
        cout << "\n--> There is a euler path";
    else
        cout << "\n--> There is no euler path";
    cout << endl;
    return 0;
}