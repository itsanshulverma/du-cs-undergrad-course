#include <iostream>
using namespace std;

#define SIZE 5

template<typename X>
class Stack
{
	X arr[SIZE];
	int top;
	
	public:
	
	Stack(){ top = -1; }
	
	bool isempty()
	{
		return (top < 0);
	}
	bool push(X n)
	{
		if(top == SIZE-1)
		{
			cout << "\nStack is full!" << endl;
			return false;
		}
		else
		{
			arr[++top] = n;
			cout << endl << n << " pushed into stack.";
			return true;
		}
	}
	
	X pop()
	{
		if(isempty())
		{
			cout << "\nStack is empty!" << endl;
			return 0;
		}
		else
		{
			int n = arr[top--];
			return n;
		}
	}
	
	X topEl()
	{
		if(isempty())
		{
			cout << "\nStack is empty!" << endl;
			return 0;
		}
		else
			return arr[top];
	}
	
	void clear()
	{
		cout << "\nClearing the stack...";
		while(!isempty())
			pop();
		cout << " Done" <<endl;
	}
	
	void display()
	{
		if(isempty())
			cout << "\nStack is empty!" << endl;
		else
		{
			cout << "\nStack<" << top+1 << "> : ";
			for(int i=0; i <= top; ++i)
			{
				cout << arr[i] << " ";
			}
			cout << "<--top" << endl;
		}
	}
};