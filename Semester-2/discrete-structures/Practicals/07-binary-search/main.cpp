#include <iostream>
using namespace std;

void sort(int arr[], int v)
{
    for (int i = 0; i < (v - 1); i++)
    {
        for (int j = 0; j < (v - i - 1); j++)
        {
            if (arr[j] > arr[j + 1])
            {
                float temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int arr[], int start, int end, int e)
{
    if (end >= 1)
    {
        int mid = (int)start + (end - 1) / 2;
        if (arr[mid] == e)
            return mid;
        if (arr[mid] > e)
            return binarySearch(arr, start, mid - 1, e);
        return binarySearch(arr, mid + 1, end, e);
    }
    return -1;
}

void print(int arr[], int n)
{
    cout << endl
         << " - [ ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "]";
}

int main()
{
    int *arr;
    int n, size;

    cout << endl
         << endl
         << "Enter the size of array : ";
    cin >> size;

    cout << endl
         << "Enter the elements of array : ";
    for (int i = 0; i < size; i++)
    {
        cin >> arr[i];
    }
    cout << endl
         << " - Sorting the array..." << endl;
    sort(arr, size);
    cout << " - Done!";
    print(arr, size);

    cout << endl
         << endl
         << "Enter the integer to be searched : ";
    cin >> n;
    cout << endl
         << " - Searching using Binary Search..." << endl;
    int result = binarySearch(arr, 0, size - 1, n);
    cout << " - Done!" << endl;
    if (result == -1)
        cout << endl
             << "--> Element is not present in the array.";
    else
        cout << endl
             << "--> Element is present in the array at index " << result << endl
             << endl;

    return 0;
}