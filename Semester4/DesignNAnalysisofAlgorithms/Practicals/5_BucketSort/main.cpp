/*
    Written by Anshul Verma (19/78065) for University of Delhi
    Lab Work for Design and Analysis of Algorithms
*/

#include <iostream>
#include <string>
#include <sys/time.h>

using namespace std;

// Declaration of required functions
template <typename T> void insertionSort(T[], int);
void print(float[], int, string);

// Bucket stuct
struct bucket 
{
  int ptr;
  float* value;
};

// Bucket Sort Function
void bucketSort(float ar[], int n)
{
  // 1) let B[0..n-1] be a new array of buckets
  struct bucket B[n];

  // 2) Create n empty buckets of size n
  for (int i=0; i < n; i++)
  {
    B[i].ptr = -1;
    B[i].value = new float[n];
  }

  // 3) Put ar elements in suitable buckets
  for (int i=0; i<n; i++) 
  {
    int idx = n * ar[i];
    B[idx].value[++B[idx].ptr] = ar[i];
  }

  // 4) Sort and print each bucket using insertion sort
  for (int i=0; i<n; i++)
  {
    insertionSort<float>(B[i].value, B[i].ptr+1);
    cout << "  Bucket " << i;
    print(B[i].value, B[i].ptr+1, " = ");
  }

  // 5) Concatenate all buckets together to ar in order
  int idx = 0;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < B[i].ptr+1; j++)
      ar[idx++] = B[i].value[j];
	delete[] B[i].value; // and free the memory
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
    float *arr = new float[size];
		
    // Initializing array with random values
    // between 0 and 1 with 2 digits after decimal
    for(int j = 0; j < size; j++)
    {
      arr[j] = (float) (rand()%100)/100;
    }
    cout << "Iteration " << i+1 << ":";
    cout << "\n------------------------------------\n";
    print(arr, size, "\nUnsorted Array = ");
    cout << "\nApplying Bucket Sort Algorithm:\n\n";
    bucketSort(arr, size);
    print(arr, size, "\nSorted Array = ");
    cout << endl;
  }

  return 0;
}
// Definition of Insertion Sort Function
template <typename T>
void insertionSort(T arr[], int size)
{
  T key;
  int i, j;
  for (i = 0; i < size; ++i)
  {
    key = arr[i];
    j = i - 1;
		
    while (j >= 0 && arr[j] > key)
    {
      arr[j+1] = arr[j];
      j--;
    }
    arr[j+1] = key;
  }
}

// Definition of Print array function
void print(float ar[], int size, string str) {
  cout << str << "[";
  for (int i = 0; i < size; ++i) {
    cout << (i == 0 ? "" : ", ") << ar[i];
  }
  cout << "]" << endl;
}
