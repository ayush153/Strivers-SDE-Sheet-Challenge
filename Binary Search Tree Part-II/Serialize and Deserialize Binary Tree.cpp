#include<bits/stdc++.h>
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

string serializeTree(TreeNode<int> *root)
{
 //    Write your code here for serializing the tree
    string ans;
    stack<TreeNode<int>*> st;
    st.push(root);
    while(st.size())
    {
        auto top = st.top();
        st.pop();
        if(top == NULL)
            ans += "#,";
        else
        {
            ans += to_string(top->data) + ",";
            st.push(top->right);
            st.push(top->left);
        }
    }
    return ans;
}

TreeNode<int>* deserializeTree(string &serialized)
{
 //    Write your code here for deserializing the tree
    int i = 0;
    vector<string> token;
    while(i < serialized.size())
    {
        int next = serialized.find(',', i);
        token.push_back(serialized.substr(i, next - i));
        i = next + 1;
    }
    //inorder traversal with stack
    stack<TreeNode<int>*> st;
    i = -1;
    auto extra = new TreeNode<int>(0);
    st.push(extra);
    while(st.size())
    {
        auto top = st.top();
        st.pop();
        if(token[++i] != "#")
        {
            st.push(top = top->right = new TreeNode<int>(stoi(token[i])));
            while(token[++i] != "#")
            {
                st.push(top = top->left = new TreeNode<int>(stoi(token[i])));
            }
        }
    }
    return extra->right;
}
