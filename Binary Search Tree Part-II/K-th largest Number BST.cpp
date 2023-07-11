#include <bits/stdc++.h> 
/************************************************************
    Following is the Binary Search Tree node structure
    
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

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    // Write your code here.
    stack<TreeNode<int>*>st;
    int ans = 0;
    while(true)
    {
        if(root)
        {
            st.push(root);
            root = root->right;
        }
        else
        {
            if(st.empty()) 
                break;
            root = st.top();
            st.pop();
            ans++;
            if(ans == k)
                return root->data;
            root = root->left;
        }
    }
    return -1;
}

