#include <bits/stdc++.h> 
/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
vector<int> getPreOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>v;
    if(root == NULL) 
        return v;
    stack<TreeNode*>s;
    s.push(root);
    while(s.empty()==false)
    { 
        TreeNode* curr = s.top();
        v.push_back(curr->data);
        s.pop();
        if(curr->right != NULL)
            s.push(curr->right);
        if(curr->left != NULL)
            s.push(curr->left);
    }
    return v;
}
