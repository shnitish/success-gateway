/*
Logic here is to check that if the given birnary tree is a mirror of itself or not.
It it is then we can say that it is symmetric.
So we make a separate bool function which check if it is mirror of itself or not and then call it in the isSymmetric method

1) isMirror
Take two tree nodes and recur for both of them checking they child nodes.
If the root is NULL then it is symmetric
If one the nodes is NULL then it is not symmetric
If value of both the nodes are equal then recur for their child nodes
    checking left chilld of the left subtree with the right child of the right subtree and vice versa

2) isSymmetric
call isMirror function and pass the root nodes into the function, if it is the mirror of itself then return true eles return false
*/

class Solution {
public:
    
    bool isMirror(TreeNode *t1, TreeNode *t2)
    {
        if(t1 == NULL && t2 == NULL)
            return true;
        
        else if( t1 == NULL || t2 == NULL)
            return false;
        
        else if( t1 != NULL && t2 != NULL)
            if(t1->val == t2->val)
                return(isMirror(t1->right, t2->left) && isMirror(t1->left, t2->right));
        
        return false;
    }
    
    bool isSymmetric(TreeNode* root) {
        return isMirror(root, root);
    }
};