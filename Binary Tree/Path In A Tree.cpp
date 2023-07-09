#include <bits/stdc++.h> 
/*   
    template <typename T = int>
	class TreeNode
	{
		public:
		T data;
		TreeNode<T> *left;
		TreeNode<T> *right;

		TreeNode(T data)
		{
			this->data = data;
			left = NULL;
			right = NULL;
		}

		~TreeNode()
		{
			if (left != NULL)
			{
		  		delete left;
			}
			if (right != NULL)
			{
			 	delete right;
			}
		}
	};
*/

vector<int>ans;
void solve(TreeNode<int>* root, int x, vector<int>v)
{
    if(root == NULL)
        return ;
    v.push_back(root->data);
    if(x == root->data)
    {
        ans = v;
        return ;
    }
    solve(root->left, x, v);
    solve(root->right, x, v);
}
vector<int> pathInATree(TreeNode<int> *root, int x)
{
    // Write your code here.
	vector<int>res;
    solve(root,x,res);
    return ans;
}

