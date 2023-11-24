// Task 3
// Suppose a set of numbers are stored using a Binary Search Tree(BST). Two numbers x and y are given as input(x<y). Your task is to find the maximum number that will be encountered from the path going from x to y.
// [O(n) solution will not be accepted]
// Sample input
// 8
// 10 50
// 25 45
// 60 80
// 25 60
// 12 25
// 10 60
// 50 60
// 75 80
// Sample output
// (current values) 50 75 25 29 45 60 10 80 -1
// 50
// 45
// 80
// 75
// 25
// 75
// 75
// 80

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
    int findMaxP(Node *temp, int x, int y)
    {
        while (1)
        {
            if (y == temp->data and x < temp->data)
            {
                return y;
            }
            else if (x < temp->data and y < temp->data)
            {
                temp = temp->left;
            }
            else if (x > temp->data and y > temp->data)
            {
                temp = temp->right;
            }
            else if ((x < temp->data and y > temp->data) or (x == temp->data and y > temp->data))
            {
                int maxq = 0;
                while (temp != nullptr)
                {
                    if (temp->data == y)
                    {
                        maxq = max(temp->data, maxq);
                        break;
                    }
                    if (y > temp->data)
                    {
                        maxq = max(temp->data, maxq);
                        temp = temp->right;
                       
                    }
                    else
                    {
                        maxq = max(temp->data, maxq);
                        temp = temp->left;
                    }
                }
                return maxq;
            }
        }
    }
};
int main()
{
    BST tree;
    int arr[] = {50, 75, 25, 29, 45, 60, 10, 80};
    for (int i = 0; i < 8; i++)
    {
        tree.insert(arr[i]);
    }
    int n;
    cin >> n;
    while (n--)
    {
        int x, y;
        cin >> x >> y;
        cout << tree.findMaxP(tree.getHead(), x, y) << endl;
    }
}