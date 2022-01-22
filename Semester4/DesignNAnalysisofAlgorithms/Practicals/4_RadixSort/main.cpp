/*
    Written by Anshul Verma (19/78065) for University of Delhi
    Lab Work for Design and Analysis of Algorithms
*/

#include <iostream>
#include <string>
#include <sys/time.h>

using namespace std;

// Print array function
void print(int ar[], int size, string str) {
  cout << str << "[";
  for (int i = 0; i < size; ++i) {
    cout << (i == 0 ? "" : ", ") << ar[i];
  }
  cout << "]" << endl;
}

// Counting Sort function on ith digit
void countingSort(int arr[], int size, int k)
{
  // 1) Let C be an array for storing counts of size 10
  // and output as sorted array of size 'size'
  int output[size];
  int C[10];

  // 2) Initialising each element of C to 0
  for (int i = 0; i < 10; ++i)
    C[i] = 0;

  // 3) Calculate number of elements equal to i 
  // for each element in arr
  for (int i = 0; i < size; i++)
    C[(arr[i] / k) % 10]++;

  // 3) Calculate number of elements less than or
  // equal to i for each element in arr
  for (int i = 1; i < 10; i++)
    C[i] += C[i - 1];

  // 4) Placing the elements in sorted order
  for (int i = size - 1; i >= 0; i--) {
    output[C[(arr[i]/k) % 10] - 1] = arr[i];
    C[(arr[i]/k) % 10]--;
  }

  // 5) Placing sorted elements to 'arr' from 'output'
  for (int i = 0; i < size; i++)
    arr[i] = output[i];
}

// Radix Sort Function
void radixSort(int arr[], int size)
{
  // 1) Get maximum element to determine maximum digits
  int max = arr[0];
  for (int i = 1; i < size; i++)
    if (arr[i] > max)
      max = arr[i];

  // 2) Applying a stable sorting algorithm (counting sort)
  // on ith digit 
  for (int i=1; max/i > 0; i *= 10)
  {
    countingSort(arr, size, i);
    cout << "  Array sorted on the basis of " << i 
	<< (i == 1 ? "st" : "th") << " digit from left:\n";
    print(arr, size, "    ");
  }
}

// Main Driver Function
int main(){
  // Initialize srand 
  srand(time(0));

  // Number of iterations
  int N = 10;

  for(int i = 0; i < N; i++)
  {
    // Taking a random size ranging from 5 to 20
    int size = rand()%15 + 5;
    int *arr = new int[size];
		
    // Initializing array with random values
    // between 0 and 999
    for(int j = 0; j < size; j++)
    {
      arr[j] = rand()%999;
    }
    cout << "Iteration " << i+1 << ":";
    cout << "\n------------------------------------\n";
    print(arr, size, "\nUnsorted Array = ");
    cout << "\nApplying Radix Sort Algorithm:\n";
    radixSort(arr, size);
    print(arr, size, "\nSorted Array = ");
    cout << endl;
  }

  return 0;
}
