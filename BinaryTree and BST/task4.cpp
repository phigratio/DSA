// ‘Runway reservation system’ has given its final requirement. Now they want your help to introduce a new feature that will show the updated list of reservations after a certain transport has used the runway(that transport will be taken out of the reservations set). 

// The first line of input will give you the number of queries. 
// Each query gives you the timestamp of transport which has used the runway. Your job is to remove the reservation and show the updated set using level-order traversal.

// Sample input
// 6(current reservations) 50 75 25 29 45 60 90 10 80 100 84 88  -1

// 29
// 25
// 75
// 45
// 50
// 80
// Sample output (level-order traversal)

// 50 25 75 10 29 60 90 45 80 100 88 (initial)
// 50 25 75 10 45 60 90 80 100 84 88
// 50 45 75 10 60 90 80 100 84 88
// 50 45 80 10 60 90 84 100 88
// 50 10 80 60 90 84 100 88
// 60 10 80 90 84 100 88
// 60 10 84 90 88 100


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
    Node *bstSearch(int key)
    {
        Node *temp = head;
        while (temp->data != key or temp != nullptr)
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

    Node *findInOrderSuccessor(Node *node)
    {
        while (node->left)
        {
            node = node->left;
        }
        return node;
    }

    void remove(int val)
    {
        Node *z = bstSearch(val);
        Node *zp = z->parent;
        if (z->left == nullptr and z->right == nullptr)
        {
            if (zp)
            {
                if (zp->left == z)
                {
                    zp->left = nullptr;
                }
                else
                {
                    zp->right = nullptr;
                }
            }
            else
            {
                head = nullptr;
            }
            delete z;
        }
        else if (z->left == nullptr || z->right == nullptr)
        {
            Node *child = (z->left) ? z->left : z->right;
            if (zp)
            {
                if (zp->left == z)
                {
                    zp->left = child;
                }
                else
                {
                    zp->right = child;
                }
                child->parent = zp;
            }
            else
            {
                head = child;
                child->parent = nullptr;
            }
            delete z;
        }
        else
        {
            Node *successorParent = z;
            Node *successor = z->right;
            while (successor->left != nullptr)
            {
                successorParent = successor;
                successor = successor->left;
            }
            z->data = successor->data;

            if (successorParent == z)
            {
                successorParent->right = successor->right;
            }
            else
            {
                successorParent->left = successor->right;
            }
            delete successor;
        }
    }
    void levelOrderTraversal()
    {
        queue<Node *> q;
        if (!head)
        {
            return;
        }

        q.push(head);
        while (!q.empty())
        {
            Node *temp = q.front();
            q.pop();
            cout << temp->data << " ";
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
};
int main()
{
    BST tree;
    int arr[] = {50, 75, 25, 29, 45, 60, 90, 10, 80, 100, 84, 88};
    for (int i = 0; i < 12; i++) {
        tree.insert(arr[i]);
    }

    int n;
    cin >> n;

    for (int i = 0; i<n; i++) {
        int x;
        cin >> x;
        tree.remove(x);
        tree.levelOrderTraversal();
    }

    return 0;
}