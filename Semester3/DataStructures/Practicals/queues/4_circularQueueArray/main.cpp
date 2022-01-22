/*
	** Circular Queue using Array Implementation **
	
	Written by Anshul Verma, 78065
*/

#include <iostream>
using namespace std;

/**************************
	Queue Class
****************************/
template<typename X>
class Queue
{
	int front, rear;
	int MAX_SIZE;
	X *arr;

  public:
	Queue(int size)
	{
		MAX_SIZE = size;
		arr = new X[MAX_SIZE];
		front = rear = -1;
	}
	
	~Queue()
	{
		delete[] arr;
	}

	bool isempty()
	{
		if (front == -1 && rear == -1)
			return true;
		return false;
	}

	bool isfull()
	{
		if ((rear + 1) % MAX_SIZE == front)
			return true;
		return false;
	}

	void enqueue(X n)
	{
		if (isfull())
		{
			cout << "Queue overflow!\n";
			return;
		}
		else if (isempty())
			front = rear = 0;
		else
			rear = (rear + 1) % MAX_SIZE;
		arr[rear] = n;
	}

	X dequeue()
	{
		X n;
		if (isempty())
		{
			cout << "Queue underflow!\n";
			return 0;
		}
		else if (rear == front)
		{
			n = arr[front];
			front = rear = -1;
		}
		else
		{
			n = arr[front];
			front = (front + 1) % MAX_SIZE;
		}
		return n;
	}

	int count()
	{
		if (!isempty())
			return (rear - front + 1);
		return 0;
	}

	void display()
	{
		if (isempty())
			cout << "Queue is empty!";
		else
		{
			cout << "\t";
			if(front > rear)
			{
				for(int i = front; i < MAX_SIZE; ++i)
					cout << arr[i] << " ";
				for(int i = 0; i <= rear; ++i)
					cout << arr[i] << " ";
			}
			else
			{
				for (int i = front; i <= rear; ++i)
					cout << arr[i] << " ";
			}
		}
		cout << endl;
	}

	X peek()
	{
		return arr[front];
	}

	void clear()
	{
		while (!isempty())
			dequeue();
	}
};

/***************************************
	Driver(Main) Function
****************************************/
int main()
{
	Queue<int> que(5);
	int op;
	int value;
	cout << "\n< Circular Queue with Array Demonstration >\n";
	do
	{
		cout << "-------------------------";
		cout << "\n1. Enqueue\n2. Dequeue\n3. Clear the queue\n4. Count\n5. Peek\n6. Display the queue\n0. Exit\n";
		cout << "-------------------------\n";
		cout << "Enter your choice: ";
		cin >> op;

		switch (op)
		{
			case 0:
				break;
			case 1:
				cout << "Enter the element: ";
				cin >> value;
				que.enqueue(value);
				break;
			case 2:
				que.dequeue();
				break;
			case 3:
				que.clear();
				cout << "Queue Cleared!\n";
				break;
			case 4:
				cout << "No of element in the queue : " << que.count() << endl;
				break;
			case 5:
				cout << "Element at front is: " << que.peek() << endl;
				break;
			case 6:
				que.display();
				break;
		}
	} while (op != 0);

	return 0;
}