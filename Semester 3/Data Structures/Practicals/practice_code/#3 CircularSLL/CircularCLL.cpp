/*
	By Anshul Verma
	19/78065
*/

#include <iostream>

using namespace std;

/******************************************
	Circular SinglyLinkedList Class
*******************************************/
class CircularSLL
{
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *temp, *ptr, *tail;

  public:
	CircularSLL()
	{
		tail = NULL;
	}
	~CircularSLL()
	{
		if (!is_empty())
		{
			cout << "\nDeallocating memory...\n";
			ptr = tail->next;
			tail->next = NULL;
			while (ptr != NULL)
			{
				temp = ptr->next;
				delete ptr;
				ptr = temp;
			}
		}
	}
	void create();
	bool is_empty();
	void count();
	void search();
	void reverse();
	void insert_at_end();
	void insert_at_begin();
	void insert_at_loc();
	void delete_at_end();
	void delete_at_begin();
	void delete_at_loc();
	void display();
};

/******************************************
	isempty Function
*******************************************/
bool CircularSLL::is_empty()
{
	if (tail == NULL)
		return true;
	else
		return false;
}

/******************************************
	Create List Function
*******************************************/
void CircularSLL::create()
{
	char ch = 'y';
	do
	{
		insert_at_end();
		cout << "Want to enter more nodes ? (y/n) : ";
		cin >> ch;
	} while (ch == 'y');
}

/******************************************
	Display List Function
*******************************************/
void CircularSLL::display()
{
	cout << "\n\t";
	if (is_empty())
		cout << "Linked List is empty.";
	else
	{
		ptr = tail;
		do
		{
			ptr = ptr->next;
			cout << "-->" << ptr->data;
		} while (ptr != tail);
		cout << "-->...";
	}
	cout << endl;
}

/******************************************
	Insert at End Function
*******************************************/
void CircularSLL::insert_at_end()
{
	temp = new node;
	cout << "\nEnter the node data : ";
	cin >> temp->data;
	if (is_empty())
	{
		tail = temp;
		tail->next = tail;
	}
	else
	{
		temp->next = tail->next;
		tail->next = temp;
		tail = temp;
	}
	cout << "Inserted!" << endl;
}

/***************************************************
	Insert at Beginning Function
****************************************************/
void CircularSLL::insert_at_begin()
{
	temp = new node;
	cout << "\nEnter the node data : ";
	cin >> temp->data;
	if (is_empty())
	{
		tail = temp;
		tail->next = tail;
	}
	else
	{
		temp->next = tail->next;
		tail->next = temp;
	}
	cout << "Inserted!" << endl;
}

/***************************************************
	Insert at a Location Function
****************************************************/
void CircularSLL::insert_at_loc()
{
	if (!is_empty())
	{
		temp = new node;
		int loc;
		cout << "\nEnter the location for new node : ";
		cin >> loc;
		if (loc == 1)
			insert_at_begin();
		else
		{
			ptr = tail->next;
			for (int i = 1; i < loc - 1; i++)
			{
				ptr = ptr->next;
			}
			if (ptr == tail)
				insert_at_end();
			else
			{
				cout << "Enter the node data : ";
				cin >> temp->data;
				temp->next = ptr->next;
				ptr->next = temp;
				cout << "Inserted!" << endl;
			}
		}
	}
}

/*******************************************
	Delete at End Function
********************************************/
void CircularSLL::delete_at_end()
{
	if (!is_empty())
	{
		if (tail->next == tail)
		{
			delete tail;
			tail=NULL;
		}
		else
		{
			ptr = tail;
			do
			{
				ptr = ptr->next;
			} while (ptr->next != tail);
			ptr->next = tail->next;
			delete tail;
			tail = ptr;
		}
		cout << "\nDeleted one node from end!" << endl;
	}
}

/**************************************************
	Delete at Beginning Function
***************************************************/
void CircularSLL::delete_at_begin()
{
	if (!is_empty())
	{
		temp = tail->next;
		if (tail->next == tail)
		{
			delete temp;
			tail = NULL;
		}
		else
		{
			tail->next = temp->next;
			delete temp;
		}
		cout << "\nDeleted one node from beginning!" << endl;
	}
}

/***************************************************
	Delete at a Location Function
****************************************************/
void CircularSLL::delete_at_loc()
{
	if (!is_empty())
	{
		int loc;
		cout << "\nEnter the location of node to delete : ";
		cin >> loc;
		if (loc == 1)
			delete_at_begin();
		else
		{
			ptr = tail->next;
			for (int i = 1; i < loc - 1; i++)
			{
				ptr = ptr->next;
			}
			if (ptr->next == tail)
				delete_at_end();
			else
			{
				temp = ptr->next;
				ptr->next = temp->next;
				delete temp;
				cout << "\nDeleted from location : " << loc << "!" << endl;
			}
		}
	}
}

/******************************************
	Count Function
*******************************************/
void CircularSLL::count()
{
	if (!is_empty())
	{
		int count = 0;
		ptr = tail;
		do
		{
			ptr = ptr->next;
			++count;
		} while (ptr != tail);
		cout << "\nThere are " << count << " nodes in the list." << endl;
	}
	else
		display();
}

/******************************************
	Search Function
*******************************************/
void CircularSLL::search()
{
	if (!is_empty())
	{
		int n, count = 0, flag = 0;
		cout << "\nEnter the node data to be searched : ";
		cin >> n;
		ptr = tail;
		do
		{
			ptr = ptr->next;
			++count;
			if (ptr->data == n)
			{
				flag = 1;
				break;
			}
		} while (ptr != tail);
		if (flag == 1)
			cout << "Data found at location " << count << " in the list." << endl;
		else
			cout << "Data not found in the list.";
	}
	else
		display();
}

/******************************************
	Reverse Function
*******************************************/
void CircularSLL::reverse()
{
	if (!is_empty() && (tail->next != tail))
	{
		struct node *temp1 = new node;
		temp1 = tail->next;
		ptr = temp1->next;
		tail->next = NULL;
		tail = temp1;
		while (ptr != NULL)
		{
			temp = ptr;
			ptr = ptr->next;
			temp->next = temp1;
			temp1 = temp;
		}
		tail->next = temp1;
	}
	cout << "\nReversed!" << endl;
}

/******************************************
	Main Function
*******************************************/
int main()
{
	int choice;
	char ch;
	CircularSLL list;
	do
	{
		cout << "\n1. Create\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Location\n5. Delete at Beginning\n6. Delete at End\n7. Delete at Location\n8. Count the nodes\n9. Search\n10. Reverse the list\n11. Display\n12. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			list.create();
			list.display();
			break;
		case 2:
			list.insert_at_begin();
			list.display();
			break;
		case 3:
			list.insert_at_end();
			list.display();
			break;
		case 4:
			list.insert_at_loc();
			list.display();
			break;
		case 5:
			list.delete_at_begin();
			list.display();
			break;
		case 6:
			list.delete_at_end();
			list.display();
			break;
		case 7:
			list.delete_at_loc();
			list.display();
			break;
		case 8:
			list.count();
			break;
		case 9:
			list.search();
			break;
		case 10:
			list.reverse();
			list.display();
			break;
		case 11:
			list.display();
			break;
		case 12:
			exit(0);
		}
		cout << "\nWant to operate more? (y/n) ";
		cin >> ch;
	} while (ch == 'y');
}