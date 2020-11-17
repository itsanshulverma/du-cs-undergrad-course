/*
	By Anshul Verma
	19/78065
*/

#include <iostream>
using namespace std;

/******************************************
	Circular SinglyLinkedList Class
*******************************************/
template <typename X>
class CircularSLL
{
	struct node
	{
		X data;
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
	bool is_empty();
	int count();
	void search();
	void reverse();
	void insert_at_end();
	void insert_at_begin();
	void insert_at_loc();
	void delete_at_end();
	void delete_at_begin();
	void delete_at_loc();
	void delete_by_data();
	void display();
	CircularSLL<X> operator+(CircularSLL<X> &list);
};

/******************************************
	isempty Function
*******************************************/
template <typename X>
bool CircularSLL<X>::is_empty()
{
	if (tail == NULL)
		return true;
	else
		return false;
}

/******************************************
	Display List Function
*******************************************/
template <typename X>
void CircularSLL<X>::display()
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
template <typename X>
void CircularSLL<X>::insert_at_end()
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
template <typename X>
void CircularSLL<X>::insert_at_begin()
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
template <typename X>
void CircularSLL<X>::insert_at_loc()
{
	if (!is_empty())
	{
		temp = new node;
		int loc;
		cout << "\nEnter the location for new node : ";
		cin >> loc;
		if (loc > (count() + 1) || loc < 1)
			cout << "Invalid Location!\n";
		else if (loc == 1)
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
template <typename X>
void CircularSLL<X>::delete_at_end()
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
		cout << "Deleted one node from end!" << endl;
	}
}

/**************************************************
	Delete at Beginning Function
***************************************************/
template <typename X>
void CircularSLL<X>::delete_at_begin()
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
		cout << "Deleted one node from beginning!" << endl;
	}
}

/***************************************************
	Delete at a Location Function
****************************************************/
template <typename X>
void CircularSLL<X>::delete_at_loc()
{
	if (!is_empty())
	{
		int loc;
		cout << "\nEnter the location of node to delete : ";
		cin >> loc;
		if (loc > count() || loc < 1)
			cout << "Invalid location!\n";
		else if (loc == 1)
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
				cout << "Deleted from location : " << loc << "!" << endl;
			}
		}
	}
}

/*******************************************************
	Delete by data entered Function
********************************************************/
template <typename X>
void CircularSLL<X>::delete_by_data()
{
	if (!is_empty())
	{
		X data;
		bool contains = false;
		cout << "Enter the node data to be deleted: ";
		cin >> data;
		ptr = tail->next;
		if (ptr->data == data)
			delete_at_begin();
		else if(tail->data == data)
			delete_at_end();
		else
		{
			do
			{
				if (ptr->data == data)
				{
					contains = true;
					temp->next = ptr->next;
					delete ptr;
					break;
				}
				temp = ptr;
				ptr = ptr->next;
			}while(ptr != tail);
			if (!contains)
				cout << "List doesn't have this node already!\n";
			cout << "Deleted!\n";
		}
	}
}	

/******************************************
	Count Function
*******************************************/
template <typename X>
int CircularSLL<X>::count()
{
	int count = 0;
	ptr = tail;
	do
	{
		ptr = ptr->next;
		++count;
	} while (ptr != tail);
	return count;
}

/******************************************
	Search Function
*******************************************/
template <typename X>
void CircularSLL<X>::search()
{
	if (!is_empty())
	{
		X data;
		int loc = 0;
		bool contains = false;
		cout << "\nEnter the node data to be searched : ";
		cin >> data;
		ptr = tail;
		do
		{
			ptr = ptr->next;
			++loc;
			if (ptr->data == data)
			{
				contains = true;
				break;
			}
		} while (ptr != tail);
		if (contains)
			cout << "Data found at location " << loc << " in the list." << endl;
		else
			cout << "Data not found in the list.";
	}
}

/******************************************
	Reverse Function
*******************************************/
template <typename X>
void CircularSLL<X>::reverse()
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
	'+' overloaded Function
*******************************************/
template <typename X>
CircularSLL<X> CircularSLL<X>::operator+(CircularSLL<X> &list)
{
	temp = tail->next;
	tail->next = list.tail->next;
	tail = list.tail;
	tail->next = temp;
	cout << tail->data << endl << tail->next->data;
	cout << "\nConcatenated list:\n";
	display();
	return *this;
}

/******************************************
	Main Function
*******************************************/
int main()
{
	int choice, choice1;
	char ch, ch1;
	CircularSLL<int> list, new_list;
	cout << "\nCircular Singly Linked list demonstration: \n";
	do
	{
		cout << "\n1. Insert node\n2. Delete node\n3. Count the nodes\n4. Search\n5. Reverse the list\n6. Display\n7. Concatenate with another list\n8. Exit" << endl;
		cout << "Enter your choice : ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			do
			{
				cout << "\n1. Insert at beginning\n2. Insert at end\n3. Insert at location\nEnter your choice: ";
				cin >> choice1;
				switch (choice1)
				{
				case 1:
					list.insert_at_begin();
					break;
				case 2:
					list.insert_at_end();
					break;
				case 3:
					list.insert_at_loc();
					break;
				}
				cout << "Want to insert more nodes? (y/n): ";
				cin >> ch1;
			} while (ch1 == 'y');
			list.display();
			break;
		case 2:
			do
			{
				if (list.is_empty())
					break;
				else
				{
					cout << "\n1. Delete at beginning\n2. Delete at end\n3. Delete at location\n4. Delete by node data\nEnter your choice: ";
					cin >> choice1;
					switch (choice1)
					{
					case 1:
						list.delete_at_begin();
						break;
					case 2:
						list.delete_at_end();
						break;
					case 3:
						list.delete_at_loc();
						break;
					case 4:
						list.delete_by_data();
						break;
					default:
						cout << "Invalid Choice!";
					}
					cout << "Want to delete more nodes? (y/n): ";
					cin >> ch1;
				}
			} while (ch1 == 'y');
			list.display();
			break;
		case 3:
			cout << "\nThe list contains " << list.count() << " nodes.";
			break;
		case 4:
			list.search();
			break;
		case 5:
			list.reverse();
			list.display();
			break;
		case 6:
			list.display();
			break;
		case 7:
			cout << "\nCreating (new) list to be concatenated...\n";
			do
			{
				new_list.insert_at_end();
				cout << "\nWant to enter more nodes? (y/n) ";
				cin >> ch1;
			} while (ch1 == 'y');
			new_list.display();
			list + new_list;
			break;
		case 8:
			exit(0);
			break;
		default:
			cout << "Invalid Choice!";
		}
		cout << "\nWant to operate more? (y/n) ";
		cin >> ch;
	} while (ch == 'y');
}

