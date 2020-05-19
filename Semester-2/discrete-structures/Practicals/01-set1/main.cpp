#include <iostream>
#include <math.h>
using namespace std;

void arraytoSet(int *arr, int *n)
{
    if (*n == 0 || *n == 1)
        return;

    for (int i = 0; i < *n; i++)
    {
        for (int j = i + 1; j < *n; j++)
        {
            if (arr[i] == arr[j])
            {
                for (int k = j + 1; k < *n; k++)
                {
                    arr[j] = arr[k];
                    j++;
                }
                *n = *n - 1;
                j--;
            }
        }
    }
}
void print(int *arr, int n)
{
    cout << "{";
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
            cout << arr[i];
        else
            cout << "," << arr[i];
    }
    cout << "} ";
}
bool ismember(int a, int *arr, int *n)
{
    for (int i = 0; i < *n; i++)
    {
        if (a == arr[i])
        {
            return true;
            break;
        }
    }
    return false;
}

/*  Helper recursive function for powerset function
    set = initial set
    n = initial set
    set_i = counter for initial set
    power_set = power set in which subsets will be stored
    powerset_i = current index for power set 
*/
void helper_powerset(int *set, int n, int set_i, int *power_set, int powerset_i)
{
    //Check for terminating recursion
    if (set_i >= n)
    {
        print(power_set, powerset_i);
        return;
    }
    //Exclude
    helper_powerset(set, n, set_i + 1, power_set, powerset_i);
    power_set[powerset_i] = set[set_i];
    //Include
    helper_powerset(set, n, set_i + 1, power_set, powerset_i + 1);
}
void powerset(int *arr, int n)
{
    int power_set[(int)pow(2, n)];
    cout << "{ ";
    helper_powerset(arr, n, 0, power_set, 0);
    cout << "}" << endl
         << endl
         << endl;
}
int main()
{
    int *A;
    int n;

    cout << endl
         << endl
         << endl
         << "Enter the size of array : ";
    cin >> n;
    cout << "Enter the array elements : ";
    for (int i = 0; i < n; i++)
    {
        cin >> A[i];
    }

    arraytoSet(A, &n);

    cout << endl
         << "Given set A : ";
    print(A, n);
    cout << endl
         << endl
         << "Cardinality of set A : " << n << endl;
    cout << endl
         << "Let a = 2, then" << endl;
    int a = 2;
    cout << "ismember(" << a << ", A) : ";
    if (ismember(a, A, &n) == 1)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << endl
         << "powerset(A) : ";
    powerset(A, n);
    return 0;
}