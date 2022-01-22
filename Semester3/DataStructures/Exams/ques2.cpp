/*
    2. Find largest element in an array using recursion.
    Written By Anshul Verma (19/78065)
*/

#include <iostream> 
using namespace std; 

// findLargest recursive function
 int findLargest(int arr[], int pos, int largest)
{
    if (pos == 0)
        return largest;
    if (pos > 0) 
    {
        if (arr[pos] > largest)
        {
            largest = arr[pos];
        }
        return findLargest(arr, pos - 1, largest);
    }
    else
        return -1;
}

// Main Function
int main() 
{ 
	int arr[] = {10, 14, 44, 6, -50, 12, 20}; 
    cout << "\n{10, 14, 44, 6, -50, 12, 20}" << endl;
	cout << "Largest -> " << findLargest(arr, 7-1, arr[0]) << "\n\n"; 
	return 0; 
} 
