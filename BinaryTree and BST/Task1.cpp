// Task1

// Disneyland has built its airport. The airport has only one runway, which results in heavy traffic. So the authority has decided to create a ‘Runway reservation system’ for their only runway, which will take the reservation of any transport desired to use the runway.

// Before making the entry, the system checks for reservations within the three-minute range of any existing reservation(s). For example, if there is a reservation in the kth minute, it won’t take any reservation in k-1, k-2, k-3, k+1, k+2, (k+3)th minutes.

// Your task is to help them build the system using Binary Search Trees(BST). (Take reservations until the user gives ‘-1’ as input.)
// For every reservation, print the existing reservations in a sorted manner.

// Sample Input
// 50
// 75
// 53
// 25
// 60
// 29
// 45
// 42
// 28
// 10
// -1
// Sample Output
// 50
// 50 75
// 50 75 (Reservation failed)
// 25 50 75
// 25 50 60 75
// 25 29 50 60 75
// 25 29 45 50 60 75
// 25 29 45 50 60 75 (Reservation failed)
// 25 29 45 50 60 75 (Reservation failed)
// 10 25 29 45 50 60 75

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class BST
{
private:
    Node *head = nullptr;

public:
    void insert(int val)
    {
        Node *newNode = new Node(val);
        if (!head)
        {
            head = newNode;
        }
        else
        {
            Node *temp = head;
            while (temp)
            {
                if (newNode->data < temp->data)
                {
                    if (temp->left == nullptr)
                    {
                        temp->left = newNode;
                        break;
                    }
                    temp = temp->left;
                }
                else if (newNode->data > temp->data)
                {
                    if (temp->right == nullptr)
                    {
                        temp->right = newNode;
                        break;
                    }
                    temp = temp->right;
                }
                else
                {

                    break;
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
            cout << temp->data << " ";
            temp = temp->right;
        }
    }

    bool inorderSearch(int key)
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
            if (temp->data <= key + 3 and temp->data >= key - 3)
            return true;
                temp = temp->right;
        }
        return false;
    }
};

int main()
{
    BST tree;
    int n;
    cin >> n;
    while (n + 1)
    {
        if (!tree.inorderSearch(n))
        {
            tree.insert(n);
            tree.inorderPrint();
        }
        else
        {
            tree.inorderPrint();
            cout << "(Reservation failed)";
        }
        cin >> n;
        cout << endl;
    }
}
