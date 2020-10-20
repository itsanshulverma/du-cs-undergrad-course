#include <iostream>
#include <stdlib.h>
#include "stack_arr.h"
using namespace std;

int main()
{
	Stack<int> s;
	int r;
	cout << "Stack<int> demonstration (w/array): \n";
	cout << "\nPushing elements to stack:\n";
	while(true)
	{
		r = (rand() % 1000 + 1);
		bool flag = s.push(r);
		if(!flag)
			break;
		else
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
	while(true)
	{
		r = rand() % 1000 + 1;
		bool flag = s.push(r);
		if(!flag)
			break;
		else
			cout << "\nElement at top: " << s.topEl();
	}
	s.display();
	s.clear();
	return 0;
}