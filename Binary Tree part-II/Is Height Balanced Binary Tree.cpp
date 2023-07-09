#include <bits/stdc++.h> 
/*************************************************************
 
    Following is the Binary Tree node structure

    class BinaryTreeNode 
    {
    public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
    };

*************************************************************/
int maxDepth(BinaryTreeNode<int>* root) {
    if (root == NULL)  return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
        
}
bool isBalancedBT(BinaryTreeNode<int>* root) {
    // Write your code here.
    if (root == NULL)  return true;
    return abs(maxDepth(root->left) - maxDepth(root->right)) <= 1 &&
        isBalancedBT(root->left) && isBalancedBT(root->right);
}
