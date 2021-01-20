
// Max Value will be present at the right most node of a BST
int maxVal(TreeNode *root)
    {   
        if(root->right == NULL)
            return root->val;
        
        return maxVal(root->right);
    }
    
// Similarily Min value will be present in the left most node of the BST
int minVal(TreeNode *root)
    {   
        if(root->left == NULL)
            return root->val;
        
        return minVal(root->left);
    }
    