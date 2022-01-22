# Insertion Sort
*Written by Anshul Verma(19/78065)*
<br />

***Objective*** - Implement Insertion Sort (The program should report the number of comparisons)
<br />

***Code*** -
<br />
*This is only the Insertion Sort function.* ***For full code, [click here](https://github.com/itsanshulverma/algo-lab/blob/main/1_InsertionNMergeSort/a_InsertionSort/main.cpp).***
```cpp
...
// Insertion Sort Function
template <typename  T>
int  insertionSort(T  arr[], int  size)
{
	T  key;
	int  i, j, comp=-1;

	// Iterate though each element
	for (i = 0; i < size; ++i)
	{
		key = arr[i];	
		j = i - 1;
		
		// Compare with previous elements
		while (j >= 0 && arr[j] > key)
		{
			comp++;
			arr[j+1] = arr[j];
			j--;
		}
		comp++;
		arr[j+1] = key; //Swapping
	}
	return  comp; // Returns no. of comparisons
}
...
```

***Sample Output*** -
```

------------------------------------
Array 1:
No. of elements: 1038
No. of comparisons: 270635
Time Elapsed: 0.008909

------------------------------------
Array 2:
No. of elements: 5439
No. of comparisons: 7482475
Time Elapsed: 0.016955

------------------------------------
Array 3:
No. of elements: 4369
No. of comparisons: 4745971
Time Elapsed: 0.010971

------------------------------------
Array 4:
No. of elements: 6792
No. of comparisons: 11502865
Time Elapsed: 0.024971

------------------------------------
Array 5:
No. of elements: 2036
No. of comparisons: 1044582
Time Elapsed: 0.00303

------------------------------------
Array 6:
No. of elements: 6985
No. of comparisons: 12026698
Time Elapsed: 0.025966

------------------------------------
Array 7:
No. of elements: 9208
No. of comparisons: 21247679
Time Elapsed: 0.047913

------------------------------------
Array 8:
No. of elements: 7583
No. of comparisons: 14441177
Time Elapsed: 0.031948
...
...
...
Array 95:
No. of elements: 2816
No. of comparisons: 1980669
Time Elapsed: 0.004987

------------------------------------
Array 96:
No. of elements: 5889
No. of comparisons: 8587635
Time Elapsed: 0.018978

------------------------------------
Array 97:
No. of elements: 426
No. of comparisons: 45144
Time Elapsed: 0.000995

------------------------------------
Array 98:
No. of elements: 6881
No. of comparisons: 11946915
Time Elapsed: 0.039205

------------------------------------
Array 99:
No. of elements: 9592
No. of comparisons: 23159375
Time Elapsed: 0.026964

------------------------------------
Array 100:
No. of elements: 946
No. of comparisons: 216313
Time Elapsed: 0.003995
```

***Plot*** -

<img alt="Plot of Insertion Sort (Size vs #Comparisons)" src="https://github.com/itsanshulverma/algo-lab/blob/main/1_InsertionNMergeSort/a_InsertionSort/plot.png" width="720px" />
