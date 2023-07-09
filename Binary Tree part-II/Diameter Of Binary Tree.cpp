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
int maxDepth(TreeNode<int> *root, int &ans) {
    if (root == NULL)
        return 0;
    int left = maxDepth(root->left, ans);
    int right = maxDepth(root->right, ans);
    ans = max(ans, left + right);
    return  1 + max(left, right);
}

int diameterOfBinaryTree(TreeNode<int> *root)
{
	// Write Your Code Here.
    int ans = 0;
    maxDepth(root, ans);
    return ans;
}

