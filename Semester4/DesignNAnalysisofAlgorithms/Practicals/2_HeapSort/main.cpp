/*
    Written by Anshul Verma (19/78065) for University of Delhi
    Lab Work for Design and Analysis of Algorithms
*/

#include <iostream>
#include <fstream>
#include <sys/time.h>
using namespace std;

// Max Heapify function
int max_heapify(int arr[], int i, int size)
{
  int count = 0; // comparison counter
	int maxIndex = i;
	int l = 2 * i + 1; // left child
	int r = 2 * i + 2; // right child

  // Comparisons with left child
	if (l < size && arr[l] > arr[maxIndex])
		maxIndex = l;
  // Comparisons with left child
	if (r < size && arr[r] > arr[maxIndex])
		maxIndex = r;
  
  // Main logic
	if (i != maxIndex)
	{
	  count++;
		swap(arr[i], arr[maxIndex]);
		count += max_heapify(arr, maxIndex, size);
	}
	return count;
}

/*
	Build Heap function - iterating over all the 
	non leaf nodes and applying max_heapify
*/
int buildMaxHeap(int arr[], int size)
{
  int count = 0;
	for (int i = size / 2-1; i >= 0; --i)
		count += max_heapify(arr, i, size) + 1;
	return count;
}

/*
	Heap Sort function - iterates (size-1) times, 
	swap max element (root) and last element and then 
	applying max_heapify on root element (and decrease size by 1)
*/
int heapSort(int arr[], int size)
{
	int count = buildMaxHeap(arr, size);
  for (int i = size - 1; i > 0; i--) {
    swap(arr[0], arr[i]);
    count += max_heapify(arr, 0, i) + 1;
  }
  return count;
} 

int main()
{
  // Initialize srand 
  srand(time(0));

  // Number of iterations
  int n = 100;

  // Opening and initializing file
  ofstream outputFile("plot_data.csv");
  outputFile << "arr_size,n_comps";

  for(int i = 0; i < n; i++)
  {
    // Taking a random size ranging from 30 to 1000
    int size = rand()%970 + 30;
    int *arr = new int[size];

    // Initializing array with random values
    for(int j = 0; j < size; j++)
    {
      arr[j] = rand()%1000000;
    }
    cout << "\n------------------------------------\n";
    cout << "Array " << i+1 << ": \n";

    // Initializing comps and applying heap sort
    int comps = heapSort(arr, size);

    // Printing the results
    cout << "No. of elements: " << size << endl;
    cout << "No. of comparisons: " << comps << endl;

    // Saving data to file
    outputFile << "\n" << size << "," << comps;
  }

  outputFile.close(); // Close the file
  cout << endl;
  return 0;
}