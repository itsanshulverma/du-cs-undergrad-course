#include <iostream>
using namespace std;

#define SIZE 10

class Stack
{
	int arr[SIZE];
	int top;
	
	public:
	
	Stack(){ top = -1; }
	
	bool isempty()
	{
		return (top < 0);
	}
	bool push(int n)
	{
		if(top == SIZE-1)
		{
			cout << "\nStack is full!" << endl;
			return false;
		}
		else
		{
			arr[++top] = n;
			return true;
		}
	}
	
	int pop()
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
	
	int topEl()
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
			cout << "\nStack : ";
			for(int i=0; i <= top; ++i)
			{
				cout << arr[i] << " ";
			}
			cout << "<--top\n\n";
		}
	}
};

Stack reverseStack(Stack &s)
{
    Stack temp;
    while(!s.isempty())
    {
        temp.push(s.pop());
    }

    return temp;
}

int main()
{
    Stack s1;
    s1.push(34);
    s1.push(44);
    s1.push(56);
    s1.push(76);
    s1.push(72);
    s1.push(14);
    s1.push(29);
    s1.display();
    cout << "Reversing...\n";
    Stack s2 = reverseStack(s1);
    s2.display();

    return 0;
}