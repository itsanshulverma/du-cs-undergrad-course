# Quick Sort
*Written by Anshul Verma(19/78065)*
<br />

***Objective*** - Implement Randomised Quick Sort(The program should report the number of comparisons). 
<br />
Test run the algorithm on 100 different inputs of sizes varying
from 30 to 1000. Count the number of comparisons and draw the graph. Compare it with a graph
of nlogn.
<br />

***Code*** -
<br />
***For full code, [please click here](https://github.com/itsanshulverma/algo-lab/blob/main/3_QuickSort/main.cpp).***

```cpp
...
// Comparison Counter
int comps;

// Function to make partitions of array
// according to a pivot
int partition(int array[], int low, int high) {
  // Select the pivot element
  int pivot = array[high];
  int i = (low - 1);

  // Put the elements smaller than pivot on the left 
  // and greater than pivot on the right of pivot
  for (int j = low; j < high; j++) {
    if (array[j] <= pivot) {
      i++;
      swap(array[i], array[j]);
      comps++; // Comparison + 1
    }
  }
  swap(array[i + 1], array[high]);
  return (i + 1);
}

// Function to generate random pivot, and then
// call partition on that pivot
int randomPartition(int arr[], int low, int high)
{
  int random = low + rand() % (high - low);
  swap(arr[random], arr[high]);
 
  return partition(arr, low, high);
}

// Quick Sort function
void quickSort(int array[], int low, int high) {
  if (low < high) {
    // Make partition based on random pivot
    int pi = randomPartition(array, low, high);

    // Sort the elements on the left of pivot
    quickSort(array, low, pi - 1);

    // Sort the elements on the right of pivot
    quickSort(array, pi + 1, high);
  }
}
...
```
*Main Driver Function*
```cpp

int main() {
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
      arr[j] = rand()%10000;
    }
    cout << "\n------------------------------------\n";
    cout << "Array " << i+1 << ": \n";

    // Initializing comps and applying Quick sort algorithm
    comps = 0;
    quickSort(arr, 0, size);

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
No. of elements: 420
No. of comparisons: 1884

------------------------------------
Array 2:
No. of elements: 103
No. of comparisons: 315

------------------------------------
Array 3:
No. of elements: 715
No. of comparisons: 4308

.....
.....
.....

------------------------------------
Array 98:
No. of elements: 347
No. of comparisons: 1347

------------------------------------
Array 99:
No. of elements: 376
No. of comparisons: 1537

------------------------------------
Array 100:
No. of elements: 719
No. of comparisons: 4688

```

***Plots*** -

- **Plot of Quick Sort Comparisons**

<img alt="Plot of Heap Sort (Size vs #Comparisons)" src="https://github.com/itsanshulverma/algo-lab/blob/main/3_QuickSort/plot.png" width="720px" />

- **Plot of Quick Sort compared with plot of nlogn**

<img alt="Plot comparison of Heap Sort and nlogn" src="https://github.com/itsanshulverma/algo-lab/blob/main/3_QuickSort/plot_compare_nlogn.png" width="720px" />
