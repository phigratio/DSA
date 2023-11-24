// Task 3: Tree Diameter

// Given a Binary Search Tree, your task is to find the diameter. The diameter of a tree is the number of nodes in the longest path between any two leaf nodes. The longest path may not be through the root node of the tree. The longest path may be entirely in the left or right subtree, or it may pass through the root node.

// The insertion process in the Binary Tree works as follows-
// Insert:
// Assuming each node contains a unique value.
// Input starts with a number N (representing the number of nodes), followed by N integers in the next line that are to be inserted into the BST.

// Sample Test Case(s)
// Input
// 7
// 4 2 6 1 3 5 7

// Output
// 5

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
        int ind = 0;
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

    void FindLeaves(vector<int> &v, vector<Node *> &vn)
    {
        for (auto x : v)
        {
            Node *temp = bstSearch(x);
            if (temp->left == nullptr && temp->right == nullptr)
                vn.push_back(temp);
        }
    }

    Node *LCA(Node *a, Node *b)
    {
        Node *temp = head;
        while (1)
        {
            if (a->data < temp->data && b->data > temp->data)
            {
                return temp;
            }
            if (temp == a || temp == b)
            {
                return temp;
            }
            if (a->data < temp->data && b->data < temp->data)
            {
                temp = temp->left;
            }
            else if (a->data > temp->data && b->data > temp->data)
            {
                temp = temp->right;
            }
        }
    }

    int PathInBetween(Node *a, Node *b)
    {
        Node *temp = LCA(a, b);
        Node *temp1 = temp;
        Node *temp2 = temp;
        int count = 0;
        while (temp1 != a)
        {
            if (a->data < temp1->data)
            {
                temp1 = temp1->left;
                count++;
            }
            else if (a->data > temp1->data)
            {
                temp1 = temp1->right;
                count++;
            }
        }
        while (temp2 != b)
        {
            if (b->data < temp2->data)
            {
                temp2 = temp2->left;
                count++;
            }
            else if (b->data > temp2->data)
            {
                temp2 = temp2->right;
                count++;
            }
        }
        return count;
    }
};

int main()
{
    int n;
    BST tree;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        tree.insert(v[i]);
    }
    vector<Node *> vn;
    tree.FindLeaves(v, vn);
    int max = 0;
    for (int i = 0; i < vn.size() - 1; i++)
    {
        for (int j = i + 1; j < vn.size(); j++)
        {
            int l = tree.PathInBetween(vn[i], vn[j]);
            if (l > max)
                max = l;
        }
    }
    cout << max + 1;
}