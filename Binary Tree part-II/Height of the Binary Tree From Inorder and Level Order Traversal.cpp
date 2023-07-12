#include <bits/stdc++.h> 
struct Node {
    int height, left, right;

    Node(int height, int left, int right) {
        this->height = height;
        this->left = left;
        this->right = right;
    }
};

int heightOfTheTree(vector<int>& inorder, vector<int>& levelOrder, int N){
	// Write your code here.
	int ans = 0;
    queue<Node> q;

    Node root(0, 0, N - 1);
    q.push(root);

    unordered_map<int, int> mp;
    for (int i = 0; i < N; i++)
        mp[inorder[i]] = i;

    for (int i = 0; i < N; i++) 
	{
        Node temp = q.front();
        q.pop();

        ans = max(ans, temp.height);

        int left = temp.left;
		int right = temp.right;
        int rootIndexOfSubTree = mp[levelOrder[i]];

        if (rootIndexOfSubTree - 1 >= left) 
		{
            Node le(temp.height + 1, left, rootIndexOfSubTree - 1);
            q.push(le);
        }

        if (rootIndexOfSubTree + 1 <= right) 
		{
            Node ri(temp.height + 1, rootIndexOfSubTree + 1, right);
            q.push(ri);
        }
    }

    return ans;
}
