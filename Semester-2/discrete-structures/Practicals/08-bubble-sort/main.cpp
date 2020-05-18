#include <iostream>
using namespace std;

float elements[50] = {0};

float swap(float ar[], int a, int b)
{
    float temp = ar[a];
    ar[a] = ar[b];
    ar[b] = temp;

    return *ar;
}

float bubbleSort(float ar[], int v)
{
    for (int i = 0; i < (v - 1); i++)
    {
        for (int j = 0; j < (v - i - 1); j++)
        {
            if (ar[j] > ar[j + 1])
            {
                swap(ar, j, j + 1);
            }
        }
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

    display(elements, v);

    cout << endl
         << endl
         << "Sorting the array using Bubble Sort Algorithm...." << endl
         << endl;
    bubbleSort(elements, v);

    cout << "Sorted. Here is the resulting array : " << endl;
    display(elements, v);

    return 0;
}
