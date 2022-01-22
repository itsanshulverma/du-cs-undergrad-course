#include <iostream>
#include <string>
#include "stack_ll.h"
using namespace std;

int precedence(char op)
{
	switch(op)
	{
		case '^':
			return 3;
			break;
		case '%':
		case '/':
		case '*':
			return 2;
			break;
		case '+':
		case '-':
			return 1;
			break;
	}
	return -1;
}

string infixToPostfix(string infix)
{
	string postfix = "";
	Stack<char> s;
	for(int i=0; i < infix.length(); ++i)
	{
		if(isblank(infix[i])) continue;
		else if(isalnum(infix[i])) postfix += infix[i];
		else if(infix[i] == '(') s.push(infix[i]);
		else if(infix[i] == ')')
		{
			while(!s.isempty() && s.topEl() != '(')
				postfix += s.pop();
			s.pop();
		}
		else
		{
			while(!s.isempty() && precedence(infix[i]) < precedence(s.topEl()))
			{
				postfix += s.pop();
			}
			s.push(infix[i]);			
		}
	}
	while(!s.isempty())
		postfix += s.pop();
	return postfix;
}

int main()
{
	string exp;
	cout << "\nEnter the infix exp. : ";
	getline(cin, exp);
	cout << "\nPostfix Equivalent : " << infixToPostfix(exp) << endl;
	return 0;
}