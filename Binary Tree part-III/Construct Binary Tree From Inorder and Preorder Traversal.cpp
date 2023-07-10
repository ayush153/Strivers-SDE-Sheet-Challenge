#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

************************************************************/
TreeNode<int> *build(vector<int> &preorder, vector<int> &inorder, int &rootIdx, int left, int right) {
    if (left > right) 
        return NULL;
    int pivot = left;
    while(inorder[pivot] != preorder[rootIdx]) 
        pivot++;
    rootIdx++;
    TreeNode<int> *newNode = new TreeNode<int>(inorder[pivot]);
    newNode->left = build(preorder, inorder, rootIdx, left, pivot-1);
    newNode->right = build(preorder, inorder, rootIdx, pivot+1, right);
    return newNode;
}

TreeNode<int> *buildBinaryTree(vector<int> &inorder, vector<int> &preorder)
{
	//    Write your code here
    int rootIdx = 0;
    return build(preorder, inorder, rootIdx, 0, inorder.size()-1);
}
