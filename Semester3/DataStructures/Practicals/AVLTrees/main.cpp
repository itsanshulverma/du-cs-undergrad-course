#include <iostream>
using namespace std;

template <typename T>
class AVL
{
    class Node
    {
        public:
        T data;
        int bfactor;
        Node *parent, *left, *right;
        Node(T data)
        {
            this->data = data;
            this->bfactor = 0;
            this->parent = nullptr;
            this->left = nullptr;
            this->right = nullptr;
        }
    };

    public:
    Node *root;
    AVL() { root = nullptr; }

    int max(int x, int y)
    {
        return (x > y) ? x : y;
    }

    Node *leftmostNode(Node *node) {
		while (node->left != nullptr) {
			node = node->left;
		}
		return node;
	}

    void leftRotate(Node* x) {
	    Node* y = x->right;
	    x->right = y->left;
	    if (y->left != nullptr) {
		    y->left->parent = x;
	    }
	    y->parent = x->parent;
	    if (x->parent == nullptr) {
		    this->root = y;
	    } else if (x == x->parent->left) {
		    x->parent->left = y;
	    } else {
		    x->parent->right = y;
	    }
	    y->left = x;
	    x->parent = y;

	    // update the balance factor
	    x->bfactor = x->bfactor - 1 - max(0, y->bfactor);
	    y->bfactor = y->bfactor - 1 + min(0, x->bfactor);
    }

    // rotate right at node x
    void rightRotate(Node* x) {
	    Node* y = x->left;
	    x->left = y->right;
	    if (y->right != nullptr) {
		    y->right->parent = x;
	    }
	    y->parent = x->parent;
	    if (x->parent == nullptr) {
		    this->root = y;
	    } else if (x == x->parent->right) {
		    x->parent->right = y;
	    } else {
		    x->parent->left = y;
	    }
	    y->right = x;
	    x->parent = y;

	    // update the balance factor
	    x->bfactor = x->bfactor + 1 - min(0, y->bfactor);
	    y->bfactor = y->bfactor + 1 + max(0, x->bfactor);
    }

    void updateBalance(Node *node)
    {
        if (node->parent != nullptr) {
			if (node == node->parent->left) {
				node->parent->bfactor -= 1;
			} 

			if (node == node->parent->right) {
				node->parent->bfactor += 1;
			}

			if (node->parent->bfactor != 0) {
				updateBalance(node->parent);
			}
		}
    }

    void insert (T n)
    {
        // Normal BST Insertion 
        Node *newNode = new Node(n);
		Node *temp = nullptr, *ptr = this->root;
		if (ptr == nullptr)
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

            newNode->parent = temp;
			if (n >= temp->data)
                temp->right = newNode;
			else
                temp->left = newNode;
		} 

		Node *node = newNode;
		if (node->bfactor < -1 || node->bfactor > 1) 
		{
			if (node->bfactor > 0) {
			    if (node->right->bfactor < 0) {
				    rightRotate(node->right);
				    leftRotate(node);
			    }
                else 
                {
				    leftRotate(node);
			    }
		    } else if (node->bfactor < 0) {
			    if (node->left->bfactor > 0) {
				    leftRotate(node->left);
				    rightRotate(node);
			    }
                else
                {
				    rightRotate(node);
			    }
			}
			return;
		}
		updateBalance(newNode);
    }

	/*
		Delete by Copying
	*/
	void del_copy(T el)
	{
		Node *prev;
		Node *ptr = root;
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

		Node* node = ptr->parent;
		
		// if (node->bfactor > 1)
		// {
		// 	if(node->left->bfactor >= 0)
		// 	{
		// 		rightRotate(root);
		// 	}
		// }

		updateBalance(prev);
	}
	void delc(Node *&temp)
	{
		Node *prev, *tmp = temp;
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
        Print Tree function borrowed from (https://www.programiz.com/dsa/avl-tree)
    */
    void printT(string prefix, Node* node, bool isLeft)
    {
        if( node != nullptr )
        {
            cout << prefix;

            cout << (isLeft ? "L----- " : "R----- ");

            // print the value of the node
            cout << node->data << " (bf=" << node->bfactor <<")" << endl;

            // enter the next tree level - left and right branch
            printT( prefix + (isLeft ? "|   " : "    "), node->left, true);
            printT( prefix + (isLeft ? "|   " : "    "), node->right, false);
        }
    }
    void printTree()
    {
        cout << endl;
    	printT("  ", root, false); 
        cout << endl;  
    }

    Node *search(T n)
	{
		Node *temp, *ptr = root;
		if (root == nullptr)
			cout << "Tree Empty!";
		else
		{
			while (ptr != nullptr)
			{
				if (n == ptr->data)
				{
					return ptr;
				}
				else if (n > ptr->data)
					ptr = ptr->right;
				else
					ptr = ptr->left;
			}
			cout << "Node not found in tree!";
		}
        return ptr;
	}
};

int main()
{
    AVL<int> avl;
    avl.insert(9);
    avl.insert(15);
    avl.insert(20);
    avl.insert(8);
    avl.insert(7);
    avl.insert(13);
    avl.insert(10);
    avl.printTree();
/*
	Output

  R----- 9 (bf=1)
      L----- 8 (bf=-1)
      |   L----- 7 (bf=0)
      R----- 15 (bf=-1)
          L----- 13 (bf=-1)
          |   L----- 10 (bf=0)
          R----- 20 (bf=0)
*/
    
}