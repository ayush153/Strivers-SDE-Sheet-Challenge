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
vector<int> getPostOrderTraversal(TreeNode *root)
{
    // Write your code here.
    vector<int>ans;
    stack<TreeNode*> st;
    
    if(root == NULL)
        return ans;
    st.push(root);
    
    while(st.empty() == NULL)
    {
        TreeNode *currentNode = root;
        currentNode = st.top();
        st.pop();
        if(currentNode->left!=NULL)
            st.push(currentNode->left);
        if(currentNode->right!=NULL)
            st.push(currentNode->right);
        ans.push_back(currentNode->data);  
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
