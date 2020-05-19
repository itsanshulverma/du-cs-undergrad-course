#include <iostream>
using namespace std;

int nCr(int n, int r)
{
    if (r > n)
        return -1;
    else if (n == 0 || r == 0 || n == r)
        return 1;
    else
        return (nCr(n - 1, r - 1) + nCr(n - 1, r));
}
void printEq(int n, int c)
{
    cout << "\nGiven equation : ";
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            cout << "x" << i + 1;
        else if (i == n - 1)
            cout << " + x" << i + 1 << " = " << c;
        else
            cout << " + x" << i + 1;
    }
    cout << endl;
}

int main()
{
    int n, c;
    cout << "\nEnter the no of variables (n) : ";
    cin >> n;
    cout << "\nEnter the value of total sum i.e. c <=10 : ";
    cin >> c;
    printEq(n, c);
    cout << "\n--> Number of possible solutions of this eq. is " << nCr(n + c - 1, c) << "\n";

    return 0;
}