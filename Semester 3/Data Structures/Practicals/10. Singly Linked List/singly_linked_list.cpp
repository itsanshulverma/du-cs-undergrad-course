/*
	By Anshul Verma
	19/78065
*/

#include <iostream>

using namespace std;

/******************************************
	SinglyLinkedList Class
*******************************************/
template <typename X>
class SinglyLinkedList
{
	struct node
	{
		X data;
		struct node *next;
	};
	struct node *head, *temp, *ptr, *tail;

  public:
	SinglyLinkedList()
	{
		head = NULL;
	}
	~SinglyLinkedList()
	{
		ptr = head;
		while (ptr != NULL)
		{
			temp = ptr->next;
			delete ptr;
			ptr = temp;
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
	SinglyLinkedList<X> operator+(SinglyLinkedList<X> &list);
};

/******************************************
	is Empty Function
*******************************************/
template <typename X>
bool SinglyLinkedList<X>::is_empty()
{
	if (head == NULL)
		return true;
	else
		return false;
}

/******************************************
	Display List Function
*******************************************/
template <typename X>
void SinglyLinkedList<X>::display()
{
	cout << "\n\t";
	if (is_empty())
		cout << "Linked List is empty.";
	ptr = head;
	while (ptr != NULL)
	{
		if (ptr == head)
			cout << ptr->data;
		else
			cout << " --> " << ptr->data;
		ptr = ptr->next;
	}
	cout << endl;
}

/******************************************
	Insert at End Function
*******************************************/
template <typename X>
void SinglyLinkedList<X>::insert_at_end()
{
	temp = new node;
	cout << "\nEnter the node data: ";
	cin >> temp->data;
	temp->next = NULL;
	if (is_empty())
	{
		head = temp;
		tail = head;
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
	cout << "Inserted!" << endl;
}

/***************************************************
	Insert at Beginning Function
****************************************************/
template <typename X>
void SinglyLinkedList<X>::insert_at_begin()
{
	temp = new node;
	cout << "\nEnter the node data: ";
	cin >> temp->data;
	if (is_empty())
	{
		temp->next = NULL;
		head = temp;
		tail = head;
	}
	else
	{
		temp->next = head;
		head = temp;
	}
	cout << "Inserted!" << endl;
}

/***************************************************
	Insert at a Location Function
****************************************************/
template <typename X>
void SinglyLinkedList<X>::insert_at_loc()
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
			ptr = head;
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
	else
		insert_at_end();
}

/*******************************************
	Delete at End Function
********************************************/
template <typename X>
void SinglyLinkedList<X>::delete_at_end()
{
	if (!is_empty())
	{
		if (head == tail)
		{
			delete tail;
			head = NULL;
		}
		else
		{
			ptr = head;
			while (ptr->next->next != NULL)
			{
				ptr = ptr->next;
			}
			delete ptr->next;
			ptr->next = NULL;
			tail = ptr;
		}
		cout << "Deleted!" << endl;
	}
}

/**************************************************
	Delete at Beginning Function
***************************************************/
template <typename X>
void SinglyLinkedList<X>::delete_at_begin()
{
	if (!is_empty())
	{
		if (head == tail)
		{
			delete tail;
			head = NULL;
		}
		else
		{
			temp = head;
			head = head->next;
			delete temp;
		}
		cout << "Deleted!" << endl;
	}
}

/***************************************************
	Delete at a Location Function
****************************************************/
template <typename X>
void SinglyLinkedList<X>::delete_at_loc()
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
			ptr = head;
			for (int i = 1; i < loc - 1; i++)
			{
				ptr = ptr->next;
			}
			if (ptr == tail)
				delete_at_end();
			else
			{
				temp = ptr->next;
				ptr->next = ptr->next->next;
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
void SinglyLinkedList<X>::delete_by_data()
{
	if (!is_empty())
	{
		X data;
		bool contains = false;
		cout << "Enter the node data to be deleted: ";
		cin >> data;
		if (head->data == data)
			delete_at_begin();
		else if(tail->data == data)
			delete_at_end();
		else
		{
			ptr = head;
			while (ptr != NULL)
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
			}
			if (!contains)
				cout << "List doesn't have this node already!";
			cout << "Deleted!";
		}
	}
}

/******************************************
	Count Function
*******************************************/
template <typename X>
int SinglyLinkedList<X>::count()
{
	int count = 0;
	ptr = head;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		++count;
	}
	return count;
}

/******************************************
	Search Function
*******************************************/
template <typename X>
void SinglyLinkedList<X>::search()
{
	if (!is_empty())
	{
		X data;
		int loc = 0;
		bool contains = false;
		cout << "\nEnter the node data to be searched : ";
		cin >> data;
		ptr = head;
		while (ptr != NULL)
		{
			++loc;
			if (ptr->data == data)
			{
				contains = true;
				break;
			}
			ptr = ptr->next;
		}
		if (contains == 1)
			cout << "Data found at location " << loc << " in the list." << endl;
		else
			cout << "Data not found in the list.";
	}
}

/******************************************
	Reverse Function
*******************************************/
template <typename X>
void SinglyLinkedList<X>::reverse()
{
	if (!is_empty())
	{
		ptr = head->next;
		head->next = NULL;
		tail = head;
		while (ptr != NULL)
		{
			temp = ptr;
			ptr = ptr->next;
			temp->next = head;
			head = temp;
		}
		cout << "\nReversed!" << endl;
	}
}

/******************************************
	'+' overloaded Function
*******************************************/
template <typename X>
SinglyLinkedList<X> SinglyLinkedList<X>::operator+(SinglyLinkedList<X> &list)
{
	tail->next = list.head;
	tail = list.tail;
	return *this;
}

/******************************************
	Main Function
*******************************************/
int main()
{
	int choice, choice1;
	char ch, ch1;
	SinglyLinkedList<int> list, new_list;
	cout << "\nSingly Linked list demonstration: \n";
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
			list = list + new_list;
			cout << "\nConcatenated list:\n";
			list.display();
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
