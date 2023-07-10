/************************************************************
   
   Following is the TreeNode class structure
   
   class TreeNode<T>
   { 
   public:
        T data; 
        TreeNode<T> *left;
        TreeNode<T> *right;
   
        TreeNode(T data) 
  		{ 
            this -> data = data; 
            left = NULL; 
            right = NULL; 
        }
   };
   
   
 ************************************************************/
TreeNode<int> *Tree(vector<int> &inOrder, int x, int y,vector<int> &postOrder,int a,int b){
     if(x > y || a > b)
          return NULL;
     TreeNode<int> *node = new TreeNode<int>(postOrder[b]);
     int ans = x;  
     while(node->data != inOrder[ans])
          ans++;
     node->left  = Tree(inOrder, x, ans-1, postOrder, a, a+ans-x-1);
     node->right = Tree(inOrder, ans+1, y, postOrder, a+ans-x, b-1);
     return node;
}
TreeNode<int>* getTreeFromPostorderAndInorder(vector<int>& postOrder, vector<int>& inOrder) 
{
	// Write your code here.
     return Tree(inOrder, 0, inOrder.size()-1, postOrder, 0, postOrder.size()-1);
}

