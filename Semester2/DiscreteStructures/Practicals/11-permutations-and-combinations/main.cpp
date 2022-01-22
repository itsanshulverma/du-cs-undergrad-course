#include <iostream>
using namespace std;

int nPr(int n, int r)
{
    if (r > n)
        return -1;
    else if (r == 0)
        return 1;
    else
        return (n * nPr(n - 1, r - 1));
}
int nCr(int n, int r)
{
    if (r > n)
        return -1;
    else if (n == 0 || r == 0 || n == r)
        return 1;
    else
        return (nCr(n - 1, r - 1) + nCr(n - 1, r));
}

int main()
{
    int n, r, p, c;
    cout << endl
         << endl
         << "Enter the value of n : ";
    cin >> n;
    cout << "Enter the value of r : ";
    cin >> r;
    p = nPr(n, r);
    c = nCr(n, r);

    cout << endl
         << "--> Given : n=" << n << ", r=" << r << endl;
    if (p == -1 || c == -1)
        cout
            << endl
            << "--> Invalid input!" << endl
            << endl;
    else
    {
        cout << endl
             << "--> Permutations (nPr) : " << p << endl;
        cout << endl
             << "--> Combinations (nCr) : " << c << endl
             << endl;
    }

    return 0;
}