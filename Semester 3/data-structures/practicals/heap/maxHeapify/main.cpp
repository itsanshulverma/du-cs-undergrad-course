/*
	by Anshul Verma
*/

#include <iostream>
using namespace std;

// Max Heapify
void max_heapify(int *arr, int i, int size)
{
	int maxIndex = i;
	int l = 2 * i;	 // left child
	int r = 2 * i + 1; // right child
	if (l <= size && arr[l] > arr[maxIndex])
		maxIndex = l;
	if (r <= size && arr[r] > arr[maxIndex])
		maxIndex = r;
	if (i != maxIndex)
	{
		swap(arr[i], arr[maxIndex]);
		max_heapify(arr, maxIndex, size);
	}
}

int main()
{
	int *arr, size, index;
	cout << "\nEnter size of array: ";
	cin >> size;
	arr = new int[size];
	cout << "Enter the elements: ";
	for (int i = 1; i <= size; ++i)
		cin >> arr[i];
	cout << "Enter an index to apply max heapify: ";
	cin >> index;

	cout << "\nApplying max heapify at " << index << "...";
	max_heapify(arr, index, size);

	cout << "\nResultant array: ";
	for (int i = 1; i <= size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}