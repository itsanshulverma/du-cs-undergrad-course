# Heap Sort
*Written by Anshul Verma(19/78065)*
<br />

***Objective*** - Implement Heap Sort(The program should report the number of comparisons). 
<br />
Test run the algorithm on 100 different inputs of sizes varying
from 30 to 1000. Count the number of comparisons and draw the graph. Compare it with a graph
of nlogn.
<br />

***Code*** -
<br />
***For full code, [please click here](https://github.com/itsanshulverma/algo-lab/blob/main/2_HeapSort/main.cpp).***

```cpp
...
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
...
```
*Main Driver Function*
```cpp

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
```

***Sample Output*** -
```

------------------------------------
Array 1:
No. of elements: 355
No. of comparisons: 2909

------------------------------------
Array 2:
No. of elements: 461
No. of comparisons: 3911

------------------------------------
Array 3:
No. of elements: 52
No. of comparisons: 276

------------------------------------
.....
.....
.....
Array 97:
No. of elements: 42
No. of comparisons: 214

------------------------------------
Array 98:
No. of elements: 385
No. of comparisons: 3176

------------------------------------
Array 99:
No. of elements: 377
No. of comparisons: 3125

------------------------------------
Array 100:
No. of elements: 942
No. of comparisons: 8940

```

***Plots*** -

- **Plot of Heap Sort**

<img alt="Plot of Heap Sort (Size vs #Comparisons)" src="https://github.com/itsanshulverma/algo-lab/blob/main/2_HeapSort/plot.png" width="720px" />

- **Plot of Heap Sort compared with plot of nlogn**

<img alt="Plot comparison of Heap Sort and nlogn" src="https://github.com/itsanshulverma/algo-lab/blob/main/2_HeapSort/plot_compare_nlogn.png" width="720px" />
