#include <bits/stdc++.h> 


struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};


int findPrice(Node* root)
{
   Node* temp=root;
   while(temp)
   {
       if(temp->left)
       temp=temp->left;
       else
       break;
   }
   return temp->data;
}