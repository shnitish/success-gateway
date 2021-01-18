/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        // base case
        if(root == NULL)
            return NULL;
        
        // search for p and q
        if(root == p || root == q)
            return root;
        
        // call for left and right sub tree
        TreeNode *left = lowestCommonAncestor(root->left, p, q);
        TreeNode *right = lowestCommonAncestor(root->right, p, q);
        
        // if both left and right of a node are not null then it is the LCA
        if(left != NULL && right != NULL)
            return root;
        
        // else one of them contains p and q while returing to call stack
        else
            return left ? left : right;
        
    }
};