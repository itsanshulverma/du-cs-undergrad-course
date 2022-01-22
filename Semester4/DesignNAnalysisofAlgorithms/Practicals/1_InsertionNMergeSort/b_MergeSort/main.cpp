/*
    Written by Anshul Verma (19/78065) for University of Delhi
    Lab Work for Design and Analysis of Algorithms
*/

#include <iostream>
#include <fstream>
#include <sys/time.h>
using namespace std;

// Comparison counter
int comps;

// Merge function to merge two subarrays into arr
void merge(int arr[], int left, int mid, int right) {
 
  // Create L <- arr[left:mid] and M <- arr[mid+1:right]
  int n1 = mid - left + 1;
  int n2 = right - mid;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
      L[i] = arr[left + i];
  for (int j = 0; j < n2; j++)
      M[j] = arr[mid + 1 + j];

  // Current indices of subarrays and arr
  int i = 0, j = 0, k = left;

  /**
    Iterate over elements of L and M and pick larger element from L and M
    until we reach end of either array, add the elements to correct position in arr
  **/
  while (i < n1 && j < n2) {
      if (L[i] <= M[j]) {
          arr[k] = L[i];
          i++;
      } else {
          arr[k] = M[j];
          j++;
      }
      comps++; // Increment comparison counter
      k++;
  }

  // Put remaining elements in arr
  while (i < n1) {
      arr[k] = L[i];
      i++;
      k++;
  }
  while (j < n2) {
      arr[k] = M[j];
      j++;
      k++;
  }
}

// Merge Sort function
void mergeSort(int arr[], int left, int right) {
  if (left < right) {
    // Finding mid of array
    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);

    // Merge the sorted subarrays
    merge(arr, left, mid, right);
  }
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

  for(int i = 0; i <= n; i++)
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

      // Initializing comps and applying merge sort
      comps = 0;
      mergeSort(arr, 0, size - 1);

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