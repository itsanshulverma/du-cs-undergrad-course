#include <iostream>
using namespace std;

int calcLeafNodes(int m, int i)
{
    return i * (m - 1) + 1;
}

int main()
{
    int m, i;
    cout << endl
         << endl
         << "Enter the degree of tree : ";
    cin >> m;
    cout << "Enter the number of internal nodes : ";
    cin >> i;
    cout << endl
         << "--> Number of leaf nodes : " << calcLeafNodes(m, i) << endl
         << endl;
    return 0;
}