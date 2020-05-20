#include <iostream>
using namespace std;

int main()
{
    int r;
    int x[4], y[4], con[4], dis[4], xOR[4], cond[4], bicond[4], nand[4], nor[4], nx[4], ny[4];
    cout << "\nEnter the number of propositions i.e. rows : ";
    cin >> r;
    cout << "\nEnter the truth values of x and y (T=1,F=0) : \n";
    for (int i = 0; i < r; i++)
    {
        cout << "--> " << i + 1 << ". ";
        cin >> x[i] >> y[i];
        con[i] = x[i] & y[i];
        dis[i] = x[i] | y[i];
        xOR[i] = (x[i] & (!y[i])) | (y[i] & (!x[i]));
        cond[i] = (!x[i]) | y[i];
        bicond[i] = (x[i] & y[i]) | ((!x[i]) & (!y[i]));
        nand[i] = !con[i];
        nor[i] = !dis[i];
        nx[i] = !x[i];
        ny[i] = !y[i];
    }
    cout << "\n    (x,y) | Conjunction | Disjunction | XOR | Conditional | Biconditional | NAND | NOR | Negation(x) | Negation(y)\n";
    for (int i = 0; i < r; i++)
    {
        cout << "\n--> (" << x[i] << "," << y[i] << ") |      "
             << con[i] << "      |      "
             << dis[i] << "      |  "
             << xOR[i] << "  |      "
             << cond[i] << "      |       "
             << bicond[i] << "       |  "
             << nand[i] << "   |  "
             << nor[i] << "  |      "
             << nx[i] << "      |      " << ny[i];
    }
    cout << endl;

    return 0;
}