#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;
    Node(int val):data(val),left(nullptr),right(nullptr){}
};

class BST{
private:
    Node *head=nullptr;
public:
    void insert(int val)
    {
        Node *newNode=new Node(val);
        if(!head)
        {
            head=newNode;
        }
        else
        {
            Node *temp=head;
            while(temp)
            {
                if(newNode->data<temp->data)
                {
                    if(temp->left==nullptr)
                    {
                        temp->left=newNode;
                        break;
                    }
                    temp=temp->left;
                }
                else
                {
                    if(temp->right==nullptr)
                    {
                        temp->right=newNode;
                        break;
                    }
                    temp=temp->right;
                }
            }
        }
    }
    void inorderPrint()
    {
        Node* temp=head;
        stack<Node*> s;
        while (temp||!s.empty())
        {
            while (temp)
            {
               s.push(temp);
               temp=temp->left;
            }
            temp=s.top();
            s.pop();
            cout<<temp->data<<" ";
            temp=temp->right;
            
        }
        
    }
    bool inorderSearch(int key) {
        Node* temp = head;
        stack<Node*> s;

        while (temp || !s.empty()) {
            while (temp) {
                s.push(temp);
                temp = temp->left;
            }

            temp = s.top();
            s.pop();
            if (temp->data == key) return true;
            temp = temp->right;
        }
        
        return false; 
    }
};

int main()
{
    int a[]={2,3,5,4,1};
    BST tree;
    for (int i = 0; i < 5; i++)
    {
        tree.insert(a[i]);
    }
    tree.inorderPrint();
    return 0;
    
}