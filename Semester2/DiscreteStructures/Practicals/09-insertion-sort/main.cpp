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

int insertionSort(int *ar, int v)
{
    int i, j, key, totalCount = 0, count = 0;
    for (i = 1; i < v; i++)
    {
        key = ar[i];
        j = i - 1;
        count = 0;
        while (j >= 0 && key < ar[j])
        {
            ++count;
            swap(ar, j, j + 1);
            j = j - 1;
        }
        totalCount += count;
        display(ar, v);
        cout << " -> " << (count) << " comparisons" << endl;
        ar[j + 1] = key;
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
         << " - Sorting the array using Insertion Sort Algorithm...." << endl
         << endl;
    comparisons = insertionSort(arr, size);

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