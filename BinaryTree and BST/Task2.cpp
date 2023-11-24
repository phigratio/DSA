// Task 2:
// ‘Runway reservation system’ has a new requirement. They want to introduce a feature that will allow any transport owner to make a new query, which will allow any transport owner to give a timestamp as input. The system will tell ‘How many reservations are in the system before it?’. 

// One of their employees proposed a solution that traverses the tree in an In-order fashion and then finds the timestamps that are less than the query. They are not happy with this O(n) solution. They want you to solve this problem in O(height) time.
// Your task is to fulfill their requirement.

// The first line of input will give you the number of queries. 
// Each query gives you the timestamp of a specific reservation. Your task is to find the number for reservation before that timestamp. 
// (current reservations) 50 75 25 29 45 60 10 -1
// Sample input
// 5
// 45
// 75
// 50
// 10
// 29
// Sample output
// 3
// 6
// 4
// 0
// 2


#include <bits/stdc++.h>
using namespace std;
class Node
{
    public:
    int data;
    int subtree_size = 0;
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
                temp->subtree_size++;
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
            cout << temp->subtree_size << " ";
            temp = temp->right;
        }
    }

    Node *bstSearch(int key)
    {
        Node *temp = head;
        while (temp->data != key || temp != nullptr)
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

    int findPos(Node *x)
    {
        int own_rsubtree = (x->right) ? x->right->subtree_size + 1 : 0;
        Node *temp = x;

        while (1)
        {
            if (temp->parent == nullptr)
                break;
            if (temp->parent->data < x->data)
            {
                temp = temp->parent;
            }
            else
                break;
        }
        return temp->subtree_size - own_rsubtree;
    }
};

int main()
{
    BST tree;
    int arr[] = {50, 75, 25, 29, 45, 60, 10};
    for (int i = 0; i < 7; i++)
    {
        tree.insert(arr[i]);
    }
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        cout << tree.findPos(tree.bstSearch(x)) << endl;
    }
}