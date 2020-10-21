/*
	by Anshul Verma
*/

#include <iostream>
using namespace std;

// Max Heapify function
void max_heapify(int arr[], int i, int size)
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

/*
	Build Heap function - iterating over all the non leaf nodes and applying max_heapify
*/
void buildHeap(int arr[], int size)
{
	for (int i = size / 2; i >= 1; --i)
		max_heapify(arr, i, size);
}

/*
	Heap Sort function - iterates (size-1) times, swap max element (root) and last element and then applying max_heapify on root element (and decrease size by 1)
*/
void heapSort(int arr[], int size)
{
	buildHeap(arr, size);
	while(size >= 1)
	{
		swap(arr[1], arr[size]);
		size--;
		max_heapify(arr, 1, size);
	}
}

/*
	Main Function
*/
int main()
{
	int *arr, size;
	cout << "\nHeap Sort Implementation\n--------------------------\n";
	cout << "\nEnter size of array: ";
	cin >> size;
	arr = new int[size];
	cout << "Enter the elements: ";
	for (int i = 1; i <= size; ++i)
		cin >> arr[i];

	cout << "\nApplying heap sort...";
	heapSort(arr, size);
	cout << "\nSorted array: ";
	for (int i = 1; i <= size; ++i)
		cout << arr[i] << " ";
	cout << endl;
}