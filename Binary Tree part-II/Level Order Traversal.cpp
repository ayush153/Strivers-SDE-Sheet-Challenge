#include <bits/stdc++.h> 
/************************************************************

    Following is the BinaryTreeNode class structure

    template <typename T>
    class BinaryTreeNode {
       public:
        T val;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T val) {
            this->val = val;
            left = NULL;
            right = NULL;
        }
    };

************************************************************/
vector<int> getLevelOrder(BinaryTreeNode<int> *root)
{
    //  Write your code here.
    vector<int> ans;
    queue<BinaryTreeNode<int>*> q;
    if(root == NULL) return ans;
    q.push(root);
    while(!q.empty())
    {
        BinaryTreeNode<int>* node = q.front();
        ans.push_back(node->val);
        q.pop();
        if(node->left != NULL) 
            q.push(node->left);
        if(node->right != NULL) 
            q.push(node->right);
    }
    return ans;
}
