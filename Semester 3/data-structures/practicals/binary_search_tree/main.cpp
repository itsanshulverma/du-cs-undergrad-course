/*
    Written by Anshul Verma
*/

#include <iostream>
#include "stack_ll.h"
#include "queue.h"
using namespace std;

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
    BST(){ root = nullptr; }

    void insert(T n)
    {
        node *newNode = new node(n);
        node *temp, *ptr = root;
        if (root == nullptr) root = newNode;
        else
        {
            while (ptr != nullptr)
            {
                temp = ptr;
                if (n >= ptr->data) ptr = ptr->right;
                else ptr = ptr->left;
            }
            if (n >= temp->data)
                temp->right = newNode;
            else
                temp->left = newNode;
        }
        cout << "Node<" << n << "> Inserted!" << endl;
    }

    void search(T n)
    {
        node *temp, *ptr = root;
        if (root == nullptr) cout << "Tree Empty!";
        else
        { 
            int count = 0;
            while (ptr != nullptr)
            {
                if (n == ptr->data)
                {
                    cout << "\nNode found at level: " << count;
                    return;
                }
                else if (n > ptr->data) ptr = ptr->right;
                else ptr = ptr->left;
                ++count;
            }
            cout << "\nNode not found in tree!";
        }
    }

    void recursive_inorder(node *ptr)
    {
        if (ptr == nullptr) return;
        else
        {
            recursive_inorder(ptr->left);
            cout << ptr->data << " ";
            recursive_inorder(ptr->right);
        }
    }
    void recursive_preorder(node *ptr)
    {
        if (ptr == nullptr) return;
        else
        {
            cout << ptr->data << " ";
            recursive_preorder(ptr->left);
            recursive_preorder(ptr->right);
        }
    }
    void recursive_postorder(node *ptr)
    {
        if (ptr == nullptr) return;
        else
        {
            recursive_postorder(ptr->left);
            recursive_postorder(ptr->right);
            cout << ptr->data << " ";
        }
    }

    node* get_root()
    {
        return this->root;
    }

    void iterative_inorder()
    {
        Stack<node*> stack;
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
        Stack<node*> stack;
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
        Stack<node*> stack;
        node *ptr = root;
        node *temp = root;
        while(ptr != nullptr)
        {
        	for(; ptr->left != nullptr; ptr=ptr->left)
        		stack.push(ptr);
        	while(ptr != nullptr && (ptr->right == nullptr || ptr->right == temp))
        	{
        		temp = ptr;
        		cout << ptr->data << " ";
        		if(stack.isempty())
        			return;
        		ptr = stack.pop();
        	}
        	stack.push(ptr);
        	ptr = ptr->right;
        }
    }
    
    int height()
    {
    	return height_helper(root);
    }
    int height_helper(node *temp)
    {
    	int hleft = 0;
    	int hright = 0;
    	if(temp != nullptr)
    	{
    		hleft = height_helper(temp->left);
    		hright = height_helper(temp->right);
    		if(hleft > hright)
    			return hleft + 1;
    		else
    			return hright + 1;
    	}
    	return -1;
    }
    
    void BFS()
    {
    	Queue<node*> q;
    	node *ptr = root;
    	if(ptr != nullptr)
    	{
    		q.enqueue(ptr);
    		while(!q.isempty())
    		{
    			ptr = q.dequeue();
    			cout << ptr->data << " ";
    			if(ptr->left != nullptr)
    				q.enqueue(ptr->left);
    			if(ptr->right != nullptr)
    				q.enqueue(ptr->right);
    		}
    	}
    }
};

int main()
{
    BST<int> bst;
    bst.insert(30);
    bst.insert(18);
    bst.insert(43);
    bst.insert(10);
    bst.insert(25);
    bst.insert(48);
    bst.insert(32);
    cout << "Inorder: ";
    bst.iterative_inorder(); //10 18 25 30 32 43 48
    cout << endl << "Preorder: ";
    bst.iterative_preorder(); //30 18 10 25 43 32 48
    cout << endl << "Postorder: ";
    bst.iterative_postorder(); //10 25 18 32 48 43 
    cout << endl << "BFS: ";
    bst.BFS();
    bst.search(32);
    cout << endl << "Height: " << bst.height();
    return 0;
}