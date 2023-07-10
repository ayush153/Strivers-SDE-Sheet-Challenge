/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/

bool Symmetric(BinaryTreeNode<int>* p, BinaryTreeNode<int>* q) {
    if (!p || !q)
        return p == q;

    return p->data == q->data && Symmetric(p->left, q->right) && Symmetric(p->right, q->left);
}

bool isSymmetric(BinaryTreeNode<int>* root)
{
    // Write your code here.   
    return Symmetric(root, root); 
}
