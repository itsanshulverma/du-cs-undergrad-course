#include <iostream>
#include <math.h>
using namespace std;

int Ta(int n)
{
    if (n == 0)
        return 1;
    else
        return (n + Ta(n - 1));
}
int Tb(int n)
{
    if (n == 0)
        return 1;
    else
        return (pow(n, 2) + Tb(n - 1));
}
int Tc(int n)
{

    if (n == 0)
        return 1;
    else
        return (n + (2 * Tc(n / 2)));
}

int main()
{
    int n;
    cout << "\nEnter thr value of n : ";
    cin >> n;
    cout << "\n--> for n=" << n << " : \n";
    cout << "\n--> 1. T(n) = T(n-1) + n, T(0) = 1 ==> " << Ta(n);
    cout << "\n--> 1. T(n) = T(n-1) + n^2, T(0) = 1 ==> " << Tb(n);
    cout << "\n--> 1. T(n) = 2*T(n/2) + n, T(0) = 1 ==> " << Tc(n);
    cout << endl;

    return 0;
}