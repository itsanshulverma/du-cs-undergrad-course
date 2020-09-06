/*
	** Circular Queue using Linked List Implementation **
	
	Written by Anshul Verma, 78065
*/

#include <iostream>
using namespace std;

/****************************
	Queue Class
*****************************/
template <typename X>
class Queue
{
	int MAX_SIZE;
	struct node
	{
		X data;
		struct node *next;
	};
	struct node *front, *rear, *temp;

  public:
  
    // Constructor
	Queue(int size)
	{
		MAX_SIZE = size;
		front = rear = NULL;
	}
	
	// Destructor
	~Queue()
	{
		clear();
	}

	// isempty Function
	bool isempty()
	{
		if (front == NULL)
			return true;
		return false;
	}

	// isfull Function
	bool isfull()
	{
		if (count() == MAX_SIZE)
			return true;
		return false;
	}

	// enqueue Function
	void enqueue(X n)
	{
		struct node *temp1 = new node;
		temp1->data = n;
		if (isfull())
		{
			cout << "Queue overflow!\n";
			return;
		}
		else if (isempty())
		{
			front = rear = temp1;
			front->next = rear;
			return;
		}
		else
		{
			cout << "Hi";
			temp1->next = rear->next;
			rear->next = temp1;
			rear = temp1;
		}
	}

	// dequeue Function
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
			n = front->data;
			delete front;
			front = rear = NULL;
		}
		else
		{
			n = front->data;
			temp = front;
			front = front->next;
			rear->next = front;
			delete temp;
		}
		return n;
	}

	// Count Function
	int count()
	{
		int cnt = 0;
		if (!isempty())
		{
			temp = front;
			do
			{
				++cnt;
				temp = temp->next;
			} while(temp != rear->next);
		}
		return cnt;
	}

	// Display Function
	void display()
	{
		if (isempty())
			cout << "Queue is empty!";
		else
		{
			cout << "\t";
			temp = front;
			do
			{
				cout << temp->data << " ";
				temp = temp->next;
			} while(temp != rear->next);
		}
		cout << endl;
	}

	// Peek Function
	X peek()
	{
		if(isempty())
			return -1;
		return front->data;
	}

	// Clear Function
	void clear()
	{
		while (!isempty())
			dequeue();
	}
};

/**************************************
	Driver (Main) Function
***************************************/
int main()
{
	Queue<int> que(5);
	int op;
	int value;
	cout << "\n< Circular Queue with Linked List Demonstration >\n";
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
			cout << "Queue cleared!\n";
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