#include <iostream>
using namespace std;

void display(int ar[], int v)
{
    cout << " - [ ";
    for (int i = 0; i < v; i++)
    {
        cout << ar[i] << " ";
    }
    cout << "]";
}

int swap(int *ar, int a, int b)
{
    int temp = ar[a];
    ar[a] = ar[b];
    ar[b] = temp;

    return *ar;
}

int bubbleSort(int *ar, int v)
{
    int totalCount = 0, count;
    for (int i = 0; i < (v - 1); i++)
    {
        count = 0;
        for (int j = 0; j < (v - i - 1); j++)
        {
            if (ar[j] > ar[j + 1])
            {
                ++count;
                swap(ar, j, j + 1);
            }
            else
                ++count;
        }
        totalCount += count;
        display(ar, v);
        cout << " -> " << (count) << " comparisons" << endl;
    }
    return totalCount;
}

int main()
{
    int *arr;
    int size, comparisons;

    cout << endl
         << endl
         << "Enter the size of array : ";
    cin >> size;

    cout << endl
         << "Enter the elements of the array : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl;

    display(arr, size);

    cout << endl
         << endl
         << " - Sorting the array using Bubble Sort Algorithm...." << endl
         << endl;
    comparisons = bubbleSort(arr, size);

    cout << endl
         << "--> Sorted. Here is the resulting array";
    display(arr, size);
    cout << endl
         << endl
         << "--> Total no. of comparisons : " << comparisons;
    cout << endl
         << endl;

    return 0;
}
