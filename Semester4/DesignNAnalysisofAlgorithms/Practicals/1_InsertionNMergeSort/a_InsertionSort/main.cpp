/*
    Written by Anshul Verma (19/78065) for University of Delhi
    Lab Work for Design and Analysis of Algorithms
*/

#include <iostream>
#include <fstream>
#include <sys/time.h>

// Insertion Sort Function
template <typename T>
int insertionSort(T arr[], int size)
{
	T key;
	int i, j, comp=-1;
	for (i = 0; i < size; ++i)
	{
		key = arr[i];
		j = i - 1;
		
		while (j >= 0 && arr[j] > key)
		{
            comp++;
            arr[j+1] = arr[j];
            j--;
		}
        comp++;
		arr[j+1] = key;
	}
    return comp; // Returns no. of comparisons
}

int main()
{
    // Initialize srand 
    srand(time(0));

    // Defining variables
    struct timeval begin, end;
    int n = 100;

    // Opening and initializing file
    std::ofstream outputFile("plot_data.csv");
    outputFile << "arr_size,n_comps";

    for(int i = 0; i < n; i++)
    {
        // Taking a random size
        int size = rand()%10000;
        int *arr = new int[size];

        // Initializing array with random values
        for(int j = 0; j < size; j++)
        {
            arr[j] = rand()%1000000;
        }

        std::cout << "\n------------------------------------\n";
        std::cout << "Array " << i+1 << ": \n";

        // Get the time at begin
        gettimeofday(&begin, 0);

        // Applying insertion sort
        int comp = insertionSort<int>(arr, size);

        // Get the time of begin
        gettimeofday(&end, 0);

        // Calculating elapsed time
        long seconds = end.tv_sec - begin.tv_sec;
        long microseconds = end.tv_usec - begin.tv_usec;
        double elapsed = seconds + microseconds*1e-6;

        // Printing the results
        std::cout << "No. of elements: " << size << std::endl;
        std::cout << "No. of comparisons: " << comp << std::endl;
        std::cout << "Time Elapsed: " << elapsed << std::endl;

        // Saving data to file
        outputFile << "\n" << size << "," << comp;
    }
    outputFile.close(); // Close the file
    std::cout << std::endl;
    return 0;
}