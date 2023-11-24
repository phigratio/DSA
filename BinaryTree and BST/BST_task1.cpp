// Task 1: Basic Implementations

// Implement the basic operations of a Binary Tree. Your program should include the following functions:
// Insert: Insert the given numbers using the ‘Binary Search Tree (BST)’ policy. The first line of input will contain N, followed by N integers to be inserted in the BST. Do not write a recursive function.
// Print_tree: After insertion, print the tree status using Inorder traversal. Note that the inorder traversal of a BST will always show the nodes in sorted order. (If not, there must be an error in the insertion algorithm.)
// Search: Returns the node if it is present and prints its description. Otherwise, print ‘Not Found’.
// Height: Given a value, search it and return the height of that node (if present). The height of a leaf node is 0. Write the insertion procedure in such a way that it considers height as an attribute for each node and updates height during insertion. Do not write the recursive height function.

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    int height = 0;
    Node *parent;
    Node *left;
    Node *right;
    Node(int val) : data(val), parent(nullptr), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *head = nullptr;

public:
    Node *getHead()
    {
        return head;
    }
    int getHeight(Node *x)
    {
        return x->height;
    }
    int getData(Node *x)
    {
        if (x)
            return x->data;
        else
            return -1;
    }
    void insert(int val)
    {
        Node *new_node = new Node(val);
        if (!head)
        {
            head = new_node;
        }
        else
        {
            Node *temp = head;
            while (temp)
            {
                if (new_node->data < temp->data)
                {
                    if (temp->left == nullptr)
                    {
                        new_node->parent = temp;
                        temp->left = new_node;
                        break;
                    }
                    temp = temp->left;
                }
                else
                {
                    if (temp->right == nullptr)
                    {
                        new_node->parent = temp;
                        temp->right = new_node;
                        break;
                    }
                    temp = temp->right;
                }
            }
        }
        Node *run_back = new_node;
        int h = 0;
        while (run_back != head)
        {
            h++;
            run_back = run_back->parent;
            run_back->height = max(h, run_back->height);
        }
    }

    void inorderPrint()
    {
        Node *temp = head;
        stack<Node *> s;

        while (temp || !s.empty())
        {
            while (temp)
            {
                s.push(temp);
                temp = temp->left;
            }

            temp = s.top();
            s.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }

    Node *bstSearch(int key)
    {
        Node *temp = head;
        while (temp)
        {
            if (temp->data > key)
            {
                temp = temp->left;
            }
            else if (temp->data < key)
            {
                temp = temp->right;
            }
            else
            {
                return temp;
            }
        }
        return nullptr;
    }

    void parChild(Node *x)
    {
        (x->parent) ? cout << "Parent(" << x->parent->data << "), " : cout << "Parent(null), ";
        (x->left) ? cout << "Left(" << x->left->data << "), " : cout << "Left(null), ";
        (x->right) ? cout << "Right(" << x->parent->data << ")" : cout << "Right(null), ";
    }

    Node *findPredecessor(Node *x)
    {
        if (x == nullptr)
            return nullptr;

        if (x->left)
        {
            x = x->left;
            while (x->right)
                x = x->right;
            return x;
        }

        Node *parent = x->parent;
        while (parent && x == parent->left)
        {
            x = parent;
            parent = parent->parent;
        }

        return parent;
    }

    Node *findSuccessor(Node *x)
    {
        if (x == nullptr)
            return nullptr;

        if (x->right)
        {
            x = x->right;
            while (x->left)
                x = x->left;
            return x;
        }

        Node *parent = x->parent;
        while (parent && x == parent->right)
        {
            x = parent;
            parent = parent->parent;
        }

        return parent;
    }
};

int main()
{
    BST tree;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        tree.insert(x);
    }
    tree.inorderPrint();
    cout << endl;
    int q;
    while (cin >> q)
    {
        if (q == 3)
        {
            int val;
            cin >> val;
            if (tree.bstSearch(val))
            {
                cout << "Present" << endl;
                tree.parChild(tree.bstSearch(val));
                cout << endl;
            }
            else
            {
                cout << "Not Present" << endl;
            }
        }
        else if (q == 4)
        {
            int val;
            cin >> val;
            cout << tree.getHeight(tree.bstSearch(val)) << endl;
        }
        else if (q == 5)
        {
            int val;
            cin >> val;
            int x = tree.getData(tree.findPredecessor(tree.bstSearch(val)));
            int y = tree.getData(tree.findSuccessor(tree.bstSearch(val)));
            if (x == -1)
            {
                cout << "null";
            }
            else
                cout << x;
            cout << " ";
            if (y == -1)
            {
                cout << "null";
            }
            else
                cout << y;
            cout << endl;
        }
    }
}
