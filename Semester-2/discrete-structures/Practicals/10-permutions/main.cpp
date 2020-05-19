#include <iostream>
using namespace std;

void printArray(int *ar, int v)
{
    cout << " {";
    for (int i = 0; i < v; i++)
    {
        if (i == 0)
            cout << ar[i];
        else
            cout << "," << ar[i];
        ;
    }
    cout << "}";
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permutation(int *arr, int n, int curr_i, int *permut_arr, int permut_i)
{
    if (curr_i >= n)
    {
        printArray(permut_arr, permut_i);
    }
    for (int i = curr_i; i < n; i++)
    {
        swap(arr[curr_i], arr[i]);
        permut_arr[permut_i] = arr[curr_i];
        permutation(arr, n, curr_i + 1, permut_arr, permut_i + 1);
        swap(arr[curr_i], arr[i]);
    }
}

int main()
{
    int *arr, pArr[100];
    int size;

    cout << endl
         << endl
         << "Enter the no. of digits : ";
    cin >> size;

    cout << endl
         << "Enter the digits : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl
         << "--> Given set of digits :";
    printArray(arr, size);
    cout << endl
         << endl
         << "--> All possible permutations of digits :";
    permutation(arr, size, 0, pArr, 0);
    cout << endl
         << endl;

    return 0;
}