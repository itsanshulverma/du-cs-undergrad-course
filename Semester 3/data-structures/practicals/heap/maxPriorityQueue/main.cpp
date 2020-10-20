/*
	Written by Anshul Verma
*/

#include <iostream>
using namespace std;

#define MAX_SIZE 15

/*
	MaxPriorityQueue class
*/
class MaxPriorityQueue
{
	public:
	int *arr, size;
	MaxPriorityQueue() 
	{ 
		arr = new int[MAX_SIZE]; 
		size = 0;
	}
	MaxPriorityQueue(int size)
	{
		arr = new int[size]; 
		size = 0;
	}
	
	/*
		Function to check for parent and swap if parent is less (iterating from current to top)
	*/
	void shiftUp(int i)
	{
		while (i > 1 && arr[i / 2] < arr[i])
		{
			swap(arr[i / 2], arr[i]);
			i = i / 2;
		}
	}
	
	/*
		Function to check for child (biggest out of left and right) and swap if it is greater (iterating from current to bottom)
	*/
	void shiftDown(int i)
	{
		int maxIndex = i;
		int l = 2 * i;
		int r = 2 * i + 1;
		if (l <= size && arr[l] > arr[maxIndex])
			maxIndex = l;
		if (r <= size && arr[r] > arr[maxIndex])
			maxIndex = r;
		if (i != maxIndex)
		{
			swap(arr[i], arr[maxIndex]);
			shiftDown(maxIndex);
		}
	}
	
	/*
		Insertion (inserting the new element at last then calling the shiftUp to reorder accordingly)
	*/
	void insert(int p)
	{
		if (size == MAX_SIZE)
		{
			cout << "Priority Queue is full!";
			return;
		}
		size++;
		arr[size] = p;
		shiftUp(size);
	}
	
	/*
		Increasing the key by replacing key at i by newkey then shifting up/down accordingly
	*/
	void increaseKey(int i, int newp)
	{
		int oldp = arr[i];
		arr[i] = newp;
		if (newp > oldp)
			shiftUp(i);
		else
			shiftDown(i);
	}
	
	/*
		max - returns the root element without deleting it
	*/
	int max()
	{
		return arr[1];
	}
	
	/*
		extractMax - returns the root element by removing it
		(swapping first and last element, reducing size by 1 and then shifting down the new root element accordingly)
	*/
	int extractMax()
	{
		int max = arr[1];
		arr[1] = arr[size];
		size--;
		shiftDown(1);
		return max;
	}
	
	/*
		To print the queue
	*/
	void printQueue()
	{
		for(int i = 1; i <= size; ++i)
			cout << arr[i] << " ";
		cout << endl;
	}
};

/*
	Main Function
*/
int main()
{
	MaxPriorityQueue mpq;
	cout << "\nMax Priority Queue Implementation\n";

	int choice, temp, temp1;
	char ch = 'y';
	do
	{
		cout << "\n---------- Menu ----------";
		cout << "\n1. Insert";
		cout << "\n2. Increase key";
		cout << "\n3. Get Maximum";
		cout << "\n4. Extract Maximum";
		cout << "\n5. Print Queue";

		cout << "\n\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "\nEnter a key to insert: ";
			cin >> temp;
			mpq.insert(temp);
			cout << "\nResultant queue: ";
			mpq.printQueue();
			break;
		case 2:
			cout << "\nEnter index of key to be increased: ";
			cin >> temp;
			cout << "Enter the new key: ";
			cin >> temp1;
			mpq.increaseKey(temp, temp1);
			cout << "\nResultant queue: ";
			mpq.printQueue();
			break;
		case 3:
			cout << "\nMaximum key: " << mpq.max() << endl;
			break;
		case 4:
			cout << "\nMaximum key: " << mpq.extractMax();
			cout << "\nResultant queue: ";
			mpq.printQueue();
			break;
		case 5:
			cout << "\nQueue: ";
			mpq.printQueue();
			break;
		default:
			cout << "\nInvalid Choice!";
		}
		cout << "\nWant to continue? (Y/N): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	return 0;
}