#include <bits/stdc++.h> 
/************************************************************

    Following is the Binary Tree node structure:
    
    template <typename T>
    class TreeNode {
        public :
        T data;
        TreeNode<T> *left;
        TreeNode<T> *right;

        TreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }

        ~TreeNode() {
            if(left)
                delete left;
            if(right)
                delete right;
        }
    };

************************************************************/
void leftVeiw(TreeNode<int> *root, vector<int> &ans){
    if(root == NULL)
       return ;  
    if(root -> left == NULL && root -> right == NULL)
       return ;  
    ans.push_back(root -> data);  
    leftVeiw(root -> left , ans);  
    if(root -> left == NULL )
    {
       leftVeiw(root -> right , ans );  
       return ;  
    }
   return ;  
}

void leafNodes(TreeNode<int> *root, vector<int> &ans){
    if(root == NULL)
       return ;  
    if(root -> left == NULL && root -> right == NULL)
    {
       ans.push_back(root->data);  
       return ;  
    }
    leafNodes(root -> left , ans);  
    leafNodes(root -> right , ans);  
    return ;  
}

void rightVeiw(TreeNode<int> *root, vector<int> &ans){
    if(root == NULL)
       return ;  
    if(root -> right == NULL && root -> left == NULL)
       return ;  
    rightVeiw(root -> right, ans);  
    if(root -> right == NULL)
       rightVeiw(root -> left, ans);  
   
    ans.push_back(root -> data);  
    return ;  
}
vector<int> traverseBoundary(TreeNode<int>* root){
    // Write your code here.
    vector<int> ans;
    if (root == NULL)
        return ans;
    ans.push_back(root -> data);
    if (root -> left)
        leftVeiw(root -> left, ans);
    leafNodes(root -> left, ans);
    leafNodes(root -> right, ans);
    if (root -> right)
        rightVeiw(root -> right, ans);
    return ans;
}
