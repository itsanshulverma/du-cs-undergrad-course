// AVL tree implementation in C++

#include <iostream>
using namespace std;

class Node {
public:
  int key;
  Node *left;
  Node *right;
  int height;
};

/* AVL Tree Class */
class AVLTree{
    public:
    Node *root;
    AVLTree() { root = nullptr; }

    // Calculate height
    int height(Node *N) {
        if (N == NULL)
            return 0;
        return N->height;
    }

    int max(int a, int b) {
        return (a > b) ? a : b;
    }

    // New node creation
    Node *newNode(int key) {
        Node *node = new Node();
        node->key = key;
        node->left = NULL;
        node->right = NULL;
        node->height = 1;
        return (node);
    }

    // Rotate right
    Node *rightRotate(Node *y) {
        Node *x = y->left;
        Node *T2 = x->right;
        x->right = y;
        y->left = T2;
        y->height = max(height(y->left),
                height(y->right)) +
                1;
        x->height = max(height(x->left),
                height(x->right)) +
                1;
        return x;
    }

    // Rotate left
    Node *leftRotate(Node *x) {
        Node *y = x->right;
        Node *T2 = y->left;
        y->left = x;
        x->right = T2;
        x->height = max(height(x->left),
                height(x->right)) +
                1;
        y->height = max(height(y->left),
                height(y->right)) +
                1;
        return y;
    }

    // Get the balance factor of each node
    int getBalanceFactor(Node *N) {
        if (N == NULL)
            return 0;
        return height(N->left) -
            height(N->right);
    }

    // Insert a node - helper
    Node *insert(Node *node, int key) {
        // Find the correct postion and insert the node
        if (node == NULL)
            return (newNode(key));
        if (key < node->key)
            node->left = insert(node->left, key);
        else if (key > node->key)
            node->right = insert(node->right, key);
        else
            return node;

        // Update the balance factor of each node and
        // balance the tree
        node->height = 1 + max(height(node->left), height(node->right));
        int balanceFactor = getBalanceFactor(node);
        if (balanceFactor > 1) {
            if (key < node->left->key) {
                return rightRotate(node);
            } else if (key > node->left->key) {
                node->left = leftRotate(node->left);
                return rightRotate(node);
            }
        }
        if (balanceFactor < -1) {
            if (key > node->right->key) {
                return leftRotate(node);
            } else if (key < node->right->key) {
                node->right = rightRotate(node->right);
                return leftRotate(node);
            }
        }
        return node;
    }

    //Insert a node
    void insertNode(int key)
    {
        root = insert(root, key);
        cout << "\nNode(" << key << ") Inserted!";
    }

    // Node with minimum value
    Node *nodeWithMimumValue(Node *node) {
        Node *current = node;
        while (current->left != NULL)
            current = current->left;
        return current;
    }

    // Delete a node - helper
    Node *del(Node *root, int key) {
        // Find the node and delete it
        if (root == NULL)
            return root;
        if (key < root->key)
            root->left = del(root->left, key);
        else if (key > root->key)
            root->right = del(root->right, key);
        else {
            if ((root->left == NULL) ||
            (root->right == NULL)) {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else
                *root = *temp;
            free(temp);
            } else {
            Node *temp = nodeWithMimumValue(root->right);
            root->key = temp->key;
            root->right = del(root->right,
                        temp->key);
            }
        }

        if (root == NULL)
            return root;

        // Update the balance factor of each node and
        // balance the tree
        root->height = 1 + max(height(root->left),
                    height(root->right));
        int balanceFactor = getBalanceFactor(root);
        if (balanceFactor > 1) {
            if (getBalanceFactor(root->left) >= 0) {
            return rightRotate(root);
            } else {
            root->left = leftRotate(root->left);
            return rightRotate(root);
            }
        }
        if (balanceFactor < -1) {
            if (getBalanceFactor(root->right) <= 0) {
            return leftRotate(root);
            } else {
            root->right = rightRotate(root->right);
            return leftRotate(root);
            }
        }
        return root;
    }

    // Delete a node
    void deleteNode(int key)
    {
        root = del(root, key);
        cout << "\nNode(" << key << ") Deleted!";
    }

    // Print the tree
    void printHelper(Node *root, string indent, bool last) {
        if (root != nullptr) {
            cout << indent;
            if (last) {
            cout << "R----";
            indent += "   ";
            } else {
            cout << "L----";
            indent += "|  ";
            }
            cout << root->key << endl;
            printHelper(root->left, indent, false);
            printHelper(root->right, indent, true);
        }
    }
    void printTree()
    {
        cout << "\n\nResultant AVL Tree:\n\n";
        printHelper(root, "", true);
    }
};

int main() {
  AVLTree avl;
  avl.insertNode(33);
  avl.insertNode(13);
  avl.insertNode(53);
  avl.insertNode(9);
  avl.insertNode(21);
  avl.insertNode(61);
  avl.insertNode(8);
  avl.insertNode(11);
  avl.printTree();
  avl.deleteNode(13);
  cout << "\nAfter deleting " << endl;
  avl.printTree();
}