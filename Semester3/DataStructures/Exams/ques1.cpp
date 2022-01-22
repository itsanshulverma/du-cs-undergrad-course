/*
    1. Create two singly linked lists and merge them in descending order.
    Written By Anshul Verma (19/78065)
*/

#include <iostream>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

/* SinglyLinkedList Class */
class SinglyLinkedList
{
    public:
	struct node *head, *temp, *ptr, *tail;
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
	bool is_empty()
    {
        if (head == NULL)
            return true;
        else
            return false;
    }
	void insert_at_end(int n)
    {
        temp = new node;
        temp->data = n;
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
    }
	void display()
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
};

// Function to merge two lists
void mergeLists(SinglyLinkedList &list1, SinglyLinkedList &list2)
{
    cout << "\nFirst List: ";
    list1.display();
    cout << "\nSecond List: ";
    list2.display();

    // Checking for NULL conditions
    if(list1.head != NULL || list2.head != NULL)
    {
        if(list1.head == NULL && list2.head != NULL)
            list1 = list2;
        else if(list1.head != NULL && list2.head != NULL)
        {
            list1.tail->next = list2.head;
            list1.tail = list2.tail;
        }

        // Sort the linked list1 using bubble sort
        node* curr = list1.head;
        node* temp = list1.head;
        while (curr->next != NULL) {
            temp = curr->next;
            while (temp != NULL) {
                if (temp->data > curr->data) {
                    int t = temp->data;
                    temp->data = curr->data;
                    curr->data = t;
                }
                temp = temp->next;
            }
            curr = curr->next;
        }       
    }
    cout << "\nMerged List: ";
    list1.display();
}

// Main function
int main()
{
	SinglyLinkedList s1, s2;
    s1.insert_at_end(20);
    s1.insert_at_end(10);
    s1.insert_at_end(15);
    s1.insert_at_end(30);
    s1.insert_at_end(50);
    s2.insert_at_end(60);
    s2.insert_at_end(80);
    s2.insert_at_end(100);
    s2.insert_at_end(45);
    mergeLists(s1, s2);

    cout << endl;
	return 0;
}
