#include<iostream>
#include<string>
#include "stack_ll.h"

struct return_val{
	bool result;
	char err_char;	
};

return_val is_matched(string str)
{
	Stack<char> s;
	char ch;
	struct return_val r;
	for(int i = 0; i<str.length(); ++i)
	{
		if(str[i] == '{' || str[i] == '(' || str[i] == '[' || str[i] == '<') s.push(str[i]);
		else if(str[i] == ')' && !s.isempty())
		{
			ch = s.pop();
			if(ch == '{' || ch == '[' || ch == '<')
			{
				r.result = false;
				r.err_char = ch;
			}
			else r.result = true;
		}
		else if(str[i] == '}' && !s.isempty())
		{
			ch = s.pop();
			if(ch == '(' || ch == '[' || ch == '<')
			{
				r.result = false;
				r.err_char = ch;
			}
			else r.result = true;
		}
		else if(str[i] == ']' && !s.isempty())
		{
			ch = s.pop();
			if(ch == '(' || ch == '{' || ch == '<')
			{
				r.result = false;
				r.err_char = ch;
			}
			else r.result = true;
		}
		else if(str[i] == '>' && !s.isempty())
		{
			ch = s.pop();
			if(ch == '(' || ch == '[' || ch == '{')
			{
				r.result = false;
				r.err_char = ch;
			}
			else r.result = true;
		}
		else r.result = false;
	}
	return r;
}

int main()
{
	string str;
	cout << "\nEnter the text to be checked: ";
	getline(cin, str);
	if(is_matched(str).result)
		cout << "\nAll delimiters matched!\n";
	else
		cout << "\nDelimiters not matched!\nUnmatched delimiter: "<< is_matched(str).err_char << endl;
}