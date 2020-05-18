#include <iostream>
using namespace std;

float elements[50] = {0};

float insertionSort(float ar[], int v)
{
    for (int i = 0; i < (v - 1); i++)
    {
        float temp = ar[i];
        int j = i - 1;
        while (j >= 0 && temp < ar[j])
        {
            ar[j + 1] = ar[j];
            j = j - 1;
        }
        ar[j + 1] = temp;
    }

    return *ar;
}

void display(float ar[], int v)
{
    cout << "[ ";
    for (int i = 0; i < v; i++)
    {
        cout << ar[i] << " ";
    }
    cout << "]";
}

int main()
{
    int v;
    float e;

    cout << "Enter the total number of elements : ";
    cin >> v;

    cout << "Enter the elements(integers/floats) : ";
    for (int i = 0; i < v; i++)
    {
        cin >> e;
        elements[i] = e;
    }

    insertionSort(elements, v);

    cout << endl
         << endl
         << "Sorting the array using Insertion Sort Algorithm...." << endl
         << endl;
    insertionSort(elements, v);

    cout << "Sorted. Here is the resulting array : " << endl;
    display(elements, v);

    return 0;
}