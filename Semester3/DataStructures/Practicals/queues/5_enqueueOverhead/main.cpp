/*
	** Queue using Stack with Enqueue Overhead Implementation **
	
	Written by Anshul Verma, 78065
*/

#include <iostream>
#include "stack_ll.h"
using namespace std;

/**************************
	Queue Class
***************************/
template <typename X>
class Queue{
	
	int cnt = 0;
	Stack<X> s1, s2;
	
	public:
	
	// Constructor
	Queue(){}
	
	// Destructor
	~Queue(){ 
		s1.clear(); 
		s2.clear();
	}
	
	// isempty function
	bool isempty()
	{
		if(s1.isempty()) return true;
		return false;
	}
	
	// enqueue function
	void enqueue(X val)
	{
		++cnt;
		
		while(!s1.isempty())
		{
			s2.push(s1.pop());
		}
		
		s1.push(val);
		
		while(!s2.isempty())
		{
			s1.push(s2.pop());
		}
	}
	
	// dequeue function
	X dequeue()
	{
		if(isempty())
		{
			cout << "Queue underflow!\n";
			return 0;
		}
		--cnt;
		return s1.pop();
	}
	
	// count function
	int count()
	{
		return cnt;
	}
	
	// display function
	void display()
	{
		if (isempty())
			cout << "Queue is empty!\n";
		else s1.display();
	}
	
	// peek function
	X peek()
	{
		if (isempty())
			return -1;
		return s1.topEl();
	}
	
	// clear function
	void clear()
	{
		cnt = 0;
		s1.clear();
	}
};

/***************************************
	Driver(Main) Function
****************************************/
int main()
{
	Queue<int> que;
	int op;
	int value;
	cout << "\n< Queue using Stacks with Enqueue Overhead >\n";
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