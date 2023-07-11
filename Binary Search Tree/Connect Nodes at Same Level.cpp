#include <bits/stdc++.h> 
/*
    ----------------- Binary Tree node class for reference -----------------

    template <typename T>
    class BinaryTreeNode {
        public : 
            T data;
            BinaryTreeNode<T> *left;
            BinaryTreeNode<T> *right;
            BinaryTreeNode<T> *next;

            BinaryTreeNode(T data) {
                this -> data = data;
                left = NULL;
                right = NULL;
                next = NULL;
            }
    };
*/

void connectNodes(BinaryTreeNode< int > *root) {
    // Write your code here.
    if(root == NULL) 
        return;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);        
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            
            BinaryTreeNode<int> *temp = q.front();
            q.pop();
            if (i != n - 1)
                temp->next = q.front();
            if (temp->left)
                q.push(temp->left);
            if (temp->right)
                q.push(temp->right);
        }
    }
}
