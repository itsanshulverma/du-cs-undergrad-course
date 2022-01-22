#include <iostream>
#include <string>
#include "stack_ll.h"
using namespace std;

int reverse(int n)
{
	int res = 0;
	while(n != 0)
	{
		res = (res*10) + n%10;
		n = n/10;
	}
	return res;
}

int evalPostfix(string &n)
{
	Stack<int> s, temp;
	int a;
	for (int i = 0; i < n.length(); ++i)
	{
		if (n[i] >= '0' && n[i] <= '9')
		{
			temp.push(n[i] - '0');
		}
		else
		{
			a = 0;
			while (!temp.isempty())
				a = (a * 10) + temp.pop();
			if(a != 0) s.push(reverse(a));
			switch(n[i])
			{
				case '+':
					s.push(s.pop() + s.pop());
					break;
				case '-':
					s.push(s.pop() - s.pop());
					break;
				case '*':
					s.push(s.pop() * s.pop());
					break;
				case '/':
					s.push(s.pop() / s.pop());
					break;
				case '%':
					s.push(s.pop() % s.pop());
					break;
			}
		}
	}
	return s.pop();
}

int main()
{
	string exp;
	cout << "\nEnter the postfix exp  : ";
	getline(cin, exp);
	cout << "\n\t\tResult : " << evalPostfix(exp) << endl;
}