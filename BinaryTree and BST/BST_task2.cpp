// Tree Traversal Algorithms

// Consider the BST given in Task 1 and write the following functions:
// Inorder
// Preorder
// Postorder
// Level_order

// Insert the numbers using the ‘Binary Search Tree (BST)’ policy. The first line of input will contain N, followed by N integers to be inserted in the BST. Do not write a recursive function for insertion. But can write for traversal algorithms.

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

    void inorderPrint(Node *x)
    {
        if (x == nullptr)
            return;
        inorderPrint(x->left);
        cout << x->data;
        if (x->parent)
        {
            cout << '(' << x->parent->data << ") ";
        }
        else
        {
            cout << "(null) ";
        }
        inorderPrint(x->right);
    }

    void preorderPrint(Node *x)
    {
        if (x == nullptr)
            return;
        cout << x->data;
        if (x->parent)
        {
            cout << '(' << x->parent->data << ") ";
        }
        else
        {
            cout << "(null) ";
        }
        preorderPrint(x->left);
        preorderPrint(x->right);
    }

    void postorderPrint(Node *x)
    {
        if (x == nullptr)
            return;
        postorderPrint(x->left);
        postorderPrint(x->right);
        if (x == nullptr)
            return;
        cout << x->data;
        if (x->parent)
        {
            cout << '(' << x->parent->data << ") ";
        }
        else
        {
            cout << "(null) ";
        }
    }

    void levelOrderPrint()
    {
        if (!head)
        {
            return;
        }

        queue<Node *> q;
        q.push(head);

        while (!q.empty())
        {
            int levelSize = q.size();
            cout << "Level " << head->height - q.front()->height + 1 << ": ";

            while (levelSize--)
            {
                Node *temp = q.front();
                q.pop();
                cout << temp->data;

                if (temp->parent)
                {
                    cout << '(' << temp->parent->data << ") ";
                }
                else
                {
                    cout << "(null) ";
                }

                if (temp->left)
                {
                    q.push(temp->left);
                }
                if (temp->right)
                {
                    q.push(temp->right);
                }
            }

            cout << endl;
        }
    }
};

int main()
{
    BST tree;
    vector<vector<int>> v;
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        tree.insert(x);
    }
    int x;
    while (cin >> x)
    {
        if (x == 1)
            tree.inorderPrint(tree.getHead());
        else if (x == 2)
            tree.preorderPrint(tree.getHead());
        else if (x == 3)
            tree.postorderPrint(tree.getHead());
        else if (x == 4)
            tree.levelOrderPrint();
        cout << endl;
    }
}
