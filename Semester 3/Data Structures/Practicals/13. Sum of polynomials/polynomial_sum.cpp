#include <iostream>
using namespace std;

class Polynomial {
	struct term {
		int coeff, pow;
		struct term *next;
	};	
	struct term *head, *ptr, *temp, *tail;
	
	public:
	Polynomial()
	{
		head = NULL;
	}
	~Polynomial()
	{
		ptr = head;
		while (ptr != NULL)
		{
			temp = ptr->next;
			delete ptr;
			ptr = temp;
		}
	}

	void insert(int n1, int n2)
	{
		temp = new term;
		temp->coeff = n1;
		temp->pow = n2;
		temp->next = NULL;
		if (head == NULL)
		{
			head = temp;
			tail = head;
		}
		else
		{
			struct term *temp1;
			if (temp->pow > head->pow)
			{
				temp->next = head;
				head = temp;
			}
			else if (temp->pow < tail->pow)
			{
				tail->next = temp;
				tail = temp;
			}
			else
			{
				ptr = head;
				while (ptr != NULL)
				{
					temp1 = ptr;
					ptr = ptr->next;
					if (temp->pow == temp1->pow)
					{
						temp1->coeff += temp->coeff;
					}
					else if ((temp->pow < temp1->pow) && (temp->pow > ptr->pow))
					{
						temp->next = ptr;
						temp1->next = temp;
					}
				}
			}
		}
	}

	void print()
	{
		if (head == NULL)
			cout << "0";
		ptr = head;
		while (ptr != NULL)
		{
			if (ptr != head)
				cout << " + ";
			if (ptr->pow == 0)
				cout << ptr->coeff;
			else
				cout << ptr->coeff << "x^" << ptr->pow;
			ptr = ptr->next;
		}
	}

	Polynomial operator+(Polynomial &p)
	{
		Polynomial poly;
		poly = *this;
		ptr = p.head;
		while(ptr != NULL)
		{
			poly.insert(ptr->coeff, ptr->pow);
			ptr = ptr->next;
		}
		return poly;
	}
};

void create_poly(Polynomial &poly)
{
	int coeff, pow;
	char ch;
	do
	{
		cout << "\n\tEnter the coefficient : ";
		cin >> coeff;
		cout << "\tEnter the power of x: ";
		cin >> pow;
		poly.insert(coeff, pow);

		cout << "\n\tWant to enter more terms? ";
		cin >> ch;
	} while (ch == 'y');
}

int main()
{
	Polynomial poly1, poly2, poly3;
	cout << "\nPolynomial P:";
	create_poly(poly1);
	cout << "\nPolynomial Q:";
	create_poly(poly2);
	cout << "\n\t--------------\n\n\tP     : ";
	poly1.print();
	cout << "\n\tQ     : ";
	poly2.print();
	cout << "\n\nSum of polynomials, i.e.\n\n\tP + Q : ";
	poly3 = poly1 + poly2;
	poly3.print();
	cout<<endl;
	return 0;
}