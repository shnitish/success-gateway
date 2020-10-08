/*
https://leetcode.com/problems/balanced-binary-tree/
*/
/*
Logic here is:
1) Set a gloabal variable flag to True
2) Calculate the height of the tree in other function and check wheter the absolute difference of the height of left and
right subtree height is greater than 1 or not, if yes then simply set the flag to false, else return the max of left and right 
subtree.
3) We just call the helper function checkHeight to manipulate and determine the flag value according to the tree.
4) Simply return flag.
    
*/
class Solution {
public:
    bool flag = true;
    int checkHeight(TreeNode *root)
    {
        if(root == NULL)
            return 0;
        
        int left = checkHeight(root->left);
        int right = checkHeight(root->right);
        
        if(abs(left - right)  > 1)
            flag = false;
        
        return 1 + max(left, right);
    }
    
    bool isBalanced(TreeNode* root) {
        checkHeight(root);
        return flag;
        
    }
};