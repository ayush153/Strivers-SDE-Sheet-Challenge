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
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    stack<TreeNode*>st;
    TreeNode *currentNode = root;
    vector<int>ans;
    
    while(true)
    {
        if(currentNode!=NULL)
        {
            st.push(currentNode);
            currentNode = currentNode->left;
        }
        else
        {
            if(st.empty() == true) break;
            currentNode = st.top();
            st.pop();
            ans.push_back(currentNode->data);
            currentNode = currentNode->right;
        }
    }
    return ans;
}
