#include <bits/stdc++.h> 
/*************************************************************

    Following is the Binary Tree node structure

    template <typename T>

    class TreeNode{
    public:
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this->data = data;
            left = NULL;
            right = NULL;
        }
        ~TreeNode() {
            if (left){
                delete left;
            }
            if (right){
                delete right;
            }
        }
    };

*************************************************************/
TreeNode<int> *bstfrompreorder(vector<int> &preorder, int &i, int max)
{
    if (i == preorder.size() || preorder[i] > max)
        return NULL;
    
    TreeNode<int> *root = new TreeNode<int>(preorder[i]);
    i++;
    root->left = bstfrompreorder(preorder, i, root->data);
    root->right = bstfrompreorder(preorder, i, max);
    return root;
}

TreeNode<int>* preOrderTree(vector<int> &preOrder){
    // Write your code here.
    int i = 0;
    TreeNode<int> *root = bstfrompreorder(preOrder, i, INT_MAX);
    return root;
}
