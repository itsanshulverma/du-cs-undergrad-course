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
	struct node *head, *temp, *ptr, *tail;
	public:
	SinglyLinkedList()
	{
		head=NULL;
	}
	~SinglyLinkedList()
	{
		cout<<"\nDeallocating memory...\n";
		ptr = head;
		while(ptr != NULL)
		{
			temp = ptr->next;
			delete ptr;
			ptr = temp;
		}
	}
	void create();
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
	int loc;
	cout<<"\nEnter the location for new node : ";
	cin>>loc;
	cout<<"Enter the node data : ";
	cin>>temp->data;
	ptr = head;
	for(int i=1; i<loc-1; i++)
	{
		ptr = ptr->next;
	}
	temp->next = ptr->next;
	ptr->next = temp;
	cout<<"Inserted!"<<endl;
}
void SinglyLinkedList::delete_at_end()
{
	ptr = head;
	while(ptr->next->next != NULL)
	{
		ptr = ptr->next;
	}
	delete ptr->next;
	ptr->next = NULL;
	tail = ptr;
	cout<<"\nDeleted one node from end!"<<endl;
}
void SinglyLinkedList::delete_at_begin()
{
	temp = head;
	head = head->next;
	delete temp;
	cout<<"\nDeleted one node from beginning!"<<endl;
}
void SinglyLinkedList::delete_at_loc()
{
	int loc;
	cout<<"\nEnter the location of node to delete : ";
	cin>>loc;
	ptr = head;
	for(int i=1; i<loc-1; i++)
	{
		ptr = ptr->next;
	}
	temp = ptr->next;
	ptr->next = ptr->next->next;
	delete temp;
	cout<<"\nDeleted from location : "<<loc<<"!"<<endl;
}
void SinglyLinkedList::count()
{
	int count=0;
	ptr=head;
	while(ptr != NULL)
	{
		ptr = ptr->next;
		++count;
	}
	cout<<"\nThere are "<<count<<" nodes in the list."<<endl;
}
void SinglyLinkedList::search()
{
	int n, count=0, flag=0;
	cout<<"\nEnter the node data to be searched : ";
	cin>>n;
	ptr = head;
	while(ptr != NULL)
	{
		++count;
		if(ptr->data == n)
		{
			flag=1;
			break;
		}
		ptr = ptr->next;
	}
	if(flag=1)
		cout<<"Data found at location "<<count<<" in the list."<<endl;
	else
		cout<<"Data not found in the list.";
}
void SinglyLinkedList::reverse()
{
	 ptr=head->next;
	 head->next = NULL;
	 tail = head;
	 while(ptr!= NULL)
	 {
	 	temp = ptr;
	 	ptr=ptr->next;
	 	temp->next = head;
		 head = temp;
	 }
	 cout<<"\nReversed!"<<endl;
	 display();
}

int main()
{
	int choice;
	char ch;
	SinglyLinkedList list;
	do
	{
		cout<<"\n1. Create\n2. Insert at Beginning\n3. Insert at End\n4. Insert at Location\n5. Delete at Beginning\n6. Delete at End\n7. Delete at Location\n8. Count the nodes\n9. Search\n10. Reverse the list\n11. Display\n12. Exit"<<endl;
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
				list.delete_at_begin();
				break;
			case 6:
				list.delete_at_end();
				break;
			case 7:
				list.delete_at_loc();
				break;
			case 8:
				list.count();
				break;
			case 9:
				list.search();
				break;
			case 10:
				list.reverse();
				break;
			case 11:
				list.display();
				break;
			case 12:
				exit(0);
		}
		cout<<"\nWant to operate more? (y/n) ";
		cin>>ch;
	}while(ch=='y');
}
