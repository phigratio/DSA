#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node *parent;
    int height;
};

Node *createNode(int val)
{
    Node *newNode = new Node();
    newNode->data = val;
    newNode->left = NULL;
    newNode->right = NULL;
    newNode->parent = NULL;
    newNode->height = -1;
    return newNode;
}

Node *root = NULL;

int height(Node *x)
{
    if (x == NULL)
        return -1;
    return x->height;
}

void update_height(Node *x)
{
    x->height = max(height(x->left), height(x->right)) + 1;
}

int balance_factor(Node *x)
{
    return height(x->left) - height(x->right);
}

void print(Node *x)
{
    if (x == NULL)
        return;
    print(x->left);
    cout << x->data << "(" << balance_factor(x) << ") ";
    print(x->right);
}

void insertion(int val)
{
    Node *cur = root;
    Node *newNode = createNode(val);
    if (cur == NULL)
    {
        root = newNode;
        root->height++;
    }
    else
    {
        Node *parent;
        while (cur != NULL)
        {
            parent = cur;
            if (val > cur->data)
                cur = cur->right;
            else
                cur = cur->left;
        }

        newNode->parent = parent;
        if (val > parent->data)
            parent->right = newNode;
        else
            parent->left = newNode;

        Node *temp = newNode;
        while (temp != NULL)
        {
            update_height(temp);
            temp = temp->parent;
        }
    }
    print(root);
    cout << endl;
}

int main()
{
    int n = 0;
    while (cin >> n && n != -1)
    {
        insertion(n);
    }
    return 0;
}