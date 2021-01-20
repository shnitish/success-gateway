/*
https://leetcode.com/problems/delete-node-in-a-bst/

https://www.youtube.com/watch?v=NL1ocKYzlAM

 */
class Solution {
public:
    
    // Find max value in the BST by moving right
    // because the max value is present at the right most node
    int maxVal(TreeNode *root)
    {   
        if(root->right == NULL)
            return root->val;
        
        return maxVal(root->right);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key)
    {
        if(root == NULL) return NULL;
        
        if(root->val > key)
            root->left = deleteNode(root->left, key);
        
        else if(root->val < key)
            root->right = deleteNode(root->right, key);
        
        else
        {
            // Left and right both not null so get the 
            // max value from left and replace the root data with the max value
            // and delete node with the max value
            if(root->left != NULL && root->right != NULL)
            {
                int max = maxVal(root->left);
                root->val = max;
                root->left = deleteNode(root->left, max);
            }
            
            else if(root->left != NULL)
            {
                return root->left;
            }
            
            else if(root->right != NULL)
            {
                return root->right;
            }
            
            else
            {
                delete root;
                return NULL;
            }
        }
        
        return root;
    }
};