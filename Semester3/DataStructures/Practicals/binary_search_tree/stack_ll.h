#include <iostream>
using namespace std;

template <typename X>
class Stack
{
	struct node
	{
		X data;
		struct node *next;
	};
	int count = 0;
	struct node *top, *temp;

  public:
	Stack() { top = NULL; }
	~Stack() { clear(); }

	bool isempty()
	{
		return (top == NULL);
	}

	void push(X n)
	{
		temp = new node;
		temp->data = n;
		if (isempty())
		{
			temp->next = NULL;
			top = temp;
		}
		else
		{
			temp->next = top;
			top = temp;
		}
		++count;
	}

	X pop()
	{
		if (isempty())
		{
			cout << "\nStack is empty!" << endl;
			return 0;
		}
		else
		{
			X n = top->data;
			if (top->next == NULL)
			{
				delete top;
				top = NULL;
			}
			else
			{
				temp = top;
				top = top->next;
				delete temp;
			}
			--count;
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
		else return top->data;
	}

	void clear()
	{
		while (!isempty())
			pop();
	}

	void display()
	{
		if (isempty())
			cout << "\nStack is empty!" << endl;
		else
		{
			temp = top;
			cout << "\t";
			while (temp != NULL)
			{
				cout << temp->data << " ";
				temp = temp->next;
			}
			cout << endl;
		}
	}
};