#include <iostream>

using namespace std;

int fib_at(int n)
{
    if (n == 0 || n == 1)
    {
        return n;
    }
    return fib_at(n - 2) + fib_at(n - 1);
}

int main()
{
    int n;
    cout << endl
         << endl
         << "Enter the size of Fibonacci series : ";
    cin >> n;
    cout << endl
         << "--> Fibonacci series (0-" << n << ") : ";
    for (int i = 0; i < n; i++)
    {
        cout << fib_at(i) << " ";
    }
    cout << endl
         << endl;

    return 0;
}