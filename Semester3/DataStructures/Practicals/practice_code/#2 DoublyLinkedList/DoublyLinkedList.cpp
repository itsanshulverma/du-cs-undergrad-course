/*
	By Anshul Verma
	19/78065
*/

#include <iostream>

using namespace std;

/******************************************
	DoublyiLinkedList Class
*******************************************/
class DoublyLinkedList
{
	struct node
	{
		int data;
		struct node *prev, *next;
	};
	struct node *head, *temp, *ptr, *tail;

  public:
	DoublyLinkedList()
	{
		head = NULL;
	}
	~DoublyLinkedList()
	{
		cout << "\nDeallocating memory...\n";
		ptr = head;
		while (ptr != NULL)
		{
			temp = ptr->next;
			delete ptr;
			ptr = temp;
		}
	}
	void create();
	void count();
	void search();
	void insert_at_end();
	void insert_at_begin();
	void insert_at_loc();
	void delete_at_end();
	void delete_at_begin();
	void delete_at_loc();
	void display();
};

/******************************************
	Create List Function
*******************************************/
void DoublyLinkedList::create()
{
	int n;
	char ch = 'y';
	do
	{
		temp = new node;
		temp->next = NULL;
		cout << "\nEnter the node data : ";
		cin >> n;
		if (head == NULL)
		{
			head = temp;
			head->data = n;
			head->next = NULL;
			head->prev = NULL;
			tail = head;
		}
		else
		{
			temp->data = n;
			temp->prev = tail;
			tail->next = temp;
			tail = temp;
		}
		cout << "Want to enter more nodes ? (y/n) : ";
		cin >> ch;
	} while (ch == 'y');
}

/******************************************
	Display List Function
*******************************************/
void DoublyLinkedList::display()
{
	cout << "\n\t";
	if (head == NULL)
		cout << "Linked List is empty.";
	ptr = head;
	while (ptr != NULL)
	{
		if(ptr==head)
			cout<<ptr->data;
		else
			cout << " <--> " << ptr->data;
		ptr = ptr->next;
	}
	cout << endl;
}

/******************************************
	Insert at End Function
*******************************************/
void DoublyLinkedList::insert_at_end()
{
	temp = new node;
	cout << "\nEnter the node data to be inserted : ";
	cin >> temp->data;
	temp->prev = tail;
	temp->next = NULL;
	tail->next = temp;
	tail = temp;
	cout << "Inserted at end!" << endl;
}

/***************************************************
	Insert at Beginning Function
****************************************************/
void DoublyLinkedList::insert_at_begin()
{
	temp = new node;
	cout << "\nEnter the node data to be inserted : ";
	cin >> temp->data;
	temp->next = head;
	head->prev = temp;
	head = temp;
	cout << "Inserted at beginning!" << endl;
}

/***************************************************
	Insert at a Location Function
****************************************************/
void DoublyLinkedList::insert_at_loc()
{
	temp = new node;
	int loc;
	cout << "\nEnter the location for new node : ";
	cin >> loc;
	ptr = head;
	for (int i = 1; i < loc - 1; i++)
	{
		ptr = ptr->next;
	}
	if(ptr==head)
		insert_at_begin();
	else if(ptr==tail)
		insert_at_end();
	else
	{
		cout << "Enter the node data to be inserted : ";
		cin >> temp->data;
		temp->next = ptr->next;
		temp->prev = ptr;
		ptr->next->prev = temp;
		ptr->next = temp;
		cout << "Inserted at location "<<loc<<"!" << endl;
	}
}

/*******************************************
	Delete at End Function
********************************************/
void DoublyLinkedList::delete_at_end()
{
	if(head==tail)
	{
		delete tail;
		head = NULL;
	}
	else
	{
		temp = tail->prev;
		delete temp->next;
		temp->next = NULL;
		tail = temp;
		cout << "\nDeleted one node from end!" << endl;
	}
}

/**************************************************
	Delete at Beginning Function
***************************************************/
void DoublyLinkedList::delete_at_begin()
{
	if(head==tail)
	{
		delete tail;
		head = NULL;
	}
	else
	{
		temp = head;
		head = head->next;
		head->prev = NULL;
		delete temp;
		cout << "\nDeleted one node from beginning!" << endl;
	}
}

/***************************************************
	Delete at a Location Function
****************************************************/
void DoublyLinkedList::delete_at_loc()
{
	int loc;
	cout << "\nEnter the location of node to delete : ";
	cin >> loc;
	ptr = head;
	for (int i = 1; i < loc - 1; i++)
	{
		ptr = ptr->next;
	}
	temp = ptr->next;
	if(ptr == head)
		delete_at_begin();
	else if(temp == tail)
		delete_at_end();
	else
	{
		ptr->next = temp->next;
		temp->next->prev = ptr;
		delete temp;
		cout << "\nDeleted the node at location " << loc << "!" << endl;
	}
}

/******************************************
	Count Function
*******************************************/
void DoublyLinkedList::count()
{
	int count = 0;
	ptr = head;
	while (ptr != NULL)
	{
		ptr = ptr->next;
		++count;
	}
	cout << "\nThere are " << count << " nodes in the list." << endl;
}

/******************************************
	Search Function
*******************************************/
void DoublyLinkedList::search()
{
	int n, count = 0, flag = 0;
	cout << "\nEnter the node data to be searched : ";
	cin >> n;
	ptr = head;
	while (ptr != NULL)
	{
		++count;
		if (ptr->data == n)
		{
			flag = 1;
			break;
		}
		ptr = ptr->next;
	}
	if (flag == 1)
		cout << "Data found at location " << count << " in the list." << endl;
	else
		cout << "Data not found in the list.";
}


/******************************************
	Main Function
*******************************************/
int main()
{
	int choice;
	char ch;
	DoublyLinkedList list;
	do
	{
		cout << "\n1. Create\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Location\n5. Delete at Beginning\n6. Delete at End\n7. Delete at Location\n8. Count the nodes\n9. Search\n10. Display\n11. Exit" << endl;
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
			list.display();
			break;
		case 12:
			exit(0);
		}
		cout << "\nWant to operate more? (y/n) ";
		cin >> ch;
	} while (ch == 'y');
}