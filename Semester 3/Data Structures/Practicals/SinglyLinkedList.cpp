// By Anshul Verma
// 19/78065

#include <iostream>

using namespace std;

class SinglyLinkedList
{
	struct node
	{
		int data;
		struct node* next;
	};
	struct node *head, *ptr, *temp, *tail;
	public:
	SinglyLinkedList()
	{
		head=NULL;
	}
	void create();
	void insert_at_end();
	void insert_at_begin();
	void insert_at_loc();
	void display();
};
void SinglyLinkedList::create()
{
	int n;
	char ch = 'y';
	do
	{
		temp = new node;
		temp->next = NULL;
		cout<<"\nEnter the node data : ";
		cin>>n;
		if(head==NULL)
		{
			head = temp;
			head->data = n;
			head->next = NULL;
			tail = head;
		}
		else
		{
			temp->data = n;
			tail->next = temp;
			tail = temp;
		}
		cout<<"Want to enter more nodes ? (y/n) : ";
		cin>>ch;
	}while(ch=='y');
}
void SinglyLinkedList::display()
{
	cout<<"\n\t";
	if(head==NULL)
		cout<<"Linked List is empty.";
	struct node *ptr;
	ptr = head;
	while(ptr != NULL)
	{
		cout<<"-->"<<ptr->data;
		ptr = ptr->next;
	}
	cout<<endl;
}
void SinglyLinkedList::insert_at_end()
{
	temp = new node;
	cout<<"\nEnter the node data you want to insert at end : ";
	cin>>temp->data;
	temp->next = NULL;
	tail->next = temp;
	tail = temp;
	cout<<"Inserted!"<<endl;
}
void SinglyLinkedList::insert_at_begin()
{
	temp = new node;
	cout<<"\nEnter the node data you want to insert at beginning : ";
	cin>>temp->data;
	temp->next = head;
	head = temp;
	cout<<"Inserted!"<<endl;
}
void SinglyLinkedList::insert_at_loc()
{
	temp = new node;
	int loc, i;
	cout<<"\nEnter the location for new node : ";
	cin>>loc;
	cout<<"Enter the node data : ";
	cin>>temp->data;
	ptr = head->next;
	while(i<loc-1)
	{
		ptr = ptr->next;
	}
	temp->next = ptr->next;
	ptr->next = temp;
	cout<<"Inserted!"<<endl;
}

int main()
{
	int choice;
	char ch;
	SinglyLinkedList list;
	do
	{
		cout<<"\n1. Create\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Location\n5. Display\n6. Exit"<<endl;
		cout<<"Enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				list.create();
				break;
			case 2:
				list.insert_at_begin();
				break;
			case 3:
				list.insert_at_end();
				break;
			case 4:
				list.insert_at_loc();
				break;
			case 5:
				list.display();
				break;
			case 6:
				exit(0);
		}
		cout<<"\nWant to operate more? (y/n) ";
		cin>>ch;
	}while(ch=='y');
}
