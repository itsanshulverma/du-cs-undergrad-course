/*
	** Linear Queue using Linked List Implementation **
	
	Written by Anshul Verma, 78065
*/

#include <iostream>
using namespace std;

/**************************
	Queue Class
**************************/
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
    Queue()
    {
    	MAX_SIZE = 50;
    	front = rear = NULL;
    }
	Queue(int size)
	{
		MAX_SIZE = size;
		front = rear = NULL;
	}
	~Queue()
	{
		clear();
	}

	bool isempty()
	{
		if (front == NULL)
			return true;
		return false;
	}

	bool isfull()
	{
		if (count()==MAX_SIZE)
			return true;
		return false;
	}

	void enqueue(X n)
	{
		struct node *temp1 = new node;
		temp1->data = n;
		temp1->next = NULL;
		if (isfull())
		{
			cout << "Queue overflow!\n";
			return;
		}
		else if (isempty())
		{
			front = rear = temp1;
			return;
		}
		else
		{
			rear->next = temp1;
			rear = temp1;
		}
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
			n = front->data;
			delete front;
			front = rear = NULL;
		}
		else
		{
			n = front->data;
			temp = front;
			front = front->next;
			delete temp;
		}
		return n;
	}

	int count()
	{
		int cnt = 0;
		if (!isempty())
		{
			temp = front;
			while(temp != NULL)
			{
				++cnt;
				temp = temp->next;
			}
		}
		return cnt;
	}

	void display()
	{
		if (isempty())
			cout << "Queue is empty!";
		else
		{
			cout << "\t";
			temp = front;
			while(temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
		}
		cout << endl;
	}

	X peek()
	{
		if(isempty())
			return -1;
		return front->data;
	}

	void clear()
	{
		while (!isempty())
			dequeue();
	}
};