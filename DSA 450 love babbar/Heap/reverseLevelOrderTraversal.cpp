
#include<bits/stdc++.h>
using namespace std;

    
    template <typename T>

    class TreeNode {
    public:
        T val;
        TreeNode<T> *left;
        TreeNode<T> *right;
        TreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };


vector<int> reverseLevelOrder(TreeNode<int> *root){
    queue<TreeNode<int>*> q;
    vector<int> ans;
    if(root==NULL)
    return ans;
    q.push(root);
    while(!q.empty())
    {
        TreeNode<int>* current=q.front();
        ans.push_back(current->val);
        q.pop();
        if(current->left)
        q.push(current->left);
        if(current->right)
        q.push(current->right);

    }

    reverse(ans.begin(),ans.end());
    return ans;
}