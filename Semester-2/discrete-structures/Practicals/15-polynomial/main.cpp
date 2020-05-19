#include <iostream>
#include <math.h>
using namespace std;

void printPoly(int *poly, int n)
{
    cout << endl
         << "Given polynomial, f(x) = ";
    for (int i = n; i >= 0; i--)
    {
        if (!poly[i] == 0)
        {
            if (i == n)
                cout << poly[i] << "x^" << i;
            else
            {
                if (poly[i] >= 0)
                    cout << " + ";
                else
                    cout << " ";
                if (!i == 0)
                    cout << poly[i] << "x^" << i;
                else
                    cout << poly[i];
            }
        }
    }
}
float evaluatePoly(int *poly, int n, int x)
{
    float total;
    for (int i = n; i >= 0; i--)
    {
        total += poly[i] * pow(x, i);
    }
    return total;
}

int main()
{
    int *polynomial, deg, x;
    cout << endl
         << "Enter the degree of polynomial : ";
    cin >> deg;
    polynomial[deg] = {0};
    for (int i = deg; i >= 0; i--)
    {
        if (i == 0)
            cout << "Enter the constant term : ";
        else
            cout << "Enter the coefficient of x^" << i << " : ";
        cin >> polynomial[i];
    }
    printPoly(polynomial, deg);
    cout << endl
         << endl
         << "Enter the value of x for which the polynomial is to be evaluated : ";
    cin >> x;

    cout << endl
         << "--> f(" << x << ") : " << evaluatePoly(polynomial, deg, x);
    cout << endl
         << endl;

    return 0;
}