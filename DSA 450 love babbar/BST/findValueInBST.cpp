#include <bits/stdc++.h> 

using namespace std;

    template <typename T>
    class TreeNode {
       public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
    };



bool findNode(TreeNode <int> * root, int key) {
    TreeNode<int> *temp=root;
    while(temp!=NULL)
    {
    if(temp->data==key)
    return true;
    else if(temp->data>key)
    {
        temp=temp->left;
    }
    else {
        temp=temp->right;
    }
    }
    return false;
}