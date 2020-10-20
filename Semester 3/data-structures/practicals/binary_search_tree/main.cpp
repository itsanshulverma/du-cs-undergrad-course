/*
    Written by Anshul Verma
*/

#include <iostream>
#include "stack_ll.h"
#include "queue.h"
using namespace std;

/*
	Binary Search Tree Class
*/
template <typename T>
class BST
{
	class node
	{
	  public:
		node *left, *right;
		T data;
		node(T n)
		{
			this->data = n;
			this->left = this->right = nullptr;
		}
	};

  public:
	node *root;
	int leafs, nonLeafs;
	BST()
	{
		root = nullptr;
		leafs = 0;
		nonLeafs = 0;
	}

	/*
		Insert
	*/
	void insert(T n)
	{
		node *newNode = new node(n);
		node *temp, *ptr = root;
		if (root == nullptr)
			root = newNode;
		else
		{
			while (ptr != nullptr)
			{
				temp = ptr;
				if (n >= ptr->data)
					ptr = ptr->right;
				else
					ptr = ptr->left;
			}
			if (n >= temp->data)
				temp->right = newNode;
			else
				temp->left = newNode;
		}
		cout << "Node<" << n << "> Inserted!";
	}

	/*
		Search
	*/
	void search(T n)
	{
		node *temp, *ptr = root;
		if (root == nullptr)
			cout << "Tree Empty!";
		else
		{
			int count = 1;
			while (ptr != nullptr)
			{
				if (n == ptr->data)
				{
					cout << "Node found at level: " << count;
					return;
				}
				else if (n > ptr->data)
					ptr = ptr->right;
				else
					ptr = ptr->left;
				++count;
			}
			cout << "Node not found in tree!";
		}
	}

	/*
		Recursive DFS Traversal
	*/
	void recursive_inorder(node *ptr)
	{
		if (ptr == nullptr)
			return;
		else
		{
			recursive_inorder(ptr->left);
			cout << ptr->data << " ";
			recursive_inorder(ptr->right);
		}
	}
	void recursive_preorder(node *ptr)
	{
		if (ptr == nullptr)
			return;
		else
		{
			cout << ptr->data << " ";
			recursive_preorder(ptr->left);
			recursive_preorder(ptr->right);
		}
	}
	void recursive_postorder(node *ptr)
	{
		if (ptr == nullptr)
			return;
		else
		{
			recursive_postorder(ptr->left);
			recursive_postorder(ptr->right);
			cout << ptr->data << " ";
		}
	}
	node *get_root()
	{
		return this->root;
	}

	/*
		Iterative DFS Traversals
	*/
	void iterative_inorder()
	{
		Stack<node *> stack;
		node *ptr = root;
		while (ptr != nullptr || !stack.isempty())
		{
			if (ptr != nullptr)
			{
				stack.push(ptr);
				ptr = ptr->left;
			}
			else
			{
				ptr = stack.pop();
				cout << ptr->data << " ";
				ptr = ptr->right;
			}
		}
	}
	void iterative_preorder()
	{
		Stack<node *> stack;
		node *ptr = root;
		while (ptr != nullptr || !stack.isempty())
		{
			if (ptr != nullptr)
			{
				cout << ptr->data << " ";
				stack.push(ptr);
				ptr = ptr->left;
			}
			else
			{
				ptr = stack.pop();
				ptr = ptr->right;
			}
		}
	}
	void iterative_postorder()
	{
		Stack<node *> stack;
		node *ptr = root;
		node *temp = root;
		while (ptr != nullptr)
		{
			for (; ptr->left != nullptr; ptr = ptr->left)
				stack.push(ptr);
			while (ptr != nullptr && (ptr->right == nullptr || ptr->right == temp))
			{
				temp = ptr;
				cout << ptr->data << " ";
				if (stack.isempty())
					return;
				ptr = stack.pop();
			}
			stack.push(ptr);
			ptr = ptr->right;
		}
	}

	/*
		Calculating height of tree
	*/
	int height()
	{
		return height_helper(root);
	}
	int height_helper(node *temp)
	{
		int hleft = 0;
		int hright = 0;
		if (temp != nullptr)
		{
			hleft = height_helper(temp->left);
			hright = height_helper(temp->right);
			if (hleft > hright)
				return hleft + 1;
			else
				return hright + 1;
		}
		return -1;
	}

	/*
		Breadth-First Traversal
	*/
	void BFS()
	{
		Queue<node *> q;
		node *ptr = root;
		if (ptr != nullptr)
		{
			q.enqueue(ptr);
			while (!q.isempty())
			{
				ptr = q.dequeue();
				cout << ptr->data << " ";
				if (ptr->left != nullptr)
					q.enqueue(ptr->left);
				if (ptr->right != nullptr)
					q.enqueue(ptr->right);
			}
		}
	}

	/*
		BFS Mirror Image
	*/
	void printMirrorImage()
	{
		Queue<node *> q;
		node *ptr = root;
		if (ptr != nullptr)
		{
			q.enqueue(ptr);
			while (!q.isempty())
			{
				ptr = q.dequeue();
				cout << ptr->data << " ";
				if (ptr->right != nullptr)
					q.enqueue(ptr->right);
				if (ptr->left != nullptr)
					q.enqueue(ptr->left);
			}
		}
	}
	
	/*
		Counting Nodes
	*/
	void count(node *temp)
	{
		if (temp != nullptr)
		{
			if (temp->left != nullptr || temp->right != nullptr)
				nonLeafs++;
			if (temp->left == nullptr && temp->right == nullptr)
				leafs++;
			count(temp->left);
			count(temp->right);
		}
	}
	void printCount()
	{
		count(this->root);
		cout << "\nNo. of leaf nodes: " << this->leafs;
		cout << "\nNo. of non-leaf nodes: " << this->nonLeafs;
		cout << "\nTotal no. of nodes: " << this->leafs + this->nonLeafs;
	}

	/*
		Delete by Copying
	*/
	void del_copy(T el)
	{
		node *prev;
		node *ptr = root;
		while (ptr != nullptr)
		{
			if (ptr->data == el)
				break;
			prev = ptr;
			if (ptr->data < el)
				ptr = ptr->right;
			else
				ptr = ptr->left;
		}
		if (ptr != nullptr && ptr->data == el)
		{
			if (ptr == root)
				delc(root);
			else if (prev->left == ptr)
				delc(prev->left);
			else
				delc(prev->right);
		}
		else if (root != 0)
			cout << "\nNode not found in the tree!";
		else
			cout << "\n\tTree is Empty!";
	}
	void delc(node *&temp)
	{
		node *prev, *tmp = temp;
		if (temp->right == NULL)
			temp = temp->left;
		else if (temp->left == NULL)
			temp = temp->right;
		else
		{
			tmp = temp->left;
			prev = temp;
			while (tmp->right != NULL)
			{
				prev = tmp;
				tmp = tmp->right;
			}
			temp->data = tmp->data;
			if (prev == temp)
				prev->left = tmp->left;
			else
				prev->right = tmp->left;
		}
		delete tmp;
	}

	/*
		Delete by Merging
	*/
	void del_merge(T el)
	{
		node *prev;
		node *ptr = root;
		while (ptr != nullptr)
		{
			if (ptr->data == el)
				break;
			prev = ptr;
			if (ptr->data < el)
				ptr = ptr->right;
			else
				ptr = ptr->left;
		}
		if (ptr != nullptr && ptr->data == el)
		{
			if (ptr == root)
				delm(root);
			else if (prev->left == ptr)
				delm(prev->left);
			else
				delm(prev->right);
		}
		else if (root != 0)
			cout << "\nNode not found in the tree";
		else
			cout << "\n\tTree is Empty!";
	}
	void delm(node *&temp)
	{
		node *tmp = temp;
		if (temp != NULL)
		{
			if (temp->right == NULL)
				temp = temp->left;
			else if (temp->left == NULL)
				temp = temp->right;
			else
			{
				tmp = temp->left;
				while (tmp->right != NULL)
				{
					tmp = tmp->right;
				}
				tmp->right = temp->right;
				tmp = temp;
				temp = temp->left;
			}
			delete tmp;
		}
	}

	/*
		Search for an element in BST and change its value to y then reorder BST accordingly
	*/
	void search_change()
	{
		int key, newKey;
		cout << "\nEnter the key to be searched: ";
		cin >> key;
		node *ptr = root;
		if (ptr == nullptr)
			cout << "Tree Empty!";
		else
		{
			cout << "Enter the new key: ";
			cin >> newKey;
			
			int flag = 0;
			while (ptr != nullptr)
			{
				if (key == ptr->data)
				{
					flag = 1;
					break;
				}
				else if (key > ptr->data)
					ptr = ptr->right;
				else
					ptr = ptr->left;
			}
			if (flag == 0)
				cout << "Node not found in tree!";
			else
			{
				del_copy(key);
				insert(newKey);
			}
		}
	}
};

/*
	Main Function
*/
int main()
{
	BST<int> bst;
	//bst.insert(30);
	//bst.insert(18);
	//bst.insert(43);
	//bst.insert(10);
	//bst.insert(25);
	//bst.insert(48);
	//bst.insert(32);

	cout << "\nBinary Search Tree Implementation\n";

	int choice, temp;
	char ch = 'y';
	do
	{
		cout << "\n---------- Menu ----------";
		cout << "\n1. Insert";
		cout << "\n2. Seach a node";
		cout << "\n3. Recursive Depth-First Traversals";
		cout << "\n4. Iterative Depth-First Traversals";
		cout << "\n5. Breadth First Traversal";
		cout << "\n6. Mirror Image (BFS)";
		cout << "\n7. Count nodes";
		cout << "\n8. Search a node, change its value, update the BST";
		cout << "\n9. Height of the tree";
		cout << "\n10. Delete by merging";
		cout << "\n11. Delete by copying";

		cout << "\n\nEnter your choice: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			cout << "Enter a node: ";
			cin >> temp;
			bst.insert(temp);
			break;
		case 2:
			cout << "\nEnter a node to be searched: ";
			cin >> temp;
			bst.search(temp);
			break;
		case 3:
			cout << "\nRecursive Inorder: ";
			bst.recursive_inorder(bst.get_root());
			cout << "\nRecursive Preorder: ";
			bst.recursive_preorder(bst.get_root());
			cout << "\nRecursive Postorder: ";
			bst.recursive_postorder(bst.get_root());
			break;
		case 4:
			cout << "\nIterative Inorder: ";
			bst.iterative_inorder();
			cout << "\nIterative Preorder: ";
			bst.iterative_preorder();
			cout << "\nIterative Postorder: ";
			bst.iterative_postorder();
			break;
		case 5:
			cout << "\nBreadth First Traversal: ";
			bst.BFS();
			break;
		case 6:
			cout << "\nBFS Mirror Image: ";
			bst.printMirrorImage();
			break;
		case 7:
			bst.printCount();
			break;
		case 8:
			bst.search_change();
			break;
		case 9:
			cout << "\nHeight of tree: " << bst.height();
			break;
		case 10:
			cout << "\nEnter the node value you want to delete: ";
			cin >> temp;
			bst.del_merge(temp);
			break;
		case 11:
			cout << "\nEnter the node value you want to delete: ";
			cin >> temp;
			bst.del_copy(temp);
			break;
		default:
			cout << "\nInvalid Choice!";
		}
		cout << "\n\nWant to continue? (Y/N): ";
		cin >> ch;
	} while (ch == 'y' || ch == 'Y');
	return 0;
}