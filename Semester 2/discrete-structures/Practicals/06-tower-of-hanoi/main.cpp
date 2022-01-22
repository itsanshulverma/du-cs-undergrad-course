#include <iostream>

using namespace std;

// total moves
int TOH(int n)
{
    if (n == 1)
        return 1;
    return (2 * TOH(n - 1) + 1);
}

// n = no. of disks
// source_t = source tower
// dest_t = destination tower
// spare_t = spare tower
void TOH_showmoves(int n, char source_t, char dest_t, char spare_t)
{
    //Base Case
    if (n == 1)
    {
        cout << endl
             << " - Move disk 1 of tower " << source_t << " --> tower " << dest_t;
        return;
    }
    //Step 1
    TOH_showmoves(n - 1, source_t, spare_t, dest_t);
    //Step 2
    cout << endl
         << " - Move disk " << n << " of tower " << source_t << " --> tower " << dest_t;
    //Step 3
    TOH_showmoves(n - 1, spare_t, dest_t, source_t);
}

int main()
{
    int n;
    cout << endl
         << endl
         << "Enter number of disks : ";
    cin >> n;
    cout << endl
         << "Let the towers are A, B and C and we are required to move the disks from A to C." << endl;
    TOH_showmoves(n, 'A', 'C', 'B');
    cout << endl
         << endl
         << "--> Total number of moves : " << TOH(n) << endl
         << endl;

    return 0;
}