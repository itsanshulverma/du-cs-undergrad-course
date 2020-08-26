#include <iostream>
#include <string>
#include "stack_ll.h"
using namespace std;

void tostack(string &n, Stack<int> &s)
{
	for (int i = 0; i < n.length(); ++i)
	{
		s.push((int)(n[i] - 48));
	}
}

void add(Stack<int> &s1, Stack<int> &s2, Stack<int> &sum)
{
	int n1, n2, carry = 0;
	int itr = s1.count;
	if (s2.count > itr)
		itr = s2.count;
	for (int i = 0; i < itr; i++)
	{
		if (s1.isempty())
			n1 = 0;
		else
			n1 = s1.pop();

		if (s2.isempty())
			n2 = 0;
		else
			n2 = s2.pop();
			
		sum.push((n1 + n2 + carry) % 10);
		carry = (n1 + n2 + carry) / 10;
	}
	if (carry > 0)
		sum.push(carry);
}

int main()
{
	string n;
	Stack<int> s1, s2, s3;
	cout << "\nEnter 1st number: ";
	cin >> n;
	tostack(n, s1);
	cout << "Enter 2nd number: ";
	cin >> n;
	tostack(n, s2);
	cout << "\n\tSum\t: ";
	add(s1, s2, s3);
	s3.display();
	cout << endl;
}