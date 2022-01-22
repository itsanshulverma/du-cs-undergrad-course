#include <iostream>
#include <stdlib.h>
#include "stack_ll.h"
using namespace std;

int main()
{
	Stack<float> s;
	float r;
	cout << "Stack<float> demonstration (w/Linked list): \n";
	cout << "\nPushing elements to stack:\n";
	for(int i=0; i<5; i++)
	{
		r = float((rand() % 1000 + 1)/(rand() % 10 + 0.1));
		s.push(r);
		cout << "\nElement at top: " << s.topEl();
	}
	s.display();
	
	cout << "\nPopping elements from stack:\n";
	while(true)
	{
		if(s.topEl() == 0)
			break;
		else
		{
			cout << "\nElement at top: " << s.topEl();
			cout << endl << s.pop() << " popped out of stack.";
		}
	}
	
	cout << "\nPushing elements to stack again...\n";
	for(int i=0; i<5; i++)
	{
		r = float((rand() % 1000 + 1)/(rand() % 10 + 0.1));
		s.push(r);
		cout << "\nElement at top: " << s.topEl();
	}
	s.display();
	return 0;
}