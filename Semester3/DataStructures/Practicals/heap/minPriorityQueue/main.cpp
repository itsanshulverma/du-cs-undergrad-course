/*
	Written by Anshul Verma
*/

#include <iostream>
using namespace std;

#define MAX_SIZE 15

/*
	MinPriorityQueue class
*/
class MinPriorityQueue
{
	public:
	int *arr, size;
	MinPriorityQueue() 
	{ 
		arr = new int[MAX_SIZE]; 
		size = 0;
	}
	MinPriorityQueue(int size)
	{
		arr = new int[size]; 
		size = 0;
	}
	
	/*
		Function to check for parent and swap if parent is greater (iterating from current to top)
	*/
	void shiftUp(int i)
	{
		while (i > 1 && arr[i / 2] > arr[i])
		{
			swap(arr[i / 2], arr[i]);
			i = i / 2;
		}
	}
	
	/*
		Function to check for child (smallest out of left and right) and swap if it is smaller (iterating from current to bottom)
	*/
	void shiftDown(int i)
	{
		int minIndex = i;
		int l = 2 * i;
		int r = 2 * i + 1;
		if (l <= size && arr[l] < arr[minIndex])
			minIndex = l;
		if (r <= size && arr[r] < arr[minIndex])
			minIndex = r;
		if (i != minIndex)
		{
			swap(arr[i], arr[minIndex]);
			shiftDown(minIndex);
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
		Decreasing the key by replacing key at i by newkey then shifting up/down accordingly
	*/
	void decreaseKey(int i, int newp)
	{
		int oldp = arr[i];
		arr[i] = newp;
		if (newp < oldp)
			shiftUp(i);
		else
			shiftDown(i);
	}
	
	/*
		min - returns the root element without deleting it
	*/
	int min()
	{
		return arr[1];
	}
	
	/*
		extractMin - returns the root element by removing it
		(swapping first and last element, reducing size by 1 and then shifting down the new root element accordingly)
	*/
	int extractMin()
	{
		int min = arr[1];
		arr[1] = arr[size];
		size--;
		shiftDown(1);
		return min;
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
	MinPriorityQueue mpq;
	cout << "\nMin Priority Queue Implementation\n";

	int choice, temp, temp1;
	char ch = 'y';
	do
	{
		cout << "\n---------- Menu ----------";
		cout << "\n1. Insert";
		cout << "\n2. Decrease key";
		cout << "\n3. Get Minimum";
		cout << "\n4. Extract Minimum";
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
			cout << "\nEnter index of key to be decreased: ";
			cin >> temp;
			cout << "Enter the new key: ";
			cin >> temp1;
			mpq.decreaseKey(temp, temp1);
			cout << "\nResultant queue: ";
			mpq.printQueue();
			break;
		case 3:
			cout << "\nMinimum key: " << mpq.min() << endl;
			break;
		case 4:
			cout << "\nMinimum key: " << mpq.extractMin();
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