#include <bits/stdc++.h> 
/************************************************************

    Following is the TreeNode class structure

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

************************************************************/
TreeNode<int>* binary_search(vector<int> &arr, int low, int high)
{
    if(low <= high)
    {
        int mid = low + (high - low) / 2;
        TreeNode<int>* root = new TreeNode<int>(arr[mid]);
        root->left = binary_search(arr, low, mid-1);
        root->right = binary_search(arr, mid+1, high);
        return root;
    }
    return NULL;
}

TreeNode<int>* sortedArrToBST(vector<int> &arr, int n)
{
    // Write your code here.
     return binary_search(arr, 0, n - 1);
}
