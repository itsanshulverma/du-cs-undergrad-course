/*
    Written by Anshul Verma
*/

#include <iostream>
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
        cout << "Node Inserted!" << endl;
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
    bst.recursive_inorder(bst.get_root()); //10 18 25 30 32 43 48
    cout << endl << "Preorder: ";
    bst.recursive_preorder(bst.get_root()); //30 18 10 25 43 32 48
    cout << endl << "Postorder: ";
    bst.recursive_postorder(bst.get_root()); //10 25 18 32 48 43 30
    return 0;
}